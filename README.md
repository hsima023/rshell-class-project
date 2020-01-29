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
1. class Tokenizer: takes in a string argument, separates string, creates tokens, and returns a vector of tokens.
2. class Token: Parent class that holds name and virtual void createToken function with several children classes to further specify the command. Each children class will also hold the functions that will be executed.
  * class cmd: creates a command token and holds functions of commands
  * class arg: creates an argument token
  * class and: creates an and token
  * class or: creates an or token
  * class pound: creates a pound token
3. class Executor: takes in a vector of tokens and executes each token by calling functions of the token.

# Prototypes/Research

# Development and Testing Roadmap
Implementing main function#2
