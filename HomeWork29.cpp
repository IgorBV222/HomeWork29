#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//��������� �������� ���������� �����
bool overwrite(string path, string str) {
	ofstream out;
	out.open(path, ios::in);
	if (out.is_open()) {
		string newstr = str;
		out << newstr;
		return true;
	}
	out.close();
	return false;
}


int main() {
	setlocale(LC_ALL, "Russian");

	//������ 29.1.�������� ���������, � ������� ����������� ������ � ���� � ���������� �� ����. ������������ ���������� ������ ������, ������� ������������ � ����,
	//���� �� ����� ������� ������ end. ����� �����, ��������� ������� ���������� ����� � ������� � ������� ����.
	cout << "������ 29.1\n";
	ofstream out;
	out.open( "file.txt", ios::app);

	if (out.is_open()) {
		string input;
		do {
			cout << "������� ������: \n";
			getline(cin, input);
			out << input << "\n";
		} while (input != "end");
	}
	else
		cout << "������ �������� �����!\n";
	out.close();

	ifstream in;
	in.open("file.txt");

	if (in.is_open()) {

		while (!in.eof()) {
			string str;
			getline(in, str);
			cout << str << '\n';
		}
	}
	else
		cout << "������ �������� �����!\n";

	in.close();
	remove("file.txt");
	cout << "\n\n";

	//������ 29.2.�������� ������� overwrite(), ������� ��������� ���� � ����� � ������, ������� ��������� �������� ���������� �����.
	//���� ����� �� ����������, �� ������� ���������� false. ���� ������ ������ �������, ������� ���������� true.
	cout << "������ 29.2\n";
	string path1, str1;

	cout << "������� ���� � �����: ";	
	getline(cin, path1);

	cout << "������� ������, ������� ��������� �������� ���������� �����: ";
	getline(cin, str1);
		
	if (overwrite(path1, str1))
		cout << "������ ������ �������!\n";
	else
		cout << "����� �� ����������.\n";

	return 0;
}