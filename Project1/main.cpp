#include "vec2.h"
#include "sfwdraw.h"
#include "GameObject.h"
#include "Player.h"
#include "declconst.h"
#include "GameState.h"
#include <iostream>
#include <cassert>






int main()
{
	sfw::initContext(WINDOW_WIDTH, WINDOW_HEIGHT, "Space Invaders");

	//Player go((BOUNDS_RIGHT + BOUNDS_LEFT) / 2, BOUNDS_BOTTOM);

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