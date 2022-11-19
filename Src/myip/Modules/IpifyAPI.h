//---------------------------------------------------------------------------

#ifndef IpifyAPIH
#define IpifyAPIH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
//---------------------------------------------------------------------------
class TDmIpifyAPI : public TDataModule
{
__published:	// IDE-managed Components
	TRESTClient *RESTClient;
	TRESTRequest *RESTRequest;
	TRESTResponse *RESTResponse;
private:	// User declarations
public:		// User declarations
	__fastcall TDmIpifyAPI(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDmIpifyAPI *DmIpifyAPI;
//---------------------------------------------------------------------------
#endif
