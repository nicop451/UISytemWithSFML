#ifndef STATECLASS_HPP
#define STATECLASS_HPP
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Window/Mouse.hpp>
#include "Widget.hpp"
#include <cctype>
#include "AdditionalWidgets.hpp"
#include "math.hpp"
// #include "StateEnum.hpp"
#include <vector>

using namespace sf;
using std::vector;

class StateManager;

class Level
{
   public:
      vector<Widget*> widgets;
      //std::vector<ButtonWidget*> buttonWidgets;
      // EquationWidget* ActiveEquationWidget;
      
      Vector2f LevelGlobalPosition = Vector2f(0, 0);
      Vector2i mouseOldPos;
      Vector2i mousePos;
      bool isMousePressed = false;

      StateManager* manager;

      Level(StateManager* _manager);
      ~Level();

      virtual void loadLevel();
      virtual void checkInputs(Event event);
      virtual void readFile();
      virtual void displayLevel(RenderWindow& win);
};


class StartMenu : public Level
{
public:
   using Level::Level;
   void loadLevel() override;
};



// Handles loading widget and input 

// class StartLevel : public Level
// {
//    public:
//       //StartLevel(StateManager* manager_I);
//       using Level::Level;
//       void loadLevel() override;
// };

// class CountDownLevel : public Level
// {
//    public:
//       //CountDownLevel(StateManager* manager_I);
//       using Level::Level;
//       void loadLevel() override;
// };

// class GameLevel : public Level
// {
//    public:
//       int correctAnswered;
//       float GameTime;
//       using Level::Level;
//       void loadLevel() override;
// };

// class EndGameLevel : public Level
// {
//    public:
//       int correctAnswered;
//       float GameTime;
//       EndGameLevel(StateManager* manager_I, int correctAnswered_I, float GameTime_I);
//       void loadLevel() override;
// };


// class TimelineLevel : public Level
// {
//    public:
//       int correctAnswered;
//       TimelineWidget* timelineWidget;
//       using Level::Level;
//       void loadLevel() override;
//       void readFile() override;
// };

#endif

