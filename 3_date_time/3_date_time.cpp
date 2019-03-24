#include <iostream>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost;
using namespace boost::gregorian;
//using namespace boost::posix_time;

int main()
{
    // construction
    date d1(2019, 03, 24);
    date d2(2019,Mar, 24);
    date d3(d2);

    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;

    date d4 = from_string("1991-12-15");
    date d5 (from_string("2019/3/24"));
    date d6 = from_undelimited_string("20190324"); // 2019324 error

    cout << d4 <<endl;
    cout << d5 <<endl;
    cout << d6 <<endl;

    cout << day_clock::local_day() << endl;
    cout << day_clock::universal_day() << endl;

    date neg(neg_infin);
    date pos(pos_infin);
    date notdate(not_a_date_time);
    date maxdate(max_date_time);
    date mindate(min_date_time);

    cout << neg << endl;
    cout << pos << endl;
    cout << notdate << endl;
    cout << maxdate << endl;
    cout << mindate <<endl;

    //access member func
    date nowdate = day_clock::local_day();
    date::ymd_type ymd = nowdate.year_month_day();
    cout << ymd.year << endl;
    cout << ymd.month << endl;
    cout << ymd.day << endl;

    date::ymd_type ymd2= day_clock::local_day_ymd();
    cout << ymd2.year << endl;
    cout << ymd2.month << endl;
    cout << ymd2.day << endl;

    cout << nowdate.day_of_week() << endl;
    cout << nowdate.day_of_year() << endl;
    cout << nowdate.end_of_month() << endl;

    // output
    date now = day_clock::local_day();
    // date output
    cout << to_simple_string(now) << endl;			//YYYY-mmm-DD  mmm English
    cout << to_iso_string(now) << endl;				//YYYYMMDD
    cout << to_iso_extended_string(now) << endl;		//YYYY-MM-DD
    cout << now << endl;

    //date duration
    days dd1(10);			// ten days
    weeks w(2);				// two weeks
    months m(5);			// five months
    years y(2);				// two years

    months m2 = y + m;		// two years and 5 months
    //error years y2 = y + m;		// two years and 5 months

    // date compute
    date dstart(2000,1,1), dend(2008,8,8);
    cout << dend - dstart << endl;			// 3142 days

    dstart += days(10);						// 2000-1-11
    dstart += months(2);					// 2000-3-11
    dstart -= weeks(1);						// 2000-3-4
    dstart += years(4);						// 2004-3-4

    //something need to be noticed
    date endofmonth(2010, 3, 30);
    endofmonth -= months(1);				//2010-2-28
    endofmonth -= months(1);				//2010-1-31
    endofmonth += months(2); 				//2010-3-31

    // date period
    date_period pd(dstart, dend);			// (date, date)
    date_period pd1(dstart, days(10));		// (date, days)

    cout << pd << endl;

    pd.shift(days(10));						// shift days, the length is not change
    cout << pd << endl;
    pd.expand(days(3));						// expand days the length add 2N
    cout << pd << endl;

    date date2014 = from_string("2014-01-01");
    date now_date = day_clock::local_day();
    date_period pdl(date2014, now_date);
    date one_day_in_2015 = from_undelimited_string("20150101");
    cout << pdl.contains(one_day_in_2015) << endl;

    date d(2006,11,26);
    day_iterator d_iter(d);
    ++d_iter;

    year_iterator y_iter(d,3);		// 增减步长为3年
    ++y_iter;						// 增加3年
    cout << y_iter->year();


    return 0;
}
