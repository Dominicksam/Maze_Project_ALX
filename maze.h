#ifndef MAZE_H
#define MAZE_H

/*
 * Desc: Header file containing declarations for all functions
 *       on this project.
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SCREEN_HEIGHT 840
#define SCREEN_WIDTH 1240

#define MAP_WIDTH 32
#define MAP_HEIGHT 32

/**
 * struct SDL_Instance - Struct for SDL rendering in window
 * @window: The window to display rendering in
 * @renderer: The renderer to render graphics with
 **/
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;


/**
 * struct double_axis - Struct for axis x/y values of doubles
 * @x: X value of the object
 * @y: Y value of the object
 **/
typedef struct double_axis
{
	double x;
	double y;
} double_axis;


/**
 * struct int_axis - Struct for x/y values of ints
 * @x: X value of the object
 * @y: Y value of the object
 **/
typedef struct int_axis
{
	int x;
	int y;
} int_axis;

/**
 * struct keys - Struct to keep track of key presses
 * @up: Is up pressed (1) or not (0)
 * @down: Is down pressed (1) or not (0)
 * @right: Is right pressed (1) or not (0)
 * @left: Is left pressed (1) or not (0)
 **/
typedef struct keys
{
	int up;
	int down;
	int right;
	int left;
} keys;

/**
 * struct level - Struct to contain the level and all starting values
 * @map: The map of the level
 * @height: height of that map
 * @win: The x/y coordinate of the win space
 * @play: The x/y starting position of the player
 * @dir: The x/y of the direction vector the player is looking
 * @plane: The x/y direction vector of the projection plane
 **/
typedef struct level
{
	char **map;
	size_t height;
	int_axis win;
	double_axis play;
	double_axis dir;
	double_axis plane;
} level;

/* Initialize SDL_Instance: init_instance.c */
int init_instance(SDL_Instance *);

/* Handle keyboard events: event_handlers.c */
int keyboard_events(keys *);
void check_key_release_events(SDL_Event, keys *);
int check_key_press_events(SDL_Event, keys *);

/* Create the map for maze from file: create_maze.c */
char **create_map(char *, double_axis *, int_axis *, size_t *);
void plot_grid_points(char **, double_axis *, int_axis *, size_t, size_t, char *,
		      int *);
size_t get_line_count(char *);
size_t get_char_count(char *);

/* Build levels for every file passed to program: create_world.c */
level *build_world_from_args(int, char **);

/* Draw the maze: draw.c */
void draw(SDL_Instance, char **, double_axis, double_axis, double_axis);
void draw_walls(char **, double_axis, SDL_Instance, double_axis, double_axis);
void choose_color(SDL_Instance, char **, int_axis, int);
void draw_background(SDL_Instance);

/* Handle player movement/rotation: movement.c */
void rotate(double_axis *, double_axis *, int);
void movement(keys, double_axis *, double_axis *, double_axis *, char **);

/* Handle player winning: win.c */
void print_win(void);
int check_win(double_axis, int_axis, int *);

/* Check distance from player to wall: dist_checks.c */
double get_wall_dist(char **, double_axis *, int_axis *, int_axis *, double_axis *, int *,
		     double_axis *, double_axis *);
void check_ray_dir(int_axis *, double_axis *, double_axis, int_axis, double_axis, double_axis);

/* Free and close everything necessary: free_stuff.c */
void free_memory(SDL_Instance, char **, size_t);
void free_map(char **, size_t);
void close_SDL(SDL_Instance);
#endif
