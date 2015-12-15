#pragma once


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define BOUNDS_TOP WINDOW_HEIGHT - 60
#define BOUNDS_BOTTOM 35
#define BOUNDS_LEFT 35
#define BOUNDS_RIGHT WINDOW_WIDTH - 80

#define ORANGE 0xffA500ff

#define TITLE "Space Invaders"

class GameState;

extern unsigned spritePlayer;
extern unsigned spriteEnemy;
extern unsigned spriteBackground;
extern unsigned spriteFont;
extern unsigned spriteBullet;

enum STATE {SPLASH, PLAY, GAME, PAUSE, VICTORY, EXIT};

extern STATE applicationState;

void drawFontCentered(unsigned sprite, const char* text, unsigned x, unsigned y, unsigned w, unsigned h, unsigned color = 0xffffffff);