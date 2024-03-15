#include <vector>
#include <algorithm>
#include<iostream>
#include <cstdlib>
#include "ScopedTimer.hpp"

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}


//std::swap(a,b);

void bubble_sort(std::vector<int> & vec){
    {
    ScopedTimer timer("bubble sort");
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
    
}

//void selection_sort(std::vector<int> & vec);



void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right){
    std::vector<int> vec2(vec.begin(), vec.end());
    // size_t i{left};
    // while (i<=middle){
    //     if(vec2[i]>vec2[i+1]){
    //         std::swap(vec2[i],vec2[i+1]);
    //     }
    //     i++;
    // }
    // size_t j{middle+1};
    // while (j<=right){
    //     if(vec2[j]>vec2[j+1]){
    //         std::swap(vec2[j],vec2[j+1]);
    //     }
    //     j++;
    // }

    int a{0};
    size_t x{left};
    size_t y{middle+1};
    while (x<=middle-left && y<right-middle){
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
    while (x<middle-left){
        vec[left+a]=vec2[x];
        x++;
        a++;
    }
    while(y<right-middle){
        vec[left+a]=vec2[y];
        y++;
        a++;
    }
}

void merge_sort(std::vector<int> & vec, size_t const left, size_t const right){
    if (right > left){
        size_t m{left+(right-left)/2};
        merge_sort(vec,left,m);
        merge_sort(vec,m+1,right);
        merge_sort_merge(vec, left, m, right);
    }
}

void merge_sort(std::vector<int> & vec) {
    {
    ScopedTimer timer("merge sort");
    merge_sort(vec, 0, vec.size() - 1);}
}

void search(std::vector<int> vec) {
    if (is_sorted(vec)) {
        
    } else {
        std::cout << "Le tableau doit être trié" << std::endl;
    }  
}

int main(){
    //std::vector<int> array {6, 2, 7, 4, 9, 1, 3, 8, 5};

    std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
    {
    ScopedTimer timer("blibliotheque standard");
    std::sort(array.begin(), array.end());
    }
    //Rapide par rapport aux fonctions de tri codées

    merge_sort(array);
    //bubble_sort(array);
    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
    return 0;
}


