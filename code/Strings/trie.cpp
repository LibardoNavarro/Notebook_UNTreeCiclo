class TrieNode{
public:
	map<char,TrieNode*> children;
	bool isEnd=false;
	TrieNode():isEnd(false){}
	~TrieNode(){
		for(auto& child:children)delete child.second;
	}
};

void insert(TrieNode& root,const string& word){
	TrieNode* node=&root;
	for(int i=0;i<sz(word);++i){
		char c=word[i];
		if(!node->children.count(c)){
			node->children[c]=new TrieNode();                        
		}            
		node=node->children[c];                                            
	}       
	node->isEnd=true;                                                           
}

void printTrie(const TrieNode& root,string word=""){
	if(root.isEnd)cout<<word<<"\n";
	for(auto it:root.children){
		printTrie(*it.S,word+it.F);
	}
}

bool search(const TrieNode& root,const string& word){
	const TrieNode* node=&root;
	for(int i=0;i<sz(word);i++){
		char c=word[i];
		auto it=node->children.find(c);
		if (it==node->children.end())return false;
		node=it->S;
	}       
	return node->isEnd;                            
}

void deleteWord(TrieNode& root,const string& word){
	TrieNode* node=&root;
	for(int i=0;i<sz(word);i++){
		char c=word[i];
		auto it=node->children.find(c);
		if (it==node->children.end())return;
		node=it->S;
	}       
	node->isEnd=false;                            
}

void deleteWordWithNodes(TrieNode& root,const string& word){
	TrieNode* node=&root;
	stack<TrieNode*> st;
	for(int i=0;i<sz(word);i++){
		char c=word[i];
		auto it=node->children.find(c);
		if (it==node->children.end())return;
		st.push(node);
		node=it->S;
	}       
	node->isEnd=false;
	while(!st.empty()){
		TrieNode* node=st.top();st.pop();
		if(node->children.empty() && !node->isEnd){
			delete node;
		}
	}                            
}

void dfs(const TrieNode& root, int& count, multiset<string>& res, string word = ""){
	if(root.isEnd)res.insert(word);
	for(auto it:root.children){
		dfs(*it.S,count,res,word+it.F);
	}
}

int startWithPrefix(const TrieNode& root,const string& prefix, multiset<string>& res){
	const TrieNode* node=&root;
	int count=0;
	for(int i=0;i<sz(prefix);i++){
		char c=prefix[i];
		auto it=node->children.find(c);
		if (it==node->children.end())return count;
		node=it->S;
	}      
	dfs(*node,count, res); 
	return count;                           
}

string longestCommonPrefix(const TrieNode& root){
	string res="";
	const TrieNode* node=&root;
	while(node && !node->isEnd && sz(node->children)==1){
		auto it=node->children.begin();
		res+=it->F;
		node=it->S;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	TrieNode* root=new TrieNode();
	insert(*root,"hola");
	insert(*root,"holas");
	insert(*root,"hol");
	cout<<search(*root,"hola")<<"\n";
	deleteWord(*root,"hola");
	cout<<search(*root,"hola")<<"\n";
	delete root;
	return 0;
}