#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Полностью заменяет содержимое файла
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

	//Задача 29.1.Напишите программу, в которой реализована запись в файл и считывание из него. Пользователь бесконечно вводит строки, которые записываются в файл,
	//пока не будет набрана строка end. После этого, программа выводит содержимое файла в консоль и удаляет файл.
	cout << "Задача 29.1\n";
	ofstream out;
	out.open( "file.txt", ios::app);

	if (out.is_open()) {
		string input;
		do {
			cout << "Введите строку: \n";
			getline(cin, input);
			out << input << "\n";
		} while (input != "end");
	}
	else
		cout << "Ошибка открытия файла!\n";
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
		cout << "Ошибка открытия файла!\n";

	in.close();
	remove("file.txt");
	cout << "\n\n";

	//Задача 29.2.Создайте функцию overwrite(), которая принимает путь к файлу и строку, которая полностью заменяет содержимое файла.
	//Если файла не существует, то функция возвращает false. Если замена прошла успешно, функция возвращает true.
	cout << "Задача 29.2\n";
	string path1, str1;

	cout << "Введите путь к файлу: ";	
	getline(cin, path1);

	cout << "Введите строку, которая полностью заменяет содержимое файла: ";
	getline(cin, str1);
		
	if (overwrite(path1, str1))
		cout << "Замена прошла успешно!\n";
	else
		cout << "Файла не существует.\n";

	return 0;
}