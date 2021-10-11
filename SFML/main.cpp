/*
* An SFML application - Darryl Charles
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
* SFML Shapes Tutorials https://www.sfml-dev.org/tutorials/2.5/graphics-shape.php
* SGML Graphics tutorial https://gamefromscratch.com/sfml-c-tutorial-basic-graphics/
*/
#include <iostream>                                                     // std namespace
#include <SFML/Graphics.hpp>                                            // sf namespace 
#include <SFML/OpenGL.hpp>
#include "graphPoints.h"

int main()
{
#pragma region Window Creation
    sf::RenderWindow window(sf::VideoMode(800, 800), "Plot Points!", sf::Style::Default, sf::ContextSettings(24));   // render a Window
    window.setVerticalSyncEnabled(true);
    sf::Vector2u winSize = window.getSize();
#pragma endregion
    graphPoints graphsPts;

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
        sf::CircleShape pt; pt.setFillColor(sf::Color(255, 0, 0)); pt.setRadius(4); pt.setOrigin(4, 4); pt.setPosition(winSize.x/2, winSize.y/2);
        graphsPts.addPoint(pt);

        window.clear();                                                 // Clear graphics buffer
        graphsPts.drawPoints(window);
        window.display();                                               // Display the graphics from the buffer to the display
    }

    return 0;
}