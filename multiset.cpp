//contains a sorted set of duplicate objects of type key
//log complexity
//implemented using Red-Black tree
//multiset is similar to set except it can have multiple elements with same value.

#include <iostream>
#include <set>
#include <string>
#include <functional>
using namespace std;

class Person{
    public:
        float age;
        string name;
    
    bool operator < (const Person& rhs) const{
        return age<rhs.age;
    }
    bool operator > (const Person& rhs) const{
        return age>rhs.age;
    }
};

int main(){
    multiset<Person> multiSet = {{25,"neeraj"},{20,"stark"}};

    for(const auto& e: multiSet){
        cout<< e.age<< " "<<e.name<<endl;
    }
    return 0;
}
/* 
int main(){
    multiset<int, std::greater<>> multiSet = {5,2,4,3,2,5};
    multiSet.insert(20);
    for(const auto& e : multiSet){
        cout<< e<<endl;
    }
}
 */
