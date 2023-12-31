#pragma once
#ifndef STORE_H
#define STORE_H
#include<iostream>
#include"cocos2d.h"
#include"Player/Player.h"
#include"Legend/BaseLegend.h"
#include"Legend/Legends.h"
#include "AppDelegate.h"
USING_NS_CC;
const int STORE_SIZE = 5;
class Store :public Node {
private:
	Vector <class LegendInfo* > _legendsPointer;
public:
	Vector <class LegendInfo* > const refresh ();
	Store();
};
#endif 
