#pragma once
#include <deque>
#include <memory>
#include "Dynamic.h"
#include "Static.h"
#include "notes.h"
//����� ����
class Screen {
public:
	Screen(int height, int width, int spawn_x, int spawn_y, const std::string& file_path);
	void Loop();
	//�������� ������
	Player self = Player(1, 1);
	//��������� ������ �����������
	Notes NoteString = Notes("Notes");
	//��� �� �����-����������� �� �������, "�������������" �� ������
	std::deque<std::shared_ptr<StaticObject>> objects;

private:
	//���� � ����� � ������
	std::string FilePath;
	//����� ������� � ������ �������� ��� ����� ������
	wchar_t* screen;
	HANDLE hConsole;
	DWORD dwBytesWritten;
	//��������� ������, ������ � ������
	const int nScreenWidth;
	const int nScreenHeight;
	int nMapWidth = 0; //������ �����
	int nMapHeight = 0; //������ �����
	int SpawnPointX, SpawnPointY; //����� �� ������, ��� �������� �����
	//�������� �������� �� ����, ��� ������� ����� �� ����� ���������
	const int CameraX = 10;
	const int CameraY = 3;
	//����� ������ ���-�� �����
	int x_border = 0;
	int y_border = 0;
	//������������ �������� ������� �������
	std::string location;
	//����� �� ��, �������� �� ����� ������-���� �� ���� �����
	bool TouchUp = true;
	bool TouchLeft = true;
	bool TouchRight = false;
	bool TouchDown = false;

	void ParseMap();
	void SetToCoordinates(char ch, int x, int y);
	void MovePicture(Direction dir);
	void UpdatePicture();

	//��������� ����� ����������� ���� ������ �� ��� ����������� � ��������� �����
	template<typename T>
	std::shared_ptr<StaticObject> ObjectDefine(const std::string& s, const std::vector<T>& key) {
		std::shared_ptr<StaticObject> object;
		if (s == "e") {
			object = std::make_shared<Space>(location);
		}
		else if (s == "w") {
			object = std::make_shared<Wall>(location);
		}
		else if (s == "b") {
			object = std::make_shared<BreakableWall>(location);
		}
		else if (s == "bh") {
			object = std::make_shared<BreakableWallHorizontal>(location);
		}
		else if (s == "k") {
			object = std::make_shared<Key>(key.at(0), key.at(1), location);
		}
		else if (s == "d") {
			object = std::make_shared<Door>(key.at(0), key.at(1), location);
		}
		else if (s == "n") {
			object = std::make_shared<None>(location);
		}
		else if (s == "X") {
			object = std::make_shared<StaticPlayer>(location);
		}
		else if (s == "o") {
			object = std::make_shared<Endgame>(location);
		}
		else {
			location = s;
		}
		return object;
	}
	//��������� ������� �� ���������� ���������� � ���� ��������
	template<typename stream>
	void ParseObject(stream& input, int& num, std::string& obj,
		std::string& location, std::string& name, std::string& key) {
		input >> num;
		input >> obj;
		if (num == -1) {
			location = obj;
			input >> num;
			input >> obj;
		}
		if (obj == "k" || obj == "d") {
			input >> name;
			input >> key;
		}
	}
};