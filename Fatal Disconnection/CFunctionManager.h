#pragma once

class CFuntionManager
{
public:
	int ConvertCharArrayToByteArray(unsigned char *dest, char *src);
	QStringList ConvertStringToAsciiStringList(QString str);

	bool AssemblyWriteJump(const unsigned long address, const void *destination, const size_t nops);
	bool AssemblyWriteCall(const unsigned long address, const void *destination, const size_t nops);
	bool AssemblyWriteBytes(const unsigned long address, char *bytes);

	const char *AssemblyReadStringPointer(const unsigned long base, const int offset);
	double AssemblyReadDoublePointer(const unsigned long base, const int offset);
	unsigned long AssemblyReadPointer(const unsigned long base, const int offset);
	unsigned long AssemblyGetValue(const unsigned long base, const int offset);
	unsigned long AssemblyReadIndefinitePointer(unsigned long base, const unsigned long levels, ...);
	bool AssemblyIsPointerReadable(const unsigned long address);
	bool AssemblyWritePointer(const unsigned long base, const int offset, const int value);

	unsigned long AssemblyFindPattern(const unsigned long start, const unsigned long end, const unsigned char *pattern, const unsigned long length, const unsigned char wildcard = 0x00);

	bool SetDetourHook(const bool install, void **target, void *detour);

	int GenerateRandomNumberInRange(const int min, const int max);
};

extern CFuntionManager FuntionManagerClass;