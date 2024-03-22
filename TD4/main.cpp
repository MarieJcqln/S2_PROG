#include <iostream>
#include <vector>
#include <string>
#include <list>


int main()
{
    std::vector<int> vec1 {};
    for (int i=0; i<10;i++){
        vec1.push_back(rand()%100);
    }
    for (std::vector<int>::iterator j{vec1.begin()}; j < vec1.end();j++){
        std::cout << *j << std::endl;
    }

    return 0;
}