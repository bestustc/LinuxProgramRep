/*
 * msgPool.cpp
 *
 *  Created on: 2014年4月14日
 *      Author: weijian
 */

#include "msgMemPool.h"

using namespace std;

MsgMemPool* MsgMemPool::_singletion = NULL;

MsgMemPool::MsgMemPool()
{
	for (_Uint32 i = 0; i < MAX_POOL_MSG_NUM; ++i)
	{
		_msgDeque.push_back(new S_DispatchMsg());
	}

	return;
}

MsgMemPool* MsgMemPool::getSingleton()
{
	if (NULL == _singletion)
	{
		_singletion = new MsgMemPool();
	}

	return _singletion;
}

_Int32 MsgMemPool::initialize()
{
	return APP_STATUS_OK;
}


