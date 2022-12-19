//
// Created by alex on 16.12.22.
//

#include "Input.h"

enum Commands {add, erase, insert, list, view, printHelp, pos, wrongCommand};

void	Input::printHelper() {
	std::cout << "Commands list:" << std::endl;
	std::cout << "1: Add - add new mission to the evaluate" << std::endl;
	std::cout << "2: Erase - removes a mission under with entered id" << std::endl;
	std::cout << "3: Insert - inserts mission with the " << std::endl;
	std::cout << "4: List - prints all missions already evaluated" << std::endl;
	std::cout << "5: View - prints details of the mission with entered id" << std::endl;
	std::cout << "6: Help - prints this message" << std::endl;
	std::cout << "7: Position - prints ROV current position" << std::endl;
	std::cout << "To end the program correctly you need to add \"Return\" mission with the add command. ";
	std::cout << "Otherwise missions won't be written to the file" << std::endl;
	std::cout << "You need to enter values in next limits: " << "Depth >= 0 && <= 100. ";
	std::cout << "X and Y coordinates >= 0 && <= 10000" << std::endl;
	std::cout << "You need to enter commands as it shown above. They are case sensitive." << std::endl;
}
int	Input::detectCommand(std::string input) {
	if (input == "Add")
		return add;
	else if (input == "Erase")
		return erase;
	else if (input == "Insert")
		return insert;
	else if (input == "List")
		return list;
	else if (input == "View")
		return view;
	else if (input == "Help")
		return printHelp;
	else if (input == "Position")
		return (pos);
	else
		return wrongCommand;
}

void Input::start(ROV &rov) {
	Mission	*mission;
	Mission	*output;
	std::string	input;
	FileWriter	writer;
	int	command;

	this->printHelper();
	while (1) {
		std::cout << "Input command" << std::endl;
		std::cin >> input;
		command = detectCommand(input);
		switch (command) {
			case add:
				rov.addMission();
				break;
			case erase:
				rov.eraseMission();
				break;
			case insert:
				rov.insertMission();
				break;
			case list:
				rov.listMission();
				break;
			case view:
				rov.viewMission();
				break;
			case printHelp:
				this->printHelper();
				break;
			case pos:
				rov.printPosition();
				break;
			case wrongCommand:
				std::cout << "Wrong input. Enter another command!" << std::endl;
				break;
		}
		mission = *rov.getMissions().rbegin();
		if (mission && mission->returnTitle() == "Return") {
			for (auto it = rov.getMissions().begin(); it != rov.getMissions().end(); ++it) {
				output = *it;
				output->accept(writer);
			}
			writer.writeToFile();
			break;
		}
	}
	return;
}