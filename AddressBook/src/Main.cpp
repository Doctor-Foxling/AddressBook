#include "base.h"
#include "pch.h"

#include "Impl/AddressBookImpl.h"
#include "Impl/EntryImpl.h"

int main()
{
    using namespace Foundry;

    // Creating new Entries
    Shared<Entry> entry   = EntryImpl::Create("Hamza",    "Khan");
    Shared<Entry> entry2  = EntryImpl::Create("HGamza",   "erhan");
    Shared<Entry> entry3  = EntryImpl::Create("Hasmza",   "vbhan");
    Shared<Entry> entry4  = EntryImpl::Create("Aadsdmza", "Ufhan");
    Shared<Entry> entry5  = EntryImpl::Create("Taymza",   "ghhan");
    Shared<Entry> entry6  = EntryImpl::Create("Yaumza",   "kuihan");
    Shared<Entry> entry7  = EntryImpl::Create("Uamza",    "ghhan");
    Shared<Entry> entry8  = EntryImpl::Create("Qamza",    "luhan");
    Shared<Entry> entry9  = EntryImpl::Create("John",     "Doe");
    Shared<Entry> entry10 = EntryImpl::Create("Jason",    "Silva");
    Shared<Entry> entry11 = EntryImpl::Create("Andy",     "Wier");
    //Entries with phone numbers
    Shared<Entry> entry12 = EntryImpl::Create("Brandon",  "Sanderson", "07566037156");
    Shared<Entry> entry13 = EntryImpl::Create("Logan",    "Ninefinger","07566235656");
    Shared<Entry> entry14 = EntryImpl::Create("Robert",   "Jordan", "07522435156");

    auto* addrBook = new Foundry::AddressBookImpl();

    addrBook->addEntry(entry);
    addrBook->addEntry(entry2);
    addrBook->addEntry(entry3);
    addrBook->addEntry(entry4);
    addrBook->addEntry(entry5);
    addrBook->addEntry(entry6);
    addrBook->addEntry(entry7);
    addrBook->addEntry(entry8);
    addrBook->addEntry(entry9);
    addrBook->addEntry(entry10);
    addrBook->addEntry(entry11);
    addrBook->addEntry(entry12);
    addrBook->addEntry(entry13);
    addrBook->addEntry(entry14);


    // [TESTS] 

    // Getting Entries by first name sorting
    std::cout << " ----- Got Entries by first name (Shared pointers) ----" << std::endl;
    auto ent_vec = addrBook->getEntriesByFName();
    std::cout << " ----- Now Printing the names within them -----" << std::endl;
    for (auto ent : *ent_vec)
    {
        std::cout << ent->getFirstName() << " " << ent->getLastName() << std::endl;
    }
    std::cout << std::endl;

    // Remove Entry by passing in the sp to Entry object
    std::cout << " ---------- Remove Entry by passing in the sp to Entry object --------" << std::endl;
    addrBook->removeEntry(entry);
    std::cout << std::endl;

    //Directly Printing the names by first name sorting in the entries
    std::cout << " --------- Printing Names --------- " << std::endl;
    addrBook->printEntriesByFName();
    std::cout << std::endl;

    //Getting Entries by second name sorting
    std::cout << " --------- Got Entries by second name (Shared pointers) ----" << std::endl;
    ent_vec = addrBook->getEntriesByLName();
    std::cout << " --------- Now Printing the names within them -----" << std::endl;
    for (auto ent : *ent_vec)
    {
        std::cout << ent->getFirstName() << " " << ent->getLastName() << std::endl;
    }
    std::cout << std::endl;


    //Directly Printing the names by last name sorting in the entries
    std::cout << " --------- Printing Names --------- " << std::endl;
    addrBook->printEntriesByLName();
    std::cout << std::endl;

    //Search Entry by first name
    std::cout << " -------- Search Entry by first name (Names starting with) --------" << std::endl;
    auto search_vec = addrBook->searchEntryByFName("Robert");
    for (auto i : *search_vec)
        std::cout << i->getFirstName() << " " << i->getLastName() << std::endl;
    std::cout << std::endl;


    //Search Entry by last name
    std::cout << " -------- Search Entry by Last name (Names starting with)--------" << std::endl;
    search_vec = addrBook->searchEntryByLName("Wier");
    for (auto i : *search_vec)
        std::cout << i->getFirstName() << " " << i->getLastName() << std::endl;
    std::cout << std::endl;


    //Search Entry by first name starting with ... 
    std::cout << " -------- Search Entry by first name (Names starting with) --------" << std::endl;
    search_vec = addrBook->searchEntryByFName("Ha");
    for (auto i : *search_vec)
        std::cout << i->getFirstName() << " " << i->getLastName() << std::endl;
    std::cout << std::endl;

    //Search Entry by last name starting with ... 
    std::cout << " -------- Search Entry by Last name (Names starting with)--------" << std::endl;
    search_vec = addrBook->searchEntryByLName("Uf");
    for (auto i : *search_vec)
        std::cout << i->getFirstName() << " " << i->getLastName() << std::endl;
    std::cout << std::endl;

    int exit;
    std::cin >> exit;

    delete addrBook;

    return 0;
}


