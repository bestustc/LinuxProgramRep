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

typedef signed char			(_Sint8);
typedef unsigned char	(_Uint8);
typedef unsigned int		(_Uint32);
typedef int							(_Int32);

#define APP_STATUS_OK			(0)			/* 正确返回值 */
#define APP_STATUS_ERROR		(-1)		/* 错误返回值 */


#endif /* LINUX_PROGRAM_LIB_COMMON_BASETYPEDEFINE_H_ */
