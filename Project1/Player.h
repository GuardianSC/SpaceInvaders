#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:

	float delay, rof;
	int health;
	Player(float x, float y) : GameObject(x, y, 35), delay (0), rof(.2f), health(3)
	{
		sprite = spritePlayer;
		speed = 100;
		color = BLUE;
	}

	virtual void onCollision(GameObject &o);
	void onUpdate();
};