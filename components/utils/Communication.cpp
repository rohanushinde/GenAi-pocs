/* ---------------------------------------------------------------------------
	Copyright (c) EP MedSystems, Inc. 2001
	All Rights Reserved
	Printed in U.S.A.
	This document contains unpublished, confidential and proprietary
	information of EP MedSystems Inc.  No disclosure or use of any
	portion of the contents of these materials may be made without the express
	written consent of EP MedSystems Inc.

$Workfile: Communication.cpp $

Description:	This is an implementation file for the CCommunication class. 
					This class provides the bi-directional communication over the ethernet card.

Reviewed By: BByrd
Review Date: 06/20/01

$Revision: 2 $

$Log: /WM 4.2.X/Communication.cpp $
 * 
 * 2     9/25/08 11:58a Bbyrd
 * 
 * 1     6/04/08 12:12p Chandrab
 * 
 * 25    6/03/08 5:22p Nvajipay
 * 
 * 24    5/22/08 6:07p Bbyrd
 * 
 * 23    5/20/08 4:57p Bbyrd
 * 
 * 22    4/03/08 11:07a Bbyrd
 * 
 * 21    3/10/08 5:17p Bbyrd
 * 
 * 20    2/26/08 4:28p Nvajipay
 * 
 * 19    2/23/08 4:43p Bbyrd
 * 
 * 18    2/20/08 1:35p Bbyrd
 * 
 * 17    2/19/08 9:59a Bbyrd
 * 
 * 16    2/05/08 6:53p Bbyrd
 * 
 * 15    1/31/08 4:53p Bbyrd
 * 
 * 14    1/29/08 6:31p Bbyrd
 * 
 * 13    1/16/08 4:36p Chandrab
 * 
 * 12    12/19/07 12:16p Chandrab
 * 
 * 11    12/19/07 11:43a Bbyrd
 * 
 * 10    11/26/07 3:02p Bbyrd
 * 
 * 9     11/13/07 6:46p Bbyrd
 * 
 * 8     11/06/07 1:31p Bbyrd
 * 
 * 7     11/06/07 10:27a Chandrab
 * 
 * 6     10/23/07 9:37a Chandrab
 * 
 * 5     10/17/07 12:20p Bbyrd
 * 
 * 4     10/10/07 3:39p Chandrab
 * 
 * 3     9/28/07 4:00p Chandrab
 * 
 * 2     9/20/07 1:32p Bbyrd
 * 
 * 1     4/24/07 10:45a Chandrab
 * 
 * 10    2/20/07 6:53p Chandrab
 * 
 * 9     2/05/07 3:08p Chandrab
 * 
 * 8     1/24/07 12:23p Chandrab
 * 
 * 7     1/23/07 10:47a Chandrab
 * 
 * 6     1/23/07 10:24a Chandrab
 * 
 * 5     1/23/07 10:20a Chandrab
 * 
 * 4     1/23/07 10:13a Chandrab
 * 
 * 3     1/23/07 10:10a Chandrab
 * 
 * 2     6/23/06 8:11p Chandrab
 * 
 * 1     3/02/06 6:13p Chandrab
 * 
 * 1     11/03/05 2:34p Chandrab
 * 
 * 18    9/19/05 4:20p Bbyrd
 * 
 * 17    9/19/05 2:59p Bbyrd
 * 
 * 16    9/17/05 1:40p Bbyrd
 * 
 * 15    6/01/05 2:31p Chandrab
 * 
 * 14    4/26/05 10:13a Chandrab
 * 
 * 13    4/26/05 10:07a Chandrab
 * 
 * 11    12/29/04 1:08p Chandrab
 * 
 * 10    12/02/04 6:07p Chandrab
 * 
 * 9     11/29/04 7:27p Chandrab
 * 
 * 8     11/18/04 6:00p Chandrab
 * 
 * 7     11/17/04 12:45p Chandrab
 * 
 * 6     11/15/04 5:33p Chandrab
 * 
 * 5     9/07/04 11:54a Chandrab
 * 
 * 4     6/24/04 10:00a Chandrab
 * 
 * 1     6/07/04 6:36p Chandrab
 * 
 * 1     6/07/04 6:11p Chandrab
 * 
 * 71    5/04/04 6:38p Chandrab
 * 
 * 70    5/04/04 4:29p Chandrab
 * 
 * 69    5/04/04 3:23p Chandrab
 * 
 * 68    5/04/04 3:23p Chandrab
 * 
 * 67    11/24/03 6:40p Bbyrd
 * 
 * 66    9/17/03 5:25p Chandrab
 * 
 * 65    9/12/03 4:57p Chandrab
 * 
 * 64    9/04/03 1:18p Chandrab
 * 
 * 63    9/03/03 2:18p Chandrab
 * 
 * 62    9/02/03 1:33p Chandrab
 * 
 * 61    8/20/03 12:59p Chandrab
 * 
 * 60    5/01/03 8:19p Chandrab
 * 
 * 59    3/06/03 2:31p Chandrab
 * 
 * 58    2/26/03 10:05a Chandrab
 * 
 * 57    1/20/03 6:54p Chandrab
 * 
 * 56    1/15/03 4:39p Chandrab
 * 
 * 55    1/15/03 3:12p Chandrab
 * 
 * 54    1/15/03 10:27a Chandrab
 * 
 * 50    12/05/02 5:10p Chandrab
 * 
 * 49    12/05/02 3:17p Chandrab
 * 
 * 48    12/05/02 2:59p Chandrab
 * 
 * 47    12/04/02 1:34p Chandrab
 * 
 * 46    12/03/02 2:57p Chandrab
 * 
 * 45    11/01/02 10:13a Chandrab
 * 
 * 44    10/21/02 10:20a Chandrab
 * 
 * 40    7/17/02 7:28p Chandrab
 * 
 * 39    7/01/02 11:11a Bbyrd
 * 
 * 38    6/26/02 10:53a Bbyrd
 * 
 * 37    5/31/02 7:21p Chandrab
 * 
 * 36    5/22/02 9:12p Chandrab
 * 
 * 35    5/21/02 3:53p Chandrab
 * 
 * 34    5/21/02 1:41p Chandrab
 * 
 * 33    5/21/02 10:27a Chandrab
 * 
 * 32    5/21/02 10:26a Chandrab
 * 
 * 31    5/20/02 5:27p Chandrab
 * 
 * 30    5/18/02 5:52p Chandrab
 * 
 * 29    5/18/02 3:25p Chandrab
 * 
 * 28    5/17/02 8:22p Chandrab
 * 
 * 27    3/26/02 11:20a Chandrab
 * 
 * 26    2/15/02 3:57p Chandrab
 * 
 * 25    2/11/02 10:22a Chandrab
 * 
 * 24    2/07/02 4:44p Chandrab
 * 
 * 23    1/23/02 7:46p Chandrab
 * 
 * 22    1/18/02 12:06p Chandrab
 * 
 * 21    1/18/02 10:39a Chandrab
 * 
 * 20    1/16/02 12:08p Chandrab
 * 
 * 19    1/08/02 4:14p Chandrab
 * 
 * 18    1/08/02 4:10p Chandrab
 * 
 * 17    12/20/01 4:23p Chandrab
 * 
 * 16    12/20/01 12:22p Chandrab
 * 
 * 15    12/19/01 8:36p Chandrab
 * 
 * 14    12/03/01 8:00p Chandrab
 * 
 * 13    12/03/01 5:17p Chandrab
 * 
 * 11    11/29/01 9:04p Chandrab
 * 
 * 10    11/29/01 7:41p Chandrab
 * 
 * 9     11/29/01 6:40p Chandrab
 * 
 * 8     11/29/01 6:39p Chandrab
 * 
 * 7     11/28/01 9:20p Chandrab
 * 
 * 5     11/20/01 8:03p Chandrab
 * 
 * 4     10/11/01 12:46p Bbyrd
 * 
 * 3     9/27/01 1:49p Chandrab
 * 
 * 2     9/26/01 12:30p Chandrab
 
Testing:
	1) Execute every line of the source code and verify correct function
	against intent.
	2) Execute each test case defined for each function below.
--------------------------------------------------------------------------- */

/*--------------------------------------------------------------------------------------------------
											EP-WorkMate 4.0.0 
----------------------------------------------------------------------------------------------------

Class Name		:	CCommunication

Description		:	This class provides the bi-directional communication over the Ethernet card.

Setup			:	1. Hook up a function generator and input a sine wave into one junction box channel.
					2. Filter the signals 500Hz 
					3. Set the amplitude so it covers the entire channel space. Set the review screen sweep
						speed to 600 mm/sec
					4. Launch the WorkMate application.
					5. Ensure live signals on the realtime screen.
		
_____________________________________________________________________________________________________

Function Name	:	ProcessPressure()

Description		:	This fucntion upon selection process the pressures .

Testing			:	___1. Connect a pressure simulator to the SCU and verify the pressure signals are
					showing correclty on the workmate.
					___2. Chanhe the pressure input in the simulator and verify the signal is showing
					correclty.
					___3. Click on the 'Zero Pressure' button on the cathmap screen and verify the 
					pressure is zeroed on all the channels correclty without any errors.

_____________________________________________________________________________________________________

Function Name	:	PerformPressureAnalysis()

Description		:	This fucntion upon selection process the pressures .

Testing			:	___1. Connect a pressure simulator to the SCU and verify the pressure signals are
					showing correclty on the workmate.
					___2. Chanhe the pressure input in the simulator and verify the signal is showing
					correclty.
					___3. Click on the 'Zero Pressure' button on the cathmap screen and verify the 
					pressure is zeroed on all the channels correclty without any errors.

_____________________________________________________________________________________________________

Function Name	:	AdjustTempValue()

Description		:	This function upon calling sets the offset and gain to adjust the temperature analysis.

Setup			:	Connect a temperature adapter box to PMI. Connect the 30/47ºC simulator to the temperature
					adapter box. While in the Review screen select the "Setup" button.

Testing			:	___1. Select the setup button and verify the cathmap window is displayed.
					___2. Setup a pressure channel and set analyisis to temperature.
					___3. Leftmouse click on 'Temp' analysis and click on Edit button. Verify Analysis window 
					is displayed.
					___4. Enter Gain as '1000' and Offset as '-130' and close the window.
					___5. Verify temperature analysis shows correctly in the realtime monitor window.
____________________________________________________________________________________________________

Function Name	:	GetDataFromPacket()

Description		:	This fucntion upon selection gets the data from the packet

Testing			:	___1. Verify the samples per second averaged over 48 hours deviates less than 1 
						  packet per 1000.  
_____________________________________________________________________________________________________

Function Name	:	Create802_3SendPackage()

Description		:	This functions loads all the data from the buffer and displays on the Monitor screen.


Testing			:	___1. Select "Config" button from the Setup window. Select the Amplifier tab. Verify the 
                            amplifier related registry settings appear.
                    ___2. Verify all fields are set.
					___3. Verify the samples per second averaged over 48 hours deviates less than 1 
						  packet per 1000.

_____________________________________________________________________________________________________

Software Version:_______	Date:_______	Initials:___	All Tests Passed: Yes	No
---------------------------------------------------------------------------------------------------*/

#include "stdafx.h"

#ifndef WM_H
#include "WM.h"
#endif

#ifndef	COMMUNICATION_H
#include "Communication.h"
#endif

#ifndef MONITORDOC_H
#include "MonitorDoc.h"
#endif

#ifndef MESSAGE_H
#include "Message.h"
#endif

#ifndef	REALTIMECHILDFRAME_H
#include "RealTimeChildFrame.h"
#endif

#ifndef	PACKET_H
#include "Packet.h"
#endif

#ifndef RFDOC_H
#include "RFDoc.h"
#endif

#ifndef	MONITORCHILDFRAME_H
#include "MonitorChildFrame.h"
#endif

#ifndef	WMLIBRARY_H
#include "WMLibrary.h"
#endif

#ifndef DATETIME_H
#include "Datetime.h"
#endif

#ifndef	VMEXCEPTION_H
#include "VMException.h"
#endif


#pragma intrinsic(memcpy, memset, _tcscpy)

SWMCommandPacket		m_pktToAmp;

// Note	:	Increasing NUM_RECIEVE_PACKAGES beyond 64 is possible in this example.
// The default setting of NUM_RECIEVE_PACKAGES is to pass 128 concurrent packet reads to the NDISHOOK driver using the W32N_PacketReadEx() function.

#define	NUM_RECIEVE_PACKAGES	(512*10)		// Better Performance

#define	TPF_TCP_PROGLEN		6		// 6 BPF Instructions
#define	TPF_ARP_PROGLEN		19		// 19 BPF Instructions
#define	TPF_RARP_PROGLEN		19		// 19 BPF Instructions
#define	TPF_NETBEUI_PROGLEN	8		// 8 BPF Instructions
#define	TPF_ETALK2_PROGLEN	16		// 16 BPF Instructions
#define	TPF_IPX_PROGLEN		8		// 8 BPF Instructions
#define	TPF_IP_PROGLEN			18		// 19 BPF Instructions
#define	TPF_DECEXP_PROGLEN	18		// 19 BPF Instructions


// This filter ACCEPTS all IP packets, both RFC 894 And 802.3
static  bpf_insn BPFAcceptIP[] =
{
	// Handle 802.3 Case
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MLength),
	BPF_JUMP(BPF_JMP+BPF_JGT+BPF_K, 0x5DC, 12, 0),

	// Check 802.2 LLC. SAP 0xAA (SNAP), Control 0x03
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LDSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xAA, 0, 13),
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LSSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xAA, 0, 11),
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LCntrl),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x3, 0, 9),

	// Internet Organization/Vendor Code 0x000000
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + SType + 0),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x00, 0, 7),
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MHdrSize + SType + 1),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x0000, 0, 5),

	// Internet Protocol 0x0800
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MHdrSize + SType + 3),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, ETHERTYPE_IP, 2, 3),

	// Handle Ethernet RFC 894 Case
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, 12),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, ETHERTYPE_IP, 0, 1),

	BPF_STMT(BPF_RET+BPF_K, (UINT )-1),	// Accept. Value is bytes to be returned
	BPF_STMT(BPF_RET+BPF_K, 0 )			// Reject
};

// This filter ACCEPTS TCP packets (RFC 894 encapsulation only) This is actually used as a TEMPLATE. BPF instruction No. 5 contains
// 0x06 as the data value, which is the TCP IP protocol number.
static  bpf_insn BPFAcceptTCP[] =
{
	// Check Ethernet Protocol Word At Offset 12
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, 12),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, ETHERTYPE_IP, 0, 3),

	// Check IP Protocol Byte At Offset 14 + 9 = 23
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, 23),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x06, 0, 1),		// IP Protocol Type 0x06

	BPF_STMT(BPF_RET+BPF_K, (UINT )-1),	// Accept. Value is bytes to be returned
	BPF_STMT(BPF_RET+BPF_K, 0 )			// Reject
};

// This filter ACCEPTS all ARP packets, both RFC 894 And 802.3
static bpf_insn BPFAcceptARP[] =
{
	// Handle 802.3 Case
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MLength),
	BPF_JUMP(BPF_JMP+BPF_JGT+BPF_K, 0x5DC, 13, 0),

	// Check 802.2 LLC. SAP 0xAA (SNAP), Control 0x03
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LDSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xAA, 0, 11),
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LSSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xAA, 0, 9),
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LCntrl),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x3, 0, 7),

	// Internet Organization/Vendor Code 0x000000
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + SType + 0),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x00, 0, 5),
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MHdrSize + SType + 1),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x0000, 0, 3),

	// ARP Protocol 0x0806
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MHdrSize + SType + 3),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, ETHERTYPE_ARP, 0, 1),

	BPF_STMT(BPF_RET+BPF_K, (UINT )-1),	// Accept. Value is bytes to be returned

	// Handle Ethernet RFC 894 Case
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, 12),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, ETHERTYPE_ARP, 0, 1),

	BPF_STMT(BPF_RET+BPF_K, (UINT )-1),	// Accept. Value is bytes to be returned
	BPF_STMT(BPF_RET+BPF_K, 0 )			// Reject
};

// This filter ACCEPTS all RARP packets, both RFC 894 And 802.3
static bpf_insn BPFAcceptRARP[] =
{
	// Handle 802.3 Case
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MLength),
	BPF_JUMP(BPF_JMP+BPF_JGT+BPF_K, 0x5DC, 13, 0),

	// Check 802.2 LLC. SAP 0xAA (SNAP), Control 0x03
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LDSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xAA, 0, 11),
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LSSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xAA, 0, 9),
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LCntrl),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x3, 0, 7),

	// Internet Organization/Vendor Code 0x000000
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + SType + 0),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x00, 0, 5),
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MHdrSize + SType + 1),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x0000, 0, 3),

	// RARP Protocol 0x8035
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MHdrSize + SType + 3),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, ETHERTYPE_REVARP, 0, 1),

	BPF_STMT(BPF_RET+BPF_K, (UINT )-1),	// Accept. Value is bytes to be returned

	// Handle Ethernet RFC 894 Case
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, 12),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, ETHERTYPE_REVARP, 0, 1),

	BPF_STMT(BPF_RET+BPF_K, (UINT )-1),	// Accept. Value is bytes to be returned
	BPF_STMT(BPF_RET+BPF_K, 0 )			// Reject
};

// This filter ACCEPTS all NETBEUI packets
static bpf_insn BPFAcceptNETBEUI[] =
{
	// Must be 802.3
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MLength),
	BPF_JUMP(BPF_JMP+BPF_JGT+BPF_K, 0x5DC, 5, 0),	// Check 802.3 Length

	// SAP 0xF0
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LDSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xF0, 0, 3),
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LSSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xF0, 0, 1),

	BPF_STMT(BPF_RET+BPF_K, (UINT )-1),	// Accept. Value is bytes to be returned
	BPF_STMT(BPF_RET+BPF_K, 0 )	// Reject
};

// This filter ACCEPTS all EtherTalk Phase 2 packets
static bpf_insn BPFAcceptEtalk2[] =
{
	// Must be 802.3
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MLength),
	BPF_JUMP(BPF_JMP+BPF_JGT+BPF_K, 0x5DC, 13, 0),

	// Check 802.2 LLC. SAP 0xAA (SNAP), Control 0x03
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LDSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xAA, 0, 11),
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LSSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xAA, 0, 9),
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LCntrl),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x3, 0, 7),

	// Apple Ethernet Organization/Vendor Code 0x080007
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + SType + 0),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x08, 0, 5),
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MHdrSize + SType + 1),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x0007, 0, 3),

	// EtherTalk Protocol 0x809B
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MHdrSize + SType + 3),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, ETHERTYPE_ATALK, 0, 1),

	BPF_STMT(BPF_RET+BPF_K, (UINT )-1),	// Accept. Value is bytes to be returned
	BPF_STMT(BPF_RET+BPF_K, 0 )	// Reject
};

