#include <SFML/Graphics.hpp>
#include <iostream>
#include <random> // Required for modern random number tools

typedef struct ColorRgb
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
} ColorRgb;

ColorRgb generateRandomColor();
void invertMvSpeed(float &mvSpeed);

int main()
{
  const uint16_t wWidth = 1280;
  const uint16_t wHeight = 720;

  sf::RenderWindow window(sf::VideoMode({wWidth, wHeight}), "SFML works!");
  window.setFramerateLimit(60);

  uint8_t r = 0;
  uint8_t g = 255;
  uint8_t b = 255;

  sf::CircleShape circle(100.f);

  circle.setFillColor(sf::Color(r, g, b));
  circle.setPosition({300.f, 300.f});

  float xSpeed = 2.f;
  float ySpeed = 2.f;

  sf::Font myFont;

  if (!myFont.openFromFile("../assets/fonts/Jacquard12-Regular.ttf"))
  {
    std::cerr << "Could not load font!\n";
    exit(-1);
  }

  sf::Text text(myFont);
  text.setString("Hello world");
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::White);

  text.setPosition({16.f, wHeight - (float)text.getCharacterSize() - 16});

  while (window.isOpen())
  {
    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    window.clear();
    window.draw(circle);
    window.draw(text);
    window.display();
    circle.setPosition({(float)circle.getPosition().x - xSpeed,
                        (float)circle.getPosition().y - ySpeed});

    const sf::FloatRect bounds = circle.getGlobalBounds();

    const bool hitHorizontalWall = (xSpeed > 0 && bounds.position.x <= 0) ||
                                   (xSpeed < 0 && bounds.position.x + bounds.size.x >= 1280.0f);

    const bool hitVerticalWall = (ySpeed > 0 && bounds.position.y <= 0) ||
                                 (ySpeed < 0 && bounds.position.y + bounds.size.y >= 720.0f);

    if (hitHorizontalWall)
    {
      invertMvSpeed(xSpeed);
      ColorRgb newColor = generateRandomColor();
      circle.setFillColor(sf::Color(newColor.r, newColor.g, newColor.b));
    }

    if (hitVerticalWall)
    {
      invertMvSpeed(ySpeed);
      ColorRgb newColor = generateRandomColor();
      circle.setFillColor(sf::Color(newColor.r, newColor.g, newColor.b));
    }
  }
}

void invertMvSpeed(float &mvSpeed)
{
  mvSpeed *= -1.f;
}

ColorRgb generateRandomColor()
{
  ColorRgb newColor;
  std::random_device rd;

  // 2. Initialize the Mersenne Twister engine with the seed
  std::mt19937 gen(rd());

  // 3. Define the range [inclusive, inclusive]
  std::uniform_int_distribution<int> distrib(0, 255);

  int random_num = distrib(gen);
  newColor.r = random_num;

  random_num = distrib(gen);
  newColor.g = random_num;

  random_num = distrib(gen);
  newColor.b = random_num;

  return newColor;
}