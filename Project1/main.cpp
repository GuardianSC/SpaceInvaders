#include "vec2.h"
#include "sfwdraw.h"
#include "GameObject.h"
#include "Player.h"
#include "declconst.h"
#include "GameState.h"
#include "SplashState.h"
#include "PauseState.h"
#include "VictoryState.h"
#include <iostream>
#include <cassert>
#include <cstring>

void drawFontCentered(unsigned sprite, const char* text, unsigned x, unsigned y, unsigned w, unsigned h, unsigned color)
{
	x -= strlen(text) * w / 2;
	sfw::drawString(spriteFont, text, x, y, w, h, 0, 0, color);
}


unsigned spritePlayer;
unsigned spriteEnemy;
unsigned spriteBackground;
unsigned spriteFont;
unsigned spriteBullet;

STATE applicationState = SPLASH;

int main()
{
	sfw::initContext(WINDOW_WIDTH, WINDOW_HEIGHT, "Space Invaders");

	spritePlayer = sfw::loadTextureMap("./images/player.png");
	spriteEnemy = sfw::loadTextureMap("./images/enemy.png");
	spriteBullet = sfw::loadTextureMap("./images/bullet.png");
	spriteBackground = sfw::loadTextureMap("./images/background.png");
	spriteFont = sfw::loadTextureMap("./images/fontmap.png", 16, 16);

	

	GameState gs;
	SplashState ss;
	PauseState ps;
	VictoryState vs;

	while (sfw::stepContext())
	{

		switch (applicationState)
		{
		case SPLASH:
			ss.update();
			ss.draw();
			break;
		case PLAY:
			gs.reset();
			applicationState = GAME;
		case GAME:
			gs.update();
			gs.draw();
			break;
		case PAUSE:
			gs.draw();
			ps.update();
			ps.draw();
			break;
		case VICTORY:
			gs.update();
			gs.draw();
			vs.update();
			vs.draw();
			break;
		/*case EXIT:
			break;*/
		}
		


		//gs.update();

		//gs.draw();
	}



	sfw::termContext();
	//system("pause");
	return 0;
}