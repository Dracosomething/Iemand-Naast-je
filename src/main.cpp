#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include "core/input.hpp"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#define BROWSER_FPS 0 // 0 means that it runs at the browser refresh rate
#define APP_NAME "Iemand Naast Je"
#define APP_VERSION "0.1"
#define APP_IDENTIFIER "nl.hellscodebase.iemand-naast-je"

static SDL_Window* spWindow = NULL;
static SDL_Renderer* spRenderer = NULL;

void initialize_game(void) {
    if (!SDL_SetAppMetadata(APP_NAME, APP_VERSION, APP_IDENTIFIER)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Encountered error when setting app metadata: %s", SDL_GetError());
		exit(1);
    }
#ifdef __EMSCRIPTEN__
    emscripten_set_window_title(APP_NAME);
#endif

    if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Encountered error when initializing video: %s", SDL_GetError());
		exit(1);
    }

#ifdef __EMSCRIPTEN__
    int width;
    int height;
    emscripten_get_screen_size(&width, &height);
    
    if (width > 1920) {
	width = 1920;
    }

    if (height > 1080) {
	height = 1080;
    }

#else
    int width = 1920;
    int height = 1080;
#endif

    if (!SDL_CreateWindowAndRenderer(APP_NAME, width, height, SDL_WINDOW_FULLSCREEN, &spWindow, &spRenderer)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Encountered error when creating window/renderer: %s", SDL_GetError());
		exit(1);
    }

    if (!SDL_SetRenderLogicalPresentation(spRenderer, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Encountered error when settimg renderer logical presentation: %s", SDL_GetError());
		exit(1);
    }

    Core::setup_input_handling();
}

static void mainloop(void) {
    // We check if we have a quit event and exit the game
    if (SDL_HasEvent(SDL_EVENT_QUIT)) {
#ifdef __EMSCRIPTEN__
		emscripten_cancel_main_loop();
#else
		exit(0);
#endif
    }

    // true game logic
}

int main(int argc, char** argv) {
    initialize_game();

    printf("Hello, World!\n");

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(mainloop, BROWSER_FPS, true);
#else
    for (;;) { mainloop(); }
#endif

    return 0;
}
