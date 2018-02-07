#include <iostream>
using namespace std;
class queue{
  public:
    queue(int size);
    ~queue();
    void enqueue(int num);
    void dequeue();
    bool empty();
    void display();
  private:
    int *q;
    int read, write, s;
};
queue::queue(int size):read(0),write(0),q(new int[size]()) {
  s = size;
}
queue::~queue() {
    delete q;
}
void queue::enqueue(int num){
  q[write] = num;
  (write++)%s;
}
void queue::dequeue(){
    (read++)%s;
}
void queue::display(){
    for(int i=0; i < s; i++){
        cout << q[i] << "  ";
    }
    cout << endl;
}

int main(){
    queue q1(10);
    q1.display();
}