#pragma once
#include <deque>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <utility>

//����� - ������ ��� ���� ��������, ������������ �� ������
class StaticObject {
public:
	StaticObject();
	//����������� ����� ��� �������������� ������
	virtual std::string Used(std::shared_ptr<StaticObject>& object);
	//"�������" (���������� ��� �������������� ������ � �������)
	std::vector<std::string> tries;
	//��������� � ��������� �����
	virtual char GetPol() const;
	virtual bool GetWalkableByPlayer() const;
	virtual std::string GetLocation() const;
protected:
	//������ �������, � ���� �������� �� ����� �����������
	char pol;
	//�����, ����� �� ��������� �� ������� ��� �������������� (������ wasd)
	bool WalkableByPlayer;
	//������� ��������������
	std::string location;
};

//�����
class Wall : public StaticObject {
public:
	Wall(const std::string& s);
};
//��������� ����
class Space : public StaticObject {
public:
	Space(const std::string& s);
};
//������ ������������(��������� �����)
class None : public StaticObject {
public:
	None(const std::string& s);
};
//����������� ������
class StaticPlayer : public StaticObject {
public:
	StaticPlayer(const std::string& s);
};
//�������� �����
class BreakableWall : public StaticObject {
public:
	BreakableWall(const std::string& s);
	BreakableWall();
	virtual std::string Used(std::shared_ptr<StaticObject>& object) override;
};
//�������������� �������� ����� (���������� ������ ��������)
class BreakableWallHorizontal : public BreakableWall {
public:
	BreakableWallHorizontal(const std::string& s);
};
//����
class Key : public StaticObject {
public:
	Key(const std::string& a, const std::string& b, const std::string& s);
	virtual std::string Used(std::shared_ptr<StaticObject>& object) override;
private:
	std::string value; //��������������� ����
	std::string name; //��� �����
};
//�����
class Door : public StaticObject {
public:
	Door(const std::string& a, const std::string& b, const std::string& s);
	virtual std::string Used(std::shared_ptr<StaticObject>& object) override;
private:
	std::string value; //"�����" �����, ����������� ��� ���������� � ������
	std::string name; //��� �����
};
//���������� ����
class Endgame : public StaticObject {
public:
	Endgame(const std::string& s);
	virtual std::string Used(std::shared_ptr<StaticObject>& object) override;
};