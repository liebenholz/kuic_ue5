#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct stTest {
	int a = 0;
	int b = 0;

	void printTest() {
		printf("a: %d, b: %d\n", a, b);
	}
};

struct stScore {
	string m_name = "";
	int m_math = 0;
	int m_eng = 0;
	int m_lang = 0;

	stScore(string name, int math, int eng, int lang) :
		m_name(name), m_math(math), m_eng(eng), m_lang(lang) { }

	void printTest() {
		printf("name: %s, math: %d, eng: %d, lang: %d\n", m_name.c_str(), m_math, m_eng, m_lang);
	}
};

void fileWrite() {
	// ���� ����
	std::ofstream writeFile;
	writeFile.open("test.txt");	// test.txt ������ ����(������ ���ٸ� �����Ѵ�)

	std::string strTest = "test 1234 asdf �Դϴ�.\n";
	writeFile.write(strTest.c_str(), strTest.size());
	writeFile.write(strTest.c_str(), strTest.size());

	writeFile.close();		// ������ �������� �ݵ�� �ݱ� ����.

}

void fileRead() {
	// ���� ����
	std::ofstream writeFile;
	// writeFile.open("test.txt");	// test.txt ������ ����(������ ���ٸ� �����Ѵ�)

	// std::string strTest = "test 1234 asdf �Դϴ�.\n";
	// writeFile.write(strTest.c_str(), strTest.size());
	// writeFile.write(strTest.c_str(), strTest.size());

	// writeFile.close();		// ������ �������� �ݵ�� �ݱ� ����.

	// ���� �б�
	std::ifstream readFile;
	readFile.open("test.txt");	// test.txt ������ �д´�

	stTest test;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			std::string str;
			std::getline(readFile, str);	// readFile�� �ؽ�Ʈ�� �� �� �о� str�� �ִ´�.
			printf("str: %s\n", str.c_str());

			// =�� �������� parse
			int nPoint = str.find('=');
			size_t index = 0;
			// �պκ��� a�� �� ���� test.a�� ����ֱ�
			if (str.substr(0, nPoint) == "a") {
				// printf("%s\n", str.substr(nPoint + 1, str.length() - 1).c_str());
				test.a = stoi(str.substr(nPoint + 1, str.length() - 1), &index);
			}
			// �պκ��� b�� �� ���� test.b�� ����ֱ�
			else if (str.substr(0, nPoint) == "b") {
				// printf("%s\n", str.substr(nPoint + 1, str.length() - 1).c_str());
				test.b = stoi(str.substr(nPoint + 1, str.length() - 1), &index);
			}
			else {	// ����ó��
			}
		}
		readFile.close();
	}
	// ����ü�� a, b ���
	test.printTest();
}

void testprint(string l, int p) {
	printf("%s\n", l.substr(p + 1, l.length() - p).c_str());
}

int strToScore(string l, int p, size_t i) {
	return stoi(l.substr(p + 1, l.length() - p), &i);
}

void fileIOTest() {
	// ���� �б�
	std::ifstream readFile;
	readFile.open("test.txt");	// test.txt ������ �д´�

	vector<stScore> vecScore;

	if (readFile.is_open()) {
		while (!readFile.eof()) {
			std::string str;
			std::getline(readFile, str);	// readFile�� �ؽ�Ʈ�� �� �� �о� str�� �ִ´�.
			// printf("str: %s\n", str.c_str());

			// stringstream�� �̿��� ',' �������� ������
			stringstream ss(str);
			string line;

			// ����ü�� �����ϱ� �� �ӽ÷� ������ ����
			string name = "";
			int math = 0, eng = 0, lang = 0;

			while (getline(ss, line, ',')) {
				// ���鹮�� �����
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				// printf("line: %s\n", line.c_str());
				
				// parse �̿��� '=' �������� member = value ������
				int point = line.find('=');
				size_t index = 0;

				// member�� ���ϰ�, �´� ��ġ�� ����ֱ�
				string target = line.substr(0, point);

				// �̸��̸� string name�� 
				if (target == "name") {
					// testprint(line, point);
					name = line.substr(point + 1, line.length() - point);
				}
				// ���������� int math�� 
				else if (target == "math") {
					// testprint(line, point);
					math = strToScore(line, point, index);
				}
				// ���������� int eng�� 
				else if (target == "eng") {
					// testprint(line, point);
					eng = strToScore(line, point, index);
				}
				// ���������� int lang�� 
				else if (target == "lang") {
					// testprint(line, point);
					lang = strToScore(line, point, index);
				}
				else { }

			}
			// member �� �� value ���� �����ڿ� ����ֱ�
			vecScore.push_back(stScore(name, math, eng, lang));
			// printf("------------------------------------\n");

		}
		readFile.close();
	}
	// ����ü ������ ���
	for (stScore& test : vecScore) {
		test.printTest();
	}
}

void removeSpace() {
	// ��Ʈ������ Ư�� ���� �����ϱ�
	string testStr = "1,2,3,4,5,6,7,8,9";
	testStr.erase(remove(testStr.begin(), testStr.end(), ','), testStr.end());
	printf("testStr: %s\n", testStr.c_str());
}

int main() {

	// fileWrite();
	// fileRead();
	// removeSpace();
	fileIOTest();
	
}