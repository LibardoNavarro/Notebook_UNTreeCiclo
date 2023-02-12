#include <bits/stdc++.h>
using namespace std;

int binary_search(long int array[], long int n, long int length){

    long int izq = 0;
    long int der = length - 1;

    while (izq <= der){
    int mid = (izq + der) / 2;
    if (array[mid] > n){
       der = mid - 1;
    }
    else if (array[mid] < n){
      izq = mid + 1;
    }
    else{
      return mid;
    }
  }
  return 0;
}

int main(){

    long int array[] = {1, 2, 3, 456, 335343, 234342333, 934342333};

    cout << binary_search(array, 335343, 7);

}