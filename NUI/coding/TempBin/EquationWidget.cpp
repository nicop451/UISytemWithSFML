// #include "EquaitionWidget.hpp"
// #include "StateManager.hpp"
// #include "LevelClass.hpp"


//       EquationWidget::EquationWidget(Level* level_I, StateManager* manager_I, int& correctAnsweredRef_I) :  Widget(level_I, manager_I), textBox(level_I, manager_I), correctAnsweredRef(correctAnsweredRef_I)
//       {
//          textBox.originSnapLocation = Vector2i(0, 1);
//          textBox.ParentEquationWidget = this;
//          textBox.setTextSize(80);
//          textBox.setText("");
//          textBox.contentString = "";
//          srand(time(NULL));
//          genEquation(equationType);
//       }

//       void EquationWidget::checkResponse(int response)
//       {
//          if(response == answer && textBox.contentString.size() > 1)
//          {
//             text.setFillColor(Color::White);
//             textBox.contentString.clear();
//             textBox.setText(textBox.contentString);
//             genEquation(equationType);
//             correctAnsweredRef++;
//          }
//          else
//          {
//             text.setFillColor(Color::Red);
//             textBox.contentString.clear();
//             textBox.text.setText(textBox.contentString);
//          }
//       }

// void EquationWidget::display(RenderWindow& win)
//       {
//          Widget::display(win); 
//          textBox.setGlobalPos(Vector2f(10 + text.getPosition().x + BoundBox.width / 2, text.getPosition().y));
//          textBox.display(win);
//       }

// void EquationWidget::genEquation(int type)
//          {
//             int num1;
//             int num2;
//             int fac1;
//             int randType = rand() % 3;
//             int smallNum_lower = 2;
//             int smallNum_higher = 3;
//             int largeNum_lower = 12;
//             int largeNum_higher = 20;
//             string textAnswer;

//             switch(0)
//             {
//                case 0:
//                   num1 = rand() % ((smallNum_higher + 1) - smallNum_lower) + smallNum_lower;
//                   num2 = rand() % ((largeNum_higher + 1) - largeNum_lower) + largeNum_lower;
//                   answer = num1 * num2;
//                   if(rand() % 2 == 1)
//                   {
//                      textAnswer = std::to_string(num1) + " x " + std::to_string(num2) + " = ";
//                   }
//                   else
//                   {
//                      textAnswer = std::to_string(num2) + " x " + std::to_string(num1) + " = ";
//                   }
//                   break;
//                case 1:
//                   fac1 = rand() % 10 + 4;
//                   num2 = rand() % 10 + 4;
//                   num1 = fac1 * num2;
//                   answer = num1 / num2;
//                   textAnswer = std::to_string(num1) + " / " + std::to_string(num2) + " = ";
//                   break;
//                case 2:
//                   num1 = rand() % 120 + 5;
//                   num2 = rand() % 100 + 5;
//                   answer = num1 + num2;
//                   textAnswer = std::to_string(num1) + " + " + std::to_string(num2) + " = ";
//                   break;
//                case 3:
//                   num1 = rand() % 120 + 5;
//                   num2 = rand() % 100 + 5;
//                   answer = num1 - num2;
//                   textAnswer = std::to_string(num1) + " - " + std::to_string(num2) + " = ";
//                   break;
//             }
//             setText(textAnswer);

//             textBox.MaxCharacters = std::to_string(answer).length();
//          }
