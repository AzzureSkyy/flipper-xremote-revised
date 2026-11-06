# Credits

## Original creator

**XRemote** — Advanced IR Remote App for Flipper Device
Copyright (c) 2023 **Sandro Kalatozishvili (kala13x)** — s.kalatoz@gmail.com
Original repository: https://github.com/kala13x/flipper-xremote (no longer available)

All application design, the learn/analyzer/saved-remote functionality, button layouts, icons, and documentation originate from the original author. This project is distributed under the same license as the original: **GNU GPLv3** (see [LICENSE](LICENSE)).

## Revisions by AzureSky

Starting from XRemote **1.4**, the following changes were made to produce **1.5**:

| Area | Change |
|------|--------|
| `xremote_app.h` / `xremote_app.c` | Added `tx_pin` and `otg_enabled` to `XRemoteAppSettings`; persisted as `txPin` / `otgEnabled` in `xremote.cfg` (backward compatible). Added `xremote_app_apply_tx_pin()`, `xremote_app_apply_otg()` and `xremote_app_get_tx_pin_str()`. |
| `xremote_settings.c` | New Settings entries **External IR** (`Flipper` / `2 (A7)` / `Detect`) and **5V on IR GPIO** (`OFF` / `ON` / `Auto`). Changes apply immediately and are saved. |
| `xremote.c` | Applies XRemote's own TX pin setting at launch instead of reading the stock Infrared app's settings file; restores internal IR output and prior OTG state on exit. |
| `xremote_app.h` | Removed firmware-specific `#include <assets_icons.h>` so the app builds against the official SDK with `ufbt`. |
| `application.fam`, `xremote.h`, `docs/changelog.md` | Version bumped to 1.5. |
| `README.md` | Image links point to the repository; added revision notes and this credits file. |

The external-module logic mirrors the approach used by the stock Flipper Zero Infrared application (`furi_hal_infrared_set_tx_output`, `furi_hal_infrared_detect_tx_output`, OTG power control).
