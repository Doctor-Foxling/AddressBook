#pragma once

#include "Abstract/AddressBook.h"
#include "EntryImpl.h"

namespace Foundry {

	class AddressBookImpl : public AddressBook
	{
	public:
		//void setEntries(const std::vector<Entry>& entries) override;
		Shared<Entry> addEntry(Shared<Entry>& entry) override;
		void removeEntry(Shared<Entry>& entry) override;
		Shared<std::vector<Shared<Entry>>> getEntriesByFName() override;
		void printEntriesByFName() override;
		Shared<std::vector<Shared<Entry>>> getEntriesByLName() override;
		void printEntriesByLName() override;

		Shared<std::vector<Shared<Entry>>> searchEntryByFName(const char* fName) override;
		Shared<std::vector<Shared<Entry>>> searchEntryByLName(const char* lName) override;
 
	private:
		std::map<char, Shared<std::vector<Shared<Entry>>>> m_fNameRef;
		std::map<char, Shared<std::vector<Shared<Entry>>>> m_lNameRef;
		//std::unordered_map<char, std::set<int>> mEntryIndices; 
		//std::vector<Shared<Entry>> mEntries;
	};

}
