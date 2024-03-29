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
#include <unistd.h>

#include "rrmCompSim.h"

RrmCompSim::RrmCompSim(const std::string &compName)
: Task(RRM_TASK_NAME, RRM_THREAD_PRIORITY, THREAD_STACK_SIZE), _compName(compName)
{

}

RrmCompSim::~RrmCompSim()
{

}

Int32 RrmCompSim::initialize()
{
	return APP_STATUS_OK;
}

void RrmCompSim::run()
{
	std::cout << _compName << " is running!, priority is " << getPriority() << std::endl;

	int count(1);

	while (count)
	{
		std::cout << "count = " << count << std::endl;
		++count;
		sleep(1);
	}
}





