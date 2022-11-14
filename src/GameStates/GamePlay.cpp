//
// Created by MLG Erwich on 18/02/2022.
//

#include "GamePlay.h"
GamePlay::GamePlay(
  STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font) :
  GameStateBase(state_id, game_window, game_font)
{
  player = new Player(window);

  for (int i = 0; i < GRID_WIDTH; i++)
  {
    alien_array[i] = new AlienShip(window);
  }


  active_lasers = 0;
  for (int i = 0; i < MAX_LASERS; i++)
  {
    lasers[i] = new Laser(window);
  }

  ui = new UI(window, *font);
}

GamePlay::~GamePlay()
{
  delete player;

  for (int i = 0; i < GRID_WIDTH; i ++)
  {
    delete alien_array[i];
  }

  for (int i = 0; i < MAX_LASERS; i++)
  {
    delete lasers[i];
  }

  delete ui;
}

bool GamePlay::init()
{
  for (int i = 0; i < 4; i += 4)
  {
    if (!alien_textures[i].loadFromFile("Data/Images/SpaceShooterRedux/PNG/ufoBlue.png"))
    {
      std::cout << "Alien blue didn't load!\n";
      return false;
    }
    if (!alien_textures[i + 1].loadFromFile("Data/Images/SpaceShooterRedux/PNG/ufoGreen.png"))
    {
      std::cout << "Alien green didn't load!\n";
      return false;
    }
    if (!alien_textures[i + 2].loadFromFile("Data/Images/SpaceShooterRedux/PNG/ufoRed.png"))
    {
      std::cout << "Alien red didn't load!\n";
      return false;
    }
    if (!alien_textures[i + 3].loadFromFile("Data/Images/SpaceShooterRedux/PNG/ufoYellow.png"))
    {
      std::cout << "Alien yellow didn't load!\n";
      return false;
    }
  }

  bool alien_init = true;

  for (int i = 0; i < GRID_WIDTH; i++)
  {
    int texture = random(0, 3);
    if (alien_array[i]->init(alien_textures[texture], 40 + i * 100, 70)) alien_init = true;
    else alien_init = false;
  }

  if (!laser.loadFromFile("Data/Images/SpaceShooterRedux/PNG/Lasers/laserBlue01.png"))
  {
    std::cout << "Laser didn't load\n";
    return false;
  }

  bool laser_init = true;

  for (int i = 0; i < MAX_LASERS; i++)
  {
    if (lasers[i]->init(laser, window.getSize().x / 2)) laser_init = true;
    else laser_init = false;
  }

  if (!ui->init())
  {
    return false;
  }

  if (!player->init() && !alien_init && !laser_init)
  {
    return false;
  }

  return true;
}

int GamePlay::getScore() { return ui->getScore(); }

bool GamePlay::gameOver()
{
  int count = 0;
  for (int i = 0; i < GRID_WIDTH; i++)
  {
    if (!alien_array[i]->getVisible())
    {
      count++;
    }
  }
  if (count == GRID_WIDTH) return true;

  return false;
}

void GamePlay::reset()
{
  player->reset();
  for (int i = 0; i < GRID_WIDTH; i += 2)
  {
    alien_array[i]->reset((i * 50) + window.getSize().x / 2, 70, false);
    alien_array[i + 1]->reset((-i * 50 - 91) + window.getSize().x / 2, 70, true);
  }
  ui->reset();

  for (int i = 0; i < MAX_LASERS; i++)
  {
    lasers[i]->resetPos();
  }
  active_lasers = 0;
}

void GamePlay::setShipMovement(movement type)
{
  for (int i = 0; i < GRID_WIDTH; i++)
  {
    alien_array[i]->setMovement(type);
  }
}

void GamePlay::input(sf::Event event)
{
  player->input(event);

  if (event.type == sf::Event::KeyPressed)
  {
    if (
      event.key.code == sf::Keyboard::Space &&
      fire_timer.getElapsedTime().asSeconds() >= 0.25)
    {
      if (!lasers[active_lasers]->getVisible())
      {
        lasers[active_lasers]->getSprite()->setPosition(
          player->getSprite()->getPosition().x +
            player->getSprite()->getGlobalBounds().width / 2,
          lasers[active_lasers]->getSprite()->getPosition().y);
        lasers[active_lasers]->setVisible(true);
        fire_timer.restart();
        if (active_lasers == 9)
        {
          active_lasers = 0;
        }
        else
        {
          active_lasers++;
        }
      }
    }
  }
}

STATE GamePlay::update(float dt)
{
  player->update(dt);

  for (int i = 0; i < GRID_WIDTH; i++)
  {
    alien_array[i]->update(dt);
    if (alien_array[i]->objectCollision(*player))
    {
      return STATE::GAME_OVER;
    }
  }

  for (int i = 0; i < MAX_LASERS; i++)
  {
    if (lasers[i]->getVisible())
    {
      lasers[i]->update(dt);

      if (lasers[i]->getSprite()->getPosition().y + lasers[i]->getSprite()->getGlobalBounds().height < 0)
      {
        lasers[i]->resetPos();
      }

      for (int j = 0; j < GRID_WIDTH; j++)
      {
        if (alien_array[j]->getVisible())
        {
          if (lasers[i]->objectCollision(*alien_array[j]))
          {
            lasers[i]->resetPos();
            alien_array[j]->setVisible(false);
            ui->increaseScore(alien_array[j]->getScore());
          }
        }
      }
    }
  }

  ui->update(dt);

  if (gameOver()) return STATE::GAME_OVER;

  return game_state_id;
}

void GamePlay::render()
{
  for (int i = 0; i < GRID_WIDTH; i++)
  {
    if (alien_array[i]->getVisible())
    {
      alien_array[i]->render();
    }
  }

  for (int i = 0; i < MAX_LASERS; i++)
  {
    if (lasers[i]->getVisible())
    {
      lasers[i]->render();
    }
  }

  player->render();
  ui->render();
}
