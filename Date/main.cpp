#include"Date.h"

int main() {
    Date d1(2024,5,27);
    Date d2(2024,1,1);
    d1.Print();
    d1 = d1+31;
    d1.Print();
    return 0;
}
