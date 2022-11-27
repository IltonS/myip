//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.JSON.hpp>
#include <Vcl.Clipbrd.hpp>
#include <System.IniFiles.hpp>
#include <System.SysUtils.hpp>
#include <iostream>
#include <fstream>
#pragma hdrstop

#include "Main.h"
#include "IPConfig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmMain *FrmMain;
//---------------------------------------------------------------------------
__fastcall TFrmMain::TFrmMain(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::FormShow(TObject *Sender)
{
	//Get Public IP Address
	 TJSONValue *JSONValue;

	 try
	 {
		DmIpifyAPI->RESTRequest->Execute();
		JSONValue = DmIpifyAPI->RESTResponse->JSONValue;

		if(dynamic_cast<TJSONObject*>(JSONValue)){
			LblPublicIP->Caption = "  " + JSONValue->GetValue<UnicodeString>("ip");
		}
	 }
	 catch (Exception &exception)
	 {
		LblPublicIP->Caption = "  0.0.0.0";
	 }

	 //Get Private IP Address
	 try
	 {
		//Run IpConfig
		IPConfigMemo->Lines->Text = ExecIPConfig();

		//Get Hostname
		FrmMain->Caption = "What's My IP - [Hostname: " + AHostName + "]";

		this->UserName = getenv("username");
		this->IniDirName = "C:\\Users\\"+ this->UserName+"\\AppData\\Roaming\\MyIP\\";
		this->IniFileName = this->IniDirName + "myip.ini";

		if(!DirectoryExists(this->IniDirName)){
			if(!CreateDir(this->IniDirName)){
				throw(Exception("Error creating ini directory."));
			}
		}

		if (!FileExists(this->IniFileName)){
			int File = FileCreate(this->IniFileName);

			if(File){
				FileClose(File);
			}else{
				throw(Exception("Error creating ini file."));
			}
		}

		TIniFile *IniFile;

		IniFile = new TIniFile("C:\\Users\\"+this->UserName+"\\AppData\\Roaming\\MyIP\\myip.ini");

		try
		{
			this->DefaultNetworkAdapter = IniFile->ReadString("CONFIG", "DEFAULT_NETWORK_ADAPTER", EmptyStr);

			if(this->DefaultNetworkAdapter == EmptyStr){
				throw(Exception("Default Network Adapter not set."));
			}
		}
		__finally
		{
			delete IniFile;
		}

	 }
	 catch (Exception &exception)
	 {
		LblPrivateIP->Caption = "  0.0.0.0";
	 }

}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::ActCloseExecute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::ActCopyPublicIPExecute(TObject *Sender)
{
	Clipboard()->AsText = LblPublicIP->Caption;
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	TIniFile *IniFile;

	IniFile = new TIniFile("C:\\Users\\"+this->UserName+"\\AppData\\Roaming\\MyIP\\myip.ini");

	try
	{
		try
		{
			IniFile->WriteString("CONFIG", "DEFAULT_NETWORK_ADAPTER", this->DefaultNetworkAdapter);
		}
		catch (Exception &exception)
		{
			//Error
		}
	}
	__finally
	{
		delete IniFile;
	}
}
//---------------------------------------------------------------------------

