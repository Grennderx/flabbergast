#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <typeinfo>
#include <math.h>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

//functions for the SIN task
bool compare_col(const vector<double>& v1, const vector<double>& v2) {
	return v1[0] > v2[0];
}
void vectorSort(vector<vector<double>>A) {
	int n = A.size();
	int m = A[0].size();
	/*cout << "2D before sorting" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "2D after sorting" << endl;*/
	sort(A.begin(), A.end(), compare_col);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
// recursion function
void recursionFunc(int m, int b, int c) {
	cout << "Для генерации введите любой символ" << endl;
	cout << "Для остановки введите F" << endl;
	string a;
	cin >> a;
	int si = 0;
	while (a != "F") {
		si = (m * si + b) % c;
		cout << si << endl;
		cin >> a;
	}

}


//FUNCTIONS FOR THE NUMBER SYSTEMS 
int fromLettoNum(char s) {
	switch (s) {
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
	}
}

int to10NS(string s, int ss) {
	int n = s.length();
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (!isdigit(s[i])) {
			int num1 = fromLettoNum(s[i]);
			int num2 = pow(ss, n - i - 1);
			int neum = num1 * num2;
			num += neum;
		}
		else {
			int num1 = int(s[i]) - 48;
			int num2 = pow(ss, n - i - 1);
			int neum = num1 * num2;
			num += neum;
		}
	}
	return num;
}

string from10toSS(int s, int ss) {
	string numstr0 = "";
	string numstr = "";
	while (s > 0) {
		int g = s % ss;
		if (g > 9) {
			int c = g + 55;
			int g = (char)c;
		}
		numstr0 += to_string(g);
		s /= ss;
	}
	
	for (int i = numstr0.length() - 1; i >= 0; i--) {
		numstr += numstr0[i];
	}
	return numstr;

}

string transSS(string s, int ss0, int ss1) {
	int a = to10NS(s, ss0);
	string b = from10toSS(a, ss1);
	return b;
}

// 2nd task functions
int sign(int x) {
	if (x > 0) {
		return 1;
	}
	else if (x == 0) {
		return 0;
	}
	return -1;
}

//3rd task functions
float rectangle(float a, float b) {
	return a * b;
}

float triangle(float a, float b, float c) {
	float p = (a + b + c) / 2;
	float s = pow(p * (p - a) * (p - b) * (p - c), 0.5);
	return s;
}	

float circle(float r) {
	return 2 * acos(0) * r * r;
}

