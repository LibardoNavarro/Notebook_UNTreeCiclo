// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())

// Encuentra la rotación lexicográficamente menor de un string
int minExp(string &t) {
	int i=0,j=1,k=0,n=sz(t),x,y;
	while(i<n && j<n && k<n) {
		x=i+k;y=j+k;
		if(x>=n)x-=n;
		if(y>=n)y-=n;
		if(t[x]==t[y])++k;
		else if(t[x]>t[y]){
			i=j+1>i+k+1?j+1:i+k+1;
			swap(i,j);
			k=0;
		}else{
			j=i+1>j+k+1?i+1:j+k+1;
			k=0;
		}
	}
	return i;
}
