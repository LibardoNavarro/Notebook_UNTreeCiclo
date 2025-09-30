// si el caracter que separa el texto es distinto al espacio
// entonces descomentar el segundo parametro y cambiar el while por el otro
vector<string> split(const string &s/*, char c */){
	vector<string> v;
	stringstream ss(s);
	string sub;
	while(ss>>sub)v.push_back(sub);
	// while(getline(ss,sub,c))if(sz(sub))v.push_back(sub);
	return v;
}

string s;
for(char& c:s)c=toupper(c); 
for(char& c:s)c=tolower(c); 
int n=stoi(s); // string -> int
int n=stoi(s, nullptr, 2); // bin string -> int
double d=stod(s); // string -> double
string s=to_string(n); // int -> string
cout<<"\U0001F600"; // emojis

Quitar repetidos (lo pongo aca porque no se donde mas ponerlo)
sort(all(bs));
bs.resize(unique(all(bs)) - bs.begin());