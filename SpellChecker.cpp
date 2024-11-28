#include "SpellChecker.h"

#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

SpellChecker::SpellChecker() {}

void SpellChecker::loadDictionary(const vector<string> &words)
{

  for (const auto &word : words)
  {

    trie.insert(word);
  }
}

bool SpellChecker::checkSpelling(const string &word)
{
  return trie.search(word);
}

vector<string> SpellChecker::getSuggestions(const std::string &word)
{

  vector<string> suggestions = trie.suggest(word.substr(0, 3));
  vector<string> bestSuggestions;

  for (const auto &suggestion : suggestions)
  {

    if (levenshteinDistance(word, suggestion) <= 2)
    {

      bestSuggestions.push_back(suggestion);
    }
  }
  return bestSuggestions;
}
