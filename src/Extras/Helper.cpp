//
// Created by p2-erwich on 04/02/2022.
//

#include "Helper.h"

void Helper::SFMLText(sf::Text& text, const std::string& string, sf::Font& font, int char_size, sf::Color color, float x, float y)
{
  text.setFont(font);
  text.setString(string);
  text.setCharacterSize(char_size);
  text.setFillColor(color);
  text.setPosition(x - text.getGlobalBounds().width / 2, y);
}