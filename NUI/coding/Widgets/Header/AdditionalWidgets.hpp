#ifndef ADD
#define ADD
#include "Widget.hpp"

class StateManager;
class Level;

class TextWidget : public Widget
{
public:
   Text text;
   Font font;
   TextWidget(string _text, int fontSize, string _font, Vector2f _LocalPosition, Vector2i _TextOrigin);
   void setText(string);
   void setFont(string);
   void setFontSize(int);
   void display(RenderWindow&) override;

   void updateBounds() override;
};


// class ButtonWidget : public Widget
// {
//    TextWidget* textWidget;
   
// };

#endif