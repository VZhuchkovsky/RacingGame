#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <chrono>
#include <conio.h>

using namespace std;

#define ROAD_WIDTH 40;
#define ROAD_LENGHT 20;
#define DISTANCE 40;

enum lane { FIRST, SECOND, THIRD, FOURTH };

class Traffic {
	static const int roadLenght = ROAD_LENGHT;
	int _isOnRoad = 0;
	int _reborn;
	vector<vector<vector<int>>> vehicleCoords;
public:
	Traffic() {
		//Начальная инициализация vehicle1Coords
		vehicleCoords = { { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } } };

		_reborn = 0;
	};

	void moveTrafficVehicle(lane chosenLane) {

		_isOnRoad = 1;

		if (_reborn) {

			if (vehicleCoords[0][0][0] == roadLenght + rand() % 10) {
				_reborn = 0;
			}

			for (int i = 0; i < vehicleCoords.size(); i++) {
				for (int j = 0; j < vehicleCoords[0].size(); j++) {
					for (int o = 0; o < vehicleCoords[0][0].size(); o++) {

						if (i == 0 && j == (vehicleCoords[0].size() - 1)) { //нижняя часть машинки из траффика по строкам

							switch (chosenLane) {
							case(FIRST):
								vehicleCoords[i][j][o] += 2;
								break;
							case(SECOND):
								vehicleCoords[i][j][o] += 3;
								break;
							case(THIRD):
								vehicleCoords[i][j][o] += 1;
								break;
							case(FOURTH):
								vehicleCoords[i][j][o] += 2;
								break;
							}

						}
						if (i == 0 && o == 0 && j < (vehicleCoords[0].size() - 1)) { //левая часть машинки из траффика по строкам не считая одного пикселя нижней части

							switch (chosenLane) {
							case(FIRST):
								vehicleCoords[i][j][o] += 2;
								break;
							case(SECOND):
								vehicleCoords[i][j][o] += 3;
								break;
							case(THIRD):
								vehicleCoords[i][j][o] += 1;
								break;
							case(FOURTH):
								vehicleCoords[i][j][o] += 2;
								break;
							}

						}
						if (i == 0 && o == (vehicleCoords[0][0].size() - 1) && j < (vehicleCoords[0].size() - 1)) { //правая часть машинки из траффика по строкам не считая одного пикселя нижней части

							switch (chosenLane) {
							case(FIRST):
								vehicleCoords[i][j][o] += 2;
								break;
							case(SECOND):
								vehicleCoords[i][j][o] += 3;
								break;
							case(THIRD):
								vehicleCoords[i][j][o] += 1;
								break;
							case(FOURTH):
								vehicleCoords[i][j][o] += 2;
								break;

							}
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

						if (i == 0 && j == (vehicleCoords[0].size() - 1)) { //нижняя часть машинки из траффика по строкам
							vehicleCoords[i][j][o] = -1;
						}
						if (i == 1 && j == (vehicleCoords[0].size() - 1)) { //нижняя часть машинки из траффика по столбцам
							vehicleCoords[i][j][o] = 2 + o;

							switch (chosenLane) {
							case(FIRST):
								break;
							case(SECOND):
								vehicleCoords[i][j][o] += 6;
								break;
							case(THIRD):
								vehicleCoords[i][j][o] += 18;
								break;
							case(FOURTH):
								vehicleCoords[i][j][o] += 24;
								break;
							}

						}
						if (i == 0 && o == 0 && j < (vehicleCoords[0].size() - 1)) { //левая часть машинки из траффика по строкам не считая одного пикселя нижней части
							vehicleCoords[i][j][o] = -(vehicleCoords[0].size() - j);
						}
						if (i == 1 && o == 0 && j < (vehicleCoords[0].size() - 1)) { //левая часть машинки из траффика по стобцам не считая одного пикселя нижней части
							vehicleCoords[i][j][o] = 2;

							switch (chosenLane) {
							case(FIRST):
								break;
							case(SECOND):
								vehicleCoords[i][j][o] += 6;
								break;
							case(THIRD):
								vehicleCoords[i][j][o] += 18;
								break;
							case(FOURTH):
								vehicleCoords[i][j][o] += 24;
								break;
							}
						}
						if (i == 0 && o == (vehicleCoords[0][0].size() - 1) && j < (vehicleCoords[0].size() - 1)) { //правая часть машинки из траффика по строкам не считая одного пикселя нижней части
							vehicleCoords[i][j][o] = -(vehicleCoords[0].size() - j);
						}
						if (i == 1 && o == (vehicleCoords[0][0].size() - 1) && j < (vehicleCoords[0].size() - 1)) { //правая часть машинки из траффика по столбцам не считая одного пикселя нижней части
							vehicleCoords[i][j][o] = 2 + (vehicleCoords[0][0].size() - 1);

							switch (chosenLane) {
							case(FIRST):
								break;
							case(SECOND):
								vehicleCoords[i][j][o] += 6;
								break;
							case(THIRD):
								vehicleCoords[i][j][o] += 18;
								break;
							case(FOURTH):
								vehicleCoords[i][j][o] += 24;
								break;
							}
						}

					}

				}
			}

			_reborn = 1;
		}
	}

	const vector<vector<vector<int>>>& getTrafficVehicle() const {
		return vehicleCoords;
	}

	const int& checkIsOnRoad() const {
		return _isOnRoad;
	}

};

