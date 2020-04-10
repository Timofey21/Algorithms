#include <iostream>
#include <fstream>
#include <string>

  std::string string;
  std::string sub_string;

  int prefix_func(std::string sub, int p[]){

    const int n = sub.length();

    p[0] = 0;
    int i = 0;
    int j = 1;

    while ((i < n) && (j < n)){

        if (sub[i] == sub[j]){
            p[j] = i + 1;
            i++;
            j++;
        } else if (i == 0){
            p[j] = 0;
            j++;
        } else i = p[i - 1];
    }
}


int main() {

    std::ifstream file("input.txt");


    getline(file, string);
    getline(file, sub_string);

    file.close();

    int m = string.length();
    int n = sub_string.length();

    int p[n];

    prefix_func(sub_string, p);


    int k = 0;
    int l = 0;

    std::ofstream file2("output.txt");

    while (k < m){
        if (string[k] == sub_string[l]) {
            k++;
            l++;

            if (l == n) {
                file2 << k - (n - 1);
                file2.close();
                exit(0);
            }
        }
        else if (l == 0) {
            k++;
            if (k == m) {
                file2 << -1;
                file2.close();
                exit(0);
            }
        } else
            l = p[l - 1];

    }

    file2 << -1;
    file2.close();
    exit(0);
}



