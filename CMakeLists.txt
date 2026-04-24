cmake_minimum_required(VERSION 4.1)
project(Pokemon_Battle_Simulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pokemon_Battle_Simulator
        Pokemon.cpp
        Pokemon.h
        main.cpp
        FirePokemon.cpp
        FirePokemon.h
        WaterPokemon.cpp
        WaterPokemon.h
        GrassPokemon.cpp
        GrassPokemon.h
        ElectricPokemon.cpp
        ElectricPokemon.h
        IcePokemon.cpp
        IcePokemon.h
        RockPokemon.cpp
        RockPokemon.h
        FlyingPokemon.cpp
        FlyingPokemon.h
        FireFlyingPokemon.cpp
        FireFlyingPokemon.h
        Move.cpp
        Move.h
        PhysicalMove.cpp
        PhysicalMove.h
        StatusMove.cpp
        StatusMove.h
        AttackMove.cpp
        AttackMove.h
        SpAttackMove.cpp
        SpAttackMove.h
        Trainer.cpp
        Trainer.h
        TypeChart.cpp
        TypeChart.h
        utils.cpp
        utils.h
)