// This filter ACCEPTS all IPX packets
// See the reference:
//    Novell's Guide To NetWare LAN Analysys, Second Edition
//    Laura A Chappell and Dan E. Hawkes
//    Novell Press
//    ISBN 0-7821-1362-1
static bpf_insn BPFAcceptIPX[] =
{
	// Must be 802.3
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MLength),
	BPF_JUMP(BPF_JMP+BPF_JGT+BPF_K, 0x5DC, 5, 0),	// Check 802.3 Length

	// Check IPX. First Two Data Bytes Are 0xFF
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xFF, 0, 3),

	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + 1),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xFF, 0, 1),

	BPF_STMT(BPF_RET+BPF_K, (UINT )-1),	// Accept. Value is bytes to be returned
	BPF_STMT(BPF_RET+BPF_K, 0 )	// Reject
};

// This filter ACCEPTS DEC Experimental packets
static bpf_insn BPFAcceptDECExperimental[] =
{
	// Handle 802.3 Case
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MLength),
	BPF_JUMP(BPF_JMP+BPF_JGT+BPF_K, 0x5DC, 12, 0),

	// Check 802.2 LLC. SAP 0xAA (SNAP), Control 0x03
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LDSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xAA, 0, 13),
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LSSAP),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0xAA, 0, 11),
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + LCntrl),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x3, 0, 9),

	// Internet Organization/Vendor Code 0x000000
	BPF_STMT(BPF_LD+BPF_B+BPF_ABS, MHdrSize + SType + 0),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x00, 0, 7),
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MHdrSize + SType + 1),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, 0x0000, 0, 5),

	// Internet Protocol 0x0800
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, MHdrSize + SType + 3),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, ETHERTYPE_DECEXP, 2, 3),

	// Handle Ethernet RFC 894 Case
	BPF_STMT(BPF_LD+BPF_H+BPF_ABS, 12),
	BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, ETHERTYPE_DECEXP, 0, 1),

	BPF_STMT(BPF_RET+BPF_K, (UINT )-1),	// Accept. Value is bytes to be returned
	BPF_STMT(BPF_RET+BPF_K, 0 )			// Reject
};

#define TEMP_START	273
#define TEMP_STOP		487
short iTempCalibrationTable[TEMP_STOP-TEMP_START];

#ifdef _DEBUG
PUCHAR pDestAddress = NULL;
PBYTE	 pCurrentAddress = NULL;
#endif

#ifndef	AMPCONFIG_INCLUDE_HIPASSFILTER
// HiPass Filter value is NOT configurable, this 
// value required for correct Malibu Amp operation
const UCHAR CCommunication::m_iHighPassShift = 16;
#endif

// Implement Singleton pattern
CCommunication& CCommunication::Instance()
{
    static CCommunication theAmp;
	return theAmp;
}

CCommunication::CCommunication()
    : m_lLastAmpPacketSequence(0)
    , m_bAmpSequenceCheckingStarted(false)
    , m_RxPacketMeter(2000) // 2K Hz is the expected nominal RX data rate
	, m_bAmplifierResetFlag(false)
{
#ifdef _DEBUG
	pDestAddress = m_DestAddress;
	pCurrentAddress = m_Adapter.m_CurrentAddress;
#endif

	::InitializeCriticalSection(&this->m_csLock);

	Reset();

#define TABLE_SPACE_BY_20 20
	short iTable[11]= { 273, 302, 331, 357, 380, 402, 422, 440, 457, 472, 487   };

	for(register int n=0; n<(TEMP_STOP-TEMP_START); n++)
	{
		for(register int j=1; j<11; j++)
		{
			int iTemp = TEMP_START+n;

			if (iTemp <= iTable[j])
			{
				iTempCalibrationTable[n] = 
					300-TABLE_SPACE_BY_20+TABLE_SPACE_BY_20*j+(short)((iTemp-iTable[j-1])*TABLE_SPACE_BY_20*1.0/(iTable[j]-iTable[j-1]) + 0.5);
				break;
			}
		}
	}

    // MS appartently flagged std::fill_n() as deprecated so fill the old school way
    for (int i = 0; i < MAX_CHANNELS; ++i) { m_BadDataBuffer[i] = BAD_ECG_VALUE_32BIT; }
}

void CCommunication::Reset(void)
{
	ZEROSET(m_BPFProgram);
	ZEROSET(m_AppVersionInfo);
	MEMSET(m_szAppVersionString);
	MEMSET(m_szGSharedParmsName);
	MEMSET(m_szAdapterName);
	MEMSET(m_szHookPeekPrefix);	::WMStrnCpy(m_szHookPeekPrefix, _T("HOOKPEEKShared_"), sizeof(m_szHookPeekPrefix));
	MEMSET(m_DestAddress);
	ZEROSET(m_DriverVersionInfo);

    m_iBPFDumpExe               = 0;       // Carefully set the bool flags
    m_bShutdown                 = false;
    m_bSendPackets              = false;
    m_bEnableLoopback           = false;
    m_bSendThreadAlive          = false;
    m_bReceiveThreadAlive       = false;
    m_dwSendCreateCount         = 0;
    m_dwSendImmediateCount      = 0;
    m_dwSendDestroyCount        = 0;
    m_dwPendingSendAPCCount     = 0;
    m_hReceiveThread            = NULL;
    m_dwReceiveThreadId         = 0;
    m_hSendThread               = NULL;
    m_dwSendThreadId            = 0;
    m_hFileMap                  = NULL;  // handle to file mapping
    m_pSSharedParms             = NULL;
    m_uiFirstPacketTimeReceived = 0;
    m_uiLastPacketTimeReceived  = 0; 
    m_iDriverDroppedPacketCount = 0;
    m_iDroppedPacketCount       = 0;
    m_uiCommPauseCount          = 0;
    m_uiTotalPackets            = 0;
	m_bAmplifierResetFlag		= false;

	// whenever we reset our communications with the amplifier (this includes initial start-up),
	// we request railed pressure data. this means that the user must perform zero offset
	// calculation on all pressure channels.
	//
	// it doesn't matter what default value we use for the pressure offsets since:
	// 1. we write a value to it once we successfully zero the pressure channel.
	// 2. we read a value from it only after we have successfully zeroed the pressure channel.
	//
	for (int i = 0; i < WM_PACKET_AMPLIFIER_PRESSURE_CHANNEL_COUNT; ++i) {
		m_ariZeroPressure[i] = PRESSURE_RAILED;
		m_arlPressureOffset[i] = 0;
	}

	this->SetConnectionState(IAmplifierStatus::ConnectionStateOffline);
	this->m_bAmplifierNotification = false;
	this->m_bAmplifierErrorClearPending = false;
	this->m_bLastPacketValid = false;
	this->m_lLastAcknowledgedCommandPacket = 0;

    m_RxPacketMeter.Reset();
}

CCommunication::~CCommunication(void)
{
	m_hReceiveThread			=	NULL;
	m_hSendThread				=	NULL;
	m_hFileMap					=	NULL;  // handle to file mapping
	m_pSSharedParms			=	NULL;

	::DeleteCriticalSection(&this->m_csLock);
}

///<ImplementInterfaces>
UINT CCommunication::GetTotalPackets    () const { return m_uiTotalPackets;     }
void CCommunication::ResetTotalPackets  ()       {        m_uiTotalPackets = 0; }

UINT CCommunication::GetCommPauseCount  () const { return m_uiCommPauseCount;     }
void CCommunication::ResetCommPauseCount()       {        m_uiCommPauseCount = 0; }

UINT CCommunication::GetDroppedPacketCount  () const { return m_iDroppedPacketCount;     }
void CCommunication::ResetDroppedPacketCount()       {        m_iDroppedPacketCount = 0; }

UINT CCommunication::GetFirstPacketTimeReceived   () const { return m_uiFirstPacketTimeReceived; }
void CCommunication::ResetFirstPacketTimeReceived ()              { m_uiFirstPacketTimeReceived = 0; }

UINT CCommunication::GetLastPacketTimeReceived    () const { return m_uiLastPacketTimeReceived; }
void CCommunication::ResetLastPacketTimeReceived  ()              { m_uiLastPacketTimeReceived = 0; }

void CCommunication::ResetDataRateMonitor()
{
    m_RxPacketMeter.Reset();
}

IAmplifierStatus::ConnectionState CCommunication::GetConnectionState() const
{
	return this->m_enumConnectionState;
}

bool CCommunication::IsConnectionStateConnected() const
{
	return this->m_enumConnectionState == ConnectionStateConnected;
}

///<GetMeasuredRateData>
// The RxMeter doesn't have knowledge about the amp connection state.
// It retains it's last measured rate when we stop calling it 
// in response to packets received by the Rx comm thread.
// And when reset, it defaults to reporting nominal rates until it 
// accumulates the amount of data it was configured to accumulate 
// before reporting live rates.
// So in these methods, ignore it's rate when not receiving packets.
double CCommunication::GetRxRate() const 
{
    return (m_enumConnectionState == ConnectionStateConnected) ?
                    m_RxPacketMeter.GetCurrentRate() : 
                    0.0L;
}
bool CCommunication::IsRxWithinSpec() const
{
    return  
        m_enumConnectionState == ConnectionStateConnected ?
            m_RxPacketMeter.IsWithinBounds() : 
            true;
}
///</GetMeasuredRateData>

UINT   CCommunication::GetRxRateThresholdLow()        const
{
    return static_cast<UINT>(m_RxPacketMeter.GetLowThresholdRate());
}

UINT   CCommunication::GetRxRateThresholdHigh()       const
{
    return static_cast<UINT>(m_RxPacketMeter.GetHighThresholdRate());
}

void CCommunication::SetObserver(IAmplifierStatusObserver* pObserver)
{
    m_RxPacketMeter.SetObserver(pObserver);
}
void CCommunication::ClearObserver()
{
    m_RxPacketMeter.ClearObserver();
}

bool CCommunication::StartMonitoring()
{
	#ifdef DEMO_CD_ROM
		return true;
	#endif

	if(theApp.m_INIfile.m_iNetworkAdapter==NO_NETWORK_ADAPTER)
	{
		return false;
	}

	GetAppVersion();

	if( !GetAdapterInfo() )	
	{
		CMessage::StartupMessage(WMFILELINE, 49, NULL, true, true);

		return false;	
	}

	const int iMaxAdapters=m_vtAdapterArray.size();
	if( iMaxAdapters<=0 || theApp.m_INIfile.m_iNetworkAdapter>iMaxAdapters)	
	{	
		CMessage::StartupMessage(WMFILELINE, 50, NULL, true, true);

		return false;	
	}

	int iAdpaterNumber = theApp.m_INIfile.m_iNetworkAdapter-1;

	/*if(theApp.m_osInfo.dwPlatformId==VER_PLATFORM_WIN32_NT)
	{
		if(theApp.m_osInfo.dwMajorVersion==5 && theApp.m_osInfo.dwMinorVersion==1)	// WinXP
		{
			iAdpaterNumber = theApp.m_INIfile.m_iNetworkAdapter;
		}
	}*/

	if(iAdpaterNumber==-1)
	{
		CMessage::StartupMessage(WMFILELINE, 49, NULL, true, true);

		return false;
	}

	CAdapterInfo& aiAdapterInfo = m_vtAdapterArray[iAdpaterNumber];

	if(theApp.m_osInfo.dwPlatformId==VER_PLATFORM_WIN32_NT && theApp.m_osInfo.dwMajorVersion==5)
	{
		::WMStrnCpy( m_szAdapterName, aiAdapterInfo.cServiceName, sizeof(m_szAdapterName) );
	}
	else
	{
		::WMStrnCpy( m_szAdapterName, aiAdapterInfo.m_csSymbolicLink, sizeof(m_szAdapterName) );
	}

	if(!Initialize())	
	{	
		CMessage::StartupMessage(WMFILELINE, 51, m_szAdapterName, true, true);

		return false;	
	}


	if(!StartListening())
	{
		return false;
	}
	
	if(!SendMessage())
	{
		return false;
	}

	return true;
}

void CCommunication::RequestAmplifierReset()
{
	this->m_bAmplifierResetFlag = true;
}

#ifdef PACKETMETER_DIAGNOSTICS
void CCommunication::GenerateDiagnosticLog()
{
    m_RxPacketMeter.GenerateLog();
}
#endif

///</ImplementInterfaces>

// Extract the application version number from the version resource. 
//	Application version information is saved in the m_AppVersionInfo variable.
void CCommunication::GetAppVersion( void ) 
{
   ::WMStrnCpy( m_szAppVersionString, _T("Unknown"), sizeof(m_szAppVersionString) );

   TCHAR szFileName[MAX_PATH]={0};

   if( GetModuleFileName( NULL, szFileName, MAX_PATH) > 0 )	{

      DWORD dwType =0;

      DWORD dwDataLen = GetFileVersionInfoSize( szFileName, &dwType );

      PTCHAR pszBuffer = WMAlloc<PTCHAR>(dwDataLen+1);

      if (!pszBuffer)	{	return;	}

      if( GetFileVersionInfo(szFileName, 0L, dwDataLen, pszBuffer) )	
		{
         VS_FIXEDFILEINFO* pFileInfo = NULL;

         if( VerQueryValue( pszBuffer, _T("\\"), (LPVOID*)&pFileInfo, (PUINT)&dwDataLen) )	
			{
            memcpy( &m_AppVersionInfo, pFileInfo, sizeof( VS_FIXEDFILEINFO ) );

            _stprintf(	m_szAppVersionString,	
							_T("%d.%2.2d.%2.2d.%2.2d"), 
							HIWORD(m_AppVersionInfo.dwFileVersionMS ), 
							LOWORD(m_AppVersionInfo.dwFileVersionMS ),
							HIWORD(m_AppVersionInfo.dwFileVersionLS ), 
							LOWORD(m_AppVersionInfo.dwFileVersionLS ));
         }
      }

      WMFree( pszBuffer);
   }

   // Say Hello
   AfxTrace( _T("WinDis 32 Packet Dump Utility APC Version %s\n"), m_szAppVersionString );
}

bool	CCommunication::Initialize(void)
{
   // Initialize The Trivial BPF Filter Program
	InitBPFProgram( );

	// Possibly Dump Packet Filter Code
   if( m_iBPFDumpExe && m_BPFProgram.bf_len && m_BPFProgram.bf_insns )
	{
		switch( m_iBPFDumpExe )
		{
      case 1:
			AfxTrace( _T("BPF Filter Dump - As Compiled Human Readable Form\n") );
         break;

      case 2:
         AfxTrace( _T("BPF Filter Dump - As  C Program Fragment\n") );
         break;

      case 3:
         AfxTrace( _T("BPF Filter Dump - As Decimal Numbers\n") );
         break;

      default:
			AfxTrace( _T("BPF Filter Dump\n") );
         break;
      }

      bpf_dump( &m_BPFProgram, m_iBPFDumpExe );
   }

	if(theApp.m_osInfo.dwPlatformId==VER_PLATFORM_WIN32_NT && theApp.m_osInfo.dwMajorVersion==5)
	{
		_stprintf( m_Adapter.m_szAdapterName, _T("\\Device\\%s"), m_szAdapterName );

		AfxTrace( _T("AdapterName : \042%s\042\n"), m_Adapter.m_szAdapterName );

		m_Adapter.m_hDevice = W32N_OpenAdapter( m_Adapter.m_szAdapterName );
	}
	else
	{
		_tcscpy( m_Adapter.m_szAdapterName, m_szAdapterName );

		AfxTrace( _T("AdapterName : \042%s\042\n"), m_Adapter.m_szAdapterName );

		m_Adapter.m_hDevice = W32N_OpenAdapter( m_Adapter.m_szAdapterName );
	}

	DWORD nResult = 0;

   if( m_Adapter.m_hDevice == INVALID_HANDLE_VALUE )	{

      nResult = W32N_GetLastError();

      AfxTrace( _T("Could Not Open Adapter; Error 0x%8.8X\n"), nResult );

      // Free The Trivial BPF Filter Program
      FreeBPFProgram( );

      return false;      // No Complaints
   }

   AfxTrace( _T("Adapter Opened\n") );

   // Create The Global OVERLAPPED Event To Wait On
   m_Adapter.m_OverLapped.hEvent = CreateEvent(	NULL,      // Security Attributes
																FALSE,   // Auto-Reset
																FALSE,   // Initial State Signaled
																NULL      // Event-object Name
															);

   if( !m_Adapter.m_OverLapped.hEvent )	{

      W32N_CloseAdapter( m_Adapter.m_hDevice );

      AfxTrace( _T("Could Not Create Event\n") );

      // Free The Trivial BPF Filter Program

      FreeBPFProgram( );

      return false;      // No Complaints
   }

   ResetEvent( m_Adapter.m_OverLapped.hEvent );

   // Display Adapter Information

   bool bResult = DisplayAdapterInfo();

   if( !bResult )	{

      // Close The Global Event Handle
      CloseHandle( m_Adapter.m_OverLapped.hEvent );	m_Adapter.m_OverLapped.hEvent=NULL;

      // Close The Adapter
      W32N_CloseAdapter( m_Adapter.m_hDevice );

      // Free The Trivial BPF Filter Program
      FreeBPFProgram( );

      AfxTrace( _T("Could Not Get Adapter Information\n") );

      return false;      // No Complaints
   }

   // Possibly Disable Loopback At Driver Level
   if( !m_bEnableLoopback )	{

       DisableLoopback();
   }


   // Create The Shared Memory
   TCHAR* s = _tcsrchr( m_Adapter.m_szAdapterName, '\\' );

   if( s )
	{
      ++s;
   }	
	else	
	{
      s = m_Adapter.m_szAdapterName;
   }

   if( s && *s )
	{
      _stprintf( m_szGSharedParmsName, _T("%s%s"), m_szHookPeekPrefix, s );

      m_hFileMap = CreateFileMapping((HANDLE) MAXDWORD,		// use paging file
													NULL,                // no security attributes
													PAGE_READWRITE,      // read/write access
													0,                   // size: high 32-bits
													sizeof( SSharedParms ),   // size: low 32-bits
													m_szGSharedParmsName   // name of map object
													);

      if( m_hFileMap == NULL )
		{
         AfxTrace( _T("HookPeek could not create shared memory file.\n") );

         return false;
      }

      // The First Process To Attach Initializes Memory
      bool bInit = (GetLastError() != ERROR_ALREADY_EXISTS); 

      // Get A Pointer To The File-Mapped Shared Memory
      m_pSSharedParms = (SSharedParms*) MapViewOfFile(m_hFileMap,     // object to map view of
																		FILE_MAP_WRITE, // read/write access
																		0,              // high offset:  map from
																		0,              // low offset:   beginning
																		0);             // default: map entire file

      if (m_pSSharedParms == NULL)	{	return false; }

      // Initialize Memory If This Is The First Process
      if( bInit )
		{
         memset(m_pSSharedParms, _T('\0'), sizeof( SSharedParms ) );
		}
   }

   // Increment Usage Count
   if( m_pSSharedParms )
	{
      InterlockedIncrement( &m_pSSharedParms->m_nAdapterUseCount );
   }

   m_bShutdown = false;

   AfxTrace( _T("Starting Packet Reception...\n") );


   // Handle The BPF Filter Program, If Any
   if( m_BPFProgram.bf_len && m_BPFProgram.bf_insns )
	{
		#ifdef USE_TEST_FILTER
      
			// Dump Test BPF Programs
			DumpBPFTestPrograms();

			// Pass Down Test BPF Program
			W32N_SetBPFProgram(m_Adapter.m_hDevice, BPFFilterStep5, 14 * sizeof( struct bpf_insn ) ); // Get This Right!!!
               
		#else
      
			// Pass Down BPF Program
			W32N_SetBPFProgram( m_Adapter.m_hDevice, m_BPFProgram.bf_insns, m_BPFProgram.bf_len * sizeof( struct bpf_insn ) );

		#endif
   }
	else
	{
      // Remove Any Existing BPF Program

      W32N_SetBPFProgram( m_Adapter.m_hDevice, NULL, 0 );
   }

   // Free The Trivial BPF Filter Program
   FreeBPFProgram();

	return true;
}

