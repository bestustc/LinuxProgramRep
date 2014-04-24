/*
 * msgMemPool.h
 *
 *  Created on: 2014年4月14日
 *      Author: weijian
 */

#ifndef LINUX_PROGRAM_LIB_MSG_QUEUE_MSGMEMPOOL_H_
#define LINUX_PROGRAM_LIB_MSG_QUEUE_MSGMEMPOOL_H_

#include <deque>

#include "typeDefine.h"
#include "../common/baseTypeDefine.h"

#define MSG_LEN_DISPATCH	(sizeof(S_DispatchMsg))

typedef struct
{
    Uint32			msgType;				/* 消息类型 */
    Uint32			extend;					/* 扩展字段 */
    Uint32			validBitLength;			/* 有效长度， 单位：bit */
} S_DispatchMsgHeade;

typedef struct
{
	S_DispatchMsgHeade		msgHeader;		/* 消息头 */
    Uint8					msgBuf[1];		/* 消息体 */
} S_DispatchMsg;

class MsgObj
{
public:
	MsgObj(const _Uint32 objType, const _Uint32 objTotalLen);
	~MsgObj();

public:
//	S_DispatchMsg* getDispatchMsg();
//	S_DispatchMsgHeade* getMsgHeade();
//	Uint8* getMsgBuf();

private:
	S_DispatchMsg 			*_pDispatchMsg;	/* 消息结构 */
	_Uint32					_objType;		/* 消息对象类型 */
	_Uint32					_objTotalLen;	/* 消息对象总长度 */
};

class MsgObjPool
{
public:
	MsgObjPool* getSingleton();
	~MsgObjPool();

public:
	_Int32 initialize(const _Int32 maxMsgConut);

private:
	MsgObjPool();

	static MsgObjPool			*_singletion;	/* 本类单件指针 */
	std::deque<MsgObj *>		_msgDeque;		/* 消息对象Deque */
	_Int32						_maxMsgConut;	/* 消息最大数目 */
	bool						_isInit;		/* 是否已经初始化消息对象池 */
};



#endif /* LINUX_PROGRAM_LIB_MSG_QUEUE_MSGMEMPOOL_H_ */
