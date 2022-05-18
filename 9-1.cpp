#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//const int MAX = 100000;

list<int> qu{};

bool isEmpty() {
  return (qu.empty());
}

bool isFull() {
  return (qu.size() == qu.max_size());
}

void enqueue(int x) {
  if (isFull()) {
    cout << "error: queue is full." << endl;
    return;
  }
  //最後尾に要素xを追加
  qu.insert(qu.end(), x);
}

int dequeue() {
  if (isEmpty()) {
    cout << "error: queue is empty. ";
    return -1;
  }
  //先頭の要素を削除し、その値をreturn
  int& res = qu.front();
  qu.pop_front();
  return res;
}

int main(){
  string str;
  while(true) {
    cin >> str;

    //入力 "e <数字>" で<数字>をenqueueできる
    if (str == "e") {
      int x;
      cin >> x;
      enqueue(x);
    }

    //入力 "d" でdequeueできる
    else if (str == "d") {
      cout << dequeue() << endl;
    }

    //"e", "d"以外の入力で終了
    else {
      break;
    }
  }
  
  return 0;
}
