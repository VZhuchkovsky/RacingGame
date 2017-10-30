#ifndef  OBSTACLES_HPP
#define  OBSTACLES_HPP

#include <vector>
#include "CommonDefines.hpp"

using namespace std;

class Obstacles {

public:
	Obstacles();
	
	void moveObstacle();
	const vector<vector<vector<int>>>& getObstacle() const;
	const int& isOnRoad() const;

private:
	static const int roadLenght = ROAD_LENGHT;
	int onRoad_ = 0;
	int reborn_ = 0;
	vector<vector<vector<int>>> obstacleCoords;
};


#endif OBSTACLES_HPP

