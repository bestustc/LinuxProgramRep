/*
 * main.cpp
 *
 *  Created on: 2014年3月3日
 *      Author: weijian
 */

#include "gtest/gtest.h"


int main(int agrc, char *agrv[])
{
	testing::InitGoogleTest(&agrc, agrv);

	testing::FLAGS_gtest_filter = "THREAD_TEST.*";

	return RUN_ALL_TESTS();
}
