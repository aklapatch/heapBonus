
/// plan, input a integer set, use heap sort to sort them, then put them into a new array to be the heap to return.
#include"heap.hpp"
// heap property, a[i/2] < a[i] 
// this sort just needs to make sure that is true
std::vector<int> makeHeap(std::vector<int> input){
    // it needs to run more than one times to ensure heap property
    for(int j = 0; j < 3; ++j){

        // start from the back and go toward the 0 of the array
        for(int i =input.size()-1; i>=0; --i){
            // swap if heap property is violated
            if(input[i] < input[i/2]){
                int tmp = input[i];
                input[i] = input[i/2];
                input[i/2] = tmp;
            }
        }
    }
    
    return input;
}
