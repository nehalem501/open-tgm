/* TextImpl.h - GPU */

#ifndef TEXT_GPU_H
#define TEXT_GPU_H

#include <TargetTypes.h>
#include <Position.h>
#include <Typeface.h>

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
        //Typeface m_typeface;
};

#endif