class Obstacles {
	static const int roadLenght = ROAD_LENGHT;
	int _isOnRoad;
	int _reborn;
	vector<vector<int>> obstacle;
public:
	Obstacles() {
		obstacle = { { 0,0,0 },{ 0,0,0 } };
		_reborn = 0;
	};

	void moveObstacle() {

		_isOnRoad = 1;

		if (_reborn) {

			if (obstacle[0][0] == roadLenght) {
				_reborn = 0;
			}

			for (int i = 0; i < obstacle.size(); i++) {
				for (int j = 0; j < obstacle[0].size(); j++) {
					if (i == 0) {
						obstacle[i][j] += 1;
					}
				}
			}

		}
		else {

			int firstLocation = rand() % 10 + 1;

			for (int i = 0; i < obstacle.size(); i++) {
				for (int j = 0; j < obstacle[0].size(); j++) {

					if (i == 0) {
						obstacle[i][j] = -1;
					}
					if (i == 1) {
						obstacle[i][j] = firstLocation + j;
					}

				}
			}

			_reborn = 1;
		}
	}

	const vector<vector<int>>& getObstacle() const {
		return obstacle;
	}

	const int& checkObstacle() const {
		return _isOnRoad;
	}
};


class PlayerCar {
	static const int carLenght = 5;
	static const int carWidth = 4;

	static const int roadLenght = ROAD_LENGHT;
	static const int roadWidth = ROAD_WIDTH;


	int car[carLenght][carWidth]; // заменить на <array> или <vector>
	vector <vector <int> > coords;
	int isAlive;
	int speed;
public:
	PlayerCar() {

		coords = { { 14,13 },{ 14,16 },{ 18,13 },{ 18,16 } }; //north-west, north-east, south-west, south-east
															  /*
															  for (int i = 0; i < carLenght; i++) {
															  for (int j = 0; j < carWidth; j++) {
															  car[i][j] = 1;
															  }
															  }
															  */
		speed = 1000;
		isAlive = 1;
	};

	void turnRight()
	{
		if (coords[1][1] < roadWidth - 1) {
			coords[0][1] += 1;
			coords[1][1] += 1;
			coords[2][1] += 1;
			coords[3][1] += 1;
		}
	}

	void turnLeft()
	{
		if (coords[0][1] > 0) {
			coords[0][1] -= 1;
			coords[1][1] -= 1;
			coords[2][1] -= 1;
			coords[3][1] -= 1;
		}
	}
	//Уменьшает время паузы
	void useAcceleration() {
		if (speed > 150) speed -= 100;
	}
	//Увеличивает время паузы
	void useBrake() {
		if (speed < 950) speed += 100;
	}

	const vector<vector<int>>& getCar() const
	{
		return coords;
	}

	void setBadCondition() {
		isAlive = 0;
	}

	const int getCondition() {
		return isAlive;
	}

	const int getSpeed() {
		return speed;
	}

};

