//
// Created by MLG Erwich on 18/02/2022.
//

#include "Player.h"
Player::Player(sf::RenderWindow& game_window) : GameObject(game_window)
{

}

bool Player::init()
{
  if (!texture->loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip1_red.png"))
  {
    std::cout << "Player texture didn't load!\n";
    return false;
  }
  sprite->setTexture(*texture);

  sprite->setPosition(window.getSize().x / 2 - sprite->getGlobalBounds().width / 2, window.getSize().y - 100);

  return true;
}

void Player::reset()
{
  sprite->setPosition(window.getSize().x / 2 - sprite->getGlobalBounds().width / 2, window.getSize().y - 100);
  vector->x = 0;
}

void Player::input(sf::Event event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::A)
    {
      vector->x = -1;
    }
    else if (event.key.code == sf::Keyboard::D)
    {
      vector->x = 1;
    }
  }

  if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
    {
      vector->x = 0;
    }
  }
}

void Player::update(float dt)
{
  sprite->move(vector->x * speed * dt, 0);

  wallCollision();
}
