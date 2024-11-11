#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/BasicROS/BasicROS.h"
#include "_basicros_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
_basicros_main_main_self_t* new__basicros_main() {
    _basicros_main_main_self_t* self = (_basicros_main_main_self_t*)lf_new_reactor(sizeof(_basicros_main_main_self_t));

    return self;
}
