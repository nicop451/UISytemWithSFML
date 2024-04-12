#include "StateManager.hpp"
#include "LevelClass.hpp"

//#include "ButtonFuncs.hpp"

StateManager::StateManager() : currState(State::StartMenu)
{
   winWidth = 1920;
   winHeight = 1080;
   CENTERX = winWidth / 2;
   CENTERY = winHeight / 2;

   maxStateTime = 60;

   currState = State::Timeline;
   loadState(currState);
}

StateManager::~StateManager()
{
   deletePointerArrayMem();
}


// Check Inputs for current Level
void StateManager::inputCheck(Event event)
{
   currLevel->checkInputs(event);
}

// Update and Display
void StateManager::update(RenderWindow& win)
{  
   currLevel->displayLevel(win);
}

// Destructor
void StateManager::deletePointerArrayMem()
{}


// State Control Functions ----------------------------------------

void StateManager::loadState(State newState)
{
   // widgets.clear();
   // buttonWidgets.clear();
   deletePointerArrayMem();
   elapsedStateTimeClock.restart();
   initState(newState);
}

void StateManager::initState(State newState) // This is where different UI and Program States are initialized and customized
{
   currState = newState;

   switch(newState)
   {
      // case State::StartMenu:
      //    std::cout << " Create Start Menu Level ";
      //    currLevel = new StartLevel(this);
      //    break;

      // case State::CountDown:
      //    currLevel = new CountDownLevel(this);
      //    break;

      // case State::Game:
      //    currLevel = new GameLevel(this);
      //    break;

      case State::Timeline:
         currLevel = new StartMenu(this);
         break;
         
      // case State::EndGameScreen:
      //    // Cast to Level to pass variables
      //    GameLevel* gameLevel = dynamic_cast<GameLevel*>(currLevel);
      //    int correctAnswered = gameLevel->correctAnswered;
      //    float GameTime = gameLevel->GameTime;
      //    currLevel = new EndGameLevel(this, correctAnswered, GameTime);
      //    break;

   }
   currLevel->loadLevel(); // Creates Widget
   // currLevel->initLevel(); // Runs Initialization Procedure for each widget for unique contructors
}