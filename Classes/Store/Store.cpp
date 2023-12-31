#include"Store.h"

using namespace cocos2d;
USING_NS_CC;

//��ʼ������������Ӣ��
Store::Store() {
	//��������ÿ��Ӣ�۵���Ϣָ�벢������Vector��
	//ÿ��Ӣ�����ɹ̶���ʮ�ſ���

	//���ɶ����˹
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Aphelios::createInfo();
		_legendsPointer.pushBack(info);
	}
	//���ɿ�����
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Caitlyn::createInfo();
		_legendsPointer.pushBack(info);
	}
	//�����������
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Ezreal::createInfo();
		_legendsPointer.pushBack(info);
	}
	//����¬����
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Lucian::createInfo();
		_legendsPointer.pushBack(info);
	}
	//���ɶ���С��
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Miss_Fortune::createInfo();
		_legendsPointer.pushBack(info);
	}
	//���ɸ��׸�˹
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Graves::createInfo();
		_legendsPointer.pushBack(info);
	}
	//������¬˹
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Varus::createInfo();
		_legendsPointer.pushBack(info);
	}
	//���ɿ�������
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Katarina::createInfo();
		_legendsPointer.pushBack(info);
	}
	//���ɰ�����
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Akali::createInfo();
		_legendsPointer.pushBack(info);
	}
	//���ɰ���
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Annie::createInfo();
		_legendsPointer.pushBack(info);
	}
	//����ά����
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Viktor::createInfo();
		_legendsPointer.pushBack(info);
	}
	//�������
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Sona::createInfo();
		_legendsPointer.pushBack(info);
	}
	//���ɽ�
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Jhin::createInfo();
		_legendsPointer.pushBack(info);
	}
	//�����ư�֮��
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Viego::createInfo();
		_legendsPointer.pushBack(info);
	}
	//����������
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Qiyana::createInfo();
		_legendsPointer.pushBack(info);
	}
	//���ɿ���
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Kayn::createInfo();
		_legendsPointer.pushBack(info);
	}
	//���ɱ���ά˹
	for (int i = 0;i < 10;i++) {
		LegendInfo* info = Bel_Veth::createInfo();
		_legendsPointer.pushBack(info);
	}
}

//ˢ��ʱ���������Ӣ��
Vector<LegendInfo*> const Store::refresh() {
	Vector<LegendInfo*> storeLegendPointer;
	int n = _legendsPointer.size();
	for (int i = 0;i < STORE_SIZE;i++) {
		int order = rand() % n ;
		storeLegendPointer.pushBack(_legendsPointer.at(order));
	}
	return storeLegendPointer;
}