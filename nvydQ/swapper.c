// swapper.c
// Based on Callum Oakley's QMK userspace

#include "swapper.h"

bool update_swapper(
    bool *active,
    uint16_t mod,
    uint16_t trigger_key,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(mod);
            }
            register_code(trigger_key);
        } else {
            unregister_code(trigger_key);
            // Don't unregister mod here — keep it held for the next press
        }
    } else if (*active) {
        // Any other key press while swapper is active: release the mod
        if (record->event.pressed) {
            *active = false;
            unregister_code(mod);
        }
    }
    return true;
} 