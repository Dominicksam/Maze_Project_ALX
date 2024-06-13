The Maze
The Maze is a 3D game that uses ray casting to render a 2D map into a 3D navigable world!

The Maze was written in C using SDL2 library. Development was performed using Ubuntu 24.04 - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0

About SDL2
Simple DirectMedia Layer is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is used by video playback software, emulators, and popular games including Valve's award-winning catalog and many Humble Bundle games.

Installation
$ git clone https://github.com/Dominicksam/Maze_Project_ALX

Usage
Execute ./maze maps/level_1 or type make run
Use up and down arrow keys to move forward and backward 
Use the right and left arrow keys to turn the camera around 

Compilation
$ gcc -g -Wall -Werror -Wextra -pedantic -I/usr/local/include/SDL2 ./src/*.c -o maze -L/usr/lib/x86_64-linux-gnu -lSDL2 -lm

