#include "Traffic.hpp"


Traffic::Traffic()
{
	//first initialization of vehicleCoords
	vehicleCoords = { { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } } };

	reborn_ = 0;
}

//makes vehicle ride down the road and returns when it runs out of scope
void Traffic::moveVehicle(Lane chosenLane)
{

	onRoad_ = 1;


	if (vehicleCoords[0][0][0] == roadLenght)
		reborn_ = 0;


	if (reborn_ != 0) {

		for (int i = 0; i < vehicleCoords.size(); i++) {
			for (int j = 0; j < vehicleCoords[0].size(); j++) {
				for (int o = 0; o < vehicleCoords[0][0].size(); o++) {

					if ((i == 0 && j == (vehicleCoords[0].size() - 1)) ||
						(i == 0 && o == 0 && j < (vehicleCoords[0].size() - 1)) ||
						(i == 0 && o == (vehicleCoords[0][0].size() - 1) &&
							j < (vehicleCoords[0].size() - 1))) { 

						vehicleCoords[i][j][o] += 1;

					}
				}
			}
		}

	}
	else {

		int rnd = rand() % 10 + 1; //using rand to make vehicles return to the game space at different time points

		for (int i = 0; i < vehicleCoords.size(); i++) {
			for (int j = 0; j < vehicleCoords[0].size(); j++) {
				for (int o = 0; o < vehicleCoords[0][0].size(); o++) {

					if (i == 0 && j == (vehicleCoords[0].size() - 1))  //bootom part of the traffic vehicle (strings)
						vehicleCoords[i][j][o] = -1;

					if (i == 1 && j == (vehicleCoords[0].size() - 1))  //bootom part of the traffic vehicle (columns)
						vehicleCoords[i][j][o] = 2 + o;

					if (i == 0 && o == 0 && j < (vehicleCoords[0].size() - 1))  //left part of the traffic vehicle (strings) (despite bottom pixel)
						vehicleCoords[i][j][o] = -(vehicleCoords[0].size() - j);

					if (i == 1 && o == 0 && j < (vehicleCoords[0].size() - 1))  //left part of the traffic vehicle (columns) (despite bottom pixel)
						vehicleCoords[i][j][o] = 2;

					//right part of the traffic vehicle (strings) (despite bottom pixel)
					if (i == 0 && o == (vehicleCoords[0][0].size() - 1) &&
						j < (vehicleCoords[0].size() - 1))  
						vehicleCoords[i][j][o] = -(vehicleCoords[0].size() - j);

					//right part of the traffic vehicle (columns) (despite bottom pixel)
					if (i == 1 && o == (vehicleCoords[0][0].size() - 1) &&
						j < (vehicleCoords[0].size() - 1))  
						vehicleCoords[i][j][o] = 2 + (vehicleCoords[0][0].size() - 1);


					if ((i == 1 && j == (vehicleCoords[0].size() - 1)) ||
						(i == 1 && o == 0 && j < (vehicleCoords[0].size() - 1)) ||
						(i == 1 && o == (vehicleCoords[0][0].size() - 1) &&
							j < (vehicleCoords[0].size() - 1))) {
						//own rajectory for each lane
						switch (chosenLane) {
						case(LANE_FIRST):
							break;
						case(LANE_SECOND):
							vehicleCoords[i][j][o] += 6;
							break;
						case(LANE_THIRD):
							vehicleCoords[i][j][o] += 26;
							break;
						case(LANE_FOURTH):
							vehicleCoords[i][j][o] += 32;
							break;
						}

					}

					//rnd usage
					if ((i == 0 && j == (vehicleCoords[0].size() - 1)) ||
						(i == 0 && o == 0 && j < (vehicleCoords[0].size() - 1)) ||
						(i == 0 && o == (vehicleCoords[0][0].size() - 1) &&
							j < (vehicleCoords[0].size() - 1))) {

						vehicleCoords[i][j][o] -= rnd;

					}

				}

			}
		}

		reborn_ = 1;

	}
}

//return vector of vehicle coordinates
const vector<vector<vector<int>>>& Traffic::getTrafficVehicle() const
{
	return vehicleCoords;
}

// check is vehicle exist
const int& Traffic::isOnRoad() const
{
	return onRoad_;
}
