/*
 * task.cpp
 *
 *  Created on: 2014年3月24日
 *      Author: weijian
 */

#include <string>
#include <unistd.h>

#include "task.h"

Task::Task(const std::string &taskName, const _Int32 priority, const size_t stackSize)
{
	_isActivate 				= false;
	_taskInfo.pId				= getpid();
	_taskInfo.threadName		= taskName;
	_taskInfo.priority			= priority;
	_taskInfo.stackSize			= stackSize;
}

Task::~Task()
{

}

_Int32 Task::activate()
{
	if (_isActivate)
	{
		return APP_STATUS_OK;
	}

	pthread_attr_t	attr;
	sched_param		priParam;

	/* 初始化线程属性 */
	CHECK_PTHREAD_RETURN(pthread_attr_init(&attr))

	/* 设置线程为分离状态（运行完自行清理） */
	CHECK_PTHREAD_RETURN(pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED))

	/* 设置栈大小(单位：Byte) */
	CHECK_PTHREAD_RETURN(pthread_attr_setstacksize(&attr, _taskInfo.stackSize))

	/* 设置调度算法为SCHED_RR（实时、轮转法）和SCHED_FIFO（实时、先入先出）的可以设置优先级，仅对超级用户有效;SCHED_OTHER（正常、非实时）调度没有优先级，该调度是创建线程时的默认方式 */
	CHECK_PTHREAD_RETURN(pthread_attr_setschedpolicy(&attr, SCHED_RR))

#ifdef __CYGWIN__
	priParam.sched_priority = _taskInfo.priority;
#else
	priParam.__sched_priority = _taskInfo.priority;
#endif

	/* 设置优先级，程序中1表示优先级最低，99表示优先级最高。但是在内核中，[0,99]表示的实时进程的优先级，0最高，99最低。 */
	CHECK_PTHREAD_RETURN(pthread_attr_setschedparam(&attr, &priParam))

	/* 创建线程 */
	CHECK_PTHREAD_RETURN(pthread_create(&(_taskInfo.threadId), &attr, Task::entryPoint, (void *)this))

	/* 销毁线程属性 */
	CHECK_PTHREAD_RETURN(pthread_attr_destroy(&attr))

	_taskInfo.pThreadId = pthread_self();
	_isActivate = true;

	sleep(1);

	return APP_STATUS_OK;
}

_Int32 Task::cancel()
{
	if (!_isActivate)
	{
		return APP_STATUS_ERROR;
	}

	/* 取消线程 */
	CHECK_PTHREAD_RETURN(pthread_cancel(_taskInfo.threadId));

	return APP_STATUS_OK;
}

_Int32 Task::getPriority()
{
	if (_isActivate)
	{
		return _taskInfo.priority;
	}
	else
	{
		return APP_STATUS_ERROR;
	}

}

void* Task::entryPoint(void *param)
{
	Task *pTask = static_cast<Task *>(param);
	pTask->run();

	return (void *)NULL;
}

