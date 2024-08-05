/* App.h */

#ifndef APP_H
#define APP_H

/* Forward declarations to avoid dependency hell */
class Scene;

struct App {
    App();
    void run(Scene& scene);
};

#endif

