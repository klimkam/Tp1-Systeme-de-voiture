#pragma once
#include<string>


class Scene
{
	int m_sceneWidth = 25;
	int m_sceneHeight = 100;

	std::string m_sceneName = "Default Scene Name";
	std::string m_informationPrompt = " Some Default Useful Information 1 Some Default Useful Information 2 Some Default Useful Information 3 Some Default Useful Information 4 Some Default Useful Information 5 Some Default Useful Information 6 Some Default Useful Information 7 Some Default Useful Information 8";

public:
	std::string ReturnSceneName();
	void DrawScene();

private:
	void DrawContent(int xPos, int yPos);
	void DrawInformationPrompt(int xPos, int yPos, bool& retFlag);
	void DrawVerticalBorder();
	void DrawHorisontalBorders(int yPos, std::string name);
};

