#include <iostream>
using namespace std;

int k;
int ret = 0;
int gear[4][8];
int state[100][2];

void clock(int n){
	int tmp;
	tmp = gear[n][0];
	gear[n][0] = gear[n][7];
	gear[n][7] = gear[n][6];
	gear[n][6] = gear[n][5];
	gear[n][5] = gear[n][4];
	gear[n][4] = gear[n][3];
	gear[n][2] = gear[n][1];
	gear[n][1] = tmp;
}

void re_clock(int n){
	int tmp;
	tmp = gear[n][0];
	gear[n][0] = gear[n][1];
	gear[n][1] = gear[n][2];
	gear[n][2] = gear[n][3];
	gear[n][3] = gear[n][4];
	gear[n][4] = gear[n][5];
	gear[n][5] = gear[n][6];
	gear[n][6] = gear[n][7];
	gear[n][7] = tmp;
}

void spin(int i, int j){


	if(i == 1){
		if(j == 1){
			if(gear[0][2] != gear[1][6]){
				if(gear[1][2] != gear[2][6]){
					if(gear[2][2] != gear[3][6]){
						re_clock(3);
					}
					clock(2);
				}
				re_clock(1);
			}
			clock(0);
		}

		else if(j == -1){
			if(gear[0][2] != gear[1][6]){
				if(gear[1][2] != gear[2][6]){
					if(gear[2][2] != gear[3][6]){
						clock(3);
					}
					re_clock(2);
				}
				clock(1);
			}
			re_clock(0);
		}
		return;
	}

	else if(i == 2){

		if(j == 1){
			if(gear[0][2] != gear[1][6]){
				re_clock(0);
			}
			if(gear[1][2] != gear[2][6]){
				if(gear[2][2] != gear[3][6]){
					clock(3);
				}
				re_clock(2);
			}
			clock(1);
		}




		else if(j == -1){
			if(gear[0][2] != gear[1][6]){
				clock(0);
			}
			if(gear[1][2] != gear[2][6]){
				if(gear[2][2] != gear[3][6]){
					re_clock(3);
				}
				clock(2);
			}
			re_clock(1);
		}
		return;

	}

	else if(i == 3){

		if(j == 1){
			if(gear[2][2] != gear[3][6]){
				re_clock(3);
			}
			if(gear[1][2] != gear[2][6]){
				if(gear[0][2] != gear[1][6]){
					clock(0);
				}
				re_clock(1);
			}
			clock(2);
		}

		else if(j == -1){
			if(gear[2][2] != gear[3][6]){
				clock(3);
			}
			if(gear[1][2] != gear[2][6]){
				if(gear[0][2] != gear[1][6]){
					re_clock(0);
				}
				clock(1);
			}
			re_clock(2);
		}
		return;

	}

	else if(i == 4){
		if(j == 1){
			if(gear[2][2] != gear[3][6]){
				if(gear[1][2] != gear[2][6]){
					if(gear[0][2] != gear[1][6]){
						re_clock(0);
					}
					clock(1);
				}	
				re_clock(2);
			}
			clock(3);
		}

		else if(j == -1){
			if(gear[2][2] != gear[3][6]){
				if(gear[1][2] != gear[2][6]){
					if(gear[0][2] != gear[1][6]){
						clock(0);
					}
					re_clock(1);
				}	
				clock(2);
			}
			re_clock(3);
		}
		return;
	}
}

int main(){

	for(int i=0; i<4; i++){
		int a;
		cin >> a;
		for(int j=7; j >= 0; j--){
			gear[i][j] = a % 10;
			a = a / 10;
		}
	}

	cin >> k;

	for(int i=0; i<k; i++){
		cin >> state[i][0] >> state[i][1];
	}

	for(int i=0; i<k; i++){
		spin(state[i][0], state[i][1]);		
	}

	if(gear[0][0] == 1)
		ret += 1;
	if(gear[1][0] == 1)
		ret += 2;
	if(gear[2][0] == 1)
		ret += 4;
	if(gear[3][0] == 1)
		ret += 8;

	cout << ret << endl;
}