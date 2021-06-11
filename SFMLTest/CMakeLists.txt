cmake_minimum_required(VERSION 3.19)
project(SFMLTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFMLTest
        Engine/main.cpp
        Engine/Input/InputController.h
        Engine/Input/InputController.cpp
        Engine/Input/Input.h
        Engine/Input/Input.cpp
        Engine/Universe.h
        Engine/Universe.cpp
        Engine/Vec2D.h
        Engine/Vec2D.cpp
        Engine/TimeUtil.h
        Engine/TimeUtil.cpp
        Engine/DebugUtil.h
        Engine/DebugUtil.cpp
        Engine/HUD.h
        Engine/HUD.cpp
        Engine/GameConstants.h
        Engine/GameConstants.cpp
        Entities/GameObject.h
        Entities/GameObject.cpp
        Entities/FallingObjects/FallingObject.h
        Entities/FallingObjects/FallingObject.cpp
        Entities/Player.h
        Entities/Player.cpp
        Entities/Projectiles/Projectile.h
        Entities/Projectiles/Projectile.cpp
        Entities/FallingObjects/Asteroids/Asteroid.h
        Entities/FallingObjects/Asteroids/Asteroid.cpp
        Entities/FallingObjects/Collectibles/Star.h
        Entities/FallingObjects/Collectibles/Star.cpp
        Entities/FallingObjects/Collectibles/RechargeStar.h
        Entities/FallingObjects/Collectibles/RechargeStar.cpp
        Entities/FallingObjects/Collectibles/ChainingStar.h
        Entities/FallingObjects/Collectibles/ChainingStar.cpp
        Entities/FallingObjects/Particles/Particle.h
        Entities/FallingObjects/Particles/Particle.cpp
        )

include_directories(headers /usr/include D:/Data/CppLibs/SFML-2.5.1x64/include)

set(SFML_ROOT D:/Data/CppLibs/SFML-2.5.1x64)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFMLTest ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()


#set(CMAKE_PREFIX_PATH "D:/Data/CppLibs/SFML-2.5.1x64" )
#set(SFML_DIR  "D:/Data/CppLibs/SFML-2.5.1x64" )
#find_package(SFML COMPONENTS graphics window system)
#
#add_executable(SFMLTest main.cpp InputController.cpp)
#target_link_libraries (SFMLTest sfml-graphics sfml-window sfml-system)