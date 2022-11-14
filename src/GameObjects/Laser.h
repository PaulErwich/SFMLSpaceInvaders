//
// Created by MLG Erwich on 18/02/2022.
//

#include "GameObject.h"

#ifndef SPACEINVADERSSFML_LASER_H
#define SPACEINVADERSSFML_LASER_H

class Laser : public GameObject
{
 public:
  Laser(sf::RenderWindow &game_window);
  ~Laser() = default;
  bool init(sf::Texture &laser_texture, float x);

  void resetPos();
  void update(float dt) override;

 private:
};

#endif // SPACEINVADERSSFML_LASER_H
