//
// Created by MLG Erwich on 18/02/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Helper.h"

#ifndef SPACEINVADERSSFML_UI_H
#define SPACEINVADERSSFML_UI_H

class UI
{
 public:
  UI(sf::RenderWindow &game_window, sf::Font &ui_font);
  ~UI();
  bool init();
  int getScore() const;
  void increaseScore(int value);
  void decreaseLives();
  void reset();

  void update(float dt);
  void render();

 private:
  sf::RenderWindow &window;
  sf::Font *font;
  sf::Text text_score;
  int score;
  static const int MAX_LIVES = 3;
  int current_lives;
  sf::Texture texture;
  sf::Sprite lives[MAX_LIVES];
};

#endif // SPACEINVADERSSFML_UI_H
