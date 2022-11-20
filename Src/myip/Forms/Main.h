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
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnCopyPublicIPClick(TObject *Sender);
	void __fastcall BtnCloseClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMain *FrmMain;
//---------------------------------------------------------------------------
#endif
