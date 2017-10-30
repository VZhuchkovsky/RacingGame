#ifndef TRAFFIC_HPP
#define TRAFFIC_HPP

#include <vector>
#include "CommonDefines.hpp"

using namespace std;

class Traffic {

public:
	Traffic();
	void moveVehicle(Lane chosenLane);
	const vector<vector<vector<int>>>& getTrafficVehicle() const;
	const int& isOnRoad() const;

private:
	const int roadLenght = ROAD_LENGHT;
	int onRoad_ = 0;
	int reborn_ = 0;
	vector<vector<vector<int>>> vehicleCoords;

};

#endif TRAFFIC_HPP
