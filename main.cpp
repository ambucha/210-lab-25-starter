// COMSC-210 | Lab 25 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
using namespace std;
using namespace std::chrono;

// size
const int SIZE = 20000;



int main() {
    // gonna start with the reading race
    set<string> s;
    list<string> l;
    vector<string> v;
    string code;

    auto start = high_resolution_clock::now();
    ifstream fin("codes.txt");

    // loop through the file and add each string code to the vector
    while(getline(fin, code)){
        v.push_back(code);
    }
    fin.close();
    auto end = high_resolution_clock::now();

    // add the variable for vectorRead time in microseconds
    auto vectorRead = duration_cast<microseconds>(end - start);

    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/