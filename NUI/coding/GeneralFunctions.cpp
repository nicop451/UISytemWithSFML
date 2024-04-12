#include "GeneralFunctions.hpp"


Color Rainbow(float length, float maxLength)
{
    float i = (length * 255 / maxLength);
    float r = round(sin(0.024 * i + 0) * 127 + 128);
    float g = round(sin(0.024 * i + 2) * 127 + 128);
    float b = round(sin(0.024 * i + 4) * 180 + 200);
    return Color(r, g, b);
}

std::string TruncateDecimals(std::string num, int decimalPlaces)
{
   std::string output;
   int decimalIndex = -1;
   for(int i = 0; i < num.size(); i++)
   {
      char charcter = num[i];
      if(charcter == '.')
      {
         decimalIndex = i;
      }
   }
   for(int i = 0; i < decimalIndex + decimalPlaces + 1; i++)
   {
      output.push_back(num[i]);
   }
   return output;
}