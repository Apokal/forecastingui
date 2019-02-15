#pragma ONCE
#include <vector>

using namespace std;
vector<float> vectorGenerator(int size) {
    int random_number;

    vector<float> randomVector;
    randomVector.reserve(size);
    int a = 0;
    while (a < size)
    {
        a++;
        random_number = rand() % (20 - 10) + 10;
        randomVector.push_back(random_number);
    }

    return randomVector;
}
