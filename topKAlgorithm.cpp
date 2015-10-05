#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
 
using namespace std;
 
void TopKAlgorithm(int inputArray[], int nInputLength, int nOutputLength )
{
       vector<int> vec1(inputArray, inputArray + 10);
       make_heap (vec1.begin(), vec1.end(), greater<int>());
       sort_heap (vec1.begin(), vec1.end());
       for(int i=0;i<vec1.size();i++) {
            cout <<vec1[i] << ' ';
       }
       //construct the minimum heap the size is K
       vector<int> vec(inputArray,inputArray+nOutputLength);
       make_heap (vec.begin(),vec.end(), greater<int>());
      
       
       cout<<'\n';
       for(int i=nOutputLength; i<10; i++)
       {
              if(inputArray[i] >= vec[0])
              {
                     vec[0] = inputArray[i];
//此处其实只需要保持堆的性质即可，并不需要重建堆
                     make_heap (vec.begin(),vec.end(), greater<int>());
              }
       }
 
       for(int i=0; i<nOutputLength; i++)
       {
              inputArray[i]=vec[i];
       }
 
 
}
 
int main ()
{
 
 int InputValues[] = {10,200,30,5,15,110,2,42,6,36};
 
 
 TopKAlgorithm(InputValues, 10, 3);
 
 cout << "The top K Values are:";
 for (unsigned i=0; i<3; i++)
 {
        cout << " " << InputValues[i];
 }
 cout << endl;
 
 return 0;
}