/* SettingsImpl.h - PS2 */

#ifndef SETTINGS_PS2_H
#define SETTINGS_PS2_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void init_graphics();
        void resize();
        void draw() const;
};

#endif
