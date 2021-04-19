#include "AssetManager.hpp"

GameEngine::AssetManager::AssetManager()
{
}

GameEngine::AssetManager::~AssetManager()
{
}

void GameEngine::AssetManager::AddTexture(int id, const std::string &filePath, bool isRepeated = false){
    auto texture = std::make_unique<sf::Texture>();

    if (texture->loadFromFile(filePath))
    {
        texture->setRepeated(isRepeated);
        m_textures[id] = std::move(texture);
    }
    
};
void GameEngine::AssetManager::AddFont(int id, const std::string &filePath){
    auto font = std::make_unique<sf::Font>();

    if (font->loadFromFile(filePath))
    {
        m_fonts[id] = std::move(font);
    }
};

const sf::Texture &GameEngine::AssetManager::getTexture(int id) const{
    return *(m_textures.at(id).get());
};
const sf::Font &GameEngine::AssetManager::getFont(int id) const{
    return *(m_fonts.at(id).get());
};