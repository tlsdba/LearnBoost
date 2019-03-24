#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;
using namespace boost;

class SmallClass
{
    public:
        SmallClass(int x_val)
        {
            x = x_val;
            std::cout << "SmallClass construct " << x << std::endl;
        }

        virtual ~SmallClass()
        {
            std::cout << "SmallClass destory " << x << std::endl;
        }

        int GetX()
        {
            return x;
        }

    private:
        int x;
};

void print_count_func(boost::shared_ptr<int> p){
    std::cout << "cout: " << p.use_count() << " value= " << *p << std::endl;
}

class shared {
private:
    boost::shared_ptr<int> p;

public:
    shared(boost::shared_ptr<int> _p):p(_p) {}
    void print(){
        std::cout << "cout: " << p.use_count() << " value= " << *p << std::endl;
    }
};

class ClassOne
{
public:
    ClassOne(int data_param):ptr_data(new int)
    {
        init(data_param);
        std::cout << "construct" << std::endl;
    }

    virtual ~ClassOne()
    {

    }

    int get_data() const{
        return *ptr_data;
    }

    long ptr_count() const {
        return ptr_data.use_count();
    }

    void init(int data_param)
    {
        *ptr_data = data_param;
    }

private:
    boost::shared_ptr<int> ptr_data;
};

int main()
{
    scoped_ptr<string> sp(new string("text"));
    cout << *sp << endl;
    cout << sp->size() << endl;

    auto_ptr<int> ap(new int(10)); // not recommented to use auto_ptr
    scoped_ptr<int> scoped(ap);
    assert(ap.get() == 0);

    ap.reset(new int(20));
    cout << *ap << ", " << *scoped << endl;

    auto_ptr<int> ap2;
    ap2 = ap;

    assert(ap.get() == 0);
    cout << *ap2 << endl;

    //scoped_ptr
    cout << "test class " << endl;

    scoped_ptr<int> int_ptr(new int);
    *int_ptr = 100;
    ++*int_ptr;
    cout << *int_ptr << endl;

    scoped_ptr<SmallClass> sc_ptr(new SmallClass(0));
    cout << sc_ptr->GetX() << endl;
    sc_ptr.reset();
    cout << "end" << endl;

    //scopted_array
    scoped_array<int> scopedarr(new int[100]);
    scopedarr[0] = 100;
    //*(scopedarr+1) = 200;// error
    fill_n(&scopedarr[0], 100, 2);
    cout << scopedarr[1] << " " << scopedarr[2] << endl;

    scopedarr[3] = scopedarr[0] + scopedarr[1];
    cout << scopedarr[3] << endl;

    cout << scopedarr.get()[3] << endl;

    //shared_ptr
    boost::shared_ptr<int> p0;

    boost::shared_ptr<int> p1(new int);
    *p1 = 12;
    boost::shared_ptr<int> p2(p1);
    cout << "p1 count: " << p1.use_count() << " p1 value: " << *p1 << " p2 value: " << *p2 << endl;
    *p2 = 13;
    cout << "p1 count: " << p1.use_count() << " p1 value: " << *p1 << " p2 value: " << *p2 << endl;
    p2.reset();
    cout << "p1 count: " << p1.use_count() << endl;

    boost::shared_ptr<int> sp1(new int(100));
    print_count_func(sp1);
    print_count_func(sp1);
    shared shared1(sp1), shared2(sp1);

    shared1.print();
    shared2.print();

    print_count_func(sp1);

    *sp1 = 200;

    print_count_func(sp1);
    shared shared3(sp1);
    print_count_func(sp1);
    shared1.print();

    boost::shared_ptr<string> strp = boost::make_shared<string>("make_test");
    boost::shared_ptr<vector<int> > vecp = boost::make_shared< vector<int> >(10, 3);

    cout << *strp << " " << vecp->size() << endl;

    // shared_ptr in vector
    typedef std::vector< boost::shared_ptr<int> > vs;
    vs v(10);

    int i = 0;
    for (vs::iterator pos = v.begin(); pos != v.end(); ++pos) {
        *pos = boost::make_shared<int>(++i);
        std::cout << *(*pos) << ", ";
    }
    std::cout << std::endl;

    boost::shared_ptr<int> ptest = v[9];
    *ptest = 100;
    std::cout << *v[9] << std::endl;

    //
    ClassOne c1(10);
    ClassOne c2(c1);
    ClassOne c3 = c2;

    std::cout << c1.ptr_count() << std::endl;
    std::cout << c2.get_data() << std::endl;

    return 0;
}
