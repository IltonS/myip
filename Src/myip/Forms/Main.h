//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>

#include "IpifyAPI.h"
#include <Vcl.Menus.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
//---------------------------------------------------------------------------
class TFrmMain : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GbPublicIP;
	TLabel *LblPublicIP;
	TPopupMenu *PublicIPPopupMenu;
	TMenuItem *BtnCopyPublicIP;
	TGroupBox *GbIPConfig;
	TButton *BtnClose;
	TMemo *IPConfigMemo;
	TGroupBox *GbPrivateIP;
	TLabel *LblPrivateIP;
	TMainMenu *MainMenu;
	TMenuItem *MyIP1;
	TMenuItem *Help1;
	TMenuItem *N1;
	TMenuItem *MniExit;
	TMenuItem *mniAbout;
	TMenuItem *MniSetDefaultAdapter;
	TActionList *ActionList;
	TAction *ActSetDefaultAdapter;
	TAction *ActClose;
	TAction *ActCopyPublicIP;
	TAction *ActCopyPrivateIP;
	TAction *ActAbout;
	TMenuItem *Edit1;
	TMenuItem *CopyPublicIP1;
	TMenuItem *Close1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ActCloseExecute(TObject *Sender);
	void __fastcall ActCopyPublicIPExecute(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
public:		// User declarations
	UnicodeString DefaultNetworkAdapter;
    UnicodeString UserName;
	UnicodeString IniDirName;
	UnicodeString IniFileName;
	__fastcall TFrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMain *FrmMain;
//---------------------------------------------------------------------------
#endif
