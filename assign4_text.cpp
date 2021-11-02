/*****************************************************
   ** Program: assign4_text.cpp
   ** Author: Robert Houeland
   ** Date: 2/23/2020
   ** Description: Performs operations on a string of the user's choice.
   ** Input: User inputs any string, paragraph or sentence of 1027 characters or left.
   ** Output: User chooses which operation to perform, and the result is shown.
   *****************************************************/

#include <iostream>
#include <cstring> /* C style strings */

using namespace std;

/*******************************************************************
   ** Function: check_vowel_cons
   ** Description: Checks if the amount of vowels equals the number of 
      consonants. Ignores non letters.
   ** Parameters: Takes in a constant pointer to a C style string.
   ** Pre-Conditions: Needs valid C style string.
   ** Post-Conditions: Returns true or false.
   *******************************************************************/
bool check_vowel_cons(const char *s)
{
   int vowels = 0;
   int consonants = 0;
   for (short i = 0; i < strlen(s); i++)
   {
      if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ||
          s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
         vowels += 1;
      /*checks if each index is a vowel, or consonant*/
      else if ((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123))
         consonants += 1;
   }
   if (vowels == consonants)
      return true;
   else
      return false;
}


/*******************************************************************
   ** Function: letter_swap
   ** Description: Takes in a letter, and replaces all instances of that letter
      with another letter taken in. Keeps capitalization.
   ** Parameters: C style string, and two letters.
   ** Pre-Conditions: Needs valid C style string.
   ** Post-Conditions: Modifies string to replace letters.
   *******************************************************************/
void letter_swap(char *s, const char a, const char b)
{
   for (short i = 0; i < strlen(s); i++)
   {
      if (s[i] == a)
         s[i] = b;
      if (s[i] == (a - 32))
         s[i] = (b - 32);
      if (s[i] == (a + 32))
         s[i] = (b + 32);
   }
}


/*******************************************************************
   ** Function: flip_str
   ** Description: Flips and reverses a string.
   ** Parameters: Takes in a constant C string and a C string.
   ** Pre-Conditions: Needs 2 valid C style strings.
   ** Post-Conditions: Outputs string reversed.
   *******************************************************************/
void flip_str(const char *s, char *s2)
{
   s2 = new char[strlen(s) + 1];
   for (short i = 0; i < strlen(s); i++)
      s2[i] = s[i];
   for (short i = 0; i < int(strlen(s2) / 2); i++)
      swap(s2[i], s2[strlen(s2) - i - 1]);
   cout << s2 << endl;
	delete [] s2;
}


/*******************************************************************
   ** Function: check_chars
   ** Description: Counts amount of uppercase and lowercase letters.
   ** Parameters: Takes in pointer to constant C style string.
   ** Pre-Conditions: Needs valid C style string.
   ** Post-Conditions: Outputs count of uppercase letters and lowercase.
   *******************************************************************/
void check_chars(const char *s)
{
   int upperCase = 0;
   for (short i = 0; i < strlen(s); i++)
   {
      if ((s[i] > 64) && (s[i] < 91))
         upperCase += 1;
   }
   int lowerCase = 0;
   for (short i = 0; i < strlen(s); i++)
   {
      if ((s[i] > 96) && (s[i] < 123))
         lowerCase += 1;
   }
   cout << "There are " << upperCase << " upper case letters." << endl;
   cout << "There are " << lowerCase << " lower case letters." << endl;
}


int main()
{
   char originalString[1028] = {};
   cout << "Welcome to Text Surgeon!" << endl;
   cout << "Please enter a string of text (max length 1027 characters): ";
   cin.getline(originalString, 1028);
   cout << endl;

   short restart;
   do
   {
      cout << "What operation would you like to perform on your string?";
      cout << endl;

      short choice;
      cout << "1. Check if the number of vowels equals the number of "; 
      cout << "consonants" << endl;
      cout << "2. Letter swap" << endl;
      cout << "3. Reverse" << endl;
      cout << "4. Capitalization character count" << endl;
      cout << "0. Quit" << endl;
      cin >> choice;
      cout << endl;

      if (choice == 1)
      {
         if (check_vowel_cons(originalString) == true)
            cout << "# of vowels = # of consonants." << endl;
         else
            cout << "# of vowels != # of consonants." << endl;
      }

      if (choice == 2)
      {
         char letter1;
         do 
         {
         cout << "Enter a letter from the original string to be replaced: ";
         cin >> letter1;
         if (letter1 < 65 || letter1 > 122 || (letter1 > 90 && letter1 < 97))
            cout << "Invalid input. Please retry." << endl;
         } while (letter1 < 65 || letter1 > 122 || (letter1 > 90 && letter1 < 97));

         char letter2;
         do
         {
         cout << "Enter a letter that will be replacing " << letter1 << " : ";
         cin >> letter2;
         if (letter2 < 65 || letter2 > 122 || (letter2 > 90 && letter2 < 97))
            cout << "Invalid input. Please retry." << endl;
         } while (letter2 < 65 || letter2 > 122 || (letter2 > 90 && letter2 < 97));

         letter_swap(originalString, letter1, letter2);
         cout << "Your new string is: " << originalString << endl;
      }

      if (choice == 3)
		{
			char flippedString[1028] = {};
			cout << "Your string backwards is: " << endl;
			flip_str(originalString, flippedString);
		}

		if (choice == 4)
			check_chars(originalString);

		if (choice == 0)
			break;

		if (choice < 0 || choice > 4)
			cout << "Invalid choice." << endl;

		cout << endl;
		cout << "Do you want to perform another operation? (0 = no, 1 = yes) ";
		cin >> restart;

	} while (restart != 0);

	return 0;
}
