## Array and Strings

Array and String type of questions were asked in interviews frequently. You will most likely encounter one during your
interviews.

### Slideing Window Technique

https://www.geeksforgeeks.org/window-sliding-technique/

1. Fixed Size Sliding Window:
   The general steps to solve these questions by following below steps:

- Find the size of the window required, say K.
- Compute the result for 1st window, i.e. include the first K elements of the data structure.
- Then use a loop to slide the window by 1 and keep computing the result window by window.

2. Variable Size Sliding Window:
   The general steps to solve these questions by following below steps:

- In this type of sliding window problem, we increase our right pointer one by one till our condition is true.
- At any step if our condition does not match, we shrink the size of our window by increasing left pointer.
- Again, when our condition satisfies, we start increasing the right pointer and follow step 1.
- We follow these steps until we reach to the end of the array.