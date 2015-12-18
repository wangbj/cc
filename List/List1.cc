#include <algorithm>
#include <string>
#include <cstdio>
#include <cassert>
 
class List {
private:
  int elem;
  List* next;
public:
  static constexpr List* nil = 0;
  List(int x, List* xs) {
    elem = x;
    next = xs;
  }
  static int head(List* xs) {
    return xs->elem;
  }
  static List* tail(List* xs) {
    return xs->next;
  }
  static List* cons(int x, List* xs) {
    return new List (x, xs);
  }
  static std::pair<int, List*> uncons(List* xs) {
    if (xs != nil) {
      return std::make_pair(xs->elem, xs->next);
    } else {
      assert(0);
    }
  }
 
  static List* concat(List* xs, List* ys) {
    if (xs == nil) return ys;
    if (ys == nil) return xs;
 
    auto x = uncons(xs);
    return cons(x.first, concat(x.second, ys));
  }
 
  static List* singleton(int x) {
    return cons(x, nil);
  }
 
  static List* reverse(List* xs) {
    if (xs == nil) return nil;
 
    auto x = uncons(xs);
    return concat(reverse(x.second), singleton(x.first));
  }
 
  static std::string show(List* xs) {
    std::string res;
 
    if (xs != nil) {
      res += std::to_string(xs->elem);
      res += show(xs->next);
    }
    return res;
  }
};
 
int main(int argc, char* argv[])
{
  List* l1 = List::cons(3, List::nil);
  List* l2 = List::cons(2, l1);
  List* t1 = List::cons(1, l2);
 
  List* r1 = List::cons(7, List::nil);
  List* r2 = List::cons(6, r1);
  List* r3 = List::cons(5, r2);
  List* t2 = List::cons(4, r3);
 
  List* t3 = List::concat(t1, t2);
  List* t4 = List::reverse(t3);
 
  List* t5 = List::cons(10, (List::cons(11, List::nil)));
 
  printf("%s\n", List::show(t3).c_str());
  printf("%s\n", List::show(t4).c_str()); 
  printf("%s\n", List::show(t5).c_str());
 
  return 0;
}

