#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "graphPoints.h"

graphPoints::graphPoints() {};
graphPoints::graphPoints(sf::CircleShape _shape) {};

void graphPoints::loadPoints(std::string _fileName) {
    std::ifstream dataStream;
    std::string line;

    dataStream.open("HeartRate.csv");

    if (dataStream.is_open())
    {
        char next = dataStream.peek();
        while (next != EOF)
        {
            std::getline(dataStream, line);
            std::stringstream lineStream(line);
            std::string character;
            std::vector<std::string> parsedRow;
            while (std::getline(lineStream, character, ','))
            {
                parsedRow.push_back(character);
                std::cout << std::stoi(character) << " ";
            }
            std::cout << std::endl;
            cords.push_back(parsedRow);

            next = dataStream.peek();
        }

    }

    dataStream.close();

    for (int i = 0; i < cords.size(); ++i)
    {
        addPoint(sf::Color(255, 0, 0), 1, sf::Vector2u(1, 1), sf::Vector2f(0, 0));
        for (int j = 0; j < cords[j].size(); ++j)
        {
            if (j == 0) points[i].setPosition(sf::Vector2f(float(stoi(cords[i][j])), 0));
            if (j == 1) points[i].setPosition(sf::Vector2f(points[i].getPosition().x + gap*i, float(stoi(cords[i][j]))));

        }
    }
    
};
void graphPoints::addPoint(sf::Color clr, int radius, sf::Vector2u origin, sf::Vector2f position) {
    sf::CircleShape pt; pt.setFillColor(clr); pt.setRadius(radius); pt.setOrigin(radius, radius); pt.setPosition(position);
    points.push_back(pt);
};
void graphPoints::setPointColor(int index, sf::Color _color) {};
void graphPoints::clearPointList() {};
void graphPoints::drawPoints(sf::RenderWindow &_win) {
    for (int i = 0; i < points.size(); ++i)
    {
        _win.draw(points[i]);
    }
};