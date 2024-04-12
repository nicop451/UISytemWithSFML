#include "StateManager.hpp"

void openLevelFunc(StateManager* manager)
{
   std::cout << "Button Function Called\n";
   if(manager->currState == State::StartMenu)
   {
      manager->loadState(State::Timeline);
   }
   else if(manager->currState == State::EndGameScreen)
   {
      manager->loadState(State::StartMenu);
   }
   else if(manager->currState == State::Game)
   {
      manager->loadState(State::StartMenu);
   }
}
