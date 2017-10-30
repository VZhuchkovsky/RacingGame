#include <iostream>
#include <iomanip>  // setprecision()
#include <conio.h> //getchar()

#include <vector>

#include <thread>
#include <chrono> // sleep_for, high_resolution_clock

#include "GameRoad.hpp"



using namespace std;
 




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