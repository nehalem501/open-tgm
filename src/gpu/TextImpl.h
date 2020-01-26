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
        TextImpl(Text& text) : m_text(text) { };

        void update_position();
        void update_text();
        void update_color();
        void render() const;

    private:
        Text& m_text;
        //Typeface m_typeface;
};

#endif
