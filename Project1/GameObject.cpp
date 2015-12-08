#include "GameObject.h"
#include "sfwdraw.h"

void GameObject::update()
{
	pos = eulerIntegration(pos, vel, sfw::getDeltaTime());

	onUpdate();
}

void GameObject::draw()
{
	sfw::drawCircle(pos.x, pos.y, radius);

	onDraw();
}

void collides(GameObject &a, GameObject &b)
{
	if (circleOverlap(a.pos, a.radius, b.pos, b.radius))
	{
		a.onCollision(b);
		b.onCollision(a);
	}
}