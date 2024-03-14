#include"myString.h"

using namespace Mine;

int main() {
    myString s1("Hello C++");
   myString s2;
   myString s3;
   s3 = s2;
   cout<<s3<<s2<<s1;
    return 0;
}
