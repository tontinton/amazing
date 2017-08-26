#include "InterfaceHooker.h"
#include "ConsoleLogger.h"
#include "MemoryProtectGuard.h"
#include "AmazingException.h"


constexpr size_t WRONG_JUMP_ADDRESS = 0;


InterfaceHooker::InterfaceHooker(size_t* interfaceAddressPointer,
                                 size_t functionIndex,
                                 void* newFunction)
    : m_detour(reinterpret_cast<size_t*>(*interfaceAddressPointer) + functionIndex),
      m_newFunctionAddress(reinterpret_cast<size_t>(newFunction)),
      m_oldFunctionAddress(WRONG_JUMP_ADDRESS),
      m_logger(ConsoleLogger::getInstance()) {}


void InterfaceHooker::hook()
{
    // Check if a hook was made or not
    if (WRONG_JUMP_ADDRESS != m_oldFunctionAddress) {
        m_logger.warning("Tried to hook a hooked function");
        return;
    }

    // Save the detour jump address
    m_oldFunctionAddress = *m_detour;

	// Chagne protection of the memory to enable writing
	MemoryProtectGuard memoryProtectGuard(m_detour, sizeof(m_detour), PAGE_READWRITE);

    // Change the detour jump address to the new function
    *m_detour = m_newFunctionAddress;

    m_logger.success(std::string("Changed detour of address ") + std::to_string(reinterpret_cast<size_t>(m_detour))
        + ", From " + std::to_string(m_oldFunctionAddress) + " To " + std::to_string(*m_detour));
}

void InterfaceHooker::unhook()
{
    // Check if a hook was made or not
    if (WRONG_JUMP_ADDRESS == m_oldFunctionAddress) {
        m_logger.warning("Tried to unhook a non hooked function");
        return;
    }

    // For logging we check the address currently in the table
    auto newFunctionAddress = *m_detour;

    // Chagne protection of the memory to enable writing
    MemoryProtectGuard memoryProtectGuard(m_detour, sizeof(m_detour), PAGE_READWRITE);

    // Change the detour jump address to the old function
    *m_detour = m_oldFunctionAddress;

    m_oldFunctionAddress = WRONG_JUMP_ADDRESS;

    m_logger.success(std::string("Changed detour of address ") + std::to_string(reinterpret_cast<size_t>(m_detour))
        + ", From " + std::to_string(newFunctionAddress) + " To " + std::to_string(*m_detour));
}

void* InterfaceHooker::getOriginalFunction()
{
    if (WRONG_JUMP_ADDRESS == m_oldFunctionAddress) {
        throw AmazingException("Function is not hooked, so you cannot get the original function");
    }
	return reinterpret_cast<void*>(m_oldFunctionAddress);
}
