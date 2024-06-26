#include "Scene.h"
#include<iostream>

using namespace std;

std::string Scene::ReturnSceneName()
{
    return m_sceneName;
}

void Scene::DrawScene()
{
    for (int xPos = 0; xPos < m_sceneHeight; xPos++) {
        for (int yPos = 0; yPos < m_sceneWidth; yPos++) {
            if (xPos == 0 || xPos == (m_sceneHeight - 1)) {
                DrawHorisontalBorders(yPos, m_sceneName);
                continue;
            }
            if (yPos == 0 || yPos == (m_sceneWidth - 1)) {
                DrawVerticalBorder();
                continue;
            }
            DrawContent(xPos, yPos);
        }
        std::cout << std::endl;
    }
}

Scene* Scene::HandleInput(char input)
{
    return NULL;
}

Scene* Scene::HandleStringInput(std::string input)
{
    return nullptr;
}

void Scene::DrawContent(int xPos, int yPos)
{
    bool retFlag;
    int lastXPos = DrawHeaderInformationPrompt(xPos, yPos, retFlag);
    if (retFlag) return;
    DrawMainPage(xPos, yPos, lastXPos, retFlag);
    if (retFlag) return;
    std::cout << " ";
}

void Scene::DrawMainPage(int xPos, int yPos, int startXPos, bool& retFlag)
{
}

int Scene::DrawHeaderInformationPrompt(int xPos, int yPos, bool& retFlag)
{
    retFlag = true;
    int yPromptStartPosition = 1;
    int yPromptEndPosition = 1;

    int xPromptStartPosition = 1;
    int xPromptEndPosition = m_sceneWidth;

    int maxPromptLenght = m_sceneWidth - 2;
    int linesOfPrompt = 1 + (m_informationPrompt.size() / maxPromptLenght + (((maxPromptLenght % m_informationPrompt.size()) > 0) ? 1 : 0));

    yPromptEndPosition = yPromptStartPosition + linesOfPrompt;

    if (m_informationPrompt.size() < maxPromptLenght) {
        xPromptStartPosition = (maxPromptLenght - m_informationPrompt.size()) / 2;
        xPromptEndPosition = (maxPromptLenght + m_informationPrompt.size()) / 2;
    }

    if (xPos > yPromptStartPosition && xPos < yPromptEndPosition && yPos >= xPromptStartPosition && yPos <= xPromptEndPosition) {
        short currentChar = yPos - xPromptStartPosition + ((xPos - yPromptStartPosition - 1) * maxPromptLenght) - 1;

        if (currentChar >= m_informationPrompt.size()) {
            std::cout << " ";
            return yPromptEndPosition + 1;
        }

        std::cout << m_informationPrompt.c_str()[currentChar];
        return yPromptEndPosition + 1;
    }

    if (xPos == yPromptStartPosition || xPos == yPromptEndPosition) {
        DrawHorisontalBorders(yPos, "Info");
        return yPromptEndPosition + 1;
    }
    if (xPos > yPromptStartPosition 
        && xPos < yPromptEndPosition 
        && yPos > xPromptStartPosition
        && yPos < xPromptEndPosition + 2) return yPromptEndPosition + 1;
    retFlag = false;

    return yPromptEndPosition + 1;
}

void Scene::DrawVerticalBorder()
{
    std::cout << "|";
}

void Scene::DrawHorisontalBorders(int yPos, std::string name)
{
    int startPositionOfName = (m_sceneWidth - (name.size() + 2)) / 2;
    int endPositionOfName = (m_sceneWidth + (name.size() + 2)) / 2;

    if (yPos == startPositionOfName){
        std::cout << "[" << name << "]";
        return;
    }

    if (yPos >= startPositionOfName && (yPos < endPositionOfName)) return;

    std::cout << "=";
}
