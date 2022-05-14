#include "animation.h"

bool GameOver_Load(Animation *animation, SDL_Renderer *renderer)
{
    Image gameOver1;
    // Load startScreen image
    if(!Image_load(renderer, &gameOver1, GAMEOVERP1_IMG))
    {
        return false;
    }
    Image gameOver2;
    // Load startScreen image
    if(!Image_load(renderer, &gameOver2, GAMEOVERP2_IMG))
    {
        return false;
    }
    if (animation->gameoverP1){

        Image_render(renderer, &gameOver1);

    }
    else
    if (animation->gameoverP2){

        Image_render(renderer, &gameOver2);

    }

    return true;
}


bool Function_Hit(Animation *animation, SDL_Renderer *renderer)

{
     if (animation->plane.image.rect.x<(animation->plane2.image.rect.x + animation->plane2.image.rect.w)/2)
    {
         if (animation->healthbar.health != 0)
         {
            animation->healthbar2.health= animation->healthbar2.health -5;
            Healthbar_Load2(animation, renderer);
            animation->combobar.combo= animation->combobar.combo +1;
            Combobar_Load(animation, renderer);
         }
         else
          if (animation->healthbar.health == 0)
          {

             animation->gameoverP2= true;
          }
      }
    return true;
}
bool Function_Hit2(Animation *animation, SDL_Renderer *renderer)
{
     if (animation->plane2.image.rect.x>=(animation->plane.image.rect.x + animation->plane.image.rect.w)/5)
    {
         if (animation->healthbar.health != 0)
         {
            animation->healthbar.health= animation->healthbar.health -5;
            Healthbar_Load(animation, renderer);
            animation->combobar2.combo= animation->combobar2.combo +1;
            Combobar_Load2(animation, renderer);
         }
         else
          {
             animation->gameoverP1= true;
          }
      }
    return true;
}

bool AnimationHIT_load(Animation *animation)
{
    if(!Plane_load(animation->renderer, &animation->plane, INEINESTEINHIT_IMG))
    {
        Plane_destroy(&animation->plane);
        return false;
    }
    else
    return true;
}
bool AnimationHIT_load2(Animation *animation)
{
    if(!Plane_load(animation->renderer, &animation->plane2, PYTHAHIT_IMG))
    {
        Plane_destroy(&animation->plane2);
        return false;
    }

    return true;
}

bool animationCOMBO(Animation *animation )
{
    if(!Plane_load(animation->renderer, &animation->plane, INEINESTEINCOMBO_IMG))
    {
        Plane_destroy(&animation->plane);
        return false;
    }

    return true;
}
bool animationCOMBO2(Animation *animation )
{
    if(!Plane_load(animation->renderer, &animation->plane2, PYTHACOMBO_IMG))
    {
        Plane_destroy(&animation->plane2);
        return false;
    }

    return true;
}
bool AnimationJump_load(Animation *animation)
{
    if(!Plane_load(animation->renderer, &animation->plane, INEINESTEINJUMP_IMG))
    {
        Plane_destroy(&animation->plane);
        return false;
    }

    animation->plane.direction &= ~DIRECTION_DOWN;
    animation->plane.direction |= DIRECTION_UP;

    return true;
}
bool AnimationJump_load2(Animation *animation)
{
    if(!Plane_load(animation->renderer, &animation->plane2, PYTHAJUMP_IMG))
    {
        Plane_destroy(&animation->plane2);
        return false;
    }
    animation->plane2.direction &= ~DIRECTION_DOWN;
    animation->plane2.direction |= DIRECTION_UP;

    return true;
}

