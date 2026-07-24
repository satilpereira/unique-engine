The "Console-Like" SFML Architecture
To get that clean, dedicated-console feel without the bloat of a full desktop environment, here is how you structure the stack:

- **The Base OS**: Use Raspberry Pi OS Lite (or a custom Buildroot image if you want to get advanced later). This gives you Linux without the heavy desktop UI.

- **The Display Server**: Use Wayland/Weston or a super lightweight X11 window manager like Openbox. This runs invisibly in the background just to satisfy SFML's requirement for a windowing system.

- **The Launcher (Your "Switch" UI)**: You build your launcher in C++ with SFML. You configure the Pi to automatically boot straight into this SFML launcher on startup, bypassing any command line or desktop.

- **The Game Engine**: When a user selects a game, your launcher executes the game's binary (also built with your SFML engine), replacing the launcher on the screen. When the game closes, it boots you back to the launcher.
