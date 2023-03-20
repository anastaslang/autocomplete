#include "Trie.h"


TrieNode::TrieNode()
{
    isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    children[i] = nullptr;
}
TrieNode::~TrieNode()
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (children[i])
            delete children[i];
}

Trie::Trie()
{
    root = new TrieNode();
}

Trie::~Trie()
{
    if (root)
        delete root;
}

TrieNode* Trie::getNewNode()// Возвращает новый узел с пустыми детьми
{
    struct TrieNode* pNode = new TrieNode;// Выделяем память под новый узел
    
    pNode->isEndOfWord = false;// устанавливаем флаг конца слова в false
    
    for (int i = 0; i < ALPHABET_SIZE; i++)// инициализируем детей нулевым указателем
        pNode->children[i] = nullptr;

    return pNode;
}

void Trie::insert(TrieNode* root, const std::string& key)
{
    TrieNode* pNode = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
                
        if (!pNode->children[index])
        {
            pNode->children[index] = getNewNode();
        }
        pNode = pNode->children[index];
    }    
    pNode->isEndOfWord = true;
}

TrieNode* Trie::search(const std::string &key) {
    
    TrieNode* current = root;
    
    for (size_t i = 0; i < key.size(); i++) 
    {
        int index = key[i] - 'a';
        if (current->children[index] && (index < ALPHABET_SIZE && index>=0))
        {
            current = current->children[index];
        }
        else 
        {
            current = nullptr;
            break;
        }
    }
    return current;
}

std::vector<std::string> Trie::vectorWords(TrieNode* pNode, std::string str, std::vector<std::string> vec)
{
    
    if (pNode->isEndOfWord && str.size())
    {
        vec.push_back(str);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        std::string curr = str;
        if (pNode->children[i]) 
        {
            curr += i + 'a';
            vec = vectorWords(pNode->children[i], curr, vec);
        }
    }
    return vec;
}

void Trie::prefix(std::string pref)
{
    std::vector<std::string> temp;
    TrieNode* current = search(pref);
    if (current == nullptr || current == root)
    {
        return;
    }

    std::vector<std::string> vec = vectorWords(current, pref, temp);
    if(vec.empty())
    {
        std::cout << "Не найдено слов с префиксом: " << pref  << std::endl;
        return;
    }
    else
    {
        std::cout << " Жмите Enter чтобы просмотреть все возможные  автодополнения с префиксом:  "<< pref << std::endl;
        std::cout << std::endl;
        for (int i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i];
            std::cout << std::endl;
            int input = std::cin.get();
            std::cout << "\r";
            std::cout << std::endl;
            std::cout << "\r";

            if (input == 13)
            {
                std::cout << vec[i];
                break;
            }
        }
    }
}

std::string Trie::enterPrefix()
{
    std::cout << "Введите префикс: ";
    std::string str;
    std::cin >> str;
    std::cout << std::endl;
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);

    return str;
}

void Trie::dictionary()
{
    insert(root, "test");
    insert(root, "testosterone");
    insert(root, "firefox");
    insert(root, "first");
    insert(root, "following");
    insert(root, "follow");
    insert(root, "river");
    insert(root, "rival");
    insert(root, "elephant");
    insert(root, "table");
    insert(root, "tableau");
    insert(root, "lamp");
    insert(root, "latex");
    insert(root, "later");
}

