
#include <openssl/md5.h>
#include <string.h>

#include "String.hh"


namespace oct::crypto
{

	//contructors
	String::String()
	{

	}
	String::String(const std::string& md5sum)
	{
		set(md5sum);
	}

	//operators
	const String& String::operator =(const String& m)
	{
		std::string::operator = (m);
		return *this;
	}	
	const String& String::operator =(const char* m)
	{
		set(m);
		return *this;
	}	
	const String& String::operator =(const std::string& m)
	{
		set(m);
		return *this;
	}

	//funtions
	void String::set(const std::string& s)
	{
		unsigned char digest[MD5_DIGEST_LENGTH];
    	char string[s.length()+1];
		strcpy(string,s.c_str());
    	MD5((unsigned char*)&string, strlen(string), (unsigned char*)&digest); 
    	char mdString[33]; 
    	for(int i = 0; i < 16; i++)
		{
			sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
		}
		
		std::string::operator = (mdString);
	}
	
	
	
}
