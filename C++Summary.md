## \<algorithm>

```c++
//sort(defalut: comp = less<T>())
template <class RandomAccessIterator>
void sort (RandomAccessIterator first, RandomAccessIterator last);
template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

## \<queue>

```c++
// priority_queue
// 类型定义
template <class T, class Container=vector<T>, class Compare=less<typename Container::value_type>> class priority_queue;
// 构造函数
explicit priority_queue (const Compare& comp=Compare(), const Container& ctnr=Container());
template <class InputIterator> 
priority_queue (InputIterator first, InputIterator last, const Compare& comp=Compare(), 
                const Container& ctnr=Container());
// 成员函数
// empty size top push pop swap(c++11) emplace(c++11)
#include <iostream>
#include <queue>
using namespace std;

struct Test {
    int value;
    int index;
    explicit Test(int value, int index): value(value), index(index) {}
    // 重载运算符<
    // const 成员函数内只能调用 const 函数
    // 仿函数less的operator()为const !!!
    bool operator< (const Test& t) const {
        return value < t.value;
    }
};

int main () {
    Test t1(20, 0), t2(10, 1), t3(30, 2);

    priority_queue<Test> q; 
//  等同于 priority_queue<Test, vector<Test>, less<Test>> q; 大顶堆
    
    q.push(t1); q.push(t2); q.push(t3);

    while (!q.empty()) {
        cout << q.top().value << " " << q.top().index << endl;
        q.pop();
    }
    return 0;
}
```

## 仿函数 operator()

```c++
//计算数组中大于输入阈值的元素个数
#include <iostream>
using namespace std;

class Func {
public:
    const int threshold;
    explicit Func(int t): threshold(t){}
    bool operator() (int num) const {
        return num > threshold;
    }
};

int RecallFunc(int *start, int *end, Func func) {
    int count = 0;
    for (int *i = start; i != end + 1; i++) {
        count = func(*i) ? count + 1 : count;
    }
    return count;
}

int main() {
    int a[5] = {10,100,11,5,19};
    int result = RecallFunc(a, a + 4, Func(10));
    cout << result << endl;
}
```

## 类构造函数（不返回任何类型包括void）

```c++
#include <iostream>
using namespace std;

class Line {
public:
    double length;
    //无参构造
    Line() {
        length = 5.0;
    }
    //有参构造()
    explicit Line(double len) {
        length = len;
    }
    //使用初始化列表来初始化字段
    explicit Line(double len): length(len) {}
};
int main() {
    Line line1, line2(5.0);
    //explicit 关键字防止隐式类型转换e.g.
    Line line3 = 5.0; //报错
    return 0;
}
```

