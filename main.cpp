#include "LevenshteinDistance.h"

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
#include <bits/stdc++.h>

using namespace std ;

vector<string> loadDictionary(const string &filename) {

  vector<string> dictionary ;

  ifstream file(filename) ;
  string word ;

  if (file.is_open()) {

    while (getline(file, word)) {

      dictionary.push_back(word) ;
    }

    file.close() ;
        
  } 
  else {

    // failed to open file
    cerr << "Failed to open dictionary file!" << endl ;
  }

  return dictionary ;
}

// Function to find the closest match for a given word
pair<int,string> findClosestWord(string &input , vector<string> &dictionary) {
    
    int minDistance = 1e9 ;
    pair<int,string> closestWord ;

    for (const std::string &word : dictionary) {
    
        int distance = levenshteinDistance(input, word);

        if (distance < minDistance) {

            minDistance = distance ;
            closestWord.second = word ;
    }
  }

    closestWord.first = minDistance ;

  return closestWord ;
}

int main() {

  string inputWord ;

  cout << "Enter a word to check: " ;
  cin >> inputWord;

  // Load the dictionary
  vector<string> dictionary = loadDictionary("dictionary.txt") ;

   // Find the closest match
  pair<int,string> closestWord = findClosestWord(inputWord, dictionary) ;

    if (closestWord.first == 0) 
    {
        cout << "Word Found Succesfully\n" ;
    }
    else 
    {
        cout << "Word Not Found !\n" ;
        cout << "Did you mean : " << closestWord.second << " ?" << endl ;
    }

  return 0 ;
}
