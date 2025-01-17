vector<string> split(const string &s/*, char c */){
	vector<string> v;
	stringstream ss(s);
	string sub;
	while(ss>>sub)v.push_back(sub);
	// while(getline(ss,sub,c))if(sz(sub))v.push_back(sub);
	return v;
}

for(char& c:s)c=toupper(c);
for(char& c:s)c=tolower(c);
int n=stoi(s); De string a entero
int n=stoi(s, nullptr, 2); base 2
double d=stod(s); De string a double
string s=to_string(n); De entero a string
cout<<"\U0001F600"; para emojis
