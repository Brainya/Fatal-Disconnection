#pragma once

typedef const unsigned long a;

namespace addresses
{
	static const char *version                          = "JMS 3.31.00";

	a CClientSocket__SendPacket                         = 0x005D4C10; // e8 ? ? ? ? be 01 00 00 00 39 ? ? ? ? ? 74 ? 89 ? ? ? ? ? e8 [call]
	a CInPacket__CInPacket                              = 0x005D53F0; // e8 ? ? ? ? 8d ? ? ? c7 ? ? ? ff ff ff ff e8 ? ? ? ? 83 ? ? ? 0f [call]

	a send_class_pointer                                = 0x01AD11F8; // 8b ? ? ? ? ? e8 ? ? ? ? 8d ? ? ? c6 ? ? ? ? ? ? 00 e8 [ptr]
	a return_trampoline                                 = (CClientSocket__SendPacket - 8);

	a recv_hook_pointer                                 = 0x0172222C;
	a recv_hook_pointer_function                        = *(a *)recv_hook_pointer;
	a recv_hook_return                                  = 0x005D5431;
	a send_hook                                         = 0x01C2D069;
}