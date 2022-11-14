//
// Created by MLG Erwich on 18/02/2022.
//

#include "AlienShip.h"
AlienShip::AlienShip(sf::RenderWindow& game_window) : GameObject(game_window)
{
  vector->x = 20;
  vector->y = 10;
  row = 1.00;
  movementX = 1;
  movementY = 1;
  moving_down = false;
  speed = 20;
  left = false;
  move_type = movement::normal;
}

bool AlienShip::init(sf::Texture &ship_texture, float x, float y)
{
  texture = &ship_texture;
  sprite->setTexture(*texture);

  sprite->setPosition(x, y);
  return false;
}

int AlienShip::getScore() const
{
  return SCORE;
}

void AlienShip::reset(float x, float y, bool side)
{
  sprite->setPosition(x, y);
  visible = true;
  movementX = 1;
  movementY = 1;
  row = 1;
  moving_down = false;
  left = side;
}

void AlienShip::setMovement(movement type)
{
  move_type = type;
}

void AlienShip::quadraticMoveShip(float dt)
{
  vector->x = 0;
  vector->y = 0;
  Vector2 middle(window.getSize().x / 2, window.getSize().y / 2);

  vector->x = (sprite->getPosition().x + sprite->getGlobalBounds().width / 2) - middle.x;
  if (sprite->getPosition().x + sprite->getGlobalBounds().width / 2 < middle.x)
  {
    vector->x = -vector->x;
    vector->x = vector->x / 10;

    vector->y = ((vector->x * vector->x) / 100);
    left = true;
  }
  else
  {
    vector->x = vector->x / 10;

    vector->y = -((vector->x * vector->x) / 100);
    left = false;
  }

  if (vector->x > 0)
  {
    vector->x += 1;
  }
  else
  {
    vector->x -= 1;
  }

  if (sprite->getPosition().x < 0 || sprite->getPosition().x + sprite->getGlobalBounds().width > window.getSize().x)
  {
    movementX = -movementX;
    movementY = -movementY;
  }
  sprite->move((speed * vector->x) * movementX * dt, (speed * vector->y) * movementY * dt);
}

void AlienShip::gravityMoveShip(float dt)
{
  /*
  vector->x = 20;
  vector->y = 3;
  movementY = 1;
  if (sprite->getPosition().x < 0 || sprite->getPosition().x + sprite->getGlobalBounds().width > window.getSize().x)
  {
    movementX = -movementX;
    vector->y += 3;
  }

  sprite->move((speed * vector->x) * movementX * dt, (speed * vector->y) * movementY * dt);*/

  vector->x = 0;
  vector->y = 0;

  vector->x = (sprite->getPosition().x + 1);

  if (movementX < 0)
  {
    vector->x = (sprite->getPosition().x - 1);
  }
  else if (movementX > 0)
  {
    vector->x = (sprite->getPosition().x + 1);
  }

  vector->y = sprite->getPosition().y + 0.5;

  sprite->setPosition(vector->x, vector->y);

  if (sprite->getPosition().x < 0 || sprite->getPosition().x + sprite->getGlobalBounds().width > window.getSize().x)
  {
    movementX = -movementX;
  }
}

void AlienShip::sineMoveShip(float dt)
{
  vector->x = 0;
  vector->y = 0;

  vector->x = (sprite->getPosition().x + 1);

  if (movementX < 0)
  {
    vector->x = (sprite->getPosition().x - 1);
  }
  else if (movementX > 0)
  {
    vector->x = (sprite->getPosition().x + 1);
  }

  vector->y = 16 * sin(vector->x / 8) + (row * 40);

  sprite->setPosition(vector->x, vector->y);

  if (sprite->getPosition().x < 0 || sprite->getPosition().x + sprite->getGlobalBounds().width > window.getSize().x)
  {
    movementX = -movementX;
    row++;
  }
}

void AlienShip::normalMoveShip(float dt)
{
  movementY = 0;
  vector->x = 200;
  vector->y = 100;
  if (sprite->getPosition().x + sprite->getGlobalBounds().width >= window.getSize().x)
  {
    sprite->setPosition(window.getSize().x - sprite->getGlobalBounds().width, sprite->getPosition().y);
    moving_down = true;
    if (sprite->getPosition().y < row * 100 + 70)
    {
      movementY = 1;
      movementX = 0;
    }
    else
    {
      movementY = 0;
      movementX = -1;
    }
    sprite->move(vector->x * movementX * dt,vector->y * movementY * dt);
    return;
  }
  else if (sprite->getPosition().x <= 0)
  {
    sprite->setPosition(0, sprite->getPosition().y);
    moving_down = true;
    if (sprite->getPosition().y < row * 100 + 70)
    {
      movementY = 1;
      movementX = 0;
    }
    else
    {
      movementY = 0;
      movementX = 1;
    }
    sprite->move(vector->x * movementX * dt,vector->y * movementY * dt);
    return;
  }
  if (moving_down)
  {
    row += 1;
    moving_down = false;
  }
  sprite->move(vector->x * movementX * dt,vector->y * movementY * dt);
}

void AlienShip::update(float dt)
{
  if (visible)
  {
    //normalMoveShip(dt);
    //quadraticMoveShip(dt);
    //gravityMoveShip(dt);
    //sineMoveShip(dt);
    //sprite->move((speed + vector->x) * movementX * dt, (speed + vector->y) * movementY * dt);

    switch(move_type)
    {
      case movement::normal:
        normalMoveShip(dt);
        break;
      case movement::gravity:
        gravityMoveShip(dt);
        break;
      case movement::quadratic:
        quadraticMoveShip(dt);
        break;
      case movement::sine:
        sineMoveShip(dt);
        break;
    }
  }
}

