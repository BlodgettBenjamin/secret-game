/** !
 * Secret game
 * 
 * @file main.c
 * 
 * @authors Ben Blodgett, Jacob Smith
 */

// Header files
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// SDL2
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Entry point
int main ( int argc, const char *argv[] )
{

    // Initialized data
    bool running = false;
    SDL_Event _event = { 0 };
    SDL_Window *p_window = (void *) 0;
    SDL_Renderer *p_renderer = (void *) 0;
    SDL_Texture *p_texture = (void *) 0;
    int x = 0, 
        y = 0;
    int s = 0;

    // Initialize SDL2
    SDL_Init(SDL_INIT_EVERYTHING);

    // Create a window
    p_window = SDL_CreateWindow("Secret game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    
    // Create a renderer
    p_renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED);

    p_texture = IMG_LoadTexture(p_renderer, "downs.png");

    // Set the running flag
    running = true;

    // Game loop
    while ( running )
    {
        
        s++;

        // Process each event
        while ( SDL_PollEvent(&_event) )
        {

            // Process an event
            switch ( _event.type )
            {

                // Close the window
                case SDL_QUIT:

                    // Clear the running flag
                    running = false;

                    // Done
                    break;
                
                // Mouse motion
                case SDL_MOUSEMOTION:

                    // Store the X and Y values
                    x = _event.motion.x;
                    y = _event.motion.y;

                default:
                    break;
            }
        }
        
        // Set the clear color
        SDL_SetRenderDrawColor(p_renderer, 255, 255, 255, 255);

        // Clear the framebuffer
        SDL_RenderClear(p_renderer);
        
        SDL_Rect r = {.x = 0, .y = 0, .w = x, .h = y };
        SDL_SetRenderDrawColor(p_renderer, 127, 127, 255, 255);

        SDL_RenderCopy(p_renderer, p_texture, NULL, &r);

        // Draw a line
        //SDL_RenderDrawLine(p_renderer, 0, 0, x, y);
        
        // Swap the framebuffer
        SDL_RenderPresent(p_renderer);
    }
    
    // Clean up SDL2
    SDL_DestroyWindow(p_window);
    SDL_Quit();

    // Success
    return EXIT_SUCCESS;
}
