#include "SubstitutionText.h"
#include <fstream>

/*
* Constructor for SubstitutionText.
* Initializes a SubstitutionText object by setting the plaintext and dictionary file name.
* Encrypts the text using the provided dictionary file.
*
* Input: text - The plaintext string to be encrypted, dictionaryFileName - the name of the dictionary file containing substitution mappings.
*
* Output: Initializes the _text member with the encrypted text, sets the _isEncrypted flag to true.
* Return: None.
*/
SubstitutionText::SubstitutionText(std::string text, std::string dictionaryFileName)
    : PlainText(text), _dictionaryFileName(dictionaryFileName)
{
    this->_text = encrypt(this->_text, this->_dictionaryFileName);
    this->_isEncrypted = 1;
}

/*
* Encrypts the given text using a substitution cipher based on a dictionary file.
* Reads the substitution mappings from the specified dictionary file and applies them
* to the input text. Each letter in the alphabet is replaced with its corresponding
* cipher letter as defined in the dictionary.
*
* Input: text: The plaintext string to be encrypted, dictionaryFileName: The name of the dictionary file containing substitution mappings.
* Output: None.
* Return: std::string: The encrypted ciphertext. Returns an empty string if the dictionary file cannot be opened.
*/
std::string SubstitutionText::encrypt(std::string text, std::string dictionaryFileName)
{
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                         'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                         'x', 'y', 'z' };
    char cipherAlphabet[26] = {};

    std::ifstream file(dictionaryFileName);

    if (!file.is_open())
    {
        std::cerr << "couldn't open file" << std::endl;
        return "";
    }

    std::string line;
    for (int i = 0; i < 26; i++)
    {
        std::getline(file, line);

        if (line.length() == 3 && line[1] == ',')
        {
            cipherAlphabet[i] = line[2];
        }
    }
    file.close();

    int alphabetSize = sizeof(alphabet) / sizeof(alphabet[0]);
    int index = -1;

    std::string encryptedText;

    for (char c : text)
    {
        index = -1;
        for (int i = 0; i < alphabetSize; i++)
        {
            if (alphabet[i] == c)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            encryptedText += cipherAlphabet[index];
        }
        else
        {
            encryptedText += c;
        }
    }

    return encryptedText;
}

/*
* Decrypts the given text using a substitution cipher based on a dictionary file.
*
* Reads the substitution mappings from the specified dictionary file and reverses them
* to convert the ciphertext back to plaintext. Each cipher letter is replaced with its
* corresponding original letter as defined in the dictionary.
*
* Input:
*   - text: The ciphertext string to be decrypted.
*   - dictionaryFileName: The name of the dictionary file containing substitution mappings.
*
* Output:
*   - None.
*
* Return:
*   - std::string: The decrypted plaintext. Returns an empty string if the dictionary file
*                  cannot be opened.
*/
std::string SubstitutionText::decrypt(std::string text, std::string dictionaryFileName)
{
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                          'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                          'w', 'x', 'y', 'z' };
    char cipherAlphabet[26] = {};

    std::ifstream file(dictionaryFileName);

    if (!file.is_open())
    {
        std::cerr << "couldn't open file" << std::endl;
        return "";
    }

    std::string line;
    for (int i = 0; i < 26; i++)
    {
        std::getline(file, line);

        if (line.length() == 3 && line[1] == ',')
        {
            cipherAlphabet[i] = line[2];
        }
    }
    file.close();

    std::string decryptedText;

    for (char c : text)
    {
        int index = -1;

        for (int i = 0; i < 26; i++)
        {
            if (cipherAlphabet[i] == c)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            decryptedText += alphabet[index];
        }
        else
        {
            decryptedText += c;
        }
    }

    return decryptedText;
}

/*
* Encrypts the object's text using the substitution cipher.
*
* Checks if the text is not already encrypted. If not, it encrypts the text using the
* substitution cipher based on the dictionary file and updates the encryption status.
*
* Input:
*   - None.
*
* Output:
*   - Updates the _text member with the encrypted text.
*   - Sets the _isEncrypted flag to true.
*
* Return:
*   - std::string: The encrypted text.
*/
std::string SubstitutionText::encrypt()
{
    if (!this->_isEncrypted)
    {
        this->_text = this->encrypt(this->_text, this->_dictionaryFileName);
        this->_isEncrypted = 1;
    }

    return this->_text;
}

/*
* Decrypts the object's text using the substitution cipher.
*
* Checks if the text is currently encrypted. If it is, it decrypts the text using the
* substitution cipher based on the dictionary file and updates the encryption status.
*
* Input:
*   - None.
*
* Output:
*   - Updates the _text member with the decrypted text.
*   - Sets the _isEncrypted flag to false.
*
* Return:
*   - std::string: The decrypted text.
*/
std::string SubstitutionText::decrypt()
{
    if (this->_isEncrypted)
    {
        this->_text = this->decrypt(this->_text, this->_dictionaryFileName);
        this->_isEncrypted = 0;
    }

    return this->_text;
}
