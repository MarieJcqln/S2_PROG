#include <vector>
#include <algorithm>
#include<iostream>

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
//std::swap(a,b);

int main(){
if (is_sorted(array)) {
    std::cout << "Le tableau est trié" << std::endl;
} else {
    std::cout << "Le tableau n'est pas trié" << std::endl;
}
return 0;
}

void bubble_sort(std::vector<int> & vec){
    int i{0};
    while(i<size(vec)){
        i++;
    }
}

void selection_sort(std::vector<int> & vec);