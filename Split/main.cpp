#include"../Split/Head/head.h"



int main()
{
    int arr[ELEM];
    FillArrayRandov(arr, ELEM);

    std::cout << "Static Arra's Random Elements!" << std::endl;
    ShowArray(arr, ELEM);
    std::cout << std::endl;
    int evenCount = 0;
    int oddCount = 0;
    for(int i = 0; i < ELEM; i++)
    {
        if(arr[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }
    int* even = new int[evenCount];
    int* odd = new int[oddCount];
    evenCount = 0;
    oddCount = 0;
    for(int i = 0; i < ELEM; i++)
    {
        if(arr[i] % 2 == 0)
        {
            even[evenCount++] = arr[i]; 
        }
        else
        {
            odd[oddCount++] = arr[i];
        }
    }
    std::cout << "\t" << "EVEN" << std::endl;
    for(int *i = even; i != even + evenCount; i++)
    {
        std::cout << *i << " \t";
    }
    std::cout << std::endl;
    std::cout << "\t" << "ODD" << std::endl;
    for(int *i = odd; i != odd + oddCount; i++)
    {
        std::cout << *i << " \t";
    }
    std::cout << std::endl;
    delete[]even;
    delete[]odd;
    even = nullptr;
    odd = nullptr;
    return 0;
}