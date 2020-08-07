// Student ID: 20274909

#include "Matrix_Algorithms.h"
#include <iostream>

using namespace std;

int main()
{

   Sparse_Matrix<int> test1(3, 5, 0);
   Sparse_Matrix<int> test2(5, 2, 0);

   test1.set(0, 0, 1);
   test1.set(0, 2, 7);
   test1.set(0, 4, 9);
   test1.set(2, 1, 1);

   test2.set(0, 1, 2);
   test2.set(1, 0, 1);
   test2.set(1, 1, 0);
   test2.set(2, 0, 3);
   test2.set(2, 1, 1);
   test2.set(3, 0, 2);
   test2.set(3, 1, 2);
   test2.set(4, 0, 5);
   test2.set(4, 1, 5);

   Mx temp = Mx();

   Sparse_Matrix<int> res;

   temp.multiply(test1, test2, res);
   
   cout << res.get_slice(0, 0, 2, 1);


}