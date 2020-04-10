#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

int64_t n;
int64_t k;
int64_t mas[100002];
int64_t tree[500005];





int64_t sum(int64_t l, int64_t r, int64_t node, int64_t tl, int64_t tr) {

    if (l > r)
        return 0;

    if (l <= tl && tr <= r) {
        return tree[node];
    }


    if (tr < l || r < tl) {
        return 0;
    }


    int64_t tm = (tl + tr) / 2;
    return sum(l, r, node * 2 + 1,     tl,     tm) + sum(l, r, node * 2 + 2, tm + 1, tr);
}


void update(int64_t idx, int64_t val, int64_t node, int64_t tl, int64_t tr) {

    if (idx <= tl && tr <= idx) {
        mas[idx] = val;
        tree[node] = val;
        return;
    }


    if (tr < idx || idx < tl) {
        return;
    }

    int64_t tm = (tl + tr) / 2;
    update(idx, val, node * 2 + 1,     tl,     tm);
    update(idx, val, node * 2 + 2, tm + 1, tr);
    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

struct Query{
    char command;
    int64_t a1;
    int64_t a2;

};

int main() {

    ifstream file("input.txt");

    file >> n;
    file >> k;


    vector<Query> query;
    vector<int64_t> answ;

    for (int64_t i = 0; i < k; i++){
        query.emplace_back();
        file >> query[i].command;
        file >> query[i].a1;
        file >> query[i].a2;
    }

    file.close();


    for (int64_t i = 0; i <= n; i++)
        mas[i] = 0;



    for (int64_t i = 0; i < k; i++){
        if (query[i].command == 'A')
            update(query[i].a1, query[i].a2, 0, 1, n);
        if (query[i].command == 'Q')
            answ.push_back(sum(query[i].a1, query[i].a2, 0, 1, n));

    }


    int64_t s = answ.size();

    ofstream file2("output.txt");

    for (int64_t i = 0; i < s; i++)
        file2 << answ[i] <<endl;

    file2.close();

}