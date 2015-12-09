#include "sfwdraw.h"
#include "Player.h"
#include "declconst.h"
#include "GameState.h"

void Player::onUpdate()
{


	vel = { 0, 0 };
	delay += sfw::getDeltaTime();
	if (sfw::getKey('W') && delay > rof)
	{
		delay = 0;
		gs->spawnBullet(pos.x, pos.y, 300);
	}

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

void Player::onCollision(GameObject &o)
	{
		if (o.vel.y < 0)
		{
			health--;
			o.active = false;
			radius /= 1.2f;
			switch (health)
			{
			case 2:
				color = YELLOW;
				break;
			case 1:
				color = RED;
				break;
			case 0:
				active = false;
				break;
			}
		}
	}