#include "vec2.h"
#include <cmath>
#include <ctime>

float distance(vec2 a, vec2 b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;

	return sqrt(dx *dx + dy*dy);
}

float circleOverlap(vec2 pos, float r, vec2 pos1, float r1)
{
	float d = distance(pos, pos1);
	float r2 = r + r1;
	return d < r;
}

vec2 operator+(vec2 a, vec2 b)
{
	vec2 retval;
	retval.x = a.x + b.x;
	retval.y = a.y + b.y;
	return retval;
}

vec2 operator-(vec2 a, vec2 b)
{
	vec2 retval;
	retval.x = a.x - b.x;
	retval.y = a.y - b.y;
	return retval;
}

vec2 operator*(vec2 a, float b)
{
	vec2 retval;
	retval.x = a.x * b;
	retval.y = a.y * b;
	return retval;
}

vec2 operator/(vec2 a, float b)
{
	vec2 retval;
	retval.x = a.x / b;
	retval.y = a.y / b;
	return retval;
}

bool operator==(vec2 a, vec2 b)
{
	return a.x == b.x && a.y == b.y;
}


vec2 eulerIntegration(vec2 pos, vec2 vel, float dt)
{
	return pos + vel * dt;
}

float randRange(float min, float max)
{
	float alpha = rand() / (RAND_MAX*1.f);
	
	return min + alpha*(max - min);
}

float lerp(float start, float end, float alpha)
{
	start + alpha *(end - start);
}