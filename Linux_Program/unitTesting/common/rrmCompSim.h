/*
 * rrmCompSim.h
 *
 *  Created on: 2014年3月26日
 *      Author: weijian
 */

#ifndef LINUX_PROGRAM_UNIT_TESTING_COMMON_RRMCOMPSIM_H_
#define LINUX_PROGRAM_UNIT_TESTING_COMMON_RRMCOMPSIM_H_

#include "task.h"
#include "typeDefine.h"
#include "taskInfo.h"

class RrmCompSim: public Task
{
public:
	RrmCompSim(const std::string &name);
	virtual ~RrmCompSim();

public:
	Int32 initialize();

protected:
	void run();

private:
	std::string _compName;
};



#endif /* LINUX_PROGRAM_UNIT_TESTING_COMMON_RRMCOMPSIM_H_ */
