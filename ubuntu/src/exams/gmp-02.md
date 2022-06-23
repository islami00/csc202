```cpp
#include<iostream>
using namespace std;
int main(){
    char s[]  = "man";
    int i;
    for(i = 0; s[i];i++){
        cout << "%c%c%c%c" , s[i],*(s+i),*(i+s), i[s];
    }
}
```

It'll print %c%c%c%c four times. Because only `<<`  is overloaded for cout, hence the comma operator which connects the other args won't do anything.

`%c%c%c%c%c%c%c%c%c%c%c%c`
