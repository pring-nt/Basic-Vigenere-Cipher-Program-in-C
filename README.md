This is my unoptimized first attempt at using strings and arrays to make a vigenere cipher program.

- This program can encode and decode messages with a given message and a key.
- The max string length is set at 254, the functions resposible for taking the input does NOT have any error detection and may accidentally overflow.
- The message can take a 254 character long string in either upper or lower case, including punctuations and any white space aside from new line.
- The key input can only take a string with the english alphabet, using other characters WILL mess up the output ty.
