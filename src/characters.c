//#include "animation.h"

//bool Animation_load(Animation *animation)
//{
//    // Load the ocean image
//    if(!Background_load(animation->renderer, &animation->background, BACKGROUND_IMG))
//        return false;


//    animation->background.image.rect.x = 0;
//    animation->background.image.rect.y = 0;


//    if(!Plane_load(animation->renderer, &animation->plane, INEINESTEIN_IMG))
//    {
//        Background_destroy(&animation->background);
//        return false;
//    }

//    if(!Plane_load(animation->renderer, &animation->plane2, PYTHA_IMG))
//    {
//        Background_destroy(&animation->background);
//        return false;
//    }

//    animation->plane.margin = INEINESTEIN_MARGIN;
//    animation->plane2.margin = PYTHA_MARGIN;

//    // Set plane initial position
//    Plane_setX(&animation->plane, (animation->width - animation->plane.image.rect.w) / 2); // Horiz. center
//    Plane_setY(&animation->plane, animation->height - animation->plane.image.rect.h - 75);

//    //healthbar first load:
//    Healthbar_Load(animation, animation->renderer);
//    printf("%d\n%d\n",animation->healthbar.health_img.rect.x , animation->healthbar.health_img.rect.y);

//    //combobar first load:
//    Combobar_Load(animation, animation->renderer);
//    printf("%d\n%d\n",animation->combobar.combo_img.rect.x , animation->combobar.combo_img.rect.y);

//    // Set plane initial position
//    Plane_setX2(&animation->plane2, (animation->width - animation->plane2.image.rect.w) / 4); // Horiz. center
//    Plane_setY2(&animation->plane2, animation->height - animation->plane2.image.rect.h - 75/*- animation->plane.margin*/);

//    //healthbar first load:
//    Healthbar_Load2(animation, animation->renderer);
//    printf("%d\n%d\n",animation->healthbar2.health_img.rect.x , animation->healthbar2.health_img.rect.y);

//    //combobar first load:
//    Combobar_Load2(animation, animation->renderer);
//    printf("%d\n%d\n",animation->combobar2.combo_img.rect.x , animation->combobar2.combo_img.rect.y);

//    // Plane move direction
//    animation->plane.direction = DIRECTION_STOP;
//    animation->plane2.direction = DIRECTION_STOP;

//    // Plane move speed in pixel/second
//    animation->plane.speed = INEINESTEIN_SPEED;
//     animation->plane2.speed = PYTHA_SPEED;

//     GameOver_Load(animation, animation->renderer);
//    return true;
//}
