#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;

    auto *answers = new long long int[numberOfTestCases];

    for(int i = 0 ; i < numberOfTestCases; i++) {
        int numberOfSessions, additionalSessions;
        cin >> numberOfSessions >> additionalSessions;

        multiset<long long int> difficulty;
        long long int previousMinutes;
        cin >> previousMinutes;

        for (int j = 1; j < numberOfSessions; j++) {
            long long int minutes;
            cin >> minutes;
            difficulty.insert(minutes - previousMinutes);
            previousMinutes = minutes;
        }

        int additionalSessionsUsed = 0;

        while((additionalSessionsUsed != additionalSessions) && *(difficulty.rbegin()) != 1) {
            long long int maxDifficulty = *(difficulty.rbegin());
            int difficultySize = difficulty.size();
            int sessionsRemaining = additionalSessions - additionalSessionsUsed;
            for (int j = 1; j <= sessionsRemaining; ++j) {
                long long newDifficulty = ceil(maxDifficulty/(j+1));
                if(j == sessionsRemaining  || (difficultySize > 1 && newDifficulty <= *(++difficulty.rbegin()))) {
                    difficulty.insert(newDifficulty);
                    long long int remaining = maxDifficulty;
                    for (int k = j; k > 0; --k) {
                        newDifficulty = ceil((remaining - newDifficulty)/k);
                        difficulty.insert(newDifficulty);
                        remaining -= newDifficulty;
                    }

                    difficulty.erase(--difficulty.end());
                    additionalSessionsUsed += j;
                    break;
                }
            }
        }

        answers[i] = *(difficulty.rbegin());
    }

    for (int l = 0; l < numberOfTestCases; ++l) {
        cout << "Case #" << (l + 1) << ": " << answers[l] << endl;
    }
    return 0;
}
