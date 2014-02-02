#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <sstream>
using namespace std;

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    int* words = new int[100001];
    map<string, int> m;
    string input;
    int wordsnum, counter;

    cin >> t;

    for (int case_num = 0; case_num < t; case_num++) {
        m.clear();
        counter = 0; // # of unique words
        wordsnum = 0; // # of total words

        while (getline(cin, input)) {
            if (input == "END") {
                break;
            }

            // remove all the punctuations, digits, symbols (except lowercase letters) with space
            for (int i = 0, sz = input.size(); i < sz; i++) {
                if (input[i] < 'a' || input[i] > 'z') {
                    input[i] = ' ';
                }
            }
            // put the char array into stringstream to split into words (sequence of lowercase letters)
            stringstream ss(input, stringstream::in);
            // All same words are numbered with one integer, the integer is given according to the order if occurance of those words
            while (ss >> input) {
                if (m.find(input) == m.end()) { // the word is unique and appears first time
                    m[input] = counter;
                    words[wordsnum] = counter;
                    counter++;
                    wordsnum++;
                } else {
                    words[wordsnum] = m[input];
                    wordsnum++;
                }
            }
        }
        // for debugging purpose
#ifndef ONLINE_JUDGE
        for(int i = 0; i < wordsnum; i++)
            printf("%d ", words[i]);
        putchar('\n');
#endif
        int a = 0, b = 0; // lower and upper range p & q
        int haswords = 0; // if hasword becomes equal to total unique word, we are done!
        map<int, int> frequency;
        // store the lower and upper range (result)
        pair<int, int> result = make_pair(-1, -1); // initialize

        // the first word is definitely unique(appears first)
        frequency[words[0]] = 1;
        haswords++; // one unique word is found, so increament

        // incase of only one word, the range would be (0, 0) (actually (1,1), assuming index from 0)
        if (wordsnum == 1) {
            result = make_pair(0, 0);
        }

        while (true) {
            // we are end of the document and we're done! , so break this infinite loop
            if (a == wordsnum - 1 && b == wordsnum - 1) {
                break;
            }

            if (haswords == counter) { // all unique words have been found :D
                if (result.first == -1) {
                    result = make_pair(a, b); // put result into result :P
                } else {
                    if (b - a < result.second - result.first) {
                        result = make_pair(a, b); // we're seeking for such p & q which difference is minimum with lowest value of p, so update result
                    }
                }
                // if left most word has more than one frequency, that means there are one or more same word inside the range. so, we can deduct this and start our range from one step ahead
                if (frequency[words[a]] > 1) {
                    frequency[words[a]]--; // deducted, so frequency decreaments by one
                    a++; // lower range increaments
                } else {
                    frequency[words[a]] = 0; // pretending that - this word is not found yet and lower range increaments by 1
                    a++;
                    haswords--; // # of found unique words decreaments by 1
                }
            } else {
                // end of document, so break
                if (b == wordsnum - 1) {
                    break;
                }
                // if current word is unique/ is not in the frequency map
                if (frequency.find(words[b + 1]) == frequency.end() || frequency[words[b + 1]] == 0) {
                    frequency[words[b + 1]] = 1; // take it
                    b++; // upper range increaments by 1
                    haswords++; // one unique word found, so increament
                } else { // current word is not unique, but we are taking it as all unique words are not found yet!
                    frequency[words[b + 1]] += 1;
                    b++;
                }
            }
        }
        printf("Document %d: %d %d\n", case_num + 1, result.first + 1,  result.second + 1);
    }
    delete [] words;

    return 0;
}
