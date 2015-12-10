#pragma once
#include "gameObject.h"

class Particle : public GameObject
{
public:
	float startRadius, endRadius, lifespan, lifetime;
	
	Particle(float x, float y, float a_startRadius, float a_endRadius, float a_lifetime, unsigned a_color) : GameObject(x, y, a_startRadius), endRadius(a_endRadius), lifetime(a_lifetime), lifespan(0)
	{
		color = a_color;
	}

	void onUpdate()
	{
		lifespan += sfw::getDeltaTime();
		if (lifespan > lifetime)
		{
			active = false;
		}
	}

};