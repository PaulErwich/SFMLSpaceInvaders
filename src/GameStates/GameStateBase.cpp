//
// Created by MLG Erwich on 18/02/2022.
//

#include "GameStateBase.h"
GameStateBase::GameStateBase(STATE state_id, sf::RenderWindow& game_window, sf::Font &game_font) : window(game_window)
{
  game_state_id = state_id;
  font = &game_font;
}

GameStateBase::~GameStateBase()
{

}

bool GameStateBase::init()
{
  return true;
}

STATE GameStateBase::getStateId()
{
  return game_state_id;
}

void GameStateBase::input(sf::Event event)
{

}

STATE GameStateBase::update(float dt)
{
  return game_state_id;
}

void GameStateBase::render()
{

}
