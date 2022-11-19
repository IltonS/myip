//---------------------------------------------------------------------------


#pragma hdrstop

#include "IpifyAPI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDmIpifyAPI *DmIpifyAPI;
//---------------------------------------------------------------------------
__fastcall TDmIpifyAPI::TDmIpifyAPI(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
