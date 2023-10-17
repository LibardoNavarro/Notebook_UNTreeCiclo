// Función para convertir un caracter a un entero
int conv(char ch) { 
  return ((ch >= 'a' && ch <= 'z') ? ch-'a' : ch-'A'+26);
}

string s="abc";
cout<<s.substr(1)<<"\n";
cout<<s.substr(0,1)<<"\n";

// El primer parametro es la posicion inicial 
s.insert(3, "def");
cout<<s<<"\n";
// El primer parametro es la posicion y el segundo es la cantidad de caracteres a borrar
s.erase(3,3);
cout<<s<<"\n";
// El primer parametro es la posicion y el segundo es la cantidad de caracteres a reemplazar
s.replace(0,2,"def");
cout<<s<<"\n";

for(char& c:s){
  c=toupper(c);
}
cout<<s<<"\n";

for(char& c:s){
  c=tolower(c);
}
cout<<s<<"\n";

// De string a entero
s="123";int n;
istringstream(s)>>n;
cout<<n<<"\n";

// De entero a string
n=456;
ostringstream os;
os<<n;
s=os.str();
cout<<s<<"\n";
