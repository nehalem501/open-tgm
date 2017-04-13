/* BaseBackground.h */

#ifndef BASE_BACKGROUND_H
#define BASE_BACKGROUND_H

class BaseBackground {
    public:
        BaseBackground();
        void initGraphics();
        void changeToOptions();
        void changeToBackground();
        
    private:
        bool options;
};

#endif

