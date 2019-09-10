#pragma once
#include <windows.h>
#include "Static.h"
//����������� �������� � ��������������
enum class Direction {
	UPWARD,
	DOWNWARD,
	LEFT,
	RIGHT,
};
//���������(�� ������, �� ����� ��������� ���)
enum class Inventory {
	KEY,
};
//����� ������: ��������� ��� ��������
class Player {
public:
	Player(int x, int y);
	//������������ �� �����
	bool Move(Direction dir, float diff, bool walkable);
	//�������������� � ���������
	std::string Use(std::shared_ptr<StaticObject>& object);
	
	int GetX() const;
	int GetY() const;
private: 
	//���������
	std::vector<std::pair<Inventory, std::string>> inventory;
	//����������
	float x_;
	float y_;
};