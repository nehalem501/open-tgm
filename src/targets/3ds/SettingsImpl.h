/* SettingsImpl.h - 3DS */

#ifndef SETTINGS_3DS_H
#define SETTINGS_3DS_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void initGraphics();
        void updateSize();
        void draw() const;
};

#endif
