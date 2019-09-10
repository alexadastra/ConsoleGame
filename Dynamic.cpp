#include "Dynamic.h"

Player::Player(int x, int y) {
	x_ = float(x);
	y_ = float(y);
}
//���� � ����������� ������� ����� ����, ���������� �������� �� �����-��
//������������ ����� (��� ����� ������������� �������� ������������ �� �����)
bool Player::Move(Direction dir, float diff, bool walkable) {
	if (walkable) {
		switch (dir)
		{
		case Direction::UPWARD:
			y_ -= diff;
			break;
		case Direction::DOWNWARD:
			y_ += diff;
			break;
		case Direction::LEFT:
			x_ -= diff;
			break;
		case Direction::RIGHT:
			x_ += diff;
			break;
		}
		return true;
	}
	return false;
}
//����������� ��������� � �����
int Player::GetX() const {
	return int(x_);
}
int Player::GetY() const {
	return int(y_);
}

std::string Player::Use(std::shared_ptr<StaticObject>& object) {
	std::string str;
	for (auto a : inventory)
		object->tries.push_back(a.second);
	std::string inv = object->Used(object);
	object->tries.clear();
	if (inv != "") {
		std::stringstream s(inv);
		s >> str;
		if (str == "Key") { //���� ����, �� ����� �������� � ���������
			s >> str;
			inventory.push_back({ Inventory::KEY, str });
			return "You found a key of " + str + " !";
		}
		else { //� ��������� ������ ������ ������� ���������
			return inv;
		}
	}
	return "";
}