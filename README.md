# Problem Set \#
### Description

### Sample

### Constraints

### Tests

## The Auto-Grader
### What It Does:
This auto-grader is a little-side project that focuses on output comparison. The grader compares the output to certain test cases. This method of comparison grading is extremely sensitive in that each character is compared exactly. In this version, the test cases fail at the first instance of a difference detected and any single character difference will automatically fail the entire test. The grader utilizes a preset set of custom inputs for any `cin` prompts and compares it to a pre-determined set of outputs, if any.

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