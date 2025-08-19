
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cstdint>

using namespace std;

class HashTable {
private:
public:
  vector<pair<string, string>> entries;
  int initialSize;
  int entriesCount;

public:
  HashTable() {
    this->initialSize = 3;
    this->entriesCount = 0;
    this->entries = vector<pair<string, string>>(this->initialSize);
  }

  ~HashTable() { this->entries.clear(); }

  int GetHash(string key) {
    uint32_t FnvOffsetBasis = 2166136261;
    uint32_t FNVPrime = 16777619;

    string keyStr = key;
    const char *data = keyStr.c_str();
    uint32_t hash = FnvOffsetBasis;

    for (size_t i = 0; i < strlen(data); i++) {
      hash = hash ^ data[i];
      hash = hash * FNVPrime;
    }

    cout << "[hash] " << keyStr << " " << hash << " " << hex << hash << " "
         << hash % static_cast<uint32_t>(this->initialSize) << endl;

    return hash % static_cast<uint32_t>(this->initialSize);
  }

  int CollisionHandling(string key, int hash, bool set) {
    int newHash;
    for (int i = 1; i < this->initialSize; i++) {
      newHash = (hash + i) % this->initialSize;

      cout << "[coll] " << key << " " << hash << ", new hash: " << newHash
           << endl;

      if (set && ((this->entries[newHash].first == "" &&
                   this->entries[newHash].second == "") ||
                  this->entries[newHash].first == key)) {
        return newHash;
      } else if (!set && this->entries[newHash].first == key) {
        return newHash;
      }
    }
    return -1;
  }

  void AddToEntries(string key, string value) {
    int hash = this->GetHash(key);
    if (hash == -1) {
      throw runtime_error("Invalid Hashtable!!!!");
    }

    if (this->entries[hash].first != "" && this->entries[hash].second != "" &&
        this->entries[hash].first != key) {
      hash = this->CollisionHandling(key, hash, true);
    }

    if (hash < this->entries.size() && this->entries[hash].second != value &&
        entries[hash].first != key) {
      this->entries[hash] = pair<string, string>({key, value});
      this->entriesCount++;
    } else if (this->entries[hash].first == key) {
      this->entries[hash].second = value;
    } else {
      throw runtime_error("Invalid Hashtable!!!!");
    }
  }

  void ResizeOrNot() {
    if (this->entriesCount < this->initialSize) {
      return;
    }
    int newSize = this->initialSize * 2;

    cout << "[resize] from " << this->initialSize << " to " << newSize << endl;

    vector<pair<string, string>> entriesCopy(this->initialSize);
    entriesCopy = this->entries;
    this->entries.clear();
    this->entries.resize(newSize);
    this->entriesCount = 0;

    for (int i = 0; i < this->initialSize; i++) {
      if (entriesCopy[i].first == "" && entriesCopy[i].second == "")
        continue;
      this->AddToEntries(entriesCopy[i].first, entriesCopy[i].second);
    }

    this->initialSize = newSize;
    entriesCopy.clear();
  }

  void Set(string key, string value) {
    this->ResizeOrNot();
    this->AddToEntries(key, value);
  }

  string Get(string key) {
    int hash = GetHash(key);
    if (hash < (int)(this->entries.size()) && entries[hash].first != key) {
      hash = CollisionHandling(key, hash, false);
    }
    if (hash == -1 || hash >= this->entries.size()) {
      return "";
    }

    if (entries[hash].first == key) {
      return entries[hash].second;
    } else {
      throw runtime_error("Invalid Hashtable!!!!");
    }
  }

  bool Remove(string key) {
    int hash = GetHash(key);
    if (hash < (int)(this->entries.size()) && entries[hash].first != key) {
      hash = CollisionHandling(key, hash, false);
    }
    
    if (hash == -1 || hash >= this->entries.size()) {
      cout << "[remove] Key '" << key << "' not found" << endl;
      return false;
    }

    if (entries[hash].first == key) {
      cout << "[remove] Removing key '" << key << "' from index " << hash << endl;
      
      // Mark the entry as deleted
      entries[hash].first = "";
      entries[hash].second = "";
      this->entriesCount--;
      
      // Need to rehash entries that might have been displaced by this entry
      // Find all entries that come after this position and were displaced
      vector<pair<string, string>> toRehash;
      int nextIndex = (hash + 1) % this->initialSize;
      
      while (nextIndex != hash && 
             (entries[nextIndex].first != "" || entries[nextIndex].second != "")) {
        
        if (entries[nextIndex].first != "") {
          // Check if this entry's natural hash position is before or at the removed position
          int naturalHash = GetHash(entries[nextIndex].first);
          
          // If the natural position is affected by the removal, we need to rehash
          if ((naturalHash <= hash && nextIndex > hash) || 
              (naturalHash > nextIndex && (naturalHash <= hash || nextIndex > hash))) {
            toRehash.push_back(entries[nextIndex]);
            entries[nextIndex].first = "";
            entries[nextIndex].second = "";
            this->entriesCount--;
          }
        }
        
        nextIndex = (nextIndex + 1) % this->initialSize;
      }
      
      // Rehash the displaced entries
      for (const auto& entry : toRehash) {
        this->AddToEntries(entry.first, entry.second);
      }
      
      return true;
    } else {
      cout << "[remove] Key '" << key << "' not found" << endl;
      return false;
    }
  }

  int Size() { return this->entries.size(); }
  
  int Count() { return this->entriesCount; }
  
  void Print() {
    std::cout << "-----------" << std::endl;
    std::cout << "[Size] " << Size() << " [Count] " << Count() << std::endl;

    for (int i = 0; i < Size(); i++) {
      if (entries[i].second == "") {
        std::cout << "[" << i << "] null" << std::endl;
      } else {
        std::cout << "[" << i << "] " << entries[i].first << ":"
                  << entries[i].second << std::endl;
      }
    }

    std::cout << "============" << std::endl;
  }
};

int main() {
  HashTable table;
  table.Print();
  
  table.Set("Sinar", "sinar@gmail.com");
  table.Set("Elvis", "elvis@gmail.com");
  table.Set("Tane", "tane@gmail.com");
  table.Print();
  
  cout << "[get] " << table.Get("Sinar") << endl;
  cout << "[get] " << table.Get("Tane") << endl;
  
  table.Set("Gerti", "gerti@gmail.com");
  table.Set("Arist", "arist@gmail.com");
  table.Print();
  
  cout << "[get] " << table.Get("Sinar") << endl;
  
  // Test Remove functionality
  cout << "\n--- Testing Remove ---" << endl;
  table.Remove("Elvis");
  table.Print();
  
  cout << "[get] Elvis after removal: '" << table.Get("Elvis") << "'" << endl;
  cout << "[get] Sinar after Elvis removal: " << table.Get("Sinar") << endl;
  
  // Try to remove non-existent key
  table.Remove("NonExistent");
  
  return 0;
}