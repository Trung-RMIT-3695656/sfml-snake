#include "Game.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

Game::Game() : m_context(std::make_shared<Context>()){
    m_context->m_window->create(sf::VideoMode(500, 500), "SFML works perfectly!", sf::Style::Close);
    // TODO:
    // Add first state to m_state here
}

Game::~Game() {

}

void Game::Run(){
    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Red);

    while (m_context->m_window->isOpen())
    {
        sf::Event event;
        while (m_context->m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_context->m_window->close();
        }

        m_context->m_window->clear();
        m_context->m_window->draw(shape);
        m_context->m_window->display();
    }
}