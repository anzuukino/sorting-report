#include <bits/stdc++.h>
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;
const ll MAX = 2e5 + 5;
const ll INF = 1e9;


using namespace std;
const ll Max_Length = 1e6;
double a[Max_Length + 1];
ll times=0;
int main(){
	using namespace std::chrono;
	for (int k = 1; k <= 10; k++){
		ifstream in;
		ofstream out;
		string file_path = "F:\\tailieudaihoc\\dsa\\generate-test\\input" + to_string(k)+".inp";
		in.open(file_path);
		for (int i = 1; i <= Max_Length; i++){
			in >> a[i];
		}
		auto start_time = high_resolution_clock::now();
		sort(a + 1, a + Max_Length + 1);
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
