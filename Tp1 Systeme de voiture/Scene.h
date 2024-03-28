#pragma once
#include<string>


class Scene
{
protected:
	int m_sceneWidth = 25;
	int m_sceneHeight = 100;

	std::string m_sceneName = "Default Scene Name";
	std::string m_informationPrompt = "Please write 'M' or 'm' to go to main menu.";

public:
	std::string ReturnSceneName();
	void DrawScene();
	virtual Scene* HandleInput(char input);
private:
	void DrawContent(int xPos, int yPos);
	void DrawInformationPrompt(int xPos, int yPos, bool& retFlag);
	void DrawVerticalBorder();
	void DrawHorisontalBorders(int yPos, std::string name);
};

