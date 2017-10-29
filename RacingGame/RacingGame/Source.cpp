#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <chrono>
#include <conio.h>
#include <iomanip>  // setprecision

using namespace std;

const int ROAD_WIDTH = 40;
const int ROAD_LENGHT = 20;
const int DISTANCE = 400;

const enum lane { FIRST, SECOND, THIRD, FOURTH , OBSTACLE};

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
		

		if (vehicleCoords[0][0][0] == roadLenght) {
			_reborn = 0;
		}

		if (_reborn) {

			for (int i = 0; i < vehicleCoords.size(); i++) {
				for (int j = 0; j < vehicleCoords[0].size(); j++) {
					for (int o = 0; o < vehicleCoords[0][0].size(); o++) {

						if ((i == 0 && j == (vehicleCoords[0].size() - 1)) ||
							(i == 0 && o == 0 && j < (vehicleCoords[0].size() - 1)) ||
							(i == 0 && o == (vehicleCoords[0][0].size() - 1) && j < (vehicleCoords[0].size() - 1))) { //нижняя часть машинки из траффика по строкам

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

						if (i == 0 && j == (vehicleCoords[0].size() - 1)) { //нижняя часть машинки из траффика по строкам
							vehicleCoords[i][j][o] = -1;
						}
						if (i == 1 && j == (vehicleCoords[0].size() - 1)) { //нижняя часть машинки из траффика по столбцам
							vehicleCoords[i][j][o] = 2 + o;
						}
						if (i == 0 && o == 0 && j < (vehicleCoords[0].size() - 1)) { //левая часть машинки из траффика по строкам не считая одного пикселя нижней части
							vehicleCoords[i][j][o] = -(vehicleCoords[0].size() - j);
						}
						if (i == 1 && o == 0 && j < (vehicleCoords[0].size() - 1)) { //левая часть машинки из траффика по стобцам не считая одного пикселя нижней части
							vehicleCoords[i][j][o] = 2;
						}
						if (i == 0 && o == (vehicleCoords[0][0].size() - 1) && j < (vehicleCoords[0].size() - 1)) { //правая часть машинки из траффика по строкам не считая одного пикселя нижней части
							vehicleCoords[i][j][o] = -(vehicleCoords[0].size() - j);
						}
						if (i == 1 && o == (vehicleCoords[0][0].size() - 1) && j < (vehicleCoords[0].size() - 1)) { //правая часть машинки из траффика по столбцам не считая одного пикселя нижней части
							vehicleCoords[i][j][o] = 2 + (vehicleCoords[0][0].size() - 1);
						}

						if ((i == 1 && j == (vehicleCoords[0].size() - 1)) ||
							(i == 1 && o == 0 && j < (vehicleCoords[0].size() - 1)) ||
							(i == 1 && o == (vehicleCoords[0][0].size() - 1) && j < (vehicleCoords[0].size() - 1))) {

							switch (chosenLane) {
							case(FIRST):
								break;
							case(SECOND):
								vehicleCoords[i][j][o] += 6;
								break;
							case(THIRD):
								vehicleCoords[i][j][o] += 26;
								break;
							case(FOURTH):
								vehicleCoords[i][j][o] += 32;
								break;
							}

						}

						//rnd
						if ((i == 0 && j == (vehicleCoords[0].size() - 1)) ||
							(i == 0 && o == 0 && j < (vehicleCoords[0].size() - 1)) ||
							(i == 0 && o == (vehicleCoords[0][0].size() - 1) && j < (vehicleCoords[0].size() - 1))) {

							vehicleCoords[i][j][o] -= rnd;

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
	vector<vector<vector<int>>> obstacleCoords;
public:
	Obstacles() {
		obstacleCoords = { { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } } };

		_reborn = 0;
	};

	void moveObstacle() {

		_isOnRoad = 1;

		if (obstacleCoords[0][0][0] == roadLenght) {
			_reborn = 0;
		}

		if (_reborn) {

			for (int i = 0; i < obstacleCoords.size(); i++) {
				for (int j = 0; j < obstacleCoords[0].size(); j++) {
					for (int o = 0; o < obstacleCoords[0][0].size(); o++) {

						if ((i == 0 && j == (obstacleCoords[0].size() - 1)) ||
							(i == 0 && o == 0 && j < (obstacleCoords[0].size() - 1)) ||
							(i == 0 && o == (obstacleCoords[0][0].size() - 1) && j < (obstacleCoords[0].size() - 1))) { 

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

						if (i == 0 && j == (obstacleCoords[0].size() - 1)) { //нижняя часть машинки из траффика по строкам
							obstacleCoords[i][j][o] = -1;
						}
						if (i == 1 && j == (obstacleCoords[0].size() - 1)) { //нижняя часть машинки из траффика по столбцам
							obstacleCoords[i][j][o] = 13 + o + rnd;
						}
						if (i == 0 && o == 0 && j < (obstacleCoords[0].size() - 1)) { //левая часть машинки из траффика по строкам не считая одного пикселя нижней части
							obstacleCoords[i][j][o] = -(obstacleCoords[0].size() - j);
						}
						if (i == 1 && o == 0 && j < (obstacleCoords[0].size() - 1)) { //левая часть машинки из траффика по стобцам не считая одного пикселя нижней части
							obstacleCoords[i][j][o] = 13 + rnd;
						}
						if (i == 0 && o == (obstacleCoords[0][0].size() - 1) && j < (obstacleCoords[0].size() - 1)) { //правая часть машинки из траффика по строкам не считая одного пикселя нижней части
							obstacleCoords[i][j][o] = -(obstacleCoords[0].size() - j);
						}
						if (i == 1 && o == (obstacleCoords[0][0].size() - 1) && j < (obstacleCoords[0].size() - 1)) { //правая часть машинки из траффика по столбцам не считая одного пикселя нижней части
							obstacleCoords[i][j][o] = 13 + (obstacleCoords[0][0].size() - 1) + rnd;
						}

					}

				}
			}
			

			_reborn = 1;
		}
	}

	const vector<vector<vector<int>>>& getObstacle() const {
		return obstacleCoords;
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

		coords = { { 14,16 },{ 14,19 },{ 18,16 },{ 18,19 } }; //north-west, north-east, south-west, south-east
															 
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
	int _pause;
	int _victory;
	int road[roadLenght][roadWidth];
	PlayerCar& _playerCar;
	Traffic& _trafficVehicle1;
	Traffic& _trafficVehicle2;
	Traffic& _trafficVehicle3;
	Traffic& _trafficVehicle4;
	Obstacles& _obstacle;

public:
	GameRoad(PlayerCar& playerCar, Traffic& trafficVehicle1, Traffic& trafficVehicle2, Traffic& trafficVehicle3, Traffic& trafficVehicle4, Obstacles& obstacle) :
		_playerCar(playerCar), _trafficVehicle1(trafficVehicle1), _trafficVehicle2(trafficVehicle2), _trafficVehicle3(trafficVehicle3), _trafficVehicle4(trafficVehicle4), _obstacle(obstacle)
	{
		_currentDistance = 1;
		_pause = 0;
		_victory = 0;
	};

	void updateRoad() {

		vector<vector<int>> coords = _playerCar.getCar();
		vector<vector<vector<int>>> trafficVehicleCoords;
		vector<vector<vector<int>>> obstacleCoords;

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

				if (_obstacle.checkObstacle()) {
					obstacleCoords = _obstacle.getObstacle();

					for (int k = 0; k < obstacleCoords[0].size(); k++) {
						for (int o = 0; o < obstacleCoords[0][0].size(); o++) {

							if ((i == obstacleCoords[0][k][o]) && (j == obstacleCoords[1][k][o])) {
								road[i][j] = 8;

							}
						}
					}
				}


				if (((i == coords[0][0]) && (j == coords[0][1])) ||
					((i == coords[1][0]) && (j == coords[1][1])) ||
					((i == coords[2][0]) && (j == coords[2][1])) ||
					((i == coords[3][0]) && (j == coords[3][1])))
				{
					road[i][j] = 1;
				}
			}
		}
	}

	void showRoad() {

		vector <vector <int> > playerCoords = _playerCar.getCar();

		for (int i = 0; i < roadLenght; i++)
		{
			for (int j = 0; j < roadWidth; j++)
			{
				if (j == 0 || j == roadWidth - 1) {
					cout << static_cast<char>(219);
				}
				else {
					cout << road[i][j];
				}

			}
			cout << endl;
		}
	}

	void checkCollision(lane chosenLane) {

		vector<vector<int>> playerCoords = _playerCar.getCar();
		vector<vector<vector<int>>> objCoords;

		switch (chosenLane) {
		case(FIRST): objCoords = _trafficVehicle1.getTrafficVehicle();
			break;
		case(SECOND): objCoords = _trafficVehicle2.getTrafficVehicle();
			break;
		case(THIRD): objCoords = _trafficVehicle3.getTrafficVehicle();
			break;
		case(FOURTH): objCoords = _trafficVehicle4.getTrafficVehicle();
			break;
		case(OBSTACLE): objCoords = _obstacle.getObstacle();
			break;

		}

		for (int i = 0; i < objCoords.size(); i++) {
			for (int j = 0; j < objCoords[0].size(); j++) {
				for (int o = 0; o < objCoords[0][0].size(); o++) {

					//нижняя часть объекта 
					if ((i == 0 && j == (objCoords[0].size() - 1)) && ((playerCoords[0][0] == objCoords[0][j][o] && playerCoords[0][1] == objCoords[1][j][o]) ||
						(playerCoords[1][0] == objCoords[0][j][o] && playerCoords[1][1] == objCoords[1][j][o]) ||
						(playerCoords[2][0] == objCoords[0][j][o] && playerCoords[2][1] == objCoords[1][j][o]) ||
						(playerCoords[3][0] == objCoords[0][j][o] && playerCoords[3][1] == objCoords[1][j][o])))
					{
						_playerCar.setBadCondition();
					}
					//левая часть объекта
					if ((i == 0 && o == 0 && j < (objCoords[0].size() - 1)) && ((playerCoords[0][0] == objCoords[0][j][o] && playerCoords[0][1] == objCoords[1][j][o]) ||
						(playerCoords[1][0] == objCoords[0][j][o] && playerCoords[1][1] == objCoords[1][j][o]) ||
						(playerCoords[2][0] == objCoords[0][j][o] && playerCoords[2][1] == objCoords[1][j][o]) ||
						(playerCoords[3][0] == objCoords[0][j][o] && playerCoords[3][1] == objCoords[1][j][o])))
					{
						_playerCar.setBadCondition();
					}
					//правая часть объекта 
					if ((i == 0 && o == (objCoords[0][0].size() - 1) && j < (objCoords[0].size() - 1)) &&
						((playerCoords[0][0] == objCoords[0][j][o] && playerCoords[0][1] == objCoords[1][j][o]) ||
						(playerCoords[1][0] == objCoords[0][j][o] && playerCoords[1][1] == objCoords[1][j][o]) ||
							(playerCoords[2][0] == objCoords[0][j][o] && playerCoords[2][1] == objCoords[1][j][o]) ||
							(playerCoords[3][0] == objCoords[0][j][o] && playerCoords[3][1] == objCoords[1][j][o])))
					{
						_playerCar.setBadCondition();
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

	const int& checkDistance() const {
		return _currentDistance;
	}

	const int& getTotalDistance() const {
		return distance;
	}

	void incrementDistance() {
		++_currentDistance;
	}

	void isVictoryAchieved() {
		if (_currentDistance > distance) {
			_victory = 1;
		}
	}

	const int& checkIfVictory() const {		
		return _victory;
	}

};

void gameLauncher() {
	int o = 0;
	cout << endl << "\t" << "Welcome to Pixel Racing" << endl;
	cout << endl << "\t" << "To start a game press any button..." << endl;
	o = getchar();
}

//Созданный поток
void Game(GameRoad& gameRoad, PlayerCar& playerCar, Traffic& trafficVehicle1, Traffic& trafficVehicle2, Traffic& trafficVehicle3, Traffic& trafficVehicle4, Obstacles& obstacle) {

	using namespace chrono;

	trafficVehicle1.moveTrafficVehicle(FIRST);
	trafficVehicle2.moveTrafficVehicle(SECOND);
	trafficVehicle3.moveTrafficVehicle(THIRD);
	trafficVehicle4.moveTrafficVehicle(FOURTH);
	obstacle.moveObstacle();

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	high_resolution_clock::time_point t2;
	duration<double> time_span;

	while (playerCar.getCondition() && !gameRoad.checkIfVictory())
	{
		if (gameRoad.checkPause()) {
			cout << "Double Enter for unpause." << endl;
			system("pause");
		}
		else {

		t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);

		gameRoad.isVictoryAchieved();

		gameRoad.checkCollision(FIRST);
		gameRoad.checkCollision(SECOND);
		gameRoad.checkCollision(THIRD);
		gameRoad.checkCollision(FOURTH);
		gameRoad.checkCollision(OBSTACLE);


		gameRoad.updateRoad();
		gameRoad.showRoad();
		cout << endl << "\t" << "Current Distance: " << gameRoad.checkDistance() - 1 << "/" << gameRoad.getTotalDistance() << endl;
		cout << "\t" << "Current Speed: " << (1100 - playerCar.getSpeed()) / 10 << " MpH" << endl;
		if (time_span.count() < 1) {
			cout << "\t" << "Current time: " << 0 << endl;
		}
		else {
			cout << "\t" << "Current time: " << setprecision(2) << time_span.count() << endl;
		}
		this_thread::sleep_for(chrono::milliseconds(playerCar.getSpeed()));
		system("cls");
		//for (int i = 0; i < 20; i++) {
		//	cout << endl;
		//}


		trafficVehicle1.moveTrafficVehicle(FIRST);
		trafficVehicle2.moveTrafficVehicle(SECOND);
		trafficVehicle3.moveTrafficVehicle(THIRD);
		trafficVehicle4.moveTrafficVehicle(FOURTH);
		obstacle.moveObstacle();

		gameRoad.incrementDistance();

		}

	}

	if (!playerCar.getCondition()) {
		cout << endl << "\t" << "Wasted!" << endl;
		cout << endl << "\t" << "Your result is: " << endl;
		cout << "\t" << gameRoad.checkDistance() - 1 << "/" << gameRoad.getTotalDistance() << endl << endl;
	}

	if (gameRoad.checkIfVictory()) {
		cout << endl << "\t" << "Congratulations! You made it to Kiev!" << endl;
		cout << endl << "\t" << "Your time is: " << endl;
		cout << "\t" << setprecision(2) << time_span.count() << endl << endl;
	}


}

//Основной поток
void Handling(GameRoad& gameRoad, PlayerCar& playerCar) {
	while (playerCar.getCondition() && !gameRoad.checkIfVictory())
	{
		
			int pressedButton = getch();
			//getch(); //Safety

			if (pressedButton == 13) {
				if (gameRoad.checkPause()) {
					gameRoad.unPause();
				}
				else {
					gameRoad.setPause();
				}
			}

			if (!gameRoad.checkPause()) {
			if (pressedButton == 72) playerCar.useAcceleration();
			else if (pressedButton == 80) playerCar.useBrake();
			else if (pressedButton == 75) playerCar.turnLeft();
			else if (pressedButton == 77) playerCar.turnRight();
			else if (pressedButton == 27) exit(0);

			//for (int i = 0; i < 20; i++) {
			//	cout << endl;
			//}

			system("cls");
			gameRoad.updateRoad();
			gameRoad.showRoad();
		}
	}
}



int main()
{
	PlayerCar playerCar;
	Traffic trafficCar1;
	Traffic trafficCar2;
	Traffic trafficCar3;
	Traffic trafficCar4;
	Obstacles obstacle;
	GameRoad gameRoad(playerCar, trafficCar1, trafficCar2, trafficCar3, trafficCar4, obstacle);

	gameLauncher();

	thread thr(Game, ref(gameRoad), ref(playerCar), ref(trafficCar1), ref(trafficCar2), ref(trafficCar3), ref(trafficCar4), ref(obstacle));
	Handling(gameRoad, playerCar);
	thr.join();

	system("pause");
}