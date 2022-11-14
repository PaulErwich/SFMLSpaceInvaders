//
// Created by MLG Erwich on 18/02/2022.
//

#include "UI.h"
UI::UI(sf::RenderWindow& game_window, sf::Font& ui_font) : window(game_window)
{
  font = &ui_font;
  current_lives = MAX_LIVES;
  score = 0;
}

UI::~UI()
{
  delete font;
}

bool UI::init()
{
  if (!texture.loadFromFile("Data/Images/SpaceShooterRedux/PNG/UI/playerLife1_red.png"))
  {
    std::cout << "Life texture didn't load\n";
    return false;
  }
  for (int i = 0; i < MAX_LIVES; i++)
  {
    std::cout << "setup\n";
    lives[i].setTexture(texture);
    lives[i].scale(2, 2);
    lives[i].setPosition(10 + i * 70, 10);
  }

  Helper::SFMLText(text_score, "Score: " + std::to_string(score), *font, 40, sf::Color::White, window.getSize().x - 200, 10);
  return true;
}

int UI::getScore() const { return score; }
void UI::increaseScore(int value) { score += value; }

void UI::decreaseLives() { current_lives--;}

void UI::reset()
{
  score = 0;
  current_lives = MAX_LIVES;
}

void UI::update(float dt)
{
  text_score.setString("Score: " + std::to_string(score));
}

void UI::render()
{
  for (int i = 0; i < current_lives; i++)
  {
    window.draw(lives[i]);
  }

  window.draw(text_score);
}
