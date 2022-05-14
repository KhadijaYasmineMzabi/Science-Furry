#include "animation.h"

bool Healthbar_Load(Animation *animation , SDL_Renderer * renderer)
{


    switch (animation->healthbar.health)
    {

        case 100:
      {
        Image_destroy(&animation->healthbar.health_img);


        if(!Image_load(renderer, &animation->healthbar.health_img, HEALTHBAR100_IMG))
        {
            Image_destroy(&animation->healthbar.health_img);
            return false;
        }
          Image_render(renderer,&animation->healthbar.health_img);
          break ;
    }
        case 90:
        {

          Image_destroy(&animation->healthbar.health_img);


          if(!Image_load(renderer, &animation->healthbar.health_img, HEALTHBAR90_IMG))
          {
              Image_destroy(&animation->healthbar.health_img);
              return false;
          }
            Image_render(renderer,&animation->healthbar.health_img);
            break ;
      }
    case 80:
    {
      Image_destroy(&animation->healthbar.health_img);


      if(!Image_load(renderer, &animation->healthbar.health_img, HEALTHBAR80_IMG))
      {
          Image_destroy(&animation->healthbar.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar.health_img);
        break ;
  }
    case 70:
    {
      Image_destroy(&animation->healthbar.health_img);


      if(!Image_load(renderer, &animation->healthbar.health_img, HEALTHBAR70_IMG))
      {
          Image_destroy(&animation->healthbar.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar.health_img);
        break ;
  }
    case 60:
    {
      Image_destroy(&animation->healthbar.health_img);


      if(!Image_load(renderer, &animation->healthbar.health_img, HEALTHBAR60_IMG))
      {
          Image_destroy(&animation->healthbar.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar.health_img);
        break ;
    }
    case 50:
    {
      Image_destroy(&animation->healthbar.health_img);


      if(!Image_load(renderer, &animation->healthbar.health_img, HEALTHBAR50_IMG))
      {
          Image_destroy(&animation->healthbar.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar.health_img);
        break ;
  }
    case 40:
    {
      Image_destroy(&animation->healthbar.health_img);


      if(!Image_load(renderer, &animation->healthbar.health_img, HEALTHBAR40_IMG))
      {
          Image_destroy(&animation->healthbar.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar.health_img);
        break ;
  }
    case 30:
    {
      Image_destroy(&animation->healthbar.health_img);


      if(!Image_load(renderer, &animation->healthbar.health_img, HEALTHBAR30_IMG))
      {
          Image_destroy(&animation->healthbar.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar.health_img);
        break ;
  }
    case 20:
    {
      Image_destroy(&animation->healthbar.health_img);


      if(!Image_load(renderer, &animation->healthbar.health_img, HEALTHBAR20_IMG))
      {
          Image_destroy(&animation->healthbar.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar.health_img);
        break ;
  }
    case 10:
    {
      Image_destroy(&animation->healthbar.health_img);


      if(!Image_load(renderer, &animation->healthbar.health_img, HEALTHBAR10_IMG))
      {
          Image_destroy(&animation->healthbar.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar.health_img);
        break ;
  }
    return true;
  }
  return false ;
}

bool Healthbar_Load2(Animation *animation , SDL_Renderer * renderer)
{


    switch (animation->healthbar2.health)
    {

        case 100:
      {
        Image_destroy(&animation->healthbar2.health_img);


        if(!Image_load(renderer, &animation->healthbar2.health_img, HEALTHBAR100_IMG))
        {
            Image_destroy(&animation->healthbar2.health_img);
            return false;
        }
          Image_render(renderer,&animation->healthbar2.health_img);
          break ;
    }
        case 90:
        {

          Image_destroy(&animation->healthbar2.health_img);


          if(!Image_load(renderer, &animation->healthbar2.health_img, HEALTHBAR90_IMG))
          {
              Image_destroy(&animation->healthbar2.health_img);
              return false;
          }
            Image_render(renderer,&animation->healthbar2.health_img);
            break ;
      }
    case 80:
    {
      Image_destroy(&animation->healthbar2.health_img);


      if(!Image_load(renderer, &animation->healthbar2.health_img, HEALTHBAR80_IMG))
      {
          Image_destroy(&animation->healthbar2.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar2.health_img);
        break ;
  }
    case 70:
    {
      Image_destroy(&animation->healthbar2.health_img);


      if(!Image_load(renderer, &animation->healthbar2.health_img, HEALTHBAR70_IMG))
      {
          Image_destroy(&animation->healthbar2.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar2.health_img);
        break ;
  }
    case 60:
    {
      Image_destroy(&animation->healthbar2.health_img);


      if(!Image_load(renderer, &animation->healthbar2.health_img, HEALTHBAR60_IMG))
      {
          Image_destroy(&animation->healthbar2.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar2.health_img);
        break ;
    }
    case 50:
    {
      Image_destroy(&animation->healthbar2.health_img);


      if(!Image_load(renderer, &animation->healthbar2.health_img, HEALTHBAR50_IMG))
      {
          Image_destroy(&animation->healthbar2.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar2.health_img);
        break ;
  }
    case 40:
    {
      Image_destroy(&animation->healthbar2.health_img);


      if(!Image_load(renderer, &animation->healthbar2.health_img, HEALTHBAR40_IMG))
      {
          Image_destroy(&animation->healthbar2.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar2.health_img);
        break ;
  }
    case 30:
    {
      Image_destroy(&animation->healthbar2.health_img);


      if(!Image_load(renderer, &animation->healthbar2.health_img, HEALTHBAR30_IMG))
      {
          Image_destroy(&animation->healthbar2.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar2.health_img);
        break ;
  }
    case 20:
    {
      Image_destroy(&animation->healthbar2.health_img);


      if(!Image_load(renderer, &animation->healthbar2.health_img, HEALTHBAR20_IMG))
      {
          Image_destroy(&animation->healthbar2.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar2.health_img);
        break ;
  }
    case 10:
    {
      Image_destroy(&animation->healthbar2.health_img);


      if(!Image_load(renderer, &animation->healthbar2.health_img, HEALTHBAR10_IMG))
      {
          Image_destroy(&animation->healthbar2.health_img);
          return false;
      }
        Image_render(renderer,&animation->healthbar2.health_img);
        break ;
  }
    return true;
  }
  return false ;
}


bool Combobar_Load(Animation * animation , SDL_Renderer * renderer)
 {

    switch (animation->combobar.combo)
    {
        case 0:
        Image_destroy(&animation->combobar.combo_img);
    if(!Image_load(renderer, &animation->combobar.combo_img, COMBOBAR0_IMG))
    {
        Image_destroy(&animation->combobar.combo_img);
        return false;
    }
    Image_load(renderer, &animation->combobar.combo_img, COMBOBAR0_IMG);
            break;
        case 1:
        Image_destroy(&animation->combobar.combo_img);
    if(!Image_load(renderer, &animation->combobar.combo_img, COMBOBAR1_IMG))
    {
        Plane_destroy(&animation->plane);
        return false;
    }
    Image_load(renderer, &animation->combobar.combo_img, COMBOBAR1_IMG);
            break;
        case 2:
    Image_destroy(&animation->combobar.combo_img);

    if(!Image_load(renderer, &animation->combobar.combo_img, COMBOBAR2_IMG))
    {
        Image_destroy(&animation->combobar.combo_img);

        return false;
    }
    Image_load(renderer, &animation->combobar.combo_img, COMBOBAR2_IMG);
            break;

        case 3:
    Image_destroy(&animation->combobar.combo_img);

    if(!Image_load(renderer, &animation->combobar.combo_img, COMBOBAR3_IMG))
    {
        Image_destroy(&animation->combobar.combo_img);

        return false;
    }
    Image_load(renderer, &animation->combobar.combo_img, COMBOBAR3_IMG);
            break;

    }
    return true;
 }

bool Combobar_Load2(Animation * animation , SDL_Renderer * renderer)
 {

    switch (animation->combobar2.combo)
    {
        case 0:
        Image_destroy(&animation->combobar2.combo_img);
    if(!Image_load(renderer, &animation->combobar2.combo_img, COMBOBAR0_IMG))
    {
        Image_destroy(&animation->combobar2.combo_img);
        return false;
    }
    Image_load(renderer, &animation->combobar2.combo_img, COMBOBAR0_IMG);
            break;
        case 1:
        Image_destroy(&animation->combobar2.combo_img);
    if(!Image_load(renderer, &animation->combobar2.combo_img, COMBOBAR1_IMG))
    {
        Image_destroy(&animation->combobar2.combo_img);
        return false;
    }
    Image_load(renderer, &animation->combobar2.combo_img, COMBOBAR1_IMG);
            break;
        case 2:
    Image_destroy(&animation->combobar2.combo_img);

    if(!Image_load(renderer, &animation->combobar2.combo_img, COMBOBAR2_IMG))
    {
        Image_destroy(&animation->combobar2.combo_img);

        return false;
    }
    Image_load(renderer, &animation->combobar2.combo_img, COMBOBAR2_IMG);
            break;

        case 3:
    Image_destroy(&animation->combobar2.combo_img);

    if(!Image_load(renderer, &animation->combobar2.combo_img, COMBOBAR3_IMG))
    {
        Image_destroy(&animation->combobar2.combo_img);

        return false;
    }
    Image_load(renderer, &animation->combobar2.combo_img, COMBOBAR3_IMG);
            break;

    }
    return true;
 }
