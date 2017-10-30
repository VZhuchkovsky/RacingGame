#include "Traffic.hpp"


Traffic::Traffic()
{
	//Начальная инициализация vehicle1Coords
	vehicleCoords = { { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } } };

	reborn_ = 0;
}

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
							j < (vehicleCoords[0].size() - 1))) { //нижняя часть машинки из траффика по строкам

						vehicleCoords[i][j][o] += 1;

					}
				}
			}
		}

	}
	else {

		int rnd = rand() % 10 + 1;

		for (int i = 0; i < vehicleCoords.size(); i++) {
			for (int j = 0; j < vehicleCoords[0].size(); j++) {
				for (int o = 0; o < vehicleCoords[0][0].size(); o++) {

					if (i == 0 && j == (vehicleCoords[0].size() - 1))  //нижняя часть машинки из траффика по строкам
						vehicleCoords[i][j][o] = -1;

					if (i == 1 && j == (vehicleCoords[0].size() - 1))  //нижняя часть машинки из траффика по столбцам
						vehicleCoords[i][j][o] = 2 + o;

					if (i == 0 && o == 0 && j < (vehicleCoords[0].size() - 1))  //левая часть машинки из траффика по строкам не считая одного пикселя нижней части
						vehicleCoords[i][j][o] = -(vehicleCoords[0].size() - j);

					if (i == 1 && o == 0 && j < (vehicleCoords[0].size() - 1))  //левая часть машинки из траффика по стобцам не считая одного пикселя нижней части
						vehicleCoords[i][j][o] = 2;

					if (i == 0 && o == (vehicleCoords[0][0].size() - 1) &&
						j < (vehicleCoords[0].size() - 1))  //правая часть машинки из траффика по строкам не считая одного пикселя нижней части
						vehicleCoords[i][j][o] = -(vehicleCoords[0].size() - j);

					if (i == 1 && o == (vehicleCoords[0][0].size() - 1) &&
						j < (vehicleCoords[0].size() - 1))  //правая часть машинки из траффика по столбцам не считая одного пикселя нижней части
						vehicleCoords[i][j][o] = 2 + (vehicleCoords[0][0].size() - 1);


					if ((i == 1 && j == (vehicleCoords[0].size() - 1)) ||
						(i == 1 && o == 0 && j < (vehicleCoords[0].size() - 1)) ||
						(i == 1 && o == (vehicleCoords[0][0].size() - 1) &&
							j < (vehicleCoords[0].size() - 1))) {

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

					//rnd
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



const vector<vector<vector<int>>>& Traffic::getTrafficVehicle() const
{
	return vehicleCoords;
}

const int& Traffic::isOnRoad() const
{
	return onRoad_;
}
