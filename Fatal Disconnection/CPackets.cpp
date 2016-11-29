#include "Includes.h"
#include "CMainForm.h"

CPackets PacketsClass;
bool is_one_click_boardgame;

void __declspec(naked) SendPacketHook()
{
	static DWORD retAddy = (addresses::send_hook + 5);
	static DWORD call_first = 0x01F01DCE;
	__asm
	{
		pushad
		mov eax,esp
		push [eax+0xB0]
		push [eax+0xB4]
		call CPackets::HandleSendPacket
		popad

		call [call_first]
		jmp [retAddy]
	}
}

void __declspec(naked) RecvPacketHook()
{
	__asm
	{
		push eax
		mov eax,[esp+4]
		cmp eax,[addresses::recv_hook_return]
		je main
end:
		pop eax
		jmp [addresses::recv_hook_pointer_function]

main:
		pushad
		mov eax,esp
		push [eax+0x54]
		push [eax+0x58]
		call CPackets::HandleRecvPacket
		popad
		jmp end
	}
}

bool CPackets::TokenizePacket(QString packet, QByteArray &data)
{
	packet.trimmed();
	
	if (packet.isEmpty())
	{
		return false;
	}

	QStringList list = packet.split(" ");

	for (int i = 0; i < list.count(); i++)
	{
		QString str = list.at(i);

		if (str.length() > 2)
		{
			return false;
		}

		for (int j = 0; j < str.length(); j++)
		{
			QChar c = str.at(j);

			if (c == '*')
			{
				c = QString().sprintf("%X", FuntionManagerClass.GenerateRandomNumberInRange(0, 15)).at(0);
			}

			if (!isxdigit(c.toAscii()))
			{
				return false;
			}

			str.replace(j, 1, c);
		}

		if (str.length() == 1)
		{
			str = ("0" + str);
		}

		list.replace(i, str);
	}

	data = QByteArray::fromHex(list.join("").toUtf8());

	return true;
}

void CPackets::InjectPacket(const COutPacket *packet)
{
	__asm
	{
		pushad

		push end
		push [packet]
		push [addresses::return_trampoline]

		mov ecx,[addresses::send_class_pointer]
		mov ecx,[ecx]

		jmp [addresses::CClientSocket__SendPacket]
end:
		popad
	}
}

void CPackets::HandleSendPacket(const COutPacket *packet, const unsigned long return_address)
{
	if (packet == NULL || packet->size < 2)
	{
		return;
	}

	unsigned short &header = *packet->header;
}

void CPackets::HandleRecvPacket(const CInPacket *packet, const unsigned long return_address)
{
	if (packet == NULL || packet->size < 2)
	{
		return;
	}
		
	unsigned short &header = packet->header_pointer->header;

	switch (header)
	{
	case 0x396:
		if (is_one_click_boardgame)
		{
			QStringList data;
		
			for (int i = 0; i < packet->size; i++)
			{
				data.append(QString().sprintf("%02X", packet->data_pointer->data[i]));
			}

			QString count = QStringList(data.mid(2, 4)).join(" ");
			QString keys_count = data.at(10);
			QString keys = QStringList(data.mid(14, keys_count.toInt(&*(bool*)0, 16))).join(" ");

			SendPacket("DC 02 " + count + " 01 00 " + keys_count + " 00 " + keys);
		}

		break;
	}

	/*
	for (int i = 0; i < PacketsClass.block_recv_packets_list.count(); i++)
	{
		QString str = PacketsClass.block_recv_packets_list.at(i);

		if (str == spaced_data.left(str.count()))
		{
			header = -1;
		}
	}
	*/
}

bool CPackets::SendPacket(const QString packet)
{
	QByteArray data;
	
	if (!TokenizePacket(packet, data))
	{
		return false;
	}

	COutPacket p;

	SecureZeroMemory(&p, sizeof(COutPacket));

	p.size = data.size();
	p.data = (unsigned char *)data.data();
	
	try
	{
		InjectPacket(&p);

		return true;
	}
	catch (...)
	{
		return false;
	}
}

void CPackets::AddToBlockRecvPacketsList(const QString packet)
{
	PacketsClass.block_recv_packets_list.append(packet);
}

void CPackets::RemoveFromBlockRecvPacketsList(const QString packet)
{
	PacketsClass.block_recv_packets_list.removeAll(packet);
}

void CPackets::ClearBlockRecvPacketsList()
{
	PacketsClass.block_recv_packets_list.clear();
}

void CPackets::Initialize()
{
	FuntionManagerClass.AssemblyWriteJump(addresses::send_hook, SendPacketHook, 0);
	*(void **)(addresses::recv_hook_pointer) = RecvPacketHook;
}