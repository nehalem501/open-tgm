/* SettingsImpl.h - PSX */

#ifndef SETTINGS_PSX_H
#define SETTINGS_PSX_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void init_graphics();
        void resize();
        void draw() const;
};

#endif
