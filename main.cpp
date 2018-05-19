#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "map.cpp"
#include "laser.cpp"

using namespace std;

int main(int argc, char *argv[]) {
   al_init();
   al_init_image_addon();
   al_init_primitives_addon();

   ALLEGRO_DISPLAY *screen = al_create_display(800, 600);
   ALLEGRO_COLOR bg_color = al_map_rgb(50, 50, 50);
   ALLEGRO_COLOR tile_color = al_map_rgb(100, 100, 100);
   ALLEGRO_COLOR laser_color = al_map_rgb(255, 20, 20);
   ALLEGRO_EVENT_QUEUE *events = al_create_event_queue();
   ALLEGRO_EVENT next_event;

   al_install_keyboard();
   al_install_mouse();

   al_register_event_source(events, al_get_display_event_source(screen));
   al_register_event_source(events, al_get_keyboard_event_source());
   al_register_event_source(events, al_get_mouse_event_source());

   Map tilemap = Map(800, 600);
   Laser laser = Laser(&tilemap, 800, 600);

   al_clear_to_color(bg_color);

   while (1) {
      al_get_next_event(events, &next_event);

      if (next_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         al_destroy_display(screen);
         al_destroy_event_queue(events);
         break;
      }

      tilemap.draw(tile_color);
      laser.draw(laser_color);

      al_flip_display();
      al_rest(0.01f);
   }

   return 0;
}
