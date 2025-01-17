// hanoi(n) = 2 * hanoi(n-1) + 1
// hanoi(n, 1, 3)
vector<int> ans;
void hanoi(int x, int start, int end){ 
	if(!x)return;
	hanoi(x-1, start, 6-start-end);
	ans.push_back({start, end});
	hanoi(x-1, 6-start-end, end);
}