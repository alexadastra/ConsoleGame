#pragma once
#include<string>
//����� �����������, ����������� ����� ������(���������� ���������, �������������� � ���������� � �.�.)
class Notes {
public:
	Notes(std::string const_note) {
		ConstantNote = const_note;
		CurrentNote = const_note;
		duration = 0.0;
	}
	
	std::string GetNote() const;
	
	void UpdateNote(const float diff);
	
	void SetConstantNote(const std::string& note);
	
	void SetTemporalNote(const std::string& note, float dur);

private:
	//�����������, ������������ �� ������ ������
	std::string CurrentNote;
	//�����������, ������� ���������� ��� ����� ���������
	std::string ConstantNote;
	//����, ���������� �� ��������� ��������� ������ �� ������
	float duration;
};