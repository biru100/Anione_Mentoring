#include "GameSystem.h"

void GameSystem::Init()
{
	SetScene(SCENETYPE::GAME);
}

void GameSystem::Update()
{
	scene->Update();
}

void GameSystem::Render()
{
	scene->Render();
}

void GameSystem::Release()
{
	scene->Release();
	delete scene;
}

void GameSystem::SetScene(int scenenumber)
{
	if (scene != nullptr)
	{
		scene->Release();
		delete scene;
	}
	switch (scenenumber)
	{
	case SCENETYPE::GAME:
		scene = new GameScene();
		break;
	case SCENETYPE::INTRO:

		break;
	}
	if (scene != nullptr)
	{
		scene->Init();
	}
}
