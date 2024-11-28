#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include "LevenshteinDistance.h"
#include "Trie.h"
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

class SpellChecker
{

public:
  SpellChecker();

  void loadDictionary(const vector<string> &words);
  bool checkSpelling(const string &word);
  vector<string> getSuggestions(const string &word);

private:
  Trie trie;
};

#endif