//// InitBPFProgram
void CCommunication::InitBPFProgram(void)
{
	m_BPFProgram.bf_insns = NULL;
	m_BPFProgram.bf_len = 0;
}

// Purpose	: Helper for BPFProgramAppend.
// Parameters:	pBPFProgram - Pointer to existing BPF program.
//					pBPFNewInstructions - BPF instructions to be appended to pBPFProgram
//					nNewBPFInstructionsLen - Length (number of BPF instruictions) to be appended to pBPFProgram
																// Instructions To Add
DWORD CCommunication::BPFProgramAppend(bpf_insn* pBPFNewInstructions, UINT nNewBPFInstructionsLen)
{
	bpf_insn* pOldBPFInstructions = m_BPFProgram.bf_insns;

	UINT nOldBPFInstructionsLen = m_BPFProgram.bf_len;

	if( !pOldBPFInstructions )
	{
		// No Existing Program. Allocate Memory 
		m_BPFProgram.bf_insns = WMAlloc<bpf_insn*>( nNewBPFInstructionsLen * sizeof( bpf_insn ) );

		if( m_BPFProgram.bf_insns )
		{
			memcpy(m_BPFProgram.bf_insns, pBPFNewInstructions, nNewBPFInstructionsLen * sizeof( bpf_insn ) );

			m_BPFProgram.bf_len = nNewBPFInstructionsLen;
		}
	}
	else
	{
		// Existing Program. Reallocate Memory

		m_BPFProgram.bf_insns = (bpf_insn * )realloc( m_BPFProgram.bf_insns, ( nNewBPFInstructionsLen + nOldBPFInstructionsLen - 1 )* sizeof( bpf_insn ) );

		if( m_BPFProgram.bf_insns )
		{
			memcpy( &m_BPFProgram.bf_insns[ nOldBPFInstructionsLen - 1 ], pBPFNewInstructions, nNewBPFInstructionsLen * sizeof( bpf_insn ) );

			m_BPFProgram.bf_len = nOldBPFInstructionsLen + nNewBPFInstructionsLen;
		}
	}

	return ERROR_SUCCESS;
}

// Purpose	:	Concatenate a new set of BPF instructions to an existing BPF program.
// Parameters	:	pBPFProgram - Pointer to existing BPF program.
//						nIPProtocol - IP protocol type. Usually one of these:
//                1 - ICMP
//                2 - IGMP
//                6 - TCP
//                17 - UDP
// Remarks	:	This routine uses the BPFAcceptTCP instructions as a TEMPLATE. Since a IP protocol filter differs only in the IP protocol number, this
// routine simply jams the desired IP protocol number into the BPFAcceptTCP TEMPLATE and then concatenates the instructions with the existing
// BPF program. Once again, a "trivial" approach to building a BPF filter program.
DWORD CCommunication::ConcatIProtoProgram(INT nIPProtocol)
{
	BPFAcceptTCP[ 3 ].k = nIPProtocol;		// Overwrite Template Value

	DWORD nResult = BPFProgramAppend( BPFAcceptTCP, TPF_TCP_PROGLEN);

	return( nResult );
}

/////////////////////////////////////////////////////////////////////////////
//// ConcatBPFProgram
// Purpose	:	Concatenate a new set of BPF instructions to an existing BPF program.
// Parameters	:	pBPFProgram - Pointer to existing BPF program.
// nTPFProtoType - Specifies protocol filtering instructions to add.
//                 Defined in tpfilter.h
// Remarks	:	If pBPFProgram is NULL, this routine allocates new memory for the specified instructions.
//
// If pBPFProgram is not NULL, then memory is re-allocated. Re-allocation copies the existing program into the expanded memory and provides space
// for the new program instructions.
//
// The new BPF instructions are then copied into the re-allocated memory so that the first new instruction overwrites the last instruction of
// the existing program. This trivial scheme works ONLY because every filter is designed so that it's last BPF instruction is the REJECT instruction.
// So, overwriting the REJECT instruction with the first byte of the new instruction set effectively extends the filter program.
//
// This is, obviously, a very simple-minded scheme - worthy of improvement in any commercial product. That's why it's called "trivial".
DWORD CCommunication::ConcatBPFProgram(TPF_PROTO_TYPE nTPFProtoType)
{
	DWORD nResult=0;

	switch( nTPFProtoType )	{

	case TFP_IP_PROTO:
		nResult = BPFProgramAppend( BPFAcceptIP, TPF_IP_PROGLEN );
		break;

	case TFP_ARP_PROTO:
		nResult = BPFProgramAppend( BPFAcceptARP, TPF_ARP_PROGLEN );
		break;

	case TFP_RARP_PROTO:
		nResult = BPFProgramAppend(BPFAcceptRARP, TPF_RARP_PROGLEN);
		break;

	case TFP_NETBEUI_PROTO:
		nResult = BPFProgramAppend( BPFAcceptNETBEUI, TPF_NETBEUI_PROGLEN);
		break;

	case TFP_ETALK2_PROTO:
		nResult = BPFProgramAppend( BPFAcceptEtalk2, TPF_ETALK2_PROGLEN);
		break;

	case TFP_IPX_PROTO:
		nResult = BPFProgramAppend( BPFAcceptIPX, TPF_IPX_PROGLEN);
		break;

	case TFP_DECEXP_PROTO:
		nResult = BPFProgramAppend( BPFAcceptDECExperimental, TPF_DECEXP_PROGLEN );
		break;

	case TFP_IP_PROTO_TCP:
		nResult = ConcatIProtoProgram(6 );	// TCP is 6
		break;

	case TFP_IP_PROTO_UDP:
		nResult = ConcatIProtoProgram(17 );	// UDP is 17
		break;

	case TFP_IP_PROTO_ICMP:
		nResult = ConcatIProtoProgram(1 );	// ICMP is 1
		break;

	case TFP_IP_PROTO_IGMP:
		nResult = ConcatIProtoProgram(2 );	// IGMP is 2
		break;

	default:
		nResult = ERROR_BAD_COMMAND;
		break;
	}

	return nResult;
}

void CCommunication::FreeBPFProgram(void)
{
	if( m_BPFProgram.bf_len && m_BPFProgram.bf_insns )	{

		// Free Memory 
		WMFree( m_BPFProgram.bf_insns );
	}

	// Re-Initialize The BPF Program 
	InitBPFProgram();
}

void CCommunication::ShutDown()
{
	#ifdef DEMO_CD_ROM
		return;
	#endif

	if(theApp.m_INIfile.m_iNetworkAdapter==NO_NETWORK_ADAPTER)	{	return;	}

	if(m_hReceiveThread==NULL || m_hSendThread==NULL)	{

		CMessage::PopupMessage(WMFILELINE, 52);

		return;	
	}

   //::SuspendThread(m_hReceiveThread);
   //::SuspendThread(m_hSendThread);
	m_bShutdown = true;
	//::ResumeThread(m_hReceiveThread);
	//::ResumeThread(m_hSendThread);

	// Sanity Checks

   if( m_Adapter.m_hDevice == INVALID_HANDLE_VALUE )	{	return;	}

   // Call Driver To Stop Reception

   AfxTrace( _T("\nStopping Packet Reception\n") );

   StopReception();      // Let main() do this...

	// Lets give the threads some time to catch up
	//Sleep(1500);

   // Display Application Statistics

   AfxTrace( _T("Application Statistics:\n") );
   AfxTrace( _T("  Received Packet Count       : %d\n"), m_Adapter.m_nReceivedPacketCount );

   if( m_Adapter.m_nSequenceErrorCount )	
	{
		AfxTrace( _T("    Sequence Error Count      : %d (+%d/-%d)\n"), m_Adapter.m_nSequenceErrorCount, m_Adapter.m_nSequenceErrorPlus, m_Adapter.m_nSequenceErrorMinus );
	}

   AfxTrace( _T("      Sent Packet Count       : %d\n"), m_Adapter.m_nSendPacketCount );

   AfxTrace( _T("Pending Send APC Count        : %d\n"), m_dwPendingSendAPCCount );

	AfxTrace( _T("      Sent C/D/I Counts       : %d/%d/%d\n"), m_dwSendCreateCount, m_dwSendDestroyCount, m_dwSendImmediateCount );

   AfxTrace( _T("\n") );

   // Display Protocol Statistics

   DisplayProtocolStatistics();

	DWORD  nResult = 0;

   // Wait For Receive Thread To Die Or 5-second Timeout

   if( m_hReceiveThread )	
	{
		AfxTrace( _T("WinYield:ReceiveThread\t") );

      //nResult = WaitForSingleObject( m_hReceiveThread, 10000 );	// More Waiting

		CWMLibrary::WinYield(m_bReceiveThreadAlive, 0, true);

		AfxTrace( _T(": ReceiveThread Returned\n") );

      CloseHandle( m_hReceiveThread );

		m_bReceiveThreadAlive = false;

		m_hReceiveThread = NULL;
   }

   // Wait For Send Thread To Die Or 5-second Timeout

   if( m_hSendThread )	
	{
		AfxTrace( _T("WinYield : SendThread\t") );

      CWMLibrary::WinYield(m_bSendThreadAlive, 0, true);
		
		//nResult = WaitForSingleObject( m_hSendThread, 5000 );

		AfxTrace( _T(": SendThread Returned\n") );

      CloseHandle( m_hSendThread );

		m_bSendThreadAlive = false;

		m_hSendThread = NULL;
   }

   // Handle Possible Closing Of Shared Memory
   if( m_pSSharedParms )   {

      // Decrement Usage Count

      InterlockedDecrement( &m_pSSharedParms->m_nAdapterUseCount );

      if( m_pSSharedParms->m_nAdapterUseCount == 0 )	{

         // Last Instance Processing
         // ------------------------
         // Entering this statement indicates that this is the last
         // instance of HookPeek which is using the global shared
         // memory area. There may be special processing that the
         // last HookPeek instance should do.
         //
         // In this case, StopReception() should be called only by
         // the exiting of the last instance of HookPeek.
         //
         // After performing Last Instance Processing, the shared
         // memory mapping must be unmapped and the file-mapping
         // object must be closed.

         // Call Driver To Stop Reception
         StopReception();
      }

      // Unmap Shared Memory From The Process's Address Space
      UnmapViewOfFile( m_pSSharedParms );

      m_pSSharedParms = NULL;
   }

   if( m_hFileMap )   {

      // Close The Process's Handle To The File-Mapping Object
      CloseHandle(m_hFileMap);
   }

   m_hFileMap = NULL;

   // Close The Adapter
   if( m_Adapter.m_hDevice != INVALID_HANDLE_VALUE )	{

      W32N_CloseAdapter( m_Adapter.m_hDevice );
   }

   m_Adapter.m_hDevice = INVALID_HANDLE_VALUE;

   // Destroy The Receive Packages
   // ----------------------------
   // NOTE: In WinDis 32 V4.20.08.28 and earlier DestroyReceivePackages()
   // was called BEFORE the call to W32N_CloseAdapter(). This was a bug.
   //
   // In WinDis 32 versions after V4.20.08.28, W32N_CloseAdapter() cancels
   // pending W32N_PacketRead() operations. DestroyReceivePackages() must be called
   // AFTER W32N_CloseAdapter() or the NDISHOOK driver will attempt to
   // cancel read operations whose associated memory has been freed. This
   // causes a page fault!!!

   DestroyReceivePackages();

   // Close The Global Event Handle
   if( m_Adapter.m_OverLapped.hEvent )
	{
      CloseHandle( m_Adapter.m_OverLapped.hEvent );
   }

   m_Adapter.m_OverLapped.hEvent = NULL;

}

// Purpose	:	Common function which performs packet read completion for Windows 95 and Windows NT platforms. Called from a platform-specific APC.
DWORD CCommunication::HandleReadComplete( PSReceivePackage pRxPackage )
{
   if( m_bShutdown )	{	return( 0 );	}

   // Sanity Checks
   // ATTENTION!!! Use additional sanity checks (e.g., signature...)

   if( IsValidReceivePackage( pRxPackage ) )
	{
      // Check For Error
      // ---------------
      // NOTE: WinDis 32 V4.20.09.29 added the mechanism to check for the completion status of W32N_PacketRead() operations. This
      // check was not present in versions prior to V4.20.09.29.

      if( pRxPackage->m_UserPacketData.nNdisStatus != NDIS_STATUS_SUCCESS )
		{
         //AfxTrace( "Read Error: 0x%4.4X\n", pRxPackage->m_UserPacketData.nNdisStatus );

         return( 0 );
      }

      ++((pRxPackage->m_pAdapter)->m_nReceivedPacketCount);

      // Display The Received Packet

      DisplayReceivedPacket(pRxPackage->m_pAdapter, &pRxPackage->m_UserPacketData);

      // Post Another Read On The Packet Package
      
      if( !m_bShutdown )
		{
			BOOLEAN	bResult = FALSE;

#if 0
         if( W32N_IsWindows95() )
			{
            bResult = W32N_PacketReadEx(	(pRxPackage->m_pAdapter)->m_hDevice,
														&pRxPackage->m_UserPacketData,
														&pRxPackage->m_dwBytesReturned,
														&pRxPackage->m_OverLapped,
														(PVOID) CCommunication::ReadCompleteApc95
													);

         } else 
#endif
            if( W32N_IsWindowsNT() )
				{

            bResult = W32N_PacketReadEx(	(pRxPackage->m_pAdapter)->m_hDevice,
														&pRxPackage->m_UserPacketData,
														&pRxPackage->m_dwBytesReturned,
														&pRxPackage->m_OverLapped,
														(PVOID ) CCommunication::ReadCompleteApcNT
													);
         }
			else
			{
            // ATTENTION!!! Deal with this case!!!
         }

         if( !bResult )
			{
				DWORD nResult = W32N_GetLastError();

            if( nResult != ERROR_IO_PENDING )
				{
               //AfxTrace( "W32N_PacketReadEx Failed; Error: 0x%8.8X\n", nResult );
            }
         }
      }
   }

   return 0;
}

VOID WINAPI CCommunication::ReadCompleteApcNT(DWORD dwErrorCode, DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped)
{
#ifndef PHILIPS_VIEWER
    CCommunication& theAmp = Instance();
    if( theAmp.m_bShutdown )	{	return; }

#if 0
   static INT64 lasttime=0;
   INT64 thistime=CWMApp::GetFastTimeUS();
   int totaltime=(int)thistime-lasttime;
   if (totaltime>2000) AfxTrace(_T("packet at %d\n"), totaltime);
   lasttime=thistime;
#endif
   
	// ATTENTION!!! Consider using try/except here...
	PSReceivePackage pRxPackage = (PSReceivePackage )lpOverlapped->OffsetHigh;

	// Call The Common Read Complete Handler
    theAmp.HandleReadComplete( pRxPackage );
#endif
}

DWORD WINAPI CCommunication::ReadCompleteApc95(LPOVERLAPPED lpOverlapped)
{
#ifndef PHILIPS_VIEWER
    CCommunication& theAmp = Instance();
   PSReceivePackage   pRxPackage;

    if( theAmp.m_bShutdown )	{	return 0;	}

   // ATTENTION!!! Consider using try/except here...
   pRxPackage = (PSReceivePackage )lpOverlapped->OffsetHigh;

   // Call The Common Read Complete Handler
   return theAmp.HandleReadComplete( pRxPackage);
#else
	return 0;
#endif
}

bool CCommunication::StartListening(void)
{
   // Create The Receive Thread
   m_hReceiveThread = CreateThread(	(LPSECURITY_ATTRIBUTES )NULL,				// No Security
												(DWORD )0,										// Same Stack Size
												(LPTHREAD_START_ROUTINE )ReceiveProc,	// Thread Procedure
												(PVOID )this,									// Parameter Pointer
												(DWORD )CREATE_SUSPENDED,					// Do Not Start Immediately
												&m_dwReceiveThreadId							// Thread ID
											);

	theApp.m_piInfo.SetThreadProcessor( m_hReceiveThread, 2 );
	BOOL bSuccess = ::SetThreadPriority( m_hReceiveThread, THREAD_PRIORITY_TIME_CRITICAL );
	::ResumeThread( m_hReceiveThread );

	AfxTrace(_T("CCommunication::Receive Thread ID : %x\n"), m_dwReceiveThreadId);

   if( !m_hReceiveThread )	
	{
      AfxTrace( _T("Could Not Start Receive Thread\n") );
   }

   // Call Driver To Start Reception
   // ------------------------------
   // Only allow FIRST instance of HookPeek to start promiscuous operation.
   // Understand that even though the receive thread has been started and packet read operations have been posted, no packets will
   // actually be received until the adapter's NDIS packet filter has been set. In this case, StartPromiscuousReception is the
   // function that sets the adapter's NDIS packet filter.

	bool bResult = false;

   if( m_pSSharedParms && m_hFileMap && m_pSSharedParms->m_nAdapterUseCount==1)	
	{   
		bResult = StartPromiscuousReception();
   }	
	else	
	{
      bResult = true;   // Reception Already Started By First Instance
   }

   if( !bResult ) 
	{
		_ftprintf(stderr, _T("Start Reception Failed\n"));

      m_bShutdown = true;

      DWORD nResult = WaitForSingleObject( m_hReceiveThread, 10000 );

      CloseHandle( m_hReceiveThread );

      m_hReceiveThread = NULL;

      W32N_CloseAdapter( m_Adapter.m_hDevice );

      DestroyReceivePackages();

      return false;
   }

	return true;
}

