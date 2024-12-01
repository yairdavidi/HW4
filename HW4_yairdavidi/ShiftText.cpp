#include "ShiftText.h"

/*
This is the class instructor.
It's encrypting the text according to the key, and enters the values in the correct fields.

Input: text - the text to encrypt, then puts in the _text field. key - what key it's encrypted with.
Output: NONE

Returned: A "ShifText" object (woohooo! :) )
*/
ShiftText::ShiftText(std::string text, int key) : PlainText(encrypt(text, key)), _key(key)
{
    this->_isEncrypted = 1;
}

std::string ShiftText::encrypt(std::string text, int key)
{
    /*
    * the function encrypts the text using the shift method, shifts-times = key.
    * 
    * Input: text - the text to encrypt,key - the times to shift the letters for encrypt.
    * Output: NONE
    * Returned: result = std::string encrypted string
    */
    std::string result = "";

    // Traverse text
    for (int i = 0; i < text.length(); i++)
    {
        // Encrypt letters
        if (isalpha(text[i]))
        {
            result += char(int(text[i] + key - 97) % 26 + 97);
        }
        // keep anything that not a letter
        else
        {
            result += text[i];
        }
    }

    // Return the resulting string
    return result;
}

std::string ShiftText::decrypt(std::string text, int key)
{
    /*
    * Decrypts the text by changing the key and send it to encrypt() method.(I'm shocked it's really works, how cool is to think!) 
    * 
    * Input: std::string text - string to decrypt, int key - key of encryption (in what key did they encrypt the text).
    * Output: NONE
    * Returned: decrypted string.
    */
    return encrypt(text, 26-key);
}

std::string ShiftText::encrypt()
{
    /*
    * Checks if the text isn't encrypted yet. if not encrypted, will encrypt, sign it to be encrypted (using the _isEncrypted field)
    *  and encrypts it. 
    * if not encrypted, returns the string as it is.
    * 
    * Input: NONE
    * Output: NONE
    * Return: encrypted text.
    */
    if (this->_isEncrypted == 0)
    {
        this->_text = encrypt(this->_text, this->_key);
        this->_isEncrypted = 1;
    }

    return this->_text;
}

std::string ShiftText::decrypt()
{
    /*
    * Checks if the text isn't decrypted yet. if not decrypted, will decrypt, sign it to be decrypted (using the _isEncrypted field)
    *  and decrypts it.
    * if not decrypted, returns the string as it is.
    *
    * Input: NONE
    * Output: NONE
    * Return: decrypted text.
    */

    if (this->_isEncrypted == 1)
    {
        this->_text = decrypt(this->_text, this->_key);
        this->_isEncrypted = 0;
    }
    return this->_text;
}