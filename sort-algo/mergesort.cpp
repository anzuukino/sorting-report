#include <bits/stdc++.h>
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;
const ll MAX = 2e5 + 5;
const ll INF = 1e9;

const ll Max_Length = 1e6;
double a[Max_Length];

ll times=0;
ll left_arr[Max_Length];
ll right_arr[Max_Length];
void merge(double a[],ll l,ll m,ll r){
    ll n1 = m - l + 1;
    ll n2 = r - m;
    for (int i = 0; i< n1 ;i++){
        left_arr[i] = a[l + i];
    }
    for (int i = 0; i< n2 ;i++){
        right_arr[i] = a[m + 1 + i];
    }
    ll i = 0;
    ll j = 0;
    ll k = l;
    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            a[k] = left_arr[i];
            i++;
        } else {
            a[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = right_arr[j];
        j++;
        k++;
    }

}
void merge_sort(double a[], ll l, ll r){
	if (l<r){
        ll m = l + (r - l)/2;
        merge_sort(a,l, m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
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
		merge_sort(a, 0,Max_Length);
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
