# CS 100 Programming Project
# Project Information
**Winter 2020**

Name | SID
---- | ----
John Dang | 862047315
Hans Simanjuntak | 862155474

# Introduction
This program will be able to print a command prompt, read in a line of commands and connectors, execute commands (fork, execvp, waitpid), and continue to do so until it exits. Inputs will be ingested using getline. It will then be separated in a tokenizor class and each separated string will be made into tokens. Then, they will be pushed onto a vector of tokens where it will be taken in by an executor class where each command will be executed.

# Diagram
![OMT Diagram](/images/OMT_Diagram.png)

# Classes
1. class Tokenizer: Takes in a string argument, separates string, creates tokens, and returns a vector of tokens.
2. class Token: Parent class that holds name and virtual void createToken function with several children classes to further specify the command. Each children class will also hold the functions that will be executed.
   * class cmd: Creates a command token and detects what command is written. Executes the various commands.
   * class arg: Creates an argument token and holds argument.
   * class and: Creates an and token and executes AND function.
   * class or: Creates an or token and executes OR function.
   * class pound: Creates a pound token and executes # function.
3. class Executor: takes in a vector of tokens and executes each token by calling functions of the token.

# Prototypes/Research

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
