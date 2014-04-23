/*
 * typeDefine.h
 *
 *  Created on: 2014年3月24日
 *      Author: weijian
 */

#ifndef LINUX_PROGRAM_LIB_COMMON_BASETYPEDEFINE_H_
#define LINUX_PROGRAM_LIB_COMMON_BASETYPEDEFINE_H_

#include <iostream>
#include <errno.h>

typedef unsigned char	_Uint8;
typedef unsigned int	_Uint32;
typedef int				_Int32;

#define APP_STATUS_OK			(0)			/* 正确返回值 */
#define APP_STATUS_ERROR		(-1)		/* 错误返回值 */

#define MAX_POOL_MSG_NUM		(300)		/* 消息池中消息对象的最大个数 */


#define CHECK_PTHREAD_RETURN(func) \
{ \
	_Int32 ret; \
	if (0 != (ret = func)) \
	{ \
		std::cout << "ERROR: time(" << __TIME__ << "), " << "fineName(" << __FILE__ << "), " << \
		"line(" << __LINE__ << "), retrun valuse: " << ret << ", errno: " << errno << std::endl; \
		return APP_STATUS_ERROR; \
	} \
}

#endif /* LINUX_PROGRAM_LIB_COMMON_BASETYPEDEFINE_H_ */
