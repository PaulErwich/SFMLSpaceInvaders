//
// Created by MLG Erwich on 18/02/2022.
//

#include "GameOver.h"
GameOver::GameOver(
  STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font) :
  GameStateBase(state_id, game_window, game_font)
{
  transition = false;
}

bool GameOver::init()
{
  Helper::SFMLText(title, "DEFAULT", *font, 40, sf::Color::White, window.getSize().x / 2, window.getSize().y / 2 - 300);
  Helper::SFMLText(final_score, "FINAL SCORE: ", *font, 40, sf::Color::White, window.getSize().x / 2, window.getSize().y / 2);
  Helper::SFMLText(return_to_menu, "PRESS ENTER TO RETURN TO MENU", *font, 40, sf::Color::White, window.getSize().x / 2, window.getSize().y / 2 + 300);

  return true;
}

void GameOver::setTitle(const std::string& string) { title.setString(string); }

void GameOver::setScore(int score) { final_score.setString("FINAL SCORE: " + std::to_string(score)); }

void GameOver::setTransition(bool _transition) { transition = _transition; }

void GameOver::input(sf::Event event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      transition = true;
    }
  }
}

STATE GameOver::update(float dt)
{
  if (transition)
  {
    return STATE::GAME_MENU;
  }

  return game_state_id;
}

void GameOver::render()
{
  window.draw(title);
  window.draw(final_score);
  window.draw(return_to_menu);
}
