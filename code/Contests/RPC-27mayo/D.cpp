#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
const char ln = '\n';

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll d1,d2;cin>>d1>>d2;

	vl nums(d1,0);
	for (int i =0;i<d1;i++) cin>>nums[i];

	sort(nums.begin(), nums.end());

	for(int _ =0;_<d2;_++){
		ll n1;cin>>n1;
		if (n1==1){


			ll n2;cin>>n2;	

			if (n2>nums.back()){
				nums.push_back(n2);
			}else{
			int ind = lower_bound(nums.begin(), nums.end(), n2)-nums.begin();
			if (n2!=nums[ind]){
				nums[ind]=n2;
			}
		}
		}
		else{
			ll l,r;cin>>l>>r;
			int ind1 = lower_bound(nums.begin(), nums.end(), l)-nums.begin();
			int ind2 = upper_bound(nums.begin(), nums.end(), r)-nums.begin();

			cout<<(ind2-ind1)<<ln;
		}
	}
}