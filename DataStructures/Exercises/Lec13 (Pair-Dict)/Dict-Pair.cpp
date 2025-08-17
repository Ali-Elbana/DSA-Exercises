/*
============================================================
* Project: Dictionary with Custom Pair Implementation
* File:    Dict-Pair.cpp
* Author:  [Ali El-bana]
* Date:    [2025-08-18]
* Version: [v1.0]
------------------------------------------------------------
* Description:
* Implementation file for custom Pair class and Dictionary
* class methods. Contains all method definitions for both
* template classes.
------------------------------------------------------------
* Notes:
* - Template implementation included in source file
* - All methods are defined here due to template nature
* - Exception handling for invalid operations
============================================================
*/

/* ====================== Includes ====================== */
#include "Dict-Pair.hpp"

/* =================== Namespace Usage ================== */
using std::cout;
using std::endl;

/* ================== Function/Method Definitions =============== */

// ▼▼▼ Pair Class Implementation ▼▼▼

// ▼▼▼ Pair Default Constructor ▼▼▼
template<typename K, typename V>
Pair<K, V>::Pair() : first(K()), second(V()) 
{
    // Default initialization
}
// ▲▲▲ End of Pair Default Constructor ▲▲▲

// ▼▼▼ Pair Parameterized Constructor ▼▼▼
template<typename K, typename V>
Pair<K, V>::Pair(const K& key, const V& value) : first(key), second(value) 
{
    // Initialize with provided values
}
// ▲▲▲ End of Pair Parameterized Constructor ▲▲▲

// ▼▼▼ Pair Copy Constructor ▼▼▼
template<typename K, typename V>
Pair<K, V>::Pair(const Pair& other) : first(other.first), second(other.second) 
{
    // Copy constructor implementation
}
// ▲▲▲ End of Pair Copy Constructor ▲▲▲

// ▼▼▼ Pair Assignment Operator ▼▼▼
template<typename K, typename V>
Pair<K, V>& Pair<K, V>::operator=(const Pair& other) 
{
    if(this != &other) 
	{
        first = other.first;
        second = other.second;
    }
    return *this;
}
// ▲▲▲ End of Pair Assignment Operator ▲▲▲

// ▼▼▼ Pair Destructor ▼▼▼
template<typename K, typename V>
Pair<K, V>::~Pair() 
{
    // Destructor implementation
}
// ▲▲▲ End of Pair Destructor ▲▲▲

// ▲▲▲ End of Pair Class Implementation ▲▲▲

// ▼▼▼ Dictionary Class Implementation ▼▼▼

// ▼▼▼ Dictionary Constructor ▼▼▼
template<typename K, typename V>
Dictionary<K, V>::Dictionary() 
{
    // Initialize empty dictionary
}
// ▲▲▲ End of Dictionary Constructor ▲▲▲

// ▼▼▼ Dictionary Destructor ▼▼▼
template<typename K, typename V>
Dictionary<K, V>::~Dictionary() 
{
    // Clear all data
    clear();
}
// ▲▲▲ End of Dictionary Destructor ▲▲▲

// ▼▼▼ Dictionary get Method ▼▼▼
template<typename K, typename V>
V Dictionary<K, V>::get(const K& key) const 
{
    for(const auto& pair : data)
	{
        if(pair.first == key) 
		{
            return pair.second;
        }
    }
    throw runtime_error("Key not found");
}
// ▲▲▲ End of Dictionary get Method ▲▲▲

// ▼▼▼ Dictionary set Method ▼▼▼
template<typename K, typename V>
void Dictionary<K, V>::set(const K& key, const V& value) 
{
    // Check if key already exists and update
    for(auto& pair : data) 
	{
        if(pair.first == key) 
		{
            pair.second = value;
            return;
        }
    }
    // Key doesn't exist, add new pair
    data.push_back(Pair<K, V>(key, value));
}
// ▲▲▲ End of Dictionary set Method ▲▲▲

// ▼▼▼ Dictionary remove Method ▼▼▼
template<typename K, typename V>
bool Dictionary<K, V>::remove(const K& key) 
{
    for(auto it = data.begin(); it != data.end(); ++it) 
	{
        if(it->first == key) 
		{
            data.erase(it);
            return true;
        }
    }
    return false; // Key not found
}
// ▲▲▲ End of Dictionary remove Method ▲▲▲

// ▼▼▼ Dictionary size Method ▼▼▼
template<typename K, typename V>
size_t Dictionary<K, V>::size() const 
{
    return data.size();
}
// ▲▲▲ End of Dictionary size Method ▲▲▲

// ▼▼▼ Dictionary print Method ▼▼▼
template<typename K, typename V>
void Dictionary<K, V>::print() const 
{
    cout << "Dictionary contents:" << endl;
    for(const auto& pair : data) 
	{
        cout << "  " << pair.first << " -> " << pair.second << endl;
    }
    if(data.empty() == true) 
	{
        cout << "  (empty)" << endl;
    }
}
// ▲▲▲ End of Dictionary print Method ▲▲▲

// ▼▼▼ Dictionary clear Method ▼▼▼
template<typename K, typename V>
void Dictionary<K, V>::clear() 
{
    data.clear();
}
// ▲▲▲ End of Dictionary clear Method ▲▲▲

// ▲▲▲ End of Dictionary Class Implementation ▲▲▲

// Explicit template instantiation for common types
template class Pair<int, int>;
template class Pair<int, std::string>;
template class Pair<std::string, int>;
template class Pair<std::string, std::string>;
template class Pair<char, std::string>;
template class Pair<std::string, char>;


template class Dictionary<int, int>;
template class Dictionary<int, std::string>;
template class Dictionary<std::string, int>;
template class Dictionary<std::string, std::string>;
template class Dictionary<char, std::string>;
template class Dictionary<std::string, char>;

/* ======================= End of File =================== */