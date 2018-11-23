#include<iostream>
#include<cctype>
#include<vector>
#include<cstdlib>
#include "heap.hpp"

// print heap contents
void printHeap(std::vector<int> input){
    
    // print out every element and its children
    for(int i = 0; i < input.size(); ++i){
        
        // root node case
        if(i == 0){
            std::cout << "Root Data= " << input[0] << "\n";  
            
            // output left child data
            if ( input.size() > 2){
                std::cout << "Left Child data = " << input[1] << "\n";
            }
            // output right child data
            if ( input.size() > 3){
                std::cout << "Right Child data = " << input[2] << "\n";
            }
        // every member node case
        }  else {
            // output data and node number
            std::cout << "Node " << i+1 << " ";
            std::cout << "Data= " << input[i] << "\n";

            // print left child
            if(2*i < input.size()){
                std::cout << "Left Child data = " << input[2*i] << "\n";
            }
        
            // print right child
            if(2*i + 1 < input.size()){
                std::cout << "Right Child data = " << input[2*i+1] << "\n";
            }
        }
    }
}

int main(int argc, char ** argv){

    // usage message
    if( argc <= 1 ){
        std::cerr << "Usage: " << argv[0] << " Number1 Number2 Number3 ...\n";
    }

    // take in the integers as input arguments
    int i = argc;
    std::vector<int> numbers(argc-1);

    // put all the arguments in the vector
    while(--i > 0){

        // check if the arg is a string
        if(isdigit(argv[i][0])){

            numbers[i -1] = atol(argv[i]);
        } else {
            std::cerr << "Non number value found, ignoring that number.\n";
        }
    }

    // sort the heap
    std::vector<int> heap = makeHeap(numbers);

    printHeap(heap);

    return 0;
}