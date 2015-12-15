#include "victorystate.h"
#include "declconst.h"
#include <cstring>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>

void VictoryState::update()
{
	float wave = (0xff * (cosf(sfw::getTime() * 4) + 1) / 2);
	color = baseColor + wave;

	if (sfw::getKey('R'))
		applicationState = SPLASH;
}

void VictoryState::draw()
{
	sfw::drawTexture(spriteBackground, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,
		WINDOW_WIDTH, WINDOW_HEIGHT, 0, true, 0, 0x88888888);

	unsigned x, y, s;

	s = 24;
	x = (WINDOW_WIDTH) / 2;
	y = WINDOW_HEIGHT * 3 / 4;
	drawFontCentered(spriteFont, "You Lose!", x, y, s, s);

	s = 18;
	y = WINDOW_HEIGHT * 5 / 8;
	drawFontCentered(spriteFont, "Press R to Return to Main", x, y, s, s, color);

	std::fstream fin("scores.dat", std::ios_base::in);
	std::vector<unsigned> scores;

	while (!fin.eof())
	{
		unsigned t;
		fin >> t;
		scores.push_back(t);
	}
	scores.pop_back();
	fin.close();

	y - WINDOW_HEIGHT / 2;
	s = 24;
	sfw::drawString(spriteFont, std::to_string(scores[scores.size() - 1]).c_str(), x + sin(sfw::getTime()) * 12, y, s, s, 0, 0, CYAN);

	s = 18;
	y = s;
	for (int i = scores.size() - 2; i >= 0 && scores.size() - i < 10; --i)
	{
		sfw::drawString(spriteFont, std::to_string(scores[i]).c_str(), x, y + 18 * i, s, s);
	}
}