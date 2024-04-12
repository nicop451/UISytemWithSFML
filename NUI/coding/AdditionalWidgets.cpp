#include "AdditionalWidgets.hpp"

TextWidget::TextWidget(string _text, int _fontSize, string _font, Vector2f _LocalPosition = Vector2f(0, 0), Vector2i _TextOrigin = Vector2i(1, 1)) : Widget(_LocalPosition)
{
   originSnapLocation = _TextOrigin;
   setText(_text);
   setFont(_font);
   setFontSize(_fontSize);
}

void TextWidget::setText(string newText)
{
   text.setString(newText);
}

void TextWidget::setFont(string newFontPath)
{
   font.loadFromFile("C:\\SFML_fonts\\HandWrittenMentalMath\\Roboto_Slab\\static\\RobotoSlab-Regular.ttf");
   text.setFont(font);
}

void TextWidget::setFontSize(int newFontSize)
{
   text.setCharacterSize(newFontSize);
}

void TextWidget::updateBounds()
{
   BoundBox = text.getLocalBounds();

   //BoundBoxShape.setPosition(GlobalPosition);
   //text.setOrigin((BoundBox.width/2) * originSnapLocation.x, (BoundBox.height/2) * originSnapLocation.y);

   cout << BoundBox.left << "\n";
   //BoundBoxShape.setOrigin((BoundBox.width/2) * originSnapLocation.x, (BoundBox.height/2) * originSnapLocation.y);
   BoundBoxShape.setPosition(GlobalPosition);
 
   //Widget::updateBounds();
}

void TextWidget::display(RenderWindow& win)
{
   Widget::display(win);
   updateBounds();
   text.setOrigin(0,0);
   text.setPosition(GlobalPosition);
   win.draw(BoundBoxShape);
   win.draw(text);
}



