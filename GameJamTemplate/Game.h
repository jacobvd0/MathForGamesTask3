#pragma once
#include <vector>
#include <raylib.h>
class GameObject;
class Player;

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Load();
	void Unload();
	void Update(float deltaTime);
	void Draw();


public:
	GameObject* m_root;
	Player* m_player;
	Camera2D m_camera = { 0 };
	

private:
	int m_windowHeight = 750;
	int m_windowWidth = 1200;
};

