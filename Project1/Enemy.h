#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:

	float delay, rof;

	Enemy(float x, float y) : GameObject(x, y, 34), delay(0), rof(.05f)
	{
		color = WHITE;
		speed = 50;
		vel.y = -speed;
	}

	void onCollision(GameObject &o);

	void onUpdate();
};