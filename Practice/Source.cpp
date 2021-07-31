//input output
#include <iostream>
//string functions
#include <string>
//include mapping data structure
#include <map>
//is digit, is char
#include<stdio.h>
#include<ctype.h>

//shortening
using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

string str = "supercalifragislisticipsyaladocious";
string puppo = "dog";
string notReal = "god";

string reverseString(string s)
{
	string r;

	for (int i = s.length()-1; i >= 0; i--)
	{
		r += s.at(i);
	}

	return r;
}

void isPalindrome(string orig, string rev)
{
	if (orig.compare(rev) != 0)
	{
		cout << rev <<  " is not a palindrome of " << orig;
		cout << NEWLINE;
	}
	else
	{
		cout << rev << " is a palindrome of " << orig;
		cout << NEWLINE;
	}
}

void matchingCharacters(string s)
{

	map<char, int> m;
    map<char, int>::iterator it = m.begin();

	cout << "Original string " << s << NEWLINE;
	
	for (int i = 0; i < int(s.length()); i++)
	{
		//if the character is not in the map
		if (m.find(s.at(i)) == m.end())
		{
			m.insert(pair<char,int>(s.at(i), 1));
		}
		else
		{
			m.at(s.at(i)) += 1;
		}
	}

	//print the map
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second != 1)
		{
			cout << it->first << " occurs " << it->second << " time(s)" << NEWLINE;
		}
		
	}

}

void nonMatchingCharacters(string s)
{

	map<char, int> m;
	map<char, int>::iterator it = m.begin();

	cout << "Original string " << s << NEWLINE;

	for (int i = 0; i < int(s.length()); i++)
	{
		//if the character is not in the map
		if (m.find(s.at(i)) == m.end())
		{
			m.insert(pair<char, int>(s.at(i), 1));
		}
		else
		{
			m.at(s.at(i)) += 1;
		}
	}

	//print the map
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second == 1)
		{
			cout << it->first << " occurs " << it->second << " time(s)" << NEWLINE;
		}

	}

}

void calcVowelsConsonants(string s)
{

	int vow = 0;
	int con = 0;
	char c;

	cout << "Original string " << s << NEWLINE;

	for (int i = 0; i < int(s.length()); i++)
	{
		c = s.at(i);

		//if the character is not a val
		if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
		{
			con += 1;
		}
		else
		{
			vow += 1;
		}
	}

	cout << "There are " << vow << " vowel(s) in the string" << NEWLINE;
	cout << "There are " << con << " consonant(s) in the string" << NEWLINE;

}

bool isAnagram(string s1, string s2)
{
	map<char, int> m1, m2;
	
	for (int i = 0; i < int(s1.length()); i++)
	{
		//if the character is not in the map
		if (m1.find(s1.at(i)) == m1.end())
		{
			m1.insert(pair<char, int>(s1.at(i), 1));
		}
		else
		{
			m1.at(s1.at(i)) += 1;
		}
	}

	for (int h = 0; h < int(s2.length()); h++)
	{
		//if the character is not in the map
		if (m2.find(s2.at(h)) == m2.end())
		{
			m2.insert(pair<char, int>(s2.at(h), 1));
		}
		else
		{
			m2.at(s2.at(h)) += 1;
		}
	}

	return m1.size() == m2.size() && equal(m1.begin(), m1.end(), m2.begin());
}

void charOccur(string s, char c)
{
	map<char, int> m1;

	for (int i = 0; i < int(s.length()); i++)
	{
		//if the character is not in the map
		if (m1.find(s.at(i)) == m1.end())
		{
			m1.insert(pair<char, int>(s.at(i), 1));
		}
		else
		{
			m1.at(s.at(i)) += 1;
		}
	}
	
	if (m1.find(c) != m1.end())
	{
		cout << "The character " << c << " was found " << m1.at(c) << " time(s)" << NEWLINE;
	}
	else
	{
		cout << "The character " << c << " was not found" << NEWLINE;
	}
}

void isRotation(string s1, string s2)
{
	if (s1.length() != s2.length())
	{
		cout << s1 << " and " << s2 << " are not rotations of each other" << NEWLINE;
	}
	else
	{
		string temp = s1 + s2;
		if (temp.find(s2))
		{
			cout << s1 << " and " << s2 << " are rotations of each other" << NEWLINE;
		}
		else
		{
			cout << s1 << " and " << s2 << " are not rotations of each other" << NEWLINE;
		}
	}
}

