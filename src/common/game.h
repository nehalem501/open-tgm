/* game.h */

#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "timer.h"
#include "labels.h"
#include "digits.h"


namespace GameState {
    enum {
        READY_GO = 0,
        INGAME,
        GAME_OVER,
        FINISHED
    };
}


#ifdef TARGET_SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Game : public sf::Drawable {
#else
class Game {
#endif
    public:
        void initGraphics();

        void updateGameLogic();
        void updateGraphics();
        
        void startPlayer1();
        bool hasPlayer1Finished();
        
    #ifdef MULTIPLAYER
        void startPlayer2();
        bool hasPlayer2Finished();
        void startDoubles();
    #endif
        
        Timer timer1;
        Labels labels1;
        Digits level_display1;
        Digits level_target_display1;
        
    #ifdef MULTIPLAYER
        Timer timer2; 
        Labels labels2;
        Digits level_display2;
        Digits level_target_display2;
    #endif

    private:
        int8_t m_player1_state, m_player2_state;
        
    #ifdef TARGET_SFML
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(sf::Vector2u screenSize);
    private:
    #endif
    #ifdef TARGET_PSP
    public:
        void draw();
    private:
    #endif
    #ifdef TARGET_GBA
    public:
        void draw();
    private:
    #endif
    #ifdef TARGET_DUMMY
    public:
        void draw();
    private:
    #endif
};
#endif
