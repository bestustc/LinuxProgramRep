/*
 * connMgrCompSim.h
 *
 *  Created on: 2014年3月26日
 *      Author: weijian
 */

#ifndef LINUX_PROGRAM_UNIT_TESTING_COMMON_CONNMGRCOMPSIM_H_
#define LINUX_PROGRAM_UNIT_TESTING_COMMON_CONNMGRCOMPSIM_H_

#include "task.h"
#include "baseTypeDefine.h"

class ConnMgrCompSim : public Task
{
public:
	ConnMgrCompSim(const std::string &compName);
	virtual ~ConnMgrCompSim();

public:
	Int32 initialize();

protected:
	void run();

private:
	std::string		_compName;
};

#endif /* LINUX_PROGRAM_UNIT_TESTING_COMMON_CONNMGRCOMPSIM_H_ */
