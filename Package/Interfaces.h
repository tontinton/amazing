#pragma once
#include <string>

#include "valve_sdk/Interfaces/ICvar.hpp"
#include "valve_sdk/interfaces/IBaseClientDll.hpp"

class Interfaces
{
public:
	static void init();

    static IBaseClientDLL*      g_baseClient;
    static ICvar*               g_convar;

private:
	template <typename T>
	static T* create(const std::string& module, const std::string& interfaceName);
};
