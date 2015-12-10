#include "vec2.h"
#include "sfwdraw.h"
#include "GameObject.h"
#include "Player.h"
#include "declconst.h"
#include "GameState.h"
#include <iostream>
#include <cassert>



unsigned spritePlayer;
unsigned spriteEnemy;
unsigned spriteBackground;
unsigned spriteFont;

int main()
{
	sfw::initContext(WINDOW_WIDTH, WINDOW_HEIGHT, "Space Invaders");

	spritePlayer = sfw::loadTextureMap("./images/player.png");
	spriteEnemy = sfw::loadTextureMap("./images/enemy.png");
	spriteBackground = sfw::loadTextureMap("./images/background.png");


	

	GameState gs;

	while (sfw::stepContext())
	{
		gs.update();

		gs.draw();
	}



	sfw::termContext();
	//system("pause");
	return 0;
}