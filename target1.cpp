#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;
int main(){
    setlocale(LC_ALL,0);
    short int sum,points,shots = 0;
	srand(time(0));
	while (shots != 5){
		pair<int,int> shot;
		cin >> shot.first >> shot.second;
		shot.first += rand() % 11 - 5;
		shot.second += rand() % 11 - 5;
		points = 5 - (int)sqrt(pow(shot.first,2)+pow(shot.second,2));
		if (((points >> 31 ) & 1) == 0){
        sum += points;
	}
	shots++;
	//cout << points <<" "<< sum << endl; 
	}
	if (sum < 10) cout << "Лузер" << endl;
    return 0;
}
