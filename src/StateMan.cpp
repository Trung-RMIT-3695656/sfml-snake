#include "StateManager.hpp"

GameEngine::StateManager::StateManager() : m_add(false), m_replace(false), m_remove(false) {

}

GameEngine::StateManager::~StateManager() {

}

// this will manage the state of the game
void GameEngine::StateManager::Add(std::unique_ptr<State> toAdd, bool replace = false){
    m_add = true;
    m_newState = std::move(toAdd);

    m_replace = replace;
};
void GameEngine::StateManager::PopCurrent(){
    m_remove = true;
};
void GameEngine::StateManager::ProcessStateChange(){
    if (m_remove && (!m_stateStack.empty()))
    {
        m_stateStack.pop();

        if (!m_stateStack.empty())
        {
            m_stateStack.top()->StartGame();
        }

        m_remove = false;
        
    }
    if (m_add)
    {
        if (m_replace && (!m_stateStack.empty()))
        {
            m_stateStack.pop();
            m_replace = false;
        }
        if (m_stateStack.empty())
        {
            m_stateStack.top()->PauseGame();
        }

        m_stateStack.push(std::move(m_newState));
        m_add = false;
        
    }
    
    
};
std::unique_ptr<GameEngine::State> & GameEngine::StateManager::GetCurrent(){
    return m_stateStack.top();
};