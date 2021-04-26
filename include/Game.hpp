#pragma once

#include <memory>


#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetManager.hpp"
#include "StateManager.hpp"

struct Context
{
    std::unique_ptr<GameEngine::AssetManager> m_assets;
    std::unique_ptr<GameEngine::StateManager> m_states;
    std::unique_ptr<sf::RenderWindow> m_window;

    Context(){
        
    };
};



class Game {
    std::shared_ptr<Context> m_context;
    const sf::Time TIME_PER_SEC = sf::seconds(1.f/60.f);
public:
    Game();
    ~Game();

    void Run();
};