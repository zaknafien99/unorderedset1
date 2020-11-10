// unorderedset1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_set>
#include <numeric>
#include "print.h"
#include <iostream>

using namespace std;

int main()
{
    // create and initialize unordered set
    unordered_set<int> coll = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 77 };

    // print elements
    // - elements are in arbitrary order

    PRINT_ELEMENTS(coll);

    // insert some additional elements
    // - might cause rehashing and create different order
    coll.insert({ -7, 17, 33, -11, 17,19,1,13 });
    PRINT_ELEMENTS(coll);

    // remove element with specific value
    coll.erase(33);

    //insert sum of all existing values
    coll.insert(accumulate(coll.begin(), coll.end(), 0));
    PRINT_ELEMENTS(coll);

    // check if value 19 is in the set
    if (coll.find(19) != coll.end()) {
        cout << "19 is available" << endl;
    }

    // remove all negative values
    unordered_set<int>::iterator pos;
    for (pos = coll.begin(); pos != coll.end();) {
        if (*pos < 0) {
            pos = coll.erase(pos);
        }
        else {
            ++pos;
        }
    }
    PRINT_ELEMENTS(coll);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
