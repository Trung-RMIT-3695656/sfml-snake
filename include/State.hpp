#pragma once
#include <SFML/System/Time.hpp>

namespace GameEngine
{
    class State
    {
    public:
        State(){};                                  // constructor
        virtual ~State();                           // destructor

        virtual void Init() = 0;                    // initiate the game function
        virtual void KeyHandle() = 0;               // handle the key input of the player
        virtual void Update(sf::Time deltaTime) = 0;// update the game by deltaTime
        virtual void Draw() = 0;                    // Draw the shape of the map, player, food...

        virtual void PauseGame(){};                 // Pause the game
        virtual void StartGame(){};                 // Resume the game
    };
    
} // namespace GameEngine
