#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <direct.h>

using namespace std;
using namespace System::IO::Compression;
using namespace System::IO;
using namespace System;


float yravn(int figure, float x, float y, int i) {
	float line1, line2, line3;
	double R2;
	switch (figure) {
	case 1:
		R2 = pow((x - 7), 2) + pow((y - 9), 2);
		return R2;
		break;
	case 2:
		if (i == 0) {
			line1 = (11 * x + 16) / 3;
			return line1;
		}
		if (i == 1) {
			line2 = 52 - 8 * x;
			return line2;
		}
		if (i == 1) {
			line3 = 10 - x;
			return line3;
		}
		break;
	case 3:
		R2 = (x - 8) * (x - 8) + (y - 6) * (y - 6);
		return R2;
		break;
	case 4:
		if (i == 0) {
			line1 = (43 - 8 * x) / 3;
			return line1;
		}
		if (i == 1) {
			line2 = 3 * x + 3;
			return line2;
		}
		break;
	case 5:
		if (i == 0) {
			R2 = (x - 8) * (x - 8) + (y - 7) * (y - 7);
			return R2;
		}
		if (i == 1) {
			line1 = (37 - 2 * x) / 3;
			return line1;
		}
		if (i == 2) {
			line2 = (x - 5) / 3;
			return line2;
		}
		break;
	case 6:
		if (i == 0) {
			R2 = (x - 7) * (x - 7) + (y - 13) * (y - 13);
			return R2;
		}
		if (i == 1) {
			line1 = (79 - 3 * x) / 5;
			return line1;
		}
		break;
	}
}

bool prin(float x, float y, int figure, float y1, float y2, float y3) {
	switch (figure) {
	case 2:
		if ((y <= y1) && (y <= y2) && (y >= y3)) { return true; }
		else { return false; }
		break;
	case 4:
		if ((y >= y1) && (y <= y2) && (x <= 5)) { return true; }
		else { return false; }
		break;
	case 5:
		if ((y >= y2) && (y <= y1) && (x >= 11)) { return true; }
		else { return false; }
		break;
	case 6:
		if ((y > y1) && (y <= 11) && (x <= 13)) { return true; }
		else { return false; }
		break;
	}
}

void transformToArchive(string& directoryName)
{
	String^ oldName = gcnew String(directoryName.c_str());
	String^ archiveName = gcnew String((directoryName + ".zip").c_str());
	if (File::Exists(archiveName)) File::Delete(archiveName);
	ZipFile::CreateFromDirectory(oldName, archiveName);
	Directory::Delete(oldName, true);
}

