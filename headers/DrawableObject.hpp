#include <SFML/Graphics.hpp>

class DrawableObject
{
public:
    int x, y;
    int width, height;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape shape;


    DrawableObject(int, int, int, int);
    void setTexture();
    void setSprite();
    void setShape(sf::Color);
    void draw(sf::RenderWindow &);

};
