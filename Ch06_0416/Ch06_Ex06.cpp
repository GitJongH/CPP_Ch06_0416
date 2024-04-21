#include <iostream>
using namespace std;

class Utility2 {
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& reSize);
};

int* Utility2::concat(int s1[], int s2[], int size) {
	int* arr = new int [size * 2];

	for (int i = 0; i < size; i++) {
		arr[i] = s1[i];
	}

	for (int i = 0; i < size; i++) {
		arr[size + i] = s2[i];
	}

	return arr;
}

int* Utility2::remove(int s1[], int s2[], int size, int& reSize) {
	int* arr = new int[size];
	int count = 0;

	for (int i = 0; i < size; i++) {
		int j;
		for (j = 0; j < size; j++) {
			if (s1[i] == s2[j]) break;
		}
		if (j == size) {
			arr[count] = s1[i];
			count++;
		}
	}

	reSize = count;
	if (count == 0) return NULL;
	int* arr2 = new int[reSize];

	for (int i = 0; i < reSize; i++) {
		arr2[i] = arr[i];
	}

	delete[] arr;
	return arr2;
}

int main() {
	int x[5];
	int y[5];
	int* arr;
	int size = 5;

	cout << "정수 5개를 입력하라. 배열 x에 삽입한다>>";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}

	cout << "정수 5개를 입력하라. 배열 y에 삽입한다>>";
	for (int i = 0; i < 5; i++) {
		cin >> y[i];
	}

	// size = (sizeof(x) + sizeof(y)) / sizeof(int);

	arr = Utility2::concat(x, y, size);

	cout << "합친 정수 배열을 출력한다." << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 2" << endl;
	int reSize = 2;
	arr = Utility2::remove(x, y, size, reSize);

	for (int i = 0; i < reSize; i++) {
		cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}