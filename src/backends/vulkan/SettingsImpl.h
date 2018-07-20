/* SettingsImpl.h - Vulkan */

#ifndef SETTINGS_VULKAN_H
#define SETTINGS_VULKAN_H

#include <core/Settings.h>

class SettingsImpl : public Core::Settings {
    public:
        void init_graphics();
        void resize();
        void draw() const;
};

#endif
