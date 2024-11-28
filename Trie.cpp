#include "Trie.h"

Trie::Trie()
{
  root = new TrieNode();
}

// Helper function to map a character to an index (0-51)
int Trie::charToIndex(char ch)
{
  if (ch >= 'a' && ch <= 'z')
  {
    return ch - 'a'; // Map lowercase to 0-25
  }
  else if (ch >= 'A' && ch <= 'Z')
  {
    return ch - 'A' + 26; // Map uppercase to 26-51
  }
  return -1; // Invalid character
}

void Trie::insert(const std::string &word)
{
  TrieNode *node = root;
  for (char ch : word)
  {
    int index = charToIndex(ch);
    if (index == -1)
    {
      continue; // Skip invalid characters
    }
    if (node->children[index] == nullptr)
    {
      node->children[index] = new TrieNode();
    }
    node = node->children[index];
  }
  node->isEndOfWord = true;
}

bool Trie::search(const std::string &word)
{
  TrieNode *node = root;
  for (char ch : word)
  {
    int index = charToIndex(ch);
    if (index == -1 || node->children[index] == nullptr)
    {
      return false;
    }
    node = node->children[index];
  }
  return node->isEndOfWord;
}

void Trie::suggestHelper(TrieNode *node, std::string currentWord, std::vector<std::string> &suggestions)
{
  if (node->isEndOfWord)
  {
    suggestions.push_back(currentWord);
  }
  for (int i = 0; i < 52; ++i)
  {
    if (node->children[i] != nullptr)
    {
      char ch = (i < 26) ? 'a' + i : 'A' + (i - 26);
      suggestHelper(node->children[i], currentWord + ch, suggestions);
    }
  }
}

std::vector<std::string> Trie::suggest(const std::string &prefix)
{
  TrieNode *node = root;
  std::vector<std::string> suggestions;

  for (char ch : prefix)
  {
    int index = charToIndex(ch);
    if (index == -1 || node->children[index] == nullptr)
    {
      return suggestions; // No suggestions found
    }
    node = node->children[index];
  }

  suggestHelper(node, prefix, suggestions);
  return suggestions;
}
