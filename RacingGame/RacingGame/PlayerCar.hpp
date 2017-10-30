#ifndef PLAYERCAR_HPP
#define PLAYERCAR_HPP

#include <vector>
#include "CommonDefines.hpp"

using namespace std;

class PlayerCar {

public:
	PlayerCar();
	void turnRight();
	void turnLeft();
	void useAcceleration();
	void useBrake();
	const vector<vector<int>>& getCar() const;
	void setBadCondition();
	const int isAlive();
	const int getSpeed();

private:
	static const int carLenght_ = 5;
	static const int carWidth_ = 4;

	static const int roadLenght = ROAD_LENGHT;
	static const int roadWidth = ROAD_WIDTH;

	int car[carLenght_][carWidth_];
	vector <vector <int> > coords;
	int alive_ = 0;
	int speed_ = 0;
};



#endif PLAYERCAR_HPP

