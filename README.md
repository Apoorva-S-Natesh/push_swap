### A tale of stacks and chunks. A sorting algorithm for the push_swap project of 42 Programming School.

Welcome to a detailed exploration of the Push_Swap challenge, a complex puzzle that tests the limits of algorithm design and efficiency. In this journey, we delve deep into the mechanics of sorting algorithms, particularly focusing on the use of two stacks to sort data with a minimal number of operations. This challenge not only sharpens problem-solving skills but also enhances understanding of data structures and algorithm optimization. Join me as we unpack the strategies that lead to an effective solution, learn from trials, and ultimately master the art of stack sorting.

## Operations in Toolbox

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time

## Sorting Strategy

Now, let’s talk strategy. The program doesn’t just *sort*—it strategizes. Here’s the flow:

1. **Small Stack Handling:**
    - For stacks with 2-5 elements, we use specific functions (`sort_two_a`, `sort_three_a`, etc.) to sort them directly.*(Small stacks = less drama. Quick and clean.)*
2. **Divide and Conquer:**
    - For larger stacks, we split them into chunks and use functions like `sort_from_left` to tackle them in segments.
3. **Control Checks:**
    - Functions like `n_ascending` and `n_descending` ensure we’re staying on track.
    
    To reduce the number of operations:
    
    - Check If an element in Stack A has to be pushed to stack B and then rotated in B(rb) and if the next element in Stack A also has to be rotated(ra) then **`rr`** is used instead.
    - Check if an element in Stack A has to be swapped and also an element in Stack B has to be swapped then **`ss`** is used.
  
### Diving Into Thirds-Based Sorting

1. **Initial Distribution**: The sorting process begins by distributing the contents of Stack A into three categories based on their rank—max, mid, and min thirds. This distribution helps in managing the complexity by focusing on smaller subsets of the stack. 
- **Max Thirds** remain in Stack A, positioned at the bottom as they represent the largest elements.
- **Mid Thirds** are transferred to Stack B, specifically to the top of Stack B.
- **Min Thirds** are rotated within Stack B to move to the bottom, preparing them for the subsequent sorting phase.
2. **Recursive Sorting**: Each of these chunks is recursively sorted again by dividing them into 3 chunks. When sorting elements in stack B,
- Max Thirds are transferred to top of Stack A.
- Mid Thirds are Transferred and rotated to bottom of Stack A.
- Min Thirds remain in Stack B.
The algorithm employs recursive functions that sort these smaller chunks and prepare them for eventual reintegration into Stack A.
3. **Integrating Back to Stack A**: Stack is sorted to have  elements in ascending order. Once sorted in Stack B, elements are strategically moved back to Stack A. This step also involves recursive sorting to ensure elements are placed in the correct order as they return to Stack A.
4. **Final Adjustments**: The algorithm concludes with any necessary final adjustments in Stack A to ensure the entire stack is sorted in ascending order. This might involve additional sorting operations or simple rotations to align all elements properly.

![sort_from_left](https://github.com/user-attachments/assets/342ffa08-6392-457d-8750-57aa1a191ff0)
