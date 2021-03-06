/**
 * @file Game.h
 * @brief このクラスはメインウィンドウズ作成やオブジェクトの作成などを行う
 * @author Kan
 * @date 2019/3/2
 */
#pragma once
#include <SDL.h>
#include<iostream>
#include<vector>
#include<unordered_map>

class Game
{
public:
	//Constructor
	Game();
	//Initialize 
	bool Initialize();
	//Game Loop
	void GameLoop();
	//Shut down windows
	void ShutDown();
	//Add Actor Function
	void AddActor(class Actor* actor);
	//Remove Actor Function
	void RemoveActor(class Actor* actor);
	//Add sprite Function
	void AddSprite(class SpriteComponent* spr);
	//Remove Sprite Function
	void RemoveSprite(class SpriteComponent* spr);
	//テキスチャーを取得
	SDL_Texture* GetTexture(const std::string& filename);
private:
	//インプット処理
	void ProcessInput();
	//ゲーム更新処理
	void UpdateGame();
	//アウトプット処理
	void GenerateOutput();
	//データ処理
	void LoadData();
	void UnloadData();
	//Texture 
	std::unordered_map <std::string, SDL_Texture*> Texture;
	//ベクトル型でクラスのにメンバーを追加
	std::vector<class Actor*> actor;
	std::vector<class Actor*> pendingActor;
	std::vector<class SpriteComponent*> sprites;
	//Use this function to create window
	//この関数を使ってウィンドウを生成
	SDL_Window* m_Window;
	//A structure that contain a rendering state
	SDL_Renderer* m_Renderer;
	//Time since start
	Uint32 m_ticksCount;
	//Check if game is running
	bool m_IsRunning;
	//Check if Actor is updating
	bool m_UpdatingActor;
	//Class player
	class Slime* slime;
};