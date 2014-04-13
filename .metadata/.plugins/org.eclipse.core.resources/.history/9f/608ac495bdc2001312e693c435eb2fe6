/*
 * connMgrCompSim.cpp
 *
 *  Created on: 2014年3月26日
 *      Author: weijian
 */

#include <iostream>

#include "connMgrCompSim.h"

ConnMgrCompSim::ConnMgrCompSim(const std::string &name)
: Task(CONN_MGR_TASK_NAME, CONN_THREAD_PRIORITY, THREAD_STACK_SIZE), _name(name)
{

}

ConnMgrCompSim::~ConnMgrCompSim()
{

}

void ConnMgrCompSim::run()
{
	std::cout << _name << " is running!\n";
}
