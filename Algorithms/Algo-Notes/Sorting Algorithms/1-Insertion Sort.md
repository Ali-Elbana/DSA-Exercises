
Insertion Sort is a simple and intuitive sorting algorithm that works similarly to the way we sort playing cards in our hands. It builds the sorted array (or list) one element at a time by comparing each new element to the ones already sorted and inserting it into its correct position.

![image](https://github.com/user-attachments/assets/bef9c66f-c344-4e2f-9a87-e222a0452922)
### **How It Works**
1. Start with the second element (index 1) of the array.
2. Compare it to the elements before it.
3. Insert it into the correct position among the already sorted elements.
4. Repeat steps 2 and 3 for all remaining elements in the array.

![image](https://github.com/user-attachments/assets/ee093741-165c-4056-827e-0afb2aee5cb8)


![image](https://github.com/user-attachments/assets/c2b8a562-f3f0-4687-99a3-ed2359c9d7bb)

### **Algorithm Steps in Pseudocode**
```
for i from 1 to n-1:
    key = array[i]
    j = i - 1
    while j >= 0 and array[j] > key:
        array[j + 1] = array[j]
        j = j - 1
    array[j + 1] = key
```

### **Time Complexity**
- **Best Case (Already Sorted Array):** O(n)
- **Worst Case (Reverse Sorted Array):** O(n^2)
- **Average Case:** O(n^2)
- **Space Complexity:** O(1) (in-place sorting)

### **C++ Implementation**
```cpp
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6};
    insertionSort(data);
    
    std::cout << "Sorted array: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

### **Example Execution**
Given the array: `[12, 11, 13, 5, 6]`
1. Start with `11`. Compare with `12` and insert before it: `[11, 12, 13, 5, 6]`
2. Move to `13`. No change needed: `[11, 12, 13, 5, 6]`
3. Move to `5`. Insert before `11`: `[5, 11, 12, 13, 6]`
4. Move to `6`. Insert before `11`: `[5, 6, 11, 12, 13]`

Sorted array: `[5, 6, 11, 12, 13]`

![image](https://github.com/user-attachments/assets/4fd36863-d956-489a-9532-f245bcd6ffe1)

### **Use Cases**
1. **Small Datasets:** Efficient for small arrays due to its simplicity.
2. **Partially Sorted Arrays:** Performs exceptionally well when the array is nearly sorted.
3. **Educational Purposes:** Useful for introducing sorting concepts due to its straightforward logic.

### **Life Application: Drawing Shapes**
Insertion Sort can be applied in scenarios where shapes are arranged on a canvas based on certain criteria (e.g., size, color, or distance from a reference point). Consider a graphical application where you need to layer shapes from smallest to largest radius for rendering purposes:

#### **C++ Example: Sorting Circles by Radius**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct Circle {
    double radius;
    Circle(double r) : radius(r) {}
};

void insertionSortCircles(std::vector<Circle>& circles) {
    for (size_t i = 1; i < circles.size(); ++i) {
        Circle key = circles[i];
        int j = i - 1;
        while (j >= 0 && circles[j].radius > key.radius) {
            circles[j + 1] = circles[j];
            --j;
        }
        circles[j + 1] = key;
    }
}

int main() {
    std::vector<Circle> circles = {Circle(4.5), Circle(2.3), Circle(3.8), Circle(1.2)};
    insertionSortCircles(circles);

    std::cout << "Circles sorted by radius: ";
    for (const auto& circle : circles) {
        std::cout << circle.radius << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

This program demonstrates sorting shapes for ordered rendering in a graphic design application. It ensures smaller shapes are rendered on top, preserving visibility.

---
