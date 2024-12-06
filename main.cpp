#include <string>
#include "DizionarioEsteso.cpp"

int main() {

    DizionarioEsteso<std::string> dict;

    
    dict.inserisci("apple", "fruit");
    dict.inserisci("car", "vehicle");
    dict.inserisci("book", "object");

    
    dict.inserisci("bpple", "collision1"); 
    dict.inserisci("cpple", "collision2"); 

    
    dict.stampa();

    
    std::cout << "Value for 'apple': " << dict.recupera("apple") << "\n";
    std::cout << "Value for 'bpple': " << dict.recupera("bpple") << "\n";

    
    std::cout << "Does 'car' exist? " << (dict.appartiene("car") ? "Yes" : "No") << "\n";
    std::cout << "Does 'pen' exist? " << (dict.appartiene("pen") ? "Yes" : "No") << "\n";

    
    dict.cancella("car");
    std::cout << "After deletion of 'car':\n";
    dict.stampa();

    return 0;
}
