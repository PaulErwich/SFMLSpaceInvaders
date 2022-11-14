//
// Created by MLG Erwich on 18/02/2022.
//

#include "GameStateBase.h"

#include "../Extras/Helper.h"
#include "../GameObjects/AlienShip.h"

#ifndef SPACEINVADERSSFML_GAMEMENU_H
#define SPACEINVADERSSFML_GAMEMENU_H

class GameMenu : public GameStateBase
{
 public:
  GameMenu(STATE state_id, sf::RenderWindow &game_window, sf::Font &game_font);
  ~GameMenu();
  bool init() override;
  void reset();
  void setTransition(STATE state);
  movement getMoveType();
  void input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  bool collisionCheck(sf::Vector2i click, sf::Text text);

  STATE transition;
  sf::Text title;
  sf::Text play;
  sf::Text exit;

  sf::Text normal;
  sf::Text gravity;
  sf::Text quadratic;
  sf::Text sine;

  movement move_type;

  const sf::Color cDefault = sf::Color::White;
  const sf::Color cSelected = sf::Color::Green;
  bool menu_select;
  bool play_menu;
};

#endif // SPACEINVADERSSFML_GAMEMENU_H