class GameRoad {
	static const int roadLenght = ROAD_LENGHT;
	static const int roadWidth = ROAD_WIDTH;
	static const int distance = DISTANCE;
	int _currentDistance;
	int _pause = 0;
	int road[roadLenght][roadWidth]; // заменить на <array> или <vector>
	PlayerCar& _playerCar;
	Traffic& _trafficVehicle1;
	Traffic& _trafficVehicle2;
	Traffic& _trafficVehicle3;
	Traffic& _trafficVehicle4;
	Obstacles& _obstacle1;
	Obstacles& _obstacle2;
	/*
	int isOnRoad1 = 0;
	vector<vector<vector<int>>> vehicle1Coords;
	*/
public:
	GameRoad(PlayerCar& playerCar, Traffic& trafficVehicle1, Traffic& trafficVehicle2, Traffic& trafficVehicle3, Traffic& trafficVehicle4, Obstacles& obstacle1, Obstacles& obstacle2) :
		_playerCar(playerCar), _trafficVehicle1(trafficVehicle1), _trafficVehicle2(trafficVehicle2), _trafficVehicle3(trafficVehicle3), _trafficVehicle4(trafficVehicle4), _obstacle1(obstacle1), _obstacle2(obstacle2)
	{
		_currentDistance = 0;
	};

	void updateRoad() {

		vector<vector<int>> coords = _playerCar.getCar();
		vector<vector<vector<int>>> trafficVehicleCoords;
		vector<vector<int>> obstacle;

		for (int i = 0; i < roadLenght; i++)
		{
			for (int j = 0; j < roadWidth; j++)
			{

				road[i][j] = 0;

				if (_trafficVehicle1.checkIsOnRoad()) {
					trafficVehicleCoords = _trafficVehicle1.getTrafficVehicle();

					for (int k = 0; k < trafficVehicleCoords[0].size(); k++) {
						for (int o = 0; o < trafficVehicleCoords[0][0].size(); o++) {

							if ((i == trafficVehicleCoords[0][k][o]) && (j == trafficVehicleCoords[1][k][o])) {
								road[i][j] = 2;

							}
						}
					}
				}

				if (_trafficVehicle2.checkIsOnRoad()) {
					trafficVehicleCoords = _trafficVehicle2.getTrafficVehicle();

					for (int k = 0; k < trafficVehicleCoords[0].size(); k++) {
						for (int o = 0; o < trafficVehicleCoords[0][0].size(); o++) {

							if ((i == trafficVehicleCoords[0][k][o]) && (j == trafficVehicleCoords[1][k][o])) {
								road[i][j] = 2;

							}
						}
					}
				}

				if (_trafficVehicle3.checkIsOnRoad()) {
					trafficVehicleCoords = _trafficVehicle3.getTrafficVehicle();

					for (int k = 0; k < trafficVehicleCoords[0].size(); k++) {
						for (int o = 0; o < trafficVehicleCoords[0][0].size(); o++) {

							if ((i == trafficVehicleCoords[0][k][o]) && (j == trafficVehicleCoords[1][k][o])) {
								road[i][j] = 2;

							}
						}
					}
				}

				if (_trafficVehicle4.checkIsOnRoad()) {
					trafficVehicleCoords = _trafficVehicle4.getTrafficVehicle();

					for (int k = 0; k < trafficVehicleCoords[0].size(); k++) {
						for (int o = 0; o < trafficVehicleCoords[0][0].size(); o++) {

							if ((i == trafficVehicleCoords[0][k][o]) && (j == trafficVehicleCoords[1][k][o])) {
								road[i][j] = 2;

							}
						}
					}
				}

				if (_obstacle1.checkObstacle()) {
					obstacle = _obstacle1.getObstacle();

					if (((i == obstacle[0][0]) && (j == obstacle[1][0])) ||
						((i == obstacle[0][1]) && (j == obstacle[1][1])) ||
						((i == obstacle[0][2]) && (j == obstacle[1][2])))
					{
						road[i][j] = 3;
					}
				}

				if (_obstacle2.checkObstacle()) {
					obstacle = _obstacle2.getObstacle();

					if (((i == obstacle[0][0]) && (j == obstacle[1][0])) ||
						((i == obstacle[0][1]) && (j == obstacle[1][1])) ||
						((i == obstacle[0][2]) && (j == obstacle[1][2])))
					{
						road[i][j] = 3;
					}
				}


				if (((i == coords[0][0]) && (j == coords[0][1])) ||
					((i == coords[1][0]) && (j == coords[1][1])) ||
					((i == coords[2][0]) && (j == coords[2][1])) ||
					((i == coords[3][0]) && (j == coords[3][1])))
				{
					road[i][j] = 1;
				}/*
				 else
				 {
				 road[i][j] = 0;
				 }*/
			}
		}
	}

