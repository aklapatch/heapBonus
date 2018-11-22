
/// plan, input a integer set, use heap sort to sort them, then put them into a new array to be the heap to return.
#include"heap.hpp"
// heap property, a[i/2] < a[i] 
// this sort just needs to make sure that is true
void heapSort(std::vector<int>& input){
    // start from the back and go toward the 0 of the array
    for(int i =input.size()-1; i>0; --i){
        // swap if property is violated
        if(input[i] < input[i/2]){
            int tmp = input[i];
            input[i] = input[i/2];
            input[i/2] = tmp;
        }
    }
}

std::vector<int> makeHeap(std::vector<int> input){
    std::vector<int> ret(input.size()); // make return vector

    heapSort(input);

    ret = input;
    
    return ret;

}
