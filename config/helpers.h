/* vim: set ft=c tw=174: */
#pragma once

#define ZMK_HELPER_STRINGIFY(x) #x

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

