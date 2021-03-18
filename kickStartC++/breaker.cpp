#include<iostream>

using namespace std;

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;

    auto *answers = new long long int[numberOfTestCases];

    for(int i = 0 ; i < numberOfTestCases; i++) {
        int numberOfDays;
        cin>>numberOfDays;

        int *visitors = new int[numberOfDays];

        for (int k = 0; k < numberOfDays; ++k) {
            cin>>visitors[k];
        }

        int max = -1;
        int numberOfBreakers = 0;
        for (int j = 0; j < numberOfDays; ++j) {
            if(visitors[j] > max) {
                max = visitors[j];
                if((j == numberOfDays -1)  || (j != (numberOfDays - 1) && visitors[j+1] < max)) {
                    numberOfBreakers++;
                }
            }
        }

        answers[i] = numberOfBreakers;
    }

    for (int l = 0; l < numberOfTestCases; ++l) {
        cout << "Case #" << (l + 1) << ": " << answers[l] << endl;
    }

    return 0;
}
