#pragma once

#include <Abstract/Entry.h>

namespace Foundry {

	class EntryImpl : public Entry
	{
	public:
		EntryImpl() {};
		EntryImpl(const char* fName, const char* lName): mFName(fName) ,mLName(lName)
		{};
		EntryImpl(const char* fName, const char* lName, const char* phNum)
			: mFName(fName), mLName(lName), mPhoneNumber(phNum) {};
		
		virtual ~EntryImpl() {};

		virtual void setFirstName(const char* fName) override { mFName = fName; }
		virtual void setLastName(const char* lName) override { mLName = lName; }

		virtual const char* getFirstName() override { return mFName; }
		virtual const char* getLastName() override { return mLName; }

		virtual int getID() override { return ID; }

		static Shared<Entry> Create();
		static Shared<Entry> Create(const char* fName, const char* lName);
		static Shared<Entry> Create(const char* fName, const char* lName, const char* phoneNumber);

		virtual bool hasPhoneNumber() { return mPhoneNumber != '\0'; }

		virtual const char* getPhoneNumber() override { return mPhoneNumber; }

		virtual void addPhoneNumber(const char* ph) override { mPhoneNumber = ph; }

		bool operator==(Shared<Entry> other)
		{
			// Should have implemented an ID system but names will have to do for now
			return (mFName == other->getFirstName() 
				&& mLName == other->getLastName() && ID == other->getID());
		}


 
	private:
		const char* mFName;
		const char* mLName;
		const char* mPhoneNumber = '\0';
		int ID;
	};

}
