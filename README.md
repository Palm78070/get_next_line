# get_next_line
Create function that can receive file descriptor as input and read content from it line by line

The definition of line is ascii character from 0-n and end with newline('\n') or end of file(EOF)

## Return values
1. **Success => Return line that have been read**
2. **NULL => there is nothing else to read, or an error occurred**

## External function
read(), malloc(), free()

## Details
Calling get_next_line() in a loop will allow you to read each line by line until the last line(EOF) or error occured which will return NULL

## What i learn from this project
1. **File descriptor manipulation**
2. **Memory alloction and how to avoid memory leak**
3. **Implementation of function from libft project**
