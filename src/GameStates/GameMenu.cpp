//
// Created by MLG Erwich on 18/02/2022.
//

#include "GameMenu.h"
GameMenu::GameMenu(
  STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font) :
  GameStateBase(state_id, game_window, game_font)
{
  transition = STATE::GAME_MENU;
  menu_select = true;
  play_menu = false;
}

GameMenu::~GameMenu()
{
}

bool GameMenu::init()
{
  Helper::SFMLText(title, "SPACE INVADERS", *font, 40, cDefault, window.getSize().x / 2, 100);
  Helper::SFMLText(play, "PLAY", *font, 40, cSelected, window.getSize().x / 4, window.getSize().y / 2);
  Helper::SFMLText(exit, "EXIT", *font, 40, cDefault, window.getSize().x / 4 + window.getSize().x / 2, window.getSize().y / 2);

  Helper::SFMLText(normal, "NORMAL", *font, 40, cDefault, window.getSize().x / 4, window.getSize().y / 2 - 200);
  Helper::SFMLText(gravity, "GRAVITY", *font, 40, cDefault, window.getSize().x / 4 + window.getSize().x / 2, window.getSize().y / 2 - 200);
  Helper::SFMLText(quadratic, "QUADRATIC", *font, 40, cDefault, window.getSize().x / 4, window.getSize().y / 2 + 200);
  Helper::SFMLText(sine, "SINE", *font, 40, cDefault, window.getSize().x / 4 + window.getSize().x / 2, window.getSize().y / 2 + 200);

  return true;
}

bool GameMenu::collisionCheck(sf::Vector2i click, sf::Text text)
{
  if (click.x > text.getPosition().x && click.x < text.getPosition().x + text.getGlobalBounds().width
      && click.y > text.getPosition().y && click.y < text.getPosition().y + text.getGlobalBounds().height)
  {
    {
      std::cout << "Inside box\n";
      return true;
    }
  }
  else
    return false;
}

void GameMenu::reset()
{
  play_menu = false;
}


movement GameMenu::getMoveType() { return move_type; }

void GameMenu::setTransition(STATE state) { transition = state; }

void GameMenu::input(sf::Event event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
    {
      menu_select = !menu_select;
      if (menu_select)
      {
        play.setFillColor(cSelected);
        exit.setFillColor(cDefault);
      }
      else
      {
        play.setFillColor(cDefault);
        exit.setFillColor(cSelected);
      }
    }

    if (event.key.code == sf::Keyboard::Enter)
    {
      if (menu_select)
      {
        // transition = STATE::GAME_PLAY;
        play_menu = true;
      }
      else
      {
        transition = STATE::GAME_EXIT;
      }
    }
  }

  if (event.type == sf::Event::MouseButtonPressed && play_menu)
  {
    sf::Vector2i click = sf::Mouse::getPosition(window);

    if (collisionCheck(click, normal))
    {
      move_type = movement::normal;
      transition = STATE::GAME_PLAY;
    }
    else if (collisionCheck(click, gravity))
    {
      move_type = movement::gravity;
      transition = STATE::GAME_PLAY;
    }
    else if (collisionCheck(click, quadratic))
    {
      move_type = movement::quadratic;
      transition = STATE::GAME_PLAY;
    }
    else if (collisionCheck(click, sine))
    {
      move_type = movement::sine;
      transition = STATE::GAME_PLAY;
    }

  }
}

STATE GameMenu::update(float dt)
{
  return transition;
}

void GameMenu::render()
{
  if (play_menu)
  {
    window.draw(normal);
    window.draw(gravity);
    window.draw(quadratic);
    window.draw(sine);
  }
  else
  {
    window.draw(title);
    window.draw(play);
    window.draw(exit);
  }

}
