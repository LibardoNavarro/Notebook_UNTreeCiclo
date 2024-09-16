typedef long long T;
struct Node{T val,acum;};
struct TwoStacks{
	stack<Node> s1,s2;
	
	void add(T x){
		Node tmp={x,x};
		if(!s2.empty()){
		// tmp.acum + s2.top().acum
		}
		s2.push(tmp);
	}

	void remove(){
		if(s1.empty()){
			while(!s2.empty()){
				Node tmp=s2.top();
				if(s1.empty()){
				// tmp.acum = tmp.val
				}else{
				// tmp.acum + s1.top().acum
				}
				s1.push(tmp);
				s2.pop();
			}
		}
		s1.pop();
	}

	bool good(){
		if(s1.empty() && s2.empty())return false;
		else if(!s1.empty() && s2.empty()){
			return true; // eval s1.top();
		}else if(s1.empty() && !s2.empty()){
			return true; // eval s2.top();
		}else{
			return true; // eval s1.top() + s2.top()
		}
	}
};
