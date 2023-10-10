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
	// 파일 쓰기
	std::ofstream writeFile;
	writeFile.open("test.txt");	// test.txt 파일을 연다(파일이 없다면 생성한다)

	std::string strTest = "test 1234 asdf 입니다.\n";
	writeFile.write(strTest.c_str(), strTest.size());
	writeFile.write(strTest.c_str(), strTest.size());

	writeFile.close();		// 파일을 열었으면 반드시 닫기 실행.

}

void fileRead() {
	// 파일 쓰기
	std::ofstream writeFile;
	// writeFile.open("test.txt");	// test.txt 파일을 연다(파일이 없다면 생성한다)

	// std::string strTest = "test 1234 asdf 입니다.\n";
	// writeFile.write(strTest.c_str(), strTest.size());
	// writeFile.write(strTest.c_str(), strTest.size());

	// writeFile.close();		// 파일을 열었으면 반드시 닫기 실행.

	// 파일 읽기
	std::ifstream readFile;
	readFile.open("test.txt");	// test.txt 파일을 읽는다

	stTest test;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			std::string str;
			std::getline(readFile, str);	// readFile의 텍스트를 한 줄 읽어 str에 넣는다.
			printf("str: %s\n", str.c_str());

			// =을 기준으로 parse
			int nPoint = str.find('=');
			size_t index = 0;
			// 앞부분이 a면 뒷 숫자 test.a로 집어넣기
			if (str.substr(0, nPoint) == "a") {
				// printf("%s\n", str.substr(nPoint + 1, str.length() - 1).c_str());
				test.a = stoi(str.substr(nPoint + 1, str.length() - 1), &index);
			}
			// 앞부분이 b면 뒷 숫자 test.b로 집어넣기
			else if (str.substr(0, nPoint) == "b") {
				// printf("%s\n", str.substr(nPoint + 1, str.length() - 1).c_str());
				test.b = stoi(str.substr(nPoint + 1, str.length() - 1), &index);
			}
			else {	// 예외처리
			}
		}
		readFile.close();
	}
	// 구조체의 a, b 출력
	test.printTest();
}

void testprint(string l, int p) {
	printf("%s\n", l.substr(p + 1, l.length() - p).c_str());
}

int strToScore(string l, int p, size_t i) {
	return stoi(l.substr(p + 1, l.length() - p), &i);
}

void fileIOTest() {
	// 파일 읽기
	std::ifstream readFile;
	readFile.open("test.txt");	// test.txt 파일을 읽는다

	vector<stScore> vecScore;

	if (readFile.is_open()) {
		while (!readFile.eof()) {
			std::string str;
			std::getline(readFile, str);	// readFile의 텍스트를 한 줄 읽어 str에 넣는다.
			// printf("str: %s\n", str.c_str());

			// stringstream을 이용해 ',' 기준으로 나누기
			stringstream ss(str);
			string line;

			// 구조체를 생성하기 전 임시로 저장할 변수
			string name = "";
			int math = 0, eng = 0, lang = 0;

			while (getline(ss, line, ',')) {
				// 공백문자 지우기
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				// printf("line: %s\n", line.c_str());
				
				// parse 이용해 '=' 기준으로 member = value 나누기
				int point = line.find('=');
				size_t index = 0;

				// member를 비교하고, 맞는 위치에 집어넣기
				string target = line.substr(0, point);

				// 이름이면 string name에 
				if (target == "name") {
					// testprint(line, point);
					name = line.substr(point + 1, line.length() - point);
				}
				// 수학점수면 int math에 
				else if (target == "math") {
					// testprint(line, point);
					math = strToScore(line, point, index);
				}
				// 영어점수면 int eng에 
				else if (target == "eng") {
					// testprint(line, point);
					eng = strToScore(line, point, index);
				}
				// 국어점수면 int lang에 
				else if (target == "lang") {
					// testprint(line, point);
					lang = strToScore(line, point, index);
				}
				else { }

			}
			// member 비교 후 value 값을 생성자에 집어넣기
			vecScore.push_back(stScore(name, math, eng, lang));
			// printf("------------------------------------\n");

		}
		readFile.close();
	}
	// 구조체 벡터의 출력
	for (stScore& test : vecScore) {
		test.printTest();
	}
}

void removeSpace() {
	// 스트링에서 특정 문자 제거하기
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