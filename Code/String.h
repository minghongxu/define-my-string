#include <iostream>
using namespace std;

class String
{
public:
  explicit String(const char * s = "");

  String( const String & s);

  String operator = (const String & s);

  char & operator [] (int index);

  int size();

  int indexOf(const char c);

  int indexOf(const String pattern);

  bool operator == (const String & s);
  bool operator < (const String & s);

  String operator + (const String & s);

  String operator += (const String & s);

  String reverse() const;
  
  void print(ostream & out);
  void read(istream & in);
  ~String();

private:
  bool inBounds(int i)
  {
    return i >= 0 && i < size();
  }

  struct ListNode
  {
    char info;
    ListNode * next;
    ListNode(char newInfo, ListNode * newNext) : info(newInfo), next(newNext)
    {
    }
    static ListNode * stringToList(const char *s);
    static ListNode * copy(ListNode * L);
    static ListNode * reverse(ListNode * L);
    static ListNode * append(ListNode * L1, ListNode * L2);
    static ListNode * find(char c, ListNode * L);
    static int compare(ListNode * L1, ListNode * L2);
    static void deleteList(ListNode * L);
    static int length(ListNode * L);
  };
  ListNode * head;
};

ostream & operator << (ostream & out, String str);
istream & operator >> (istream & in, String & str);
