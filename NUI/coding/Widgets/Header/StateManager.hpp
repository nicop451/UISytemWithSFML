#ifndef STATEMANGER_HPP
#define STATEMANGER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Widget.hpp"
// #include "TimerWidget.hpp"
// #include "ButtonWidget.hpp"
// #include "EquaitionWidget.hpp"
// #include "TextInputWidget.hpp"
// #include "ButtonFuncs.hpp"
#include "StateEnum.hpp"
#include <vector>

class Level;

class StateManager
{
   public:
      State currState;

      Level* currLevel;
      
      unsigned int winWidth;
      unsigned int CENTERX;
      unsigned int winHeight;
      unsigned int CENTERY;

      float maxStateTime;
      Clock elapsedStateTimeClock;
      float elapsedStateTime;
      float timeLeft;
      
      StateManager();
      ~StateManager();

      void loadState(State newState);
      void inputCheck(Event event);
      void update(RenderWindow& win);

   
      void initState(State newState); // This is where different UI and Program States are initialized and customized
      void deletePointerArrayMem();
};

#endif