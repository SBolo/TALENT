#include <iostream>
using namespace std;

class Dummy {
public:
    int n;
    Dummy ();
    ~Dummy () { n--; };
};

Dummy::Dummy() {
    n = 0;
    n++;
}

int main () {
    Dummy a;
    cout << a.n << '\n';
    delete a;
    cout 
    return 0;
}