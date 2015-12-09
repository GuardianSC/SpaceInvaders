#include "GameObject.h"
#include "sfwdraw.h"


GameState *GameObject::gs;

void GameObject::update()
{
	if (!active)return;

	pos = eulerIntegration(pos, vel, sfw::getDeltaTime());

	onUpdate();
}

void GameObject::draw()
{
	if (!active)return;

	sfw::drawCircle(pos.x, pos.y, radius, 12, color);

	onDraw();
}

void collides(GameObject &a, GameObject &b)
{
	if (a.active && b.active)
	{
		if (circleOverlap(a.pos, a.radius, b.pos, b.radius))
		{
			a.onCollision(b);
			b.onCollision(a);
		}
	}
}