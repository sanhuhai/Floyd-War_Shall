#include <iostream>
using namespace std;

const int INF = 65535;
const int MAX = 100;
int Graph[MAX][MAX];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			Graph[i][j] = Graph[j][i] = INF;
		}
		Graph[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << Graph[i][j] << " ";
		}
		putchar(10);
	}
	for (int i = 0; i < m; i ++ ) {
		int row, col, value;
		cin >> row >> col >> value;
		Graph[row][col] = value;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (Graph[j][k] > Graph[j][i] + Graph[i][k]) Graph[j][k] = Graph[j][i] + Graph[i][k];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << Graph[i][j] << " ";
		}
		putchar(10);
	}
	return 0;
}

/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/