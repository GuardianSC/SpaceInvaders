#include "GameState.h"
#include <string>
#include <fstream>

void GameState::update()
{
	player.update();

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].update();
	}

	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].update();
	}

	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].update();
	}

	for (int i = 0; i < bullets.size(); ++i)
	{
		collides(player, bullets[i]);
	}

	for (int i = 0; i < enemies.size(); ++i)
	{
		for (int j = 0; j < bullets.size(); ++j)
		{
			collides(enemies[i], bullets[j]);
		}
	}

	spawnDelay += sfw::getDeltaTime();

	if (spawnDelay > spawnRate)
	{
		spawnDelay = 0;
		spawnEnemy(randRange(BOUNDS_LEFT, BOUNDS_RIGHT), BOUNDS_TOP);
	}

	if (applicationState == GAME)
	{
		if (!player.active)
		{
			std::fstream fout("scores.dat", std::ios_base::out | std::ios_base::app);

			fout << score << std::endl;
			fout.close();


			applicationState = VICTORY;
		}
		if (sfw::getKey('P'))
		{
			applicationState = PAUSE;
		}
	}
	else player.setInactive();


}

void GameState::draw()
{
	sfw::drawTexture(spriteBackground, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,	WINDOW_WIDTH, WINDOW_HEIGHT);

	player.draw();
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].draw();
	}
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].draw();
	}
}

void GameState::spawnBullet(float x, float y, float a_speed)
{
	Bullet b(x, y, a_speed);

	for (int i = 0; i < bullets.size(); i++)
	{
		if (!bullets[i].active)
		{
			bullets[i] = b;
			return;
		}
	}
	bullets.push_back(b);
}

void GameState::spawnEnemy(float x, float y)
{
	Enemy e(x, y);

	for (int i = 0; i < enemies.size(); i++)
	{
		if (!enemies[i].active)
		{
			enemies[i] = e;
			return;
		}
	}
	enemies.push_back(e);
}

void GameState::spawnParticle(float x, float y, float a_startRadius, float a_endRadius, float a_lifetime, unsigned a_color)
{
	Particle p(x, y, a_startRadius, a_endRadius, a_lifetime, a_color);

	for (int i = 0; i < particles.size(); ++i)
	{
		if (!particles[i].active)
		{
			particles[i] = p;
			return;
		}
	}
}