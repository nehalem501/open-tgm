/* SettingsImpl.h - GBA */

#ifndef SETTINGS_GBA_H
#define SETTINGS_GBA_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void init_graphics();
        void resize();
        void draw() const;
};

#endif
