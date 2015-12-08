#pragma once
#include "vec2.h"
class GameObject
{
public:
	vec2 pos, vel;
	float radius, speed;

	

	GameObject(float x, float y, float radius) : pos({ x, y }), vel({ 0, 0 }), radius(radius)
	{ }



	void update();
	void draw();


	virtual void onUpdate() {}
	virtual void onDraw() {}
	virtual void onCollision(GameObject &o)
	{ }
};

bool isColliding(GameObject &a, GameObject &b);

