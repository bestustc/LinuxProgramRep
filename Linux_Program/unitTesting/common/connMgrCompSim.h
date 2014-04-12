/*
 * connMgrCompSim.h
 *
 *  Created on: 2014年3月26日
 *      Author: weijian
 */

#ifndef CONNMGRCOMPSIM_H_
#define CONNMGRCOMPSIM_H_

#include "task.h"
#include "taskInfo.h"

class ConnMgrCompSim : public Task
{
public:
	ConnMgrCompSim(const std::string &name);
	virtual ~ConnMgrCompSim();

protected:
	void run();

private:
	std::string		_name;
};

#endif /* CONNMGRCOMPSIM_H_ */