bool AnimationDown_load(Animation *animation) //SDL_Renderer *renderer
{
    //plane->image.rect.x= t - plane->image.rect.x;
    if(!Plane_load(animation->renderer, &animation->plane, INEINESTEINDOWN_IMG))
    {
        Plane_destroy(&animation->plane);
        return false;
    }

    else
        return true;
}
bool AnimationDown_load2(Animation *animation) //SDL_Renderer *renderer
{
    //plane->image.rect.x= t - plane->image.rect.x;
    if(!Plane_load(animation->renderer, &animation->plane2, PYTHADOWN_IMG))
    {
        Plane_destroy(&animation->plane2);
        return false;
    }

    else
        return true;
}
bool Animation_start(SDL_Renderer *renderer, int width, int height)
{
    Animation animation = {0};
    animation.renderer  = renderer;
    animation.width     = width;
    animation.height    = height;

    animation.healthbar.health = 100;
    animation.healthbar2.health = 100;
    animation.combobar.combo = 0;
    animation.combobar2.combo = 0;
    animation.gameoverP2=false;
    animation.gameoverP1=false;

    // Loat animation assets
    if(!Animation_load(&animation))
     return false;


    // Initialize framerate manager : 30 FPS
    FPSmanager fpsmanager;
    SDL_initFramerate(&fpsmanager);
    SDL_setFramerate(&fpsmanager, 60);

    // Initialize start frame
    int frame = SDL_getFramecount(&fpsmanager);


    // Event loop exit flag
    bool quit = false;

    // Event loop
    while(!quit)
    {
        SDL_Event e;

        // Get available event
        while(SDL_PollEvent(&e))
        {
            // Handle animation events
            quit = Animation_handleEvent(&animation, &e);
        }

        // Each new frame
        int currentFrame = SDL_getFramecount(&fpsmanager);
        if(currentFrame != frame)
        {
            // Update animation frame
            Animation_update(&animation, SDL_getFramerate(&fpsmanager));

            currentFrame = frame;
        }

        // Render animation
        Animation_render(&animation);

        // Update screen
        SDL_RenderPresent(renderer);

        // Delay
        SDL_framerateDelay(&fpsmanager);
    }

    Animation_destroy(&animation);

    return true;
}


bool Animation_load(Animation *animation)
{
    // Load the ocean image
    if(!Background_load(animation->renderer, &animation->background, BACKGROUND_IMG))
        return false;


    animation->background.image.rect.x = 0;
    animation->background.image.rect.y = 0;

    // Background move direction
    //animation->background.direction = DIRECTION_DOWN;

    // Background speed in pixel/second
    //animation->background.speed = BACKGROUND_SPEED;

    if(!Plane_load(animation->renderer, &animation->plane, INEINESTEIN_IMG))
    {
        Background_destroy(&animation->background);
        return false;
    }

    if(!Plane_load(animation->renderer, &animation->plane2, PYTHA_IMG))
    {
        Background_destroy(&animation->background);
        return false;
    }

    animation->plane.margin = INEINESTEIN_MARGIN;
    animation->plane2.margin = PYTHA_MARGIN;

    // Set plane initial position
    Plane_setX(&animation->plane, (animation->width - animation->plane.image.rect.w) / 2); // Horiz. center
    Plane_setY(&animation->plane, animation->height - animation->plane.image.rect.h - 75);

    //healthbar first load:
    Healthbar_Load(animation, animation->renderer);
    printf("%d\n%d\n",animation->healthbar.health_img.rect.x , animation->healthbar.health_img.rect.y);

    //combobar first load:
    Combobar_Load(animation, animation->renderer);
    printf("%d\n%d\n",animation->combobar.combo_img.rect.x , animation->combobar.combo_img.rect.y);

    // Set plane initial position
    Plane_setX2(&animation->plane2, (animation->width - animation->plane2.image.rect.w) / 4); // Horiz. center
    Plane_setY2(&animation->plane2, animation->height - animation->plane2.image.rect.h - 75/*- animation->plane.margin*/);

    //healthbar first load:
    Healthbar_Load2(animation, animation->renderer);
    printf("%d\n%d\n",animation->healthbar2.health_img.rect.x , animation->healthbar2.health_img.rect.y);

    //combobar first load:
    Combobar_Load2(animation, animation->renderer);
    printf("%d\n%d\n",animation->combobar2.combo_img.rect.x , animation->combobar2.combo_img.rect.y);

    // Plane move direction
    animation->plane.direction = DIRECTION_STOP;
    animation->plane2.direction = DIRECTION_STOP;

    // Plane move speed in pixel/second
    animation->plane.speed = INEINESTEIN_SPEED;
     animation->plane2.speed = PYTHA_SPEED;

     GameOver_Load(animation, animation->renderer);
    return true;
}

void Animation_destroy(Animation *animation)
{
    Plane_destroy(&animation->plane);
    Plane_destroy(&animation->plane2);
    Background_destroy(&animation->background);
}

