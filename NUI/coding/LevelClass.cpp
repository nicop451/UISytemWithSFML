#include "LevelClass.hpp"
#include "StateManager.hpp"


Level::Level(StateManager* manager_I) : manager(manager_I)
{
   LevelGlobalPosition = Vector2f(manager->CENTERX, manager->CENTERY);
}

Level::~Level() // When Level Is Destructu
{
   widgets.clear();
   //buttonWidgets.clear();
   for(Widget* widget:widgets)
   {
      delete widget;
   }
   // for(ButtonWidget* button:buttonWidgets)
   // {
   //    delete button;
   // }
}


void Level::checkInputs(Event event)
{
   int keycodes[11] = {26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
   

   // Key input
   if(event.type == Event::KeyPressed) // TextBox inputs
   {
         int keycode = event.key.code;
         for(int i{0}; i <= 10; i++) // Handles 1 - 10 number inputs
         {
            if(keycode == keycodes[i])
            {
               //ActiveEquationWidget->textBox.addChar(std::to_string(i)[0]);
            }
         }
      
         if(keycode == Keyboard::Hyphen) // Negative Number Character
         {
            //ActiveEquationWidget->textBox.addChar('-');
         }
         if(keycode == Keyboard::BackSpace) // Delete Character
         {
            //ActiveEquationWidget->textBox.removeChar();
         }
   }
   
   // Sets Condition If Mouse Is Held Down
   if(event.type == Event::MouseButtonPressed)
   {
      isMousePressed = true;
   }
   else if (event.type == Event::MouseButtonReleased)
   {
      isMousePressed = false;
   }

   // Button and Mouse Clicks
   if(event.type == Event::MouseButtonPressed) 
   {
      mousePos = Mouse::getPosition();
      // for(ButtonWidget* button:buttonWidgets)
      // {
      //    Vector2f mouseClickPos = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);
      //       std::vector<float> bounds = {button->text.getPosition().x - button->BoundBox.width / 2, button->text.getPosition().x + button->BoundBox.width / 2, button->text.getPosition().y - button->BoundBox.height / 2, button->text.getPosition().y + button->BoundBox.height / 2};
      //       bool isOverlappingButton = mouseClickPos.x > bounds[0] && mouseClickPos.x < bounds[1] && mouseClickPos.y > bounds[2] && mouseClickPos.y < bounds[3];

      //       if(isOverlappingButton)
      //       {
      //          std::cout << "Button Press Input\n";
      //          button->pressed();
      //       }
      // }
   }

   // Screen Dragging Functionality
   if(isMousePressed)
   {
      mousePos = Mouse::getPosition();
      Vector2i MousePosDiff = mousePos - mouseOldPos;
      LevelGlobalPosition = Vector2f(LevelGlobalPosition.x + MousePosDiff.x, LevelGlobalPosition.y + MousePosDiff.y);
   }
   mouseOldPos = Mouse::getPosition(); // Update Old Mouse Position
}

void Level::displayLevel(RenderWindow& win)
{

   for(Widget* widget:widgets) // display all widgets in this level
   {  
      widget->setGlobalPos(LevelGlobalPosition);
      widget->display(win);
   }
}

void Level::loadLevel() {/*To be customized in each derived class*/}
void Level::readFile() {/*To be customized in each class depending on how file should be read*/}

// Custom Levels ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void StartMenu::loadLevel()
{
   string tempFontPath = "C:\\SFML_fonts\\HandWrittenMentalMath\\Roboto_Slab\\static\\RobotoSlab-Regular.ttf";

   TextWidget* IntroTextWidget = new TextWidget("X", 50, tempFontPath, Vector2f(0, 0), Vector2i(0, 0));
   //TextWidget* IntroTextWidget2 = new TextWidget("Maatin", 70, tempFontPath, Vector2f(0, 0), Vector2i(0, 0));

   widgets.push_back(IntroTextWidget);
   //widgets.push_back(IntroTextWidget2);
}


//StartLevel::StartLevel(StateManager* manager_I) : Level(manager_I) {}

// void StartLevel::loadLevel()
// {
//    //Create Start Button
//   cout << "Load Level ";
   
//    ButtonWidget* StartButton = new ButtonWidget(this, manager);
       
//    StartButton->buttonFunction = openLevelFunc;
 
//    StartButton->setLocalPos(Vector2f(0, 0));
   
//    StartButton->setText("Start");
//    StartButton->setTextSize(100);
//    widgets.push_back(StartButton); buttonWidgets.push_back(StartButton);
// }

// void CountDownLevel::loadLevel()
// {
//    TimerWidget* CountDownWidget = new TimerWidget(this, manager);
//    CountDownWidget->elapsedTimer.restart();
//    CountDownWidget->startTime = 4;
//    CountDownWidget->setLocalPos(Vector2f(0, 0));
//    CountDownWidget->setTextSize(200);
//    widgets.push_back(CountDownWidget);
// }

// void GameLevel::loadLevel()
// {
//    // Equation Widget
//    ActiveEquationWidget = new EquationWidget(this, manager, correctAnswered);
//    ActiveEquationWidget->correctAnsweredRef = correctAnswered;
//    ActiveEquationWidget->setLocalPos(Vector2f(0, 0));
//    ActiveEquationWidget->setTextSize(80);
//    widgets.push_back(ActiveEquationWidget);

//    // Restart Button Widget
//    ButtonWidget* RestartButton = new ButtonWidget(this, manager);
//    RestartButton->buttonFunction = openLevelFunc;
//    RestartButton->setLocalPos(Vector2f(-850, -440));
//    RestartButton->setTextSize(60);
//    RestartButton->setText("<<<");
//    widgets.push_back(RestartButton); buttonWidgets.push_back(RestartButton);
   
//    // Timer Widget
//    TimerWidget* TimeLeftWidget = new TimerWidget(this, manager);
//    TimeLeftWidget->elapsedTimer.restart();
//    TimeLeftWidget->startTime = 15;
//    TimeLeftWidget->setLocalPos(Vector2f(0, -440));
//    TimeLeftWidget->setText("");
//    TimeLeftWidget->setTextSize(80);
//    widgets.push_back(TimeLeftWidget);
// }

// EndGameLevel::EndGameLevel(StateManager* manager_I, int correctAnswered_I, float GameTime_I) : Level(manager_I), correctAnswered(correctAnswered_I), GameTime(GameTime_I) {}

// void EndGameLevel::loadLevel()
// {
//    Widget* ProbMinWidget = new Widget(this, manager);
//    ProbMinWidget->setLocalPos(Vector2f(0, 0));
//    ProbMinWidget->setText(TruncateDecimals(std::to_string(correctAnswered / (GameTime/60)), 1) + " p/m");
//    ProbMinWidget->setTextSize(85);
//    widgets.push_back(ProbMinWidget);

//    // Play Again Button
//    ButtonWidget* PlayAgainButton = new ButtonWidget(this, manager);
//    PlayAgainButton->buttonFunction = openLevelFunc;
//    PlayAgainButton->setLocalPos(Vector2f(0, 100));
//    PlayAgainButton->setText("Play Again");
//    PlayAgainButton->setTextSize(70);
//    widgets.push_back(PlayAgainButton); buttonWidgets.push_back(PlayAgainButton);
// }

// void TimelineLevel::loadLevel()
// {
//    timelineWidget = new TimelineWidget(1700, 1900, this, manager);
//    timelineWidget->setLocalPos(Vector2f(0, 0));

//    widgets.push_back(timelineWidget);
//    readFile();
// }

// void TimelineLevel::readFile()
// {
//    string line;
//    std::ifstream inputFile("coding\\TimelinePlotsData.txt");

//    if(!inputFile.is_open())
//    {
//       cout << " Error Opening File ";
//       return;
//    }

//    while(std::getline(inputFile, line))
//    {
//       string eventText;
//       string yearString;
//       for(int i = 0; i < line.size(); i++)
//       {
//          if(std::isdigit(line[i]) == 0 && line[i] != '-')
//          {
//             eventText.push_back(line[i]);
//          }
//          if(std::isdigit(line[i]) > 0)
//          {
//             yearString.push_back(line[i]);
//          }
//       }
//       cout << yearString;
//       timelineWidget->addPlot(std::stoi(yearString), eventText);
//    }
//    inputFile.close();
// }