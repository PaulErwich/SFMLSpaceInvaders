//
// Created by MLG Erwich on 18/02/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef SPACEINVADERSSFML_GAMESTATEBASE_H
#define SPACEINVADERSSFML_GAMESTATEBASE_H

enum class STATE {GAME_UNKNOWN = -1, GAME_EXIT, GAME_MENU, GAME_PLAY, GAME_OVER};

class GameStateBase
{
 public:
  GameStateBase(STATE state_id, sf::RenderWindow &game_window, sf::Font &game_font);
  ~GameStateBase();
  virtual bool init();
  STATE getStateId();
  virtual void input(sf::Event event);
  virtual STATE update(float dt);
  virtual void render();

 protected:
  STATE game_state_id;
  sf::RenderWindow &window;
  sf::Font* font;
};

#endif // SPACEINVADERSSFML_GAMESTATEBASE_H
