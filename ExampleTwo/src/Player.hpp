#pragma once

#include <SFML/Graphics.hpp>

class Player
{
    private:
        const float START_SPEED = 200;
        const float START_HEALTH = 100;

        sf::Vector2f m_position;

        sf::Vector2f m_resolution;

        sf::Sprite m_sprite;

        sf::Texture m_texture;

        //Size of the arena
        sf::IntRect m_arena;

        int m_tileSize;

        //Maybe change this input stuff
        bool m_isUpPressed;
        bool m_isDownPressed;
        bool m_isLeftPressed;
        bool m_isRightPressed;

        int m_health;

        int m_maxHealth;

        sf::Time m_lastHit;

        float m_speed;

    public:
        Player();
        void Spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);

        void ResetPlayerStats();

        bool Hit(sf::Time timeHit);

        sf::Time GetHitLastTime();
        sf::FloatRect GetPosition();
        float GetRotation();
        sf::Vector2f GetCenter();
        sf::Sprite GetSprite();

        void StopRight();
        void StopLeft();
        void StopUp();
        void StopDown();

        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();

        void Update(float elapsedTime, sf::Vector2i mousePos);

        void UpgradeSpeed();
        void UpgradeHealth();

        void IncreaseHealth(int amount);
        int GetHealth();

        void StopMoving();
};