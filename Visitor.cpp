//
// Created by alex on 16.12.22.
//

#include "Visitor.h"

FileWriter::FileWriter() {
	this->myFile.open("Mission.txt", std::ios::out);
	std::cout << "File is opened: " << myFile.is_open() << std::endl;
}

void	FileWriter::doLift(Lift &l) {
	this->myFile << "Id: " << this->_cnt << ". Lift to depth " << l.getDepth() << std::endl;
	this->_cnt++;
}

void	FileWriter::doDive(Dive &d) {
	this->myFile << "Id: " << this->_cnt << ". Dive to depth " << d.getDepth() << std::endl;
	this->_cnt++;
}

void 	FileWriter::doMove(Move &m) {
	this->myFile << "Id: " << this->_cnt << ". Move to coordinates " << m.getX() << " " << m.getY() << std::endl;
	this->_cnt++;
}

void	FileWriter::doReturn(Return &r) {
	this->myFile << "Id: " << this->_cnt << ". Return to initial position and ending the mission: ";
	this->myFile << r.getX() << " " << r.getY() << " " << r.getZ() << std::endl;
	this->_cnt++;
}

void FileWriter::writeToFile() {
	this->myFile.flush();
}

void	ConsoleWriter::setCnt(int cnt) {
	this->_cnt = cnt;
}

int		ConsoleWriter::getCnt() {
	return (this->_cnt);
}

void	ConsoleWriter::doLift(Lift &l) {
	std::cout << "Id: " << this->_cnt << ". Lift to depth " << l.getDepth() << std::endl;
	this->_cnt++;
}

void	ConsoleWriter::doDive(Dive &d) {
	std::cout << "Id: " << this->_cnt << ". Dive to depth " << d.getDepth() << std::endl;
	this->_cnt++;
}

void 	ConsoleWriter::doMove(Move &m) {
	std::cout << "Id: " << this->_cnt << ". Move to coordinates " << m.getX() << " " << m.getY() << std::endl;
	this->_cnt++;
}

void	ConsoleWriter::doReturn(Return &r) {
	std::cout << "Id: " << this->_cnt << ". Return to initial position and ending the mission: ";
	std::cout << r.getX() << " " << r.getY() << " " << r.getZ() << std::endl;
	this->_cnt++;
}