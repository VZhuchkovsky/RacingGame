#include "GameRoad.hpp"
#include "Obstacles.hpp"
#include "PlayerCar.hpp"
#include "Traffic.hpp"




GameRoad::GameRoad(PlayerCar& playerCar, Traffic& trafficVehicle1, Traffic& trafficVehicle2,
	Traffic& trafficVehicle3, Traffic& trafficVehicle4, Obstacles& obstacle) :
	playerCar_(playerCar), trafficVehicle1_(trafficVehicle1), trafficVehicle2_(trafficVehicle2),
	trafficVehicle3_(trafficVehicle3), trafficVehicle4_(trafficVehicle4), obstacle_(obstacle) {

	currentDistance_ = 1;
	pause_ = 0;
	victory_ = 0;
}

