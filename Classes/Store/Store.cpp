#include"Store.h"

using namespace cocos2d;
USING_NS_CC;

//初始化卡池中所有英雄
Store::Store() {
	//以下生成每个英雄的信息指针并保存在Vector中
	//每个英雄生成固定的十张卡牌

	//生成厄斐琉斯
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Aphelios::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成凯特琳
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Caitlyn::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成伊泽瑞尔
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Ezreal::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成卢锡安
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Lucian::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成厄运小姐
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Miss_Fortune::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成格雷福斯
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Graves::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成瓦卢斯
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Varus::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成卡特琳娜
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Katarina::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成阿卡丽
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Akali::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成安妮
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Annie::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成维克托
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Viktor::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成娑娜
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Sona::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成烬
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Jhin::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成破败之王
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Viego::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成奇亚娜
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Qiyana::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成凯隐
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Kayn::createInfo();
		_legendsPointer.pushBack(info);
	}
	//生成卑尔维斯
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Bel_Veth::createInfo();
		_legendsPointer.pushBack(info);
	}
}

//刷新时，随机生成英雄
Vector<LegendInfo*> const Store::refresh() {
	Vector<LegendInfo*> storeLegendPointer;
	int n = _legendsPointer.size();
	for (int i = 0;i < STORE_SIZE;i++) {
		int order = rand() % n ;
		storeLegendPointer.pushBack(_legendsPointer.at(order));
	}
	return storeLegendPointer;
}