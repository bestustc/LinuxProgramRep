/*
 * task.h
 *
 *  Created on: 2014年3月24日
 *      Author: weijian
 */

#ifndef TASK_H_
#define TASK_H_

#include <pthread.h>

#include "../common/baseTypeDefine.h"


typedef struct
{
	pthread_t		threadId;		/* 自己线程ID */
	pthread_t		pThreadId;		/* 父线程ID */
	pid_t			pId;			/* 进程ID */
	std::string		threadName;		/* 线程名称 */
	_Int32			priority;		/* 线程优先级 */
	size_t			stackSize;		/* 线程栈大小 byte */
}S_TaskInfo;

class Task
{
public:
	Task(const std::string &taskName, const _Int32 priority, const size_t stackSize);
	virtual ~Task();

public:
	_Int32 activate();
	_Int32 getPriority();

protected:
	virtual void run() = 0;
	static void *entryPoint(void *param);

private:
	bool		_isActivate;
	S_TaskInfo	_taskInfo;
};



#endif /* TASK_H_ */
