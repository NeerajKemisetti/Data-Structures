//store data in sorted order
//usually implemented using Red-Black Tree
//we can pass the order of sorting while constructing the set object
//default ascending order
//it stores unique elements and they are stored in sorted order(A/D)
#include <iostream>
#include <set>
#include <string>
#include <functional>
using namespace std;

class Person{
    public:
        float age;
        string name;
    
    bool operator < (const Person& rhs) const { 
        return age< rhs.age;
    }

    bool operator >(const Person& rhs) const{
        return age>rhs.age;
    }
};

int main(){
    set<int> Set = {1,2,3,4,5,1,2,3,4,5};   //for ascending order
    //set<int,greater> Set = {1,2,3,4,5,1,2,3,4,5}; //decending order
    
    set<Person, greater<>> Set2 = {{55, "neeraj"}, {40, "stark"}, {22,"John"}};
    /* for(const auto& e : Set){
        cout<< e<<endl;
    } */
    for(const auto& e: Set2){
        cout << e.age <<" "<<e.name<<endl;
    }
    return 0;
}
