#pragma once

class IHooker
{
public:
    virtual ~IHooker() = default;

    virtual void hook() = 0;
    virtual void unhook() = 0;
};