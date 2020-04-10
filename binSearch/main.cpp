#include <iostream>
#include <fstream>


uint64_t w, h, n;
const uint64_t max = 10e18;


uint64_t BinSearch(uint64_t l, uint64_t r) {

    uint64_t mid;
    while (l < r - 1) {

        mid = (l + r) / 2;

        if ((mid / h) * (mid / w) >= n)
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main()
{
    std::ifstream file("diploma.in");


    file >> w;
    file >> h;
    file >> n;

    file.close();

    std::ofstream file2("diploma.out");
    file2 << BinSearch(0, max);
    file2.close();


}