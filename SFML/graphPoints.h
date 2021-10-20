#pragma once
#include <vector>
#include <SFML/Graphics.hpp>																	// sf namespace 
class graphPoints
{
private:
	std::vector<sf::CircleShape> points;
	std::vector<std::vector<std::string> > cords;
	int pointsGap = 2;																			// Horizontal gap between plotted points
public:

	graphPoints();
	graphPoints(sf::CircleShape _shape);

	void loadPoints(std::string _fileName, sf::RenderWindow& _win);
	void addPoint(sf::Color clr, int radius, sf::Vector2u origin, sf::Vector2f position);
	void setPointColor(int index, sf::Color _color);
	void clearPointList();
	void drawPoints(sf::RenderWindow &_win);

};

