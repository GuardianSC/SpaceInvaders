#pragma once
#include "vec2.h"
#include "sfwdraw.h"
#include "declconst.h"


class GameObject
{
public:

	static GameState *gs;

	vec2 pos, vel;
	float radius, speed;
	unsigned color;
	bool active;
	unsigned sprite;
	GameObject(float x, float y, float radius) : pos({ x, y }), vel({ 0, 0 }), speed(0), color(NONE), radius(radius), active(true)
	{ }



	void update();
	void draw();

	void setInactive()
	{
		if (!active)return;
		active = false;
		onInactive();
	}

	virtual void onUpdate() {}
	virtual void onDraw() {}
	virtual void onCollision(GameObject &o){}
	virtual void onInactive() {}
};

void collides(GameObject &a, GameObject &b);

