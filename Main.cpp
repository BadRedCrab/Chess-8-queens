#include <iostream>
#include <vector>

using namespace std;

int N, MainCounter = 0;

void print(vector <vector<int>> a, int type=0){ //вывод поля
	if (type == 1) {
		for (auto y : a) {
			cout << endl;
			for (auto x : y) { 
				if (x==2){ cout << x << " "; }
				else if (x == 1) { cout << 0 << " "; }
				else { cout << x << " "; }
			}
		}
		cout << endl;
		return;
	}

	for (auto y : a) {
		cout << endl;
		for (auto x : y) { cout << x << " "; }
	}
	cout << endl;
	return;
}

void _fl(vector <vector<int>>& a, int y, int x, int n){ //проверка заменяемого значения
	if (a[y][x] == 0 and n==1){
		a[y][x] = n;
	}
	else if (n == 2) {
		a[y][x] = n;
	}
}

void fill(vector <vector<int>> &a, int y, int x) { //заполнение поля агрессии по координатам
	
	int temp1y=y, temp2x=x;
	//горизонт и вертикальное заполнение
	for (int i = 0; i < N; i++) { 
		_fl(a, y, i, 1);
		_fl(a, i, x, 1);
	}
	//угловое заполнение
	temp1y = y, temp2x = x;
	for (int i = 0; temp1y < N and temp2x < N; i++) {
		_fl(a, temp1y, temp2x, 1);
		temp1y++;
		temp2x++;
	}
	temp1y = y, temp2x = x;
	for (int i = 0; temp1y >= 0 and temp2x >= 0; i++) {
		_fl(a, temp1y, temp2x, 1);
		temp1y--;
		temp2x--;
	}
	temp1y = y, temp2x = x;
	for (int i = 0; temp1y >= 0 and temp2x < N; i++) {
		_fl(a, temp1y, temp2x, 1);
		temp1y--;
		temp2x++;
	}
	temp1y = y, temp2x = x;
	for (int i = 0; temp1y < N and temp2x >= 0; i++) {
		_fl(a, temp1y, temp2x, 1);
		temp1y++;
		temp2x--;
	}

	_fl(a, y, x, 2);
}

void chess(vector <vector<int>> a, int y, int x, int cnt) {
	if (cnt!=0){
		fill(a, y, x); 
	}

	if (cnt >= N) {
		MainCounter += 1;
		print(a, 1); //для вывода правильных результатов
		return;
	}
	
	int temp;
	for (int j = 0; j < N; j++) {
		if (a[cnt][j]==0){
			temp=cnt+1;
			chess(a, cnt, j, temp);
		}
	}
	return;
}


int main() {
	int counter=0;
	cin >> N;
	vector<vector<int>> a(N, vector<int>(N, 0));
	chess(a, 0, 0, counter);
	cout << MainCounter;
}