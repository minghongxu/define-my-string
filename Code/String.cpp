#include "String.h"

String::ListNode* String::ListNode::stringToList(const char *s)
{
  if (*s == '\0')
    return nullptr;
  else
    return new ListNode(*s, stringToList(s+1));
}

String::ListNode* String::ListNode::copy(ListNode * l)
{
  return l == nullptr ? nullptr: new ListNode(l-> info, copy(l->next));
}

String::ListNode* String::ListNode::reverse(ListNode * l)
{
  ListNode * result = nullptr;
  for (ListNode * p = l; p != nullptr; p = p->next)
    result = new ListNode(p->info, result);
  return result;
}

String::ListNode* String::ListNode::append(ListNode * l1, ListNode * l2)
{
  return l1 == nullptr ? copy(l2): new ListNode(l1->info, append(l1->next, l2));
}

String::ListNode* String::ListNode::find(char c, ListNode * l)
{
  return l ==nullptr ? nullptr: l->info == c ? l :find(c, l->next);
}

int String::ListNode::compare(ListNode * l1, ListNode * l2)
{
  if (l1 == nullptr && l2 == nullptr)
    return 0;
  else if (l1 == nullptr)
    return -1;
  else if (l2 == nullptr)
    return 1;
  else
    return compare(l1->next, l2->next);
}

void String::ListNode::deleteList(ListNode * l)
{
  if (l != NULL)
    {
      deleteList(l->next);
      delete l;
    }  
}

int String::ListNode::length(ListNode * l)
{
  return l == nullptr ? 0: 1 + length(l->next);
}


String::String(const char * s)
{
  head  = ListNode::stringToList(s);
}

String::String( const String & s)
{
  head = ListNode::copy(s.head);
}

String String :: operator = (const String & s)
{
  ListNode::deleteList(head);
  head = ListNode::copy(s.head);  
  return *this;
}

char & String :: operator [] (int index)
  {
    if (inBounds(index))
      {
      for (int i = 0; i < index; i++)
        {head = head->next;}
      return head->info;
      }
    else
      cout << "Index is out of range" << endl;
  }

int String :: size()
  {
    return ListNode::length(head);
  }

int String :: indexOf(char c)
  {
    if (ListNode::find(c, head) == NULL)
    {
      cout << "Not found" << endl;
      return -1;
    }
    else 
    {
      int i;
      for (i=0;head != nullptr; i++)
      {
        if (head->info == c)
          return i;
        head = head->next;
      }
    }
  }

bool String :: operator == (const String & s)
  {
    return ListNode::compare(head, s.head) == 0;
  }

bool String :: operator < (const String & s)
  {
    return ListNode::compare(head, s.head) < 0;
  }

String String :: operator + (const String & s)
  {
    String result;
    result.head = ListNode::append(head, s.head);
    return result;
  }

String String :: operator += (const String & s)
  {
    ListNode * temp = ListNode::append(head, s.head);
    ListNode::deleteList(head);
    head = temp;
    return *this;
  }

String String :: reverse() const
  {
    String result;
    result.head = ListNode::reverse(head);
    return result;
  }

void String :: print(ostream & out)
  {
    for (int i =0; head != nullptr; i++)
    {
      out << head->info;
      head = head->next;
    }
  }
void String :: read(istream & in)
  {
    char *input = new char[1000];
    in >> input;
    ListNode::deleteList(head);
    head = ListNode::stringToList(input);
    delete [] input;
  }

String :: ~String()
{
  ListNode::deleteList(head);
}

ostream & operator << (ostream & out, String str)
{
  str.print(out);
  return out;
}
istream & operator >> (istream & in, String & str)
{
  str.read(in);
  return in;
}
