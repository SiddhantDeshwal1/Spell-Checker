#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

class TrieNode
{
public:
  TrieNode *children[52]; // Fixed array for 26 lowercase + 26 uppercase
  bool isEndOfWord;

  TrieNode() : isEndOfWord(false)
  {
    for (int i = 0; i < 52; ++i)
    {
      children[i] = nullptr;
    }
  }
};

class Trie
{
public:
  Trie();
  void insert(const std::string &word);
  bool search(const std::string &word);
  std::vector<std::string> suggest(const std::string &prefix);

private:
  TrieNode *root;
  int charToIndex(char ch); // Declare helper function here
  void suggestHelper(TrieNode *node, std::string currentWord, std::vector<std::string> &suggestions);
};

#endif
