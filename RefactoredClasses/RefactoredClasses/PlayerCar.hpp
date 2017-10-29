#ifndef  PLAYERCAR_HPP
#define  PLAYERCAR_HPP

#include "CommonDefines.hpp"
#include <vector>

using std::vector;

class PlayerCar {
public:
   /*EXTRACT TO CPP AS IN OTHER CLASSES*/
   PlayerCar() {

      coords = { { 14,16 },{ 14,19 },{ 18,16 },{ 18,19 } }; //north-west, north-east, south-west, south-east

      speed = 1000;
      isAlive = 1;
   };

   void turnRight()
   {
      if (coords[1][1] < roadWidth - 1) {
         coords[0][1] += 1;
         coords[1][1] += 1;
         coords[2][1] += 1;
         coords[3][1] += 1;
      }
   }

   void turnLeft()
   {
      if (coords[0][1] > 0) {
         coords[0][1] -= 1;
         coords[1][1] -= 1;
         coords[2][1] -= 1;
         coords[3][1] -= 1;
      }
   }

   /*INLINE AS IN OTHER CLASSES */
   //Уменьшает время паузы
   void useAcceleration() {
      if (speed > 150) speed -= 100;
   }
   //Увеличивает время паузы
   void useBrake() {
      if (speed < 950) speed += 100;
   }
   const vector<vector<int>>& getCar() const
   {
      return coords;
   }

   void setBadCondition() {
      isAlive = 0;
   }

   const int getCondition() {
      return isAlive;
   }

   const int getSpeed() {
      return speed;
   }

private:
   static const int carLenght = 5;
   static const int carWidth = 4;

   static const int roadLenght = ROAD_LENGHT;
   static const int roadWidth = ROAD_WIDTH;


   int car[carLenght][carWidth]; // заменить на <array> или <vector>
   std::vector <vector <int> > coords;
   int isAlive;
   int speed;
};

#endif PLAYERCAR_HPP
