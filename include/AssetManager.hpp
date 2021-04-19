#pragma once

#include <map>
#include <memory>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace GameEngine
{
class AssetManager {
    private: 
        std::map<int, std::unique_ptr<sf::Texture>> m_textures;
        std::map<int, std::unique_ptr<sf::Font>> m_fonts;

    public:
        AssetManager();
        ~AssetManager();

        void AddTexture(){};
};
} // namespace GameEngine


