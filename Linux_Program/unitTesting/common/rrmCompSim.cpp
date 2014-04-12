/*
 * rrmCompSim.cpp
 *
 *  Created on: 2014年3月26日
 *      Author: weijian
 */

/*
 * rrmComp.cpp
 *
 *  Created on: 2014年3月25日
 *      Author: weijian
 */

#include <iostream>

#include "rrmCompSim.h"

RrmCompSim::RrmCompSim(const std::string &name)
: Task(RRM_TASK_NAME, RRM_THREAD_PRIORITY, THREAD_STACK_SIZE), _compName(name)
{

}

RrmCompSim::~RrmCompSim()
{

}

void RrmCompSim::run()
{
	std::cout << _compName << " is running!\n";
}




