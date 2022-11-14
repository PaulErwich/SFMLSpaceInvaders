#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));

  game_menu = new GameMenu(STATE::GAME_MENU, window, font);
  game_play = new GamePlay(STATE::GAME_PLAY, window, font);
  game_over = new GameOver(STATE::GAME_OVER, window, font);
  current_state = game_menu;
}

Game::~Game()
{
  delete game_menu;
  delete game_play;
  delete game_over;
  delete current_state;
}

bool Game::init()
{
  if (!font.loadFromFile("Data/Fonts/Space_Mono/SpaceMono-Regular.ttf"))
  {
    std::cout << "Font didn't load!\n";
    return false;
  }

  if (game_menu->init() && game_play->init() && game_over->init())
  {
    return true;
  }

  return false;
}

void Game::input(sf::Event event)
{
  current_state->input(event);
}

void Game::update(float dt)
{
  STATE new_state = current_state->update(dt);

  if (new_state == current_state->getStateId())
  {

  }
  else
  {
    switch(new_state)
    {
      case STATE::GAME_EXIT:
        window.close();
        break;
      case STATE::GAME_MENU:
        std::cout << "GameMenu\n";
        game_menu->reset();
        game_menu->setTransition(STATE::GAME_MENU);
        current_state = game_menu;
        break;
      case STATE::GAME_PLAY:
        std::cout << "GamePlay\n";
        game_play->setShipMovement(game_menu->getMoveType());
        game_play->reset();
        current_state = game_play;
        break;
      case STATE::GAME_OVER:
        std::cout << "GameOver\n";
        game_over->setTransition(false);
        game_over->setScore(game_play->getScore());
        if (game_play->gameOver())
        {
          game_over->setTitle("YOU WIN!");
        }
        else
        {
          game_over->setTitle("YOU LOSE!");
        }
        current_state = game_over;
        break;
      case STATE::GAME_UNKNOWN:
        std::cout << "Unknown game state, error. Closing window\n";
        window.close();
        break;
      default:
        std::cout << "Error! Closing window\n";
        window.close();
        break;
    }
  }
}

void Game::render()
{
  current_state->render();
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{

}


