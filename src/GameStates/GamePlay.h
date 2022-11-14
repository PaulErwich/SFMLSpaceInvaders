//
// Created by MLG Erwich on 18/02/2022.
//

#include "GameStateBase.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/AlienShip.h"
#include "../GameObjects/Laser.h"
#include "../Extras/UI.h"

#ifndef SPACEINVADERSSFML_GAMEPLAY_H
#define SPACEINVADERSSFML_GAMEPLAY_H

class GamePlay : public GameStateBase
{
 public:
  GamePlay(STATE state_id, sf::RenderWindow &game_window, sf::Font &game_font);
  ~GamePlay();
  bool init() override;
  int getScore();
  bool gameOver();
  void reset();
  void setShipMovement(movement type);

  void input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  sf::Texture alien_textures[4];
  sf::Texture laser;

  Player* player;

  static const int GRID_WIDTH = 10;
  static const int GRID_HEIGHT = 3;
  AlienShip *alien_array[GRID_WIDTH];

  static const int MAX_LASERS = 10;
  int active_lasers;
  sf::Clock fire_timer;
  Laser *lasers[MAX_LASERS];

  UI *ui;
};

#endif // SPACEINVADERSSFML_GAMEPLAY_H
