//
// Created by MLG Erwich on 18/02/2022.
//

#include "GameStateBase.h"
#include "../Extras/Helper.h"

#ifndef SPACEINVADERSSFML_GAMEOVER_H
#define SPACEINVADERSSFML_GAMEOVER_H

class GameOver : public GameStateBase
{
 public:
  GameOver(STATE state_id, sf::RenderWindow &game_window, sf::Font &game_font);
  ~GameOver() = default;
  bool init() override;
  void setTitle(const std::string& string);
  void setScore(int score);
  void setTransition(bool _transition);

  void input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  sf::Text title;
  sf::Text final_score;
  sf::Text return_to_menu;

  bool transition;
};

#endif // SPACEINVADERSSFML_GAMEOVER_H
