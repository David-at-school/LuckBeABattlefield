#pragma once
#include "Engine.h"

class Game
{
public:
	enum class eState
	{
		Reset,
		Title,
		StartGame,
		GameOver
	};

public:
	void Initialize();
	void Shutdown();

	void Update();
	void Draw();

	bool IsQuit() { return quit; };

private:
	void Reset();
	void Title();
	void StartGame();
	void GameOver();

public:
	std::unique_ptr<luck::Engine> engine;
	std::unique_ptr<luck::Scene> scene;
	SDL_DisplayMode dm;

private:
	bool quit = false;

	eState state = eState::StartGame;
	float score = 0;
	float stateTimer = 0;
	float spawnTimer = 0;
};