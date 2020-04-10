#include <vector>
#include <fstream>
#include <algorithm>


std::vector<std::vector<int64_t>> graph;
std::string *color;
std::vector<int64_t> topsort;


int64_t n;
int64_t m;


bool dfs(const int64_t &v) {
    if (color[v] == "grey") return false;
    else if (color[v] == "black") return true;
    else
    color[v] = "grey";

    for (int64_t u: graph[v]) {
        if (!dfs(u)) {
            return false;
        }

    }

    color[v] = "black";
    topsort.push_back(v);
    return true;


}





int main() {

    std::ifstream file("input.txt");
    std::ofstream file2("output.txt");


    file >> n;
    file >> m;

    topsort.reserve(n + 1);

    int64_t buffer1;
    int64_t buffer2;



    graph.resize(n + 1);
    for (int64_t i = 0; i < m; i++) {
        file >> buffer1;
        file >> buffer2;
        graph[buffer1].push_back(buffer2);

    }

    file.close();


    color = new std::string[n + 1];
    for (int64_t i = 0; i <= n; i++)
        color[i] = "white";

    for (int64_t i = 1; i <= n; i++) {

            if (!dfs(i)) {
                file2 << -1;
                return 0;
            }


    }


    std::reverse(topsort.begin(), topsort.end());

    for (int64_t i: topsort)
        file2 << i << ' ';

    file2.close();

    return 0;
}