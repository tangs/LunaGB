#pragma once

#include <Luna/Runtime/Result.hpp>

//using namespace Luna;

struct Emulator
{
    ~Emulator() { close(); }
    
    Luna::RV init(const void* cartridge_data, Luna::usize cartridge_data_size);
    void close();
};
