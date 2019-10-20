/* TextImpl.h - Dummy */

#ifndef TEXT_DUMMY_H
#define TEXT_DUMMY_H

#include <TargetTypes.h>
#include <Position.h>

/* Forward declarations to avoid dependency hell */
class Text;

class TextImpl {
    public:
        TextImpl(Text& text) : m_text(text) { };

        void update_position();
        void update_text();
        void update_color();
        void render() const;

    private:
        Text& m_text;
};

#endif
