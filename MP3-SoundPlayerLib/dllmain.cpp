// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
extern "C" __declspec(dllexport) bool PlayWAVSound(LPCSTR filename, int sounds_flags) {
    fs::path p(filename);
    if (p.empty()) {
        return false;
    }
    else {
        PlaySoundA(filename, 0, sounds_flags);
        return true;
    }
    return true;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        std::cout << "This is My First DLL Library for Playing Sound or Music... So Enjoy to use this DLL Lib!!!" << std::endl;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

