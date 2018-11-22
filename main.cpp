#include<iostream>
#include<cctype>
#include<vector>
#include<cstdlib>
#include "heap.hpp"

// print heap contents
void printHeap(std::vector<int> input){
    
    // print out every element and its children
    for(int i = 0; i < input.size(); ++i){
        if(i == 0){
            std::cout << "Root Data= " << input[0] << "\n";  
            
            if ( input.size() > 2){
                
                std::cout << "Left Child data = " << input[1] << "\n";
            }
            if ( input.size() > 3){
                
                std::cout << "Left Child data = " << input[2] << "\n";
            }
        }  else {
            std::cout << "Member " << i+1 << " ";
            std::cout << "Data= " << input[i] << "\n";

            if(2*i < input.size()){
                std::cout << "Left Child data = " << input[2*i] << "\n";
            }
        

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

    while(--i > 0){
        if(isdigit(argv[i][0])){

            numbers[i -1] = atol(argv[i]);
        } else {
            std::cerr << "Non number value found, ignoring that number.\n";
        }
    }

    std::vector<int> heap = makeHeap(numbers);

    printHeap(heap);

    return 0;
}