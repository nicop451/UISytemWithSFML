// #include "TimerWidget.hpp"
// #include "StateManager.hpp"

// // TimerWidget::TimerWidget(Level* level_I, StateManager* manager_I) : Widget(level, manager_I)
// // {
// //    elapsedTimer.restart();
// // }

// void TimerWidget::display(RenderWindow& win)
// {
//    Widget::display(win);
//    elapsedTime = elapsedTimer.getElapsedTime().asSeconds();


//    timeLeft = startTime - elapsedTime;
//    setText(TruncateDecimals(std::to_string(timeLeft), -1));

//    if(timeLeft <= 1)
//    {
//       if(manager->currState == State::CountDown)
//       {
//          manager->loadState(State::Game);
//       }
//       else if(manager->currState == State::Game)
//       {
//          manager->loadState(State::EndGameScreen);
//       }
//    }
// }