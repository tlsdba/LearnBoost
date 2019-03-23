#include <iostream>
#include <boost/timer.hpp>
#include <boost/date_time.hpp>

using namespace std;
using namespace boost;
//using namespace boost::posix_time;

int main()
{
    timer t;
    cout << "max time: " << t.elapsed_max() / 3600.0 << "h" << endl;
    cout << "min time: " << t.elapsed_min() << "s" << endl;
    cout << "now time elapsed: " << t.elapsed() << "s" << endl;

    return 0;
}
