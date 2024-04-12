// #include "TextInputWidget.hpp"
// #include "EquaitionWidget.hpp"
// #include "StateManager.hpp"

// // TextInputWidget::TextInputWidget(Level* level_I, StateManager* manager_I) : Widget(level_I, manager_I)
// // {
// //    originSnapLocation = Vector2i(0, 1);
// // }

// void TextInputWidget::addChar(char input)
// {

//    if(contentString.size() < MaxCharacters)
//    {
//       contentString.push_back(input);
//       setText(contentString);
      
//    }
// }

// void TextInputWidget::removeChar()
// {
//    if(contentString.size() > 0)
//    {
//       contentString.pop_back();
//       setText(contentString);
//    }
// }

// void TextInputWidget::display(RenderWindow& win)
// {
//    Widget::display(win);
//    if(contentString.size() == MaxCharacters)
//    {
//       ParentEquationWidget->checkResponse(std::stoi(contentString));
//    }
// }