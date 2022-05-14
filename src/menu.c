#include "menu.h"
#include "image.h"

#define STARTSCREEN_PATH        "assets/startScreen.png"
#define MENU_PATH               "assets/menuDesign.png"
#define HOWTOPLAY_PATH          "assets/HowTo.png"
#define ABOUTGAME_PATH          "assets/AboutTheGame.png"
#define CHOOSE_PERSO_PATH       "assets/choosePerso.png"
#define INFOPERSO1_PATH         "assets/persoInfo/perso1.png"
#define INFOPERSO2_PATH         "assets/persoInfo/perso2.png"
#define INFOPERSO3_PATH         "assets/persoInfo/perso3.png"
#define INFOPERSO4_PATH         "assets/persoInfo/perso4.png"
#define INFOPERSO5_PATH         "assets/persoInfo/perso5.png"
#define INFOPERSO6_PATH         "assets/persoInfo/perso6.png"
#define INFOPERSO7_PATH         "assets/persoInfo/perso7.png"



bool menu(SDL_Renderer *renderer, int width, int height/*, int persoNb*/)
{
    Image start;
    // Load startScreen image
    if(!Image_load(renderer, &start, STARTSCREEN_PATH))
    {
        return false;
    }

    Image menu;
    // Load menu image
    if(!Image_load(renderer, &menu, MENU_PATH))
    {
        return false;
    }

//    Image howToPlay;
//    // Load menu image
//    if(!Image_load(renderer, &howToPlay, HOWTOPLAY_PATH))
//    {
//        return false;
//    }

    Image chooseP;
    // Load menu image
    if(!Image_load(renderer, &chooseP, CHOOSE_PERSO_PATH))
    {
        return false;
    }

//    Image perso1;
//    // Load menu image
//    if(!Image_load(renderer, &perso1, INFOPERSO1_PATH))
//    {
//        return false;
//    }

//    Image aboutG;
//    // Load menu image
//    if(!Image_load(renderer, &aboutG, ABOUTGAME_PATH))
//    {
//        return false;
//    }

    menu.rect=start.rect;
    chooseP.rect=menu.rect;
//    howToPlay.rect=menu.rect;
//    aboutG.rect=menu.rect;
    //perso1.rect=chooseP.rect;

    bool showStart = true;
    bool isRunning = true;
    bool startGame = false;
    bool choosePerso=false;
//    bool howPlay=false;
//   bool aboutGame=false;
    //bool motion=false;

    SDL_Event e;

    while (isRunning)
    {

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                isRunning = false;
                startGame = false;
            }
//            if (e.type==SDL_MOUSEMOTION)
//            {
//                if(choosePerso==true && motion==true && showStart==false)
//                {
//                    if (e.button.y>70 && e.button.y<172 && e.button.x>60 && e.button.x<177)
//                {
//                    isRunning = false;
//                    //showStart =false;
//                    motion=true;
//                }
//                }

//            }
            else if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    if(showStart == true) // Show start
                    {
                        showStart = false;
                        //choosePerso=true;
                        //startGame=true;

                    }
                    else
                    { // Show menu
                        if (e.button.y>360 && e.button.y<396 && e.button.x>310 && e.button.x<480)
                         {
                         //isRunning = false;
                         //startGame = true;
                         choosePerso=true;//show choose perso

                         }
//                        if (e.button.y>460 && e.button.y<500 && e.button.x>310 && e.button.x<485)
//                         {
//                         //isRunning = false;
//                         //startGame = true;
//                         howPlay=true;//show how to play
//                         }
//                      if (e.button.y>410 && e.button.y<444 && e.button.x>290 && e.button.x<514)
//                       {
//                            aboutGame=true;
//                      }
                      if (e.button.y>70 && e.button.y<172 && e.button.x>60 && e.button.x<177)
                      { isRunning = false;
                         choosePerso=false;
                        startGame = true;
                        //persoNb=1;

                      }
                      else if (e.button.y>70 && e.button.y<172 && e.button.x>268 && e.button.x<480)
                      { isRunning = false;
                         choosePerso=false;
                        startGame = true;
                        //persoNb=2;

                      }
                      else if (e.button.y>70 && e.button.y<172 && e.button.x>660 && e.button.x<880)
                      { isRunning = false;
                         choosePerso=false;
                        startGame = true;
                        //persoNb=3;

                      }
                      else if (e.button.y>250 && e.button.y<360 && e.button.x>120 && e.button.x<240)
                      {  isRunning = false;
                         choosePerso=false;
                         startGame = true;
                        // persoNb=4;

                      }
                      else if (e.button.y>250 && e.button.y<360 && e.button.x>120 && e.button.x<240)
                      { isRunning = false;
                         choosePerso=false;
                        startGame = true;
                        //persoNb=5;

                      }

                    }

                }
            }

        }



        if(showStart == true)
        {
            Image_render(renderer, &start);

        }

        else
        {
            Image_render(renderer, &menu);

         }
        if (choosePerso==true && showStart==false)
        {
            Image_render(renderer, &chooseP);

        }


//        if (howPlay==true && showStart==false)
//        {
//            Image_render(renderer, &howToPlay);
//        }
//        if (choosePerso==true && motion==true && showStart==false)
//        {
//             Image_render(renderer, &perso1);
//        }
//        else if (aboutGame==true && showStart==false)
//        {
//            Image_render(renderer, &aboutG);
//        }



    SDL_RenderPresent(renderer);

}

    return startGame;
}
