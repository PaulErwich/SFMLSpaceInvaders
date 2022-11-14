
#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"

#include "GameStates/GameStateBase.h"
#include "GameStates/GameMenu.h"
#include "GameStates/GamePlay.h"
#include "GameStates/GameOver.h"

#include "GameObjects/AlienShip.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void input(sf::Event event);
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

 private:
  sf::RenderWindow& window;
  sf::Font font;

  // State machine variables
  GameMenu* game_menu;
  GamePlay* game_play;
  GameOver* game_over;
  GameStateBase* current_state;

};

#endif // SPACEINVADERS_GAME_H
