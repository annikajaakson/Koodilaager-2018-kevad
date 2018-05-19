#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

class Block {
public:
    int blocks[2][2];
    Block() {
        blocks[0][0] = 1;
        blocks[0][1] = 1;
        blocks[1][0] = 2;
        blocks[1][1] = 2;
   }
    void draw(ALLEGRO_COLOR tile_color) {
      int block_x;
      int block_y;
      int tile_size = 40;
      int tile_distance = 5;
      int map_width = 10;
      int map_height = 10;
      int screen_width = 800;
      int screen_height = 600;
      int map_start_x = (screen_width - map_width*tile_size - (map_width-1)*tile_distance)/2;
      int map_start_y = (screen_height - map_height*tile_size - (map_height-1)*tile_distance)/2;

         for (int i=0;i<2;i++) {
            //cout << i*j << endl;
            block_x = map_start_x+blocks[i][0]*tile_size+(blocks[i][0]-1)*tile_distance;
            block_y = map_start_y+blocks[i][1]*tile_size+(blocks[i][1]-1)*tile_distance;
            al_draw_filled_rectangle(block_x, block_y, block_x + tile_size, block_y + tile_size, tile_color);
         }
    }
};
