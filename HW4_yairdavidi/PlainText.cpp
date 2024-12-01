#include "PlainText.h"

int PlainText::numOfTexts = 0; // Counter for the times a "PlainText" class (or its inheritor)

/*
* The instructor. initialize the fields _text and _isEnccrypted to: the given text, and 0;
* after that, the function add one to the class counter, which counts the amount of created objects.
* 
* Input: std::string text - the text to be in the class.
* Output: NONE
* Returned: NONE
*/
PlainText::PlainText(std::string text) : _text(text), _isEncrypted(0)
{
	numOfTexts++;
}

// I understood that if I didn't allocate anything, I don't need the destructor.


bool PlainText::isEncrypted() const
{
	/*
	* The function checks if the text is encrypted or not using the _isEncrypted field.
	* if encrypted, the function will return 1 (as the field equals to 1).
	* if the opposite, will return 0.
	* 
	* Input: NONE
	* Output: NONE
	* Returned: "_isEncrypted" field.
	*/
	return this->_isEncrypted;
}

std::string PlainText::getText() const
{
	/*
	* The function gets the text from the protected section.
	* 
	* Input: NONE
	* Output: NONE
	* Returned: _text.
	*/
	return this->_text;
}

std::ostream& operator<<(std::ostream& os, const PlainText& obj)
{
	/*
	* An operator to print the text in any PlainText object(or inheritor)
	* 
	* Input: std::ostream& os - the stream to use, in our case - "cout".
			 const PlainText& obj - the object to get the text from.

	* Output: NONE
	* Returned: reference to the std::ostream object. to be printed!!
	*/
	os << obj.getText();
	return os;
}
