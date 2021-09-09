# Rshell Programming Project
# Project Information
**Winter 2020**

# Introduction
This program will be able to print a command prompt, read in a line of commands and connectors, execute commands (fork, execvp, waitpid, implemented test function), and continue to do so until it exits. Inputs will be ingested using getline. It will then be separated in a tokenizer class and each separated string will be made into tokens. Then, they will be pushed onto an array of tokens where it will be taken in by an executor class where each command will be executed.

# Diagram
![OMT DIAGRAM](https://github.com/cs100/assignment-jdhs/blob/master/images/Updated_OMT_Diagram2.png?raw=true)

# Classes
1. class Tokenizer: Takes in a string argument, separates string, creates tokens, and returns an array of tokens.
2. class Token: Parent class that holds name ,bool isExist function and virtual void logic function with several children classes to further specify the command. Each children class will also hold the functions that will be executed.
   * class cmdToken: Detects whether a command that is inputted by user is a valid command.
   * class smcolonToken: Finding a semicolon sign(;) in an array of tokens. Splitting the array of tokens into two based on the index of the semicolon token. 
   * class andToken: Finding a double ampersand sign(&&) in an array of tokens. Splitting the array of tokens into two based on the index of the double ampersand token.
   * class orToken: Finding a double or/broken bar sign(||) in an array of tokens. Splitting the array of tokens into two based on the index of the double or token. 
   * class poundToken: Locating a pound sign(#) in an array of tokens. Deleting the token with the pound sign in it and the rest of the tokens that exist after the pound sign.
   * class quoteToken: Locating a quote sign( " , ' ) in an array of tokens. Deleting the token(s) with the quote sign in it. If an unmatched quote is found, throw an error message.
   * class parenToken: Locating parentheses signs in an array of tokens. Deleting the token(s) with the parentheses sign in it. If non-empty token(s) are found outside the end parentheses, the rest of the token(s) are allocated into a new array.
   * class bracketToken: Locating bracket signs in an array of tokens. Replacing the open bracket with "test". Deleting the token with end bracket sign in it and the rest of the token(s) after the end bracket sign. If non-empty token(s) are found outside the end bracket, the rest of the token(s) are allocated into a new array. If inappropriate syntax is inputted by user, throws an error message.
   * class testToken: Detects whether a command that is inputted by user is "test". Checks whether the path to file exists. In addition, it checks whether it is a file or a directory if the user desires. Returns a "(True)" or "(False)" statement(s) based on the availability and the type of the path to file. If inappropriate syntax is inputted by user, throws an error message.
3. class Executor: Takes in an array of tokens. If "exit" is inputted by user, exits the program. If "test" is inputted by user, execute the test function. Executes the rest of the commands using fork, execvp, and waitpid. If it is an invalid command(s), throws an error message.  	

# Prototypes/Research
We utilized the Boost Tokenizer class to perform our parse. In the prototype, it parses a string with four "./test" separated by spaces. Although it is hardcoded at the moment, we can fix that later for it to work with user input as well as connectors. To work with connectors, we plan to have them added as another token and save them to the argv array.
The three functions (execvp, waitpid, fork) are working with the hardcoded string mentioned previously. They were able to output all four "./test" correctly. We hope to change the loop so that it may accept an infinite amount of user inputs. 

# Development and Testing Road
[Implementing main function](https://github.com/cs100/assignment-jdhs/issues/2)

[Declare classes and functions](https://github.com/cs100/assignment-jdhs/issues/3)

[Implementing token class](https://github.com/cs100/assignment-jdhs/issues/4)

[Implementing class tokenizor](https://github.com/cs100/assignment-jdhs/issues/5)

[Implementing class cmdToken](https://github.com/cs100/assignment-jdhs/issues/6
)

[Implementing argToken class](https://github.com/cs100/assignment-jdhs/issues/7)

[Implementing class AndToken](https://github.com/cs100/assignment-jdhs/issues/8)

[Implementing class poundToken](https://github.com/cs100/assignment-jdhs/issues/9)

[Implementing orToken class](https://github.com/cs100/assignment-jdhs/issues/10)

[Function to detect semicolon (;)](https://github.com/cs100/assignment-jdhs/issues/11)

[Implementing execute class](https://github.com/cs100/assignment-jdhs/issues/12)

[Implementing command "ls -a" ](https://github.com/cs100/assignment-jdhs/issues/13)

[Implementing exit command](https://github.com/cs100/assignment-jdhs/issues/14)

[Implementing command "echo"](https://github.com/cs100/assignment-jdhs/issues/15)

[Implementing mkdir command function](https://github.com/cs100/assignment-jdhs/issues/16)

[Create unit tests](https://github.com/cs100/assignment-jdhs/issues/17)
