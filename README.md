# AddressBook

<img src=https://github.com/Doctor-Foxling/AddressBook/blob/master/Images/flowChart.PNG>

This is an AddressBook program written for the Foundry interview test. The source code follows the abstract factory design pattern which makes program:
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



