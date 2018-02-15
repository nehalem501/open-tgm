/* SettingsImpl.h - PSP */

#ifndef SETTINGS_PSP_H
#define SETTINGS_PSP_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void init_graphics();
        void resize();
        void draw() const;
};

#endif
