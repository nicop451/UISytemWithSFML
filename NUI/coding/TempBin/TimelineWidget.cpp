// #include "TimelineWidget.hpp"
// #include "TimePlotWidget.hpp"


// TimelineWidget::TimelineWidget(int startTime_I, int endTime_I, Level* level_I, StateManager* manager_I) : Widget(level_I, manager_I), startTime(startTime_I), endTime(endTime_I)
// {

//    // Timeline Rectangle Line
//    timelineRect = RectangleShape(Vector2f(1500, 4));
//    timelineRect.setOrigin(Vector2f(timelineRect.getSize().x / 2, timelineRect.getSize().y / 2));
//    timelineRect.setFillColor(Color(255, 255, 255));
//    timelineRect.setPosition(Vector2f(0, 0));

//    // Adding One Plot To TimeLine
//    TimePlotWidget* startPlot = new TimePlotWidget(startTime, "", level, manager);

//    TimePlotWidget* endPlot = new TimePlotWidget(endTime, "", level, manager);
      
//    // newPlot->setLocalPos(Vector2f(0, 0));


//    plots.push_back(startPlot);
//    plots.push_back(endPlot);
// }

// void TimelineWidget::addPlot(int year, string newEventText)
// {
//    TimePlotWidget* newPlot = new TimePlotWidget(year, newEventText, level, manager);
//    // newPlot->timelineWidget = this;
//    newPlot->year = year;
//    newPlot->eventText = newEventText;
//    newPlot->init();

//    plots.push_back(newPlot);
// }

// void TimelineWidget::display(RenderWindow& win)
// {
//    Widget::display(win);

//    timelineRect.setPosition(Vector2f(GlobalPosition));

//    FloatRect timelineBounds = timelineRect.getLocalBounds();
//    startMark.setPosition(Vector2f(timelineRect.getPosition().x - timelineBounds.width / 2, timelineRect.getPosition().y));
//    endMark.setPosition(Vector2f(timelineRect.getPosition().x + timelineBounds.width / 2, timelineRect.getPosition().y));
//    win.draw(startMark);
//    win.draw(endMark);
//    win.draw(timelineRect);

//    for(TimePlotWidget* plot:plots)
//    {
//       // Calc Plot Position
//       float yearDiff = endTime - startTime;
//       float relativePercentLocation = (plot->year - startTime) / yearDiff;
//       float actualDiff = endMark.getPosition().x - startMark.getPosition().x;
//       float xPos  = startMark.getPosition().x + (actualDiff * relativePercentLocation);
//       plot->GlobalPosition = Vector2f(xPos, GlobalPosition.y);

//       plot->display(win);
//    }
// }