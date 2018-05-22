/* SettingsImpl.h - PS3 */

#ifndef SETTINGS_PS3_H
#define SETTINGS_PS3_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void init_graphics();
        void resize();
        void draw() const;
};

#endif
