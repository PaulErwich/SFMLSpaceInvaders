cmake_minimum_required(VERSION 3.14)
project(SpaceInvadersSFML)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h src/Vector2.h src/Vector2.cpp src/GameObjects/GameObject.h src/GameObjects/GameObject.cpp src/GameStates/GameStateBase.cpp src/GameStates/GameStateBase.h src/GameStates/GameMenu.cpp src/GameStates/GameMenu.h src/GameStates/GamePlay.cpp src/GameStates/GamePlay.h src/GameStates/GameOver.cpp src/GameStates/GameOver.h src/Extras/Helper.cpp src/Extras/Helper.h src/GameObjects/Player.cpp src/GameObjects/Player.h src/GameObjects/AlienShip.cpp src/GameObjects/AlienShip.h src/GameObjects/Laser.cpp src/GameObjects/Laser.h src/Extras/UI.cpp src/Extras/UI.h)
add_executable(SpaceInvadersSFML ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries (SpaceInvadersSFML sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)