#include "All_headers.h"

ALLEGRO_TIMER *fps_timer = NULL; 
ALLEGRO_DISPLAY *display = NULL;
int width = 640;
int height = 480;
int fps = 60;

int main(void)
{
	//allegro variables
	if (!al_init())		// test allegro
		al_show_native_message_box(display, "Arcade Jump", "Error", "Error", "Error with allegro", ALLEGRO_MESSAGEBOX_WARN);

	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
	display = al_create_display(width, height);
	al_set_window_title(display, "Arcade Jump");
	al_hide_mouse_cursor(display);

	if (!display)		//test display
		al_show_native_message_box(display, "Arcade Jump", "Error", "Error", "Error with display", ALLEGRO_MESSAGEBOX_WARN);

	fps_timer = al_create_timer(1.0 / fps);
	al_start_timer(fps_timer);

	//addon init
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	menu();

	// destroying globall variables
	al_destroy_display(display);
	al_destroy_timer(fps_timer);
	return EXIT_SUCCESS;
}