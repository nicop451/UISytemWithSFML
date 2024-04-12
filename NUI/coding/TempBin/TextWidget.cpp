// #include "TextWidget.hpp"

// TextWidget::TextWidget(string text_I, int textSize_I, Level* level_I, StateManager* manager_I) : Widget(level_I, manager_I)
// {
//    font.loadFromFile("C:\\SFML_fonts\\HandWrittenMentalMath\\Roboto_Slab\\static\\RobotoSlab-Regular.ttf");
//    setText(text_I);
//    setTextSize(textSize_I);
//    text.setFont(font);
//    BoundBox = text.getLocalBounds();
//    text.setOrigin(BoundBox.left + BoundBox.width / 2, BoundBox.top + BoundBox.height / 2);
// }

// void TextWidget::setText(string newText)
// {
//    text.setString(newText);
// }
// void TextWidget::setTextColor(Color newColor)
// {
//    text.setFillColor(newColor);
// }
// void TextWidget::setTextSize(int newTextSize)
// {
//    text.setCharacterSize(newTextSize);
// }

// void TextWidget::display(RenderWindow& win)
// {
//    Widget::display(win); // Just in case I want to add something to all widgets
   
//    // Bounding Box Handling
//    BoundBox = text.getLocalBounds();
//    text.setOrigin(BoundBox.left + BoundBox.width / 2, BoundBox.top + BoundBox.height / 2);
//    BoundBoxShape.setSize(Vector2f(BoundBox.width, BoundBox.height));
//    BoundBoxShape.setPosition(GlobalPosition);

//    text.setPosition(GlobalPosition);
//    //win.draw(BoundBoxShape);
//    win.draw(text);
// }