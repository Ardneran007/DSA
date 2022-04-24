#include<iostream>
#include<queue>
using namespace std;
struct person{
    int age;
    float ht;
    person(int a,float h)
    {
        age=a;
        ht=h;
    }
};

struct mycmp{
    bool operator() (person const &p1,person const &p2){
        p1.ht<p2.ht;
    }
};
int main()
{
    priority_queue<int,vector<person>,mycmp>pq;
    return 0;
}
