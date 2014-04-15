/*
 * msgPool.cpp
 *
 *  Created on: 2014年4月14日
 *      Author: weijian
 */

#include "msgMemPool.h"

using namespace std;

MsgPool* MsgPool::_singletion = NULL;

MsgPool::MsgPool()
{
	for (_Uint32 i = 0; i < MAX_POOL_MSG_NUM; ++i)
	{
		_msgDeque.push_back(new S_DispatchMsg());
	}

	return;
}

MsgPool* MsgPool::getSingleton()
{
	if (NULL == _singletion)
	{
		_singletion = new MsgPool();
	}

	return _singletion;
}


