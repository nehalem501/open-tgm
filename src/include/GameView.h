/* GameView.h */

#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <Enums.h>
#include <Game.h>
class GameView {
    public:
        GameView(const Size& parent_size);

        void draw() const;

        #ifdef RESIZABLE
        void resize(const Size& parent_size) {
            // TODO layout code
            m_player1_position = compute_position(parent_size);
            //print("GameView x: %d, y:%d\n", m_player1_position.x, m_player1_position.y);
            m_player1_game.resize();

            #ifdef MULTIPLAYER
            m_player2_game.resize();
            #endif
        }
        #endif

        void update(SceneState& state);

    private:
        Position m_player1_position;
        Game m_player1_game;

        #ifdef MULTIPLAYER
        Position m_player2_position;
        Game m_player2_game;
        #endif

        inline static Position compute_position(const Size& parent_size) {
            // TODO use parent aspect ratio
            return Position(parent_size.width / 10, parent_size.height / 12);
        }
};

#endif // GAME_VIEW_H
