#include "CaesarText.h"

/*
* Constructor for CaesarText.
* Initializes a CaesarText object by calling the ShiftText constructor with a fixed key of 3.
* create the text automatically encrypted by encrypting on the initial list

* Input: text - The plaintext string to be encrypted.
* Output: None.
* Return: None.
*/
CaesarText::CaesarText(std::string text) : ShiftText(text, 3)
{
}

// I understood that if I didn't allocated anything, I don't need the destructor.


std::string CaesarText::encrypt(std::string text)
{
	/*
	* Encrypts the given text using Caesar cipher with a fixed key of 3.
	* Encrypts each alphabetical character in the input text by shifting it 3 positions forward.
	* Non-alphabetical characters remain unchanged.
	*
	* Input: - text: The plaintext string to be encrypted.
	* Output: - None.
	* Return: - std::string: The encrypted ciphertext.
	*/

	return ShiftText::encrypt(text, 3);
}

std::string CaesarText::decrypt(std::string text)
{
	/*
	* Decrypts the given text using Caesar cipher with a fixed key of 3.
	* Decrypts each alphabetical character in the input text by shifting it 3 positions backward.
	* Non-alphabetical characters remain unchanged.
	* 
	* Input: - text: The ciphertext string to be decrypted.
	* Output: - None.
	* Return: - std::string: The decrypted plaintext.
	*/
	return ShiftText::decrypt(text, 3);
}

std::string CaesarText::encrypt()
{
	/*
	* Encrypts the object's text if it is not already encrypted.
	* Checks the encryption status of the current text. If the text is not encrypted, it encrypts
	* the text using the Caesar cipher with a fixed key of 3 and updates the encryption status.
	*
	* Input: - None.
	* Output: - None.
	* Return: - std::string: The encrypted text.
	*/

	if (!this->_isEncrypted)
	{
		this->_text = CaesarText::encrypt(this->_text);
		this->_isEncrypted = 1;
	}

	return this->_text;
}

std::string CaesarText::decrypt()
{
	/*
	* Decrypts the object's text if it is currently encrypted.
	* Checks the encryption status of the current text. If the text is encrypted, it decrypts
	* the text using the Caesar cipher with a fixed key of 3 and updates the encryption status.
	*
	* Input: - None.
	* Output: - None.
	* Return: - std::string: The decrypted text.
	*/

	if (this->_isEncrypted)
	{
		this->_text = CaesarText::decrypt(this->_text);
		this->_isEncrypted = 0;
	}
	return this->_text;
}
