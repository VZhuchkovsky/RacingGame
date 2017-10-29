#ifndef TRAFFIC_HPP
#define  TRAFFIC_HPP

#include <vector>
#include "CommonDefines.hpp"

using std::vector;

class Traffic {
public:
   Traffic(); // TODO init members Here

   void moveTrafficVehicle(lane chosenLane);
   inline const vector<vector<vector<int>>>& getTrafficVehicle() const;
   inline const int& checkIsOnRoad() const;
private:
                                              // DO YOU REALLY NEED another static member???
   static const int roadLenght = ROAD_LENGHT; //TODO member variables names as mMemberVariable
   int _isOnRoad = 0;
   int _reborn;
   vector<vector<std::vector<int>>> vehicleCoords;
};

inline const vector<vector<vector<int>>>& Traffic::getTrafficVehicle() const
{
   return vehicleCoords;
}

inline const int& Traffic::checkIsOnRoad() const
{
   return _isOnRoad;
}
#endif