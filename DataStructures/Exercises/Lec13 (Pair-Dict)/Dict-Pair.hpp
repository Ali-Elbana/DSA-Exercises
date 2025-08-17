/*
============================================================
* Project: Dictionary with Custom Pair Implementation
* File:    Dict-Pair.hpp
* Author:  [Ali El-bana]
* Date:    [2025-08-18]
* Version: [v1.0]
------------------------------------------------------------
* Description:
* Header file containing custom Pair class and Dictionary 
* class declarations for a generic dictionary data structure
* using a vector of custom pairs.
------------------------------------------------------------
* Notes:
* - Template-based implementation for generic types
* - Dictionary uses vector of Pair objects for storage
* - Linear search implementation (O(n) complexity)
============================================================
*/

#ifndef DICT_PAIR_HPP
#define DICT_PAIR_HPP

/* ====================== Includes ====================== */
#include <iostream>
#include <vector>
#include <stdexcept>

/* =================== Namespace Usage ================== */
using std::cout;
using std::endl;
using std::vector;
using std::runtime_error;

/* ====================== Declarations ================== */
// ▼▼▼ Class: Pair ▼▼▼
template<typename K, typename V>
class Pair;
// ▲▲▲ End of Pair ▲▲▲

// ▼▼▼ Class: Dictionary ▼▼▼
template<typename K, typename V>
class Dictionary;
// ▲▲▲ End of Dictionary ▲▲▲

/* ===================== Class Definitions =============== */
// ▼▼▼ Class: Pair ▼▼▼
template<typename K, typename V>
class Pair 
{
public:
    K first;
    V second;
    
    // Constructors
    Pair();
    Pair(const K& key, const V& value);
    
    // Copy constructor
    Pair(const Pair& other);
    
    // Assignment operator
    Pair& operator=(const Pair& other);
    
    // Destructor
    ~Pair();
};
// ▲▲▲ End of Pair ▲▲▲

// ▼▼▼ Class: Dictionary ▼▼▼
template<typename K, typename V>
class Dictionary 
{
private:
    vector<Pair<K, V>> data;

public:
    // Constructor
    Dictionary();
    
    // Destructor
    ~Dictionary();
    
    // Core methods
    V get(const K& key) const;
    void set(const K& key, const V& value);
    bool remove(const K& key);
    size_t size() const;
    void print() const;
    
    // Helper methods
    void clear();
};
// ▲▲▲ End of Dictionary ▲▲▲

#endif // DICT_PAIR_HPP

/* ======================= End of File =================== */