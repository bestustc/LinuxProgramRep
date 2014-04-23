/*
 * typeDefine.h
 *
 *  Created on: 2014年3月24日
 *      Author: weijian
 */

#ifndef LINUX_PROGRAM_COMMON_TYPEDEFINE_H_
#define LINUX_PROGRAM_COMMON_TYPEDEFINE_H_

typedef unsigned char	Uint8;
typedef unsigned int	Uint32;
typedef int				Int32;
typedef unsigned long	Uint64;

#define APP_STATUS_OK		(0)
#define APP_STATUS_ERROR	(-1)

#define CHECK_RETURN(func) \
{ \
	_Int32 ret; \
	if (0 != (ret = func)) \
	{ \
		std::cout << "ERROR: time(" << __TIME__ << "), " << "fineName(" << __FILE__ << "), " << \
		"line(" << __LINE__ << "), retrun valuse: " << ret << ", errno: " << errno << std::endl; \
		return APP_STATUS_ERROR; \
	} \
}

#define CHECK_BUF(buf) \
{\
	if (NULL == buf) \
	{\
		std::cout << "ERROR: time(" << __TIME__ << "), " << "fineName(" << __FILE__ << "), " << \
				"line(" << __LINE__ << ")" << std::endl; \
		return APP_STATUS_ERROR; \
	}\
}

#define DELETE_BUF(buf) \
{ \
	if (NULL != buf) \
	{ \
		delete buf; \
		buf = NULL; \
	} \
}

#endif /* LINUX_PROGRAM_COMMON_TYPEDEFINE_H_ */
