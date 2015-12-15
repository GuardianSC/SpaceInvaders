#pragma once
#include "BaseState.h"
#include "sfwdraw.h"

class SplashState : public BaseState
{
	public:
		unsigned color, baseColor;
		SplashState() : color(CYAN)
		{}
		void update();
		void draw();
};