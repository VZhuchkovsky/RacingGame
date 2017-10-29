#include <iostream>
#include <iomanip>  // setprecision()
#include <conio.h> //getchar()

#include <vector>

#include <thread>
#include <chrono> // sleep_for, high_resolution_clock




using namespace std;

const int ROAD_WIDTH = 40;
int roadWidth() {
	return 40;
}
const int ROAD_LENGHT = 20;
const int DISTANCE = 400;

const enum Lane { 
	LANE_FIRST = 0,
	LANE_SECOND, 
	LANE_THIRD, 
	LANE_FOURTH , 
	LANE_OBSTACLE
};

class Traffic {
public:

	Traffic() 
	{
		//Начальная инициализация vehicle1Coords
		vehicleCoords = { { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } } };

		reborn_ = 0;
	};

	void moveVehicle(Lane chosenLane) 
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

	const vector<vector<vector<int>>>& getTrafficVehicle() const 
	{
		return vehicleCoords;
	}

	const int& isOnRoad() const 
	{
		return onRoad_;
	}

private:
	static const int roadLenght = ROAD_LENGHT;
	int onRoad_ = 0;
	int reborn_ = 0;
	vector<vector<vector<int>>> vehicleCoords;

};

class Obstacles {

public:
	Obstacles() 
	{
		obstacleCoords = { { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
		{ { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } } };

		reborn_ = 0;
	};

	void moveObstacle() 
	{

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

						if (i == 0 && j == (obstacleCoords[0].size() - 1))  //нижняя часть машинки из траффика по строкам
							obstacleCoords[i][j][o] = -1;
						
						if (i == 1 && j == (obstacleCoords[0].size() - 1))  //нижняя часть машинки из траффика по столбцам
							obstacleCoords[i][j][o] = 13 + o + rnd;
						
						if (i == 0 && o == 0 && j < (obstacleCoords[0].size() - 1))  //левая часть машинки из траффика по строкам не считая одного пикселя нижней части
							obstacleCoords[i][j][o] = -(obstacleCoords[0].size() - j);
						
						if (i == 1 && o == 0 && j < (obstacleCoords[0].size() - 1))  //левая часть машинки из траффика по стобцам не считая одного пикселя нижней части
							obstacleCoords[i][j][o] = 13 + rnd;
						
						if (i == 0 && o == (obstacleCoords[0][0].size() - 1) && 
							j < (obstacleCoords[0].size() - 1))  //правая часть машинки из траффика по строкам не считая одного пикселя нижней части
							obstacleCoords[i][j][o] = -(obstacleCoords[0].size() - j);
						
						if (i == 1 && o == (obstacleCoords[0][0].size() - 1) && 
							j < (obstacleCoords[0].size() - 1))  //правая часть машинки из траффика по столбцам не считая одного пикселя нижней части
							obstacleCoords[i][j][o] = 13 + (obstacleCoords[0][0].size() - 1) + rnd;
						

					}

				}
			}
			
			reborn_ = 1;

		}
	}

	const vector<vector<vector<int>>>& getObstacle() const 
	{
		return obstacleCoords;
	}

	const int& isOnRoad() const 
	{
		return onRoad_;
	}

private:
	static const int roadLenght = ROAD_LENGHT;
	int onRoad_ = 0;
	int reborn_ = 0;
	vector<vector<vector<int>>> obstacleCoords;
};


class PlayerCar {

public:
	PlayerCar() 
	{

		coords = { { 14,16 },{ 14,19 },{ 18,16 },{ 18,19 } }; //north-west, north-east, south-west, south-east
															 
		speed_ = 1000;
		alive_ = 1;
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
	void useAcceleration() 
	{
		if (speed_ > 150) 
			speed_ -= 100;
	}
	//Увеличивает время паузы
	void useBrake() 
	{
		if (speed_ < 950) 
			speed_ += 100;
	}

	const vector<vector<int>>& getCar() const
	{
		return coords;
	}

	void setBadCondition()
	{
		alive_ = 0;
	}

	const int isAlive() 
	{
		return alive_;
	}

	const int getSpeed()
	{
		return speed_;
	}

private:
	static const int carLenght_ = 5;
	static const int carWidth_ = 4;

	static const int roadLenght = ROAD_LENGHT;
	static const int roadWidth = ROAD_WIDTH;

	int car[carLenght_][carWidth_];
	vector <vector <int> > coords;
	int alive_ = 0;
	int speed_ = 0;

};

class GameRoad {

public:
	GameRoad(PlayerCar& playerCar, Traffic& trafficVehicle1, Traffic& trafficVehicle2, 
		Traffic& trafficVehicle3, Traffic& trafficVehicle4, Obstacles& obstacle) :
		playerCar_(playerCar), trafficVehicle1_(trafficVehicle1), trafficVehicle2_(trafficVehicle2), 
		trafficVehicle3_(trafficVehicle3), trafficVehicle4_(trafficVehicle4), obstacle_(obstacle) 
	{

		currentDistance_ = 1;
		pause_ = 0;
		victory_ = 0;

	};

