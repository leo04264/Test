#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int i) {
    vector<int> vi={};
    vi.emplace_back(0);
    vi.emplace_back(1);
    if (i < 2) {
        return vi[i];
    }
    for (int tmp = 2; tmp <= i; tmp++) {
        vi.emplace_back(vi[tmp-1] + vi[tmp-2]);
    }
    return vi[i];
}

int main() {
    cout << fibonacci(0) << endl;// 0
    cout << fibonacci(1) << endl;// 1
    cout << fibonacci(2) << endl;// 1
    cout << fibonacci(3) << endl;// 2
    cout << fibonacci(4) << endl;// 3 
}
