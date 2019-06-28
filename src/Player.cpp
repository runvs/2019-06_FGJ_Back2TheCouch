
#include "Player.hpp"
#include "JamTemplate/Game.hpp"
#include "JamTemplate/MathHelper.hpp"
#include <iostream>

Player::Player()
{
}

void Player::doUpdate(float const elapsed)
{
    std::cout << "I am alive" << std::endl;
    m_sprite->update(elapsed);
}
void Player::doDraw() const
{
    m_sprite->draw(getGame()->getRenderTarget());
}

void Player::doCreate()
{
    m_sprite = std::make_shared<JamTemplate::Animation>();
    m_sprite->add("assets/coin.png", "idle", sf::Vector2u { 16, 16 }, JamTemplate::MathHelper::vectorBetween(0U, 11U), 0.15f);
    m_sprite->play("idle");
}