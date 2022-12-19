//
// Created by alex on 16.12.22.
//

#include "Mission.h"

std::string	Dive::returnTitle() {
	return ("Dive");
}

double	Dive::getDepth() {
	return (this->depth);
}

void	Dive::setDepth(double d) {
	this->depth = d;
}

void	Dive::accept(Visitor &v) {
	v.doDive(*this);
}

std::string	Lift::returnTitle() {
	return ("Lift");
}

double	Lift::getDepth() {
	return (this->depth);
}

void	Lift::setDepth(double d) {
	this->depth = d;
}

void	Lift::accept(Visitor &v) {
	v.doLift(*this);
}

std::string Move::returnTitle() {
	return ("Move");
}

double	Move::getX() {
	return (this->x);
}

double	Move::getY() {
	return (this->y);
}

void	Move::setCoord(double x, double y) {
	this->x = x;
	this->y = y;
}

void	Move::accept(Visitor &v) {
	v.doMove(*this);
}

std::string Return::returnTitle() {
	return ("Return");
}

void Return::accept(Visitor &v) {
	v.doReturn(*this);
}

void Return::setInit(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

double	Return::getX() {
	return (this->x);
}

double	Return::getY() {
	return (this->y);
}

double	Return::getZ() {
	return (this->z);
}