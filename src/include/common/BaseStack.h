/* BaseStack.h */

#ifndef BASE_STACK_H
#define BASE_STACK_H

#include <stdint.h>
#include <Global.h>
#include <Piece.h>
#include <Mode.h>
#include <common/BasePlayer.h>
#include <LineClearParticles.h>

#define FILLED_LINES_NB 4

class BaseStack {
    protected:
        int m_active_particles;

        int8_t m_filled_lines[FILLED_LINES_NB];
        int8_t m_outline[MAX_WIDTH * MAX_HEIGHT];

        LineClearParticles m_part0, m_part1;
        LineClearParticles m_part2, m_part3;

    public:
        int m_pos_x, m_pos_y;
        int m_height, m_width;
        int8_t m_stack[MAX_WIDTH * MAX_HEIGHT];

        BaseStack();
        void init(int pos_x, int pos_y, int width, int height);
        void startGame(Mode *mode);

        int8_t getGhostY(Piece *piece);

        bool checkMove(Piece *piece, int x, int y);

        bool checkLeftRotation(Piece *piece);
        bool checkLeftKickRotation(Piece *piece, int x_offset, int y_offset);

        bool checkRightRotation(Piece *piece);
        bool checkRightKickRotation(Piece *piece, int x_offset, int y_offset);

        void shiftLine(int8_t line);
        void shiftLines();
        void checkLines(BasePlayer *player);

        void updateOutline(int8_t line);
        
        void removeGreyBlocks(Piece *piece);
};

#endif
