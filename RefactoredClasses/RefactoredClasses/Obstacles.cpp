#include "Obstacles.hpp"



Obstacles::Obstacles()
{
   obstacleCoords = { { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
   { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } } };

   _reborn = 0;
}

void Obstacles::moveObstacle()
{

   _isOnRoad = 1;

   if (obstacleCoords[0][0][0] == roadLenght) {
      _reborn = 0;
   }

   if (_reborn) {

      for (int i = 0; i < obstacleCoords.size(); i++) {
         for (int j = 0; j < obstacleCoords[0].size(); j++) {
            for (int o = 0; o < obstacleCoords[0][0].size(); o++) {

               if ((i == 0 && j == (obstacleCoords[0].size() - 1)) ||
                  (i == 0 && o == 0 && j < (obstacleCoords[0].size() - 1)) ||
                   (i == 0 && o == (obstacleCoords[0][0].size() - 1) && j < (obstacleCoords[0].size() - 1))) {

                  obstacleCoords[i][j][o] += 1;

               }
            }
         }
      }

   }
   else {

      int rnd = rand() % 9;

      for (int i = 0; i < obstacleCoords.size(); i++) {
         for (int j = 0; j < obstacleCoords[0].size(); j++) {
            for (int o = 0; o < obstacleCoords[0][0].size(); o++) {

               if (i == 0 && j == (obstacleCoords[0].size() - 1)) { //нижняя часть машинки из траффика по строкам
                  obstacleCoords[i][j][o] = -1;
               }
               if (i == 1 && j == (obstacleCoords[0].size() - 1)) { //нижняя часть машинки из траффика по столбцам
                  obstacleCoords[i][j][o] = 13 + o + rnd;
               }
               if (i == 0 && o == 0 && j < (obstacleCoords[0].size() - 1)) { //левая часть машинки из траффика по строкам не считая одного пикселя нижней части
                  obstacleCoords[i][j][o] = -(obstacleCoords[0].size() - j);
               }
               if (i == 1 && o == 0 && j < (obstacleCoords[0].size() - 1)) { //левая часть машинки из траффика по стобцам не считая одного пикселя нижней части
                  obstacleCoords[i][j][o] = 13 + rnd;
               }
               if (i == 0 && o == (obstacleCoords[0][0].size() - 1) && j < (obstacleCoords[0].size() - 1)) { //правая часть машинки из траффика по строкам не считая одного пикселя нижней части
                  obstacleCoords[i][j][o] = -(obstacleCoords[0].size() - j);
               }
               if (i == 1 && o == (obstacleCoords[0][0].size() - 1) && j < (obstacleCoords[0].size() - 1)) { //правая часть машинки из траффика по столбцам не считая одного пикселя нижней части
                  obstacleCoords[i][j][o] = 13 + (obstacleCoords[0][0].size() - 1) + rnd;
               }

            }

         }
      }


      _reborn = 1;
   }
}
