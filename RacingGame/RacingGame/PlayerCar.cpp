#include "PlayerCar.hpp"



PlayerCar::PlayerCar(){
	coords = { { 14,16 },{ 14,19 },{ 18,16 },{ 18,19 } }; //north-west, north-east, south-west, south-east

	speed_ = 1000;
	alive_ = 1;
}

