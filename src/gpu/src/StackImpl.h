/* StackImpl.h - GPU */

#ifndef STACK_GPU_H
#define STACK_GPU_H

#include <Global.h>
#include "Texture.h"
#include "Tilemap.h"

/* Forward declarations to avoid dependency hell */
class Stack;

class StackImpl {
    public:
        StackImpl(const Stack& stack);

        void update_field();
        void update_outline();

        inline void render() const {
            m_field_tilemap.render();
            m_outline_tilemap.render();
        }

        #ifdef RESIZABLE
        void resize(const Position& position) {
            m_field_tilemap.resize(position);
            m_outline_tilemap.resize(position);
        }
        #endif

    private:
        const Stack& m_stack;
        Tilemap<MAX_WIDTH * MAX_HEIGHT> m_field_tilemap;
        Tilemap<MAX_WIDTH * MAX_HEIGHT> m_outline_tilemap;
};

#endif
