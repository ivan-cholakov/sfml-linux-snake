#include "Game.h"

Game::Game() : m_window("Window", sf::Vector2u(800, 600))
{
  m_characterTeture.loadFromFile("../assets/character.png");
  m_character.setTexture(m_characterTeture);
  m_increment = sf::Vector2i(400, 400);
}

Game::~Game() {}

void Game::Update()
{
  m_window.Update();
  MoveSprite();
}

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }

void Game::MoveSprite()
{
  sf::Vector2u l_windSize = m_window.GetWindowSize();
  sf::Vector2u l_textSize = m_characterTeture.getSize();

  if ((m_character.getPosition().x > l_windSize.x - l_textSize.x && m_increment.x > 0) || (m_character.getPosition().x < 0 && m_increment.x < 0))
  {
    m_increment.x = -m_increment.x;
  }

  if ((m_character.getPosition().y > l_windSize.y - l_textSize.y && m_increment.y > 0) || (m_character.getPosition().y < 0 && m_increment.y < 0))
  {
    m_increment.y = -m_increment.y;
  }

  float fElapsed = m_elapsed.asSeconds();

  m_character.setPosition(m_character.getPosition().x + (m_increment.x * fElapsed), m_character.getPosition().y + (m_increment.y * fElapsed));
}

void Game::Render()
{
  m_window.BeginDraw();
  m_window.Draw(m_character);
  m_window.EndDraw();
}

Window *Game::GetWindow() { return &m_window; }