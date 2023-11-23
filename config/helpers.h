/* vim: set ft=c tw=174: */
#pragma once

// Global definitions
#define QUICK_TAP_MS 175

#define ZMK_HELPER_STRINGIFY(x) #x

// Create ZMK behavior
#define ZMK_BEHAVIOR(name, type, ...) \
    / { \
        behaviors { \
            name: name { \
                label = ZMK_HELPER_STRINGIFY(ZB_ ## name); \
                ZMK_BEHAVIOR_CORE_ ## type; \
                __VA_ARGS__ \
            }; \
        }; \
    };

// Create ZMK layer
#define ZMK_LAYER(name, layout) \
    / { \
        keymap { \
            compatible = "zmk,keymap"; \
            layer_ ## name { \
                label = ZMK_HELPER_STRINGIFY(name); \
                bindings = <layout>; \
            }; \
        }; \
    };

// Create Home Row Mode key maker
#define MAKE_HRM(NAME, HOLD, TAP, TRIGGER_POS) \
    ZMK_BEHAVIOR(NAME, hold_tap, \
        flavor = "balanced"; \
        tapping-term-ms = <280>; \
        quick-tap-ms = <QUICK_TAP_MS>; \
        require-prior-idle-ms = <150>; \
        bindings = <HOLD>, <TAP>; \
        hold-trigger-key-positions = <TRIGGER_POS>; \
        hold-trigger-on-release; \
    )
