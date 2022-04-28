#include <iostream>
#include "Weight.h"
#define DEBUG
#ifdef DEBUG
#include <iostream>
using namespace std;
#include "Weight.h"

int main() {
    Weight w1;
    w1.dump();

    Weight w2(KILO);
    w2.dump();

    Weight w3(3.2);
    w3.dump();

    Weight w4(3.4, KILO);
    w4.dump();

    Weight w5(3.54, 10);
    w5.dump();

    Weight w6(KILO, 30.2);
    w6.dump();

    Weight w7(3.0, KILO, 50);
    w7.dump();

    cout << endl << "w7 is less than w3? " << (w7 < w3 ? "true":"false") << endl;
    cout << "w3 is less than w7? " << (w3 < w7 ? "true":"false") << endl << endl;

    cout << "w7 weight: " << w7.getWeight() << endl;
    w7 += 10;
    cout << "w7 weight: " << w7.getWeight() << endl << endl;

    cout << "w7 equals w3? " << (w7 == w3 ? "true":"false") << endl;
    w3.setWeight(w7.getWeight());
    cout << "w7 equals w3? " << (w7 == w3 ? "true":"false") << endl << endl;

    cout << "w7 weightUnit: " << w7.getWeightUnit() << endl;
    cout << "w7 weight: Kilo " << w7.getWeight() << endl;
    cout << "w7 weight: pounds " << w7.getWeight(POUND) << endl;
    cout << "w7 weight: slugs " << w7.getWeight(SLUG) << endl;

    return 0;
}

#else

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

#endif