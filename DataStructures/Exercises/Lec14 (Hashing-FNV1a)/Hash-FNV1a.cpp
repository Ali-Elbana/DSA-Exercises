/*
============================================================
* Project: FNV-1a Hash Implementation
* File:    Hash.cpp
* Author:  [Ali El-bana]
* Date:    [2025-08-18]
* Version: [v1.0]
------------------------------------------------------------
* Description:
* Implementation of the FNV-1a hash algorithm supporting both
* 32-bit and 64-bit variants for string input.
------------------------------------------------------------
* Notes:
* - Fowler–Noll–Vo (FNV-1a) hash algorithm.
* - Includes formatted output in decimal and hexadecimal.
============================================================
*/

/* ====================== Includes ====================== */
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdint>

/* =================== Namespace Usage ================== */
using std::cout;
using std::endl;
using std::hex;
using std::dec;
using std::setw;
using std::setfill;

/* =================== Global Constants ================= */
const uint32_t FNV_32_OFFSET_BASIS = 2166136261U;
const uint32_t FNV_32_PRIME        = 16777619U;

const uint64_t FNV_64_OFFSET_BASIS = 14695981039346656037ULL;
const uint64_t FNV_64_PRIME        = 1099511628211ULL;

/* ====================== Declarations ================== */
// ▼▼▼ Class: Hash ▼▼▼
class Hash;
// ▲▲▲ End of Hash ▲▲▲

// ▼▼▼ Function Prototypes ▼▼▼
void displayHashResult32(const std::string& str, uint32_t hash);
void displayHashResult64(const std::string& str, uint64_t hash);
// ▲▲▲ End of Function Prototypes ▲▲▲

/* ===================== Class Definitions =============== */
// ▼▼▼ Class: Hash ▼▼▼
class Hash 
{
public:
    uint32_t Hash32(const std::string& str);
    uint64_t Hash64(const std::string& str);
};
// ▲▲▲ End of Hash ▲▲▲

/* ==================== Main Application ================= */
int main(void) 
{
    // ----- Initialization -----
    system("cls");   // Clear screen (Windows only)
    cout << "FNV-1a Hash Implementation Started...\n";
    cout << "====================================\n";

    // ----- Logic -----
    Hash hashGen;
    std::string testString = "This is Original Text";

    cout << "\nComputing hashes for: \"" << testString << "\"\n";
    cout << "--------------------------------------------\n";

    hashGen.Hash32(testString);
    hashGen.Hash64(testString);

    // ----- End -----
    cout << "\nProgram completed successfully.\n";
    return 0;
}

/* ================== Function/Method Definitions =============== */
// ▼▼▼ Method: Hash32 ▼▼▼
uint32_t Hash::Hash32(const std::string& str) 
{
    uint32_t hash = FNV_32_OFFSET_BASIS;

    for(char c : str) 
	{
        hash ^= static_cast<uint8_t>(c);
        hash *= FNV_32_PRIME;
    }

    displayHashResult32(str, hash);
    return hash;
}
// ▲▲▲ End of Hash32 ▲▲▲

// ▼▼▼ Method: Hash64 ▼▼▼
uint64_t Hash::Hash64(const std::string& str) 
{
    uint64_t hash = FNV_64_OFFSET_BASIS;

    for(char c : str) 
	{
        hash ^= static_cast<uint8_t>(c);
        hash *= FNV_64_PRIME;
    }

    displayHashResult64(str, hash);
    return hash;
}
// ▲▲▲ End of Hash64 ▲▲▲

// ▼▼▼ Function: displayHashResult32 ▼▼▼
void displayHashResult32(const std::string& str, uint32_t hash)
{
    cout << "32-bit: " << str << " -> " 
         << dec << hash 
         << " (0x" << hex << setfill('0') << setw(8) << hash << ")\n";
}
// ▲▲▲ End of displayHashResult32 ▲▲▲

// ▼▼▼ Function: displayHashResult64 ▼▼▼
void displayHashResult64(const std::string& str, uint64_t hash)
{
    cout << "64-bit: " << str << " -> " 
         << dec << hash 
         << " (0x" << hex << setfill('0') << setw(16) << hash << ")\n";
}
// ▲▲▲ End of displayHashResult64 ▲▲▲

/* ======================= End of File =================== */
