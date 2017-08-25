#pragma once
#include "valve_sdk/interfaces/IPrediction.hpp"

class C_LocalPlayer
{
public:
    C_LocalPlayer() : m_local(nullptr) {}

    explicit operator bool() const
    {
        return *m_local != nullptr;
    }

    explicit operator C_BasePlayer*() const
    {
        return *m_local;
    }

    C_BasePlayer* operator->() const
    {
        return *m_local;
    }

private:
    C_BasePlayer** m_local;
};
