
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Vector2.h"

#define random(min, max) rand() % (max + 1 - min) + min // Function I use to generate random numbers

#ifndef SPACEINVADERS_GAMEOBJECT_H
#define SPACEINVADERS_GAMEOBJECT_H

class GameObject
{
 public:
  GameObject(sf::RenderWindow &game_window);
  ~GameObject();
  sf::Sprite *getSprite();
  Vector2 getVector();
  void setVector(float x, float y);
  bool getVisible();
  void setVisible(bool visibility);
  void wallCollision();
  bool objectCollision(GameObject& collider);

  virtual bool init();
  virtual void update(float dt) = 0;
  void render();

 protected:
  sf::RenderWindow &window;
  sf::Texture *texture;
  sf::Sprite *sprite;
  Vector2 *vector;
  float speed;
  bool visible;
};


#endif // SPACEINVADERS_GAMEOBJECT_H
