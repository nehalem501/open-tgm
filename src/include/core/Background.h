/* Background.h */

#ifndef CORE_BACKGROUND_H
#define CORE_BACKGROUND_H

namespace Core {
    class Background {
        public:
            Background();
            void changeToOptions();
            void changeToBackground();

        protected:
            bool options;
    };
}

#endif
