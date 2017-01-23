/* app-sfml.cpp */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../app.h"
#include "../global.h"
#include "../background.h"
#include "../menu.h"


sf::Texture tileset_tex;
sf::Texture outline_tex;
sf::Texture frame_tex;
sf::Texture digits_tex;
sf::Texture labels_tex;
sf::Texture text_tex;
sf::Texture grades_tex;
sf::Texture timer_tex;

sf::Time timePerFrame;

int tile_size;

void app() {
    // Resize graphics accordingly
    sf::Vector2u windowSize(640, 480);
    menu.updateSize(windowSize);
    bool fullscreen = false; // TODO load config

    // Create window
    sf::RenderWindow window;
    window.create(sf::VideoMode(windowSize.x, windowSize.y), "Open TGM");
    window.clear();
    window.display();

    // Init frame timer
    timePerFrame = sf::microseconds(16667);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    
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
                    
                    if (event.key.code == sf::Keyboard::F11) {
                        if (fullscreen) {
                            window.create(sf::VideoMode(windowSize.x, windowSize.y), "Open TGM", sf::Style::Default);
                            window.setView(sf::View(sf::FloatRect(0.f, 0.f, windowSize.x, windowSize.y)));
                            window.clear();
                            window.display();
                            
                            fullscreen = false;
                            menu.updateSize(windowSize);
                        } else {
                            window.create(sf::VideoMode::getDesktopMode(), "Open TGM", sf::Style::Fullscreen);
                            window.setView(sf::View(sf::FloatRect(0.f, 0.f, window.getSize().x, window.getSize().y)));
                            window.clear();
                            window.display();
                        
                            fullscreen = true;
                            menu.updateSize(window.getSize());
                        }
                    }
                }

                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::Resized) {
                    sf::Vector2u newWindowSize = window.getSize();
                    if (newWindowSize != windowSize) {
                        window.setView(sf::View(sf::FloatRect(0.f, 0.f, newWindowSize.x, newWindowSize.y)));
                        window.clear();
                        window.display();
                        
                        menu.updateSize(newWindowSize);
                        
                        if (!fullscreen)
                            windowSize = newWindowSize;
                    }
                }
            }

            menu.update();

            window.clear();
            window.draw(background);
            window.draw(menu);

            window.display();
        }
        sf::sleep(sf::milliseconds(1));
    }
}