	void showRoad() {

		for (int i = 0; i < roadLenght; i++)
		{
			for (int j = 0; j < roadWidth; j++)
			{
				cout << road[i][j];
			}
			cout << endl;
		}
	}

	void checkCollision(lane chosenLane) {

		vector<vector<int>> playerCoords = _playerCar.getCar();
		vector<vector<vector<int>>> trafficVehicleCoords;
		vector<vector<int>> obstacle;

		switch (chosenLane) {
		case(FIRST): trafficVehicleCoords = _trafficVehicle1.getTrafficVehicle();
			break;
		case(SECOND): trafficVehicleCoords = _trafficVehicle2.getTrafficVehicle();
			break;
		case(THIRD): trafficVehicleCoords = _trafficVehicle3.getTrafficVehicle();
			break;
		case(FOURTH): trafficVehicleCoords = _trafficVehicle4.getTrafficVehicle();
			break;

		}

		for (int i = 0; i < trafficVehicleCoords.size(); i++) {
			for (int j = 0; j < trafficVehicleCoords[0].size(); j++) {
				for (int o = 0; o < trafficVehicleCoords[0][0].size(); o++) {

					//нижняя часть машинки из траффика
					if ((i == 0 && j == (trafficVehicleCoords[0].size() - 1)) && ((playerCoords[0][0] == trafficVehicleCoords[0][j][o] && playerCoords[0][1] == trafficVehicleCoords[1][j][o]) ||
						(playerCoords[1][0] == trafficVehicleCoords[0][j][o] && playerCoords[1][1] == trafficVehicleCoords[1][j][o]) ||
						(playerCoords[2][0] == trafficVehicleCoords[0][j][o] && playerCoords[2][1] == trafficVehicleCoords[1][j][o]) ||
						(playerCoords[3][0] == trafficVehicleCoords[0][j][o] && playerCoords[3][1] == trafficVehicleCoords[1][j][o])))
					{
						_playerCar.setBadCondition();
					}
					//левая часть машинки из траффика
					if ((i == 0 && o == 0 && j < (trafficVehicleCoords[0].size() - 1)) && ((playerCoords[0][0] == trafficVehicleCoords[0][j][o] && playerCoords[0][1] == trafficVehicleCoords[1][j][o]) ||
						(playerCoords[1][0] == trafficVehicleCoords[0][j][o] && playerCoords[1][1] == trafficVehicleCoords[1][j][o]) ||
						(playerCoords[2][0] == trafficVehicleCoords[0][j][o] && playerCoords[2][1] == trafficVehicleCoords[1][j][o]) ||
						(playerCoords[3][0] == trafficVehicleCoords[0][j][o] && playerCoords[3][1] == trafficVehicleCoords[1][j][o])))
					{
						_playerCar.setBadCondition();
					}
					//правая часть машинки из траффика
					if ((i == 0 && o == (trafficVehicleCoords[0][0].size() - 1) && j < (trafficVehicleCoords[0].size() - 1)) &&
						((playerCoords[0][0] == trafficVehicleCoords[0][j][o] && playerCoords[0][1] == trafficVehicleCoords[1][j][o]) ||
						(playerCoords[1][0] == trafficVehicleCoords[0][j][o] && playerCoords[1][1] == trafficVehicleCoords[1][j][o]) ||
							(playerCoords[2][0] == trafficVehicleCoords[0][j][o] && playerCoords[2][1] == trafficVehicleCoords[1][j][o]) ||
							(playerCoords[3][0] == trafficVehicleCoords[0][j][o] && playerCoords[3][1] == trafficVehicleCoords[1][j][o])))
					{
						_playerCar.setBadCondition();
					}

					if (_obstacle1.checkObstacle()) {
						obstacle = _obstacle1.getObstacle();

						for (int n = 0; n < obstacle.size(); n++) {
							for (int m = 0; m < obstacle[0].size(); m++) {
								if ((playerCoords[0][0] == obstacle[0][m] && playerCoords[0][1] == obstacle[1][m]) ||
									(playerCoords[1][0] == obstacle[0][m] && playerCoords[1][1] == obstacle[1][m]) ||
									(playerCoords[2][0] == obstacle[0][m] && playerCoords[2][1] == obstacle[1][m]) ||
									(playerCoords[3][0] == obstacle[0][m] && playerCoords[3][1] == obstacle[1][m]))
								{
									_playerCar.setBadCondition();

								};

							}
						}
					}

					if (_obstacle2.checkObstacle()) {
						obstacle = _obstacle2.getObstacle();

						for (int n = 0; n < obstacle.size(); n++) {
							for (int m = 0; m < obstacle[0].size(); m++) {
								if ((playerCoords[0][0] == obstacle[0][m] && playerCoords[0][1] == obstacle[1][m]) ||
									(playerCoords[1][0] == obstacle[0][m] && playerCoords[1][1] == obstacle[1][m]) ||
									(playerCoords[2][0] == obstacle[0][m] && playerCoords[2][1] == obstacle[1][m]) ||
									(playerCoords[3][0] == obstacle[0][m] && playerCoords[3][1] == obstacle[1][m]))
								{
									_playerCar.setBadCondition();

								};

							}
						}
					}
				}
			}
		}
	};