bool Animation_handleEvent(Animation *animation, SDL_Event *e)
{
    bool quit = false;

    // User requests quit
    if(e->type == SDL_QUIT)
    {
        quit = true;
    }
    else if(e->type == SDL_KEYDOWN)
    {
        switch (e->key.keysym.sym)
        {
        case SDLK_ESCAPE:
            quit = true;
            break;

            case SDLK_UP:
            AnimationJump_load(animation);
            break;
            case SDLK_DOWN:

                AnimationDown_load(animation);// cut v value in half
                break;
            case SDLK_RIGHT:
            case SDLK_LEFT:
            //SET!!
             Plane_setDirection(&animation->plane, e->key.keysym.sym);
                break;
        case SDLK_SPACE: //Hit
            Function_Hit(animation, animation->renderer);
            AnimationHIT_load(animation);
            break;
        case SDLK_KP_ENTER:
             if (animation->combobar.combo>=3)
              {
                animationCOMBO(animation);
                animation->combobar.combo=0;
                if (animation->plane.image.rect.x<(animation->plane2.image.rect.x + animation->plane2.image.rect.w)/2)
                {
                    animation->healthbar2.health=animation->healthbar2.health-2;
                    animation->combobar.combo=0;
                }
               }

            break;


        case SDLK_w:
          AnimationJump_load2(animation);
            break;

         case SDLK_z:
            AnimationDown_load2(animation);
            break;

          case SDLK_d:
          Plane_setDirection(&animation->plane2, SDLK_RIGHT);
          break ;

          case SDLK_a:
          Plane_setDirection(&animation->plane2, SDLK_LEFT);
          break ;
          case SDLK_CAPSLOCK:
            Function_Hit2(animation, animation->renderer);
            AnimationHIT_load2(animation);
            break;
         case SDLK_TAB:
            if (animation->combobar2.combo>=3)
            {
              animationCOMBO2(animation);
              animation->combobar2.combo=0;
              if (animation->plane2.image.rect.x<(animation->plane.image.rect.x + animation->plane.image.rect.w)/5)
              {
                  animation->healthbar.health=animation->healthbar.health-2;
                  animation->combobar2.combo=0;
              }
            }
            break;
        }


    }

    else if(e->type == SDL_KEYUP)
    {
        switch (e->key.keysym.sym)
        {

        case SDLK_UP:
    //Plane_load(animation->renderer, &animation->plane, INEINESTEIN_IMG);
        // Plane_unsetDirection(&animation->plane, e->key.keysym.sym);
        break;
        case SDLK_DOWN:
         Plane_load(animation->renderer, &animation->plane, INEINESTEIN_IMG);
         break;
        case SDLK_RIGHT:
        case SDLK_LEFT:
           Plane_unsetDirection(&animation->plane, e->key.keysym.sym);
           break;
        case SDLK_SPACE: //Hit
           // animation->plane.NumberHits=animation->plane.NumberHits +1;
             Plane_load(animation->renderer, &animation->plane, INEINESTEIN_IMG);
        break;
        case SDLK_KP_ENTER: //Hit
           // animation->plane.NumberHits=animation->plane.NumberHits +1;
             Plane_load(animation->renderer, &animation->plane, INEINESTEIN_IMG);
        break;


         case SDLK_w:
        Plane_load(animation->renderer, &animation->plane2, PYTHA_IMG);
            break;
         case SDLK_a:
         case SDLK_d:
            Plane_unsetDirection2(&animation->plane2, e->key.keysym.sym);
            break;
        case SDLK_z:
        Plane_load(animation->renderer, &animation->plane2, PYTHA_IMG);
           break;
         case SDLK_CAPSLOCK:
            Plane_load(animation->renderer, &animation->plane2, PYTHA_IMG);
            break;
         case SDLK_TAB:
            Plane_load(animation->renderer, &animation->plane, PYTHA_IMG);
            break;
        }
    }
    return quit;
}

void Animation_update(Animation *animation, int framerate)
{
   // Move plane
    Plane_move(&animation->plane, animation->width, animation->height, framerate, animation);
    // Move plane2
    Plane_move(&animation->plane2, animation->width, animation->height, framerate, animation);
}


void Animation_render(Animation *animation)
{
    // Render ocean
    Background_render(animation->renderer, &animation->background, animation->width, animation->height);

    // Render plane
    Plane_render(animation->renderer, &animation->plane);

    // Render plane2*

    Plane_render(animation->renderer, &animation->plane2);

    //Render healthbar
    animation->healthbar.health_img.rect.x=500;
    animation->healthbar.health_img.rect.y=30;
    Image_render(animation->renderer , &animation->healthbar.health_img);

    //Render healthbar2
    animation->healthbar2.health_img.rect.x=30;
    animation->healthbar2.health_img.rect.y=30;
    Image_render(animation->renderer , &animation->healthbar2.health_img);

    //Render combobar
    animation->combobar.combo_img.rect.x=560;
    animation->combobar.combo_img.rect.y=560;
    Image_render(animation->renderer, &animation->combobar.combo_img);

    //Render combobar2

    animation->combobar2.combo_img.rect.x=30;
    animation->combobar2.combo_img.rect.y=560;
    Image_render(animation->renderer, &animation->combobar2.combo_img);


}
