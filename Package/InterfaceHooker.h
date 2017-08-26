#pragma once
#include "IHooker.h"
#include "ILogger.h"

class InterfaceHooker : public IHooker
{
public:
    InterfaceHooker(size_t* interfaceAddressPointer,
                    size_t functionIndex,
                    void* newFunction);

    void hook() override;
    void unhook() override;
	void* getOriginalFunction() override;
private:
    size_t* m_detour;
    size_t m_newFunctionAddress;

    // This will save the detour as it was before changing the memory for the hook (So we can unhook later)
    size_t m_oldFunctionAddress;

    ILogger& m_logger;
};
