#pragma once

class CPackets
{
private:
	struct COutPacket
	{
		int loopback;
		
		union
		{
			unsigned char *data;
			void *unknown;
			unsigned short *header;
		};
		
		unsigned long size;
		unsigned int offset;
		int encrypted_by_shanda;
	};

	struct CInPacket
	{
		int loopback;
		int state;

		union
		{
			void *data;

			struct
			{
				unsigned long unknown;
				unsigned short header;
			} *header_pointer;

			struct
			{
				unsigned long unknown;
				unsigned char data[0];
			} *data_pointer;
		};
		
		unsigned short size;
		unsigned short raw_seq;
		unsigned short data_length;
		unsigned short unknown1;
		unsigned int offset;
		void *unknown2;
	};

	QStringList block_recv_packets_list;

private:
	bool TokenizePacket(QString packet, QByteArray &data);
	void InjectPacket(const COutPacket *packet);

	void HandleSendPacket(const COutPacket *packet, const unsigned long return_address);
	void HandleRecvPacket(const CInPacket *packet, const unsigned long return_address);

public:
	bool SendPacket(const QString packet);

	void AddToBlockRecvPacketsList(const QString packet);
	void RemoveFromBlockRecvPacketsList(const QString packet);
	void ClearBlockRecvPacketsList();

	void Initialize();
};

extern CPackets PacketsClass;
extern bool is_one_click_boardgame;