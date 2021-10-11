#pragma once
#include <vector>
#include <SFML/Graphics.hpp>                                            // sf namespace 
class graphPoints
{
private:
	std::vector<sf::CircleShape> points;
public:

	graphPoints();
	graphPoints(sf::CircleShape _shape, sf::Vector2f position);

	void loadPoints(std::string _fileName);
	void addPoint(sf::CircleShape _point);
	void setPointColor(int index, sf::Color _color);
	void clearPointList();
	void drawPoints(sf::RenderWindow &_win);

};

