//
// Created by MLG Erwich on 18/02/2022.
//

#include "GameObject.h"

#ifndef SPACEINVADERSSFML_PLAYER_H
#define SPACEINVADERSSFML_PLAYER_H

class Player : public GameObject
{
 public:
  Player(sf::RenderWindow &game_window);
  ~Player() = default;
  bool init() override;
  void reset();

  void input(sf::Event event);
  void update(float dt) override;

 private:
};

#endif // SPACEINVADERSSFML_PLAYER_H
