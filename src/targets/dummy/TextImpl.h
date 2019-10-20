/* TextImpl.h - Dummy */

#ifndef TEXT_DUMMY_H
#define TEXT_DUMMY_H

class TextImpl {
    public:
        void init_graphics();
        void update_graphics();
        void update_color(int8_t color);
        void render() const;
};

#endif
