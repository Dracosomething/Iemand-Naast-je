#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_gamepad.h>
#include <SDL3/SDL_touch.h>
#include <cstdio>
#include <cstdint>
#include <cstring>

namespace Core {
    typedef union {
	SDL_KeyboardEvent k_event;
	SDL_MouseEvent m_event;
	SDL_GamepadButtonEvent g_event;
	SDL_TouchFingerEvent t_event;
    } input_event_t;

    bool filter_for_input_events(void* user_data, SDL_Event* event) {
	return false; // check for input down events.
    }

    bool is_input_received(input_event_t* event) {
	if (!(SDL_HasEvent(SDL_EVENT_KEY_DOWN) || SDL_HasEvent(SDL_EVENT_MOUSE_BUTTON_DOWN) ||
	     SDL_HasEvent(SDL_EVENT_GAMEPAD_BUTTON_DOWN) || SDL_HasEvent(SDL_EVENT_FINGER_DOWN))) {
	    return false;
	}
	
	SDL_Event event;
	if (!SDL_PollEvent(&event)) {
	    return false;
	}
    }
}

#endif
