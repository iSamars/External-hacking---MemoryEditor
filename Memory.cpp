#include "Memory.h"

int MemoryHelper::readInt(HANDLE hProcess, int addr)
{
	int readedInt;
	ReadProcessMemory(hProcess, (LPCVOID)addr, &readedInt, sizeof(readedInt), nullptr);
	return readedInt;
}

float MemoryHelper::readFloat(HANDLE hProcess, int addr)
{
	float readedFloat;
	ReadProcessMemory(hProcess, (LPCVOID)addr, &readedFloat, sizeof(readedFloat), nullptr);
	return readedFloat;
}

char* MemoryHelper::readString(HANDLE hProcess, int addr, int size)
{
	char readedChar;
	char* readedString = new char[size];
	for (int i = 0; i < addr; i++)
	{
		ReadProcessMemory(hProcess, (LPCVOID)addr, &readedChar, sizeof(readedChar), nullptr);
		readedString[i] = readedChar;
		addr++;
	}
	return readedString;
}

bool MemoryHelper::writeInt(HANDLE hProcess, int addr, int data)
{
	if (WriteProcessMemory(hProcess, (LPVOID)addr, &data, sizeof(data), nullptr))
		return true;
	else
		return false;
}

bool MemoryHelper::writeFloat(HANDLE hProcess, int addr, float data)
{
	if (WriteProcessMemory(hProcess, (LPVOID)addr, &data, sizeof(data), nullptr))
		return true;
	else
		return false;
}

bool MemoryHelper::writeString(HANDLE hProcess, int addr, char* data)
{
	if (WriteProcessMemory(hProcess, (LPVOID)addr, &data, sizeof(data), nullptr))
		return true;
	else
		return false;
}