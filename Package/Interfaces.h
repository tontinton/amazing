#pragma once
#include <windows.h>
#include <string>

#include "valve_sdk/Interfaces/ICvar.hpp"
#include "valve_sdk/interfaces/IBaseClientDll.hpp"
#include "valve_sdk/interfaces/CInput.hpp"
#include "valve_sdk/interfaces/C_LocalPlayer.hpp"
#include "valve_sdk/interfaces/IClientEntityList.hpp"
#include "valve_sdk/interfaces/IVEngineClient.hpp"
#include "valve_sdk/interfaces/IEngineTrace.hpp"
#include "valve_sdk/interfaces/IVModelInfoClient.hpp"

class Interfaces
{
public:
    static void init();

    static IBaseClientDLL* g_baseClient;
	static IClientEntityList* g_entityList;
    static ICvar* g_convar;
	static IVEngineClient* g_engineClient;
    static IEngineTrace* g_engineTrace;
    static CInput* g_input;
    static CGlobalVarsBase* g_globalVars;
	static IVModelInfoClient* g_mdlInfo;
	static C_LocalPlayer g_player;

	static unsigned char* patternScan(void* module, const char* signature);

private:
    template <typename T>
    static T* create(HMODULE moduleHandle, const std::string& interfaceName);
};
