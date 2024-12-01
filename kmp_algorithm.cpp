/*
 *	This is an implementation of KMP algorithm
 *	@author: shaikhalvee
 *	implemented with the help of geeksforgeeks
*/

#include <bits/stdc++.h>
#define FOR(i, start, end) for(size_t i = (start); i < (end); ++i)
#define pi (2*acos(0.0))
#define MAX 1e7+9

using namespace std;

void longestPrefixSuffix(string, unsigned[]);
void kmp_implement(string, string);

int main()
{
	string pattern, text;
	while (cout << "Enter text:" && getline(cin>>ws, text) && cout << "Enter pattern:" && getline(cin>>ws, pattern)) {
		kmp_implement(text, pattern);
	}

    return 0;
}

void longestPrefixSuffix(string pattern, unsigned lps[])
{
	int pattern_len = pattern.length();

	lps[0] = 0;	// lps[0] is always 0

	// loop calculates lps for i=1 to pattern_len - 1
	// longest_prefix_suffix is the longest prefix suffix inside the pattern
	int i = 1, longest_prefix_suffix = 0;
	while (i < pattern_len) {
		if (pattern[i] == pattern[longest_prefix_suffix]){
			lps[i++] = ++longest_prefix_suffix;
		}
		else {	// patter[i] != pattern[longest_prefix_suffix]
			// This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (longest_prefix_suffix)	longest_prefix_suffix = lps[longest_prefix_suffix - 1];
            else lps[i++] = 0;
		}
	}
}

void kmp_implement(string text, string pattern)
{
	int patternLength = pattern.length();
	int textLength = text.length();
	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	unsigned lps[patternLength];

	// preprocess the longest prefix suffix array
	longestPrefixSuffix(pattern, lps);
	int text_index = 0;	// index for text
	int pattern_index = 0;	// index for pattern
	while (text_index < textLength) {
		if (pattern[pattern_index] == text[text_index]) {
			pattern_index++;
			text_index++;
		}
		if (pattern_index == patternLength) {
			cout << "Found pattern at index " << text_index - pattern_index << "\n";
			pattern_index = lps[pattern_index - 1];
		}
		// mismatch after j matches
		else if (text_index < textLength && pattern[pattern_index] != text[text_index]) {
			// Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (pattern_index != 0) pattern_index = lps[pattern_index - 1];
            else text_index++;
		}
	}
}
