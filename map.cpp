#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "map.hpp"

using namespace std;

/*class Map {
public:
   int tile_size;
   int tile_distance;
   int map_width;
   int map_height;
   int map_grid[10][10];
   int map_start_x;
   int map_start_y;

   Map(int screen_width, int screen_height) {
      tile_size = 40;
      tile_distance = 5;
      map_width = 10;
      map_height = 10;

      map_start_x = (screen_width - map_width*tile_size - (map_width-1)*tile_distance)/2;
      map_start_y = (screen_height - map_height*tile_size - (map_height-1)*tile_distance)/2;
   }

   void draw(ALLEGRO_COLOR tile_color) {
      int starting_x;
      int starting_y;

      for (int i = 0; i < map_width; i++) {
         for (int j = 0; j < map_height; j++) {
            starting_x = map_start_x+i*tile_size+(i-1)*tile_distance;
            starting_y = map_start_y+j*tile_size+(j-1)*tile_distance;
            al_draw_filled_rectangle(starting_x, starting_y, starting_x + tile_size, starting_y + tile_size, tile_color);
         }
      }
   }
};*/

Map::Map(int screen_width, int screen_height) {
    tile_size = 40;
      tile_distance = 5;
      map_width = 10;
      map_height = 10;

      map_start_x = (screen_width - map_width*tile_size - (map_width-1)*tile_distance)/2;
      map_start_y = (screen_height - map_height*tile_size - (map_height-1)*tile_distance)/2;
}

void Map::draw(ALLEGRO_COLOR tile_color) {
    int starting_x;
    int starting_y;

    for (int i = 0; i < map_width; i++) {
        for (int j = 0; j < map_height; j++) {
            starting_x = map_start_x+i*tile_size+(i-1)*tile_distance;
            starting_y = map_start_y+j*tile_size+(j-1)*tile_distance;
            al_draw_filled_rectangle(starting_x, starting_y, starting_x + tile_size, starting_y + tile_size, tile_color);
        }
    }
}
