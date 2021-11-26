#include "Game.h"

void Game::Initialize()
{
	// create engine
	engine = std::make_unique<luck::Engine>();
	engine->Startup();

	if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
	{
		SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
	}

	engine->Get<luck::Renderer>()->Create("Luck Be a Battlefield", dm.w, dm.h);

	std::cout << dm.w << ", " << dm.h << std::endl;

	// create scene
	scene = std::make_unique<luck::Scene>();
	scene->engine = engine.get();

	luck::SeedRandom(static_cast<unsigned int>(time(nullptr)));
	luck::SetFilePath("../Resources");
}

void Game::Shutdown()
{
	scene->RemoveAllActors();
	engine->Shutdown();
}

void Game::Update()
{
	engine->Update();

	quit = engine->Get<luck::InputSystem>()->GetKeyState(SDL_SCANCODE_ESCAPE) == luck::InputSystem::eKeyState::Pressed;

	switch (state)
	{
	case Game::eState::Reset:
		//Reset();
		break;
	case Game::eState::Title:
		//Title();
		break;
	case Game::eState::StartGame:
		StartGame();
		break;
	case Game::eState::GameOver:
		GameOver();
		break;
	default:
		break;
	}

	// update score


	scene->Update(engine->time.deltaTime);
}

void Game::Draw()
{

	engine->Get<luck::Renderer>()->BeginFrame();

	engine->Draw(engine->Get<luck::Renderer>());
	scene->Draw(engine->Get<luck::Renderer>());

	engine->Get<luck::Renderer>()->EndFrame();
}

//void Game::Reset()
//{
//	scene->RemoveAllActors();
//
//	//rapidjson::Document document;
//	//bool success = luck::json::Load("scene.txt", document);
//	//assert(success);
//
//	//scene->Read(document);
//
//	//state = eState::Title;
//	state = eState::StartGame;
//}
//
//void Game::Title()
//{
//	if (engine->Get<luck::InputSystem>()->GetKeyState(SDL_SCANCODE_SPACE) == luck::InputSystem::eKeyState::Pressed)
//	{
//		auto title = scene->FindActor("Title");
//		assert(title);
//		title->active = false;
//
//		state = eState::StartGame;
//	}
//}

void Game::StartGame()
{
	rapidjson::Document document;
	bool success = luck::json::Load("scene.txt", document);
	assert(success);

	scene->Read(document);

	luck::Tilemap tilemap;
	tilemap.scene = scene.get();
	success = luck::json::Load("board.txt", document);
	assert(success);
	tilemap.Read(document);
	tilemap.Create();
}

void Game::GameOver()
{

}