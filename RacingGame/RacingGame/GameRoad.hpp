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
	inline const int& checkPause() const;
	inline const int& checkDistance() const;
	inline const int& getTotalDistance() const;
	void incrementDistance();
	void isVictoryAchieved();
	inline const int& checkIfVictory() const;


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

void GameRoad::updateRoad() {

	vector<vector<int>> coords = playerCar_.getCar();
	vector<vector<vector<int>>> trafficVehicleCoords;
	vector<vector<vector<int>>> obstacleCoords;

	for (int i = 0; i < roadLenght; i++)
	{
		for (int j = 0; j < roadWidth; j++) {

			road[i][j] = 0;

			if (trafficVehicle1_.isOnRoad() != 0) {
				trafficVehicleCoords = trafficVehicle1_.getTrafficVehicle();

				for (int k = 0; k < trafficVehicleCoords[0].size(); k++) {
					for (int o = 0; o < trafficVehicleCoords[0][0].size(); o++) {

						if ((i == trafficVehicleCoords[0][k][o]) && (j == trafficVehicleCoords[1][k][o]))
							road[i][j] = 2;

					}
				}
			}

			if (trafficVehicle2_.isOnRoad() != 0) {
				trafficVehicleCoords = trafficVehicle2_.getTrafficVehicle();

				for (int k = 0; k < trafficVehicleCoords[0].size(); k++) {
					for (int o = 0; o < trafficVehicleCoords[0][0].size(); o++) {

						if ((i == trafficVehicleCoords[0][k][o]) && (j == trafficVehicleCoords[1][k][o]))
							road[i][j] = 2;

					}
				}
			}

			if (trafficVehicle3_.isOnRoad() != 0) {
				trafficVehicleCoords = trafficVehicle3_.getTrafficVehicle();

				for (int k = 0; k < trafficVehicleCoords[0].size(); k++) {
					for (int o = 0; o < trafficVehicleCoords[0][0].size(); o++) {

						if ((i == trafficVehicleCoords[0][k][o]) && (j == trafficVehicleCoords[1][k][o]))
							road[i][j] = 2;

					}
				}
			}

			if (trafficVehicle4_.isOnRoad() != 0) {
				trafficVehicleCoords = trafficVehicle4_.getTrafficVehicle();

				for (int k = 0; k < trafficVehicleCoords[0].size(); k++) {
					for (int o = 0; o < trafficVehicleCoords[0][0].size(); o++) {

						if ((i == trafficVehicleCoords[0][k][o]) && (j == trafficVehicleCoords[1][k][o]))
							road[i][j] = 2;

					}
				}
			}

			if (obstacle_.isOnRoad() != 0) {
				obstacleCoords = obstacle_.getObstacle();

				for (int k = 0; k < obstacleCoords[0].size(); k++) {
					for (int o = 0; o < obstacleCoords[0][0].size(); o++) {

						if ((i == obstacleCoords[0][k][o]) && (j == obstacleCoords[1][k][o]))
							road[i][j] = 8;

					}
				}
			}


			if (((i == coords[0][0]) && (j == coords[0][1])) ||
				((i == coords[1][0]) && (j == coords[1][1])) ||
				((i == coords[2][0]) && (j == coords[2][1])) ||
				((i == coords[3][0]) && (j == coords[3][1]))) {

				road[i][j] = 1;

			}
		}
	}
}

void GameRoad::showRoad() {
	vector <vector <int> > playerCoords = playerCar_.getCar();

	for (int i = 0; i < roadLenght; i++)
	{
		for (int j = 0; j < roadWidth; j++)
		{
			if (j == 0 || j == roadWidth - 1)
				cout << static_cast<char>(219);

			else {
				cout << road[i][j];
			}

		}
		cout << endl;
	}
}

void GameRoad::checkCollision(Lane chosenLane)
{

	vector<vector<int>> playerCoords = playerCar_.getCar();
	vector<vector<vector<int>>> objCoords;

	switch (chosenLane) {
	case(LANE_FIRST): objCoords = trafficVehicle1_.getTrafficVehicle();
		break;
	case(LANE_SECOND): objCoords = trafficVehicle2_.getTrafficVehicle();
		break;
	case(LANE_THIRD): objCoords = trafficVehicle3_.getTrafficVehicle();
		break;
	case(LANE_FOURTH): objCoords = trafficVehicle4_.getTrafficVehicle();
		break;
	case(LANE_OBSTACLE): objCoords = obstacle_.getObstacle();
		break;

	}

	for (int i = 0; i < objCoords.size(); i++) {
		for (int j = 0; j < objCoords[0].size(); j++) {
			for (int o = 0; o < objCoords[0][0].size(); o++) {

				//нижняя часть объекта 
				if ((i == 0 && j == (objCoords[0].size() - 1)) &&
					((playerCoords[0][0] == objCoords[0][j][o] && playerCoords[0][1] == objCoords[1][j][o]) ||
					(playerCoords[1][0] == objCoords[0][j][o] && playerCoords[1][1] == objCoords[1][j][o]) ||
						(playerCoords[2][0] == objCoords[0][j][o] && playerCoords[2][1] == objCoords[1][j][o]) ||
						(playerCoords[3][0] == objCoords[0][j][o] && playerCoords[3][1] == objCoords[1][j][o])))
				{
					playerCar_.setBadCondition();
				}
				//левая часть объекта
				if ((i == 0 && o == 0 && j < (objCoords[0].size() - 1)) &&
					((playerCoords[0][0] == objCoords[0][j][o] && playerCoords[0][1] == objCoords[1][j][o]) ||
					(playerCoords[1][0] == objCoords[0][j][o] && playerCoords[1][1] == objCoords[1][j][o]) ||
						(playerCoords[2][0] == objCoords[0][j][o] && playerCoords[2][1] == objCoords[1][j][o]) ||
						(playerCoords[3][0] == objCoords[0][j][o] && playerCoords[3][1] == objCoords[1][j][o]))) {

					playerCar_.setBadCondition();

				}
				//правая часть объекта 
				if ((i == 0 && o == (objCoords[0][0].size() - 1) && j < (objCoords[0].size() - 1)) &&
					((playerCoords[0][0] == objCoords[0][j][o] && playerCoords[0][1] == objCoords[1][j][o]) ||
					(playerCoords[1][0] == objCoords[0][j][o] && playerCoords[1][1] == objCoords[1][j][o]) ||
						(playerCoords[2][0] == objCoords[0][j][o] && playerCoords[2][1] == objCoords[1][j][o]) ||
						(playerCoords[3][0] == objCoords[0][j][o] && playerCoords[3][1] == objCoords[1][j][o]))) {

					playerCar_.setBadCondition();

				}

			}
		}
	}
}

void GameRoad::setPause()
{
	pause_ = 1;
}

void GameRoad::unPause()
{
	pause_ = 0;
}

inline const int& GameRoad::checkPause() const
{
	return pause_;
}

inline const int& GameRoad::checkDistance() const
{
	return currentDistance_;
}

inline const int& GameRoad::getTotalDistance() const
{
	return distance;
}

void GameRoad::incrementDistance()
{
	++currentDistance_;
}

void GameRoad::isVictoryAchieved() {
	if (currentDistance_ > distance)
		victory_ = 1;

}

inline const int& GameRoad::checkIfVictory() const
{
	return victory_;
}



#endif  GAMEROAD_HPP
