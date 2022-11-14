//
// Created by p2-erwich on 04/02/2022.
//

#include <SFML/Graphics.hpp>

#ifndef BREAKOUTSFML_HELPER_H
#define BREAKOUTSFML_HELPER_H

class Helper
{
 public:
  static void SFMLText(sf::Text& text, const std::string& string, sf::Font& font,
                       int char_size, sf::Color color, float x, float y);
};

#endif // BREAKOUTSFML_HELPER_H
