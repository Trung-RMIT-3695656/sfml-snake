// Libraries to use
// CPP libraries
#include <iostream>

// SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

class Player{

};

class Food{

};

// main program
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works perfectly!");
    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}