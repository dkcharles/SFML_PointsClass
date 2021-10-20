/*
* An SFML application - Darryl Charles
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
* SFML Shapes Tutorials https://www.sfml-dev.org/tutorials/2.5/graphics-shape.php
* SGML Graphics tutorial https://gamefromscratch.com/sfml-c-tutorial-basic-graphics/
*/
#include <iostream>                                                     // std namespace
#include <SFML/Graphics.hpp>                                            // sf namespace 
#include "graphPoints.h"

int main()
{
#pragma region Window Creation
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Plot Points!", sf::Style::Default, sf::ContextSettings(24));   // render a Window
    window.setVerticalSyncEnabled(true);
    sf::Vector2u winSize = window.getSize();
#pragma endregion
    graphPoints graphPts;                                               // create an instance of my point plotting class
    graphPts.loadPoints("HeartRate.csv", window);
    while (window.isOpen())                                             // This is the Windows application loop - infinite loop until closed
    {
#pragma region Check for Exit
        sf::Event event;                                                // Windows is event driven - so check for events
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

#pragma endregion
        
        // Set up x and y axis lines - this could be modified to look better. Further lines can be drawn in the same way. 
        // Lines can also be draw more efficiently with vertices. https://en.sfml-dev.org/forums/index.php?topic=11121.0
        // A function for this code would be better.
        sf::RectangleShape horizLine; sf::RectangleShape vertLine;
        horizLine.setFillColor(sf::Color(0,0,0)); horizLine.setSize(sf::Vector2f(1000, 2)); horizLine.setPosition(50, winSize.y - 50); horizLine.setRotation(0);
        vertLine.setFillColor(sf::Color(0,0,0)); vertLine.setSize(sf::Vector2f(700, 2));  vertLine.setPosition(50, winSize.y - 50); vertLine.setRotation(-90); // anticlockwise

        window.clear(sf::Color(168, 168, 168));                         // Clear graphics buffer

        window.draw(horizLine);                                         // Draw x and y axis lines 
        window.draw(vertLine);
        graphPts.drawPoints(window);                                    // Call draw function in my class

        window.display();                                               // Display the graphics from the buffer to the display
    }

    return 0;
}