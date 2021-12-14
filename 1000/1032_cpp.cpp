#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int N, length; // 파일 갯수, 파일이름길이 
	string fileNames[50], result = ""; // 파일 이름 
	
	// 입력 
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> fileNames[i];
	}
	
	length = fileNames[0].length();
	char c;
	for(int i = 0; i < length; i++) {
		c = fileNames[0].at(i);
		for(int j = 1; j < N; j++) {
			if(fileNames[j].at(i) != fileNames[0].at(i)) {
				c = '?';
				break;
			}
		}
		result += c;
	}
	
	cout << result;
	
	return 0;
}