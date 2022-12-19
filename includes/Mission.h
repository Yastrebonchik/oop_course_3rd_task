//
// Created by alex on 16.12.22.
//

#ifndef OOP_COURSE_3RD_TASK_MISSION_H
# define OOP_COURSE_3RD_TASK_MISSION_H

class Visitor;
class FileWriter;

# include "Visitor.h"

class	Mission {
public:
	virtual	std::string	returnTitle() = 0;
	virtual void	accept(Visitor &v) = 0;
};

class	Dive : public Mission {
public:
	void	accept(Visitor &v) override;
	std::string	returnTitle() override;
	void	setDepth(double d);
	double	getDepth();
private:
	double	depth;
};

class	Lift : public Mission {
public:
	void	accept(Visitor &v) override;
	std::string	returnTitle() override;
	void	setDepth(double d);
	double	getDepth();

private:
	double	depth;
};

class	Move : public Mission {
public:
	void	accept(Visitor &v) override;
	std::string	returnTitle() override;
	void	setCoord(double x, double y);
	double	getX();
	double	getY();
private:
	double	x;
	double	y;
};

class	Return : public Mission {
private:
	double	x;
	double	y;
	double	z;
public:
	void	accept(Visitor &v) override;
	double	getX();
	double	getY();
	double	getZ();
	void	setInit(double x, double y, double z);
	std::string	returnTitle() override;
};

#endif //OOP_COURSE_3RD_TASK_MISSION_H
