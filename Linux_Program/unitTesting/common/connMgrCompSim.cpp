/*
 * connMgrCompSim.cpp
 *
 *  Created on: 2014年3月26日
 *      Author: weijian
 */

#include <iostream>

#include "connMgrCompSim.h"

ConnMgrCompSim::ConnMgrCompSim(const std::string &compName)
: Task(CONN_MGR_TASK_NAME, CONN_THREAD_PRIORITY, THREAD_STACK_SIZE), _compName(compName)
{

}

ConnMgrCompSim::~ConnMgrCompSim()
{

}

Int32 ConnMgrCompSim::initialize()
{
	return APP_STATUS_OK;
}

void ConnMgrCompSim::run()
{
	std::cout << _compName << " is running!, priority is " << getPriority() << std::endl;
}