void numOfNumChars(string s1)
{
	int charNums = 0;

	for (int i = 0; i < s1.length(); i++)
	{
		if (isdigit(s1.at(i)))
		{
			charNums += 1;
		}
	}

	if (charNums == 0)
	{
		cout << s1 << " has no numerical characters" << NEWLINE;
	}
	else
	{
		cout << s1 << " has " << charNums << " numerical character(s)" << NEWLINE;
	}
}

void questionOne()
{
	cout << "How can you reverse a string?" << NEWLINE;
	string orig = "cat";
	cout << "Original string " << orig << NEWLINE;
	string rev = reverseString(orig);

	cout << "Reversed String " << rev << NEWLINE;
	cout << NEWLINE << NEWLINE << NEWLINE;
}

void questionTwo()
{
	cout << "What is a palindrome string?" << NEWLINE;
	string orig = "cat";
	cout << "Original String " << orig << NEWLINE;
	string rev = reverseString(orig);

	isPalindrome(orig, rev);

	orig = "tat";
	rev.clear();
	rev = reverseString(orig);

	cout << rev;
	cout << NEWLINE;

	isPalindrome(orig, rev);

	cout << NEWLINE << NEWLINE << NEWLINE;
}

void questionThree()
{
	cout << "How to get the matching characters in a string?" << NEWLINE;
	matchingCharacters(str);
	cout << NEWLINE << NEWLINE << NEWLINE;
}

void questionFour()
{
	cout << "How to get the non-matching characters in a string?" << NEWLINE;
	nonMatchingCharacters(str);
	cout << NEWLINE << NEWLINE << NEWLINE;
}

void questionFive()
{
	cout << "How to calculate the number of vowels and consonants in a string?" << NEWLINE;
	calcVowelsConsonants(str);
	cout << NEWLINE << NEWLINE << NEWLINE;
}

void questionSix()
{
	cout << "How do you prove that the two strings are anagrams?" << NEWLINE;
	bool isTrue = isAnagram(puppo, notReal);
	
	if (isTrue)
	{
		cout << puppo << " and " << notReal << " are anagrams" << NEWLINE;
	}
	else
	{
		cout << puppo << " and " << notReal << " are not anagrams" << NEWLINE;
	}

	isTrue = isAnagram(puppo, str);

	if (isTrue)
	{
		cout << puppo << " and " << str << " are anagrams" << NEWLINE;
	}
	else
	{
		cout << puppo << " and " << str << " are not anagrams" << NEWLINE;
	}

	cout << NEWLINE << NEWLINE << NEWLINE;
}

void questionSeven()
{
	cout << "Find the count for the occurrence of a particular character in a string." << NEWLINE;

	charOccur(str, 'c');
	charOccur(str, 'z');
	charOccur(str, 'a');
	charOccur(str, 'x');

	cout << NEWLINE << NEWLINE << NEWLINE;

}

void questionEight()
{
	cout << "How to verify if two strings are a rotation mutually ?" << NEWLINE;

	string s1 = "ABCD";
	string s2 = "CDAB";
	string s3 = "ZYXV";
	string s4 = "VC";

	isRotation(s1, s2);
	isRotation(s1, s3);
	isRotation(s1, s4);

	cout << NEWLINE << NEWLINE << NEWLINE;
}

void questionNine()
{
	cout << "How to calculate the number of numerical digits in a string?" << NEWLINE;

	string s1 = "abcd123";
	string s2 = "h3ll0w0r1d";
	string s3 = "hello";
	string s4 = "j311y";

	numOfNumChars(s1);
	numOfNumChars(s2);
	numOfNumChars(s3);
	numOfNumChars(s4);

	cout << NEWLINE << NEWLINE << NEWLINE;
}

void questionTen()
{

}

//main function
int main()
{
	cout << "Hello World \n" << NEWLINE << NEWLINE << NEWLINE;
	
	//Q1
	questionOne();

	//Q2
	questionTwo();

	//Q3
	questionThree();

	//Q4
	questionFour();

	//Q5
	questionFive();

	//Q6
	questionSix();

	//Q7
	questionSeven();

	//Q8
	questionEight();

	//Q9
	questionNine();

	return 0;

};

