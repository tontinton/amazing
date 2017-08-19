#include "Interfaces.h"
#include <windows.h>
#include "AmazingException.h"
#include "WinApiException.h"


constexpr char* CREATE_INTERFACE = "CreateInterface";

constexpr char* CLIENT = "client.dll";
constexpr char* V_STD_LIB = "vstdlib.dll";


IBaseClientDLL*		Interfaces::g_baseClient	= nullptr;
ICvar*				Interfaces::g_convar		= nullptr;


void Interfaces::init()
{
    g_baseClient = create<IBaseClientDLL>(CLIENT, "VClient018");
	g_convar = create<ICvar>(V_STD_LIB, "VEngineCvar007");
}

template <typename T>
T* Interfaces::create(std::string module, std::string interfaceName)
{
	auto moduleHandle = GetModuleHandle(module.c_str());
	if (!moduleHandle) {
		throw WinApiException("Getting module handle of an interface failed with error code: " + std::to_string(GetLastError()));
	}

	auto createInterfaceAddress = GetProcAddress(moduleHandle, CREATE_INTERFACE);
	if (!createInterfaceAddress) {
		throw WinApiException("Getting the address to the create interface function failed with error code: " + std::to_string(GetLastError()));
	}

	auto createInterfaceFunction = reinterpret_cast<CreateInterfaceFn>(createInterfaceAddress);

	auto interfaceInstance = reinterpret_cast<T*>(createInterfaceFunction(interfaceName.c_str(), nullptr));
	if (!interfaceInstance) {
		throw AmazingException("The create interface function failed, so no instance could be made of the requested interface");
	}

	return interfaceInstance;
}
