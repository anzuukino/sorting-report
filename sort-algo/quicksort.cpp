#include <bits/stdc++.h>
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;
const ll MAX = 2e5 + 5;
const ll INF = 1e9;

const ll Max_Length = 1e6;
double a[Max_Length];

ll times=0;
ll partition(double a[], ll l,ll r){
    double pivot = a[(l + r ) / 2];
	ll i = l - 1, j = r + 1;
	while (1){
		do{
			i++;
		}while(a[i] < pivot);
		do{
			j--;
		}while(a[j] > pivot);
		if (i < j){
			swap(a[i], a[j]);
		}
		else return j;
	}
}
void quick_sort(double a[], ll l, ll r){
    if (l >= r) return;
    ll p = partition(a, l , r);
    quick_sort(a, l, p);
    quick_sort(a, p + 1, r);
}
int main(){
	using namespace std::chrono;
	for (int k = 1; k <= 10; k++){
		ifstream in;
		ofstream out;
		string file_path = "F:\\tailieudaihoc\\dsa\\generate-test\\input" + to_string(k)+".inp";
		in.open(file_path);
		for (int i = 0; i < Max_Length; i++){
			in >> a[i];
		}
		auto start_time = high_resolution_clock::now();
		quick_sort(a, 0, Max_Length - 1);
		auto end_time = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end_time - start_time);
		// for (int i = 1;i <= 50; i++){
		// 	cout << a[i] << "\n";
		// }
		
    	cout << "input" << k <<".inp: " << duration.count() << " ms" << endl;
		times += duration.count();
		in.close();
	}
	cout << "Average:" << times/10;
	return 0;
}
