/* Stack.h */

#ifndef STACK_H
#define STACK_H

#include <string.h>
#include <TargetTypes.h>
#include <Coordinates.h>
#include <Position.h>
#include <Field.h>
#include <LineClearParticles.h>
#include <StackImpl.h>

/* Forward declarations to avoid dependency hell */
class Mode;
class Piece;
class Player;

#define FILLED_LINES_NB 4 // TODO 8 for BIG mode

class Stack {
    public:
        Stack(Position &parent);

        void draw() const;

        #ifdef RESIZABLE
        void resize() {
            for (unsigned int i = 0; i < FILLED_LINES_NB; i++) {
                //m_particles[i].resize();
            }

            m_implementation.resize(m_parent);
        }
        #endif

        void init(Position &parent, const uint8_t width, const uint8_t height);

        void start_game(const Mode mode);

        bool check_bravo();

        void shift_line(unsigned int line);
        void shift_lines();
        bool check_lines(Player& player);
        void remove_line(int line);

        void update_outline(size_t line);

        void remove_grey_blocks(const Piece& piece);

        inline const Field& field() const { return m_field; };
        inline const Position& position() const { return m_parent; };

    private:
        Position& m_parent;

        Field m_field;

        //int m_filled_lines[FILLED_LINES_NB];

        //LineClearParticles m_particles[FILLED_LINES_NB];

        StackImpl m_implementation;
};

#endif // STACK_H
