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
	inline const vector<vector<int>>& getCar() const;
	void setBadCondition();
	inline const int isAlive();
	inline const int getSpeed();

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

void PlayerCar::turnRight()
{
	if (coords[1][1] < roadWidth - 1) {
		coords[0][1] += 1;
		coords[1][1] += 1;
		coords[2][1] += 1;
		coords[3][1] += 1;
	}
}

void PlayerCar::turnLeft()
{
	if (coords[0][1] > 0) {
		coords[0][1] -= 1;
		coords[1][1] -= 1;
		coords[2][1] -= 1;
		coords[3][1] -= 1;
	}
}

//Уменьшает время паузы
void PlayerCar::useAcceleration()
{
	if (speed_ > 150)
		speed_ -= 100;
}

//Увеличивает время паузы
void PlayerCar::useBrake()
{
	if (speed_ < 950)
		speed_ += 100;
}

inline const vector<vector<int>>& PlayerCar::getCar() const
{
	return coords;
}

void PlayerCar::setBadCondition()
{
	alive_ = 0;
}

inline const int PlayerCar::isAlive()
{
	return alive_;
}

inline const int PlayerCar::getSpeed()
{
	return speed_;
}

#endif PLAYERCAR_HPP

