/*
 * baseTypeDefine.h
 *
 *  Created on: 2014年8月19日
 *      Author: weijian
 */

#ifndef LINUX_PROGRAM_COMMON_BASETYPEDEFINE_H_
#define LINUX_PROGRAM_COMMON_BASETYPEDEFINE_H_

typedef signed char			(Sint8);
typedef unsigned char	(Uint8);
typedef unsigned int		(Uint32);
typedef int							(Int32);


#define APP_STATUS_OK			(0)			/* 正确返回值 */
#define APP_STATUS_ERROR		(-1)		/* 错误返回值 */


#define CHECK_PTHREAD_RETURN(func) \
{ \
	Int32 ret; \
	if (0 != (ret = func)) \
	{ \
		std::cout << "ERROR: time(" << __TIME__ << "), " << "fineName(" << __FILE__ << "), " << \
		"line(" << __LINE__ << "), retrun valuse: " << ret << ", errno: " << errno << std::endl; \
		return APP_STATUS_ERROR; \
	} \
}

#define DELETE_BUF(buf) \
{ \
	if (NULL != buf) \
	{ \
		delete buf; \
		buf = NULL; \
	} \
}



#endif /* LINUX_PROGRAM_COMMON_BASETYPEDEFINE_H_ */
