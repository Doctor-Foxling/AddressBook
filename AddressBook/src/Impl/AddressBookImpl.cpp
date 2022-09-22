#include "pch.h"
#include "AddressBookImpl.h"


Shared<Entry> AddressBookImpl::addEntry(Shared<Entry>& entry)
{
const char* fName = entry->getFirstName();
const char* lName = entry->getLastName();

char fLetter_fN = tolower(fName[0]);
char fLetter_lN = tolower(lName[0]);

// Add the sp to Entry to the map with the first letter of first name
if (m_fNameRef.size() && m_fNameRef.find(fLetter_fN) != m_fNameRef.end())
{
	auto entry_vec = m_fNameRef.find(fLetter_fN)->second;

	entry_vec->push_back(entry);
	std::sort(entry_vec->begin(), entry_vec->end(), [](Shared<Entry> a, Shared<Entry> b) {
		return strcmp(a->getFirstName(), b->getFirstName()) < 0;
		});
}
else
{
	auto entry_vec = createShared<std::vector<Shared<Entry>>>();
	entry_vec->push_back(entry);
	m_fNameRef.insert(std::pair<char, Shared<std::vector<Shared<Entry>>>>(fLetter_fN, entry_vec));
}

// Add the sp to Entry to the map with the first letter of last name
if (m_lNameRef.size() && m_lNameRef.find(fLetter_lN) != m_lNameRef.end())
{
	auto entry_vec = m_lNameRef.find(fLetter_lN)->second;
	entry_vec->push_back(entry);
	std::sort(entry_vec->begin(), entry_vec->end(), [](Shared<Entry> a, Shared<Entry> b) {
		return strcmp(a->getLastName(), b->getLastName()) < 0;
		});
}
else
{
	auto entry_vec = createShared<std::vector<Shared<Entry>>>();
	entry_vec->push_back(entry);
	m_lNameRef.insert(std::pair<char, Shared<std::vector<Shared<Entry>>>>(fLetter_lN, entry_vec));
}

return entry;

}

void AddressBookImpl::removeEntry(Shared<Entry>& entry)
{
const char* fName = entry->getFirstName();
const char* lName = entry->getLastName();

char fLetter_fN = fName[0];
char fLetter_lN = lName[0];

if (m_fNameRef.find(fLetter_fN) != m_fNameRef.end())
{
	auto ent_vec = m_fNameRef.find(fLetter_fN)->second;

	for (auto it=ent_vec->begin(); it != ent_vec->end(); ++it)
	{
		if (*it == entry)
		{
			it = ent_vec->erase(it);
			break;
		}
	}
}

if (m_lNameRef.find(fLetter_lN) != m_lNameRef.end())
{
	auto ent_vec = m_lNameRef.find(fLetter_lN)->second;

	for (auto it = ent_vec->begin(); it != ent_vec->end(); ++it)
	{
		if (*it == entry)
		{
			it = ent_vec->erase(it);
			return;
		}
	}
}
}

Shared<std::vector<Shared<Entry>>> AddressBookImpl::getEntriesByFName()
{
auto vec = createShared<std::vector<Shared<Entry>>>();

for (auto ent_pair : m_fNameRef)
{
	auto other_vec = ent_pair.second;
	vec->insert(vec->end(), other_vec->begin(), other_vec->end());
}

return vec;
}

void Foundry::AddressBookImpl::printEntriesByFName()
{
for (auto i : m_fNameRef)
{
	for (auto j : *i.second)
	{
		std::cout << j->getFirstName() << " " << j->getLastName() << std::endl;
		if (j->hasPhoneNumber())
		{
			std::cout << "Phone Number: " << j->getPhoneNumber() << std::endl;
		}
		std::cout << std::endl;
	}
}
}

Shared<std::vector<Shared<Entry>>> AddressBookImpl::getEntriesByLName()
{
auto vec = createShared<std::vector<Shared<Entry>>>();

for (auto ent_pair : m_lNameRef)
{
	auto other_vec = ent_pair.second;
	vec->insert(vec->end(), other_vec->begin(), other_vec->end());
}

return vec;
}

void AddressBookImpl::printEntriesByLName()
{
for (auto i : m_lNameRef)
{
	for (auto j : *i.second)
	{
		std::cout << j->getFirstName() << " " << j->getLastName() << std::endl;
		if (j->hasPhoneNumber())
		{
			std::cout << "Phone Number: " << j->getPhoneNumber() << std::endl << std::endl;
		}
		std::cout << std::endl;
	}
}
}

Shared<std::vector<Shared<Entry>>> AddressBookImpl::searchEntryByFName(const char* fName)
{
std::string srch_tmp = fName;
std::string tmp;
std::string sub;
int srch_size = strlen(fName);

std::transform(srch_tmp.begin(), srch_tmp.end(), srch_tmp.begin(),
	[](char c) { return std::tolower(c); });
char fLetter = srch_tmp[0];

auto srch_vec = createShared<std::vector<Shared<Entry>>>();

if (m_fNameRef.find(fLetter) != m_fNameRef.end())
{
	auto ent_vec = m_fNameRef.find(fLetter)->second;

	for (auto i : *ent_vec)
	{
		tmp = i->getFirstName();
		std::transform(tmp.begin(), tmp.end(), tmp.begin(),
			[](char c) { return std::tolower(c); });
		sub = tmp.substr(0, srch_size);
		if (sub.c_str() == srch_tmp)
		{
			srch_vec->push_back(i);
		}
	}
}

return srch_vec;

}

Shared<std::vector<Shared<Entry>>> AddressBookImpl::searchEntryByLName(const char* lName)
{
std::string srch_tmp = lName;
std::string tmp;
std::string sub;
int srch_size = strlen(lName);

std::transform(srch_tmp.begin(), srch_tmp.end(), srch_tmp.begin(),
	[](char c) { return std::tolower(c); });
char fLetter = srch_tmp[0];

auto srch_vec = createShared<std::vector<Shared<Entry>>>();

if (m_lNameRef.find(fLetter) != m_lNameRef.end())
{
	auto ent_vec = m_lNameRef.find(fLetter)->second;

	for (auto i : *ent_vec)
	{
		tmp = i->getLastName();
		std::transform(tmp.begin(), tmp.end(), tmp.begin(),
			[](char c) { return std::tolower(c); });
		sub = tmp.substr(0, srch_size);

		if (sub == srch_tmp)
		{
			srch_vec->push_back(i);
		}
	}
}

return srch_vec;
}
