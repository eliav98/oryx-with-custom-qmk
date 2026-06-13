// swapper.h
// Based on Callum Oakley's QMK userspace
// https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum

#pragma once

#include QMK_KEYBOARD_H

// Call this from process_record_user to handle swapper keys.
// - trigger:   the custom keycode (e.g. SW_WIN)
// - mod:       the modifier to hold (e.g. KC_LALT or KC_LGUI)
// - keys: the keys to send each press (e.g. KC_TAB)
// - active:    pointer to a bool tracking whether the mod is currently held
typedef struct {
    uint16_t        trigger;
    uint16_t        mod;
    const uint16_t *keys;
    uint8_t         keys_count;
    bool            active;
} swapper_t;

bool update_swapper(swapper_t *s, uint16_t keycode, keyrecord_t *record);
void release_all_swappers(swapper_t *swappers, uint8_t count);