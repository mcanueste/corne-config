/* vim: set ft=c tw=174: */
#pragma once

// Aliases
#define QUICK_TAP_MS 175
#define HOMEROW_TAPPING_TERM_MS 280
#define THUMB_TAPPING_TERM_MS 200
// #define TMUX_PREFIX LA(A)

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
        tapping-term-ms = <HOMEROW_TAPPING_TERM_MS>; \
        quick-tap-ms = <QUICK_TAP_MS>; \
        require-prior-idle-ms = <100>; \
        bindings = <HOLD>, <TAP>; \
        hold-trigger-key-positions = <TRIGGER_POS>; \
        hold-trigger-on-release; \
    )

&lt {  // layer-tap config
    flavor = "balanced";
    tapping-term-ms = <THUMB_TAPPING_TERM_MS>;
    quick-tap-ms = <QUICK_TAP_MS>;
};

// &sk {  // sticky-key config
//     release-after-ms = <900>;  // release after 0.6s
//     quick-release;             // no double capitalization when rolling keys
// };
//
// &sl {  // sticky-layer config
//     ignore-modifiers;          // allow chording sticky mods & layers
// };

// Create TMUX combos
// wait-ms = <0>;
// tap-ms = <1>;
// #define MAKE_TMUX(NAME, KEY) \
//     ZMK_BEHAVIOR(NAME, macro, \
//         bindings = <&macro_tap TMUX_PREFIX>, <&macro_tap KEY>; \
//     )
