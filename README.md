# Asgn6 - Tying it all thogether...with THREADS
No Design Due  
Final Due: Sunday 5/02

# Objectives 
1. Practice writing multi-threaded programs.
2. Continue to explore program optimization.

# Goal
Somehow, we seem to be caught in a time loop: Patrick, Spongebob, and Mr. Krabs are arguing about matrix multiply again. It is up to you to demonstrate all that you have learned this semester to write the fastest matrix multiply that ever did multiply. Of course, to do that you are going to need THREADS.

Your task is to insert a multi-threaded matrix multiply into the test harness we used way back in Assignment 1. The newly threaded ```mm``` program you write should take a single argument: the number of threads to use. It will output the CPE for matrix multiplication for various sized matricies. HINT: By far the easiest way to do this is using [Cannon's Algorithm](https://en.wikipedia.org/wiki/Cannon%27s_algorithm "Decription of Cannon's algorithm").

## Assumptions
1. The matricies are always square.
2. The number of columns and rows is always a power of two.
3. The number of threads will always be a power of two.
4. The number of threads will always be square.
5. The matricies to be multiplied are global variables named ```ga``` and ```gb```. The result should go into a global variable named ```gc```.  
    * NOTE: Using global variables like this is generally a bad idea, but the test harness code is stolen (borrowed!) it uses global variables. Since threads share global variables, this works out just fine. 
    
# Submission
Due: Sunday 5/02

Submit to GitHub:
1. All relevant code and makefiles.
2. A file named ***analysis.txt*** in which you have:  
    * explored the effect of increasing the thread count and pontificated a bit on the implications of your exploration.  
    * recalled fondly your results from Assignment 1 and compared your current results to them.  
    * perhaps, if feeling particularly ambitious, explored the effects of loop ordering or optimization strategies
3. A file named ***output.txt*** containing a script of ```mm 1```, ```mm 4```, and ```mm 16```.

# Reminders
1. You should be committing when appropriate with appropriate commit messages.
2. You should not have any warnings when you compile.
3. If you use malloc, you need to free your memory.
4. Use function headers.
