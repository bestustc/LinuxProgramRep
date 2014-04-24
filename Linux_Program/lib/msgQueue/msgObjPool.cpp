/*
 * msgPool.cpp
 *
 *  Created on: 2014年4月14日
 *      Author: weijian
 */

#include "msgObjPool.h"

using namespace std;

MsgObjPool* MsgObjPool::_singletion = NULL;

/******************************************************************
  Function:		MsgObjPool::MsgObjPool()
  Description:	消息对象池类的构造函数
  Input:		none
  Output:		none
  Return:		none
  Others:		none
*******************************************************************/
MsgObjPool::MsgObjPool() :
		_isInit(false), _maxMsgConut(0)
{

}

/******************************************************************
  Function:		MsgObjPool::getSingleton()
  Description:	获取消息对象池类单件
  Input:		none
  Output:		none
  Return:		成功返回MsgObjPool指针，失败返回NULL
  Others:		none
*******************************************************************/
MsgObjPool* MsgObjPool::getSingleton()
{
	if (!_isInit)
	{
		return NULL;
	}

	if (NULL == _singletion)
	{
		_singletion = new MsgObjPool();
	}

	return _singletion;
}

/******************************************************************
  Function:		MsgObjPool::initialize()
  Description:	消息对象池类的构造函数
  Input:		池中的最大消息个数（大于0时才有效）
  Output:		none
  Return:		成功返回APP_STATUS_OK，失败返回APP_STATUS_ERROR
  Others:		none
*******************************************************************/
_Int32 MsgObjPool::initialize(const _Int32 maxMsgConut)
{
	if (_isInit)
	{
		return APP_STATUS_OK;
	}

	if (0 >= maxMsgConut)
	{
		return APP_STATUS_ERROR;
	}

	for (_Int32 i = 0; i < maxMsgConut; ++i)
	{
		_msgDeque.push_back(new S_DispatchMsg());
	}

	_maxMsgConut = maxMsgConut;
	_isInit = true;
	return APP_STATUS_OK;
}


