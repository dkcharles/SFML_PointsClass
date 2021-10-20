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

void graphPoints::loadPoints(std::string _fileName, sf::RenderWindow& _win) {
    std::ifstream dataStream;
    std::string line;

#pragma region CSV File Reading
    dataStream.open("HeartRate.csv");                                   // open file to a data stream for reading
    if (dataStream.is_open())                                           // check if file is open - e.g. it could be in the wrong folder
    {
        char next = dataStream.peek();                                  // take a peek at the next data character - i.e. only look, don't read
        while (next != EOF)                                             // if the next character is not the end of file then continue to read data
        {
            std::getline(dataStream, line);                             // get a line of text from the file
            std::stringstream lineStream(line);                         // create a line stream                      
            std::string character;
            std::vector<std::string> parsedRow;                         // a 2d vector - many rows of point co-ordinates                        
            while (std::getline(lineStream, character, ','))            // we  read a row at a time and parse it to get rid of the comma
            {
                parsedRow.push_back(character);                         // push a character at a time into the vector row (x and y co-ordinates)
                std::cout << std::stoi(character) << " ";               // print out to check
            }
            std::cout << std::endl;
            cords.push_back(parsedRow);                                 // push the parsed row into the vector list of co-ordinates

            next = dataStream.peek();                                   // take a sneek peek at the next character in case its the end of file character
        }

    }
    dataStream.close();
#pragma endregion

#pragma region Create Graph points 
    // add an SFML circle object (as a graph point) to our points vector list
    // set positions of graph points from point co-ordinates loaded in from CSV file

    for (int i = 0; i < cords.size(); ++i) // for number of rows (300 in this example)
    {
        addPoint(sf::Color(0, 0, 255), 1, sf::Vector2u(1, 1), sf::Vector2f(0, 0)); 
        for (int j = 0; j < cords[j].size(); ++j) // for number of columns (2)
        {
            // set (x, y) position for each graph point (SFML circle object). 
            // Note that " _win.getSize().y - (50 + " is used to draw the points from bottom of the screen up (starting at my x-axis line at y = 50)
            if (j == 0) points[i].setPosition(sf::Vector2f(float(stoi(cords[i][j])), 0)); // x coordinate 
            if (j == 1) points[i].setPosition(sf::Vector2f(points[i].getPosition().x + 50 + pointsGap * i, _win.getSize().y - (50 + float(stoi(cords[i][j]))))); // adjusted y coordinate
        }
    }
#pragma endregion
  
};
// Add SFML Circle object to a vector list (points)
void graphPoints::addPoint(sf::Color clr, int radius, sf::Vector2u origin, sf::Vector2f position) 
{
    sf::CircleShape pt; pt.setFillColor(clr); pt.setRadius(radius); pt.setOrigin(radius, radius); pt.setPosition(sf::Vector2f(position));
    
    points.push_back(pt);
};
void graphPoints::setPointColor(int index, sf::Color _color) {/* not implemented yet*/ };
void graphPoints::clearPointList() {/* not implemented yet*/ };

// Go through the points (vector list) and draw the points (circles) on the render surface (using a reference to window - _win)
void graphPoints::drawPoints(sf::RenderWindow &_win) {
    for (int i = 0; i < points.size(); ++i)
    {
        _win.draw(points[i]);
    }
};