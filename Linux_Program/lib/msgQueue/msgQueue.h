/*
 * msgQueue.h
 *
 *  Created on: 2014年4月14日
 *      Author: weijian
 */

#ifndef MSGQUEUE_H_
#define MSGQUEUE_H_

#include <mqueue.h>

#include "msgQueueIf.h"

class MsgQueue : public MsgQueueIf
{
public:
	MsgQueue();
	~MsgQueue();

protected:
	virtual _Int32 sendMsg();
	virtual _Int32 recvMsg();

private:

};



#endif /* MSGQUEUE_H_ */
