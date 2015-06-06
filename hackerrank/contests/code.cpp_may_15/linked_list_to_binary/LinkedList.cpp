// c++0x only
#include <iostream>
using namespace std;

class Node {
public:
    Node *next;
    int data;
};

Node* insertIntoList(Node *cur, int data) {
    if(cur == nullptr) {
        cur = new Node();
        cur->data = data;
        cur->next = nullptr;
    }
    else {
        cur->next = insertIntoList(cur->next, data);
    }
    return cur;
}

long long getNumber(Node *head) {
    // Complete this function
    int res = 0;
    Node *p = head;
    stringstream bin;
    while (1) {
      bin << p->data;
      if (p->next != nullptr)
        p = p->next;
      else
        break;
    }
    string s = bin.str();
    unsigned long long value = std::stoull(s, 0, 2);
    return value;
}

int main()
{
    int N;
    cin >> N;
    Node *head = nullptr;

    for(int i = 0; i < (int)N; ++i) {
        int curData;
        cin >> curData;
        head = insertIntoList(head, curData);
    }

    cout << getNumber(head) << endl;

    return 0;
}
