/*
 * typeDefine.h
 *
 *  Created on: 2014年3月24日
 *      Author: weijian
 */

#ifndef BASETYPEDEFINE_H_
#define BASETYPEDEFINE_H_

#include <iostream>
#include <errno.h>

typedef unsigned char	_Uint8;
typedef unsigned int	_Uint32;
typedef int				_Int32;

#define APP_STATUS_OK		(0)
#define APP_STATUS_ERROR	(-1)

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

#endif /* BASETYPEDEFINE_H_ */
