## <font color="yellow"><u>Introduction:</u></f>

#### **Definition of Notation**

In general, **notation** refers to a system of symbols, characters, or expressions used to represent ideas, quantities, relationships, or operations in a concise and standardized manner. It is a fundamental tool in mathematics, science, and programming, allowing complex concepts to be communicated clearly and efficiently.

In the context of **algorithm analysis**, notation is used to express the performance and behavior of algorithms in terms of time complexity, space complexity, and other characteristics.

---
#### **Definition of Big O Notation**

Big O notation is a mathematical concept used to describe the upper bound of an algorithm's growth rate. It provides an asymptotic analysis of an algorithm's performance, representing the worst-case scenario as the input size (n) grows. Big O focuses on the dominant term in a function and disregards lower-order terms and constants, as these become negligible for large inputs.

---
#### **Big O Notation Explained**

Big O is used to express the **time complexity** or **space complexity** of an algorithm. Formally, a function f(n) is O(g(n)) if there exist constants c>0 and n0 ≥0 such that:

f(n) ≤ c⋅g(n), for all n≥n0 

Here:

- f(n): Actual performance function.
- g(n): Simplified growth rate (dominant term).
- c: A constant multiplier.
- n0: The threshold beyond which the inequality holds.

---
#### **Mathematical Examples**

1. **Linear Function**:
    
    f(n)=5n+10
    - For large n, the constant 10 and coefficient 5 are negligible.
    - f(n) is O(n).
2. **Quadratic Function**:
    
    f(n) = 3n^2 + 2n + 1
    - For large n, the dominant term is n^2.
    - f(n) is O(n^2).
3. **Logarithmic Function**:
    
    f(n)=log⁡ n+20
    - Dominant term is log⁡ n.
    - f(n) is O(log⁡ n).

---
#### **Coding Examples in C++**

1. **Constant Time – O(1):**
    
    ```cpp
    int getFirstElement(vector<int>& vec) {
        return vec[0]; // Always takes the same time regardless of vector size.
    }
    ```
    
2. **Linear Time – O(n):**
    
    ```cpp
    int sumElements(vector<int>& vec) {
        int sum = 0;
        for (int i : vec) {
            sum += i; // Iterates through all elements.
        }
        return sum;
    }
    ```
    
3. **Quadratic Time – O(n^2):**
    
    ```cpp
    void printPairs(vector<int>& vec) {
        for (size_t i = 0; i < vec.size(); i++) {
            for (size_t j = 0; j < vec.size(); j++) {
                cout << vec[i] << ", " << vec[j] << endl;
            }
        }
    }
    ```
    
4. **Logarithmic Time – O(log⁡ n):**
    
    ```cpp
    int binarySearch(vector<int>& vec, int target) {
        int left = 0, right = vec.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid] == target) return mid;
            if (vec[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    ```
    

---
#### **Complexity Classes**

![image](https://github.com/user-attachments/assets/56b67a1d-4658-4f38-9967-6789cf64fc22)

---
#### **Examples of Complexity Classes**

1. **Constant Time – O(1):**
    
    - Array element access: `arr[0]`.
2. **Linear Time – O(n):**
    
    - Summing elements in an array.
3. **Logarithmic Time – O(log ⁡n):**
    
    - Binary search in a sorted array.
4. **Quadratic Time – O(n^2):**
    
    - Finding all pairs in a dataset.
5. **Exponential Time – O(2^n):**
    
    - Solving the Tower of Hanoi.

---
#### **Summary**

Big O notation is a mathematical tool for evaluating and comparing algorithms' efficiency, focusing on their growth rates relative to input size. It classifies algorithms into complexity classes, helping programmers choose the most efficient solution for their needs.

---
### **Summary Table: Complexity Classes**

| **Complexity Class** | **Notation** | **Description**                       | **Example**           |
| -------------------- | ------------ | ------------------------------------- | --------------------- |
| **Constant**         | O(1)         | Independent of input size             | Array access          |
| **Logarithmic**      | O(log⁡ n)    | Reduces problem size exponentially    | Binary search         |
| **Linear**           | O(n)         | Proportional to input size            | Array traversal       |
| **Linearithmic**     | O(n log ⁡n)  | Combination of linear and logarithmic | Merge Sort, Heap Sort |
| **Quadratic**        | O(n^2)       | Growth is squared with input size     | Nested loops          |
| **Exponential**      | O(2^n)       | Growth doubles with each increase     | Recursive Fibonacci   |

---
