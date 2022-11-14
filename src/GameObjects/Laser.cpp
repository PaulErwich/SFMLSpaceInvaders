//
// Created by MLG Erwich on 18/02/2022.
//

#include "Laser.h"
Laser::Laser(sf::RenderWindow &game_window) : GameObject(game_window)
{
  vector->y = -1;
  visible = false;
}

bool Laser::init(sf::Texture &laser_texture, float x)
{
  texture = &laser_texture;
  sprite->setTexture(*texture);
  sprite->setPosition(x - sprite->getGlobalBounds().width / 2, window.getSize().y - 100);

  return true;
}

void Laser::resetPos()
{
  sprite->setPosition( window.getSize().x / 2, window.getSize().y - 100);
  visible = false;
}

void Laser::update(float dt)
{
  sprite->move(vector->x, vector->y * speed * dt);
}
