#pragma once
#include "GameObject.h"
#include "Graphic.h"
#include "Scene.h"
#include "GameScene.h"

enum SCENETYPE
{
	INTRO,
	MAIN,
	GAME,
	SCORE
};

class GameSystem
{
private:
	Scene* scene = nullptr;
public:
	void Init();
	void Update();
	void Render();
	void Release();
	void SetScene(int scenenumber);
};

