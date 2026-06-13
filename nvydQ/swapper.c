// swapper.c
// Based on Callum Oakley's QMK userspace

#include "swapper.h"

bool update_swapper(swapper_t *s, uint16_t keycode, keyrecord_t *record) {
    if (keycode == s->trigger) {
        if (record->event.pressed) {
            if (!s->active) {
                s->active = true;
                register_code(s->mod);
            }
            for (uint8_t i = 0; i < s->keys_count; i++) {
                register_code(s->keys[i]);
            }
        } else {
            for (int8_t i = s->keys_count - 1; i >= 0; i--) {
                unregister_code(s->keys[i]);
            }
        }
        return false;
    } else if (s->active && record->event.pressed) {
        s->active = false;
        unregister_code(s->mod);
    }
    return true;
}

void release_all_swappers(swapper_t *swappers, uint8_t count) {
    for (uint8_t i = 0; i < count; i++) {
        if (swappers[i].active) {
            swappers[i].active = false;
            unregister_code(swappers[i].mod);
        }
    }
}