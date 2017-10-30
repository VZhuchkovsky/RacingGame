#ifndef  GAMEROAD_HPP
#define  GAMEROAD_HPP

#include <iostream>

#include <vector>
#include "CommonDefines.hpp"
#include "Obstacles.hpp"
#include "PlayerCar.hpp"
#include "Traffic.hpp"


using namespace std;

class GameRoad {

public:
	GameRoad(PlayerCar& playerCar, Traffic& trafficVehicle1, Traffic& trafficVehicle2,
		Traffic& trafficVehicle3, Traffic& trafficVehicle4, Obstacles& obstacle);
	void updateRoad();
	void showRoad();
	void checkCollision(Lane chosenLane);
	void setPause();
	void unPause();
	const int& checkPause() const;
	const int& checkDistance() const;
	const int& getTotalDistance() const;
	void incrementDistance();
	void isVictoryAchieved();
	const int& checkIfVictory() const;


private:
	static const int roadLenght = ROAD_LENGHT;
	static const int roadWidth = ROAD_WIDTH;
	static const int distance = DISTANCE;
	int currentDistance_ = 1;
	int pause_ = 0;
	int victory_ = 0;
	int road[roadLenght][roadWidth];
	PlayerCar& playerCar_;
	Traffic& trafficVehicle1_;
	Traffic& trafficVehicle2_;
	Traffic& trafficVehicle3_;
	Traffic& trafficVehicle4_;
	Obstacles& obstacle_;

};



#endif  GAMEROAD_HPP
