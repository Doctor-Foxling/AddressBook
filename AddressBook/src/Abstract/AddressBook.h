#pragma once

#include "base.h"
#include "Entry.h"

namespace Foundry {

	class AddressBook {
	public:
		virtual ~AddressBook() = default;

		//virtual void setEntries(const std::vector<Entry>& entries);
		virtual Shared<Entry> addEntry(Shared<Entry>& entry) = 0;
		virtual void removeEntry(Shared<Entry>& entry) = 0;
		virtual Shared<std::vector<Shared<Entry>>> getEntriesByFName() = 0;
		virtual void printEntriesByFName() = 0;
		virtual Shared<std::vector<Shared<Entry>>> getEntriesByLName() = 0;
		virtual void printEntriesByLName() = 0;
		virtual Shared<std::vector<Shared<Entry>>> searchEntryByFName(const char* fName) = 0;
		virtual Shared<std::vector<Shared<Entry>>> searchEntryByLName(const char* lName) = 0;
 	};

}