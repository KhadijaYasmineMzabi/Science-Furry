/*
* Copyright (c) 2018, 2019 Yasmine Mzabi, Seifallah Ben othmen, Fatma Mehrez, Mouhab Arafa
* <yasmine.mzabi@medtech.tn>
* Permission is hereby granted, free of charge, to any
* person obtaining a copy of this software and associated
* documentation files (the "Software"), to deal in the
* Software without restriction, including without
* limitation the rights to use, copy, modify, merge,
* publish, distribute, sublicense, and/or sell copies of
* the Software, and to permit persons to whom the Software
* is furnished to do so, subject to the following
* conditions:
*
* The above copyright notice and this permission notice
* shall be included in all copies or substantial portions
* of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
* ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
* SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
* IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*/

#include "utils.h"
#include "animation.h"
#include "menu.h"
#include <SDL_mixer.h>

#define WAVES_SOUND   "assets/MainMenu1.wav" //other sounds and effects for latte

// Define screen dimensions
#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600

int main(int argc, char* argv[])
{
    // Unused argc, argv
    (void) argc;
    (void) argv;

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        fprintf(stderr, "SDL could not be initialized!\n"
                        "SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Initialize SDL image
    int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;

    if((IMG_Init(flags) & flags) != flags)
    {
        fprintf(stderr, "SDL_image could not be initialized with JPG and PNG support!\n"
                        "SDL_image Error: %s\n", IMG_GetError());
        return 0;
    }

    //Initialize SDL2_mixer
       if (Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096) == -1)
        {
            printf("SDL2_mixer could not be initialized!\n"
                    "SDL_Error: %s\n", SDL_GetError() );
            return 0;
        }





#if defined linux && SDL_VERSION_ATLEAST(2, 0, 8)
    // Disable compositor bypass
    if(!SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0"))
    {
        fprintf(stderr, "SDL can not disable compositor bypass!\n");
        return 0;
    }
#endif

    // Create window
    SDL_Window *window = SDL_CreateWindow("Flying plane SDL animation",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if(!window)
    {
        fprintf(stderr, "Window could not be created!\n"
                        "SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        // Create renderer
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(!renderer)
        {
            fprintf(stderr, "Renderer could not be created!\n"
                            "SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            //  Load Wav sound
            Mix_Chunk *waves = Mix_LoadWAV(WAVES_SOUND);
            if (!waves)
            {
                printf(".Wav sound '%s' could not be loaded! \n "
                      "SDL_Error: %s\r", WAVES_SOUND, SDL_GetError());
            }
            // Play waves sound
            if(Mix_PlayChannel(-1, waves, 0) == -1)
            {
                printf("Waves sound could not be played!\n"
                       "SDL_Error: %s\n", SDL_GetError());
                Mix_FreeChunk(waves);
                return 0;

            }

            if(menu(renderer, SCREEN_WIDTH, SCREEN_HEIGHT) == true) {
                // Start animation
                Animation_start(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
            }

            // Destroy renderer
            SDL_DestroyRenderer(renderer);
        }

        // Destroy window
        SDL_DestroyWindow(window);
    }

    // Quit SDL_image
    IMG_Quit();

    // Quit SDL
    SDL_Quit();

    return 0;
}
