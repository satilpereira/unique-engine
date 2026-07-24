# unique-engine

A C++ game engine built on SFML 3 and OpenGL.

## Layout

```
src/            Engine source, one module per subsystem
  Core/         Application bootstrap, main loop, logging, time
  ECS/          Entities, components, systems
  Scene/        Scene graph / scene management
  Physics/      Physics simulation
  Renderer/     2D/3D rendering (SFML + OpenGL draw layer)
  Resources/    Asset loading & caching
  Platform/     Window/input abstraction
  Audio/        Sound & music playback

assets/         Runtime content: fonts/, textures/, models/, shaders/, sounds/

_lab/           Scratch space. Every *.cpp here is a standalone, self-
                contained experiment -- nothing in _lab links against src/.

third_party/    Vendored dependencies (gitignored, built locally -- see below)
```

Each `src/` and `assets/` subfolder currently holds a `.gitkeep`; they're
placeholders waiting for real code/content.

## Dependencies

Ubuntu/Debian package names (apt's SFML is only 2.6.x, so it's not enough
by itself -- see "Vendored SFML" below for the 3.x build):

```bash
sudo apt-get install build-essential cmake git \
  libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev \
  libfreetype-dev libharfbuzz-dev libxrandr-dev libxcursor-dev libxi-dev \
  libudev-dev libflac-dev libvorbis-dev libegl1-mesa-dev libdrm-dev \
  libgbm-dev libmbedtls-dev libssh2-1-dev xorg-dev
```

### Vendored SFML (3.1.0)

The engine links against SFML 3.1.0 built from source into
`third_party/sfml/`, not the system package. To (re)build it:

```bash
git clone --branch 3.1.0 --depth 1 https://github.com/SFML/SFML.git third_party/sfml-src

cmake -S third_party/sfml-src -B third_party/sfml-build \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX="$(pwd)/third_party/sfml" \
  -DSFML_BUILD_EXAMPLES=OFF -DSFML_BUILD_TEST_SUITE=OFF -DSFML_BUILD_DOC=OFF

cmake --build third_party/sfml-build -j"$(nproc)"
cmake --install third_party/sfml-build
```

`third_party/` is gitignored -- it's a local build artifact, reproducible
with the commands above, not checked into source control.

## Building

### Engine (`src/`)

```bash
make        # builds bin/unique-engine from everything under src/
make run    # build + run
make clean
```

### Lab experiments (`_lab/`)

Each `.cpp` file is compiled into its own binary, independent of the others
and of `src/`:

```bash
cd _lab
make               # builds every *.cpp -> bin/<name>
make bin/window    # build just window.cpp -> bin/window
make run-window    # build and run window.cpp
make clean
```

## Docs

See [docs/sfml.md](docs/sfml.md) for notes on a Raspberry Pi
"console-like" launcher architecture (separate from the engine build
itself -- a possible deployment target).
