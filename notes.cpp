#include "notes.h"
//�����, ����������� ���������� � ����������� �����������
std::string Notes::GetNote() const
{
	return CurrentNote;
}
//���������� ������: ���� ����� �� �����, �� ����������� �� �����-�� ��������,
//� ��������� ������, ��������� ������� ��������� �� ����������
void Notes::UpdateNote(const float diff)
{
	if (duration <= 0.0) {
		CurrentNote = ConstantNote;
	}
	else {
		duration -= diff;
	}
}
//��������� ����� "���������� ������"
void Notes::SetConstantNote(const std::string& note)
{
	ConstantNote = note;
}
//��������� ������, ������������ �� �����-�� �����
void Notes::SetTemporalNote(const std::string& note, float dur)
{
	CurrentNote = note;
	duration = dur;
}