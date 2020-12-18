#include <iostream>
#include <vector>

using namespace std;

int M, N;
int** area;

void input() {
	do {
		cin >> M >> N;
	} while (M < 1 || M > 50 || N < 1 || N > 200);
	area = new int* [M];
	for (int i = 0; i < M; i++) {
		area[i] = new int[N];
		for (int j = 0; j < N; j++) {
			do {
				cin >> area[i][j];
			} while (area[i][j] < 0 || area[i][j] > 1000);
		}
	}
}

vector<int> findBirds() {
	vector<int> birds;

	for (int i = 0; i < N; i++) {
		bool isEverywhere = true;
		for (int j = 0; j < M; j++) {
			int sum = 0;
			for (int k = 0; k < N; k++) {
				sum += area[j][k];
			}
			sum -= area[j][i];
			if (sum != 0 && area[j][i] == 0)
				isEverywhere = false;
		}
		if (isEverywhere)
			birds.push_back(i + 1);
	}
	return birds;
}

void output(vector<int> birds) {
	int index = 0;
	if (birds.size() != 0)
		index = birds[0];
	cout << index << endl;
}

int main()
{
	input();
	output(findBirds());
	return 0;
}