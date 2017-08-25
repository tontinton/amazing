#pragma once
#include <windows.h>
#include <string>

#include "valve_sdk/Misc/Enums.hpp"
#include "valve_sdk/Misc/vfunc.hpp"

#include "valve_sdk/Math/VMatrix.hpp"
#include "valve_sdk/Math/QAngle.hpp"
#include "valve_sdk/Math/Vector.hpp"
#include "valve_sdk/Misc/Studio.hpp"

#include "valve_sdk/Interfaces/IAppSystem.hpp"
#include "valve_sdk/Interfaces/IBaseClientDll.hpp"
#include "valve_sdk/Interfaces/IClientEntity.hpp"
#include "valve_sdk/Interfaces/IClientEntityList.hpp"
#include "valve_sdk/Interfaces/IClientMode.hpp"
#include "valve_sdk/Interfaces/IConVar.hpp"
#include "valve_sdk/Interfaces/ICvar.hpp"
#include "valve_sdk/Interfaces/IEngineTrace.hpp"
#include "valve_sdk/Interfaces/IVEngineClient.hpp"
#include "valve_sdk/Interfaces/IVDebugOverlay.hpp"
#include "valve_sdk/Interfaces/ISurface.hpp"
#include "valve_sdk/Interfaces/CInput.hpp"
#include "valve_sdk/Interfaces/IVModelInfoClient.hpp"
#include "valve_sdk/Interfaces/IVModelRender.hpp"
#include "valve_sdk/Interfaces/IRenderView.hpp"
#include "valve_sdk/Interfaces/IGameEventmanager.hpp"
#include "valve_sdk/Interfaces/IMaterialSystem.hpp"
#include "valve_sdk/Interfaces/IMoveHelper.hpp"
#include "valve_sdk/Interfaces/IMDLCache.hpp"
#include "valve_sdk/Interfaces/IPrediction.hpp"
#include "valve_sdk/Interfaces/IPanel.hpp"
#include "valve_sdk/Interfaces/IEngineSound.hpp"
#include "valve_sdk/Interfaces/IViewRender.hpp"
#include "valve_sdk/Interfaces/CClientState.hpp"
#include "valve_sdk/Interfaces/IPhysics.hpp"

#include "valve_sdk/Misc/Convar.hpp"
#include "valve_sdk/Misc/CUserCmd.hpp"
#include "valve_sdk/Misc/glow_outline_effect.hpp"

class C_LocalPlayer
{
    friend bool operator==(const C_LocalPlayer& lhs, void* rhs);
public:
    C_LocalPlayer() : m_local(nullptr) {}

    operator bool() const { return *m_local != nullptr; }
    operator C_BasePlayer*() const { return *m_local; }

    C_BasePlayer* operator->() { return *m_local; }

private:
    C_BasePlayer** m_local;
};

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
    static C_LocalPlayer g_player;
    static unsigned char* patternScan(void* module, const char* signature);

private:
    template <typename T>
    static T* create(HMODULE moduleHandle, const std::string& interfaceName);
};
