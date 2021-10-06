/*
* An SFML application using a vector list to store point data - Darryl Charles
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
* Set up your own VS2019 project https://www.youtube.com/watch?v=lFzpkvrscs4
*/
#include <iostream>                                                     // std namespace
#include <SFML/Graphics.hpp>                                            // sf namespace 

int main()
{
#pragma region Previous Example Setup
    sf::RenderWindow window(sf::VideoMode(800, 800), "Plot Points!");   // render a Window
    sf::Vector2u winSize = window.getSize();
    sf::CircleShape shape(4.f);                                         // create a circle object called shape
    shape.setFillColor(sf::Color::Green);                               // colour shape Green
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    std::vector<sf::Vector2f> points;                                   // vector list of points  
#pragma endregion

    int numDataPts = 20;
    srand(time(NULL));                                                  // initialize random seed

    for (int i = 0; i < numDataPts; ++i)
    {
        points.push_back(sf::Vector2f(rand() % winSize.x, rand() % winSize.y));   // choose random values inside the Window scope
    }                                                                             // rand() gives an integer value between 0 and RAND_MAX (at least 32767)

    int count = 0;
    int countTarget = 100;

    while (window.isOpen())                                             // This is the Windows application loop - infinite loop until closed
    {
#pragma region Check for Exit
        sf::Event event;                                                // Windows is event driven - this code closes the Window properly
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
#pragma endregion

        if (count < countTarget) count++;        
        else count = 0;

        window.clear();                                                 // Clear render buffer
        for (int i = 0; i < numDataPts; ++i)
        {
            sf::Vector2f point = points[i];                             // Get points one at a time
            shape.setPosition(point);
            window.draw(shape);
            if (count == countTarget) points[i].y += rand() % 2 + 1;    // Only draw each point every countTarget times with a random speed
        }
                                                                         
        window.display();                                               // Display the graphics from the buffer to the display
    }

    return 0;
}