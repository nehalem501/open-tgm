/* GameImpl.cpp - Dummy */

#include <Global.h>
#include <Stack.h>
#include <Player.h>
#include "GameImpl.h"

void GameImpl::draw() const {
    player1.draw();
    stack1.draw();

    timer1.draw();
    labels1.draw();
}
