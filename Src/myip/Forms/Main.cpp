//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.JSON.hpp>
#include <Vcl.Clipbrd.hpp>
#pragma hdrstop

#include "Main.h"
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
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::BtnCopyPublicIPClick(TObject *Sender)
{
	Clipboard()->AsText = LblPublicIP->Caption;
}
//---------------------------------------------------------------------------

