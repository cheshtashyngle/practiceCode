#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;

    auto *answers = new int[numberOfTestCases];

    for(int i = 0 ; i < numberOfTestCases; i++) {
        int numberOfStrings, stringsInEachSet;
        cin >> numberOfStrings >> stringsInEachSet;

        multiset<string> strings;

        for (int j = 0; j < numberOfStrings; ++j) {
            string s;
            cin >> s;
            strings.insert(s);
        }

    }
    return 0;
}