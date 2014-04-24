/*
 * task.cpp
 *
 *  Created on: 2014年3月24日
 *      Author: weijian
 */

#include <string>
#include <unistd.h>

#include "task.h"

/******************************************************************
  Function:		Task::Task()
  Description:	线程类构造函数
  Input:		线程名、线程优先级、线程栈大小
  Output:		none
  Return:		none
  Others:		none
*******************************************************************/
Task::Task(const std::string &taskName, const _Int32 priority, const size_t stackSize)
{
	_isActivate 				= false;
	_taskInfo.pId				= getpid();
	_taskInfo.threadName		= taskName;
	_taskInfo.priority			= priority;
	_taskInfo.stackSize			= stackSize;
}

/******************************************************************
  Function:		Task::~Task()
  Description:	线程类析构函数，析构时取消线程
  Input:		none
  Output:		none
  Return:		none
  Others:		none
*******************************************************************/
Task::~Task()
{
	cancel();
}

/******************************************************************
  Function:		Task::activate()
  Description:	线程激活，此时才创建线程
  Input:		none
  Output:		none
  Return:		成功返回APP_STATUS_OK，失败返回APP_STATUS_ERROR
  Others:		none
*******************************************************************/
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

	/* 修改调度策略或者优先级后，要显式地设置继承调度属性inheritsched（系统不会给该属性设置默认值）, PTHREAD_EXPLICIT_SCHED为不继承（控制调度策略或优先级时必须采用），PTHREAD_INHERIT_SCHED为继承 */
	CHECK_PTHREAD_RETURN(pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED))

	/* 销毁线程属性 */
	CHECK_PTHREAD_RETURN(pthread_attr_destroy(&attr))

	_taskInfo.pThreadId = pthread_self();
	_isActivate = true;

	sleep(1);

	return APP_STATUS_OK;
}

/******************************************************************
  Function:		Task::cancel()
  Description:	取消线程
  Input:		none
  Output:		none
  Return:		成功返回APP_STATUS_OK，失败返回APP_STATUS_ERROR
  Others:		none
*******************************************************************/
_Int32 Task::cancel()
{
	if (!_isActivate)
	{
		return APP_STATUS_ERROR;
	}

	/* 取消线程 */
	CHECK_PTHREAD_RETURN(pthread_cancel(_taskInfo.threadId))

	return APP_STATUS_OK;
}

/******************************************************************
  Function:		Task::entryPoint()
  Description:	创建线程后调用的，启动线程的run函数
  Input:		线程this
  Output:		none
  Return:		none
  Others:		none
*******************************************************************/
void* Task::entryPoint(void *param)
{
	Task *pTask = static_cast<Task *>(param);
	pTask->run();

	return (void *)NULL;
}

/******************************************************************
  Function:		Task::getPriority()
  Description:	获取线程优先级
  Input:		none
  Output:		none
  Return:		成功返回APP_STATUS_OK，失败返回APP_STATUS_ERROR
  Others:		none
*******************************************************************/
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

/******************************************************************
  Function:		Task::setPriority()
  Description:	设置线程优先级
  Input:		线程优先级
  Output:		none
  Return:		成功返回APP_STATUS_OK，失败返回APP_STATUS_ERROR
  Others:		none
*******************************************************************/
_Int32 Task::setPriority(const _Int32 priority)
{
	if (!_isActivate)
	{
		return APP_STATUS_ERROR;
	}

	if (MIN_LINUX_PRIORITY > priority || MAX_LINUX_PRIORITY < priority)
	{
		return APP_STATUS_ERROR;
	}

	pthread_attr_t	attr;
	sched_param		priParam;

#ifdef __CYGWIN__
	priParam.sched_priority = priority;
#else
	priParam.__sched_priority = priority;
#endif

	CHECK_PTHREAD_RETURN(pthread_attr_init(&attr))
	CHECK_PTHREAD_RETURN(pthread_attr_setschedparam(&attr, &priParam))
	CHECK_PTHREAD_RETURN(pthread_attr_destroy(&attr))

	_taskInfo.priority = priority;

	return APP_STATUS_OK;
}

/******************************************************************
  Function:		Task::setSchedpolicy()
  Description:	设置线程的调度策略
  Input:		E_Schedpolicy
  Output:		none
  Return:		成功返回APP_STATUS_OK，失败返回APP_STATUS_ERROR
  Others:		none
*******************************************************************/
_Int32 Task::setSchedpolicy(const E_Schedpolicy schedpolicy)
{
	if (!_isActivate)
	{
		return APP_STATUS_ERROR;
	}

	pthread_attr_t	attr;

	CHECK_PTHREAD_RETURN(pthread_attr_init(&attr))
	CHECK_PTHREAD_RETURN(pthread_attr_setschedpolicy(&attr, schedpolicy))
	CHECK_PTHREAD_RETURN(pthread_attr_destroy(&attr))

	return APP_STATUS_OK;
}

/******************************************************************
  Function:		Task::getTaskInfo()
  Description:	获取线程信息结构
  Input:		S_TaskInfo
  Output:		S_TaskInfo
  Return:		成功返回APP_STATUS_OK，失败返回APP_STATUS_ERROR
  Others:		none
*******************************************************************/
_Int32 Task::getTaskInfo(S_TaskInfo& taskInfo)
{
	taskInfo = _taskInfo;

	return APP_STATUS_OK;
}

/******************************************************************
  Function:		Task::getTaskId()
  Description:	获取线程ID
  Input:		none
  Output:		none
  Return:		线程ID
  Others:		none
*******************************************************************/
_Int32 Task::getTaskId()
{
	return _taskInfo.threadId;
}

/******************************************************************
  Function:		Task::getTaskName()
  Description:	获取线程名称
  Input:		none
  Output:		none
  Return:		线程名称字符串的引用
  Others:		none
*******************************************************************/
std::string& Task::getTaskName()
{
	return _taskInfo.threadName;
}

