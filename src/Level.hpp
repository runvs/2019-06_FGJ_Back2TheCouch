#ifndef LEVEL_HPP_INCLUDEGUARD
#define LEVEL_HPP_INCLUDEGUARD

#include "JamTemplate/GameObject.hpp"
#include "JamTemplate/ObjectGroup.hpp"
#include "JamTemplate/SmartSprite.hpp"
#include "Tile.hpp"
// forward declaration
class StateGame;

class Level : public JamTemplate::GameObject {
public:
    Level(StateGame& sg);

    void LoadLevel(std::string const& fileName);

    sf::Vector2f getSpawnPosition(int id) const;
    sf::Vector2f getSpawnPositionAbove(float minHeight) const;

    JamTemplate::ObjectGroup<Tile>::Sptr getTiles() { return m_tiles; };

    JamTemplate::SmartSprite::Sptr m_backgroundImage;

private:
    StateGame& m_gameState;

    JamTemplate::ObjectGroup<Tile>::Sptr m_tiles;
    std::vector<sf::Vector2i> m_spawnPositions;

    void AddTile(int x, int y, TileType::TileType type);

    virtual void
    doUpdate(float const /*elapsed*/);
    virtual void doDraw() const;
    virtual void doCreate();
};

#endif
