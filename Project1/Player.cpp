#include "sfwdraw.h"
#include "Player.h"
#include "declconst.h"


void Player::onUpdate()
{
	vel = { 0, 0 };
	if (sfw::getKey('A'))
	{
		vel.x = -speed;
	}
	if (sfw::getKey('D'))
	{
		vel.x = speed;
	}

	if (pos.x - radius < BOUNDS_LEFT)
	{
		pos.x = BOUNDS_LEFT + radius;
	}

	if (pos.x + radius > BOUNDS_RIGHT)
	{
		pos.x = BOUNDS_RIGHT - radius;
	}
}