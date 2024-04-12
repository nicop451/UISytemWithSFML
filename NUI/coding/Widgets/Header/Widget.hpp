#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <SFML/Graphics.hpp>
#include <GeneralFunctions.hpp>
#include <vector>
#include <functional>
// #include "StateEnum.hpp"
// #include "WidgetParamsType.hpp"
// Forward Declaration of Neccesary Types
class StateManager;
class Level;
typedef std::function<void(StateManager*)> ManagerCallbackFunction;

using namespace sf;
using std::cout;
using std::string;
using std::vector;



class Widget
{
private:


public:

   // Widget Visuals
   CircleShape origin;
   // Text text;
   FloatRect BoundBox;
   RectangleShape BoundBoxShape;
   bool hidden;

   // Constants
   const unsigned int winWidth, winHeight;
   const unsigned int CENTERX, CENTERY;
   // Origin Location
   Vector2i originSnapLocation;

   // Widget Location Variables
   Vector2f LocalPosition;
   Vector2f GlobalPosition;

   // // References
   // Level* level;
   // StateManager* manager;

   // Sub Widget Elements
   vector<Widget*> subWidgets;


   Widget(Vector2f _LocalPosition);
   ~Widget();

   void setLocalPos(Vector2f newLocalPos);
   void setGlobalPos(Vector2f parentGlobalPosition);
   virtual void updateBounds();

   virtual void display(RenderWindow& win);
};

#endif
