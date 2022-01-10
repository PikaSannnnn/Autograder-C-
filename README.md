# Problem I
### Introduction
For every problem set, the focus will be to practice everything that was learnt up to that week and to apply them to problems of a higher degree of difficulty. The problems will mostly feel simple, but for each, it will require you to apply everything that you've learned before. *hint hint*

This quarter, there will be more things you will learn, in fact, you'll learn 2x the new material that you've learnt in CS10A. Your code will only get longer and more complicated. This means that we need a new way to check your code without going to each individual breakout room for a walk-through, or a super long section at the end of the session where we go over each individual parts of the code.

Thus, with the new quarter, we have leveled-up in terms of the ability to check work while in breakout rooms. We introduce to you this Auto-Grader. The auto-grader is simple to use, just press the `Run` button to make everything work. You know how Zybooks checks your code? Or maybe perhabs you've used leetcode or hackerrank. The method in those is to compare your output with their expected output. Each problem set will do the exact same thing. It will run your code, get its outputs, and compare them with an expected output.

You can run the code as many times as you'd like to see the output that you're getting and to see how the compare with the expected output. This auto-grader is in its earliest stages. This means that it's not perfect, which it definitely isn't. 

The `Tests` will be displayed in each problem and will show what the grader is checking your solution with. It'll be similar to how Zybooks had been extremely sensitive. But fret not, you don't have to add random `endl`'s at the end, nor do you have to do anything to make your code match the expected output. Code it like you normally would as if you were getting input from the terminal. The expected outputs omit any of the wackiness that Zybooks had required.

`Sample` will provide an example solution that we as humans hope to see and use. `Tests` will show what the actual grader is hoping to see, and there will be differences, particularly wherever a `cin` exists.

**The grader is somewhat customizable. If you'd like to do certain things with it, i.e. run it normally as a human rather than comparing with the outputs, read `The Auto-Grader` section of this README**

**You can also use your own IDE/editor to write and test your code, just remember to paste it in the locations specified**

---

### Problem
In CS10A, you've learned a couple of things: data structures, algorithms, and loops. We will, of course, use this for our problem.  

Sometimes when collecting data, there may be multiple sources for the data. One data set can come from a student, and another a professor. We may need to compare the data, or combine to see how they work together.

Write a program that will take in **TWO** data sets. The program will have these functions:
* Mean() - Find the mean of the merged data set
    * command: `mean`
    * If merged data set does not exist, print `No Merged Data Set`
* Median() - Find the median of the merged data set
    * command: `median`
    * If merged data set does not exist, print `No Merged Data Set`
* Range() - Find the range of the merged data set
    * command: `range`
    * If merged data set does not exist, print `No Merged Data Set`
* Print() - Prints whatever is passed in (merged or int/double)
    * command: `print`
    * If merged data set does not exist, print `No Merged Data Set`
    * Either prints a single `int` or and entire data set
        * How do we take in both a single `int` or an entire data set without taking both at the same time?
    * End with a single `endl`
* Merge() - Merges two data sets together and returns a new data set
    * command: `merge`
    * This algorithm will be provided. You will modify the function so that it allows the algorithm to work
    * Creates data set 3
* Exit() - Exits the program
    * command: `exit`
    * Print out **"Bye!"** before leaving

Support Functions:  
* `sprt::Sort(vector<int>)` - returns a sorted vector

**After each command (except Exit()), print out the result or `No Merged Data Set`. If both data sets are empty, every output, including `merge` should essentially print `No Merged Data Set`**

The program will start by asking the user for the size `n` of a data set. Each following `n` integers are members of that data set. The same occurs with the second data set immediately after the first. These 2 data sets are data sets `1` and `2`. Commands will follow the input of both data sets.

---

### Sample
<details><summary>Input</summary>
    
```
4
0 1 2 3 
1
4
mean
mean
mean
merge
median
range
merge
merge
print
median
print
exit
```
</details>


<details>
    <summary>Output</summary>
    
