#include "Widget.hpp"
#include "StateManager.hpp"
#include "LevelClass.hpp"

Widget::Widget(Vector2f _LocalPosition = Vector2f(0, 0)) : winWidth(1920), winHeight(1080), CENTERX(1920/2), CENTERY(1080/2)
{
   // Init Member Variables
   originSnapLocation = Vector2i(1, 1);
   LocalPosition = _LocalPosition;

   // Visual Stuff
   BoundBoxShape.setSize(Vector2f(100, 100)); 
   BoundBoxShape.setFillColor(Color(255, 255, 255, 50));
   // Origin
   origin.setRadius(4);
   origin.setOrigin(Vector2f(origin.getRadius(), origin.getRadius()));
   origin.setFillColor(Color::Green);
   origin.setPosition(GlobalPosition);
}

Widget::~Widget()
{
   subWidgets.clear();
   for(Widget* subWidget:subWidgets)
   {
      delete subWidget;
   }
}


void Widget::setLocalPos(Vector2f newLocalPos)
{
   LocalPosition = newLocalPos;
}

void Widget::setGlobalPos(Vector2f parentGlobalPos)
{
   GlobalPosition = parentGlobalPos + LocalPosition;
}

void Widget::updateBounds()
{
   BoundBoxShape.setPosition(GlobalPosition);
   BoundBoxShape.setSize(Vector2f(BoundBox.width, BoundBox.height));
}

void Widget::display(RenderWindow& win)
{

   updateBounds();
   origin.setPosition(GlobalPosition);
   win.draw(origin);
   for(Widget* subWidget:subWidgets)
   {
      subWidget->setGlobalPos(this->GlobalPosition);
      subWidget->display(win);
   }
}