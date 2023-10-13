#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
using namespace std;
int main(){
    setlocale(LC_ALL,0);
    short int sum,points = 0;
	vector<pair<int,int>> shots(5);
	srand(time(0));
	for (int i = 0; i < 5;i++){
		cout << "Введите координаты "<< i + 1 <<"-го выстрела"<< endl;
        cin >> shots[i].first  >> shots[i].second;
		shots[i].first += rand()%10 - 5;
		shots[i].second += rand()%10 - 5;
	}
	 for (const auto& shot : shots){
		 points = 5 - (int)sqrt(pow(shot.first,2)+pow(shot.second,2));;
        if (((points >> 31) & 1 ) == 0){
            sum += points;
			//cout << points <<" "<< sum << endl;
        };
	 }
	if (sum < 10) cout << "Лузер" << endl;
	else cout << "ТЫ ЧЕМПИОН " << endl;
    return 0;
}