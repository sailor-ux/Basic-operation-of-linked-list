#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

int _size = 0; // 全局变量

void getAtIndex(int a, ListNode* dummyHead) {
    if (a < 1 || a > _size) {
        cout << "get fail" << endl;
        return;
    }
    while (a) {
        a--;
        dummyHead = dummyHead->next;
    }
    cout << dummyHead->val << endl;
}

void deleteAtIndex(int a, ListNode* dummyHead) {
    if (a < 1 || a > _size) {
        cout << "delete fail" << endl;
        return;
    }
    while (--a) {
        dummyHead = dummyHead->next;
    }
    ListNode* delNode = dummyHead->next;
    dummyHead->next = dummyHead->next->next;
    delete delNode;
    cout << "delete OK" << endl;
    _size--;
}

void insertAtIndex(int a, int e, ListNode* dummyHead) {
    if (a < 1 || a > _size) {
        cout << "insert fail" << endl;
        return;
    }
    while (--a) {
        dummyHead = dummyHead->next;
    }
    ListNode* nextNode = dummyHead->next;
    dummyHead->next = new ListNode(e);
    dummyHead->next->next = nextNode;
    cout << "insert OK" << endl;
    _size++;
}

void show(ListNode* head) {
    if (!head) {
        cout << "Link list is empty" << endl;
        return;
    }
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << "\n";
}

int main() {
    int n, m, a, e;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ListNode* dummyHead = new ListNode(-1);
    ListNode* node = dummyHead;
    for (int i = n - 1; i >= 0; i--) {
        node->next = new ListNode(nums[i]);
        node = node->next;
    }
    _size = n;
    cin >> m;
    getchar();
    string str;
    while (m--) {
        cin >> str;
        if (str == "get") {
            cin >> a;
            getAtIndex(a, dummyHead);
        } else if (str == "delete") {
            cin >> a;
            deleteAtIndex(a, dummyHead);
        } else if (str == "insert") {
            cin >> a >> e;
            insertAtIndex(a, e, dummyHead);
        } else if (str == "show") {
            show(dummyHead->next);
        }
    }
    return 0;
}