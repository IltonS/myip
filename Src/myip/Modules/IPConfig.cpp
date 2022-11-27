//---------------------------------------------------------------------------

#pragma hdrstop

#include "IPConfig.h"
#include <System.Classes.hpp>
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <time.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
UnicodeString AHostName;

 UnicodeString ExecIPConfig()
 {
	UnicodeString Result = EmptyStr;
	TStringList *Console = new TStringList;

	try
	{
		try
		{
			DWORD Err;

			PFIXED_INFO pFixedInfo;
			DWORD FixedInfoSize = 0;

			PIP_ADAPTER_INFO pAdapterInfo, pAdapt;
			DWORD AdapterInfoSize;
			PIP_ADDR_STRING pAddrStr;

			UINT i;

			struct tm newtime;
			char buffer[32];
			errno_t error;

			// Get the main IP configuration information for this machine using a FIXED_INFO structure

			if ((Err = GetNetworkParams(NULL, &FixedInfoSize)) != 0)
			{
				if (Err != ERROR_BUFFER_OVERFLOW)
				{
					 throw(Exception("GetNetworkParams sizing failed with error"));
				}
			}

			// Allocate memory from sizing information
			if ((pFixedInfo = (PFIXED_INFO) GlobalAlloc(GPTR, FixedInfoSize)) == NULL)
			{
				throw(Exception("Memory allocation error"));
			}

			if ((Err = GetNetworkParams(pFixedInfo, &FixedInfoSize)) == 0)
			{
				AHostName = UnicodeString(pFixedInfo->HostName);
			} else
			{
				throw(Exception("GetNetworkParams failed with error"));
			}

			// Enumerate all of the adapter specific information using the IP_ADAPTER_INFO structure.
			// Note:  IP_ADAPTER_INFO contains a linked list of adapter entries.
			//
			AdapterInfoSize = 0;
			if ((Err = GetAdaptersInfo(NULL, &AdapterInfoSize)) != 0)
			{
				if (Err != ERROR_BUFFER_OVERFLOW)
				{
					throw(Exception("GetAdaptersInfo sizing failed with error"));
				}
			}

			// Allocate memory from sizing information
			if ((pAdapterInfo = (PIP_ADAPTER_INFO) GlobalAlloc(GPTR, AdapterInfoSize)) == NULL)
			{
				throw(Exception("Memory allocation error"));
			}

			// Get actual adapter information
			if ((Err = GetAdaptersInfo(pAdapterInfo, &AdapterInfoSize)) != 0)
			{
				throw(Exception("GetAdaptersInfo failed with error"));
			}

			pAdapt = pAdapterInfo;

			while (pAdapt)
			{
				UnicodeString AdapterInfoType;
				switch (pAdapt->Type)
				{
					case MIB_IF_TYPE_ETHERNET:
						AdapterInfoType = "Ethernet adapter ";
						break;
					case MIB_IF_TYPE_TOKENRING:
						AdapterInfoType = "Token Ring adapter ";
						break;
					case MIB_IF_TYPE_FDDI:
						AdapterInfoType = "FDDI adapter ";
						break;
					case MIB_IF_TYPE_PPP:
						AdapterInfoType = "PPP adapter ";
						break;
					case MIB_IF_TYPE_LOOPBACK:
						AdapterInfoType = "Loopback adapter ";
						break;
					case MIB_IF_TYPE_SLIP:
						AdapterInfoType = "Slip adapter ";
						break;
					case MIB_IF_TYPE_OTHER:
					default:
						AdapterInfoType = "Other adapter ";
				}

				//Console->Add(AdapterInfoType + ": " + UnicodeString(pAdapt->AdapterName));
				Console->Add(AdapterInfoType + ": " + UnicodeString(pAdapt->Description));
				//Console->Add("Description . . . . . . . . : " + UnicodeString(pAdapt->Description));

				UnicodeString yn = pAdapt->DhcpEnabled ? "yes" : "no";
				Console->Add("DHCP Enabled. . . . . . . . : " + yn);

				pAddrStr = &(pAdapt->IpAddressList);
				while(pAddrStr)
				{
					Console->Add("IP Address. . . . . . . . . : " + UnicodeString(pAddrStr->IpAddress.String));
					Console->Add("Subnet Mask . . . . . . . . : " + UnicodeString(pAddrStr->IpMask.String));
					pAddrStr = pAddrStr->Next;
				}


				Console->Add("Default Gateway . . . . . . : " + UnicodeString(pAdapt->GatewayList.IpAddress.String));
				pAddrStr = pAdapt->GatewayList.Next;

				while(pAddrStr)
				{
					Console->Add(".  " + UnicodeString(pAddrStr->IpAddress.String));
					pAddrStr = pAddrStr->Next;
				}


				Console->Add("DHCP Server . . . . . . . . : " + UnicodeString(pAdapt->DhcpServer.IpAddress.String));
				Console->Add("Primary WINS Server . . . . : " + UnicodeString(pAdapt->PrimaryWinsServer.IpAddress.String));
				Console->Add("Secondary WINS Server . . . : " + UnicodeString(pAdapt->SecondaryWinsServer.IpAddress.String));
				Console->Add("");

                pAdapt = pAdapt->Next;
			}

			Result = Console->Text;
		}
		catch(const Exception& e)
		{
			Console->Add(e.Message);
			Result = Console->Text;
		}
	}
	__finally
	{
		delete Console;
	}

	return Result;
 }
