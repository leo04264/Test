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