```
Enter num entries in data set 1: 4
Enter your data set: 0 1 2 3
Enter num entries in data set 2: 1
Enter your data set: 4
mean
No Merged Data Set
mean
No Merged Data Set
mean
No Merged Data Set
merge
0 1 2 3 4 
median
2
range
4
merge
0 1 2 3 4 
merge
0 1 2 3 4 
print
0 1 2 3 4 
median
2
print
0 1 2 3 4 
exit
Bye!
```
</details>


---

### Constraints
* `-1000 <= set[i] <= 1000`
* `0 <= set.size() <= 20`
* Assume all commands are valid

---

### Tests


## The Auto-Grader
### What It Does:
This auto-grader is a little-side project writte on repl.it that focuses on output comparison. The grader compares the output to certain test cases. This method of comparison grading is extremely sensitive in that each character is compared exactly. In this version, the test cases fail at the first instance of a difference detected and any single character difference will automatically fail the entire test. The grader utilizes a preset set of custom inputs for any `cin` prompts and compares it to a pre-determined set of outputs, if any.

### Writing Your Solutions:
Normally, solutions or code would be written in `main.cpp`. However, in this version of the Auto-Grader, `main.cpp` isused solely to make the Auto-Grader work. In order to write any code to test solutions against, they must be written in `solution.cpp`, with `smain()` as the substitute `main()`. Everything else-- with functions, classes, headers, etc.-- can be done normally. The only thing that needs consideration is command arguments. In the case of classroom/tutoring use, there is a expected method of doing the command arguments. In this case, simply set it as wished in in `main()` in `main.cpp`. Also not that each of the desired command line arguments will need to be properly passed into `smain()` and must be done in `main.cpp`. These changes must also be applied in `solution.h`.

### Results - How To Get Them:
There are a few ways to run the Auto-Grader. If it is being used on repl.it, simply pressing the `Run` will be enough to work the grading process. Otherwise, manually typing compiling every `.cpp` file and running it should be fine. Such a process is done by typing `g++ *.cpp` in the terminal and then typing `./a.out`, or whatever the executable is named as. 

### Results - Custom Input:
Of course, if you'd like to set your own custom inputs, and check their outputs, this can be done in two ways.

1. There is a commented `main()` in `solution.cpp`. Uncommenting and performing the same procedure of passing in values, etc. will effectively make it a new `main.cpp`. Note that on repl.it, the `Run` button **cannot** be used here. Instead, the programm will need to be compiled and ran manually. This can be done with `g++ [file1].cpp [file2].cpp ... ` and running the executable created.
2. There is no *CMake* for this Auto-Grader yet, which means option 1 can be very tedious when there are multiple files. The second option is to go into `main.cpp` and set `CUSTOM_IN` to `1`. This way, it'll skip the setup for automatic input and output.

### Results - What They Mean:
After running the code, you may get something along the lines of this:
```
==== Running Test Cases ====
>>>>> Case 0
    RESULT: PASSED
>>>>> Case 1
    RESULT: FAILED
        Your Output:
~~~~~~~~~~~~~~~~~~~~~~~
Hello World!

~~~~~~~~~~~~~~~~~~~~~~~
    Mismatch: First appeared on line 0, char 4

=======================
Total Cases: 2
Cases Passed: 1
=======================
```
* Each case will be distinguishly marked from `0 - N`. All the information per case is placed below `>>>>> Case N` and above `Case N+1`.  
* **Passed** cases are simply displayed as `PASSED` and outputs are hidden from the user.  
* **Failed** cases first display that it has `FAILED` before printing your output between the two `~~~~~~~~~~~~~~~~~~~~~~~`.
* The new line at the end of the output can be ignored and is not part of the code output.
* After your output is displayed, the location of where the **first** mistmatch is located is printed, and the `line` and `char` are incremented from 0. Note that the first mismatch actually marks the last location in which the last correct char is located, and the mismatch may occur after that char instead.
* If the error location is located in the *ignored new line*, the error is likely to have occured at the **end** of the previous line.
* Within the `=======================`, the total cases and number of cases passed is displayed.

### Possible Future Changes:
* [ ] Allowing Running to be done through *Cmake*
* [ ] Allowing code to be written in `main()` again.
* [ ] Perform difference threshold pass/fails rather than first instance