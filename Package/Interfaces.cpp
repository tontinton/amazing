#include "Interfaces.h"
#include <windows.h>
#include "AmazingException.h"
#include "WinApiException.h"
#include <vector>


constexpr char* CREATE_INTERFACE = "CreateInterface";

constexpr char* CLIENT = "client_panorama.dll";
constexpr char* ENGINE = "engine.dll";
constexpr char* DATA_CACHE = "datacache.dll";
constexpr char* V_STD_LIB = "vstdlib.dll";


IBaseClientDLL* Interfaces::g_baseClient = nullptr;
IClientEntityList* Interfaces::g_entityList = nullptr;
ICvar* Interfaces::g_convar = nullptr;
IVEngineClient* Interfaces::g_engineClient = nullptr;
CInput* Interfaces::g_input = nullptr;
CGlobalVarsBase* Interfaces::g_globalVars = nullptr;
IClientMode* Interfaces::g_clientMode = nullptr;
CGlowObjectManager* Interfaces::g_glowObjManager = nullptr;
IVModelInfoClient* Interfaces::g_mdlInfo = nullptr;
IEngineTrace* Interfaces::g_engineTrace = nullptr;

C_LocalPlayer g_player;


void Interfaces::init()
{
	auto client = safeGetModuleHandle(CLIENT);
	auto engine = safeGetModuleHandle(ENGINE);
	auto vstdlib = safeGetModuleHandle(V_STD_LIB);

	g_baseClient = create<IBaseClientDLL>(client, "VClient018");
	g_entityList = create<IClientEntityList>(client, "VClientEntityList003");

	g_convar = create<ICvar>(vstdlib, "VEngineCvar007");

	g_engineClient = create<IVEngineClient>(engine, "VEngineClient014");
	g_mdlInfo = create<IVModelInfoClient>(engine, "VModelInfoClient004");
	g_engineTrace = create<IEngineTrace>(engine, "EngineTraceClient004");

	g_input = *reinterpret_cast<CInput**>(patternScan(client, "B9 ? ? ? ? 8B 40 38 FF D0 84 C0 0F 85") + 1);
	g_globalVars = **reinterpret_cast<CGlobalVarsBase***>(patternScan(client, "A1 ? ? ? ? 5E 8B 40 10") + 1);

	g_clientMode = *reinterpret_cast<IClientMode**>(patternScan(client, "A1 ? ? ? ? 8B 80 ? ? ? ? 5D") + 1);

	g_glowObjManager = *reinterpret_cast<CGlowObjectManager**>(patternScan(client, "0F 11 05 ? ? ? ? 83 C8 01") + 3);

	g_player = *reinterpret_cast<C_LocalPlayer*>(patternScan(client, "8B 0D ? ? ? ? 83 FF FF 74 07") + 2);
}

HMODULE Interfaces::safeGetModuleHandle(const std::string& moduleName)
{
	auto module = GetModuleHandle(moduleName.c_str());
	if (!module) {
		throw WinApiException("Getting module handle of an interface failed");
	}
	return module;
}

template <typename T>
T* Interfaces::create(HMODULE moduleHandle, const std::string& interfaceName)
{
	auto createInterfaceAddress = GetProcAddress(moduleHandle, CREATE_INTERFACE);
	if (!createInterfaceAddress) {
		throw WinApiException("Getting the address to the create interface function failed");
	}

	auto createInterfaceFunction = reinterpret_cast<CreateInterfaceFn>(createInterfaceAddress);

	auto interfaceInstance = reinterpret_cast<T*>(createInterfaceFunction(interfaceName.c_str(), nullptr));
	if (!interfaceInstance) {
		throw AmazingException("The create interface function failed, so no instance could be made of the requested interface: " + interfaceName);
	}

	return interfaceInstance;
}

unsigned char* Interfaces::patternScan(void* module, const char* signature)
{
	static auto pattern_to_byte = [](const char* pattern) {
		auto bytes = std::vector<int>{};
		auto start = const_cast<char*>(pattern);
		auto end = const_cast<char*>(pattern) + strlen(pattern);

		for (auto current = start; current < end; ++current) {
			if (*current == '?') {
				++current;
				if (*current == '?') {
					++current;
				}
				bytes.push_back(-1);
			}
			else {
				bytes.push_back(strtoul(current, &current, 16));
			}
		}
		return bytes;
	};

	auto dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(module);
	auto ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<unsigned char*>(module) + dosHeader->e_lfanew);

	auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
	auto patternBytes = pattern_to_byte(signature);
	auto scanBytes = reinterpret_cast<unsigned char*>(module);

	auto size = patternBytes.size();
	auto data = patternBytes.data();

	for (size_t i = 0; i < sizeOfImage - size; ++i) {
		auto found = true;
		for (size_t j = 0; j < size; ++j) {
			if (scanBytes[i + j] != data[j] && data[j] != -1) {
				found = false;
				break;
			}
		}
		if (found) {
			return &scanBytes[i];
		}
	}
	return nullptr;
}
