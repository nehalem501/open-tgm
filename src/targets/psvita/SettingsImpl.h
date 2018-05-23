/* SettingsImpl.h - PSVita */

#ifndef SETTINGS_PSVITA_H
#define SETTINGS_PSVITA_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void init_graphics();
        void resize();
        void draw() const;
};

#endif
