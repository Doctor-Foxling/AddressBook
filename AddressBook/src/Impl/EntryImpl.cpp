#include "pch.h"
#include "base.h"
#include "EntryImpl.h"

namespace Foundry
{
    Shared<Entry> EntryImpl::Create()
    {
        // In future, other versions of an Entry can be returned based on some condition
        return createShared<EntryImpl>();
    }
    Shared<Entry> EntryImpl::Create(const char* fName, const char* lName)
    {
        return createShared<EntryImpl>(fName, lName);
    }

    Shared<Entry> EntryImpl::Create(const char* fName, const char* lName, const char* phoneNumber)
    {
        return createShared<EntryImpl>(fName, lName, phoneNumber);
    }


}