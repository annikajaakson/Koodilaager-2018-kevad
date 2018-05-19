#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "time.h"

using namespace std;

class Laser {
public:
   int start_x;
   int start_y;
   int end_x;
   int end_y;
   int direction; // -1 - right, 1 - left
   int radius;
   int thickness;

   Map *tilemap;
   int sw;
   int sh;

   Laser(Map *_tilemap, int screen_width, int screen_height) {
      tilemap = _tilemap;

      srand(time(NULL));
      start_x = rand() % tilemap->map_width;
      start_y = 0;
      radius = 10;
      thickness = 5;

      sw = screen_width;
      sh = screen_height;

      if (!start_x) {
         direction = -1;
      } else if (start_x == tilemap->map_width-1) {
         direction = 1;
      } else {
         direction = (rand() % 2 ? -1 : 1);
      }
   }

   void draw(ALLEGRO_COLOR laser_color) {
      int x = tilemap->map_start_x + start_x*tilemap->tile_size + (start_x - 1)*tilemap->tile_distance + tilemap->tile_size/2;
      int y = tilemap->map_start_y + start_y*tilemap->tile_size + (start_y - 1)*tilemap->tile_distance;

      if (direction == -1) {
         end_x = sw;
         end_y = y + sw-x;
      } else if (direction == 1) {
         end_x = 0;
         end_y = y + x;
      }

      al_draw_filled_circle(x, y, radius, laser_color);
      al_draw_line(x, y, end_x, end_y, laser_color, thickness);
   }
};
