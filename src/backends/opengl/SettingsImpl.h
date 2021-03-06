/* SettingsImpl.h - OpenGL */

#ifndef SETTINGS_OPENGL_H
#define SETTINGS_OPENGL_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void init_graphics();
        void resize();
        void draw() const;
};

#endif
