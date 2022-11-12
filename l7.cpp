#include <iostream>
#include <string>
#include <vector>
template <typename T>
const void ind(const T& arr, size_t size)
{
   typename T::value_type key;
    std::cout <<"\nVvedite key\n";
    std::cin >> key;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == key)
        { 
            std::cout <<"Naideno "<< arr[i] << " c indexom " << i<<"\n";
        }
    }
}
int main()
{
    std::vector<int> arr{ 1,2,3,4 };
    ind(arr, arr.size());
    std::string str("ajs");
    ind(str,str.length());
    return 0;
}
