#pragma once
#include <windows.h>

#include "valve_sdk/Interfaces/IBaseClientDll.hpp"
#include "valve_sdk/Interfaces/IClientEntityList.hpp"
#include "valve_sdk/Interfaces/ICvar.hpp"
#include "valve_sdk/Interfaces/IVEngineClient.hpp"
#include "valve_sdk/Interfaces/CInput.hpp"

class C_LocalPlayer;

class Interfaces
{
public:
    static void init();

    static HMODULE safeGetModuleHandle(const std::string& moduleName);

    static IBaseClientDLL* g_baseClient;
    static IClientEntityList* g_entityList;
    static ICvar* g_convar;
    static IVEngineClient* g_engineClient;
    static CInput* g_input;
    static CGlobalVarsBase* g_globalVars;
    static unsigned char* patternScan(void* module, const char* signature);

private:
    template <typename T>
    static T* create(HMODULE moduleHandle, const std::string& interfaceName);
};

#include "customstructs.hpp"
extern C_LocalPlayer g_player;
