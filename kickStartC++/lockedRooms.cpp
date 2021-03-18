#include <iostream>
#include <vector>

using namespace std;

int numberOfDoors;
int *locks;

//vector<vector<vector<int>>> cache;

vector<int> roomsOrder(int leftLock, int rightLock) {
    vector<int> order;
//    if (!cache[leftLock][rightLock].empty()) {
//        return cache[leftLock][rightLock];
//    }

    if(leftLock == 0  && rightLock == numberOfDoors) {
        return order;
    }

    if(leftLock == 0 || (rightLock != numberOfDoors && (locks[rightLock] < locks[leftLock]))) {
        order.push_back(rightLock + 1);
        vector<int> secondOrder = roomsOrder(leftLock, rightLock + 1);
        order.insert(order.end(), secondOrder.begin(), secondOrder.end());
    } else if(rightLock == numberOfDoors || (locks[rightLock] > locks[leftLock])) {
        order.push_back(leftLock);
        vector<int> secondOrder = roomsOrder(leftLock -1, rightLock);
        order.insert(order.end(), secondOrder.begin(), secondOrder.end());
    }

    //cache[leftLock][rightLock] = order;
    return order;
}

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;

    vector<vector<int >>answers;

    for(int i = 0 ; i < numberOfTestCases; i++) {
        int numberOfQueries;
        cin >> numberOfDoors >> numberOfQueries;

        locks = new int[numberOfDoors];

        for (int j = 1; j < numberOfDoors; ++j) {
            cin >> locks[j];
        }

//        cache.clear();
//        for (int l = 0; l <= numberOfDoors; ++l) {
//            vector<vector<int>> cacheVector;
//            for (int j = 0; j <= numberOfDoors ; ++j) {
//                vector<int> vector;
//                cacheVector.push_back(vector);
//            }
//            cache.push_back(cacheVector);
//        }

        vector<vector<int>> secondCache;

        for (int l = 0; l <= numberOfDoors; ++l) {
            vector<int> vector;
            secondCache.push_back(vector);
        }

        vector<int> answer;

        for (int k = 0; k < numberOfQueries; ++k) {
            int startingRoom, kRoom;
            cin >> startingRoom >> kRoom;
            vector<int> order;
            order.push_back(startingRoom);

            if(!secondCache[startingRoom].empty()) {
               order = secondCache[startingRoom];
            } else {
                vector<int> secondOrder = roomsOrder(startingRoom - 1, startingRoom);
                order.insert(order.end(), secondOrder.begin(), secondOrder.end());
                secondCache[startingRoom] = order;
            }
            answer.push_back(order[kRoom - 1]);
        }

        answers.push_back(answer);
    }

    for (int l = 0; l < numberOfTestCases; ++l) {
        vector<int> answer = answers[l];
        cout << "Case #" << (l + 1) << ": ";
        for (int i : answer) {
            cout <<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}

