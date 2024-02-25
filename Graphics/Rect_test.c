#include <SDL2/SDL.h>

int main()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("My Graphics Program", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Get the window renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Set the clear color
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // black

    // Clear the window
    SDL_RenderClear(renderer);

    // Set the rectangle drawing color
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // red

    // Draw a rectangle
    SDL_Rect rect = {100, 50, 200, 100}; // position and size
    SDL_RenderDrawRect(renderer, &rect);

    // Update the screen
    SDL_RenderPresent(renderer);

    // Wait for user input
    SDL_Event event;
    while (SDL_WaitEvent(&event) && event.type != SDL_QUIT)
    {
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
