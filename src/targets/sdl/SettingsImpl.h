/* SettingsImpl.h - SDL */

#ifndef SETTINGS_SDL_H
#define SETTINGS_SDL_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void init_graphics();
        void resize();
        void draw() const;
};

#endif
