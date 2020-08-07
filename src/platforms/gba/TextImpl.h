/* TextImpl.h - GBA */

#ifndef TEXT_GBA_H
#define TEXT_GBA_H

#include <TargetTypes.h>
#include <Position.h>

/* Forward declarations to avoid dependency hell */
class Text;

class TextImpl {
    public:
        TextImpl(const Text& text) : m_text(text) { };

        void update_position();
        void update_text();
        void update_color();

        void layout(const Position &position);
        void render() const;

    private:
        const Text& m_text;
};

#endif
