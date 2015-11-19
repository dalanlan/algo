#include <iostream>
using namespace std;


struct Node{
  int x;
  Node* next;

  Node() {
    x = 0;
    next = NULL;
  }

  Node(int _x) {
    x = _x;
    next = NULL;
  }

  ~Node() {}

};

Node* mergeSort(Node* a, Node* b) {
  Node* res = NULL;
  if(a == NULL) {
    return b;
  }
  else if(b == NULL) {
    return a;
  }

  if(a->x <= b->x){
    res = a;
    res->next = mergeSort(a->next, b);
  }
  else {
    res = b;
    res->next = mergeSort(a, b->next); 
  }
  return res;
}

int main() {

  Node* list1 = NULL;
  Node* list2 = NULL;
  int n,m,tmp;

  cin >> n;
  Node* tail1 = NULL;
  Node* tail2 = NULL; ///tail pointer 

  for (int i = 1; i <= n; ++i) {
    cin >> tmp;

    if (i == 1) {
      Node* x = new Node(tmp);
      list1 = tail1 = x;
    } else {
      Node* x = new Node(tmp);
      tail1->next = x;
      tail1 = tail1->next;
    }
  }

  cin >> m;
  for (int i = 1, tmp; i <= m; ++i) {
    cin >> tmp;

    if (i == 1) {
      Node* x = new Node(tmp);
      list2 = tail2 = x;
    } else {
      Node* x = new Node(tmp);
      tail2->next = x;
      tail2 = tail2->next;
    }
  }

  Node* list3 = mergeSort(list1, list2);

  for (Node* le = list3; le != NULL; le = le->next)
    cout << le->x << endl;

  for (Node* le = list3; le != NULL;) {
      Node* t = le->next;
      delete le;
      le = t;
  }

  return 0;
}

