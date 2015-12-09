#pragma once

struct vec2
{
	float x, y;
};

float circleOverlap(vec2 pos, float r, vec2 pos1, float r1);

float distance(vec2 a, vec2 b);

vec2 operator+(vec2 a, vec2 b);
vec2 operator-(vec2 a, vec2 b);

vec2 operator*(vec2 a, float b);
vec2 operator/(vec2 a, float b);

bool operator==(vec2 a, vec2 b);

vec2 eulerIntegration(vec2 pos, vec2 vel, float dt);

float randRange(float min, float max);

// Alpha is number between 0 and 1
float lerp(float start, float end, float alpha);