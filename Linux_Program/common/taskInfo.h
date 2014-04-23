/*
 * taskInfo.h
 *
 *  Created on: 2014年3月24日
 *      Author: weijian
 */

#ifndef LINUX_PROGRAM_COMMON_TASKINFO_H_
#define LINUX_PROGRAM_COMMON_TASKINFO_H_

#define RRM_THREAD_PRIORITY		68
#define CONN_THREAD_PRIORITY	70


#define RRM_TASK_NAME		"tRrm"
#define CONN_MGR_TASK_NAME	"tConnMgr"

#ifdef _POSIX_THREAD_ATTR_STACKSIZE
#define THREAD_STACK_SIZE		(1048576 * 1)	/* 字节为单位， 1048576字节为1M，栈大小设置为10M */
#else
#define THREAD_STACK_SIZE		(1048576 * 1)	/* 字节为单位， 1048576字节为1M，栈大小设置为10M */
#endif



#endif /* LINUX_PROGRAM_COMMON_TASKINFO_H_ */
