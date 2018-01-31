#ifndef CONFIG_H
#define CONFIG_H
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    TCLT Troltek Corp Lewandowski Tech
#define PRODUCT         Klawiatura Mechaniczna Mark 1
#define DESCRIPTION     Oprogramowanie ukladowe bóg wie która wersja. Ja nie wiem...
#define MATRIX_ROWS 6
#define MATRIX_COLS 16
#define DEBOUNCE    5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
#define IS_COMMAND() ( \
keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)
#endif
