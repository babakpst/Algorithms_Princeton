
#include "TwoSum.h"

// constructor
TwoSum::TwoSum(int sizeOfStream, long long target, std::string inputFileName)
    : sizeOfStream{sizeOfStream}, target{target}, inputFileName{inputFileName} {
  std::cout << " Initiating the 2-Sum class ... \n";
  std::cout << " size of stream: " << sizeOfStream << ", target: " << target
            << "\n";
  // numbers.reserve(sizeOfStream);
}

// ======
void TwoSum::readData() {
  std::cout << " reading numbers from the file ... \n";
  std::ifstream inputFile(inputFileName);
  long long temp;
  for (int i = 0; i < sizeOfStream; ++i) {
    inputFile >> temp;
    numbers.push_back(temp);
    // std::cout << " reading: " << i << " " << numbers[i] << "\n";
  }
  std::cout << "Done reading the data\n";
}

// ===
void TwoSum::brute_force_2_sum() {

  std::cout << " Evaluating 2-sum using brute force method: \n";
  int counter = 0;
  int NumOfPairs = 0;
  for (std::vector<long long>::iterator it1 = numbers.begin();
       it1 != numbers.end(); ++it1) {
    counter++;
    if (counter % 10000 == 0)
      std::cout << " item: " << counter++ << " - " << NumOfPairs << "\n";
    for (std::vector<long long>::iterator it2 = it1 + 1; it2 != numbers.end();
         ++it2) {
      if ((*it1 + *it2) == target) {
        NumOfPairs++;
        std::cout << std::distance(numbers.begin(), it1) << ":" << *it1 << "--"
                  << std::distance(numbers.begin(), it2) << ":" << *it2 << "\n";
      }
    }
  }
  std::cout << " Total number of pairs: " << NumOfPairs << "\n";
  std::cout << " End of brute-force search \n";
}

// ===
void TwoSum::hash_table_2_sum() {
  std::cout << " Evaluating 2-sum using hash table ... \n";
}

void TwoSum::list_2_sum() {

  std::cout << " Evaluating 2-sum using unordered set ... \n";
  int NumOfPairs = 0;
  std::unordered_set<long long> set;
  for (int i = 0; i < sizeOfStream; i++) {
    long long temp = target - numbers[i];
    // std::cout << temp << "\n";
    if (set.find(temp) != set.end()) {
      NumOfPairs++;
      std::cout << "Pair with given target " << target << " is (" << numbers[i]
                << ", " << temp << ")\n";
    }
    set.insert(numbers[i]);
  }
  std::cout << " Total number of pairs: " << NumOfPairs << "\n";
  std::cout << " End of the unsorted set \n";
}