// Purpose	: HookPeek receive thread Thread Start routine.
DWORD WINAPI CCommunication::ReceiveProc(CCommunication* pCommunication)
{
#ifndef PHILIPS_VIEWER
	CCommunication& theAmp = Instance();
    theAmp.m_bReceiveThreadAlive = true;

   // Create An Event For The Thread To Wait On
   HANDLE hReceiveEvent = CreateEvent( NULL,
													FALSE,   // Auto-Reset
													FALSE,   // Initial State Signaled
													NULL );

   // Create Receive Packages
   theAmp.m_Adapter.m_pRxPackageBase = NULL;

   DWORD nResult = theAmp.CreateReceivePackages(NUM_RECIEVE_PACKAGES, FALSE);	  // Do Not Create Per-Package Event

   if( !nResult || theAmp.m_Adapter.m_nPackageCount == 0 )   
	{
      AfxTrace( _T("Could Not Create Read Packages\n") );

      return( 0 );
   }

   AfxTrace( _T("Using %d Read Packages (%dKB)\n"), theAmp.m_Adapter.m_nPackageCount, (theAmp.m_Adapter.m_nPackageCount * sizeof(SReceivePackage))/1024 );


   // Start All The Packet Reads

   for(register DWORD dwEachPackage=0; dwEachPackage<theAmp.m_Adapter.m_nPackageCount; ++dwEachPackage)	
	{
      PSReceivePackage pRxPackage = &theAmp.m_Adapter.m_pRxPackageBase[ dwEachPackage ];

      // Post The First Packet Read
      ResetEvent( pRxPackage->m_OverLapped.hEvent );

		BOOL bResult = FALSE;

#if 0
      if( W32N_IsWindows95() )	
		{
         bResult = W32N_PacketReadEx(	theAmp.m_Adapter.m_hDevice,
													&pRxPackage->m_UserPacketData,
													&pRxPackage->m_dwBytesReturned,
													&pRxPackage->m_OverLapped,
													CCommunication::ReadCompleteApc95
												);
      }	
		else 
#endif
			if( W32N_IsWindowsNT() )
			{

				bResult = W32N_PacketReadEx(theAmp.m_Adapter.m_hDevice,
													 &pRxPackage->m_UserPacketData,
													 &pRxPackage->m_dwBytesReturned,
													 &pRxPackage->m_OverLapped,
													 CCommunication::ReadCompleteApcNT
												    );
      }
		else	
		{
         // ATTENTION!!! Deal with this case!!!
      }

      if( !bResult )	
		{
         nResult = W32N_GetLastError();

         if( nResult == ERROR_IO_PENDING )	
			{
         }	
			else	
			{
            AfxTrace( _T("W32N_PacketReadEx Failed; Error: 0x%8.8X\n"), nResult );
         }
      }
   }

	DWORD dwConnectTime = 0;
	DWORD dwFlushTime = 0;

	theAmp.SetConnectionState(IAmplifierStatus::ConnectionStateOffline);

	while (theAmp.m_bShutdown == false) {
		// [hkc:04.22.2012]:
		//
		// Wait in an alertable state--thread must  be capable of being alerted
		// when a packet is received from a W32N_PacketReadEx() call above. The
		// event we wait on is not important, it will never be set. We are more
		// interested in the wait timeout, which specifies how long this thread
		// will wait for a packet until detecting a disconnection.

		const DWORD dwTimeOutMilliseconds = static_cast<DWORD>(1000);

		// [hkc:04.22.2012]:
		//
		// Following call places the calling thread into a wait state until one
		// of the following events occur:
		//
		// 1) Event hReceiveEvent was  set--this cannot occur--nothing sets it.
		// 2) Specified timeout dwTimeOutMilliseconds was exceeded during wait.
		// 3) Thread was interrupted to process APC call (W32N_PacketReadEx()).
		//
		// If the specified timeout is exceeded,  this signals that we have not
		// received any packets from the amplifier.
		// 
		// If the thread was interrupted to process APC call, this signals that
		// we have received and processed a new packet from the amplifier.

		DWORD dwWaitResult =
			::WaitForSingleObjectEx(
				hReceiveEvent,
				dwTimeOutMilliseconds,
				TRUE
			);

		// [hkc:06.11.2012]:
		//
		// IF: GUI requested that the amplifier error be cleared. Such requests
		// must be queued since the communications thread is solely responsible
		// for updating the amplifier status.   Clear the amplifier status here
		// and simulate a disconnection from the amplifier (WAIT_TIMEOUT). This
		// will force application to re-initiate the handshaking algorithm with
		// the amplifier (involves purging existing packets on the wire).

		if (theAmp.m_bAmplifierErrorClearPending) {
			theApp.m_INIfile.m_dwAmplifierStatus = AMP_STATUS_OK;
			dwWaitResult = WAIT_TIMEOUT;
		}

		if (theAmp.m_bShutdown == false) {
			switch (dwWaitResult) {
			case WAIT_TIMEOUT:
				// [hkc:04.22.2012]: packet not received within timeout period.
				if (theApp.m_dMonitor.m_bEnetInterrupts) {
					theAmp.OnAmplifierDisconnect();
                    // Force an RX rate update because no recently received 
                    // packets have come in to trigger one in the normal fashion
                    theAmp.m_RxPacketMeter.Update();
				}
				else {
					// [hkc:04.22.2012]: no-op:   amplifier still disconnected.
				}
				theAmp.SetConnectionState(IAmplifierStatus::ConnectionStateOffline);
				break;

			case WAIT_IO_COMPLETION:

				// [hkc:04.22.2012]:
				//
				// Packet was received within timeout period.  Note: only valid
				// signal packets transitions the application to the connecting
				// or connected state.

				if (theAmp.m_bLastPacketValid) {
					if (theApp.m_dMonitor.m_bEnetInterrupts) {
						if (theAmp.IsConnectionStateConnecting()) {
							const DWORD dwConnectTimeDelta = ::GetTickCount() - dwConnectTime;

							if (dwConnectTimeDelta > dwFlushTime) {
								theAmp.SetConnectionState(IAmplifierStatus::ConnectionStateConnected);
							}
						}
					}
					else {
						theAmp.OnAmplifierConnection();

						if (theAmp.IsConnectionStateConnected() == false) {
							dwConnectTime = ::GetTickCount();
							dwFlushTime =
								(theAmp.m_lLastAcknowledgedCommandPacket == 0) ?
									CCommunication::InitialFlushTimeMilliseconds :
									CCommunication::ConnectFlushTimeMilliseconds;

							theAmp.SetConnectionState(IAmplifierStatus::ConnectionStateConnecting);
						}
					}
				}
				break;

			case WAIT_OBJECT_0:
			default:
				// [hkc:04.22.2012]: *code should never be reached (event set)*
				break;
			}
		}

		if (theAmp.m_bAmplifierErrorClearPending)
			theAmp.m_bAmplifierErrorClearPending = false;
	}

   // Cancel All The Packet Reads
   // ---------------------------
   // Actually it is not necessary to explicitly cancel outstanding W32N_PacketRead operations. Any left pending will be closed
   // automatically by the I/O cancel logic of the NDIS protocol driver.
   // The cancel loop is put here simply to test and demonstrate  W32N_CancelPacketRead function.
   
   for( dwEachPackage = 0; dwEachPackage < theAmp.m_Adapter.m_nPackageCount; ++dwEachPackage)	
	{
      PSReceivePackage  pRxPackage = &theAmp.m_Adapter.m_pRxPackageBase[ dwEachPackage ];

      // Cancel The Packet Read
      W32N_CancelPacketRead( theAmp.m_Adapter.m_hDevice, &pRxPackage->m_UserPacketData );
   }

   // Free Resources
   CloseHandle( hReceiveEvent );	hReceiveEvent=NULL;

	theAmp.m_bReceiveThreadAlive	=	false;

#endif

   return 0;   // No Complaint
}


////////////////////++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++////////////
///////////////		Send
//-----=++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


/////////////////////////////////////////////////////////////////////////////
// The following definitions and variables control sending of the test packet.
// The number of test packets defined by SEND_BURST_COUNT will be sent
// in a back-to-back "burst" at the interval defined by SEND_TEST_INTERVAL.
// The default definition will send 20 packets in a "burst" every 5-seconds.


#define  SEND_BURST_COUNT     1	//20  // Packets To Send In "Burst"
#define  SEND_TEST_INTERVAL   1  // Seconds Interval


bool CCommunication::SendMessage(void)
{
   // Create The Send Thread

	m_hSendThread = CreateThread( (LPSECURITY_ATTRIBUTES )NULL,			// No Security
											(DWORD )0,									// Same Stack Size
											(LPTHREAD_START_ROUTINE )SendProc,	// Thread Procedure
											(PVOID )this,								// Parameter Pointer
											(DWORD )CREATE_SUSPENDED ,				// Start Immediately
											&m_dwSendThreadId							// Thread ID
											);

	AfxTrace(_T("CCommunication::Send Thread ID : %x\n"), m_dwSendThreadId);

	if( !m_hSendThread )	
	{
		AfxTrace( _T("Could Not Start Send Thread\n") );

		return false;
	}
  
	return true;
}

/////////////////////////////////////////////////////////////////////////////
// Purpose	:	HookPeek send thread Thread Start routine.
// Parameters	:	pAdapter -  Pointer to the SHookAdapter structure which the thread will send on.

DWORD WINAPI CCommunication::SendProc( LPVOID )
{
#ifndef PHILIPS_VIEWER
   // Create The Thread Event
   // -----------------------
   // hSendEvent is simply used as a timer for periodically sending test packets.
    CCommunication& theAmp = Instance();
  
   HANDLE hSendEvent = CreateEvent(	NULL,    
												FALSE,   // Auto-Reset
												FALSE,   // Initial State Signaled
												NULL );


   // Loop Until Shutdown

   while( !theAmp.m_bShutdown )	
	{
      DWORD nResult = WaitForSingleObjectEx( hSendEvent, 200, TRUE );	// This was 200

      if( nResult == WAIT_TIMEOUT )	
		{
			if( theAmp.m_bShutdown )
			{
				break;
			}

         // Send Packet(s) Occasionally        

         if ( theAmp.m_bSendPackets )
			{
				theAmp.SendTestPacket(sizeof(SWMCommandPacket) - MHdrSize,  true );    // 64 Total	
			}
      }
   }

   // Free Resources
   CloseHandle( hSendEvent );	hSendEvent=NULL;

	theAmp.m_bSendThreadAlive = false;
#endif
   return 0;    // No Complaint
}

/////////////////////////////////////////////////////////////////////////////
//// HandleSendComplete
// Purpose			:	Handle a send complete operation.
// Parameters		:
//    lpOverlapped -
// Return Value	:	NONE.
// Remarks			:	This routine is called by either the Windows 95 or the Windows NT SendCompleteApc. It performs the send complete handling that is
// platform independent. It is important to know that reaching this point has little meaning EXCEPT that the memory used for sending may be freed
// or recycled.
// The packet:
//    1.) May have been sent
//    2.) May be sent later
//    3.) May never be sent
//
// In addition, it is not possible to determine whether the packet has actually been sent by any other means. For example, waiting
// to receive a loopback of the sent packet also has little meaning. In particular, reception of the loopback packet amy be done by
// the NDIS wrapper and the loopback packet may actually "received" AFTER responses are seen by remote network clients.
DWORD CCommunication::HandleSendComplete(PSSendPackage pTxPackage)
{
   // Sanity Checks
   if( IsValidSendPackage( pTxPackage ) )
	{
      ++m_dwSendDestroyCount;

      ++(pTxPackage->m_pAdapter)->m_nSendPacketCount;

      --(pTxPackage->m_pAdapter)->m_nPendingSendAPCCount;

      DestroySendPackage( pTxPackage );
   }

   return 0;
}

/////////////////////////////////////////////////////////////////////////////
//// SendCompleteApcNT
// Purpose
// The Windows NT asynchronous procedure callback (APC) which is called by the PCANDIS driver when each W32N_PacketSendEx() completes.
// Parameters:	dwErrorCode - dwNumberOfBytesTransfered -  lpOverlapped -
// Remarks	: Performs some sanity checks and then calls a common routine to finish  processing.

VOID WINAPI CCommunication::SendCompleteApcNT(DWORD dwErrorCode, DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped)
{
#ifndef PHILIPS_VIEWER
   // ATTENTION!!! Consider using try/except here...
   PSSendPackage pTxPackage = (PSSendPackage )lpOverlapped->OffsetHigh;

   Instance().HandleSendComplete( pTxPackage );
#endif
}

/////////////////////////////////////////////////////////////////////////////
//// SendCompleteApc95
// Purpose	:	The Windows 95 asynchronous procedure callback (APC) which is called by the PCANDIS driver when each W32N_PacketSendEx() completes.
// Parameters:  lpOverlapped -
// Return Value	: NONE
// Remarks	: Performs some sanity checks and then calls a common routine to finish processing.
DWORD WINAPI CCommunication::SendCompleteApc95(LPOVERLAPPED lpOverlapped)
{
#ifndef PHILIPS_VIEWER
   PSSendPackage pTxPackage = (PSSendPackage )lpOverlapped->OffsetHigh;

   Instance().HandleSendComplete( pTxPackage );
#endif
   return 0;
}


/////////////////////////////////////////////////////////////////////////////
//// SendTestPacket
// Purpose	:	Send a test packet using the PCANDIS driver services.

