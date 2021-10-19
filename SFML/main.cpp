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
        
        sf::RectangleShape line; sf::RectangleShape line2;
        line.setFillColor(sf::Color(0,0,0)); line.setSize(sf::Vector2f(1000, 2)); line.setPosition(50, winSize.y - 50); line.setRotation(0);
        line2.setFillColor(sf::Color(0,0,0)); line2.setSize(sf::Vector2f(700, 2));  line2.setPosition(50, winSize.y - 50); line2.setRotation(-90);

        window.clear(sf::Color(128,128,128));                                 // Clear graphics buffer

        window.draw(line); 
        window.draw(line2);
        graphPts.drawPoints(window);                                    // Call draw function in my class

        window.display();                                               // Display the graphics from the buffer to the display
    }

    return 0;
}