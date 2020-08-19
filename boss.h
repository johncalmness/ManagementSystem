#pragma once
#include<iostream>
using namespace std;
#include"worker.h"


class Boss :public Worker
{
public:
	Boss(int, string, int);

	void showInfo();

	string getDepName();
};