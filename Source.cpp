//������ ���� ϰ�� 4

#include <iostream>
using namespace std;

int main(){
	int table[3][3] = { 0 };
	int i, j, k, judgeRow, judgeCol, judgeDig1, judgeDig2, player = 1, row,
		col;

	for (k = 0; k < 9; ++k){
		do{
			for (i = 0; i < 3; ++i){
				for (j = 0; j < 3; ++j)
					switch (table[i][j]){
					case 1: cout << "[O]";
						break;
					case -1: cout << "[X]";
						break;
					default: cout << "[ ]";
				}
				cout << endl;
			}
			cout << "������player" << player << "��ѡ��";
			cin >> row >> col;
			if (row < 1 || row > 3 || col < 1 || col > 3 || table[row - 1][col - 1])
				cout << "������������������" << endl;
			else break;
		} while (true);
		table[row - 1][col - 1] = (player == 1 ? 1 : -1);
		for (i = 0; i < 3; ++i){
			judgeRow = table[i][0] + table[i][1] + table[i][2];
			judgeCol = table[0][i] + table[1][i] + table[2][i];
			if (judgeRow == 3 || judgeCol == 3){
				cout << "���1Ӯ�ˣ���Ϸ����" << endl;
				return 0;
			}
			else if (judgeRow == -3 || judgeCol == -3){
				cout << "���2Ӯ�ˣ���Ϸ����" << endl;
				return 0;
			}
		}
		judgeDig1 = table[0][0] + table[1][1] + table[2][2];
		judgeDig2 = table[0][2] + table[1][1] + table[2][0];
		if (judgeDig1 == 3 || judgeDig2 == 3){
			cout << "���1Ӯ�ˣ���Ϸ����" << endl;
			return 0;
		}
		else if (judgeDig1 == -3 || judgeDig2 == -3){
			cout << "���2Ӯ�ˣ���Ϸ����" << endl;
			return 0;
		}
		player = player % 2 + 1;
	}
	cout << "ƽ�֣�" << endl;
	return 0;
}