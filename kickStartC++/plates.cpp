#include <iostream>

int totalBeauty(int numberOfPlatesToPick, int currentStack);

int numberOfStack, platesInEachStack;
int **plateStacksWithBeauty, **cacheOfBeauty;

using namespace std;

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;

    int *answers = new int[numberOfTestCases];

    for(int i = 0 ; i < numberOfTestCases; i++) {
        int numberOfPlatesToPick;
        cin >> numberOfStack >> platesInEachStack >> numberOfPlatesToPick;

        plateStacksWithBeauty = new int*[numberOfStack];
        cacheOfBeauty = new int*[numberOfStack];

        for(int j = 0; j < numberOfStack; j++) {
            plateStacksWithBeauty[j] = new int[platesInEachStack + 1];
            cacheOfBeauty[j] = new int[numberOfPlatesToPick + 1];
            plateStacksWithBeauty[j][0] = 0;
            cin >> plateStacksWithBeauty[j][1];
            for (int k = 2; k <= platesInEachStack; ++k) {
                int beauty;
                cin >> beauty;
                plateStacksWithBeauty[j][k] = plateStacksWithBeauty[j][k-1] + beauty;
            }

            for (int l = 0; l <= numberOfPlatesToPick; ++l) {
                cacheOfBeauty[j][l] = -1;
            }
        }

        answers[i] = totalBeauty(numberOfPlatesToPick, 0);
    }

    for (int l = 0; l < numberOfTestCases; ++l) {
        cout << "Case #" << (l + 1) << ": " << answers[l] << endl;
    }

    return 0;
}

int totalBeauty(int numberOfPlatesToPick, int currentStack) {
    if(numberOfPlatesToPick == 0) {
        return 0;
    }
    if (cacheOfBeauty[currentStack][numberOfPlatesToPick] != -1) {
        return cacheOfBeauty[currentStack][numberOfPlatesToPick];
    }
    int minPlatesToTake = max(0, numberOfPlatesToPick - (numberOfStack - currentStack - 1) * platesInEachStack);
    int maxPlatesToTake = min(numberOfPlatesToPick, platesInEachStack);
    cacheOfBeauty[currentStack][numberOfPlatesToPick] = 0;
    for (int i = minPlatesToTake; i <= maxPlatesToTake; i++) {
        int beauty = plateStacksWithBeauty[currentStack][i] +
                totalBeauty(numberOfPlatesToPick - i, currentStack + 1);
        cacheOfBeauty[currentStack][numberOfPlatesToPick] = max(cacheOfBeauty[currentStack][numberOfPlatesToPick], beauty);
    }

    return cacheOfBeauty[currentStack][numberOfPlatesToPick];
}
