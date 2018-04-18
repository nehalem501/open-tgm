/* SettingsImpl.h - SDL2 */

#ifndef SETTINGS_SDL2_H
#define SETTINGS_SDL2_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void init_graphics();
        void resize();
        void draw() const;
};

#endif
