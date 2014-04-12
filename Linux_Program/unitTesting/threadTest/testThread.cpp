/*
 * threadTestMain.cpp
 *
 *  Created on: 2014年3月25日
 *      Author: weijian
 */

#include <iostream>
#include <gtest/gtest.h>

#include "typeDefine.h"
#include "rrmCompSim.h"
#include "connMgrCompSim.h"

TEST(THREAD_TEST, ONE)
{
	RrmCompSim *pRrm = new RrmCompSim("RRM Component");
	ConnMgrCompSim *pConnMgr = new ConnMgrCompSim("ConnMgr Component");

	pRrm->activate();
	pConnMgr->activate();

	std::cout << "Main thread is running!\n";

	DELETE_BUF(pRrm)
	DELETE_BUF(pConnMgr)
}

