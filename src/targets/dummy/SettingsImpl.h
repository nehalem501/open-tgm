/* SettingsImpl.h - Dummy */

#ifndef SETTINGS_DUMMY_H
#define SETTINGS_DUMMY_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void initGraphics();
        void updateSize();
        void draw() const;
};

#endif
