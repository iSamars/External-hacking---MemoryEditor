#pragma once
#include <Windows.h>

class MemoryHelper
{
public:
    int readInt(HANDLE hProcess, int addr);
    float readFloat(HANDLE hProcess, int addr);
    char* readString(HANDLE hProcess, int addr, int size);

    bool writeInt(HANDLE hProcess, int addr, int data);
    bool writeFloat(HANDLE hProcess, int addr, float data);
    bool writeString(HANDLE hProcess, int addr, char* data);
};