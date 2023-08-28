/*
[1 1] p    [fib(p+1) fib(p)]
[1 0]   =  [fib(p) fib(p-1)]
*/
vector<vl> matriz = {{1, 1}, {1, 0}};
matrix m(2, 2, matriz);

ll n; cin >> n;

cout << pow(m, n).m[0][1] << "\n";