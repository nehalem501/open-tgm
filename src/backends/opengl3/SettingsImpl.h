/* SettingsImpl.h - OpenGL3 */

#ifndef SETTINGS_OPENGL3_H
#define SETTINGS_OPENGL3_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void init_graphics();
        void resize();
        void draw() const;
};

#endif
