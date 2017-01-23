#include "../input.h"
#include <SFML/Window.hpp>
#include <map>

bool TestEvent(MyKeys k, sf::Event e) {
    // Mouse event
    if (k.myInputType == MouseInput && k.myEventType == e.type && k.myMouseButton == e.mouseButton.button) {
        return true;
    }
    
    // Keyboard event
    if (k.myInputType == KeyboardInput && k.myEventType == e.type && k.myKeyCode == e.key.code) {
        return true;
    }
    
    return false;
}

void Input::init() {
    eventKey assignedKeys;
    MyKeys key;

    // Start
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::Return;
    assignedKeys.add(key);
    eventKeys[Start] = assignedKeys;
    assignedKeys.clear();
    
    // Options
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::F2;
    assignedKeys.add(key);
    eventKeys[Options] = assignedKeys;
    assignedKeys.clear();

    // Up
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::Z;
    //key.myKeyCode = sf::Keyboard::W;
    assignedKeys.add(key);
    eventKeys[Up] = assignedKeys;
    assignedKeys.clear();

    // Down
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::S;
    //key.myKeyCode = sf::Keyboard::S;
    assignedKeys.add(key);
    eventKeys[Down] = assignedKeys;
    assignedKeys.clear();

    // Left
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::Q;
    //key.myKeyCode = sf::Keyboard::A;
    assignedKeys.add(key);
    eventKeys[Left] = assignedKeys;
    assignedKeys.clear();

    // Right
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::D;
    //key.myKeyCode = sf::Keyboard::D;
    assignedKeys.add(key);
    eventKeys[Right] = assignedKeys;
    assignedKeys.clear();

    // A
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::J;
    assignedKeys.add(key);
    eventKeys[A] = assignedKeys;
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
    eventKeys[B] = assignedKeys;
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
    eventKeys[C] = assignedKeys;
    assignedKeys.clear();
}

void Input::pollInputs() {
    bool tmp_up = eventKeys[Up].testInput();
    bool tmp_down = eventKeys[Down].testInput();
    bool tmp_left = eventKeys[Left].testInput();
    bool tmp_right = eventKeys[Right].testInput();
    
    bool tmp_a = eventKeys[A].testInput();
    bool tmp_c = eventKeys[C].testInput();
    
    if (tmp_left != prev_left) {
        m_left = tmp_left;
    }
    
    if (tmp_right != prev_right) {
        m_right = tmp_right;
    }
    
    if (tmp_right && tmp_left) {
        if (prev_right) {
            m_right = false;
        }
        if (prev_left) {
            m_left = false;
        }
    } else {
        m_left = tmp_left;
        m_right = tmp_right;
        prev_left = tmp_left;
        prev_right = tmp_right;
    }
    
    m_up = (tmp_up && !tmp_down) || (!m_up && m_down && tmp_up);
    m_down = (!tmp_up && tmp_down) || (m_up && !m_down && tmp_down);

    //m_left = (tmp_left && !tmp_right) || (!m_left && m_right && tmp_left);
    //m_right = (!tmp_left && tmp_right) || (m_left && !m_right && tmp_right);

    m_b = eventKeys[B].testInput();
    
    if (tmp_a != prev_a) {
        m_a = tmp_a;
    }
    
    if (tmp_c != prev_c) {
        m_c = tmp_c;
    }
    
    if (tmp_c && tmp_a) {
        if (prev_c) {
            m_c = false;
        }
        if (prev_a) {
            m_a = false;
        }
    } else {
        m_a = tmp_a;
        m_c = tmp_c;
        prev_a = tmp_a;
        prev_c = tmp_c;
    }
    
    m_start = eventKeys[Start].testInput();
}

