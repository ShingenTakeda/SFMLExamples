#include <math.h>

#include "Player.hpp"

//Make a sfml view for the resolution and make a better input system

Player::Player()
{
    m_speed = START_SPEED;
    m_health = START_HEALTH;
    m_maxHealth = START_HEALTH;

    m_texture.loadFromFile("graphics/player.png");
    m_sprite.setTexture(m_texture);

    m_sprite.setOrigin(25, 25);
}

void Player::Spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize)
{
    m_position.x = arena.width / 2;
    m_position.y = arena.height /2;

    m_arena.left = arena.left;
    m_arena.top = arena.top;
    m_arena.width = arena.width;
    m_arena.height = arena.height;
}

sf::Time Player::GetHitLastTime()
{
    return m_lastHit;
}

bool Player::Hit(sf::Time timeHit)
{
    if(timeHit.asMilliseconds() - m_lastHit.asMilliseconds() < 200)
    {
        m_lastHit = timeHit;
        m_health -= 10;
        return true;
    }
    else
    {
        return false;
    }
}

sf::FloatRect Player::GetPosition()
{
   return m_sprite.getLocalBounds();
}

sf::Sprite Player::GetSprite()
{
    return m_sprite;
}

int Player::GetHealth()
{
    return m_health;
}

float Player::GetRotation()
{
    return m_sprite.getRotation();
}

sf::Vector2f Player::GetCenter()
{
    return m_position;
}

void Player::MoveLeft()
{
	m_isLeftPressed = true;
}

void Player::MoveRight()
{
	m_isRightPressed = true;
}

void Player::MoveUp()
{
	m_isUpPressed = true;
}

void Player::MoveDown()
{
	m_isDownPressed = true;
}

void Player::StopLeft()
{
	m_isLeftPressed = false;
}

void Player::StopRight()
{
	m_isRightPressed = false;
}

void Player::StopUp()
{
	m_isUpPressed = false;
}

void Player::StopDown()
{
	m_isDownPressed = false;
}

void Player::Update(float elapsedTime, sf::Vector2i mousePos)
{
    
	if (m_isUpPressed)
	{
		m_position.y -= m_speed * elapsedTime;
	}

	if (m_isDownPressed)
	{
		m_position.y += m_speed * elapsedTime;
	}

	if (m_isRightPressed)
	{
		m_position.x += m_speed * elapsedTime;
	}

	if (m_isLeftPressed)
	{
		m_position.x -= m_speed * elapsedTime;
	}

	m_sprite.setPosition(m_position);



	// Keep the player in the arena
	if (m_position.x > m_arena.width - m_tileSize)
	{
		m_position.x = m_arena.width - m_tileSize;
	}

	if (m_position.x < m_arena.left + m_tileSize)
	{
		m_position.x = m_arena.left + m_tileSize;
	}

	if (m_position.y > m_arena.height - m_tileSize)
	{
		m_position.y = m_arena.height - m_tileSize;
	}

	if (m_position.y < m_arena.top + m_tileSize)
	{
		m_position.y = m_arena.top + m_tileSize;
	}

	// Calculate the angle the player is facing
	float angle = (atan2(mousePos.y - m_resolution.y / 2,
		mousePos.x - m_resolution.x / 2)
		* 180) / 3.141;

	m_sprite.setRotation(angle);
}