// Student ID: 20274909

#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>

#include "Matrix.h"
#include "Sparse_Matrix.h"

using namespace std;

#ifndef Matrix_Algorithms_h
#define Matrix_Algorithms_h

class Mx {
public:
   template <typename T> static bool can_multiply(const Matrix<T>& a, const Matrix<T>& b) {
      if (a.get_num_cols() == b.get_num_rows())
         return true;
      return false;
   }

   template <typename T> static bool multiply(const Matrix<T>& a, const Matrix<T>& b, Matrix<T>& res) {
      
      if (can_multiply(a, b)) {
         res.clear();
         res.resize(a.get_num_rows(), b.get_num_cols());

         for (size_t j = 0; j < res.get_num_rows(); j++) {
            for (size_t k = 0; k < res.get_num_cols(); k++) {
               T result = 0;
               for (size_t l = 0; l < a.get_num_cols(); l++) {
                  result += a.const_at(j, l) * b.const_at(l, k);
               }
               res.at(j, k) = result;
            }
         }
         return true;
      }
      return false;
   }

   // Sparse_Matrix utils----------------------------------------------------------

   template <typename T> static bool can_multiply(const Sparse_Matrix<T>& a, const Sparse_Matrix<T>& b) {
      if (a.get_num_cols() == b.get_num_rows())
         return true;
      return false;
   }

   template <typename T> static bool add_to_cell(Sparse_Matrix<T>& spmat, size_t r, size_t c, const T& val) {
      if (!spmat.is_valid(r, c))
         return false;

      T spmat_val = spmat.get(r, c);

      if (spmat.is_default(val + spmat_val)) {
         spmat.set(r, c, spmat._default_val);
      }
      else {
         spmat.set(r, c, val + spmat_val);
      }
      return true;
   }

   template <typename T> static bool multiply(const Sparse_Matrix<T>& a, const Sparse_Matrix<T>& b, Sparse_Matrix<T>& res) {
      if (can_multiply(a, b)) {
         res = Sparse_Matrix<T>(a.get_num_rows(), b.get_num_cols());
         //res.clear();
         //res._num_rows = a.get_num_rows();
         //res._num_cols = b.get_num_cols();
         //res._rows.resize(a.get_num_rows());


         for (size_t j = 0; j < res._num_rows; j++) {
            if (a._rows[j].empty())
               continue;
            for (size_t k = 0; k < res._num_cols; k++) {
               T total = 0;
               for (auto it = a._rows[j].begin(); it != a._rows[j].end(); ++it) {
                  T temp = it->get_value();
                  size_t col = it->get_col();
                  if (b._rows[col].empty())
                     continue;
                  T temp2 = b.get(col, k);
                  if (res.is_default(temp2))
                     continue;
                  total += (temp * temp2);
               }
               if (total)
                  res.add_Node(j, k, total);
            }
         }
         return true;
      }
      return false;
   }

};

#endif