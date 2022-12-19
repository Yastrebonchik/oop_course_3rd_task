//
// Created by alex on 16.12.22.
//

#ifndef OOP_COURSE_3RD_TASK_INPUT_H
# define OOP_COURSE_3RD_TASK_INPUT_H

# include "ROV.h"
# include "Visitor.h"
# include <string>
# include <iostream>
# include <strstream>

class Input {
private:
	void	printHelper();
	int		detectCommand(std::string input);

public:
	void	start(ROV	&rov);
};


#endif //OOP_COURSE_3RD_TASK_INPUT_H
