/* InputImpl.h - SFML */

#ifndef INPUT_SFML_H
#define INPUT_SFML_H

#include <SFML/Window.hpp>
#include <iostream>
#include <map>
#include <core/Input.h>

enum Buttons {
    Up = 0,
    Down = 1,
    Right = 2,
    Left = 3,
    A = 4,
    B = 5,
    C = 6,
    Start = 7,
    Settings = 8
};

enum InputType {
    KeyboardInput,
    MouseInput,
    JoystickInput
};

struct MyKeys {
    InputType myInputType;
    sf::Event::EventType myEventType;
    sf::Keyboard::Key myKeyCode;
    sf::Mouse::Button myMouseButton;
};

bool TestEvent(MyKeys k, sf::Event e);

class eventKey {
    public:
        void add(MyKeys key) {
            assignedKeys.push_back(key);
        }

        void clear() {
            assignedKeys.clear();
        }

        bool test(sf::Event event) {
            for (unsigned int i = 0; i < assignedKeys.size(); i++) {
                if(TestEvent(assignedKeys[i], event))
                    return true;
            }
            return false;
        }

        bool testInput() {
            for (unsigned int i = 0; i < assignedKeys.size(); i++) {
                switch(assignedKeys[i].myInputType) {
                    case KeyboardInput:
                        if (sf::Keyboard::isKeyPressed(assignedKeys[i].myKeyCode))
                            return true;
                        break;

                    case MouseInput:
                        // TODO
                        /*if (sf::Keyboard::isKeyPressed(assignedKeys[i].myKeyCode))
                            return true;*/
                        break;

                    case JoystickInput:
                        // TODO
                        /*if (sf::Keyboard::isKeyPressed(assignedKeys[i].myKeyCode))
                            return true;*/
                        break;

                    default:
                        return false;
                }
            }
            return false;
        }

        std::vector<MyKeys> assignedKeys;
};

class InputImpl : public Core::Input {
    public:
        void init();
        void pollInputs();

    private:
        std::map<int, eventKey> eventKeys;
};

#endif
