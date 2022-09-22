#pragma once

class Entry {
public:
	virtual ~Entry() = default;

	virtual void setFirstName(const char* fName) = 0;
	virtual void setLastName(const char* lName) = 0;
	virtual const char* getFirstName() = 0;
	virtual const char* getLastName() = 0;
	virtual int getID() = 0;
	virtual bool hasPhoneNumber() = 0;
	virtual const char* getPhoneNumber() = 0;
	virtual void addPhoneNumber(const char* ph) = 0;
};
