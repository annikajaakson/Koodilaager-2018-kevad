#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

//#include "map.cpp"

class Map {
public:
   int tile_size;
   int tile_distance;
   int map_width;
   int map_height;
   int map_grid[10][10];
   int map_start_x;
   int map_start_y;

   Map(int, int);
   void draw(ALLEGRO_COLOR);
};
