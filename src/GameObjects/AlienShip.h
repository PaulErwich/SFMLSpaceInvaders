//
// Created by MLG Erwich on 18/02/2022.
//

#include "GameObject.h"
#include <cmath>

#ifndef SPACEINVADERSSFML_ALIENSHIP_H
#define SPACEINVADERSSFML_ALIENSHIP_H

enum class movement
{
  normal = 1,
  gravity = 2,
  quadratic = 3,
  sine = 4
};

class AlienShip : public GameObject
{
 public:
  AlienShip(sf::RenderWindow &game_window);
  ~AlienShip() = default;
  bool init(sf::Texture &ship_texture, float x, float y);
  int getScore() const;

  void reset(float x, float y, bool side);

  void setMovement(movement type);

  void quadraticMoveShip(float dt);
  void gravityMoveShip(float dt);
  void sineMoveShip(float dt);
  void normalMoveShip(float dt);
  void update(float dt) override;

 private:
  movement move_type;
  float row;
  float movementX;
  float movementY;
  bool moving_down;
  const int SCORE = 10;
  bool left;
};

#endif // SPACEINVADERSSFML_ALIENSHIP_H
