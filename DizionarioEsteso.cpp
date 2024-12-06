#include <iostream>

template <typename T>
class DizionarioEsteso {
private:
    static const int TABLE_SIZE = 10; 
    struct Entry {
        std::string key;
        T value;
        bool isOccupied = false;
    };

    Entry table[TABLE_SIZE];

 
    int hashFunction(const std::string key) const {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % TABLE_SIZE; 
        }
        return hash;
    }

public:
    
    void inserisci(const std::string key, const T value) {
        int index = hashFunction(key);
        int start = index;

        while (table[index].isOccupied && table[index].key != key) {
            index = (index + 1) % TABLE_SIZE;
            if (index == start) {
                std::cerr << "Tabella Hash piena\n";
                return;
            }
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
    }

    
    void cancella(const std::string key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                table[index].isOccupied = false;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == start) break;
        }

        std::cerr << "Error: Key not found for deletion!\n";
    }

    
    bool appartiene(const std::string key) const {
        int index = hashFunction(key);
        int start = index;

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == start) break;
        }
        return false;
    }

    
    T recupera(const std::string key) const {
        int index = hashFunction(key);
        int start = index;

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                return table[index].value;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == start) break;
        }

    }

   
    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Index " << i << ": " << table[i].key << " => " << table[i].value << "\n";
            }
        }
    }
};
