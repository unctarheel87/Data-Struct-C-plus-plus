#include <iostream>
using namespace std;

class HashTable {
  private:
    string*** keyMap;
    int mapLength;
    int arrSize;

  public:
    HashTable() {
      // Prime number length of HashTable array
      mapLength = 53;
      // Seperate Chaining array size
      arrSize = 500;
      keyMap = new string**[mapLength];
    }
    string*** getHashTable() { return keyMap; };
    int _hash(string key);
    void set(string key, string value);
    string get(string key);
};

int HashTable::_hash(string key) {
  int total;
  int WEIRD_PRIME = 31;
  int length(key.length());
  for (int i = 0; i < min(length, 100); i++) {
    int value(key[i]);
    value -= 96;
    total = (total * WEIRD_PRIME + value) % mapLength;
  }
  return total;
}
void HashTable::set(string key, string value) {
  int index = _hash(key);
  if (!keyMap[index]) {
    keyMap[index] = new string*[arrSize];
  }
  for (int i = 0; i < arrSize; i++) {
    if(!keyMap[index][i]) {
      keyMap[index][i] = new string[2] { key, value };
      return;
    }
  }
}
string HashTable::get(string key) {
    int index = _hash(key);
    if (keyMap[index]) {
      for (int i = 0; i < arrSize; i++) {
        if (keyMap[index][i][0] == key) {
          return keyMap[index][i][1];
        }
      }
    }
    return NULL;
  }

int main() {
  HashTable* hash = new HashTable;
  // hash->set("yellow", "1234");
  // cout << hash->get("yellow") << endl;
  return 0;
}