# Installation

### Linux Instructions

1. Install gcc / sfml on your system
   - For Ubuntu/Debian based systems:
     ```bash
     sudo apt-get install g++ build-essential libsfml-dev
     ```
1. Download and extract the assignment zip file
1. Navigate to the assignment root directory
1. Use g++ compile the program with the following command:
   ```bash
   g++ src/*.cpp -Isrc -std=c++17 -o bin/sfmlgame -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
   ```
   Or use the makefile provided by running:
   ```bash
   make
   ```
1. This will replace the executable sfmlgame in the bin directory
1. Change to the bin directory and run the program with:
   ```bash
   cd bin
   ./sfmlgame
   ```
