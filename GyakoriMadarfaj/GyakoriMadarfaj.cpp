#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	int** area = new int* [M];
	for (int i = 0; i < M; i++) {
		area[i] = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];
		}
	}

	vector<int> birds;
	int index = 0;
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

	if (birds.size() != 0)
		index = birds[0];

	cout << index << endl;
	
	return 0;
}