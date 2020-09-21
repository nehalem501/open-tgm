/* pspsdk.h - PSP */

#ifndef WRAP_PSP_HEADERS_H
#define WRAP_PSP_HEADERS_H

// We need this hack because ISO C prohibits enum values greather than INT_MAX
#include "../../utils/disable_warnings_start.h"

#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <pspgu.h>
#include <pspgum.h>

#include "../../utils/disable_warnings_end.h"

#endif // WRAP_PSP_HEADERS_H
