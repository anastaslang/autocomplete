#include"Trie.h"

int main()
{
   

    Trie trie;
    trie.dictionary();
     std::cout << std::endl;
     std::cout << "тест консольный" << std::endl;
     //тест консольный
     std::cout << std::endl;
     trie.prefix("te");
     trie.prefix("la");
     trie.prefix("ri");
     trie.prefix("river");
     trie.prefix("late");
     trie.prefix("ter");
     trie.prefix("te08");
     std::cout << std::endl;
     std::cout << "тест пользовательский" << std::endl;
     std::cout << std::endl;
     //тест пользовательский(предлагаем пользователю ввести префикс)
     std::string pref = trie.enterPrefix();
     trie.prefix(pref);

    return 0;
}