int elemcount(char s, string l) {
	int k = 0;
	for (int i = 0; i < l.length(); i++) {
		if (l[i] == s) {
			k += 1;
		}
	}
	return k;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int tasknum;
	while (true) {
		cout << "Введите номер задания" << endl;
		cin >> tasknum;
		if (tasknum == 1) {
			cout << "Введите 10 чисел" << endl;
			ofstream file("task4.1.txt");
			ofstream out;
			out.open("task4.1.txt");

			for (int i = 0; i < 10; i++) {
				string num;
				cin >> num;
				for (int j = 0; j < num.length(); j++) {
					char c = num[j];
					if (!isdigit(c) and (not(j == 0 and c == '-' and num.length() != 1))) {
						cout << "Вы ввели НЕ число" << endl;
						i--;
						break;
					}
				}
				out << num << endl;
			}

			out.close();

			string num;
			ifstream in("task4.1.txt");
			int summ = 0;
			while (getline(in, num)) {
				summ += atoi(num.c_str());
			}

			cout << "Сумма чисел = " << summ << endl;
		}
		if (tasknum == 2) {
			int x;
			cout << "y = sign(x)" << endl << "Введите х" << endl;
			cin >> x;
			cout << sign(x) << endl;
		}
		if (tasknum == 3) {
			cout << "Введите стороны прямоугольника" << endl;
			float a, b;
			cin >> a >> b;
			cout << "S = " << rectangle(a, b) << endl;
			cout << "Введите стороны треугольника" << endl;
			float a1, b1, c1;
			cin >> a1 >> b1 >> c1;
			cout << "S = " << triangle(a1, b1, c1) << endl;
			cout << "Введите радиус круга" << endl << setw(10);
			float r;
			cin >> r;
			cout << "S = " << circle(r) << endl;
		}
		if (tasknum == 4) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			string m = "===================";
			int n = m.length();
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					SetConsoleTextAttribute(hConsole, 9);
					cout << setw(2) << "*";
				}
				SetConsoleTextAttribute(hConsole, 12 * (i % 2 == 0) + 15 * (i % 2 != 0));
				cout << "===================";
				cout << endl;
			}
			for (int i = 0; i < 5; i++) {
				SetConsoleTextAttribute(hConsole, 12 * (i % 2 == 0) + 15 * (i % 2 != 0));
				cout << setw(2);
				for (int j = 0; j < 7 * 2 + 1 + n; j++) {
					cout << "=";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, 15);
		}

		if (tasknum == 5) {
			vector<vector<double>> sinums;
			double k = 0;
			for (double m = -8.0; m <= 8.0; m += 0.5) {
				double x = m * acos(0);
				sinums.push_back({ sin(x), x, k });
				k += 1;
			}
			int m = sinums.size();
			int n = sinums[0].size();
			/*for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					cout << sinums[i][j] << " ";

				}
				cout << endl;
			}*/
			vectorSort(sinums);


			// вывод 2D списка
			/*int temp = 0;
			for (int i = 0; i < m - 1; i++) {
				if (sinums[i][0] > sinums[i + 1][0]) {
					for (int j = temp; j <= i; j++) {
						for (int k = temp; k < j; k++) {
							if (sinums[k][2] > sinums[k + 1][2]) {
								int tmp = sinums[k][2];
								sinums[k][2] = sinums[k + 1][2];
								sinums[k + 1][2] = tmp;
							}
						}

					}

				}
			}
			*/
			vector<double> row{ 0 };
			for (int i = 0; i < m - 1; i++) {
				row.push_back(sinums[i][2]);
				if (sinums[i][0] != sinums[i + 1][0]) {
					sort(row.begin(), row.end());
					for (int j = 1; j < row.size(); j++) {
						for (int c = 0; c < (row[j] - row[j - 1]); c++) {
							cout << " ";
						}
						cout << "*";
					}
					row.clear();
					row.push_back(0);

				}

			}
		}
		if (tasknum == 7) {
			cout << "Введите вариант" << endl;
			int variant;
			cin >> variant;
			if (variant == 1) {
				recursionFunc(37, 3, 64);
			}
			else {
				recursionFunc(25173, 13849, 65537);
			}
		}
		if (tasknum == 9) {
			string a;
			int b, c;
			cout << "Введите исходное число: ";
			cin >> a;
			cout << endl << "Введите старое основание: ";
			cin >> b;
			cout << endl << "Введите новое основание: ";
			cin >> c;
			cout << endl << "Число в новом основании: " << transSS(a, b, c) << endl;
		}
		if (tasknum == 10) {
			map<char, int> nums;
			nums['I'] = 1;
			nums['V'] = 5;
			nums['X'] = 10;
			nums['L'] = 50;
			nums['C'] = 100;
			nums['D'] = 500;
			nums['M'] = 1000;
			string l;
			cin >> l;
			int sum = 0;
			int k = 0;
			for (int i = 0; i < l.length() - 1; i++) {
				int a = nums[l[i]];
				if (a == 1 or a == 10 or a == 100 or a == 1000) {
					if (l.length() >= 4) {
						if (elemcount(l[i], l) > 3) {
							if (l[i] == l[i + 1] == l[i + 2] == l[i + 3]) {
								k += 1;
								cout << "Ошибка" << endl;
								break;
							}
						}
					}
				}
				else if (a == 5 or a == 50 or a == 500) {
					if (elemcount(l[i], l) > 1) {
						k += 1;
						cout << "Ошибка" << endl;
						break;
					}
				}
			}
			if (k == 0) {
				for (int i = 0; i < l.length() - 1; i++) {
					char f = l[i];
					char g = l[i + 1];
					if (f != g and nums[f] < nums[g]) {
						if ((f == 'I' and !(g == 'V' or g == 'X')) or (f == 'X' and !(g == 'L' or g == 'C')) or (f == 'C' and !(g == 'D' or g == 'M'))) {
							k += 1;
							cout << "Ошибка" << endl;
							break;
						}
					}
				}
			}
			if (k == 0) {
				for (int i = 0; i < l.length() - 2 + (l.length() <= 2); i++) {
					int a = nums[l[i]];
					int b = nums[l[i + 1]];
					int c = nums[l[i + 2]];
					if ((a < b and b < c) or (((b - a) >= pow(10, to_string(b).length() - to_string(a).length()) - 1)) && b - a != 0 or (((c - b) >= pow(10, to_string(c).length() - to_string(b).length()) - 1)) && c - b != 0) {
						cout << "Ошибка" << endl;
						k += 1;
						break;
					}
				}
			}
			/*for (int i = 0; i < l.length() - 2 + (l.length() <= 2); i++) {
				int a = nums[l[i]];
				int b = nums[l[i + 1]];
				int c = nums[l[i + 2]];
				if ((a < b and b < c) or (((b - a) >= pow(10, to_string(b).length() - to_string(a).length()) - 1)) && b - a != 0) {
					cout << "Ошибка" << endl;
					k += 1;
					break;
				}
				else if (l.length() > 4) {
					if ((a == b == c and (a == nums[l[i - 1]] or a == nums[l[i + 3]]))) {
						cout << "Ошибка" << endl;
						k += 1;
						break;
					}
				}
				if ((a == b or b == c or a == nums[l[i - 1]]) and (a == 5 or a == 50 or a == 500)){
					cout << "Ошибка" << endl;
					k += 1;
					break;
				}
			}*/
			if (k == 0) {
				for (int i = 0; i < l.length() - 1; i++) {
					int a = nums[l[i]];
					int b = nums[l[i + 1]];
					if (a >= b) {
						sum += a;
					}
					else {
						sum += (b - a);
						i += 1;
						
					}
				}
				if (k == 0) {
					if (nums[l[l.length() - 1]] <= nums[l[l.length() - 2]]) {
						sum += nums[l[l.length() - 1]];
					}
					cout << sum << endl;
				}
			}

		}
		if (tasknum == 11) {
			double aMatrix[3][4] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} };
			double bMatrix[4][2] = { {1.2, 0.5}, {2.8, 0.4}, {5, 1}, {2, 1.5} };
			double product[3][2] = { {0, 0}, {0, 0}, {0, 0} };

			for (int row = 0; row < 3; row++) {
				for (int col = 0; col < 2; col++) {
					for (int inner = 0; inner < 4; inner++) {
						product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
					}
				}
			}
			//1)
			double kmax = 0;
			double kmin = pow(10, 6);
			for (int i = 0; i < 3; i++) {
				kmax = max(product[i][0], kmax);
				kmin = min(product[i][0], kmax);
			}
			for (int i = 0; i < 3; i++) {
				if (product[i][0] == kmax) {
					cout << "Продавец №" << i + 1 << " - больше всего денег с продажи (" << kmax << ")" << endl;
				}
				if (product[i][0] == kmin) {
					cout << "Продавец №" << i + 1 << " - меньше всего денег с продажи (" << kmin << ")" << endl;
				}
			}
			//2)
			kmax = 0;
			kmin = pow(10, 6);
			for (int i = 0; i < 3; i++) {
				kmax = max(product[i][1], kmax);
				kmin = min(product[i][1], kmax);
			}
			for (int i = 0; i < 3; i++) {
				if (product[i][1] == kmax) {
					cout << "Продавец №" << i + 1 << " - наибольшие комиссионные (" << kmax << ")" << endl;
				}
				if (product[i][1] == kmin) {
					cout << "Продавец №" << i + 1 << " - наименьшие комиссионные (" << kmin << ")" << endl;
				}
			}
			//3)
			double summ = 0;
			for (int i = 0; i < 3; i++) {
				summ += product[i][0];
			}
			cout << "Общая сумма вырученных денег = " << summ << endl;
			//4)
			double summ1 = 0;
			for (int i = 0; i < 3; i++) {
				summ1 += product[i][1];
			}
			cout << "Всего комиссионных = " << summ1 << endl;
			//5)
			cout << "Всего денег прошло = " << summ + summ1 << endl;
		}
		
	}
} 
