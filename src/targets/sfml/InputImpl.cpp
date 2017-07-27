/* InputImpl.cpp - SFML */

#include <SFML/Window.hpp>
#include <map>
#include "InputImpl.h"

bool TestEvent(MyKeys k, sf::Event e) {
    // Mouse event
    if (k.myInputType == MouseInput && k.myEventType == e.type && k.myMouseButton == e.mouseButton.button) {
        return true;
    }

    // Keyboard event
    if (k.myInputType == KeyboardInput && k.myEventType == e.type && k.myKeyCode == e.key.code) {
        return true;
    }

    // TODO Joystick event

    return false;
}

void InputImpl::init() {
    eventKey assignedKeys;
    MyKeys key;

    // Start
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::Return;
    assignedKeys.add(key);
    eventKeys[Button::Start] = assignedKeys;
    assignedKeys.clear();

    // Options
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::F2;
    assignedKeys.add(key);
    eventKeys[Button::Settings] = assignedKeys;
    assignedKeys.clear();

    // Up
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::Z;
    //key.myKeyCode = sf::Keyboard::W;
    assignedKeys.add(key);
    eventKeys[Button::Up] = assignedKeys;
    assignedKeys.clear();

    // Down
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::S;
    //key.myKeyCode = sf::Keyboard::S;
    assignedKeys.add(key);
    eventKeys[Button::Down] = assignedKeys;
    assignedKeys.clear();

    // Left
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::Q;
    //key.myKeyCode = sf::Keyboard::A;
    assignedKeys.add(key);
    eventKeys[Button::Left] = assignedKeys;
    assignedKeys.clear();

    // Right
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::D;
    //key.myKeyCode = sf::Keyboard::D;
    assignedKeys.add(key);
    eventKeys[Button::Right] = assignedKeys;
    assignedKeys.clear();

    // A
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::J;
    assignedKeys.add(key);
    eventKeys[Button::A] = assignedKeys;
    assignedKeys.clear();

    // B
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::K;
    assignedKeys.add(key);
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::I;
    assignedKeys.add(key);
    eventKeys[Button::B] = assignedKeys;
    assignedKeys.clear();

    // C
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::L;
    assignedKeys.add(key);
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::O;
    assignedKeys.add(key);
    eventKeys[Button::C] = assignedKeys;
    assignedKeys.clear();
}

void InputImpl::pollInputs() {
    m_prev_joystick = m_curr_joystick;
    m_prev_buttons = m_curr_buttons;

    m_curr_joystick = 0x00;
    m_curr_buttons = 0x00;

    // Joystick
    if (eventKeys[Button::Up].testInput())
        m_curr_joystick |= UP_BIT | RAW_UP_BIT;
    if (eventKeys[Button::Down].testInput())
        m_curr_joystick |= DOWN_BIT | RAW_DOWN_BIT;
    if (eventKeys[Button::Left].testInput())
        m_curr_joystick |= LEFT_BIT | RAW_LEFT_BIT;
    if (eventKeys[Button::Right].testInput())
        m_curr_joystick |= RIGHT_BIT | RAW_RIGHT_BIT;

    // Buttons
    if (eventKeys[Button::A].testInput())
        m_curr_buttons |= A_BIT;
    if (eventKeys[Button::B].testInput())
        m_curr_buttons |= B_BIT;
    if (eventKeys[Button::C].testInput())
        m_curr_buttons |= C_BIT;
    if (eventKeys[Button::Start].testInput())
        m_curr_buttons |= START_BIT;
    if (eventKeys[Button::Settings].testInput())
        m_curr_buttons |= SETTINGS_BIT;

    process();
}
