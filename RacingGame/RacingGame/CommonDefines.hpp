#ifndef COMMONDEFINES_HPP
#define COMMONDEFINES_HPP

const int ROAD_WIDTH = 40; //width of the game space
const int ROAD_LENGHT = 20; //lenght of the game space
const int DISTANCE = 400; //goal to reach

//lanes of the game space
const enum Lane {
	LANE_FIRST = 0,
	LANE_SECOND,
	LANE_THIRD,
	LANE_FOURTH,
	LANE_OBSTACLE
};

#endif COMMONDEFINES_HPP