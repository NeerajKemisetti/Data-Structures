//unordered set is a associative container that contains set of unique objects.
//search, insertion and removal have average constant time complexity
// internally the elements are organized into buckets
// It uses hashing to insert elememnts into buckets
// this allows fast access to individual elements, since once a hash bucket is
// computed, it referes to the exact bucket the element is placed into

//Why unorderedset? to maintain a collection of unique item with fast insertion and removal

#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> uset = {4,1,2,3,4,2,3};

    auto search=uset.find(2);

    if(search != uset.end()){
        cout<< "Found" << (*search) <<'\n';
    }else {
        cout<< "NOt found\n";
    }
    for(auto& elm: uset){
        cout<< elm<< " ";
    }
    cout<< endl;
    return 0;
}
