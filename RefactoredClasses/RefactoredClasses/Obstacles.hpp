#ifndef  OBSTACLES_HPP
#define  OBSTACLES_HPP

#include <vector>
#include "CommonDefines.hpp"

using std::vector;

class Obstacles {
public:
   Obstacles();

   void moveObstacle();
   inline const vector<vector<vector<int>>>& getObstacle() const;
   inline const int& checkObstacle() const;

private:
   static const int roadLenght = ROAD_LENGHT;
   int _isOnRoad;
   int _reborn;
   vector<vector<vector<int>>> obstacleCoords;
};

#endif OBSTACLES_HPP

inline const int& Obstacles::checkObstacle() const
{
   return _isOnRoad;
}

inline const vector<vector<vector<int>>>& Obstacles::getObstacle() const
{
   return obstacleCoords;
}
