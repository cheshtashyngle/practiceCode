#include<iostream>
#include <cmath>

using namespace std;

int numberOfNotes;
int *pitch;
int **cache;

int numberOfRulesBreak(int startIndex, int previousKey) {
    if(startIndex == numberOfNotes) {
        return 0;
    }
    if(cache[startIndex][previousKey] != -1) {
        return cache[startIndex][previousKey];
    }

    int minRulesBreak = numberOfNotes;
    if (startIndex == 0) {
        for(int i = 1; i <= 4; i++) {
            minRulesBreak = min(minRulesBreak, numberOfRulesBreak(startIndex + 1, i));
        }
    }
    else {
            if (pitch[startIndex] > pitch[startIndex - 1]) {
                for(int i = 1; i <= previousKey; ++i) {
                    minRulesBreak = min(minRulesBreak, numberOfRulesBreak(startIndex + 1, i) + 1);
                }
                for (int i = previousKey + 1; i <=4 ; ++i) {
                    minRulesBreak = min(minRulesBreak, numberOfRulesBreak(startIndex + 1, i));
                }
            } else if (pitch[startIndex] < pitch[startIndex - 1]) {
                for (int i = 1; i < previousKey ; ++i) {
                    minRulesBreak = min(minRulesBreak, numberOfRulesBreak(startIndex + 1, i));
                }
                for (int i = previousKey; i <=4 ; ++i) {
                    minRulesBreak = min(minRulesBreak, numberOfRulesBreak(startIndex + 1, i) + 1);
                }
                
            } else {
                for (int i = 1; i <= 4; ++i) {
                    if (i == previousKey) {
                        minRulesBreak = min(minRulesBreak, numberOfRulesBreak(startIndex + 1, previousKey));
                    } else {
                        minRulesBreak = min(minRulesBreak,
                                                      numberOfRulesBreak(startIndex + 1, previousKey) + 1);
                    }
                }
            }
    }

    cache[startIndex][previousKey] = minRulesBreak;
    return minRulesBreak;
}

int main() {

    int numberOfTestCases;
    cin >> numberOfTestCases;

    auto *answers = new int[numberOfTestCases];

    for(int i = 0 ; i < numberOfTestCases; i++) {
        cin>>numberOfNotes;

        cache = new int*[numberOfNotes];
        pitch = new int[numberOfNotes];

        for (int j = 0; j < numberOfNotes; ++j) {
            cin>>pitch[j];
            cache[j] = new int[5];

            for (int k = 0; k < 5; ++k) {
                cache[j][k] = -1;
            }
        }

        int ruleBreak = numberOfRulesBreak(0, 0);
        answers[i] = ruleBreak;
    }

    for (int l = 0; l < numberOfTestCases; ++l) {
        cout << "Case #" << (l + 1) << ": " << answers[l] << endl;
    }

    return 0;
}
