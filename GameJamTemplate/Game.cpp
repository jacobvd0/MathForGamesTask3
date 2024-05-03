#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "EnvironmentBlock.h"

Game::Game()
{
	//Default constructor
}

Game::~Game()
{
	//Destructor
}

void Game::Run()
{
	//Contains raylib window launching and game logic loop calls
    InitWindow(m_windowWidth, m_windowHeight, "Raylib Template");

    SetTargetFPS(60);

    Load();

    while (!WindowShouldClose())
    {
        Update(GetFrameTime());
        Draw();
    }

    Unload();

    CloseWindow();

}

void Game::Load()
{
    m_root = new GameObject();
    m_player = new Player({0, 0}, {30, 30}, this);

    //Add player to game logic
    m_root->AddChild(m_player);

    //Make basic platforms (!!!CURRENTLY NOT BEING CLEANED UP PROPERLY BY MEMORY!!!) 
    m_root->AddChild(new EnvironmentBlock({ -20, 100 }, { 400, 20 }, this));
    m_root->AddChild(new EnvironmentBlock({ 400, 140 }, { 200, 1 }, this));
    m_root->AddChild(new EnvironmentBlock({ 800, 200 }, { 75, 2 }, this));
    m_root->AddChild(new EnvironmentBlock({ 900, 150 }, { 75, 1 }, this));
    m_root->AddChild(new EnvironmentBlock({ 1000, 100 }, { 75, 2 }, this));
    m_root->AddChild(new EnvironmentBlock({ 1100, 50 }, { 75, 1 }, this));

    //Safety Platforms :-)
    m_root->AddChild(new EnvironmentBlock({ -1400, 400 }, { 4000, 10 }, this));
    m_root->AddChild(new EnvironmentBlock({ -50, 350 }, { 30, 10 }, this));
    m_root->AddChild(new EnvironmentBlock({ -50, 300 }, { 30, 10 }, this));
    m_root->AddChild(new EnvironmentBlock({ -50, 250 }, { 30, 10 }, this));
    m_root->AddChild(new EnvironmentBlock({ -50, 200 }, { 30, 10 }, this));
    m_root->AddChild(new EnvironmentBlock({ -50, 150 }, { 30, 10 }, this));
    
   
    //SetUp Camera
    m_camera.offset = { (float)m_windowWidth / 2, (float)m_windowHeight / 2 };
    m_camera.rotation = 0.0f;
    m_camera.zoom = 1.0f;
}

void Game::Unload()
{
    delete m_root;
    delete m_player;
}

void Game::Update(float deltaTime)
{
    m_root->Update(deltaTime);

    //Camera follow player directly
    m_camera.target = m_player->GetPos();
}

void Game::Draw()
{
	BeginMode2D(m_camera); //Function for using the 2D camera "camera" thats been created
	ClearBackground(BLACK);

    m_root->Draw();

    EndMode2D();

	DrawFPS(10, 10);

	EndDrawing();
}
