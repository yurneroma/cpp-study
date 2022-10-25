#include <iostream>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>


using namespace std;

int main() {
    // 队尾插入, 队头弹出
    // push(), pop(), front(), back(); 
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty()) {
        cout << q.front() << ' ';  
        q.pop();
    }
    cout << endl;

    struct Student {
        int Age;
        string name;
        bool operator< (const Student& t) const {
            return Age < t.Age;
        }
    };

    // 优先队列, push(), pop(), top();
    // 实际上是堆, 默认大根堆
    priority_queue<Student> p;
    p.push(Student{Age:1,name:"mabin"});
    p.push(Student{Age:12,name:"hello"});

    while (!p.empty()) {
        cout << p.top().name << p.top().Age << ' ';
        p.pop();
        cout << endl;
    }


    // 双端队列
    // 队头和队尾都可以插入弹出
    deque<int> a;
    a.push_front(1);
    a.push_back(2);
    a.pop_back();
    a.pop_front();


    // set, 动态维护一个有序的集合
    // 红黑树, 平衡树

    set<int> sa; // 元素不能重复   O(log(n))
    multiset<int> sb;  // 有序多重集合, 元素可以重复

    unordered_set<int> ua; // 哈希, 不能存储重复元素, O(1)
    

    int x;
    sa.lower_bound(x); // 返回大于等于x的最小元素
    sa.upper_bound(x); // 返回小于等于x的最大元素

    //map, 底层也是红黑树 ,  O(log(n))
    map<string, string> ma; 
    ma["name"] = "mabin";
    ma.clear();

    // unordered_map, 哈希表, O(1)
    unordered_map<string, string> uma; 
    
    // bitset 
    bitset<1000> ba; // 长度是1000位的字节 
    ba[0] = 1;
    ba[1] = 1;
    cout << ba[0] << endl;
    cout << ba.count() << endl;
    
}