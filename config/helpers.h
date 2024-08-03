/* vim: set ft=c tw=174: */
#pragma once

#include "./corne_key_positions.h"

// Aliases
#define QUICK_TAP_MS 150
#define PRIOR_IDLE_MS 100
#define HOMEROW_TAPPING_TERM_MS 200
#define THUMB_TAPPING_TERM_MS 180
#define COMBO_TIMEOUT_MS 50

#define ZMK_BEHAVIOR_CORE_caps_word       compatible = "zmk,behavior-caps-word";       #binding-cells = <0>
#define ZMK_BEHAVIOR_CORE_dynamic_macro   compatible = "zmk,behavior-dynamic-macro";   #binding-cells = <1>
#define ZMK_BEHAVIOR_CORE_hold_tap        compatible = "zmk,behavior-hold-tap";        #binding-cells = <2>
#define ZMK_BEHAVIOR_CORE_key_repeat      compatible = "zmk,behavior-key-repeat";      #binding-cells = <0>
#define ZMK_BEHAVIOR_CORE_macro           compatible = "zmk,behavior-macro";           #binding-cells = <0>
#define ZMK_BEHAVIOR_CORE_macro_one_param compatible = "zmk,behavior-macro-one-param"; #binding-cells = <1>
#define ZMK_BEHAVIOR_CORE_macro_two_param compatible = "zmk,behavior-macro-two-param"; #binding-cells = <2>
#define ZMK_BEHAVIOR_CORE_mod_morph       compatible = "zmk,behavior-mod-morph";       #binding-cells = <0>
#define ZMK_BEHAVIOR_CORE_sticky_key      compatible = "zmk,behavior-sticky-key";      #binding-cells = <1>
#define ZMK_BEHAVIOR_CORE_tap_dance       compatible = "zmk,behavior-tap-dance";       #binding-cells = <0>
#define ZMK_BEHAVIOR_CORE_tri_state       compatible = "zmk,behavior-tri-state";       #binding-cells = <0>

#define ZMK_HELPER_STRINGIFY(X) #X

// Create ZMK layer
#define ZMK_LAYER(NAME, LAYOUT) \
    / { \
        keymap { \
            compatible = "zmk,keymap"; \
            layer_##NAME { \
                label = ZMK_HELPER_STRINGIFY(NAME); \
                bindings = <LAYOUT>; \
            }; \
        }; \
    };

// Combo Configuration
#define COMBO(NAME, LAYER, BINDINGS, KEYPOS) \
  combo_##NAME { \
    timeout-ms = <50>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
    layers = <LAYER>; \
  };

// Create Home Row Mode key maker
#define ZMK_BEHAVIOR(NAME, TYPE, ...) \
    / { \
        behaviors { \
            name: name { \
                label = ZMK_HELPER_STRINGIFY(ZB_##NAME); \
                ZMK_BEHAVIOR_CORE_##TYPE; \
                __VA_ARGS__ \
            }; \
        }; \
    };

#define MAKE_HRM(NAME, HOLD, TAP, TRIGGER_POS) \
    ZMK_BEHAVIOR(NAME, hold_tap, \
        flavor = "balanced"; \
        tapping-term-ms = <HOMEROW_TAPPING_TERM_MS>; \
        quick-tap-ms = <QUICK_TAP_MS>; \
        require-prior-idle-ms = <PRIOR_IDLE_MS>; \
        bindings = <HOLD>, <TAP>; \
        hold-trigger-key-positions = <TRIGGER_POS>; \
        hold-trigger-on-release; \
    )

// Home row modes
MAKE_HRM(hml, &kp, &kp, KEYS_R THUMBS)  // left-hand HRMs
MAKE_HRM(hmr, &kp, &kp, KEYS_L THUMBS)  // right-hand HRMs

// Home row layer switches
MAKE_HRM(hll, &mo, &kp, KEYS_R THUMBS)  // left-hand HRMs
MAKE_HRM(hlr, &mo, &kp, KEYS_L THUMBS)  // right-hand HRMs

// layer-tap config
&lt {
    flavor = "balanced";
    tapping-term-ms = <THUMB_TAPPING_TERM_MS>;
    quick-tap-ms = <QUICK_TAP_MS>;
};
