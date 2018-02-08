/* Background.h */

#ifndef CORE_BACKGROUND_H
#define CORE_BACKGROUND_H

namespace Core {
    class Background {
        public:
            Background();

            void go_to_options() {
                options = true;
            };

            void go_to_background() {
                options = false;
            };

        protected:
            bool options;
    };
}

#endif
