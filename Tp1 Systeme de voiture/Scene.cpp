#include "Scene.h"
#include<iostream>

using namespace std;

std::string Scene::ReturnSceneName()
{
    return m_sceneName;
}

void Scene::DrawScene()
{
    for (int xPos = 0; xPos < m_sceneWidth; xPos++) {
        for (int yPos = 0; yPos < m_sceneHeight; yPos++) {
            if (xPos == 0 || xPos == (m_sceneWidth - 1)) {
                DrawHorisontalBorders(yPos, m_sceneName);
                continue;
            }
            if (yPos == 0 || yPos == (m_sceneHeight - 1)) {
                DrawVerticalBorder();
                continue;
            }
            DrawContent(xPos, yPos);
        }
        std::cout << std::endl;
    }
}

void Scene::DrawContent(int xPos, int yPos)
{
    bool retFlag;
    DrawInformationPrompt(xPos, yPos, retFlag);
    if (retFlag) return;
    
    std::cout << " ";
}

void Scene::DrawInformationPrompt(int xPos, int yPos, bool& retFlag)
{
    retFlag = true;
    int yPromptStartPosition = 1;
    int yPromptEndPosition = 1;

    int xPromptStartPosition = 1;
    int xPromptEndPosition = m_sceneHeight;

    int maxPromptLenght = m_sceneHeight - 2;
    int linesOfPrompt = 1 + (m_informationPrompt.size() / maxPromptLenght + (((maxPromptLenght % m_informationPrompt.size()) > 0) ? 1 : 0));

    yPromptEndPosition = yPromptStartPosition + linesOfPrompt;

    if (m_informationPrompt.size() < maxPromptLenght) {
        xPromptStartPosition = (maxPromptLenght - m_informationPrompt.size()) / 2;
        xPromptEndPosition = (maxPromptLenght + m_informationPrompt.size()) / 2;
    }

    if (xPos > yPromptStartPosition && xPos < yPromptEndPosition && yPos > xPromptStartPosition && yPos < xPromptEndPosition) {
        short currentChar = yPos - 2 + ((xPos - yPromptStartPosition - 1) * maxPromptLenght);

        if (currentChar >= m_informationPrompt.size()) {
            cout << " ";
            return;
        }

        std::cout << m_informationPrompt.c_str()[currentChar];
        return;
    }

    if (xPos == yPromptStartPosition || xPos == yPromptEndPosition) {
        DrawHorisontalBorders(yPos, "Info");
        return;
    }
    if (xPos > yPromptStartPosition && xPos < yPromptEndPosition && yPos > xPromptStartPosition && yPos < xPromptEndPosition + 2) return;
    retFlag = false;
}

void Scene::DrawVerticalBorder()
{
    std::cout << "|";
}

void Scene::DrawHorisontalBorders(int yPos, std::string name)
{
    int startPositionOfName = (m_sceneHeight - (name.size() + 2)) / 2;
    int endPositionOfName = (m_sceneHeight + (name.size() + 2)) / 2;

    //Print Scene Name in the middle of the screen
    if (yPos == startPositionOfName){
        std::cout << "[" << name << "]";
        return;
    }

    //Skip chars on the pposition of scene name
    if (yPos >= startPositionOfName && (yPos < endPositionOfName)) return;

    std::cout << "=";
}
