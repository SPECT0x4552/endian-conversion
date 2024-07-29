# Endian Conversion from HEXADECIMAL format

This program allows to convert HEXADECIMAL format from Big Endian byte ordering to Little Endian byte ordering and vice versa.

First, the hexadecimal format is stored in a string. 
The string is passed onto a function in which the hex value is converted into a integer. 
The integer value is passed onto the function which makes the necessary bit shifting operations to convert between to Endian formats.

sprintf() function is currently hard-coded and not scalable. 
I.e. if you have a larger hexadecimal array('char'), you have to manually add the elements of the array to the sprintf() function so that it will get converted into a string. 




_Will be making updates on a regular basis if I manage to and figure out ways to make this better._