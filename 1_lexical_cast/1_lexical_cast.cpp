#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

//self defined class
class foo{
    friend ostream& operator<<(ostream& os, const foo& x){
        os << "class content" << endl;
        return os;
    }
};

int main()
{
    // string -> int long double float
    int a = lexical_cast<int>("123");
    long b = lexical_cast<long>("2019");
    double c = lexical_cast<double>("123.321");
    float pi = lexical_cast<float>("3.14165698");

    cout << a << " " << b << " " << c << " " << pi << endl;

    // to string
    string str = lexical_cast<string>(123);
    cout << str<< endl;
    cout << lexical_cast<string>(1.234) << endl;
    cout << lexical_cast<string>(0x11) << endl;

    // bool to string, only "0" and "1" can work
    bool bl = lexical_cast<bool>("1");
    cout << bl << endl;

    // exception
    try {
        cout << lexical_cast<int>("0x100") << endl;
        cout << lexical_cast<bool>("false") << endl;
    } catch (bad_lexical_cast& e) {
        cout << "error: " << e.what() << endl;
    }

    //self defined class
    foo demo = foo();
    cout << lexical_cast<string>(demo) << endl;

    return 0;
}
