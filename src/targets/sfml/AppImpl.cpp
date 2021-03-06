/* AppImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Global.h>
#include <Background.h>
#include <MainMenu.h>
#include <App.h>

sf::Texture tileset_tex;
sf::Texture outline_tex;
sf::Texture frame_tex;
sf::Texture digits_tex;
sf::Texture labels_tex;
sf::Texture text_tex;
sf::Texture grades_tex;
sf::Texture timer_tex;
sf::Texture particle_tex;

sf::Time timePerFrame;

sf::Vector2u screen_size(320, 240);

int tile_size = screen_size.y / TILE_RATIO;

void app() {
    // Resize graphics to window size
    menu.resize();
    bool fullscreen = false; // TODO load config

    // Used to remember window size when going fullscreen
    sf::Vector2u window_size(screen_size.x, screen_size.y);

    // Create window
    sf::RenderWindow window;
    window.create(sf::VideoMode(screen_size.x, screen_size.y), "Open TGM");
    window.clear();
    window.display();

    // Init frame timer
    timePerFrame = sf::microseconds(16667);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // Used to run the game frame by frame
    #ifdef DEBUG
    bool frameByFrame = false;
    bool doFrame = false;
    #endif

    // main loop for target SFML
    while (window.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        if (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            sf::Event event;

            while(window.pollEvent(event)) {
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }

                    #ifdef DEBUG
                    if (event.key.code == sf::Keyboard::P) {
                        frameByFrame = !frameByFrame;
                    }

                    if (event.key.code == sf::Keyboard::N) {
                        doFrame = true;
                    }
                    #endif

                    if (event.key.code == sf::Keyboard::F11) {
                        if (fullscreen) {
                            window.create(sf::VideoMode(window_size.x, window_size.y), "Open TGM", sf::Style::Default);
                            window.setView(sf::View(sf::FloatRect(0.f, 0.f, window_size.x, window_size.y)));
                            window.clear();
                            window.display();

                            screen_size = window_size;
                            fullscreen = false;

                            menu.resize();
                        } else {
                            window_size = window.getSize();
                            window.create(sf::VideoMode::getDesktopMode(), "Open TGM", sf::Style::Fullscreen);
                            screen_size =  window.getSize();
                            window.setView(sf::View(sf::FloatRect(0.f, 0.f, screen_size.x, screen_size.y)));
                            window.clear();
                            window.display();

                            fullscreen = true;
                            menu.resize();
                        }
                    }
                }

                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::Resized) {
                    sf::Vector2u newWindowSize = window.getSize();
                    if (newWindowSize != screen_size) {
                        screen_size = newWindowSize;
                        window.setView(sf::View(sf::FloatRect(0.f, 0.f, newWindowSize.x, newWindowSize.y)));
                        window.clear();
                        window.display();

                        menu.resize();
                    }
                }
            }

            #ifdef DEBUG
            if (frameByFrame) {
                if (!doFrame) {
                    continue;
                } else {
                    doFrame = false;
                }
            }
            #endif

            menu.update();

            window.clear();
            window.draw(menu);

            window.display();
        }
        sf::sleep(sf::milliseconds(1));
    }
}
