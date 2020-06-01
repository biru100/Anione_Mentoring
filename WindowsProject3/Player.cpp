#include "Player.h"

Player::Player(LPCWSTR filename) : GameObject(filename)
{
	for (int i = 0; i < 10; i++)
	{
		bullet[i] = new Bullet(L"1.png");
	}
	currentbullet = 0;
}

void Player::Move()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
	{
		position.x++;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		position.y--;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
	{
		position.x--;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	{
		position.y++;
	}
}

void Player::Shot()
{
	if (GetTickCount() - bullettime > 300)
	{
		bullettime = GetTickCount();
		if (GetAsyncKeyState(VK_SPACE) & 0x8001) // ÃÑ¾Ë »ý¼º
		{
			currentbullet %= 10;
			bullet[currentbullet++]->position = position;
		}
	}
	for (int i = 0; i < 10; i++) // ÃÑ¾Ë ³¯¾Æ°¨
	{
		bullet[i]->Move();
	}
}

void Player::Render()
{
	for (int i = 0; i < 10; i++)
	{
		Graphic::Render(bullet[i]);
	}
	Graphic::Render(this);
}

void Player::BulletAttackCheck(GameObject* obj)
{
	for (int i = 0; i < 10; i++)
	{
		bullet[i]->Attack(obj);
	}
}
