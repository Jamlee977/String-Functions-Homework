#include <iostream>

// Omar Estietie

using namespace std;


/**
 * @brief This function is used to get the length of an Array of Characters.
 * 
 * @param __LEN_OF_ARRAY_OF_CHARACTERS__ is an array of characters that needs to be put in the function.
 * @return int
 */
int length(char __LEN_OF_ARRAY_OF_CHARACTERS__[]) {
    int i, countOfChar = 0;
    for (int i = 0; __LEN_OF_ARRAY_OF_CHARACTERS__[i]; i++)
    {
        countOfChar++;
    }
    return countOfChar;
}

/**
 * @brief A function that takes a subset of a string and puts it in another string.
 * 
 * @param __TOCOPYIN An array to copy the substring in.
 * @param __TOBECOPIED An array to copy the substring from.
 * @param __START The starting point of copying the substring.
 * @param __END The final point of copying the substring.
 * @return int 
 */
int substring(char __TOCOPYIN[], char __TOBECOPIED[], int __START, int __END) {
    int len = length(__TOBECOPIED);
    if (__END > len) return 0;
    
    if (__START > len) return 0;


    int half = length(__TOBECOPIED) / 2;
    int i, j;
    int size;

    if (__END > __START) size = __END - __START;
   

    else size = __START - __END;
    

    if ((__START > (half + 1)) && (__END > (__START - half))) return 0;
    
    
    for (i = 0, j = __START; i < __END && __TOBECOPIED[j] != '\0'; i++, j++) __TOCOPYIN[i] = __TOBECOPIED[j];


    if (!(__END == 1)) __TOCOPYIN[size] = '\0'; 
    

    else __TOCOPYIN[1] = '\0';
    
    return 1;
}

/**
 * @brief A function that can be used to append a string to another string.
 * 
 * @param __APPENDTOARRAY A string that is going to get another string at the end of it. 
 * @param __APPENDEDARRAY A string that is going to be appended.
 * @return int 
 */
int append(char __APPENDTOARRAY[], char __APPENDEDARRAY[])
{
	int i, j, k, countOfFirst = 0, countOfSecond = 0;
	int appendToLength = length(__APPENDTOARRAY);	
	int appendedLength = length(__APPENDEDARRAY);
    
    for (int k = 0; __APPENDTOARRAY[k]; k++) { countOfFirst++; };
    for (int k = 0; __APPENDEDARRAY[k]; k++) { countOfSecond++; };

    int countOfArrays = countOfFirst + countOfSecond;

    if (countOfArrays > 100) return 0;

	for (i = appendToLength, j = 0; j <= appendedLength; i++, j++) {
		__APPENDTOARRAY[i] = __APPENDEDARRAY[j];
	}
	return 1;
}

/**
 * @brief A function to copy two strings.
 * 
 * @param __TOCOPYIN The array to be copied in
 * @param __TOBECOPIED The array to be copied from
 */
void copy(char __TOCOPYIN[], char __TOBECOPIED[]) {
    int i, size;
    size = length(__TOBECOPIED);
    for (i = 0; i <= size; i++)
    {
        __TOCOPYIN[i] = __TOBECOPIED[i];
    }
    __TOCOPYIN[i] = '\0';    
}

/**
 * @brief A function that is used to get replace a specific index of the string with a specific character.
 * 
 * @param __ARRAYOFCHAR A string that is needed to replace a character in.
 * @param __INDEX The index of the character that is wanted to be changed.
 * @param __INSERTEDCHAR The character that is wanted to be inserted.
 * @return int 
 */
int at(char __ARRAYOFCHAR[], int __INDEX, char __INSERTEDCHAR) {
    int len = length(__ARRAYOFCHAR);
    if (len < 4) return 0;

    int i;

    for (i = 0; i <= len; i++) {
        if (i == __INDEX) __ARRAYOFCHAR[i] = __INSERTEDCHAR;
    }

    return 1;
}

/**
 * @brief A function used to find an index of a desired character in a string.
 * 
 * @param __INVESTIGATED_ARRAY The string that we want to find a character in. 
 * @param __DESIRED_CHARACTER The character that we want to find its index inside of the string.
 * @return int 
 */
int find(char __INVESTIGATED_ARRAY[], char __DESIRED_CHARACTER) {
    int i;
    int len = length(__INVESTIGATED_ARRAY);
    for (i = 0; __INVESTIGATED_ARRAY[i]; i++) {
        if (__INVESTIGATED_ARRAY[i] == __DESIRED_CHARACTER) return i;
    }
    return -1;
}


int main()
{
    char first[100], second[100], third[100];
    int len, end, ok, ok1, ok2, ok3;
    char ch;
    cout << "Enter a string: ";
    gets_s(first);
    len = length(first);
    end = len / 2;

    substring(second, first, 0, end);
    ok = substring(second, first, 0, end);
    cout << "The second string is: " << second << endl;
    cout << ok << endl; // to get the return-value whether it's 1 or 0.

    ok1 = substring(third, first, end, len);
    cout << "The third string is: " << third;
    cout << endl << ok1 << endl; // to get the return-value whether it's 1 or 0.

    append(third, second);

    cout << endl << "The third array after being appended: " << third;

    copy(first, third);

    cout << "\n\nNew version of the string: " << first << endl << endl;

    cout << "Enter the desired inserted character: ";
    cin >> ch;
    ok2 = at(first, 3, ch);

    if (!ok2) cout << "The new string has less than 4 char\n";
    
    else cout << "The very new string is: " << first << endl << endl;
    

    cout << endl << endl << "Enter the character that you wanna find: ";
    cin >> ch; 
    ok3 = find(first, ch);
    if (ok3 == -1) cout << "There is no " << ch << " in the new string.";
    
    else cout << "The first place " << ch << " was found is in " << ok3;

}
