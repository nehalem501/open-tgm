/* TextImpl.h - GPU */

#ifndef TEXT_GPU_H
#define TEXT_GPU_H

#include <TargetTypes.h>
#include <Position.h>
#include <Glyphs.h>

#define TEXT_LEN_MAX 256 // TODO

/* Forward declarations to avoid dependency hell */
class Text;

class TextImpl {
    public:
        TextImpl(const Text& text);

        void update_position();
        void update_text();
        void update_color();

        void render() const;

        #ifdef RESIZABLE
        void resize() {
            // TODO
            update_text();
        }
        #endif

    private:
        const Text& m_text;
        Glyphs<TEXT_LEN_MAX> m_glyphs;
};

#endif
