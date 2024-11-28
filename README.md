# 🧙‍♂️ Spell Checker

This **Spell Checker** is a fast and efficient tool designed to check and correct spelling mistakes in words. Built using **C++**, it employs advanced algorithms and data structures to ensure high performance and accuracy in identifying and suggesting word corrections.

## ⚡ Key Features:
<ul>
  <li><strong>Efficient Searching:</strong> The spell checker uses a <strong>Trie</strong> data structure for rapid searching of words. The Trie allows quick lookup by storing words in a tree-like structure where common prefixes are shared, making the search process faster, even for large dictionaries.</li>
  <li><strong>Levenshtein Distance:</strong> The algorithm used to measure how closely a given word matches the words in the dictionary. It calculates the minimum number of edits (insertions, deletions, or substitutions) required to convert one word into another, which allows the program to find the closest matches.</li>
  <li><strong>Suggestions:</strong> If a match is not found, the program will suggest the most similar words from the dictionary based on their Levenshtein distance to the input word. This helps users quickly correct their misspellings.</li>
</ul>

## 🔍 How It Works

### 🧠 Levenshtein Distance:
The **Levenshtein Distance** is a powerful algorithm used for spelling correction. It calculates the minimum number of single-character edits needed to convert one string into another. The three allowable operations are:
<ul>
  <li><strong>Insertion:</strong> Adding a character into the word.</li>
  <li><strong>Deletion:</strong> Removing a character from the word.</li>
  <li><strong>Substitution:</strong> Replacing one character with another in the word.</li>
</ul>

This metric is crucial for determining how similar two words are. The spell checker uses this distance to identify the closest word matches and suggest alternatives for potentially misspelled words.

For example:
- Transforming "kitten" to "sitting" involves:
  1. Substituting "k" for "s"
  2. Inserting "i"
  3. Substituting "e" for "i"
  4. Substituting "n" for "t"
  5. Inserting "g"

The Levenshtein Distance for this transformation is 3 (because three edits are required).

### 🌳 Trie Data Structure:
A **Trie** is a tree-like data structure specifically designed to store strings in an efficient way. Each node in the Trie represents a character of a word, and the tree structure allows for shared prefixes among words. This leads to reduced memory usage and faster lookups.

The **Trie** data structure enables:
- **O(L)** search time where **L** is the length of the word being searched.
- **Efficient Matching:** By following the tree structure from the root to the leaf nodes, the program can find the desired word quickly by checking each character in the word.
- **Space Optimization:** Words with common prefixes share the same path, so memory consumption is minimized.

Using a Trie for storing and searching words makes the spell checker particularly effective when dealing with large datasets, such as a comprehensive dictionary.

## 📚 What I Learned:
This project has been an excellent opportunity to deepen my knowledge of string algorithms, data structures, and C++. Here are the key takeaways:
<ul>
  <li>By implementing the <strong>Levenshtein Distance</strong> algorithm, I gained a better understanding of dynamic programming and string comparison techniques. This knowledge is also applicable in other domains like natural language processing (NLP).</li>
  <li>Working with a <strong>Trie</strong> helped me realize how powerful tree-based data structures can be for storing and searching data efficiently. I learned the importance of space optimization in large datasets.</li>
  <li>This project improved my C++ skills, especially in terms of memory management, algorithm design, and optimizing for performance.</li>
</ul>

## 🛠️ Installation Instructions

To get started with the Spell Checker, follow these steps:

<pre>
<code>
1. <strong>Clone the repository:</strong>
   git clone https://github.com/SiddhantDeshwal1/Spell-Checker

2. <strong>Navigate to the project directory:</strong>
   cd Spell-Checker

3. <strong>Compile the code using g++:</strong>
   g++ main.cpp Trie.cpp LevenshteinDistance.cpp SpellChecker.cpp -o spellchecker

4. <strong>Run the program:</strong>
   ./spellchecker
</code>
</pre>

Simply follow these steps, and the program will be up and running on your local machine.

## ✨ Conclusion

This project has been a great learning experience. By combining the **Levenshtein Distance** algorithm and the **Trie** data structure, I was able to create a highly efficient and fast spell checker. The project not only improved my understanding of algorithms and data structures but also allowed me to practice and refine my C++ programming skills.

I hope this project can help others who are looking to implement their own spell checking systems, and I encourage you to explore and expand on it further!

---

Let me know if you need any further changes! 😄
