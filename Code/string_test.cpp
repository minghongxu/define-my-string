#include "String.h"
#include<iostream>
using namespace std;

void test_constructors_and_print()
{
    String s("Hello World");
    String s2(s);
    String s3("Monkey is coding");
    String s4(s3);
    cout << s << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
}

void test_assignment()
{
    String s("Monkey is coding");
    String s2;
    String s3("Human is coding");
    s2 = s;
    s = s3;
    cout << s2 << endl;
    cout << s << endl;
}

void test_size()
{
    String s("Hello World");
    String s3("Human is coding");
    cout << s.size() << endl;
    cout << s3.size() << endl;
}

void test_reverse()
{
    String s("Hello World");
    String s3("Human is coding");
    cout << s.reverse() << endl;
    cout << s3.reverse() << endl;
}

void test_index()
{
    String s("Monkey is coding");
    cout << s.indexOf('M') << endl;
    cout << s.indexOf('c') << endl;
}

void test_relationals()
{
    String s("Hello World");
    String s2("Monkey is coding");
    String s3("Human is coding");
    String s4("Hello World");
    String s5("");
    if (s==s2)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    if (s==s4)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    if (s<s2)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    if (s<s5)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
}

void test_concatenation()
{
    String s("Monkey ");
    String s2("Human ");
    String s3("is coding");
    cout << s + s3 << endl;
    cout << s + s2 << endl;
    s += s3;
    cout << s << endl;
    s += s2;
    cout << s << endl;
}

int main()
{
    cout << "-----test_constructors_and_print-----" << endl;
    test_constructors_and_print();
    cout << "-----test_assignment-----" << endl;
    test_assignment();
    cout << "-----test_size-----" << endl;
    test_size();
    cout << "-----test_reverse-----" << endl;
    test_reverse();
    cout << "-----test_index-----" << endl;
    test_index();
    cout << "-----test_relationals-----" << endl;
    test_relationals();
    cout << "-----test_concatenation-----" << endl;
    test_concatenation();
    
    return 0;
}
