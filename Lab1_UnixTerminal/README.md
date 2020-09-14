# Terminal Overview
<img align="right" width="150px" src="./images/Color-of-the-LinkedIn-Logo.jpg">

* Usage of gcc compiler instead clang compiler. Got approved from the TA's post @67 via piazza post.

> "Name 10 terminal commands"

That was a prompt I was given when interviewing for LinkedIn several years ago, and that was not the first time someone had asked me about the terminal at an interview! It's not that you should memorize 10 terminal commands, but rather you should understand that working on the terminal is an essential skill.

In this lab, you are going to perform a few terminal commands to get familiar with the Unix Environment along with some other standard tools used throughout this course (and that you will use in your career!).

## Part 0 - Going through the git tutorials

1. Run through the following github tutorial if you are not familiar with git.
  - https://guides.github.com/introduction/git-handbook/
  - This is worth the 15 minutes it takes to avoid headaches later on!
  - Video guides if needed: https://www.youtube.com/githubguides

## Part 1 - SSH

**I don't care what operating system you use locally as long as you have a terminal and internet access**

### ssh clients for each operating system

* For Windows Users installing Putty is sufficient. (https://www.putty.org/)
  * You might prefer to also install the bash shell from the Windows Store as well. (https://docs.microsoft.com/en-us/windows/wsl/install-win10)
* For Linux/Mac users, you already have a terminal available! Just search for 'terminal'.
* You can optionally install a virtual machine which you may work from, and which has a terminal.

### ssh'ing
* Once your terminal is open, 'ssh' into Khoury with: `ssh khoury_user_name_here@login.khoury.neu.edu`
  * If for some reason you do not have a Khoury username, [follow these instructions](https://www.khoury.northeastern.edu/systems/getting-started/)
* After you have successfully ssh'd, you are now running programs on the Khoury servers (i.e. not locally on your machine).

## Part 1.5 - Obtaining the course repo

When you have successfully ssh'd into the khoury machines (Part 1), watch the video provided [here](https;//google.com) to get familiar with the workflow and set up your working environment. 

A cheatsheet has been added to the repository (Under /ExternalResources) that may be helpful! **Please go through the recommended git tutorials.**

## Part 2 - The (at least) 10 Commands

Try running the following commands (See deliverables section at the end for copying and pasting to output.txt).

1. ls - lists the files and folders in the current directory.
2. mkdir - Create a new directory
3. cd - Change directory
4. man - Manual pages
5. rmdir - Removes an empty directory
6. sort - Sorts information
7. cat - Concatenates files and prints them to standard output
8. nl - Outputs a file with number of lines
9. cut - Remove sections from each file
10. grep - Prints lines that match a pattern.

### Navigating the terminal quickly.

Here are some other nice things to know with the terminal.

* Pressing up and down arrowkeys iterates through your command history (There is also a commmand called *history* you can checkout).
* Pressing *tab* autocompletes if it finds a program, command, or file path.
* Pressing Ctrl+C sends a signal to the terminal to terminate a program if it gets stuck.
* Pressing Ctrl+Z sends a signal to the terminal to suspend a program and give you back control.
  * You can play with these by typing in *sleep 10* (which puts the terminal to sleep) for 10 seconds, and see how you can terminate this program.
* Practice getting help by typing `man ssh` into the terminal. (Press q to quit the manual pages).

### A bit of precision
Calling each of these 'commands' (i.e. ls, sort, cat, etc.) is not really correct. Each of these is itself a program (typically implemented in C or some other language).

As an example, here is the source code for 'ls': http://git.savannah.gnu.org/cgit/coreutils.git/tree/src/ls.c
Each of these commands are part of the coreutils package in Unix. If you look through the source tree, you will additionally find many other programs (i.e. terminal commands you run in your shell) here: http://git.savannah.gnu.org/cgit/coreutils.git/tree/src/.

## Part 3 - Learn-C
<img align="center"  src="./images/learnc.PNG">
The main programming language we will be using in this course is "C".

Complete the 'Learn the Basics' section of the C tutorial on the web from http://www.learn-c.org/
(If for some reason learn-c.org is down, run through the examples provided in the slides)

- [Hello, World!](http://www.learn-c.org/en/Hello%2C_World%21)
- [Variables and Types](http://www.learn-c.org/en/Variables_and_Types)
- [Arrays](http://www.learn-c.org/en/Arrays)
- [Multidimensional Arrays](http://www.learn-c.org/en/Multidimensional_Arrays)
- [Conditions](http://www.learn-c.org/en/Conditions)
- [Strings](http://www.learn-c.org/en/Strings)
- [For loops](http://www.learn-c.org/en/For_loops)
- [While loops](http://www.learn-c.org/en/While_loops)
- [Functions](http://www.learn-c.org/en/Functions)
- [Static](http://www.learn-c.org/en/Static)

Once you are comfortable write a C program on the Khoury machines in the file **main.c**.

1. The program will contain a function with the signature 'double power(double base, double n)'.
2. Your program will call this function in a loop in the main function, computing the first power(2,1) to power(2,10) and print out these results to the terminal.  
3. You can compile your program with: `clang main.c -o main` to see if it works.
	- Instead of compile the code with clang, I ended up using gcc compiler instead. 

Here is a little tutorial on VIM as a resource: https://www.howtoforge.com/vim-basics (Note I use VIM, and have limited knowledge of other editors, but you are free to use what you like).

**Note, if you progrm doesn't compile, it doesn't get credit.**

# Part 4 - How to work locally. 

If you have a Mac or a Linux box you already have a termainal, and should have gcc and clang installed. If you have a Windows machine you can download a C IDE of your choice, or you could look into installing the Windows Powershell or Cygwin, or you could look into installing a Linux/Mac virtual machine. I would recommend working locally as your last resort if the network is down. 

Whatever path you choose to go, make sure your code compiles when you SSH on the khoury machines.

## More resources to help

- There is a lovely user manual on Virtual Box here: https://www.virtualbox.org/manual/
- There is another example of installing an older Ubuntu on an older version of virtual box here with pictures: https://askubuntu.com/questions/142549/how-to-install-ubuntu-on-virtualbox
- If you are not comfortable with compiling a C program on the terminal, take a look at this resource: https://www.cs.fsu.edu/~myers/howto/g++compiling.txt
- Hackerrank has an excellent series of shell tutorials here: https://www.hackerrank.com/domains/shell/bash
  - I highly recommend going through them if you are not comfortable with the shell.
- **If you accidently delete something** you can navigate to `cd .snapshot/` which will show files that have been periodically backed up for that current directory. This is yet anothe reason to make sure you are working within the Khoury systems which provide this backup service.
- A pretty good introduction to shell scripting is here: https://www.howtogeek.com/67469/the-beginners-guide-to-shell-scripting-the-basics/ .


## Deliverable

* Copy and Paste the output from the command-line interface of you running five different terminal commands above into a file called "output.txt" (no capitalization, exactly as named.)
  * Make sure to 'add/commit/push' this file to the repo in this directory.
* Modify the file called 'main.c' in your respository containing the power example.
  * Make sure to 'add/commit/push' this file to the repo in this directory.
  
* Make sure you submit **output.txt** and **main.c** on [handins](https://handins.ccs.neu.edu/). 

## Going Further

(Some more terminal programs to research and try out on your own time)

1. history
2. tree
3. touch
4. awk
5. sed
