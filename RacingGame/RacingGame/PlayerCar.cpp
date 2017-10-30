#include "PlayerCar.hpp"



PlayerCar::PlayerCar(){
	coords = { { 14,16 },{ 14,19 },{ 18,16 },{ 18,19 } }; //north-west, north-east, south-west, south-east

	speed_ = 1000;
	alive_ = 1;
}
//move car per pixel to the right
void PlayerCar::turnRight(){
	if (coords[1][1] < roadWidth - 1) {
		coords[0][1] += 1;
		coords[1][1] += 1;
		coords[2][1] += 1;
		coords[3][1] += 1;
	}
}
//move car per pixel to the left
void PlayerCar::turnLeft()
{
	if (coords[0][1] > 0) {
		coords[0][1] -= 1;
		coords[1][1] -= 1;
		coords[2][1] -= 1;
		coords[3][1] -= 1;
	}
}

//decrease the frame change
void PlayerCar::useAcceleration()
{
	if (speed_ > 150)
		speed_ -= 100;
}

//increase the frame change
void PlayerCar::useBrake()
{
	if (speed_ < 950)
		speed_ += 100;
}

const vector<vector<int>>& PlayerCar::getCar() const
{
	return coords;
}

//car is destroyed
void PlayerCar::setBadCondition()
{
	alive_ = 0;
}

const int PlayerCar::isAlive()
{
	return alive_;
}

const int PlayerCar::getSpeed()
{
	return speed_;
}
