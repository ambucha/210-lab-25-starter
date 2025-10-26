// COMSC-210 | Lab 25 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
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

    // now read for the list
    start = high_resolution_clock::now();
    fin.open("codes.txt");

    // loop through the file and add each string to the list
    while(getline(fin, code)){
        l.push_back(code);
    }
    fin.close();

    end = high_resolution_clock::now();
    // add the variable for listRead time in microseconds
    auto listRead = duration_cast<microseconds>(end - start);

    // now read for the set
    start = high_resolution_clock::now();
    fin.open("codes.txt");

    // loop through the file and add each string to the list
    while(getline(fin, code)){
        s.insert(code);
    }
    fin.close();

    end = high_resolution_clock::now();
    // add the variable for setRead time in microseconds
    auto setRead = duration_cast<microseconds>(end - start);

    // sorting time
    start = high_resolution_clock::now();

    // just use sort for vector sorting
    sort(v.begin(), v.end());
    end = high_resolution_clock::now();
    auto vectorSort = duration_cast<microseconds>(end - start);

    // list sorting time
    start = high_resolution_clock::now();
    l.sort();
    end = high_resolution_clock::now();
    auto listSort = duration_cast<microseconds>(end - start);

    // just set the set sort to -1 since its auto sorted
    int setSort = -1;




    // displays
    cout << vectorRead.count() << " " << listRead.count() << " " << setRead.count() << endl;
    cout << vectorSort.count() << " " << listSort.count() << " " << setSort << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/