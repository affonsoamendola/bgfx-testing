#pragma once

#include "interface_module.hpp"

namespace dui
{
    void push_module(const InterfaceModule& t_module);

    void init();
    void draw();
    void quit();
}