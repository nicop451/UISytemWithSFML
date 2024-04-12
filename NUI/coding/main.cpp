#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "math.hpp"

#include <GeneralFunctions.hpp>
// #include "Widget.hpp"
// #include "TimerWidget.hpp"
#include "StateManager.hpp"

#include <iomanip>

using namespace sf;

int main ()
{
   // Window Dimensions
   unsigned int winWidth = 1920; unsigned int CENTERX = winWidth/2;
   unsigned int winHeight = 1080; unsigned int CENTERY = winHeight/2;

   // Window Init
   RenderWindow win(VideoMode::getDesktopMode(), "Nico's Simulation", Style::Fullscreen);
   win.setFramerateLimit(500);

   // CLOCKS AND TIME VARIABLES **************************
   sf::Clock clock;
   float deltaTime;
   float timeMultiplier = 14;

   sf::Clock fpsUpdateTickClock;
   float fpsUpdateTimeValue;

   Clock elapsedClock;
   float elapsedTime;
   /**/

   // FPS DISPLAY VARIABLES *******************************
   sf::Font font;
   font.loadFromFile("C:\\SFML_fonts\\Kanit-Regular.ttf");

   sf::Text fpsText;
   fpsText.setFont(font);
   fpsText.setFillColor(Color::Green);
   fpsText.setPosition(Vector2f(winWidth * 0.93, 10));
   /**/

   int currInterface = 0;

   StateManager stateManager;

   int keycodes[11] = {26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};



   // Program Loop
   while(win.isOpen())
   {
      // Closes window and polls events
      Event event;
      while(win.pollEvent(event))
      {
         if (event.type == Event::Closed)
         {
            win.close();
         }
         if (event.type == Event::KeyPressed) 
         {
            if (event.key.code == Keyboard::Escape)
            {
               win.close();
            }
         }
         stateManager.inputCheck(event);
      }

      elapsedTime = elapsedClock.getElapsedTime().asSeconds() * 1000;

      // FPS Update Code ************************************
      // deltaTime = clock.restart().asSeconds();
      // int fps = 1/deltaTime;
      
      // if(fpsUpdateTickClock.getElapsedTime().asSeconds() > 0.2)
      // {
      //    if (fps < 60)
      //    {
      //       fpsText.setFillColor(Color(200, 90, 10));
      //    }
      //    else
      //    {
      //       fpsText.setFillColor(Color::Green);
      //    }
      //    fpsText.setString(std::to_string(int(fps)) + " fps");
      //    fpsUpdateTickClock.restart();
      // }
      /**/

      // Rendering-----------------------------------
      win.clear(Color(30, 30, 30));

      win.draw(fpsText);


      stateManager.update(win);

      win.display();
   }  //---------------------------------------------
   return 0;
}