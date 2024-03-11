#include <vector>
#include <algorithm>
#include<iostream>

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

std::vector<int> array {6, 2, 7, 4, 9, 1, 3, 8, 5};
//std::swap(a,b);

void bubble_sort(std::vector<int> & vec){
    while (is_sorted(vec)==false){
        int i{0};
        while(i<size(vec)){
            if (vec[i]>vec[i+1]){
                std::swap(vec[i],vec[i+1]);
            }
            i++;
        }
    }
    
}

//void selection_sort(std::vector<int> & vec);

void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right){
    std::vector<int> vec2(vec.begin(), vec.end());
    size_t i{left};
    while (i<=middle){
        if(vec2[i]>vec2[i+1]){
            std::swap(vec2[i],vec2[i+1]);
        }
        i++;
    }
    size_t j{middle+1};
    while (j<=right){
        if(vec2[j]>vec2[j+1]){
            std::swap(vec2[j],vec2[j+1]);
        }
        j++;
    }

    int a{0};
    size_t x{left};
    size_t y{middle+1};
    while (a<right-left +1){
        if(vec2[x]>vec2[y]){
            vec[left+a]=vec2[y];
            y++;
        }
        else{
            vec[left+a]=vec2[x];
            x++;
        }
        a++;
    }

}

void merge_sort(std::vector<int> & vec, size_t const left, size_t const right){
    if (right-left >= 1){
        merge_sort(vec,left,left+(right-left)/2);
        merge_sort(vec,left+(right-left)/2+1,right);
    }
    else if (right == left){
        merge_sort_merge(vec,left,left,right);
    }
}

void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

int main(){
    merge_sort(array);
    //bubble_sort(array);
    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
    return 0;
}


