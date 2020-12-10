// associative container that contains set of possibly non-unique objects
//search, insertion and removal haev average const-time complecity
//internally the elements are organized into buckets
//uses hashing to insert elements into buckets
//why/?? maintain a collection of non-unique items with fast insertion and removal

#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_multiset<int> umset = {4,1,2,3,9,4,3,2,9,8,10};

    auto search=umset.find(2);

    if(search != umset.end()){
        cout<< "Found" << (*search) <<'\n';
    }else {
        cout<< "NOt found\n";
    }
    for(auto& elm: umset){
        cout<< elm<< " ";
    }
    cout<< endl;
    cout<< umset.count(4)<<endl;
    return 0;
}
