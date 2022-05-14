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

#ifndef ANIMATION_H
#define ANIMATION_H

#include "utils.h"
#include "plane.h"
#include "background.h"
#include "health_combo.h"

#define GAMEOVERP1_IMG       "assets/GameoverP1.jpg"
#define GAMEOVERP2_IMG       "assets/GameoverP2.jpg"

#define BACKGROUND_IMG       "assets/back.jpg"
#define BACKGROUND2_IMG      "assets/SPace.jpg"
#define BACKGROUND_SPEED     200

#define EINESTEIN_IMG        "assets/persoMvts/einestein.png"
#define EINESTEIN_SPEED      250
#define EINESTEIN_MARGIN     20

#define EINESTEINDOWN_IMG    "assets/persoMvts/einesteinDOWN.png"
#define EINESTEIN_SPEED      250
#define EINESTEIN_MARGIN     20

#define EINESTEINHIT_IMG     "assets/persoMvts/einesteinHIT.png"
#define EINESTEIN_SPEED      250
#define EINESTEIN_MARGIN     20

#define EINESTEINHIT_IMG     "assets/persoMvts/Pun.png"
#define EINESTEINJUMP_IMG    "assets/persoMvts/Jump.png"
#define EINESTEINCOMBO_IMG   "assets/persoMvts/einesteinCOMBO.png"
#define EINESTEINCOMBO2_IMG  "assets/persoMvts/einesteinCOMBO2.png"

#define INEINESTEIN_IMG       "assets/persoMvts2/INEinstein.png"
#define INEINESTEIN_SPEED     250
#define INEINESTEIN_MARGIN    20
#define INEINESTEINDOWN_IMG   "assets/persoMvts2/INEinsteinDOWN.png"
#define INEINESTEINHIT_IMG    "assets/persoMvts2/INEinsteinPun.png"
#define INEINESTEINJUMP_IMG   "assets/persoMvts2/INEinsteinJump.png"
#define INEINESTEINCOMBO_IMG  "assets/persoMvts2/INEinsteinCOMBO.png"

#define DARWIN_IMG              "assets/persoMvts/Darwin.png"
#define DARWIN_SPEED            250
#define DARWIN_MARGIN           20

#define DARWINDOWN_IMG   "assets/persoMvts/DarwinDOWN.png"
#define DARWIN_SPEED     250
#define DARWIN_MARGIN    20

#define DARWIN_IMG       "assets/persoMvts/DarwinPUN.png"
#define DARWIN_IMG       "assets/persoMvts/DarwinJUMP.png"


#define HAWKING_IMG       "assets/persoMvts/Hawking.png"
#define HAWKING_SPEED     250
#define HAWKING_MARGIN    20

#define HAWKINGHIT_IMG    "assets/persoMvts/hawkingPUN.png"
#define HAWKINGJUMP_IMG   "assets/persoMvts/hawkingJUMP.png"
#define HAWKINGCOMBO_IMG  "assets/persoMvts/hawkingCOMBO.png"


#define NEWTON_IMG       "assets/persoMvts/Newton.png"
#define NEWTON_SPEED     250
#define NEWTON_MARGIN    20

#define NEWTONDOWN_IMG   "assets/persoMvts/NewtonDOWN.png"
#define NEWTON_SPEED     250
#define NEWTON_MARGIN    20

#define NEWTONHIT_IMG    "assets/persoMvts/NewtonPUN.png"
#define NEWTONJUMP_IMG   "assets/persoMvts/NewtonJUMP.png"
#define NEWTONCOMBO_IMG  "assets/persoMvts/NewtonCOMBO.png"

#define PYTHA_IMG       "assets/persoMvts/Pytha.png"
#define PYTHA2_IMG       "assets/persoMvts/INPytha.png"
#define PYTHA_SPEED     250
#define PYTHA_MARGIN    20

#define PYTHADOWN_IMG   "assets/persoMvts/PythaDOWN.png"
#define PYTHADOWN2_IMG   "assets/persoMvts/INPythaDOWN.png"
#define PYTHA_SPEED     250
#define PYTHA_MARGIN    20

#define PYTHAHIT_IMG    "assets/persoMvts/PythaPUN.png"
#define PYTHAHIT2_IMG    "assets/persoMvts/INPythaPUN.png"
#define PYTHAJUMP_IMG   "assets/persoMvts/PythaJUMP.png"
#define PYTHAJUMP2_IMG   "assets/persoMvts/INPythaJUMP.png"
#define PYTHACOMBO_IMG  "assets/persoMvts/PythaCOMBO.png"
#define PYTHACOMBO2_IMG  "assets/persoMvts/INPythaCOMBO.png"

#define HEALTHBAR10_IMG  "assets/health_combo/HelathBar1.png"
#define HEALTHBAR20_IMG  "assets/health_combo/HelathBar2.png"
#define HEALTHBAR30_IMG  "assets/health_combo/HelathBar3.png"
#define HEALTHBAR40_IMG  "assets/health_combo/HelathBar4.png"
#define HEALTHBAR50_IMG  "assets/health_combo/HelathBar5.png"
#define HEALTHBAR60_IMG  "assets/health_combo/HelathBar6.png"
#define HEALTHBAR70_IMG  "assets/health_combo/HelathBar7.png"
#define HEALTHBAR80_IMG  "assets/health_combo/HelathBar8.png"
#define HEALTHBAR90_IMG  "assets/health_combo/HelathBar9.png"
#define HEALTHBAR100_IMG "assets/health_combo/HelathBar10.png"

#define COMBOBAR0_IMG  "assets/health_combo/ComboBar0.png"
#define COMBOBAR1_IMG  "assets/health_combo/ComboBar1.png"
#define COMBOBAR2_IMG "assets/health_combo/ComboBar2.png"
#define COMBOBAR3_IMG "assets/health_combo/ComboBar3.png"

//#define HEALTHBAR100_MARGIN  50

struct Health
{

    Image health_img;
    int margin ;
    int health ;
};
typedef struct Health Health ;

struct Combo
{
    Image combo_img;
    int combo;
    int margin;

};
typedef struct Combo Combo ;


struct Animation
{
    // Animation screen dimensions
    int width;
    int height;

    // Animation renderer
    SDL_Renderer *renderer;

    // Background and Plane
    Background background;
    Plane plane;
    Plane plane2;

    Health healthbar;
    Health healthbar2;
    Combo combobar;
    Combo combobar2;
    bool  gameoverP2;
    bool  gameoverP1;

};
typedef struct Animation Animation;

bool Healthbar_Load(Animation *animation, SDL_Renderer * renderer);
bool Healthbar_Load2(Animation *animation , SDL_Renderer * renderer);
bool Combobar_Load(Animation *animation, SDL_Renderer * renderer);
bool Combobar_Load2(Animation * animation , SDL_Renderer * renderer);

bool GameOver_Load(Animation *animation, SDL_Renderer *renderer);

bool AnimationDown_load(Animation *animation);
bool AnimationDown_load2(Animation *animation);
bool Animation_start(SDL_Renderer *renderer, int width, int height);

bool Animation_load(Animation *animation);
void Animation_destroy(Animation *animation);

bool Animation_handleEvent(Animation *animation, SDL_Event *e);
bool AnimationHIT_load(Animation *animation);
bool AnimationHIT_load2(Animation *animation);
bool animationCOMBO(Animation *animation);
bool animationCOMBO2(Animation *animation);
bool AnimationJump_load(Animation *animation);
bool AnimationJump_load2(Animation *animation);
void Animation_update(Animation *animation, int framerate);
void Animation_render(Animation *animation);

#endif // ANIMATION_H
