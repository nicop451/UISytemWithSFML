// #include "TimePlotWidget.hpp"
// #include "TimelineWidget.hpp"
// #include "TextWidget.hpp"
// #include "StateManager.hpp"


// TimePlotWidget::TimePlotWidget(int year_I, string eventText_I, Level* level_I, StateManager* manager_I) : Widget(level_I, manager_I), year(year_I), eventText(eventText_I)
// {
//    // Create Default Plots
//    YearTextWidget = new TextWidget(std::to_string(year), 15, level, manager);
//    EventTextWidget = new TextWidget(eventText, 15, level, manager);

//    // Create Plot Circle
//    plotShape.setRadius(7);
//    plotShape.setOrigin(Vector2f(plotShape.getRadius(), plotShape.getRadius()));
// }

// void TimePlotWidget::display(RenderWindow& win)
// {
//    Widget::display(win);

//    YearTextWidget->setGlobalPos(GlobalPosition + Vector2f(0, 50));
//    EventTextWidget->setGlobalPos(GlobalPosition + Vector2f(0, -50));

//    YearTextWidget->display(win);
//    EventTextWidget->display(win);

//    plotShape.setPosition(GlobalPosition + Vector2f(0, 0));
//    win.draw(plotShape);
// }