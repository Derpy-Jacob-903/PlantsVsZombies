#pragma once
#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"
#include "Based/LZGlobalVariable.h"

using namespace spine;
using namespace cocos2d;

class Zombies;

class Car:public Node
{
public:
	static Car* create(Node* node = nullptr);
	static void deleteCar(list<Car*>::iterator& car);
	void showCar();
	void setPosition(const Vec2& position);
	void setCarTag(const int tag);
	void setParent(Node* node);
	void setScale(const float& scale);
	void setLive(bool isLive);
	void setInRow(int row);
	int getInRow();
	bool getLive() const;
	int getCarTag() const;
	Sprite* getCar();
	void createCarListener();
	void carStartUp();
	
CC_CONSTRUCTOR_ACCESS:
	Car(Node* node = nullptr);
	~Car();

private:
	void createCarShadow();
	void createAppearSpecialEffect();
	bool getZombieIsSameLineWithCar(Zombies* zombie) const;
	bool getzombieIsEncounterCar(Zombies* zombie) const;
	int getZOrder() const;

private:
	Sprite* _carImage;    // С��ͼƬ
	Vec2 _position;       // λ��
	bool _isLive;         // �Ƿ񼤻�
	int _tag;             // ���
	int _row;             // ������
	int _carState;        // С��״̬
	float _scale;         // ��С
	Node* _node;          // ���ڵ�
	Global* _global;
};