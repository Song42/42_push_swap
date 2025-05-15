# push_swap

### Stack push and swap
Sorting numbers using only stack push/swap

### Overview
Push_swap is a project about sorting a stack of integers using a limited set of operations (`sa`, `pb`, `rb`, `rra`, etc.).
The goal is to amke the shortest possible combination of these sequences to sort the integers provided by user.
This project emphasizes algorithm optimization, stack manipulation and complexity management.

### Keypoints
- no standard sort functions
- using only provided stack operations are permitted
  - `sa`/`sb`: swap first 2 elements of stack a/b
  - `pa`/`pb`: push first 1 element of stack b/a to stack a/b
  - `ra`/`rb`: rotate all elements of stack a/b
  - `rra`/`rrb`: rerotate all elements of stack a/b
- benchmark cut-line
  - 100 numbers - under 700 operations
  - 500 numbers - under 5500 operations
- implementing checker to verify the stack was sorted using optimal operations
