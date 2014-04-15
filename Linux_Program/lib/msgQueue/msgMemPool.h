/*
 * msgMemPool.h
 *
 *  Created on: 2014年4月14日
 *      Author: weijian
 */

#ifndef MSGMEMPOOL_H_
#define MSGMEMPOOL_H_

#include <deque>

#include "typeDefine.h"
#include "../common/baseTypeDefine.h"

typedef struct
{
    Uint32			msgType;			/* 消息类型 */
    Uint32			extend;				/* 扩展字段 */
    Uint32			validBitLength;		/* 有效长度， 单位：bit */
} S_DispatchMsgHeade;

typedef struct
{
	S_DispatchMsgHeade		msgHeader;		/* 消息头 */
    Uint8					msgBuf[1];		/* 消息体 */
} S_DispatchMsg;

class MsgMemObj
{

};

class MsgMemPool
{
public:
	MsgMemPool* getSingleton();
	~MsgMemPool();

public:
	_Int32 initialize();

private:
	MsgMemPool();

	static MsgMemPool					*_singletion;
	std::deque<S_DispatchMsg *>		_msgDeque;
};



#endif /* MSGMEMPOOL_H_ */
