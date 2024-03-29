#ifndef GAME_GAMEPROPERTIES_HPP_INCLUDEGUARD
#define GAME_GAMEPROPERTIES_HPP_INCLUDEGUARD

#include <SFML/Graphics.hpp>
#include <string>

class GP {
public:
    GP() = delete;
    static float CellPositionSpacing() { return 32.0f; }
    static float CellPositionOffsetX() { return 10.0f; }
    static float CellPositionOffsetY() { return 10.0f; }
    static float GameBoardInputTimerMax() { return 0.6f; }
    static float GameBoardInputOffsetMax() { return 300; }
    static unsigned int GameBoardMaxParse() { return 20; }

    static unsigned int PlayfieldWidth() { return 828; }
    static unsigned int PlayfieldHeight() { return 600; }
    static unsigned int PixelScalingFactor() { return 3; }

    static sf::Color Player1PrimaryColor() { return sf::Color { 252, 114, 232 }; };
    static sf::Color Player1SecondaryColor() { return sf::Color { 219, 65, 195 }; };
    static sf::Color Player1TertiaryColor() { return sf::Color { 154, 32, 121 }; };
    static sf::Color Player2PrimaryColor() { return sf::Color { 140, 242, 255 }; };
    static sf::Color Player2SecondaryColor() { return sf::Color { 97, 211, 227 }; };
    static sf::Color Player2TertiaryColor() { return sf::Color { 65, 146, 195 }; };

    static sf::Color PaletteBackground() { return sf::Color { 14, 16, 20 }; };
    static sf::Color PaletteFontFront() { return sf::Color { 248, 249, 254 }; };
    static sf::Color PaletteFontShadow(sf::Uint8 a = 255) { return sf::Color { 26, 29, 36, a }; };
    static sf::Color PaletteSelector() { return sf::Color { 221, 228, 236 }; };
    static sf::Color PaletteHighlight() { return sf::Color { 163, 183, 205 }; };

    static sf::Color PaletteFlashGreen() { return sf::Color { 51, 143, 63 }; };
    static sf::Color PaletteFlashRed() { return sf::Color { 143, 33, 33 }; };

    static std::string GameName() { return "grounded"; };

    static std::int32_t PhysicVelocityIterations() { return 8; };
    static std::int32_t PhysicPositionIterations() { return 2; };
    static float PhysicsGravity() { return 1200.0f; };

    static unsigned int SpriteSize() { return 12; };
    static float SpriteLinearDamping() { return 6.0f; };

    static float PlayerMovementAcceleration() { return 67000.0f; };
    static float PlayerFriction() { return 0.01f; };
    static float PlayerDensity() { return 1.0f * 6.0f / 3.5f; };
    static float PlayerMaxSpeedHorizontal() { return 125.0f; };
    static float PlayerMaxSpeedVertical() { return 500.0f; };
    static float PlayerJumpImpulse() { return 86000.0f; };
    static float PlayerVerticalSpeedJumpThreshold() { return 1e-4f; };

    static float TileFriction() { return 0.60f; };
    static float TileDensity() { return 1.0f; };

    static float ShotVelocityStart() { return 220; };
    static float ShotVelocityMax() { return 325; };
    static float ShotTimer() { return 0.33; };
    static float ShotInvincibleTime() { return 0.1f; };
    static float ShotKnockbackHorizontal() { return 90000.0f; };
    static float ShotKnockbackVertical() { return 50000.0f; };
    static float ShotRecoilHorizontal() { return 8000.0f; };
    static float ShotRecoilVertical() { return 10000.0f; };

    static float LavaRiseSpeed() { return 2.3f; };
    static float LavaStartTime() { return 10.0f; };
    static float LavaStopTime() { return 75.0f; };
    static float TotalGameTime() { return 90.0f; };
    static float ReturnToCouchTime() { return 80.0f; };
    static int PointsForHit() { return 1; };
    static int PointsForOtherPlayerDyingInAFire() { return 4; };
    static int PointsForReturningToTheCouch() { return 40; };

    static sf::Vector2f CouchSpawnPosition() { return sf::Vector2f { 114.0f, 132.0f }; };
};

#endif
