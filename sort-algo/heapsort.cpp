#include <bits/stdc++.h>
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;
const ll MAX = 2e5 + 5;
const ll INF = 1e9;

const ll Max_Length = 1e6;
double a[Max_Length];
double maxnode = -INF;

ll times=0;
void heapify(double a[],ll Max_Length, ll i){
	ll largest = i;
	ll left = 2 * i + 1;
	ll right = 2 * i + 2;
	if (left < Max_Length && a[left] > a[largest]){
		largest = left;
	}
	if (right < Max_Length && a[right] > a[largest]){
		largest = right;
	}
    if (largest != i){
		swap(a[i],a[largest]);
		heapify(a,Max_Length,largest);
	}
}
void heap_sort(double a[], ll Max_Length){
	for (int i = Max_Length / 2 - 1; i >=0 ; i-- ){
		heapify(a,Max_Length,i);
	}
	for (int i = Max_Length - 1 ; i >=0;i--){
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}
int main(){
	using namespace std::chrono;
	for (int k = 1; k <= 10; k++){
		maxnode = -INF;
		ifstream in;
		ofstream out;
		string file_path = "F:\\tailieudaihoc\\dsa\\generate-test\\input" + to_string(k)+".inp";
		in.open(file_path);
		for (int i = 0; i < Max_Length; i++){
			in >> a[i];
			maxnode = max(a[i],maxnode);
		}
		auto start_time = high_resolution_clock::now();
		heap_sort(a, Max_Length);
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
