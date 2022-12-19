//
// Created by alex on 16.12.22.
//

#ifndef OOP_COURSE_3RD_TASK_ROV_H
# define OOP_COURSE_3RD_TASK_ROV_H

# include "Mission.h"
# include <list>
# include <iostream>

class ROV {

private:
	double _x = 0;
	double _y = 0;
	double _z = 0;

	double	_initX = 0;
	double	_initY = 0;
	double	_initZ = 0;

	const int _MAX_X = 10000;
	const int _MAX_Y = 10000;
	const int _MAX_Z = 100;

	std::list<Mission*>	_missions;

	Mission*	createMission(std::string missionType);
public:
	ROV();
	ROV(double x, double y, double z);
	~ROV();

	bool	addMission();
	bool	insertMission();
	bool	eraseMission();
	bool	listMission();
	bool	viewMission();
	void	printPosition();
	std::list<Mission*>	&getMissions();
};


#endif //OOP_COURSE_3RD_TASK_ROV_H
