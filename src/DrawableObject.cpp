#include "../headers/DrawableObject.hpp"

DrawableObject::DrawableObject(int x, int y, int width, int height)
                                : x(x), y(y), width(width), height(height)
{ }

void DrawableObject::setShape(sf::Color color)
{
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(sf::Vector2f(x, y));
    shape.setFillColor(color);
}

void DrawableObject::draw(sf::RenderWindow & window)
{
    window.draw(shape);
}
