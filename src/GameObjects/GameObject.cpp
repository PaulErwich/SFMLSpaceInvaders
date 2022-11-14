#include "GameObject.h"
GameObject::GameObject(sf::RenderWindow& game_window) : window(game_window)
{
  texture = new sf::Texture();
  sprite = new sf::Sprite();
  vector = new Vector2(0, 0);
  speed = 300;
  visible = true;
}

GameObject::~GameObject()
{
  delete texture;
  delete sprite;
  delete vector;
}

sf::Sprite *GameObject::getSprite()
{
  return sprite;
}

Vector2 GameObject::getVector()
{
  return *vector;
}

void GameObject::setVector(float x, float y)
{
  vector->x = x;
  vector->y = y;
}

bool GameObject::getVisible() { return visible; }
void GameObject::setVisible(bool visibility) { visible = visibility; }

void GameObject::wallCollision()
{
  if (sprite->getPosition().x < 0)
  {
    sprite->setPosition(0, sprite->getPosition().y);
  }
  else if (sprite->getPosition().x + sprite->getGlobalBounds().width > window.getSize().x)
  {
    sprite->setPosition(window.getSize().x - sprite->getGlobalBounds().width, sprite->getPosition().y);
  }
}

bool GameObject::objectCollision(GameObject& collider)
{
  if (sprite->getPosition().x < collider.sprite->getPosition().x + collider.sprite->getGlobalBounds().width &&
      sprite->getPosition().x + sprite->getGlobalBounds().width > collider.sprite->getPosition().x &&
      sprite->getPosition().y < collider.sprite->getPosition().y + collider.sprite->getGlobalBounds().height &&
      sprite->getPosition().y + sprite->getGlobalBounds().height > collider.sprite->getPosition().y)
  {
    std::cout << "Collision\n";
    return true;
  }
  return false;
}

bool GameObject::init()
{
  return true;
}

void GameObject::render()
{
  window.draw(*sprite);
}
