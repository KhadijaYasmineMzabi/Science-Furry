/*
 * Copyright (c) 2018 Amine Ben Hassouna <amine.benhassouna@gmail.com>
 * All rights reserved.
 *
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
 *
 */

#include "plane.h"
#include "animation.h"

bool Plane_load(SDL_Renderer *renderer, Plane *plane, const char *image/*, const char *shadow*/)
{
    // Load plane image
    if(!Image_load(renderer, &plane->image, image))
    {
        return false;
    }

    return true;
}

void Plane_destroy(Plane *plane)
{
    Image_destroy(&plane->image);
    //Image_destroy(&plane->shadow);
}

void Plane_setX(Plane *plane, int x)
{
    //x=x+150;
    // Plane x coordinate
    plane->image.rect.x = x;

}
void Plane_setX2(Plane *plane2, int x)
{
    // Plane x coordinate
   // x=x-150;
    plane2->image.rect.x = x;

}
void Plane_setY(Plane *plane, int y)
{
    // Plane y coordinate
    plane->image.rect.y = y;

}

void Plane_setY2(Plane *plane2, int y)
{
    // Plane y coordinate
    plane2->image.rect.y = y;

}

void Plane_setCoordinates(Plane *plane, int x, int y )
{
    Plane_setX(plane, x);
    Plane_setY(plane, y);
}

void Plane_moveX(Plane *plane, int x)
{
    Plane_setX(plane, plane->image.rect.x + x);
}
void Plane_moveX2(Plane *plane2, int x)
{
    Plane_setX(plane2, plane2->image.rect.x + x);
}

void Plane_moveY(Plane *plane, int y)
{
    Plane_setY(plane, plane->image.rect.y + y);
}
void Plane_moveY2(Plane *plane2, int y)
{
    Plane_setY(plane2, plane2->image.rect.y + y);
}
void Plane_setDirection(Plane *plane, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_UP://maybe remove it
        plane->direction &= ~DIRECTION_DOWN;
        plane->direction |= DIRECTION_UP;
        break;

        case SDLK_DOWN:
        plane->direction &= ~DIRECTION_UP;
        plane->direction |= DIRECTION_DOWN;
        break;

    case SDLK_RIGHT:
        plane->direction &= ~DIRECTION_LEFT;
        plane->direction |= DIRECTION_RIGHT;
        break;

    case SDLK_LEFT:
        plane->direction &= ~DIRECTION_RIGHT;
        plane->direction |= DIRECTION_LEFT;
        break;
    }
}
void Plane_setDirection2(Plane *plane2, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_w://maybe remove it
        plane2->direction &= ~DIRECTION_DOWN;
        plane2->direction |= DIRECTION_UP;
        break;

        case SDLK_z:
        plane2->direction &= ~DIRECTION_UP;
        plane2->direction |= DIRECTION_DOWN;
        break;

    case SDLK_d:
        plane2->direction &= ~DIRECTION_LEFT;
        plane2->direction |= DIRECTION_RIGHT;
        break;

    case SDLK_a:
        plane2->direction &= ~DIRECTION_RIGHT;
        plane2->direction |= DIRECTION_LEFT;
        break;
    }
}
void Plane_unsetDirection(Plane *plane, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_UP:
        plane->direction &= ~DIRECTION_UP;
        break;

    case SDLK_DOWN:
        plane->direction &= ~DIRECTION_DOWN;
        break;

    case SDLK_RIGHT:
        plane->direction &= ~DIRECTION_RIGHT;
        break;

    case SDLK_LEFT:
        plane->direction &= ~DIRECTION_LEFT;
        break;
    }
}
void Plane_unsetDirection2(Plane *plane2, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_w:
        plane2->direction &= ~DIRECTION_UP;
        break;

    case SDLK_z:
        plane2->direction &= ~DIRECTION_DOWN;
        break;

    case SDLK_d:
        plane2->direction &= ~DIRECTION_RIGHT;
        break;

    case SDLK_a:
        plane2->direction &= ~DIRECTION_LEFT;
        break;
    }
}
void Plane_render(SDL_Renderer *renderer, Plane *plane)
{
    // Render plane shadow
    //Image_render(renderer, &plane->shadow);

    // Render plane
    Image_render(renderer, &plane->image);
}

void Plane_move(Plane *plane, int screenWidth, int screenHeight, int framerate, Animation* animation)
{
    int planeStep = plane->speed / framerate;


//    if (plane->image.rect.y >= 100)
//     {
//        plane->direction &= ~DIRECTION_UP;
//        plane->direction |= DIRECTION_DOWN;}

//    else

            if( (plane->direction & DIRECTION_UP)
            && plane->image.rect.y - planeStep >= plane->margin)
    {
        Plane_moveY(plane, -planeStep);

        if(plane->image.rect.y<230)
            {
            Plane_setDirection(plane,SDLK_DOWN);
        }

    }
    else if( (plane->direction & DIRECTION_DOWN))
    {
        if( plane->image.rect.y + plane->image.rect.h + planeStep <= screenHeight - plane->margin - 70) {
            Plane_moveY(plane, planeStep);
        } else { // to the initial position
            if(!Plane_load(animation->renderer, plane, INEINESTEIN_IMG))
            {

            }
            plane   ->direction &= ~DIRECTION_DOWN;

        }

    }

    if( (plane->direction & DIRECTION_RIGHT)
            && plane->image.rect.x + plane->image.rect.w + planeStep <= screenWidth - plane->margin)
    {
        Plane_moveX(plane, planeStep);
    }
    else if( (plane->direction & DIRECTION_LEFT)
             && plane->image.rect.x - planeStep >= plane->margin)
    {
        Plane_moveX(plane, -planeStep);
    }
}
void Plane_move2(Plane *plane2, int screenWidth, int screenHeight, int framerate, Animation* animation)
{
    int planeStep = plane2->speed / framerate;


//    if (plane->image.rect.y >= 100)
//     {
//        plane->direction &= ~DIRECTION_UP;
//        plane->direction |= DIRECTION_DOWN;}

//    else

            if( (plane2->direction & DIRECTION_UP)
            && plane2->image.rect.y - planeStep >= plane2->margin)
    {
        Plane_moveY(plane2, -planeStep);

        if(plane2->image.rect.y<230)
            {
            Plane_setDirection(plane2,SDLK_DOWN);
        }

    }
    else if( (plane2->direction & DIRECTION_DOWN))
    {
        if( plane2->image.rect.y + plane2->image.rect.h + planeStep <= screenHeight - plane2->margin - 70) {
            Plane_moveY(plane2, planeStep);
        } else { // to the initial position
            if(!Plane_load(animation->renderer, plane2, PYTHA_IMG))
            {

            }
            plane2->direction &= ~DIRECTION_DOWN;

        }

    }

    if( (plane2->direction & DIRECTION_RIGHT)
            && plane2->image.rect.x + plane2->image.rect.w + planeStep <= screenWidth - plane2->margin)
    {
        Plane_moveX(plane2, planeStep);
    }
    else if( (plane2->direction & DIRECTION_LEFT)
             && plane2->image.rect.x - planeStep >= plane2->margin)
    {
        Plane_moveX(plane2, -planeStep);
    }
}