void CCommunication::SendTestPacket(DWORD nDataSize, bool bSendToAmp )
{
    // Sanity Checks
   if( m_Adapter.m_hDevice == INVALID_HANDLE_VALUE )
	{
      AfxTrace( _T("SendTestPacket: Adapter Not Open\n") );

      return;
   }

   // Create Send Packet
   // ------------------
   // The CreateSendPackage() function gleans the medium from pAdapter and builds a SSendPackage appropriate for the medium. 
   //
   // Creating An Event For Overlapped I/O
   // ------------------------------------
   // The last parameter passed to CreateSendPackage controls whether an event is created for overlapped (asynchronous) I/O operation.
   //
   // An event is REQUIRED for Windows 9X asynchronous I/O. However, an event is NOT REQUIRED for Windows NT asynchronous I/O using APC's
   // (although it may be necessary for other types of NT async I/O...).
   //
   // Hence, the last parameter passed to CreateSendPackage is determined by whether or not the application is running on the Windows 9X platform.
 
   PSSendPackage pTxPackage = CreateSendPackage(	nDataSize, W32N_IsWindows95(), bSendToAmp  );  // Per-Packet Event If Windows 95
															 
   if( pTxPackage )
	{
      ++m_dwSendCreateCount;

      // Send The Data Buffer

      //AfxTrace( "\nSending 802.3 Test Packet... %s \n", pTxPackage->m_szPacketBufferSpace);

      ++m_Adapter.m_nPendingSendAPCCount;

      // Call The Driver To Send The Packet

		BOOL bSendSuccess = FALSE;

#if 0
      if( W32N_IsWindows95() )
		{
         bSendSuccess = W32N_PacketSendEx(	m_Adapter.m_hDevice,
														(PUCHAR) pTxPackage->m_szPacketBufferSpace,
														pTxPackage->m_dwFrameSize,    // Input Data (i.e., To Driver)
														&pTxPackage->m_dwBytesReturned,
														&pTxPackage->m_OverLapped,   // REQUIRED For FILE_FLAG_OVERLAPPED
														(PVOID) SendCompleteApc95
													);
      }
		else 
		{
#endif
         if( W32N_IsWindowsNT() )
			{
				bSendSuccess = W32N_PacketSendEx(	m_Adapter.m_hDevice,
														(PUCHAR) pTxPackage->m_szPacketBufferSpace,
														pTxPackage->m_dwFrameSize,    // Input Data (i.e., To Driver)
														&pTxPackage->m_dwBytesReturned,
														&pTxPackage->m_OverLapped,   // REQUIRED For FILE_FLAG_OVERLAPPED
														(PVOID )SendCompleteApcNT
													);
      }
		else
		{
         // ATTENTION!!! Deal with this case!!!
      }

      if( !bSendSuccess)
		{
			DWORD nSendResult = W32N_GetLastError();

         if( nSendResult == ERROR_SUCCESS )
			{
            // Immediate Completion
            // --------------------
            // But SendCompleteApc() should still be called. Don't free any resources here!

            ++m_dwSendImmediateCount;

            return;
         }

         if( nSendResult != ERROR_IO_PENDING )
			{
            // Send Failed
            // -----------
            // SendCompleteApc() won't be called. Free resources here.

            AfxTrace( _T("Send Failed; Error: 0x%8.8X\n"), nSendResult );

            --m_Adapter.m_nPendingSendAPCCount;

            ++m_dwSendDestroyCount;

            DestroySendPackage( pTxPackage );

            return;
         }
      }
   }
}



////////////////////////////////////////////////////////////////////////////////////////////////////////
//+++++++++++++++++++++++++++++++		HPCtrl
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// This module includes several adapter control and display routines which  are used by all of the different variations of the HookPeek samples.
// Purpose	:	Command the NDISHOOK driver to reject loopback packets.
// Return Value :	Returns TRUE if loopback was successfully disabled.
// Remarks	:Loopback packets are rejected by NDISHOOK by comparing the link source address against the adapter current. If the address is equal, the packet
// is rejected.

BOOLEAN CCommunication::DisableLoopback( void )
{
   BOOLEAN  bResult = FALSE;

	switch( m_Adapter.m_nMedium )
	{
		case NdisMedium802_3:
		case NdisMediumDix:

			bResult = W32N_DisableLoopback(	m_Adapter.m_hDevice,
														MSrcAddr + 0,        // Offset Of Source Address Into Packet
														ETHER_ADDR_LENGTH,   // Length Of Address
														m_Adapter.m_CurrentAddress    // Address Byte Bytes
													);
		break;

		case NdisMedium802_5:

			bResult = W32N_DisableLoopback(	m_Adapter.m_hDevice,
														MSrcAddr + 2 + 0,    // Offset Of Source Address Into Packet
														ETHER_ADDR_LENGTH,   // Length Of Address
														m_Adapter.m_CurrentAddress // Address Byte Bytes
													);
		  break;

		case NdisMediumLocalTalk:   // ATTENTION!!! Add This Case!!!
		case NdisMediumFddi:
		case NdisMediumWirelessWan:
		case NdisMediumArcnetRaw:
		case NdisMediumArcnet878_2:
		case NdisMediumAtm:
		case NdisMediumIrda:
		default:
			bResult = FALSE;
			break;
   }

   return	bResult;
}

// Purpose	:	Set the adapter driver's NDIS packet filter.
// Remarks
// Performs most of the mechanics of making the OID_GEN_CURRENT_PACKET_FILTER NDIS request.
bool CCommunication::SetPacketFilter(ULONG nPacketFilter )
{
   W32N_REQUEST W32N_Request={0};
       
   W32N_Request.NdisRequest.RequestType = NdisRequestSetInformation;

   W32N_Request.NdisRequest.DATA.SET_INFORMATION.Oid = OID_GEN_CURRENT_PACKET_FILTER;
   W32N_Request.NdisRequest.DATA.SET_INFORMATION.InformationBuffer = &nPacketFilter;
   W32N_Request.NdisRequest.DATA.SET_INFORMATION.InformationBufferLength = sizeof( ULONG );
   W32N_Request.NdisRequest.DATA.SET_INFORMATION.BytesRead = 0;
   W32N_Request.NdisRequest.DATA.SET_INFORMATION.BytesNeeded = 0;

   NDIS_STATUS nNdisStatus = W32N_MakeNdisRequest( m_Adapter.m_hDevice, &W32N_Request, &m_Adapter.m_OverLapped, TRUE );     // Synchronous

   if( nNdisStatus )	{	return false;	}

   return true;
}

// Purpose	:	Start reception by placing the adapter into promiscuous mode.
// Remarks
// As written, this function places the MAC adapter driver into the
// PROMISCUOUS mode of operation.
//
//         NDIS_PACKET_TYPE_PROMISCUOUS
//
// This may not be desirable in all cases.
//
// For example, if you are developing a special purpose protocol, then it is likely that you should set the MAC adapter driver to deliver
// only DIRECTED packets; that is, packets which are addressed specifically to your adapter. If you do this, then the system does not have to do
// the extra work of passing unneeded packets to your application.
//
//         NDIS_PACKET_TYPE_DIRECTED
//
// In addition to directed packets, some protocols need to receive multicast packets. In that case, the filter should be set to include MULTICAST
// packets in addition to DIRECTED packets.
//
//         NDIS_PACKET_TYPE_DIRECTED | NDIS_PACKET_TYPE_MULTICAST
//
// If reception of multicast packets is needed by a protocol, then setting the MAC packet filter to NDIS_PACKET_TYPE_MULTICAST is not sufficient.
// In addition, you must specifically tell the MAC driver WHICH multicast addresses you wish to receive. To do this you must use the NdisRequestSetInformation
// to set the multicast list that you wish to receive. See the DDK for more information on how to do this.
//
// If you are implementing a protocol you may wish to disable the loopback mechanism. You may also wish to use the BPF mechanism to direct the
// NDISHOOK driver to perform some additional filtering for you at the driver.
bool CCommunication::StartPromiscuousReception( void)
{
	m_Adapter.m_nReceivedPacketCount = 0;

   m_Adapter.m_nLastSequenceNo = 0;
   m_Adapter.m_nSequenceErrorCount = 0;
   m_Adapter.m_nSequenceErrorPlus = 0;
   m_Adapter.m_nSequenceErrorMinus = 0;

   m_Adapter.m_nSendPacketCount = 0;
   m_Adapter.m_nPendingSendAPCCount = 0;

   m_Adapter.m_nProtocolFramesRcvGood = 0;
   m_Adapter.m_nRcvMissed_KernelResource = 0;
   m_Adapter.m_nRcvMissed_UserResource = 0;

   m_Adapter.m_nProtocolFramesXmitGood = 0;
   m_Adapter.m_nXmitMissed_KernelResource = 0;

	bool bResult = false;
   switch( m_Adapter.m_nMedium )	{

   case NdisMedium802_3:   // Ethernet
   case NdisMediumDix:      // Also Ethernet
		bResult = SetPacketFilter(NDIS_PACKET_TYPE_DIRECTED | NDIS_PACKET_TYPE_PROMISCUOUS);
      break;

   case NdisMedium802_5:   // TokenRing

		bResult = SetPacketFilter( NDIS_PACKET_TYPE_DIRECTED | NDIS_PACKET_TYPE_PROMISCUOUS);

      // Some TokenRing Adapters Don't Support Promiscuous Operation
      if( !bResult )	{

			bResult = SetPacketFilter(NDIS_PACKET_TYPE_ALL_LOCAL);

         if( !bResult )	{

               bResult = SetPacketFilter( NDIS_PACKET_TYPE_DIRECTED);
            }
      }
    break;

   case NdisMediumLocalTalk:
		bResult = SetPacketFilter( NDIS_PACKET_TYPE_DIRECTED | NDIS_PACKET_TYPE_BROADCAST);
      break;

	case NdisMediumFddi:
   case NdisMediumWirelessWan:
   case NdisMediumArcnetRaw:
   case NdisMediumArcnet878_2:
   case NdisMediumAtm:
   case NdisMediumIrda:
   default:
		bResult = false;
      break;
   }

   return bResult;
}

// Stop reception by setting the adapter's NDIS packet filter to 0.
bool CCommunication::StopReception( void)
{
   return SetPacketFilter(0);
}

/////////////////////////////////////////////////////////////////////////////
// Purpose			:	Query the adapter for it's vendor description string.
// Return Value	: Returns TRUE is the vendor description string is determined; description string saved in the p_Adapter structure 
//	in the m_szAdapterDriverDescription member variable.
bool CCommunication::UpdateAdapterDescription(void)
{
   W32N_REQUEST W32N_Request={0};

   _tcscpy( m_Adapter.m_szAdapterDriverDescription, _T("Unknown") );

   W32N_Request.NdisRequest.RequestType = NdisRequestQueryInformation;

   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_GEN_VENDOR_DESCRIPTION;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBuffer = m_Adapter.m_szAdapterDriverDescription;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBufferLength = sizeof( m_Adapter.m_szAdapterDriverDescription );
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesWritten = 0;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesNeeded = 0;

   NDIS_STATUS nNdisStatus = W32N_MakeNdisRequest(	m_Adapter.m_hDevice, &W32N_Request, &m_Adapter.m_OverLapped, TRUE);	// Synchronous

	if(nNdisStatus)	{	return false;	}

   return true;
}

/////////////////////////////////////////////////////////////////////////////
// Purpose			:	Query the adapter for it's NDIS medium.
// Return Value	:	Returns TRUE is the medium is determined; medium saved in the p_Adapter structure in the m_nMedium member variable.
bool CCommunication::UpdateAdapterMedium( void )
{
   W32N_REQUEST W32N_Request={0};
   
   // Get Media In Use
   
   m_Adapter.m_nMedium = -1;         // Invalidate

   W32N_Request.NdisRequest.RequestType = NdisRequestQueryInformation;

   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_GEN_MEDIA_IN_USE;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBuffer = &m_Adapter.m_nMedium;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBufferLength = sizeof( m_Adapter.m_nMedium );
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesWritten = 0;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesNeeded = 0;

   NDIS_STATUS nNdisStatus = W32N_MakeNdisRequest(	m_Adapter.m_hDevice, &W32N_Request, &m_Adapter.m_OverLapped, TRUE );	// Synchronous

   if( nNdisStatus )	{	return false;	}

   return true;
}

/////////////////////////////////////////////////////////////////////////////
// Purpose			:	Query the adapter for it's current link address.
// Return Value	:	Returns TRUE is the current link address is determined; address saved m_Adapter structure in the m_CurrentAddress member variable.
// Remarks			:	This is a medium-specific call. It needs refinement to work with non-Ethernet mediums...
bool CCommunication::UpdateAdapterCurrentAddress(void)
{
   W32N_REQUEST W32N_Request={0};
   
   // Get Link Address, If Necessary
   if( !m_Adapter.m_bCurrentAddressValid )	{

      W32N_Request.NdisRequest.RequestType = NdisRequestQueryInformation;

      W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBuffer = m_Adapter.m_CurrentAddress;
      W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBufferLength = 32;
      W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesWritten = 0;
      W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesNeeded = 0;

      switch( m_Adapter.m_nMedium )	{

      case NdisMedium802_3:
      case NdisMediumDix:
			W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_802_3_CURRENT_ADDRESS;
         break;

      case NdisMedium802_5:
         W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_802_5_CURRENT_ADDRESS;
         break;

      case NdisMediumFddi:
         W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_FDDI_LONG_CURRENT_ADDR;
         break;

      case NdisMediumWan:
         W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_WAN_CURRENT_ADDRESS;
         break;

      case NdisMediumWirelessWan:
         W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_WW_GEN_CURRENT_ADDRESS;
         break;

      case NdisMediumLocalTalk:
         W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_LTALK_CURRENT_NODE_ID;
         break;

      case NdisMediumArcnetRaw:
      case NdisMediumArcnet878_2:
         W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_ARCNET_CURRENT_ADDRESS;
         break;

      case NdisMediumAtm:
         W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_ATM_HW_CURRENT_ADDRESS;
         break;

      case NdisMediumIrda:
      default:
			break;
      }

      NDIS_STATUS nNdisStatus = W32N_MakeNdisRequest(	m_Adapter.m_hDevice,	&W32N_Request,	&m_Adapter.m_OverLapped, TRUE);               // Synchronous
														
      if( nNdisStatus )	{	return false;	}

      m_Adapter.m_bCurrentAddressValid = true;
   }

   return ( m_Adapter.m_bCurrentAddressValid ) ? true	:	false;
}

bool CCommunication::GetProtocolStatistics( void)
{
  
   // m_nRcvMissed_KernelResource - Receive Error Due Lack Of Kernel Resource
   // -----------------------------------------------------------------------
   // Value maintained by the NDISHOOK protocol driver. Count of packets that the driver received but was not able to pass up to the Win32
   // application because some kernel resource (typically a NDIS_PACKET or NDIS_BUFFER) was not available.
 
	W32N_REQUEST W32N_Request={0}; 

   W32N_Request.NdisRequest.RequestType = NdisRequestQueryInformation;

   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_PCANDIS_RCV_ERROR_KERNEL_RESOURCE;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBuffer = &m_Adapter.m_nRcvMissed_KernelResource;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBufferLength = sizeof( m_Adapter.m_nRcvMissed_KernelResource );
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesWritten = 0;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesNeeded = 0;

   NDIS_STATUS nNdisStatus = W32N_MakePrivateRequest( m_Adapter.m_hDevice, &W32N_Request, &m_Adapter.m_OverLapped, TRUE );           // Synchronous
   
	if( nNdisStatus )
	{
      m_Adapter.m_nRcvMissed_KernelResource = MAXDWORD;
   }
   
   // m_nRcvMissed_UserResource - Receive Error Due Lack Of User Resource
   // -------------------------------------------------------------------
   // Value maintained by the NDISHOOK protocol driver. Count of packets that the driver received but was not able to pass up to the Win32
   // application because no W32N_PACKET was available to be filled.
   
   W32N_Request.NdisRequest.RequestType = NdisRequestQueryInformation;

   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_PCANDIS_RCV_ERROR_USER_RESOURCE;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBuffer = &m_Adapter.m_nRcvMissed_UserResource;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBufferLength = sizeof( m_Adapter.m_nRcvMissed_UserResource );
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesWritten = 0;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesNeeded = 0;

   nNdisStatus = W32N_MakePrivateRequest( m_Adapter.m_hDevice, &W32N_Request, &m_Adapter.m_OverLapped, TRUE );	           // Synchronous

   if( nNdisStatus )	{

      m_Adapter.m_nRcvMissed_UserResource = MAXDWORD;
   }

   // m_nProtocolFramesRcvGood - Receive OK Count
   // -------------------------------------------
   // Value maintained by the NDISHOOK protocol driver. Count of packets
   // that the driver believes that it received and passed up to the Win32
   // application.

   W32N_Request.NdisRequest.RequestType = NdisRequestQueryInformation;

   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_GEN_RCV_OK;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBuffer = &m_Adapter.m_nProtocolFramesRcvGood;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBufferLength = sizeof( m_Adapter.m_nProtocolFramesRcvGood );
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesWritten = 0;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesNeeded = 0;

   nNdisStatus = W32N_MakePrivateRequest( m_Adapter.m_hDevice, &W32N_Request, &m_Adapter.m_OverLapped, TRUE );	// Synchronous

   if( nNdisStatus )	{

      m_Adapter.m_nProtocolFramesRcvGood = MAXDWORD;
   }

   // m_nXmitMissed_KernelResource - Send Error Due Lack Of Kernel Resource
   // ---------------------------------------------------------------------
   // Value maintained by the NDISHOOK protocol driver. Count of packets
   // that the driver was commanded to send but was not able to pass to
   // the lower-level MAC driver because some kernel resource (typically a
   // NDIS_PACKET or NDIS_BUFFER) was not available.
   
   W32N_Request.NdisRequest.RequestType = NdisRequestQueryInformation;

   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_PCANDIS_XMIT_ERROR_KERNEL_RESOURCE;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBuffer = &m_Adapter.m_nXmitMissed_KernelResource;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBufferLength = sizeof( m_Adapter.m_nXmitMissed_KernelResource );
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesWritten = 0;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesNeeded = 0;

   nNdisStatus = W32N_MakePrivateRequest( m_Adapter.m_hDevice, &W32N_Request, &m_Adapter.m_OverLapped, TRUE );	// Synchronous

   if( nNdisStatus )   {

      m_Adapter.m_nXmitMissed_KernelResource = MAXDWORD;
   }

   // m_nProtocolFramesXmitGood - Send OK Count
   // -----------------------------------------
   // Value maintained by the NDISHOOK protocol driver. Count of packets
   // that the driver believes that it successfully sent.

   W32N_Request.NdisRequest.RequestType = NdisRequestQueryInformation;

   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_GEN_XMIT_OK;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBuffer = &m_Adapter.m_nProtocolFramesXmitGood;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBufferLength = sizeof( m_Adapter.m_nProtocolFramesXmitGood );
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesWritten = 0;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesNeeded = 0;

   nNdisStatus = W32N_MakePrivateRequest( m_Adapter.m_hDevice, &W32N_Request, &m_Adapter.m_OverLapped, TRUE );	// Synchronous

   if( nNdisStatus )	{

      m_Adapter.m_nProtocolFramesXmitGood = MAXDWORD;
   }

   // m_szProtocolDriverDescription - Protocol Driver Vendor Description
   // ------------------------------------------------------------------

   _stprintf( m_Adapter.m_szProtocolDriverDescription, _T("Unknown") );

   W32N_Request.NdisRequest.RequestType = NdisRequestQueryInformation;

   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.Oid = OID_GEN_VENDOR_DESCRIPTION;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBuffer = m_Adapter.m_szProtocolDriverDescription;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.InformationBufferLength = sizeof( m_Adapter.m_szProtocolDriverDescription );
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesWritten = 0;
   W32N_Request.NdisRequest.DATA.QUERY_INFORMATION.BytesNeeded = 0;

   nNdisStatus = W32N_MakePrivateRequest( m_Adapter.m_hDevice, &W32N_Request, &m_Adapter.m_OverLapped, TRUE );	// Synchronous

   if( nNdisStatus )	
	{
      _stprintf( m_Adapter.m_szProtocolDriverDescription, _T("Unknown") );
   }

   return true;
}

/////////////////////////////////////////////////////////////////////////////
// Purpose		:	Call the NDISHOOK driver to get kernel-mode statistics.
// Parameters	:	pAdapter - Pointer to the SHookAdapter structure of interest.
void CCommunication::DisplayProtocolStatistics(void)
{
   // Fetch The Protocol Statistics Information

   GetProtocolStatistics();

   // Display The Protocol Statistics Information

   AfxTrace( _T("Protocol Statistics:\n") );

   AfxTrace( _T("  Driver Description          : %s\n"), m_Adapter.m_szProtocolDriverDescription );

   AfxTrace( _T("  Received Packet Count       : %d\n"), m_Adapter.m_nProtocolFramesRcvGood );

   AfxTrace( _T("    Rx Missed, Kernel Resource: %d\n"), m_Adapter.m_nRcvMissed_KernelResource );

   AfxTrace( _T("    Rx Missed, User Resource  : %d\n"), m_Adapter.m_nRcvMissed_UserResource );

   AfxTrace( _T("  Sent Packet Count           : %d\n"), m_Adapter.m_nProtocolFramesXmitGood );

   AfxTrace( _T("    Tx Missed, Kernel Resource: %d\n"), m_Adapter.m_nXmitMissed_KernelResource );
}

// Purpose	:		Display adapter information returned from IOCTL_NDISHOOK_QUERY_LOWER_INFO call to the NDISHOOK protocol driver.
bool CCommunication::DisplayAdapterInfo( void )
{
	PTCHAR szNameTable[] =
   {
      _T("802.3"),
      _T("802.5"),
      _T("Fddi"),
      _T("Wan"),
      _T("LocalTalk"),
      _T("Dix"),
      _T("Arcnet (Raw)"),
      _T("Arcnet (878.2)"),
      _T("ATM"),
      _T("Wireless WAN"),
      _T("Irda")
   };

   // Sanity Checks

   if( m_Adapter.m_hDevice == INVALID_HANDLE_VALUE )	{	return FALSE;	}

   AfxTrace( _T("Adapter Information:\n\n") );

   // Display The Adapter Description

   bool bResult = UpdateAdapterDescription();

   AfxTrace( _T("Description    : %s\n"), m_Adapter.m_szAdapterDriverDescription );

   // Display The Adapter Medium
   bResult = UpdateAdapterMedium( );

   if( !bResult )	{	return false;	}

   if( NdisMedium802_3 <= m_Adapter.m_nMedium && m_Adapter.m_nMedium < NdisMediumArcnet878_2 )
	{
      AfxTrace( _T("Adapter Medium : %s\n"), szNameTable[ m_Adapter.m_nMedium ] );
   }

   // Display The Adapter Current Link Address

   bResult = UpdateAdapterCurrentAddress();

   if( !bResult )	{	return false;	}

   if( m_Adapter.m_bCurrentAddressValid )
	{
      switch( m_Adapter.m_nMedium )
		{
      case NdisMediumLocalTalk:
			AfxTrace( _T("Adapter Address: %2.2X\n"), (TCHAR *) m_Adapter.m_CurrentAddress[ 5 ] );
         break;

      case NdisMedium802_5:
      case NdisMedium802_3:
      default:
			AfxTrace( _T("Adapter Address: %2.2X.%2.2X.%2.2X.%2.2X.%2.2X.%2.2X\n"),
               (TCHAR * )m_Adapter.m_CurrentAddress[ 0 ],
               (TCHAR * )m_Adapter.m_CurrentAddress[ 1 ],
               (TCHAR * )m_Adapter.m_CurrentAddress[ 2 ],
               (TCHAR * )m_Adapter.m_CurrentAddress[ 3 ],
               (TCHAR * )m_Adapter.m_CurrentAddress[ 4 ],
               (TCHAR * )m_Adapter.m_CurrentAddress[ 5 ]
               );
         break;
      }
   }
	else
	{
      AfxTrace( _T("Unknown\n") );
   }

   return bResult;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////		From HPRXUTIL
//////////////////////////////////////////////////////////////////////////////

// DestroyReceivePackages
// Purpose	:	Close event handles and free memory associated with packet packages created previously by CreateReceivePackages().
void CCommunication::DestroyReceivePackages( void)
{
   // Sanity Checks
   if( !&m_Adapter.m_pRxPackageBase )  {	return;	}

   if( m_Adapter.m_hDummyReceiveEvent )   
	{   
      // Close The Special Receive Event
      
      CloseHandle( m_Adapter.m_hDummyReceiveEvent );

      m_Adapter.m_hDummyReceiveEvent = NULL;
   }	
	else	
	{
      // Close Event Handles For Each Package

      for(register DWORD i=0; i<m_Adapter.m_nPackageCount; ++i )
		{
         PSReceivePackage pRxPackage = &m_Adapter.m_pRxPackageBase[ i ];

         if( pRxPackage->m_OverLapped.hEvent )	
			{
            CloseHandle( pRxPackage->m_OverLapped.hEvent );
         }

         pRxPackage->m_OverLapped.hEvent = NULL;
      }
   }

   // Free Memory Allocated For The Packages
   WMFree( m_Adapter.m_pRxPackageBase );

   m_Adapter.m_pRxPackageBase= NULL;
   m_Adapter.m_nPackageCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
// Purpose			:	Verify that the SReceivePackage is valid.
// Parameters		:	PSReceivePackage pRxPackage - Pointer to the SReceivePackage to be   verified.
// Return Value	:	Returns TRUE if the package is valid. Returns FALSE otherwise.
// Remarks			:	Structured Exception Handling (SEH) is also used for debug builds. SEH is not used in release builds because IsValidReceivePackage()
// can be called fairly often of the same package and the use of SEH could introduce a performance penalty.
bool CCommunication::IsValidReceivePackage( PSReceivePackage pRxPackage )
{
   bool  bResult = TRUE;

   // Sanity Checks
   if( !pRxPackage )	{	return( FALSE );	}

   // Test Signature
   // --------------
   // Use Structured Exception Handling (SEH) for _DEBUG builds.
   //
#ifdef _DEBUG
   __try
#endif
   {
      // Check Receive Package Signature
      if( pRxPackage->m_dwSignature != RX_PACKAGE_SIGN )
      {
         bResult = FALSE;
      }
   }
#ifdef _DEBUG
   __except(EXCEPTION_EXECUTE_HANDLER)
   {
      AfxTrace( _T("IsValidReceivePackage: EXCEPTION!!!\n") );
      bResult = FALSE;
   }
#endif

   return( bResult );
}

/////////////////////////////////////////////////////////////////////////////
// Purpose		:	Routine to display a received packet on the console.
// Parameters	:	Pointer to W32N_PACKET data structure to be displayed.
// Remarks		:	This routine displays medium-independent packet information and then dispatches to a medium-specific display routine.
void	CCommunication::DisplayReceivedPacket( PSHookAdapter pAdapter, PW32N_PACKET pW32NPacket)
{
   // Sanity Checks
   if( !pW32NPacket )	{	return;	}

   if( pAdapter->m_hDevice == INVALID_HANDLE_VALUE )	{	return;	}

   // Fix Timestamp
   // -------------
   // Unfortunately, Windows 95 VxD's cannot perform floating point operations at ring-0. This means that NDISHOOK VxD cannot scale
   // from the one millisecond units that it gets from Get_System_Time to the 100-nanosecond units that is defined for the TimeReceived
   // field. This fix is done here.

   if( W32N_IsWindows95() )	{	pW32NPacket->TimeReceived.QuadPart *= (LONGLONG )10000;	}

   bool bSequenceError = false;

	bool bPlus = false;

   // Packet Sequence# checking on the Ethernet Driver Layer
   // ----------------------------
   // A sequence number error can be generated by two basic causes:
   //
   // 1.) The NDISHOOK driver received a packet which it could not pass to the application because no read was posted.
   //
   //     Large packet loss (sequence errors) can be expected for this cause when dumping packets to the console.
   //
   // 2.) When using the W32N_PacketReadEx() facility the NDISHOOK driver ReceiveHandler can be entered recursively. When this
   //     occurs, the APC's appear to be queued by the system in LIFO fashion. When the APC's are run in the calling thread packets
   //     can be received out of order.
   //
   //     These errors are seen only occasionally at PCAUSA, and then only 1.) on the Windows NT platform 2.) running an APC or IOCP
   //     version of a WinDis 32 application 3.) on a dual-processor workstation.
   //
   //     In addition, it appears that the reentrant receive packets are loopback packets.
   //
   //     No packets are lost in this situation - just an occasional reversal of order seen at the Win32 application. The order that
   //     the packets are completed by the NDISHOOK driver appears to be correct.

   if( pAdapter->m_nLastSequenceNo )
	{
		// Increment The Last Sequence Number
      
      ++pAdapter->m_nLastSequenceNo;

      // Check Whether The Packet Has The Expected Sequence Number
      
      if( pAdapter->m_nLastSequenceNo != pW32NPacket->nPacketNumber.u.LowPart )
		{
         // Count a Device Driver Sequence Error Event

         bSequenceError = true;

         ++pAdapter->m_nSequenceErrorCount;
         m_iDriverDroppedPacketCount += CalcDroppedPackets(pAdapter->m_nLastSequenceNo, pW32NPacket->nPacketNumber.u.LowPart);

         //
         // Determine Whether Error Is Plus Or Minus
         //
         if( pAdapter->m_nLastSequenceNo < pW32NPacket->nPacketNumber.u.LowPart )
			{
            bPlus = true;

            pAdapter->m_nSequenceErrorPlus += pW32NPacket->nPacketNumber.u.LowPart - pAdapter->m_nLastSequenceNo;
         }

         if( pAdapter->m_nLastSequenceNo > pW32NPacket->nPacketNumber.u.LowPart )
			{
            bPlus = false;

            pAdapter->m_nSequenceErrorMinus += pAdapter->m_nLastSequenceNo - pW32NPacket->nPacketNumber.u.LowPart;
         }
      }
   }

    // Adopt The Current Packet Number For Future Checking
    pAdapter->m_nLastSequenceNo = pW32NPacket->nPacketNumber.u.LowPart;

   // Display Packet Header
   //AfxTrace( "Packet No.: %10.10d\t", pW32NPacket->nPacketNumber.QuadPart );
   // Prepare Packet Timestamp For Display In Millisecond Units
   //AfxTrace( "Time: %10.10Lu msec\t", pW32NPacket->TimeReceived.QuadPart / (LONGLONG )10000 );
   //AfxTrace( "Length: %d/%d ", pW32NPacket->nPacketDataLength, pW32NPacket->nBufferDataLength );
   // Display Packet Sequence Error Indicator
   // ---------------------------------------
   // If it is not the expected sequence number, append "* LOST PACKET//"  to the end of the line.
   //if(bSequenceError)	{	AfxTrace( " * LOST PACKET *" );	}
   //AfxTrace("\n");

	///Test Anything here

	// [hkc:06.14.2012]: cannot possibly be a signal packet from amplifier.
	// [rlg:12.12.2012]: Moved this check up the call stack to keep all 
    //                   sequence checking and basic packet validation in one place.
	if (  pW32NPacket->nBufferDataLength != sizeof(SWMSignalPacket) || 
        !(pW32NPacket->PacketBuffer)) 
    {
		this->m_bLastPacketValid = false;
	}
    else
    {
        SWMSignalPacket* pSignalPacket = reinterpret_cast<SWMSignalPacket*>(pW32NPacket->PacketBuffer);

        // ------------------------------------------------------
        // Packet Sequence# checking on data from the Amplifier
        // ------------------------------------------------------
        if (m_bAmpSequenceCheckingStarted)
        {
            m_iDroppedPacketCount += CalcDroppedPackets(m_lLastAmpPacketSequence, 
                                                        static_cast<unsigned long>(pSignalPacket->packetHeader.sequenceNumber));
        }
        else
        {
            m_bAmpSequenceCheckingStarted = true;
        }
        m_lLastAmpPacketSequence = static_cast<unsigned long>(pSignalPacket->packetHeader.sequenceNumber);

        // ------------------------------------------------------
        // Process data from the amplifier (updates this->m_bLastPacketValid)
        // ------------------------------------------------------
        GetDataFromPacket(*pSignalPacket);
    }

	// [hkc:02.11.2013]:
	//
	// Wake up the send thread upon receiving the first valid signal packet from
	// the amplifier (initiates the sending of command packets). The association
	// between amplifier and application is established only *once* per lifetime
	// of the application.
	//
	// The destination MAC address of  the  amplifier is determined by examining
	// the first valid signal packet we receive. We thereupon send *all* command
	// packets to that MAC address. Since the affinity between the amplifier and
	// our application is set only once, it is  *critical* that the first signal
	// packet we process from the amplifier is valid.

	if (this->m_hSendThread != NULL && !this->m_bSendThreadAlive && this->m_bLastPacketValid) {
		std::memcpy(this->m_DestAddress, &pW32NPacket->PacketBuffer[MSrcAddr], 6);
		::ResumeThread(this->m_hSendThread);
		this->m_bSendThreadAlive = true;
		this->m_bSendPackets = true;
	}

	return;
}

DWORD CCommunication::CalcDroppedPackets(const DWORD& prevSeq, const DWORD& currSeq)
{
    DWORD droppedPkts = 0;
    if (currSeq >= prevSeq) 
    {
        droppedPkts = currSeq - prevSeq - 1;
    }
    else // Larry Hull confirmed Amp wraps seq as an unsigned quantity
    {
        droppedPkts = 0xFFFFFFFFL - prevSeq + currSeq;
    }
    return droppedPkts;
}

/////////////////////////////////////////////////////////////////////////////
//// CreateReceivePackages
// Purpose	:	Allocate memory and create event handles for the specified number of packet "packages". 
// Parameters	:	nPackageCount - The number of packet packages to create.
// Return Value	:  If successfull, returns pointer to an array of packet packages.
// Remarks	:	NDISHOOK uses multiple concurrent asynchronous IOCTL_NDISHOOK_PACKET_READ calls as a means to reduce packet loss.
// Each receive "package" is a data structure (defined elsewhere) which contains a W32N_PACKET, OVERLAPPED and other fields needed to
// make one asynchronous call to the NDISHOOK driver.
// This function simply allocates and initializes multiple packet packages.

DWORD CCommunication::CreateReceivePackages(DWORD nPackageCount, BOOL bInitOverlappedEvent)
{
	// Allocate Memory For The Packages
   DWORD	nReceivePackageSize = sizeof( SReceivePackage );

   m_Adapter.m_pRxPackageBase = NULL;
   m_Adapter.m_nPackageCount = 0;   

   m_Adapter.m_pRxPackageBase = WMAlloc<PSReceivePackage>( nReceivePackageSize * nPackageCount );

   if( !m_Adapter.m_pRxPackageBase )	{	return 0;	}

   //
   // Possibly Create The Special Windows 9X Receive Event
   // ----------------------------------------------------
   // Asynchronous I/O to Windows 9X VxD's REQUIRES a pointer to an
   // OVERLAPPED structure. In addition, the hEvent field of the
   // OVERLAPPED structure MUST be initialized to a manual reset event.
   //
   // Windows NT does NOT have the same requirement.
   //
   // If bInitOverlappedEvent is TRUE, this function will create
   // an event on a per-package basis. This, of course, limits the
   // number of packages that can be created to the number of events
   // that can be created. This limit is defined as MAXIMUM_WAIT_OBJECTS,
   // which is typically 64.
   //
   // If bInitOverlappedEvent is FALSE, this function will create
   // one special event which is assigned to ALL packages. This scheme
   // is provided to support the Windows 9X W32N_PacketReadEx() function
   // for APC's. When using W32N_PacketReadEx() and APC's on Windows 9X,
   // the special event is actually never used. Instead, the APC is called
   // using the _VWIN32_QueueUserApc() VxD system service. The special
   // receive event serves the sole purpose of satisfying the DeviceIoControl
   // call parameter checking.

   m_Adapter.m_hDummyReceiveEvent = NULL;

   if( W32N_IsWindows95() && !bInitOverlappedEvent )	
	{
      m_Adapter.m_hDummyReceiveEvent = CreateEvent(	NULL,    // Security Attributes
																		TRUE,    // Manual-Reset
																		FALSE,	// Initial State Not Signaled
																		NULL     // Event-object Name
																	);
   }

   // Initialize Each Receive Package

   for(DWORD i = 0; i < nPackageCount; ++i )	
	{
      PSReceivePackage	pRxPackage = &m_Adapter.m_pRxPackageBase[ i ];

      // Zero The Package Memory
      memset( pRxPackage, 0x00, nReceivePackageSize );

      // Set The Signature
      
      pRxPackage->m_dwSignature = RX_PACKAGE_SIGN;

      pRxPackage->m_pAdapter = &m_Adapter;

		// Initialize The OVERLAPPED Structure
      // -----------------------------------
      // Because we are performing I/O to a device, Windows does not
      // use the Offset or OffsetHigh fields of the OVERLAPPED structure.
      // This means that we can use these fields for our own purposes.
      //
      // The next two lines initialize these fields woth pointers to
      // the SHookAdapter and SReceivePackage. Later, when certain types
      // of ascynchronous I/O operations complete, are given a only a
      // pointer to the OVERLAPPED structure in the completion routine.
      //
      // Since the OVERLAPPED fields have been initialized as below,
      // pointers to the SReceivePackage structure can be recovered from
      // the OffsetHigh field.
      //
      // Do not use the Offset field. On the Windows 9X platform Offset
      // is used to return completion status IF the operation does not
      // fail immediately.
      //
      pRxPackage->m_OverLapped.OffsetHigh = (DWORD )pRxPackage;

      //
      // Create The OVERLAPPED Event To Wait On
      //
      if( bInitOverlappedEvent && i < MAXIMUM_WAIT_OBJECTS )	
		{
         pRxPackage->m_OverLapped.hEvent = CreateEvent(	NULL,      // Security Attributes
																		TRUE,      // Manual-Reset
																		FALSE,   // Initial State Not Signaled
																		NULL      // Event-object Name
																	);

         // Verify That The Event Was Created

         if( !pRxPackage->m_OverLapped.hEvent )	
			{
            //free( pRxPackage );   // Free This Partailly Built One Only...

            return( m_Adapter.m_nPackageCount );
         }
      }	
		else	
		{
         if( W32N_IsWindows95() )	
			{
            pRxPackage->m_OverLapped.hEvent = m_Adapter.m_hDummyReceiveEvent;
         }	
			else	
			{
            pRxPackage->m_OverLapped.hEvent = NULL;
         }
      }

      // Setup Allocated Buffer Size

      pRxPackage->m_UserPacketData.nBufferSize = PACKET_BUFFER_SIZE;

      // Add Handle To Array For Call To WaitForMultipleObjects
      // ------------------------------------------------------
      // This is used for the WaitForMultipleObject asynchronous I/O method only...

      if( i < MAXIMUM_WAIT_OBJECTS )	
		{
         m_Adapter.m_PackageHandles[ i ] = pRxPackage->m_OverLapped.hEvent;
      }

      ++m_Adapter.m_nPackageCount;
   }

   return m_Adapter.m_nPackageCount;
}

void CCommunication::Log( long lStart, PUCHAR puPacketBuffer, int iBufferDataLength)
{
   // Sanity Checks
   if( !puPacketBuffer )	{	return ;	}

   if( !iBufferDataLength )			{	return ;	}

	PUCHAR pszBuffer = WMAlloc<PUCHAR>(iBufferDataLength);	

	int iIndex=0;

   while( iBufferDataLength > 0L )	
	{
      // Print The ASCII Representations

      for(int i = 0; i < 16; ++i )	
		{
         if( iBufferDataLength - i > 0 )	
			{   
				if( _istprint( puPacketBuffer[ i ] ) )	
				{	
					pszBuffer[iIndex++] = puPacketBuffer[ i ];
            }	
				else	
				{
               //AfxTrace( "%c", '.' );
            }
         }	
			else	
			{
            //AfxTrace( "%c", '.' );
         }
      }

      iBufferDataLength -= 16;

      lStart += 16L;

      puPacketBuffer += 16;
   }

	WMFree(pszBuffer);
}


/////////////////////////////////////////////////////////////////////////////
// Purpose			:	Verify that the SSendPackage is valid.
// Parameters		:
//   PSSendPackage pTxPackage - Pointer to the SSendPackage to be verified.
// Return Value	:	Returns TRUE if the package is valid. Returns FALSE otherwise.
// Remarks			:	Structured Exception Handling (SEH) is also used for debug builds. SEH is not used in release builds because IsValidSendPackage()
// can be called fairly often of the same package and the use of SEH could introduce a performance penalty.
bool CCommunication::IsValidSendPackage( PSSendPackage pTxPackage )
{
   bool  bResult = true;

   // Sanity Checks

   if( !pTxPackage )
	{
		return false;
	}

   // Test Signature
   // --------------
   // Use Structured Exception Handling (SEH) for _DEBUG builds.
#ifdef _DEBUG
   __try
#endif
   {
      // Check Send Package Signature
      if( pTxPackage->m_dwSignature != TX_PACKAGE_SIGN )
		{

         bResult = false;
      }
   }
#ifdef _DEBUG
   __except(EXCEPTION_EXECUTE_HANDLER)
   {
      bResult = false;
   }
#endif

   return bResult;
}

/////////////////////////////////////////////////////////////////////////////
//// DestroySendPackage
// Purpose	:	Destroy SSendPackage resources.
VOID CCommunication::DestroySendPackage( PSSendPackage pTxPackage )
{
   // Sanity Checks

   if( !IsValidSendPackage( pTxPackage ) )
	{
		return;
	}

   if( pTxPackage->m_dwSignature != TX_PACKAGE_SIGN )
	{
		return;
	}

   // Zap The Signature For Sanity Checks
   pTxPackage->m_dwSignature = 0;

   if( pTxPackage->m_OverLapped.hEvent )	
	{
      CloseHandle( pTxPackage->m_OverLapped.hEvent );
   }

	pTxPackage->m_OverLapped.hEvent=NULL;

   delete pTxPackage;	pTxPackage = NULL;
}

/////////////////////////////////////////////////////////////////////////////
// Purpose	:	Allocate and initialize a SSendPackage resources.
// Parameters	:
//   pAdapter -  Pointer to the SHookAdapter structure describing the adapter
//               that the packet is to be sent on. The adapter link source
//               address and medium is gleaned from SHookAdapter.
//   nDataSize - The desired size of the packet payload (bytes following
//               the link header).
//   bInitOverlappedEvent - If TRUE, call CreateEvent to initialize the OverLapped hEvent handle.
// Return Value	:	If successful, return is pointer to initialized SSendPackage structure.
// On failure, returns NULL pointer.
//
// Remarks	:	The SSendPackage must be freed with a call to DestroySendPackage() to properly free resources allocated for the SSendPackage.
//
// The PacketBufferSpace buffer is initialized with the BROADCAST destination address and the adapter's source address. The type is set to EXPERIMENTAL
// so it will not intefer with "real" protocols. The packet payload (following the link header) is filled with a pattern of upper case characters that
// changes with each packet. The OverLapped.hEvent is initialized with CreateEvent().

PSSendPackage CCommunication::CreateSendPackage(DWORD nDataSize, BOOL bInitOverlappedEvent, bool bSendToAmp )
{
   // Make Sure Driver Has Been Opened
   if( m_Adapter.m_hDevice == INVALID_HANDLE_VALUE )	{	return NULL;	}

   // Create Packet According To Medium
	// Allocate The Send Package
	PSSendPackage pTxPackage = Create802_3SendPackage(nDataSize, bSendToAmp  );
   //AfxTrace("send time %ld\n", theApp.m_uiMSecTimer);

   // Common Initialization
   if( pTxPackage )	{

      pTxPackage->m_dwSignature = TX_PACKAGE_SIGN;      // Signature

      pTxPackage->m_pAdapter = &m_Adapter;               // Adapter Pointer

      // Initialize The OVERLAPPED Structure
      // -----------------------------------
      // Because we are performing I/O to a device, Windows does not use the Offset or OffsetHigh fields of the OVERLAPPED structure.
      // This means that we can use these fields for our own purposes.
      // The next line initializes the OffsetHigh field with a pointer to the SSendPackage. Later, when certain types of ascynchronous
      // I/O operations complete, are given a only a pointer to the OVERLAPPED structure in the completion routine.
      // Since the OVERLAPPED OffsetHigh field has been initialized as below, the pointers to the SSendPackage structure can be recovered from the
      // OffsetHigh fields. Do not use the Offset field. On the Windows 9X platform Offset is used to return completion status IF the operation does not
      // fail immediately.

      pTxPackage->m_OverLapped.OffsetHigh = (DWORD )pTxPackage;

      // Create The OVERLAPPED Event To Wait On

      if( bInitOverlappedEvent )	
		{
			pTxPackage->m_OverLapped.hEvent = CreateEvent( NULL,    // Security Attributes
																		TRUE,    // Manual-Reset
																		FALSE,   // Initial State Not Signaled
																		NULL     // Event-object Name
																	 );

         if( !pTxPackage->m_OverLapped.hEvent )	
			{
            delete pTxPackage;	pTxPackage=NULL;	

            return (PSSendPackage)NULL;
         }
      }	
		else
		{
         pTxPackage->m_OverLapped.hEvent = NULL;
      }
   }

   return pTxPackage;
}

// Comment
// -------
// All HookPeek samples illustrate sending of packets. Although the method used to send a packet may vary from one example to another,
// in all samples a buffer containing the link header and payload to be sent must be created.
// Since the work of building the buffer to be sent is common to all HookPeek examples, it has been moved to this Common program module
// instead of being duplicated in each HookPeek program directory.

/////////////////////////////////////////////////////////////////////////////
// Purpose		:	Allocate and initialize 802.3 SSendPackage resources.
// Parameters	:
//   pAdapter -  Pointer to the SHookAdapter structure describing the adapter that the packet is to be sent on. The adapter link source
//               address is gleaned from SHookAdapter.
//   nDataSize - The desired size of the packet payload (bytes following the link header).
//   bInitOverlappedEvent - If TRUE, call CreateEvent to initialize the  OverLapped hEvent handle.
// Return Value: If successful, return is pointer to initialized SSendPackage structure. On failure, returns NULL pointer.
// Remarks		: The SSendPackage must be freed with a call to DestroySendPackage() to  properly free resources allocated for the SSendPackage.
// The PacketBufferSpace buffer is initialized with the BROADCAST destination address and the adapter's source address. The type is set to EXPERIMENTAL
// so it will not intefer with "real" protocols. The packet payload (following the link header) is filled with a pattern of upper case characters that
// changes with each packet. The OverLapped.hEvent is initialized with CreateEvent().

PSSendPackage CCommunication::Create802_3SendPackage(DWORD nDataSize, bool bSendToAmp )
{
   // Allocate The Send Package

	PSSendPackage  pTxPackage = new SSendPackage;

   if( !pTxPackage )	{	return (PSSendPackage) NULL;	}

   // Fill The Data Buffer

   static unsigned int PktSendCount = 0;

	// Sanity Check On The Frame Size
	if( MHdrSize + nDataSize > PACKET_BUFFER_SIZE )
	{
		return (PSSendPackage) NULL;
	}

	// Save The Frame Size
	pTxPackage->m_dwFrameSize = MHdrSize + nDataSize;

	memset(&m_pktToAmp, 0, sizeof(m_pktToAmp));

	memcpy(m_pktToAmp.ethernetHeader.targetAddress, m_DestAddress, ETHER_ADDR_LENGTH ); //set from address
	memcpy(m_pktToAmp.ethernetHeader.sourceAddress, m_Adapter.m_CurrentAddress, ETHER_ADDR_LENGTH ); //set from address

	m_pktToAmp.ethernetHeader.packetType = WM_PACKET_TYPE;
	memcpy(
		m_pktToAmp.packetHeader.packetVersion,
		WM_PACKET_VERSION,
		WM_PACKET_VERSION_BYTE_LENGTH
	);

	m_pktToAmp.packetHeader.packetNumber = PktSendCount;
	m_pktToAmp.packetHeader.sequenceNumber = PktSendCount++;
	m_pktToAmp.packetHeader.packetByteLength = sizeof(SWMCommandPacket);
	m_pktToAmp.packetHeader.packetDataByteLength = sizeof(SWMCommandPacketPayload);

	m_pktToAmp.payload.syncOutNegative = theApp.m_dMonitor.m_shSignalHeader.map.config[theApp.m_dCathMap.m_CathMap.channelindex.chan_out_screen][theApp.m_dCathMap.m_CathMap.channelindex.chan_out_config].neg_offset;
	m_pktToAmp.payload.syncOutPositive = theApp.m_dMonitor.m_shSignalHeader.map.config[theApp.m_dCathMap.m_CathMap.channelindex.chan_out_screen][theApp.m_dCathMap.m_CathMap.channelindex.chan_out_config].pos_offset;

	for (int i = 0; i < WM_PACKET_AMPLIFIER_PRESSURE_CHANNEL_COUNT; ++i) {
		m_pktToAmp.payload.bloodPressureControl[i] = m_ariZeroPressure[i];
	}
	
	m_pktToAmp.payload.stimMarkerDuration = (UCHAR)theApp.m_INIfile.m_iStimMarkerTime;
	m_pktToAmp.payload.highPassShift = 
#ifdef AMPCONFIG_INCLUDE_HIPASSFILTER
        theApp.m_INIfile.m_iHighPassShift
#else
        m_iHighPassShift;
#endif
	m_pktToAmp.payload.analogAcquisitionSampleRate = SAMPLE_RATE;

	// Malibu extensions
	// {

	m_pktToAmp.payload.stimRoutingPositiveA = theApp.m_dCathMap.m_PacingSite.A_pos;
	m_pktToAmp.payload.stimRoutingNegativeA = theApp.m_dCathMap.m_PacingSite.A_neg;
	m_pktToAmp.payload.stimRoutingPositiveB = theApp.m_dCathMap.m_PacingSite.A2_pos;
	m_pktToAmp.payload.stimRoutingNegativeB = theApp.m_dCathMap.m_PacingSite.A2_neg;
	m_pktToAmp.payload.stimRoutingPositiveC = theApp.m_dCathMap.m_PacingSite.B_pos;       // New Stim C+
	m_pktToAmp.payload.stimRoutingNegativeC = theApp.m_dCathMap.m_PacingSite.B_neg;       // New Stim C-
	m_pktToAmp.payload.stimRoutingPositiveD = theApp.m_dCathMap.m_PacingSite.B2_pos;       // New Stim D+
	m_pktToAmp.payload.stimRoutingNegativeD = theApp.m_dCathMap.m_PacingSite.B2_neg;
	for (int i = 0; i < WM_PACKET_AMPLIFIER_ANALOG_OUTPUT_COUNT; ++i) {
		theApp.m_INIfile.m_ampAnalogOutputSetting[i].Serialize(m_pktToAmp.payload.analogOutput[i]);

		// notch filter settings are per application, not per signal
		m_pktToAmp.payload.analogOutput[i].notchFilter = theApp.m_INIfile.m_iNotchFilter;
	}
	//}

	m_pktToAmp.payload.amplifierSoftReset = this->m_bAmplifierResetFlag ? CCommunication::AmplifierSoftResetCommand : 0;
	this->m_bAmplifierResetFlag = false;

	memcpy( &pTxPackage->m_szPacketBufferSpace, &m_pktToAmp, pTxPackage->m_dwFrameSize );

   return pTxPackage;
}


inline long AdjustTempValue(register long iTemp)
{
	iTemp = (long)(iTemp*theApp.m_INIfile.m_aratThdInit[TRIG_TEMP].floor*0.001 + 0.5); // the gain is based on 1000 for integerization
	iTemp -= (short)theApp.m_INIfile.m_aratThdInit[TRIG_TEMP].level; // was a USHORT, subtract off the offset, now it is in degrees C*10

	if (iTemp>=TEMP_START && iTemp<TEMP_STOP) // correction factor
	{
		iTemp = iTempCalibrationTable[iTemp-TEMP_START];
	}

	//switch (iTemp/10)

	return iTemp - 400; // off by 40 degrees *10
}

inline long AdjustPressureValue(long iPressure)
{
	// Given a pressure value P mmHg, WorkMate expects to receive a raw value of P' = P * 2.
	// The Malibu amplifier sends pressure values in P'' = P * 1,000,000.
	//
	// We therefore need to convert from the Malibu raw value P'' to P':
	//
	// P' = P * 2 = (P'' / 1,000,000) * 2 = P'' / 500,000.
	//
	// Exception: if the pressure value is not in the valid range for pressure data, we send
	// out BAD_ECG_VALUE_32BIT, which is handled as "no data" in the application.

	const double PressureScaling = 500000.0;

	long iAdjustedPressureValue = BAD_ECG_VALUE_32BIT;

	switch (iPressure) {
	case CCommunication::PRESSURE_BAD_DATA_1:
	case CCommunication::PRESSURE_BAD_DATA_2:
		break;

	default:
		iAdjustedPressureValue = long(double(iPressure) / PressureScaling);
		break;
	}

	return iAdjustedPressureValue;
}

/////////////////////////////////////////////////////////////////////////////////////////
void CCommunication::GetDataFromPacket(SWMSignalPacket& signalPacket) // Pressure value adjustments prevents this from being const
{
	try
	{
		// [hkc:06.14.2012]: wrong packet header version (incompatible packet).
		static bool bErrReport = false;
		if (std::memcmp(signalPacket.packetHeader.packetVersion, WM_PACKET_VERSION, WM_PACKET_VERSION_BYTE_LENGTH)) {
			if (!bErrReport) {
				CString temp;
				temp.Format(_T("Amp software version %4.4s is INCORRECT - will not work with 32 bit software"), signalPacket.packetHeader.packetVersion);
				CMessage::m_erLog.ReportError(temp);
				bErrReport = true;
			}
			this->m_bLastPacketValid = false;
			return;
		}

		this->m_bLastPacketValid = true;
		
		this->m_lLastAcknowledgedCommandPacket = signalPacket.payload.echoPacketHeader.sequenceNumber;

		// [hkc:05.03.2012]:
		//
		// Check the amplifier status only if we have established a connection.
		// If we are currently connecting, ignore the amplifier status--need to
		// flush incoming packets from the amplifier.
		//
		// Most recently received command packet (echoed in signal packet) from
		// amplifier is cached in packetCommand.  This variable is reachable by
		// this thread only.  If there has been a change in the command packet,
		// it is copied into the instance variable this->m_packetCommand, using
		// a critical section for thread-safety. Idea is to minimize the amount
		// of contention on the critical section.

		static SWMCommandPacketPayload packetCommand;

		const DWORD dwReservedSet = signalPacket.payload.amplifierStatus & AMP_STATUS_MASK_RESERVED;
		const DWORD dwCheckedSet = signalPacket.payload.amplifierStatus & AMP_STATUS_MASK_CHECKED;

		if (this->IsConnectionStateConnected()) {
			if (dwReservedSet != 0) {
				theApp.m_INIfile.m_dwAmplifierStatus |= AMP_STATUS_MASK_RESERVED;
			}
			if (dwCheckedSet != 0) {
				if ((theApp.m_INIfile.m_dwAmplifierStatus & AMP_STATUS_MASK_RESERVED) == 0) {
					theApp.m_INIfile.m_dwAmplifierStatus |= dwCheckedSet;
				}
			}
			
			if (this->HasAmplifierError()) {
				if (std::memcmp(&packetCommand, &signalPacket.payload.echoCommandPacket, sizeof(SWMCommandPacketPayload))) {
					packetCommand = signalPacket.payload.echoCommandPacket;
					this->SetAmplifierCommandPacket(signalPacket.payload.echoCommandPacket);
				}
			}
		}

		if(!theApp.m_bProcessData) return;

		// reported in Software Versions screen of Help dialog.
		theApp.m_dMonitor.m_szAmpVersion[0] = signalPacket.packetHeader.packetVersion[0];
		theApp.m_dMonitor.m_szAmpVersion[1] = signalPacket.packetHeader.packetVersion[1];
		theApp.m_dMonitor.m_szAmpVersion[2] = signalPacket.packetHeader.packetVersion[2];
		theApp.m_dMonitor.m_szAmpVersion[3] = signalPacket.packetHeader.packetVersion[3];
		theApp.m_dMonitor.m_szAmpVersion[4] = 0;
		theApp.m_dMonitor.m_szAmpVersion[5] = 0;

		// After the header comes the data array
		if (!theApp.m_dMonitor.m_iDemoMode) 
		{
			if (signalPacket.payload.sampleRate != SAMPLE_RATE) return;

			theApp.m_dMonitor.m_iSignalResolution = theApp.m_dMonitor.m_shSignalHeader.map.signal_resolution = signalPacket.payload.signalResolution;
			theApp.m_dMonitor.m_shSignalHeader.map.sample_rate = signalPacket.payload.sampleRate;
		}

		long* pInputData = signalPacket.payload.data;

		if (!bErrReport)
		{
			CString temp;
			temp.Format(_T("Amp software version %4.4s - resolution %d"), signalPacket.packetHeader.packetVersion, theApp.m_dMonitor.m_shSignalHeader.map.signal_resolution);
			CMessage::m_erLog.ReportError(temp);
			bErrReport=true;
		}

		static long bad_packet_count=0;

		// set zero pressure processing
		ProcessPressure(
			pInputData[56],
			pInputData[57],
			pInputData[138],
			pInputData[139],
			signalPacket.payload.pressureOffset
		);

		// adjust pressure values from raw Malibu units to units expected by WorkMate:
		pInputData[56] = AdjustPressureValue(pInputData[56]);
		pInputData[57] = AdjustPressureValue(pInputData[57]);
		pInputData[138] = AdjustPressureValue(pInputData[138]);
		pInputData[139] = AdjustPressureValue(pInputData[139]);

		if (theApp.m_INIfile.m_bTempProbe)
		{
			pInputData[139] = AdjustTempValue(pInputData[139]);
		}

		// record the time of when the data arrived
		theApp.m_dMonitor.m_ariAcquireTimeBuffer[theApp.m_dMonitor.m_usAcquirePush] = CWMLibrary::LocalTimeToMilliSeconds();

		if (theApp.m_dMonitor.m_iDemoMode) 
		{
			if(theApp.m_dMonitor.m_iDemoMode==DEMO_MODE_CONT)
			{
				// let the PMI channels come through
				memcpy(&theApp.m_dMonitor.m_ariAcquireBuffer[theApp.m_dMonitor.m_usAcquirePush][52], &pInputData[52], 6*sizeof(long));

				// PMI 7,8
				theApp.m_dMonitor.m_ariAcquireBuffer[theApp.m_dMonitor.m_usAcquirePush][138]=pInputData[138];
				theApp.m_dMonitor.m_ariAcquireBuffer[theApp.m_dMonitor.m_usAcquirePush][139]=pInputData[139];
			}
		}
		else
		{
            // ----------------------------------------------------------------------------
            // Transfer signal data from the Amp, but if the data rate is out of bounds or 
            // the associated blanking period is in effect, consider the data bad and cause 
            // all traces to flatline by substituting bad data values on all channels.
            // ----------------------------------------------------------------------------
		    memcpy(theApp.m_dMonitor.m_ariAcquireBuffer[theApp.m_dMonitor.m_usAcquirePush], 
                   ( m_RxPacketMeter.IsWithinBounds(true)) ? 
                        pInputData : 
                        m_BadDataBuffer,
                   MAX_CHANNELS*sizeof(long));
		}

		if ( ++theApp.m_dMonitor.m_usAcquirePush >= ACQUIRE_BUFFER_SIZE )	
		{	
			theApp.m_dMonitor.m_usAcquirePush=0;	
		}

		if(m_uiFirstPacketTimeReceived<=0)
		{
			m_uiFirstPacketTimeReceived=theApp.m_uiMSecTimer;
		}
		else
		{
			if (theApp.m_uiMSecTimer-m_uiLastPacketTimeReceived>500)	// 500 Msecs between packets is a long time
			{
				m_uiCommPauseCount++;
                // Force an RX rate update because no recently received 
                // packets have come in to trigger one in the normal fashion
                m_RxPacketMeter.Update(); 
			}
		}
		m_uiLastPacketTimeReceived=theApp.m_uiMSecTimer;      
		++m_uiTotalPackets;

        /// <RX Bandwidth Monitoring>
        m_RxPacketMeter.Update();
        /// </RX Bandwidth Monitoring>

		if(signalPacket.payload.bitmapActiveADCBanks & 0xff00)
		{
			theApp.m_INIfile.m_iAmplifierType = JUNCTION_BOX_120; // it is a 120 Channel Amp
		}
		else
		{
			if(!(signalPacket.payload.bitmapActiveADCBanks & 0x00f0))
			{
				theApp.m_INIfile.m_iAmplifierType = JUNCTION_BOX_24; // it is a 24 channel Amp
			}
			else
			{
				theApp.m_INIfile.m_iAmplifierType = JUNCTION_BOX_56_PMI9;
			}
		}

		if(theApp.m_bProcessData)	
		{ 
			theApp.m_dMonitor.ProcessInputData();	
		} else {
			// acquirepop and push should always match
			theApp.m_dMonitor.m_usAcquirePop=theApp.m_dMonitor.m_usDisplayPush=theApp.m_dMonitor.m_usAcquirePush;
		}
	}
	catch(CVMException& v)
	{
		CMessage::m_erLog.ReportError( v.Translate() );
	}
}

bool CCommunication::GetAdapterInfo(void)
{
	/* Get OS/Platform Version Information
	-------------------------------------- */

	if( !( theApp.m_osInfo.dwPlatformId==VER_PLATFORM_WIN32_NT || theApp.m_osInfo.dwPlatformId==VER_PLATFORM_WIN32_WINDOWS ) )
	{
		CMessage::PopupMessage(WMFILELINE, 53);

		return false;
	}

	if( theApp.m_osInfo.dwPlatformId==VER_PLATFORM_WIN32_NT )	
	{
		if( theApp.m_osInfo.dwMajorVersion < 4 )	
		{
			CMessage::PopupMessage(WMFILELINE, 54);

			return false;
		}
	}

   //
   // Get Driver Version Number
   // -------------------------
   // WinDis 32 V5.00.12.44 and higher use different driver names for Windows 9X, Windows NT and Windows 2000.
   //
   // Earlier versions used the common "PCANDIS5" name for the driver name on all platrofms.
   //
	if( theApp.m_osInfo.dwPlatformId==VER_PLATFORM_WIN32_NT )	
	{
		if( theApp.m_osInfo.dwMajorVersion == 5 )	
		{
         // Windows 2000. Looking for PCANDIS5.SYS
	      GetDriverVersion( PCANDIS5_BASE_NAME );
      }	
		else	
		{
         // Windows NT 4.0. Looking for PCANDIS4.SYS
	      GetDriverVersion( PCANDIS4_BASE_NAME );
      }
   }	
	else	
	{
		// Windows 9X. Looking for PCANDIS3.VXD
	   GetDriverVersion( PCANDIS3_BASE_NAME );
   }

	if( !FillAdapterList() )	{	return false;	}

	return true;
}

int CCommunication::FillAdapterList(void)
{
	HKEY	hKeyClassNet=NULL;

	long	lResult=0L;

	if( W32N_IsWindowsNT() )	
	{
		DWORD nVersion = W32N_OSGetPlatformVersion( VER_PLATFORM_WIN32_NT );

		if( nVersion==0x0005 )	
		{
			// Open NetworkCard Key For Windows NT 4.5
			lResult = RegOpenKeyEx(	HKEY_LOCAL_MACHINE,
											W32N_REGSTR_PATH_CLASS_NET_NT5,	// Address Of Name Of Subkey To Open
											0,											// Options (Reserved)
											KEY_READ,								// Security Access Mask
											&hKeyClassNet );
		}	
		else	
		{
			// Open NetworkCard Key For Windows NT 4.0
			lResult = RegOpenKeyEx(	HKEY_LOCAL_MACHINE,
											W32N_REGSTR_PATH_NETCARDS,	// Address Of Name Of Subkey To Open
											0,									// Options (Reserved)
											KEY_READ,						// Security Access Mask
											&hKeyClassNet );
		}
	}	
	else	
	{
		// Open Class\\Net Key For Windows 95
		lResult = RegOpenKeyEx(	HKEY_LOCAL_MACHINE,
										W32N_REGSTR_PATH_CLASS_NET,	// Address Of Name Of Subkey To Open
										0,										// Options (Reserved)
										KEY_READ,							// Security Access Mask
										&hKeyClassNet );
	}

	register int iAdapterCount = 0;

	if( lResult==ERROR_SUCCESS )	
	{
		register DWORD dwIndex = 0;

		while( lResult == ERROR_SUCCESS )	
		{
			TCHAR szName[16]={0};
			DWORD cbName = 16L;

			lResult = RegEnumKeyEx(	hKeyClassNet,	// Handle Of Key To Enumerate
											dwIndex,			// Index Of Subkey To Enumerate
											szName,			// Buffer For Subkey Name
											&cbName,			// Size Of Subkey Name
											NULL,				// Reserved, Must Be NULL
											NULL,				// Buffer For Class String
											NULL,				// Size Of Class Buffer
											NULL				// Time Key Last Written To
											);

			if( lResult != ERROR_SUCCESS )	{	break;	}

			CAdapterInfo aiAdapterInfo;
			aiAdapterInfo.GetInfo(szName, theApp.m_osInfo);
			m_vtAdapterArray.push_back( aiAdapterInfo );

			++dwIndex;
			++iAdapterCount;
		}

		RegCloseKey( hKeyClassNet );
	}

	return iAdapterCount;
}

void CCommunication::GetDriverVersion( LPCTSTR lpDriverBaseName ) 
{	
	// Dispatch To Platform-Dependent Handlers
	if( theApp.m_osInfo.dwPlatformId==VER_PLATFORM_WIN32_NT )	
	{
		GetDriverVersionNT( lpDriverBaseName );
	}	
	else if( theApp.m_osInfo.dwPlatformId==VER_PLATFORM_WIN32_WINDOWS )	
	{
		GetDriverVersion95( lpDriverBaseName );
	}
}

void CCommunication::GetDriverVersionNT( LPCTSTR lpDriverBaseName ) 
{	
	CString strAppPath;

	LPTSTR pszFileName = strAppPath.GetBuffer(_MAX_PATH + 1);

	CString csDriverExePath;

	if( ::GetSystemDirectory( pszFileName, _MAX_PATH) > 0)	
	{
		csDriverExePath.Format(_T("%s//%s.SYS"), strAppPath, lpDriverBaseName );
	}

	DWORD dwType=0L;
	DWORD dwDataLen = GetFileVersionInfoSize( (PTCHAR)(LPCTSTR)csDriverExePath, &dwType );

	m_csDriverVersionString = _T("Unknown");

	PVOID pszBuffer = WMAlloc<PVOID>(dwDataLen + 1);

	if (pszBuffer == NULL)	{	return;	}

	if (GetFileVersionInfo( (PCHAR )(LPCTSTR )csDriverExePath, 0L, dwDataLen, pszBuffer) == TRUE)	
	{
		VS_FIXEDFILEINFO* pFileInfo=NULL;

		if (VerQueryValue(pszBuffer, _T( "\\" ), (void **)&pFileInfo, (UINT *)&dwDataLen) == TRUE)	
		{
			TCHAR	szScratch[16]={0};

			memcpy( &m_DriverVersionInfo, pFileInfo, sizeof( VS_FIXEDFILEINFO ) );

			_stprintf( szScratch, _T("%d.%2.2d.%2.2d.%2.2d"),
						HIWORD( m_DriverVersionInfo.dwFileVersionMS ),
						LOWORD( m_DriverVersionInfo.dwFileVersionMS ),
						HIWORD( m_DriverVersionInfo.dwFileVersionLS ),
						LOWORD( m_DriverVersionInfo.dwFileVersionLS ));

			m_csDriverVersionString = szScratch;
		}
	}

	WMFree(pszBuffer);
}

void CCommunication::GetDriverVersion95( LPCTSTR lpDriverBaseName ) 
{	
	PCHAR pText = _T("NDISHOOK.VXD");
	DWORD dwType=0L;
	DWORD dwDataLen = GetFileVersionInfoSize( pText, &dwType);

	m_csDriverVersionString = _T("Unknown");

	PVOID pszBuffer = WMAlloc<PVOID>(dwDataLen + 1);

	if (pszBuffer == NULL)
		return;

	if (GetFileVersionInfo( pText, 0L, dwDataLen, pszBuffer) == TRUE)
	{
		VS_FIXEDFILEINFO *pFileInfo;
		if (VerQueryValue(pszBuffer, _T( "\\" ), (void **)&pFileInfo, (UINT *)&dwDataLen) == TRUE)
		{
			TCHAR	szScratch[16]={0};

			memcpy( &m_DriverVersionInfo, pFileInfo, sizeof( VS_FIXEDFILEINFO ) );

			_stprintf( szScratch, _T("%d.%2.2d.%2.2d.%2.2d"),
				HIWORD( m_DriverVersionInfo.dwFileVersionMS ),
				LOWORD( m_DriverVersionInfo.dwFileVersionMS ),
				HIWORD( m_DriverVersionInfo.dwFileVersionLS ),
				LOWORD( m_DriverVersionInfo.dwFileVersionLS )
				);

			m_csDriverVersionString = szScratch;
		}
	}
	WMFree(pszBuffer);
}


// reset session with amplifier--called whenever we start a new study.
void CCommunication::ResetSession()
{
	// disable any outstanding zero pressure requests
	theApp.m_iZeroPressure = 0;

	// need to force user to re-zero pressure channels.
	for (int i = 0; i < WM_PACKET_AMPLIFIER_PRESSURE_CHANNEL_COUNT; ++i) {
		m_ariZeroPressure[i] = PRESSURE_RAILED;
	}
}


void CCommunication::ProcessPressure(long p0, long p1, long p2, long p3, long offsets[4])
{
	// these are static because this method is re-entrant:
	static int wait_count = 0;

	// set_count signifies which pressure channel we are currently zeroing.
	// set_limit signifies which pressure channel we want to zero up to.
	// so, to start off a zeroing of all channels:
	//     set_count = 0 (start at first pressure channel)
	//     set_limit = 3 (stop at last pressure channel)
	// to zero a single channel i:
	//     set_count = i
	//     set_limit = i
	static int set_count = 0;
	static int set_limit = 0;

	// when we send a zero pressure request, we expect a response from the amplifier
	static bool zero_set_ack_received = false;

	// number of samples we wait for the amplifier to perform a zero pressure
	const unsigned int zero_set_timeout = SAMPLE_RATE * 2;

	// number of samples we wait for the amplifier to start sending normalized pressure data
	const unsigned int norm_set_timeout = SAMPLE_RATE;

	// place pressure values into array for access by pressure channel
	long pPressureValue[4];
	pPressureValue[0] = p0;
	pPressureValue[1] = p1;
	pPressureValue[2] = p2;
	pPressureValue[3] = p3;

	// represents the states in the zero pressure algorithm:
	enum {
		eOff = 0,			// not performing a zero pressure

		eInit = 1,			// zero pressure on all pressure channels:   set_count = 0; set_limit = 3;
		eInit5 = 5,			// zero pressure on pressure channel 0 only: set_count = 0; set_limit = 0;
		eInit6 = 6,			// zero pressure on pressure channel 1 only: set_count = 1; set_limit = 1;
		eInit7 = 7,			// zero pressure on pressure channel 2 only: set_count = 2; set_limit = 2;
		eInit8 = 8,			// zero pressure on pressure channel 3 only: set_count = 3; set_limit = 3;

		eZeroSetStart = 9,	// start zero pressure process for pressure channel set_count
		eZeroSet = 2,		// send zero pressure request to amplifier
		eZeroSetWait = 3,	// wait for amplifier to perform zero pressure

		eZeroSample = 4,	// verify zero pressure has been performed;
							// set_count <- set_count + 1;
							// goto eZeroSetStart if (set_count > set_limit);

		eZeroDone = 10
	};

	// FYI:
	//
	// When performing zero pressure on all pressure channels, current algorithm iterates
	// over each pressure channel separately. The amplifier is capable of performing zero
	// pressure on all pressure channels simultaneously. The original implementation of
	// this algorithm was iterative in nature, we keep it that way to maintain user
	// experience--this may change at a future date.

	switch (theApp.m_iZeroPressure) {
	case eInit:
		set_count = 0;	// start: pressure channel 0
		set_limit = 3;	// stop:  pressure channel 3
		theApp.m_iZeroPressure = eZeroSetStart;
		break;

	case eInit5:
		set_count = 0;	// start: pressure channel 0
		set_limit = 0;	// stop:  pressure channel 0
		theApp.m_iZeroPressure = eZeroSetStart;
		break;

	case eInit6:
		set_count = 1;	// start: pressure channel 1
		set_limit = 1;	// stop:  pressure channel 1
		theApp.m_iZeroPressure = eZeroSetStart;
		break;

	case eInit7:
		set_count = 2;	// start: pressure channel 2
		set_limit = 2;	// stop:  pressure channel 2
		theApp.m_iZeroPressure = eZeroSetStart;
		break;

	case eInit8:
		set_count = 3;	// start: pressure channel 3
		set_limit = 3;	// stop:  pressure channel 3
		theApp.m_iZeroPressure = eZeroSetStart;
		break;

	case eZeroSetStart:
		theApp.m_iZeroPressure = eZeroSet;
		wait_count = 0;
		zero_set_ack_received = false;
		break;

	case eZeroSet:
		m_ariZeroPressure[set_count] = PRESSURE_SETZERO;
		theApp.m_iZeroPressure = eZeroSetWait;
		break;

   case eZeroSetWait:
		if (++wait_count > zero_set_timeout) {
			if (zero_set_ack_received) {
				m_ariZeroPressure[set_count] = PRESSURE_NORMALIZED;
			}
			else {
				m_ariZeroPressure[set_count] = PRESSURE_RAILED;
			}

			theApp.m_iZeroPressure = eZeroSample;
			wait_count = 0;
		}
		else if (zero_set_ack_received == false) {
			// look for zero pressure acknowledgement from amplifier
			zero_set_ack_received = (pPressureValue[set_count] == PRESSURE_BAD_DATA_2);
		}
		break;

	case eZeroSample:
		if (zero_set_ack_received) {
			// if we're here, we received a zero set acknowledgement and requested normalized pressure data
			if (++wait_count > norm_set_timeout) {
				// we still haven't received normalized pressure data so the zero set operation failed.
				m_ariZeroPressure[set_count] = PRESSURE_RAILED;
				theApp.m_iZeroPressure = (++set_count > set_limit) ? eZeroDone : eZeroSetStart;
			}
			else {
				switch (pPressureValue[set_count]) {
				case PRESSURE_BAD_DATA_1:
				case PRESSURE_BAD_DATA_2:
					// we're still not getting normalized pressure data...
					break;

				default:
					// we received normalized pressure data--pressure offset can be stored now
					m_arlPressureOffset[set_count] = offsets[set_count];
					theApp.m_iZeroPressure = (++set_count > set_limit) ? eZeroDone : eZeroSetStart;
					break;
				}
			}
		}
		else {
			// we never got a zero pressure acknowledgement from amplifier
			theApp.m_iZeroPressure = (++set_count > set_limit) ? eZeroDone : eZeroSetStart;
		}
		break;

	case eZeroDone:
		theApp.m_iZeroPressure = eOff;
		break;

	case eOff:
		// we need to continually monitor the pressure offset PO reported by the amplifier and
		// compare it with the pressure offset PO' we expect (and store for the life of a study session).
		//
		// if PO != PO', we need to ask for railed pressure data.
		//
		// why do we need to continously check for PO != PO'?
		//     during a power-cycling of the amplifier, the amplifier may lose the PO information
		//     it has stored. whenever this occurs, we must re-zero the pressure channel.

		for (int i = 0; i < WM_PACKET_AMPLIFIER_PRESSURE_CHANNEL_COUNT; ++i) {
			if (m_ariZeroPressure[i] == PRESSURE_NORMALIZED && m_arlPressureOffset[i] != offsets[i]) {
				m_ariZeroPressure[i] = PRESSURE_RAILED;
			}
		}
		break;

	default:
		theApp.m_iZeroPressure = eOff;
		break;
	}
}


bool CCommunication::HasAmplifierError() const
{
	// [hkc:12.04.2012]: simulate amplifier status OK in demonstration mode {
	return ((theApp.m_dMonitor.m_iDemoMode == 0) && (theApp.m_INIfile.m_dwAmplifierStatus != AMP_STATUS_OK));
	// }
}


bool CCommunication::HasAmplifierErrorClearPending() const
{
	return (this->m_bAmplifierErrorClearPending);
}


void CCommunication::AmplifierErrorClear()
{
	this->m_bAmplifierErrorClearPending = true;
}


DWORD CCommunication::GetAmplifierStatus() const
{
	return (theApp.m_INIfile.m_dwAmplifierStatus);
}


DWORD CCommunication::GetAmplifierStatus(LPTSTR pszAmplifierStatus, DWORD dwBufferCharacterLength) const
{
	const DWORD dwAmplifierStatus = this->GetAmplifierStatus();

	if (pszAmplifierStatus && dwBufferCharacterLength) {
		typedef struct { DWORD dwStatusCode; LPCTSTR pszStatusCode; } ampStatusPair;

		const ampStatusPair pStatusLookup[] = {
			{ AMP_STATUS_MASK_RESERVED, GETMESSAGE(2270) },
			{ AMP_STATUS_CMD_TIMEOUT,   GETMESSAGE(2271) },
			{ AMP_STATUS_CMD_SEQUENCE,  GETMESSAGE(2272) },
			{ AMP_STATUS_CMD_PARAMETER, GETMESSAGE(2273) },
			{ AMP_STATUS_CMD_FORMAT,    GETMESSAGE(2274) },
			{ AMP_STATUS_GEN_HW,        GETMESSAGE(2275) },
			{ AMP_STATUS_HARD_FAIL,     GETMESSAGE(2276) }
		};
		const unsigned int nRowCount = static_cast<unsigned int>(sizeof(pStatusLookup) / sizeof(ampStatusPair));
		const TCHAR tDelimiter = _T('\n');

		std::basic_string<TCHAR> strAmplifierStatus;

		for (unsigned int i = 0; i < nRowCount; ++i) {
			if ((pStatusLookup[i].dwStatusCode & dwAmplifierStatus) != 0) {
				strAmplifierStatus.append(pStatusLookup[i].pszStatusCode);
				strAmplifierStatus.push_back(tDelimiter);
			}
		}

		std::memset(pszAmplifierStatus, 0, dwBufferCharacterLength * sizeof(TCHAR));
		std::_tcsncpy(pszAmplifierStatus, strAmplifierStatus.c_str(), dwBufferCharacterLength - 1);
	}

	return (dwAmplifierStatus);
}


bool CCommunication::GetAmplifierCommandPacket(SWMCommandPacketPayload& packetCommand)
{
	::EnterCriticalSection(&this->m_csLock);
	const bool bAmplifierNotification = this->m_bAmplifierNotification;
	if (bAmplifierNotification) {
		packetCommand = this->m_packetCommand;
		this->m_bAmplifierNotification = false;
	}
	::LeaveCriticalSection(&this->m_csLock);

	return bAmplifierNotification;
}


void CCommunication::SetAmplifierCommandPacket(const SWMCommandPacketPayload& packetCommand)
{
	::EnterCriticalSection(&this->m_csLock);
	this->m_packetCommand = packetCommand;
	this->m_bAmplifierNotification = true;
	::LeaveCriticalSection(&this->m_csLock);
}

void CCommunication::SetConnectionState(ConnectionState enumConnectionState)
{
	this->m_enumConnectionState = enumConnectionState;

    if (enumConnectionState != ConnectionStateConnected)
    {
        m_RxPacketMeter.Reset(); 
    }
}

void CCommunication::OnAmplifierConnection()
{
	// clear any pending soft-reset requests (don't want to instantly restart after connecting)
	this->m_bAmplifierResetFlag = false;

	theApp.m_dMonitor.m_bZeroDisplay[0] = true;
	theApp.m_dMonitor.m_bEnetInterrupts = true;	
    ResetRxSeqChecking();

	if (theApp.m_INIfile.m_iAmplifierType == JUNCTION_BOX_24) {
		theApp.m_fMonitor->SetAmpBar();
	}
	theApp.m_fRealTime->SetAmpBar();

	CDateTime::GetTime(theApp.m_lStartTime);
	theApp.m_iStartMS = CWMApp::GetFastTimeMS();
}

void CCommunication::OnAmplifierDisconnect()
{
	// [hkc:12.17.2012]:
	//
	// Play a beep if a zero pressure was active at time of disconnect. We make
	// the duration short since this *blocks* the communications thread. Longer
	// durations should be offloaded to the GUI thread.
	//
	// {
	if (theApp.m_iZeroPressure != 0) {
		const DWORD dwWarningFrequency = 1000;
		const DWORD dwWarningDuration = 50;

		CMessage::Beep(dwWarningFrequency, dwWarningDuration);
	}
	// }

	// clear any pending soft-reset requests (don't want to instantly restart after connecting)
	this->m_bAmplifierResetFlag = false;

	theApp.m_iZeroPressure = 0;
	theApp.m_dMonitor.m_bEnetInterrupts = false;
    ResetRxSeqChecking();
	theApp.m_fRealTime->Invalidate();
	theApp.m_fRealTime->SetAmpBar();

	if (theApp.m_INIfile.m_iAmplifierType == JUNCTION_BOX_24) {
		theApp.m_fMonitor->SetAmpBar();
	}
}

void CCommunication::ResetRxSeqChecking()
{
    m_lLastAmpPacketSequence = 0;
    m_bAmpSequenceCheckingStarted = false;
    ResetDroppedPacketCount();
}

IConfigIntegration* IConfigIntegration::AmpRateDetection()
{
    static           IConfigIntegration* theInterface = 
        dynamic_cast<IConfigIntegration*>(&(CCommunication::Instance().m_RxPacketMeter.m_Config));
	return theInterface;
}

IAmpRateDetection* IAmpRateDetection::GlobalInstance()
{
    static           IAmpRateDetection* theInterface = 
        dynamic_cast<IAmpRateDetection*>(&CCommunication::Instance().m_RxPacketMeter);
	return theInterface;
}
