/*
 * rrmCompSim.h
 *
 *  Created on: 2014年3月26日
 *      Author: weijian
 */

#ifndef RRMCOMPSIM_H_
#define RRMCOMPSIM_H_

#include "task.h"
#include "taskInfo.h"

class RrmCompSim: public Task
{
public:
	RrmCompSim(const std::string &name);
	virtual ~RrmCompSim();

protected:
	void run();

private:
	std::string _compName;
};



#endif /* RRMCOMPSIM_H_ */
