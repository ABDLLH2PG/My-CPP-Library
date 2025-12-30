# 📦 My Custom C++ Libraries

Welcome to my personal collection of **C++ Header-only Libraries**.
I built these libraries from scratch not just to solve problems, but to practice **Clean Architecture** and high-quality coding standards following the roadmap of **Prof. Mohammed Abu Hadhoud**.

---

## 🌟 Design Philosophy & Code Quality

What makes this library special is the way it's built:
* **Divide and Conquer Strategy:** Every complex problem is broken down into small, manageable, and reusable functions.
* **Clean Code:** The code is highly organized, readable, and fully commented.
* **Modular Architecture:** Each function performs a single task (Single Responsibility Principle), making debugging and updating extremely easy.
* **No Spaghetti Code:** Strict adherence to structured programming best practices.

---

## 🚀 Libraries Overview

| Library File | Description |
| :--- | :--- |
| ✅ **`MyInputLib`** | Robust input validation to read Integers, Doubles, and Strings safely without crashing. |
| 🔤 **`MyStringLib`** | Advanced string manipulations, splitting, trimming, and formatting. |
| 📅 **`MyDateLib`** | Full date management: comparison, logic, adding days, and validation. |
| 🔢 **`MyMathLib`** | Custom mathematical helper functions. |
| 🛠️ **`MyUtilityLib`** | General utility functions (Encryption, Random generation, Swapping, etc.). |
| 🧊 **`MyArrayLib`** | Helper functions to manage and manipulate arrays efficiently. |

---

## 💻 How to Use

Since these are **header-only** libraries, you don't need to compile them or link distinct files. Just include the header you need in your project.

### 1. Installation
Simply clone this repository or download the `MyLib` folder to your project directory.

### 2. Example Code
Here is how to include and use the libraries in your `.cpp` file.
*Note: Ensure you include the folder path `MyLib/` before the library name.*

```cpp
#include <iostream>
#include "MyLib/MyInputLib.h"   // Handles safe user input
#include "MyLib/MyUtilityLib.h" // Handles random numbers, encryption, etc.

using namespace std;

int main() {
    
    // --- Example 1: Safe Input Reading (MyInputLib) ---
    // This function keeps asking until the user enters a valid Integer.
    // No more "Cin" crashes!
    int Age = MyInputLib::ReadNumber("Please enter your age: ");
    cout << "Valid Age Received: " << Age << endl;

    // --- Example 2: Utility Functions (MyUtilityLib) ---
    // Generating a random number between 1 and 100
    MyUtilityLib::Srand(); // Initialize random seed
    int RandomNum = MyUtilityLib::RandomNumber(1, 100);
    cout << "\nGenerated Random Number: " << RandomNum << endl;

    // --- Example 3: Text Encryption (MyUtilityLib) ---
    string Text = "Abdullah";
    string Encrypted = MyUtilityLib::EncryptText(Text, 2);
    cout << "Encrypted Name: " << Encrypted << endl;

    return 0;
}
