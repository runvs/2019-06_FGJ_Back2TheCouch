#ifndef GAME_STATE_MENU_HPP_INCLUDEGUARD
#define GAME_STATE_MENU_HPP_INCLUDEGUARD

#include "JamTemplate/GameState.hpp"

namespace JamTemplate {
class SmartText;
class SmartShape;
class SmartSprite;
}

class StateMenu : public JamTemplate::GameState {
public:
    StateMenu();

private:
    std::shared_ptr<JamTemplate::SmartSprite> m_background;

    mutable std::shared_ptr<JamTemplate::SmartText> m_text_Title;
    mutable std::shared_ptr<JamTemplate::SmartSprite> m_text_start;
    mutable std::shared_ptr<JamTemplate::SmartSprite> m_text_start2;

    std::shared_ptr<JamTemplate::SmartShape> m_overlay;

    std::shared_ptr<JamTemplate::SmartSprite> m_title;

    bool m_starting { false };

    void doInternalUpdate(float const /*elapsed*/) override;
    void doCreate() override;
    void doInternalDraw() const override;
};

#endif
