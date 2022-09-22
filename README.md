# AddressBook

<img src=https://github.com/Doctor-Foxling/AddressBook/blob/master/Images/flowChart.PNG>

This is an AddressBook program written for an interview test. The source code follows the abstract factory design pattern which makes program:
<ul>
<li>More Scalable</li>
<li>Easy to contribute to</li>
<li>Easy to wrap with Mock Tests</li>
</ul>

The code makes use of smart pointers wherever possible which makes the code memory safe (This can make the code less readable).

# Build Instructions
The project was built using VisualStudio 2019 targetting C++14. Premake is used to build the project.

To Build the project:
<ul>
<li>Use the GenerateProject.bat file to generate Visual Studio .sln file</li>
<li>The solution can then be opened and built</li>
<li>The executables binary is generated in the bin folder</li>
</ul>

Currently the build system only supports Windows but support for other platforms would be added in the future.

# Documentation

A walkthrough of the source code can be found here: <a href="https://youtu.be/0KZnnGY6pB8"> https://youtu.be/0KZnnGY6pB8 </a>

The source is divided into main parts:
<ul>
<li>Abstract</li>
<li>Implementation</li>
</ul>

The Abstract files lay out the basic interface, on top of which are the implentations created.

Following are the two abstract files:

<h3>Entry</h3>
The Entry is just a simple abstract class that provides pure virtual functions for adding, checking and retriving information to a given element of the Addressbook.

```c++
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

```

<h3>AddressBook</h3>

The AddressBook is what adds, removes and retrieves the Entry objects themselves. 

```c++
class AddressBook {
	public:
		virtual ~AddressBook() = default;
    
		virtual Shared<Entry> addEntry(Shared<Entry>& entry) = 0;
		virtual void removeEntry(Shared<Entry>& entry) = 0;
		virtual Shared<std::vector<Shared<Entry>>> getEntriesByFName() = 0;
		virtual void printEntriesByFName() = 0;
		virtual Shared<std::vector<Shared<Entry>>> getEntriesByLName() = 0;
		virtual void printEntriesByLName() = 0;
		virtual Shared<std::vector<Shared<Entry>>> searchEntryByFName(const char* fName) = 0;
		virtual Shared<std::vector<Shared<Entry>>> searchEntryByLName(const char* lName) = 0;
 	};
```

<h3> Creation of Entries </h3>

The EntryImpl class provides overloaded, static Create() function that creates a std::shared_ptr to an EntryImpl object and returns a ```sp``` to an Entry object pointing to it.

```c++
Shared<Entry> EntryImpl::Create(const char* fName, const char* lName)
    {
        return createShared<EntryImpl>(fName, lName);
    }

    Shared<Entry> EntryImpl::Create(const char* fName, const char* lName, const char* phoneNumber)
    {
        return createShared<EntryImpl>(fName, lName, phoneNumber);
    }
```

Entries can thus be created in the follwing way:

```c++
 Shared<Entry> entry10 = EntryImpl::Create("Jason",    "Silva");
 Shared<Entry> entry11 = EntryImpl::Create("Andy",     "Wier");
 //Entries with phone numbers
 Shared<Entry> entry12 = EntryImpl::Create("Brandon",  "Sanderson", "07566037156");

```
An AdressBookImpl object can be created and the entries can be added like so:

```c++
auto* addrBook = new AddressBookImpl(); // Needs to use smart pointers

    addrBook->addEntry(entry);
    addrBook->addEntry(entry2);
    addrBook->addEntry(entry3);
```

# Improvements

The project can be improved in many ways, to name a few:

<ul>
<li>Using an algorithm like Suffix tree to store the Entries, which would make the retrieval of entries (The operation that's performed the most) to be much faster</li>
<li>Using a Mock test (e.g., GTest) for unit testing the functionalities</li>
<li>Provide build support for other platforms so it can be contributes to by most developers</li>
<li>Provide better Documentation</li>
<li>Improve upon the design pattern</li>
<ul>