	void updateRoad() 
	{

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

	void showRoad() 
	{

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

	void checkCollision(Lane chosenLane) 
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
	};

	void setPause() 
	{
		pause_ = 1;
	}

	void unPause() 
	{
		pause_ = 0;
	}

	const int& checkPause() const
	{
		return pause_;
	}

	const int& checkDistance() const 
	{
		return currentDistance_;
	}

	const int& getTotalDistance() const 
	{
		return distance;
	}

	void incrementDistance() 
	{
		++currentDistance_;
	}

	void isVictoryAchieved() {
		if (currentDistance_ > distance) 
			victory_ = 1;
		
	}

	const int& checkIfVictory() const
	{		
		return victory_;
	}

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

void gameLauncher() 
{
	int o = 0;
	cout << endl << "         " << "Welcome to Pixel Racing" << endl;
	cout << endl << "         " << "To start a game press any button..." << endl;
	o = getchar();
}

//Созданный поток
void Game(GameRoad& gameRoad, PlayerCar& playerCar, Traffic& trafficVehicle1, 
	Traffic& trafficVehicle2, Traffic& trafficVehicle3, Traffic& trafficVehicle4, Obstacles& obstacle) 
{

	using namespace chrono;

	trafficVehicle1.moveVehicle(LANE_FIRST);
	trafficVehicle2.moveVehicle(LANE_SECOND);
	trafficVehicle3.moveVehicle(LANE_THIRD);
	trafficVehicle4.moveVehicle(LANE_FOURTH);
	obstacle.moveObstacle();

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	high_resolution_clock::time_point t2;
	duration<double> time_span;

	while (playerCar.isAlive() && !gameRoad.checkIfVictory())	{
		if (gameRoad.checkPause()) {
			cout << "Double Enter for unpause." << endl;
			system("pause");
		}
		else {

		t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);

		gameRoad.isVictoryAchieved();

		gameRoad.checkCollision(LANE_FIRST);
		gameRoad.checkCollision(LANE_SECOND);
		gameRoad.checkCollision(LANE_THIRD);
		gameRoad.checkCollision(LANE_FOURTH);
		gameRoad.checkCollision(LANE_OBSTACLE);


		gameRoad.updateRoad();
		gameRoad.showRoad();
		cout << endl << "         " << "Current Distance: " << gameRoad.checkDistance() - 1;
		cout << "/" << gameRoad.getTotalDistance() << endl;
		cout << "         " << "Current Speed: " << (1100 - playerCar.getSpeed()) / 10 << " MpH";
		cout << endl;
		if (time_span.count() < 1) {
			cout << "         " << "Current time: " << 0 << endl;
		}
		else {
			cout << "         " << "Current time: " << setprecision(2) << time_span.count();
			cout << endl;
		}
		this_thread::sleep_for(chrono::milliseconds(playerCar.getSpeed()));
		system("cls");
		//for (int i = 0; i < 20; i++) {
		//	cout << endl;
		//}


		trafficVehicle1.moveVehicle(LANE_FIRST);
		trafficVehicle2.moveVehicle(LANE_SECOND);
		trafficVehicle3.moveVehicle(LANE_THIRD);
		trafficVehicle4.moveVehicle(LANE_FOURTH);
		obstacle.moveObstacle();

		gameRoad.incrementDistance();

		}

	}

	if (playerCar.isAlive() == 0) {
		cout << endl << "         " << "Wasted!" << endl;
		cout << endl << "         " << "Your result is: " << endl;
		cout << "         " << gameRoad.checkDistance() - 1 << "/" << gameRoad.getTotalDistance() << endl << endl;
	}

	if (gameRoad.checkIfVictory() != 0) {
		cout << endl << "         " << "Congratulations! You made it to Kiev!" << endl;
		cout << endl << "         " << "Your time is: " << endl;
		cout << "         " << setprecision(2) << time_span.count() << endl << endl;
	}


}

//Основной поток
void Handling(GameRoad& gameRoad, PlayerCar& playerCar) 
{
	while (playerCar.isAlive() && !gameRoad.checkIfVictory())	{
		
			int pressedButton = getch();
			//getch(); //Safety

			if (pressedButton == 13) {
				if (gameRoad.checkPause()) 
					gameRoad.unPause();
				
				else {
					gameRoad.setPause();
				}
			}

			if (gameRoad.checkPause() == 0) {
			if (pressedButton == 72) 
				playerCar.useAcceleration();
			else if (pressedButton == 80) 
				playerCar.useBrake();
			else if (pressedButton == 75) 
				playerCar.turnLeft();
			else if (pressedButton == 77) 
				playerCar.turnRight();
			else if (pressedButton == 27) 
				exit(0);

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

	thread thr(Game, ref(gameRoad), ref(playerCar), ref(trafficCar1), 
		ref(trafficCar2), ref(trafficCar3), ref(trafficCar4), ref(obstacle));
	Handling(gameRoad, playerCar);
	thr.join();

	system("pause");
}