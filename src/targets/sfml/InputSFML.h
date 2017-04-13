/* InputSFML.h */

#ifndef INPUT_H
#define INPUT_H

#ifdef TARGET_SFML
#include <SFML/Window.hpp>
#include <iostream>
#include <map>

enum Buttons {
    Up = 0,
    Down = 1,
    Right = 2,
    Left = 3,
    A = 4,
    B = 5,
    C = 6,
    Start = 7,
    Options = 8
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
#endif // TARGET_SFML

class Input {
    private:
        bool m_start, m_up, m_down, m_left, m_right, m_a, m_b, m_c;
        bool prev_up, prev_down, prev_left, prev_right, prev_a, prev_c;

    public:
        Input();

        void init();

        inline bool start() { return m_start; };

        inline bool up() { return m_up; };
        inline bool down() { return m_down; };
        inline bool left() { return m_left; };
        inline bool right() { return m_right; };

        inline bool drop() { return m_up; };

        inline bool rotateRight() { return m_b; };
        inline bool rotateLeft() { return m_a; }; //TODO m_c

        inline bool a() { return m_a; };
        inline bool b() { return m_b; };
        inline bool c() { return m_c; };

        void pollInputs();

    #ifdef TARGET_SFML
    private:
        std::map<int, eventKey> eventKeys;
    #endif
};

#endif
