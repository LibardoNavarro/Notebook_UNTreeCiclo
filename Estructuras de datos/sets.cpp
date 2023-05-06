#include <bits/stdc++.h>
using namespace std;

int main(){

    // Unordered sets
    //Las inserciones, eliminaciones y búsquedas son todas O(1)
    //Pueden haber peores casos de O(n)
    unordered_set<int> s;
    s.insert(1);                 // {1}
    s.insert(4);                 // {1, 4}
    s.insert(2);                 // {1, 4, 2}
    s.insert(1);                 // does nothing because 1's already in the set
    cout << s.count(1) << endl;  // 1, porque contiene
    s.erase(1);                  // {2, 4}
    cout << s.count(5) << endl;  // 0, porque no contiene
    s.erase(0);                  // does nothing because 0 wasn't in the set

    //Sorted sets
    //Las inserciones, eliminaciones y búsquedas son todas O(log n)
    set<int> s;
    s.insert(1); // [1]
    s.insert(14); // [1, 14]
    s.insert(9); // [1, 9, 14]
    s.insert(2); // [1, 2, 9, 14]
    cout << *s.upper_bound(7) << '\n'; // 9
    cout << *s.upper_bound(9) << '\n'; // 14
    cout << *s.lower_bound(5) << '\n'; // 9
    cout << *s.lower_bound(9) << '\n'; // 9
    cout << *s.begin() << '\n'; // 1
    auto it = s.end();
    cout << *(--it) << '\n'; // 14
    s.erase(s.upper_bound(6)); // [1, 2, 14]
    
    //Recorrer el set
    for (int element : s) { cout << element << "\n"; }
}