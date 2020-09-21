/* callbacks.cpp - PSP */

#include "callbacks.h"
#include "pspsdk.h"

/*static bool exit_request = false;

bool running() {
    return !exit_request;
}*/

int exit_callback(int arg1, int arg2, void *common) {
    // unused arguments
    (void)(arg1);
    (void)(arg2);
    (void)(common);

    sceKernelExitGame();
    return 0;
}

int callback_thread(SceSize args, void *argp) {
    // unused arguments
    (void)(args);
    (void)(argp);

    int callback_id = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(callback_id);

    sceKernelSleepThreadCB();

    return 0;
}

int setup_callbacks(void) {
    int thread_id = 0;

    thread_id = sceKernelCreateThread("Update thread", callback_thread, 0x11, 0xFA0, 0, 0);
    if(thread_id >= 0) {
        sceKernelStartThread(thread_id, 0, 0);
    }

    return thread_id;
}
