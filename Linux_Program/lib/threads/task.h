/*
 * task.h
 *
 *  Created on: 2014年3月24日
 *      Author: weijian
 */

#ifndef LINUX_PROGRAM_LIB_THREAD_TASK_H_
#define LINUX_PROGRAM_LIB_THREAD_TASK_H_

#include <pthread.h>
#include <map>

#include "../common/baseTypeDefine.h"

#define MIN_LINUX_PRIORITY		(0)
#define MAX_LINUX_PRIORITY		(99)

typedef enum
{
	E_SCHED_OTHER	= 0,
	E_SCHED_FIFO	= 1,
	E_SCHED_RR		= 2
} E_Schedpolicy;

typedef struct
{
	pthread_t		threadId;		/* 自己线程ID */
	pthread_t		pThreadId;		/* 父线程ID */
	pid_t			pId;			/* 进程ID */
	std::string		threadName;		/* 线程名称 */
	_Int32			priority;		/* 线程优先级 */
	size_t			stackSize;		/* 线程栈大小 byte */
} S_TaskInfo;

class Task
{
public:
	Task(const std::string &taskName, const _Int32 priority, const size_t stackSize);
	virtual ~Task();

public:
	_Int32 activate();
	_Int32 cancel();
	_Int32 getPriority();
	_Int32 setPriority(const _Int32 priority);
	_Int32 setSchedpolicy(const E_Schedpolicy schedpolicy);
	_Int32 getTaskInfo(S_TaskInfo& taskInfo);
	_Int32 getTaskId();
	std::string& getTaskName();

protected:
	virtual void run() = 0;
	static void *entryPoint(void *param);

private:
	bool		_isActivate;
	S_TaskInfo	_taskInfo;
};


#endif /* LINUX_PROGRAM_LIB_THREAD_TASK_H_ */
