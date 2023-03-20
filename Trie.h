#pragma once
#include <string>
#include <iostream>
#include <vector>

const int ALPHABET_SIZE = 26;
// Структура узла дерева
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;// true, если ключ является концом слова

    TrieNode();
    ~TrieNode();
};

class Trie
{
public:
    Trie();
    ~Trie();    

    TrieNode* getNewNode();
    void insert(TrieNode* root, const std::string &key);
    TrieNode* search(const std::string& key);
    void dictionary();//словарь
    std::string enterPrefix();// запрос префикса от пользователя
    std::vector<std::string> vectorWords(TrieNode* pNode, std::string str, std::vector<std::string> vec);//
    void prefix(std::string pref);

private:
    TrieNode* root;
};