void task() {
	int i, j, p;
	float y1, y2, y3;
	double R;
	ofstream stream;
	string path1, path2, path3, path4, path5, way, wayout, dir, dir1;
	path3 = "IDZ";
	i = _mkdir(path3.c_str());
	for (p = 1; p < 7; p++) {
		way = "IDZ\\";
		if (p == 1) {
			way += "task1";
			_mkdir(way.c_str());
			path3 = way + "\\";
			path1 = "\\task";
			path1 += ".txt";
			way += path1;
			stream.open(way);
			stream << "�������� ��������� ��� �������� ��������� ��������� ��������� (x, y) ����������� ����� � ������� ����������� ���� �����:\r\n ���� (7;9), r=4; ������� (0;9), (0;15), (6;15), (6;9).\r\n������������ ������ ������� ���������� ����� int x, int y, ��������: 4, 0; ������ ������: yes, no.";
			stream.close();
		}
		if (p == 2) {
			way += "task2";
			_mkdir(way.c_str());
			path3 = way + "\\";
			path1 = "\\task";
			path1 += ".txt";
			way += path1;
			stream.open(way);
			stream << "�������� ��������� ��� �������� ��������� ��������� ��������� (x, y) ����������� ����� � ������� ����������� ���� �����:\r\n ����������� (1;9), (4;20), (6;4); ������������� (1;9), (1;13), (11;13), (11;9).\r\n������������ ������ ������� ���������� ����� int x, int y, ��������: 4, 0; ������ ������: yes, no.";
			stream.close();
		}
		if (p == 3) {
			way += "task3";
			_mkdir(way.c_str());
			path3 = way + "\\";
			path1 = "\\task";
			path1 += ".txt";
			way += path1;
			stream.open(way);
			stream << "�������� ��������� ��� �������� ��������� ��������� ��������� (x, y) ����������� ����� � ������� �������� ���� �����(�� 1 ���������� 2):\r\n ������������� (1;1), (1;4), (7;4), (7;1); ���� (8;6), r=4.\r\n������������ ������ ������� ���������� ����� int x, int y, ��������: 4, 0; ������ ������: yes, no.";
			stream.close();
		}
		if (p == 4) {
			way += "task4";
			_mkdir(way.c_str());
			path3 = way + "\\";
			path1 = "\\task";
			path1 += ".txt";
			way += path1;
			stream.open(way);
			stream << "�������� ��������� ��� �������� ��������� ��������� ��������� (x, y) ����������� ����� � ������� ����������� ���� �����:\r\n ����������� (5;1),(2;9),(5;18); ������� (3;2), (3;11), (12;11), (12;2); ������������� (2;6), (2;14), (8;14), (8;6).\r\n������������ ������ ������� ���������� ����� int x, int y, ��������: 4, 0; ������ ������: yes, no.";
			stream.close();
		}
		if (p == 5) {
			way += "task5";
			_mkdir(way.c_str());
			path3 = way + "\\";
			path1 = "\\task";
			path1 += ".txt";
			way += path1;
			stream.open(way);
			stream << "�������� ��������� ��� �������� ��������� ��������� ��������� (x, y) ����������� ����� � ������� ����������� ���� �����:\r\n ������������� (9;10), (9;13), (18;13), (18;10); ���� (8;7), r=4; ����������� (11;2), (11;5), (14;3).\r\n������������ ������ ������� ���������� ����� int x, int y, ��������: 4, 0; ������ ������: yes, no.";
			stream.close();
		}
		if (p == 6) {
			way += "task6";
			_mkdir(way.c_str());
			path3 = way + "\\";
			path1 = "\\task";
			path1 += ".txt";
			way += path1;
			stream.open(way);
			stream << "�������� ��������� ��� �������� ��������� ��������� ��������� (x, y) ����������� ����� � ������� �������� ���� ����� (2 � 3 ���������� �� 1):\r\n �������� (7;13), x>=7, r=5; ����������� (8;11), (13;11), (13;8); ������������� (3;7), (3;13), (10;13), (10;7).\r\n������������ ������ ������� ���������� ����� int x, int y, ��������: 4, 0; ������ ������: yes, no.";
			stream.close();
		}
		for (j = 0; j < 30; j++){
			path4 = path3 + "in";
			path5 = path3 + "out";
			i = _mkdir(path4.c_str());
			i = _mkdir(path5.c_str());
			way = "IDZ\\task";
			wayout = "IDZ\\task";
			way += 48 + (p % 10);
			dir = way;
			dir += "\\in";
			way += "\\in\\";
			wayout += 48 + (p % 10);
			dir1 = wayout;
			dir1 += "\\out";
			wayout += "\\out\\";
			path1 = "in";
			if (j / 10 > 0) path1 += 48 + ((j + 1) / 10);
			path1 += 48 + ((j + 1) % 10);
			path1 += ".txt";
			path2 = "out";
			if (j / 10 > 0) path2 += 48 + ((j + 1) / 10);
			path2 += 48 + ((j + 1) % 10);
			path2 += ".txt";
			way += path1;
			wayout += path2;
			stream.open(way);
			int inp_x = rand() % 21, inp_y = rand() % 21;
			stream << inp_x << endl;
			stream << inp_y;
			stream.close();
			stream.open(wayout);
			switch (p) {
			case 1:
				R = yravn(p, inp_x, inp_y, i);
				if ((inp_x >= 0) && (inp_x <= 6) && (inp_y >= 9) && (inp_y <= 15) && (R <= 16)) {
					stream << "��";
				}
				else { stream << "���"; }
				break;
			case 2:
				for (int k = 0; k < 3; k++) {
					if (k == 0) { y1 = yravn(p, inp_x, inp_y, k); }
					if (k == 1) { y2 = yravn(p, inp_x, inp_y, k); }
					if (k == 2) { y3 = yravn(p, inp_x, inp_y, k); }
				}
				if (prin(inp_x, inp_y, p, y1, y2, y3) != false) {
					stream << "��";
				}
				else if ((inp_x >= 1) && (inp_x <= 11) && (inp_y >= 9) && (inp_y <= 13)) {
					stream << "��";
				}
				else { stream << "���"; }
				break;
			case 3:
				R = yravn(p, inp_x, inp_y, i);
				if ((R > 4) && (inp_x >= 1) && (inp_x <= 7) && (inp_y >= 1) && (inp_y <= 4)) {
					stream << "��";
				}
				else { stream << "���"; }
				break;
			case 4:
				for (int k = 0; k < 2; k++) {
					if (k == 0) {
						y1 = yravn(p, inp_x, inp_y, k);
					}
					if (k == 1) {
						y2 = yravn(p, inp_x, inp_y, k);
					}
				}
				if ((prin(inp_x, inp_y, p, y1, y2, y3) != false) && (inp_x >= 3) && (inp_x <= 8) && (inp_y >= 6) && (inp_y <= 11)) {
					stream << "��";
				}
				else { stream << "���"; }
				break;
			case 5:
				for (int k = 0; k < 3; k++) {
					if (k == 0) {
						y1 = yravn(p, inp_x, inp_y, k);
					}
					if (k == 1) {
						y2 = yravn(p, inp_x, inp_y, k);
					}
					if (k == 2) {
						y3 = yravn(p, inp_x, inp_y, k);
					}
				}
				if (prin(inp_x, inp_y, p, y1, y2, y3) != false) {
					stream << "��";
				}
				else if ((inp_x >= 9) && (inp_x <= 18) && (inp_y >= 10) && (inp_y <= 13)) {
					stream << "��";
				}
				else if (R <= 4) {
					stream << "��";
				}
				else { stream << "���"; }
				break;
			case 6:
				for (int k = 0; k < 2; k++) {
					if (k == 0) {
						y1 = yravn(p, inp_x, inp_y, k);
					}
					if (k == 1) {
						R = yravn(p, inp_x, inp_y, k);
					}
				}
				if ((R <= 5) && (inp_x >= 7)) {
					if ((prin(inp_x, inp_y, p, y1, y2, y3) == false) && ((inp_x < 3) || (inp_x > 10) || (inp_y < 7) || (inp_y > 13))) {
						stream << "��";
					}
					else { stream << "���"; }
				}
				else { stream << "���"; }
				break;
			}
			stream.close();
		}
			transformToArchive(dir);
			transformToArchive(dir1);
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	task();
	return 0;
}