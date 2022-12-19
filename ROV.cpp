//
// Created by alex on 16.12.22.
//

#include "ROV.h"

enum Missions {ret, dive, lift, move};

ROV::ROV() {};

ROV::ROV(double x, double y, double z) : _x(x), _y(y), _z(z), _initX(x), _initY(y), _initZ(z) {}

ROV::~ROV() {
//	for (auto it = this->_missions.begin(); it != this->_missions.end() ; ++it) {
//		delete *it;
//	}
}

std::list<Mission *> &ROV::getMissions() {
	return (this->_missions);
}

Mission *ROV::createMission(std::string missionType) {

	if (missionType == "Dive") {
		Dive	*dive;
		double	depth;

		std::cout << "Enter depth" << std::endl;
		std::cin >> depth;
		if (depth < 0 || depth > this->_MAX_Z) {
			std::cout << "Wrong input. No mission is added." << std::endl;
			return (nullptr);
		}
		else {
			std::cout << "Added new mission to evaluate" << std::endl;
			dive = new Dive();
			dive->setDepth(depth);
			this->_z = depth;
			return (dive);
		}
	}
	else if (missionType == "Lift") {
		Lift	*lift;
		double	depth;

		std::cout << "Enter depth" << std::endl;
		std::cin >> depth;
		if (depth < 0 || depth > this->_MAX_Z) {
			std::cout << "Wrong input. No mission is added." << std::endl;
			return (nullptr);
		}
		else {
			std::cout << "Added new mission to evaluate" << std::endl;
			lift = new Lift();
			lift->setDepth(depth);
			this->_z = depth;
			return (lift);
		}
	}
	else if (missionType == "Move") {
		Move	*move;
		double x;
		double y;

		std::cout << "Enter coordinates with space" << std::endl;
		std::cin >> x >> y;
		if (x < 0 || y < 0 || x > this->_MAX_X || y > this->_MAX_Y) {
			std::cout << "Wrong input. No mission is added." << std::endl;
			return (nullptr);
		}
		else {
			std::cout << "Added new mission to evaluate" << std::endl;
			move = new Move();
			move->setCoord(x, y);
			this->_x = x;
			this->_y = y;
			return (move);
		}
	}
	else if (missionType == "Return") {
		Return	*ret;

		ret = new Return();
		std::cout << "Ending the ROV's mission. Returning to initial point" << std::endl;
		return (ret);
	}
	else {
		std::cout << "Mission type input incorrect. No mission is added." << std::endl;
		return (nullptr);
	}
}

bool ROV::addMission() {
	Mission	*mission;
	std::string	missionType;

	std::cout << "Enter mission type" << std::endl;
	std::cin >> missionType;
	mission = this->createMission(missionType);
	if (mission != nullptr) {
		this->_missions.push_back(mission);
		return (true);
	}
	return (false);
}

bool	ROV::insertMission() {
	Mission	*mission;
	std::string	missionType;
	int	id;

	std::cout << "Enter mission id to insert" << std::endl;
	std::cin >> id;
	if (id <= 0 || id > this->_missions.size()) {
		std::cout << "Incorrect id. No mission is inserted" << std::endl;
		return (false);
	}
	std::cout << "Enter mission type" << std::endl;
	std::cin >> missionType;
	mission = this->createMission(missionType);
	if (missionType == "Return") {
		std::cout << "Can't insert Return mission. Make it with command Add" << std::endl;
		return (false);
	}
	else {
		auto it = this->_missions.begin();
		for (int i = 1; i < id; ++i) {
			it++;
		}
		this->_missions.insert(it, mission);
		return (true);
	}
}

bool	ROV::eraseMission() {
	int	id;

	std::cout << "Enter mission id to erase" << std::endl;
	std::cin >> id;
	if (id <= 0 || id > this->_missions.size()) {
		std::cout << "Incorrect id. No mission is erased" << std::endl;
		return (false);
	}
	else {
		auto it = this->_missions.begin();
		for (int i = 1; i < id; ++i) {
			it++;
		}
		this->_missions.erase(it);
		std::cout << "Mission with id " << id << " is erased" << std::endl;
		return (true);
	}
}

bool	ROV::viewMission() {
	ConsoleWriter	writer;
	Mission	*mission;
	int	id;

	std::cout << "Enter mission id to view" << std::endl;
	std::cin >> id;
	if (id <= 0 || id > this->_missions.size()) {
		std::cout << "Incorrect id. No mission is found" << std::endl;
		return (false);
	}
	else {
		auto it = this->_missions.begin();
		for (int i = 1; i < id; ++i) {
			it++;
		}
		writer.setCnt(id);
		mission = *it;
		mission->accept(writer);
	}
}

bool ROV::listMission() {
	Mission	*output;
	ConsoleWriter	writer;

	writer.setCnt(1);
	for (auto it = this->getMissions().begin(); it != this->getMissions().end(); ++it) {
		output = *it;
		output->accept(writer);
	}
}

void ROV::printPosition() {
	std::cout << "ROV depth is " << this->_z << " .X is " << this->_x << " and Y is " << this->_y << std::endl;
}