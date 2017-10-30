#include "Obstacles.hpp"



Obstacles::Obstacles() {

	//first initialization of obstacleCoords
	obstacleCoords = { { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } } };

	reborn_ = 0;
}

//makes obstacle ride down the road and returns when it runs out of scope
void Obstacles::moveObstacle() {

	onRoad_ = 1;

	if (obstacleCoords[0][0][0] == roadLenght)
		reborn_ = 0;


	if (reborn_ != 0) {

		for (int i = 0; i < obstacleCoords.size(); i++) {
			for (int j = 0; j < obstacleCoords[0].size(); j++) {
				for (int o = 0; o < obstacleCoords[0][0].size(); o++) {

					if ((i == 0 && j == (obstacleCoords[0].size() - 1)) ||
						(i == 0 && o == 0 && j < (obstacleCoords[0].size() - 1)) ||
						(i == 0 && o == (obstacleCoords[0][0].size() - 1) &&
							j < (obstacleCoords[0].size() - 1))) {

						obstacleCoords[i][j][o] += 1;

					}
				}
			}
		}

	}
	else {

		int rnd = rand() % 9;

		for (int i = 0; i < obstacleCoords.size(); i++) {
			for (int j = 0; j < obstacleCoords[0].size(); j++) {
				for (int o = 0; o < obstacleCoords[0][0].size(); o++) {

					if (i == 0 && j == (obstacleCoords[0].size() - 1)) //bootom part of the traffic vehicle (strings)
						obstacleCoords[i][j][o] = -1;

					if (i == 1 && j == (obstacleCoords[0].size() - 1))   //bootom part of the traffic vehicle (columns)
						obstacleCoords[i][j][o] = 13 + o + rnd;

					if (i == 0 && o == 0 && j < (obstacleCoords[0].size() - 1))  //left part of the traffic vehicle (strings) (despite bottom pixel)
						obstacleCoords[i][j][o] = -(obstacleCoords[0].size() - j);

					if (i == 1 && o == 0 && j < (obstacleCoords[0].size() - 1))  //left part of the traffic vehicle (columns) (despite bottom pixel)
						obstacleCoords[i][j][o] = 13 + rnd;

					//right part of the traffic vehicle (strings) (despite bottom pixel)
					if (i == 0 && o == (obstacleCoords[0][0].size() - 1) &&
						j < (obstacleCoords[0].size() - 1))  
						obstacleCoords[i][j][o] = -(obstacleCoords[0].size() - j);

					//right part of the traffic vehicle (columns) (despite bottom pixel)
					if (i == 1 && o == (obstacleCoords[0][0].size() - 1) &&
						j < (obstacleCoords[0].size() - 1))  
						obstacleCoords[i][j][o] = 13 + (obstacleCoords[0][0].size() - 1) + rnd;


				}

			}
		}

		reborn_ = 1;

	}
}

const vector<vector<vector<int>>>& Obstacles::getObstacle() const {

	return obstacleCoords;

}

const int& Obstacles::isOnRoad() const
{
	return onRoad_;
}
