#include "graphPoints.h"

graphPoints::graphPoints() {};
graphPoints::graphPoints(sf::CircleShape _shape, sf::Vector2f position) {};

void graphPoints::loadPoints(std::string _fileName) {};
void graphPoints::addPoint(sf::CircleShape _point) {
	points.push_back(_point);
};
void graphPoints::setPointColor(int index, sf::Color _color) {};
void graphPoints::clearPointList() {};
void graphPoints::drawPoints(sf::RenderWindow &_win) {
	_win.draw(points[0]);
};