	void setPause() {
		_pause = 1;
	}

	void unPause() {
		_pause = 0;
	}

	const int& checkPause() const {
		return _pause;
	}
};


//Созданный поток
void Game(GameRoad& gameRoad, PlayerCar& playerCar, Traffic& trafficVehicle1, Traffic& trafficVehicle2, Traffic& trafficVehicle3, Traffic& trafficVehicle4, Obstacles& obstacle1, Obstacles& obstacle2) {

	int flag;

	trafficVehicle1.moveTrafficVehicle(FIRST);
	trafficVehicle2.moveTrafficVehicle(SECOND);
	trafficVehicle3.moveTrafficVehicle(THIRD);
	trafficVehicle4.moveTrafficVehicle(FOURTH);

	while (playerCar.getCondition())
	{

		gameRoad.checkCollision(FIRST);
		gameRoad.checkCollision(SECOND);
		gameRoad.checkCollision(THIRD);
		gameRoad.checkCollision(FOURTH);
		/*
		flag = trafficVehicle1.checkIsOnRoad();

		if (!flag) {
		trafficVehicle1.moveTrafficVehicle(FIRST);
		}
		*/
		//vehicle1Coords = gameRoad.getLaneVehicle1();

		gameRoad.updateRoad();
		gameRoad.showRoad();
		this_thread::sleep_for(chrono::milliseconds(playerCar.getSpeed()));
		system("cls");
		//for (int i = 0; i < 20; i++) {
		//	cout << endl;
		//}


		trafficVehicle1.moveTrafficVehicle(FIRST);
		trafficVehicle2.moveTrafficVehicle(SECOND);
		trafficVehicle3.moveTrafficVehicle(THIRD);
		trafficVehicle4.moveTrafficVehicle(FOURTH);

	}
}

//Основной поток
void Handling(GameRoad& gameRoad, PlayerCar& playerCar) {
	while (playerCar.getCondition())
	{
		int pressedButton = getch();
		//getch(); //Safety
		if (pressedButton == 72) playerCar.useAcceleration();
		else if (pressedButton == 80) playerCar.useBrake();
		else if (pressedButton == 75) playerCar.turnLeft();
		else if (pressedButton == 77) playerCar.turnRight();

		//for (int i = 0; i < 20; i++) {
		//	cout << endl;
		//}

		system("cls");
		gameRoad.updateRoad();
		gameRoad.showRoad();
	}
}



int main()
{
	PlayerCar playerCar;
	Traffic trafficCar1;
	Traffic trafficCar2;
	Traffic trafficCar3;
	Traffic trafficCar4;
	Obstacles obstacle1;
	Obstacles obstacle2;
	GameRoad gameRoad(playerCar, trafficCar1, trafficCar2, trafficCar3, trafficCar4, obstacle1, obstacle2);

	thread thr(Game, ref(gameRoad), ref(playerCar), ref(trafficCar1), ref(trafficCar2), ref(trafficCar3), ref(trafficCar4), ref(obstacle1), ref(obstacle2));
	Handling(gameRoad, playerCar);
	thr.join();

	system("pause");
}