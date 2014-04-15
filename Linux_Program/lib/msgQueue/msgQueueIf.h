/*
 * msgQueueIf.h
 *
 *  Created on: 2014年4月14日
 *      Author: weijian
 */

#ifndef MSGQUEUEIF_H_
#define MSGQUEUEIF_H_

#include "../common/baseTypeDefine.h"

class MsgQueueIf
{
public:
	MsgQueueIf();
	virtual ~MsgQueueIf();

protected:
	virtual _Int32 sendMsg() = 0;
	virtual _Int32 revcMsg() = 0;


private:
	_Uint32		_msgCount;

	// todo 是否需要互斥？
};



#endif /* MSGQUEUEIF_H_ */
