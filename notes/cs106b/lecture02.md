## Lecture 02
### string functions
```c++
s.erase(index, length)
s.insert(index, str)
s.replace(index, len, str)
s.substr(start, len) // return the ext length characters beginning at start(inclusive)


```

### program

`output?`

```c++

void mystery(string a, string &b) {
    a.erase(0, 1);
    b += a[0];
    b.insert(3, "FOO");
}

int main() {
    string a = "marty";
    string b = "stepp";
    mystetry(a, b);
    cout << a << " " << b << endl;
}

// answer: marty steFOOppa
```

`Diamond print`

```c++
/*
M
MA
MAR
MART
MARTY
 ARTY
  RTY
   TY
    Y
*/
void nameDiamond(string s) {
 for(i = 0; i < s.size() * 2 - 1; i++) {
    int index;
    if (i < s.size()) {
        // substr（0， i+1）
        for (j = 0; j <= i; j++) {
            cout << s[j];
        }
    }
    else {
        for (j = 0; j < s.size(); j++) {
            if (j <= i - s.size) continue;
            cout << s[j]
        }
    }
    cout << std:endl;
 }

 }

}
```