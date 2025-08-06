# push_swap - Efficient Stack Sorting Algorithm

## About

**push_swap** is an algorithmic project at École 42 that challenges students to sort a stack of integers using a limited set of operations and two stacks. The goal is to sort the numbers in ascending order in stack A using the minimum number of operations possible. This project emphasizes algorithm optimization, complexity analysis, and efficient problem-solving strategies.

The project requires implementing a sorting algorithm that works with specific stack operations, making it a unique constraint-based sorting challenge. The solution must be highly optimized to handle various input sizes while maintaining excellent performance characteristics.

## Learning Objectives

- **Algorithm Design**: Creating efficient sorting algorithms under specific constraints
- **Complexity Analysis**: Understanding time and space complexity trade-offs
- **Data Structure Management**: Working with stacks and stack operations
- **Optimization Techniques**: Minimizing operation count through intelligent algorithm choice
- **Binary Operations**: Understanding and implementing binary-based algorithms
- **Problem Decomposition**: Breaking complex problems into manageable components
- **Performance Testing**: Analyzing algorithm performance across different input scenarios

## Available Operations

### Stack A Operations
- **sa**: Swap the first two elements of stack A
- **pa**: Push the top element from stack B to stack A
- **ra**: Rotate stack A (first element becomes last)
- **rra**: Reverse rotate stack A (last element becomes first)

### Stack B Operations
- **sb**: Swap the first two elements of stack B
- **pb**: Push the top element from stack A to stack B
- **rb**: Rotate stack B (first element becomes last)
- **rrb**: Reverse rotate stack B (last element becomes first)

### Combined Operations
- **ss**: Execute sa and sb simultaneously
- **rr**: Execute ra and rb simultaneously
- **rrr**: Execute rra and rrb simultaneously

## Algorithm Implementation: Radix Sort

### Algorithm Choice Rationale

The radix sort algorithm was chosen for its optimal performance characteristics with this specific constraint set:

- **Time Complexity**: O(n * log(n)) - Excellent for large datasets
- **Operation Count**: Predictable and minimal for all input sizes
- **Simplicity**: Clean implementation with consistent performance
- **Scalability**: Maintains efficiency as input size increases

### Radix Sort Strategy

#### Core Concept
The algorithm sorts integers by processing them bit by bit, starting from the least significant bit (LSB) to the most significant bit (MSB). For each bit position, numbers are distributed between stacks based on the bit value (0 or 1).

#### Implementation Steps

1. **Bit Analysis**: Determine the maximum number of bits needed
2. **Bit Processing**: For each bit position (0 to max_bits):
   - Check each number's bit at current position
   - Move numbers with bit = 0 to stack B
   - Keep numbers with bit = 1 in stack A
   - Move all numbers back from B to A
3. **Completion**: After processing all bits, stack A is sorted

### Optimization Techniques

#### Bit Manipulation Efficiency
- Direct bit testing using bitwise operations
- Efficient bit extraction: `(number >> bit_position) & 1`
- Minimal computational overhead per comparison

#### Operation Minimization
- Strategic use of rotate vs push operations
- Optimal stack management to reduce total operations
- Elimination of unnecessary movements

#### Input Preprocessing
- Number normalization to reduce bit requirements
- Duplicate detection and handling
- Input validation and error management

## Implementation Architecture

### Core Components

#### Stack Management
- Dynamic stack implementation with linked lists
- Efficient push/pop operations
- Stack size tracking and validation
- Memory management for stack operations

#### Operation Engine
- Implementation of all 11 required stack operations
- Operation logging for output generation
- Optimization detection for combined operations (ss, rr, rrr)
- Operation validation and error checking

#### Radix Sort Engine
- Bit analysis and maximum bit calculation
- Iterative bit processing loops
- Stack coordination for sorting process
- Performance monitoring and optimization

#### Input Processing
- Command-line argument parsing
- Number validation and duplicate detection
- Error handling for invalid inputs
- Input preprocessing and normalization

### Performance Characteristics

#### Operation Count Analysis
- **3 numbers**: ≤ 3 operations
- **5 numbers**: ≤ 12 operations  
- **100 numbers**: ≤ 700 operations (excellent: ≤ 700, good: ≤ 900)
- **500 numbers**: ≤ 5500 operations (excellent: ≤ 5500, good: ≤ 7000)

#### Complexity Metrics
- **Time Complexity**: O(n * log(max_value))
- **Space Complexity**: O(n) for stack storage
- **Operation Complexity**: O(n * log(max_value)) operations generated

## Usage Examples

### Basic Execution
```bash
# Sort a simple sequence
./push_swap 4 67 3 87 23
# Output: series of operations (pb, ra, pa, etc.)

# Sort with checker program
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
# Output: "OK" if correctly sorted, "KO" if not
```

### Performance Testing
```bash
# Test with 100 random numbers
ARG=$(seq 1 100 | sort -R | tr '\n' ' ')
./push_swap $ARG | wc -l
# Should output ≤ 700 operations

# Test with 500 random numbers
ARG=$(seq 1 500 | sort -R | tr '\n' ' ')
./push_swap $ARG | wc -l
# Should output ≤ 5500 operations
```

### Edge Case Testing
```bash
# Already sorted
./push_swap 1 2 3 4 5

# Reverse sorted
./push_swap 5 4 3 2 1

# Single element
./push_swap 42

# Two elements
./push_swap 2 1
```

### Integration with Checker
```bash
# Verify sorting correctness
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4

# Test with large dataset
ARG="4 67 3 87 23 1 45 68 89 12"
./push_swap $ARG | ./checker $ARG
```

## Technical Challenges

### Algorithm Selection
Choosing the optimal algorithm from various sorting approaches (quick sort, merge sort, radix sort) based on the specific constraints and operation set available.

### Operation Optimization
Minimizing the total number of operations while maintaining correctness, requiring deep understanding of each operation's impact on the sorting process.

### Edge Case Handling
Managing various edge cases including already sorted data, reverse sorted data, duplicates, and invalid inputs while maintaining optimal performance.

### Memory Management
Efficient stack implementation and memory usage, ensuring no memory leaks while maintaining high performance.

## Key Challenges & Solutions

### Algorithm Efficiency
- **Challenge**: Achieving optimal operation counts for different input sizes
- **Solution**: Radix sort implementation with bit-level processing for predictable performance

### Stack Coordination
- **Challenge**: Managing two stacks efficiently with limited operations
- **Solution**: Strategic use of stack operations and careful state management

### Performance Scaling
- **Challenge**: Maintaining efficiency as input size increases
- **Solution**: O(n log n) algorithm choice with consistent performance characteristics

### Code Optimization
- **Challenge**: Writing clean, maintainable code while maximizing performance
- **Solution**: Modular architecture with specialized functions for each component

## Skills Demonstrated

- **Algorithm Analysis**: Deep understanding of sorting algorithms and complexity analysis
- **Optimization Techniques**: Creating highly efficient solutions under strict constraints
- **Data Structure Mastery**: Advanced stack manipulation and management
- **Problem Solving**: Breaking down complex algorithmic challenges into manageable components
- **Performance Engineering**: Creating solutions that scale efficiently with input size
- **Code Architecture**: Building modular, maintainable code for complex algorithms
- **Testing Methodologies**: Comprehensive testing across various input scenarios and edge cases

## Applications and Extensions

The concepts learned in push_swap apply to numerous real-world scenarios:
- **Database Query Optimization**: Understanding operation costs and optimization
- **Compiler Design**: Instruction optimization and register allocation
- **Network Routing**: Efficient path finding with constrained operations
- **Game Development**: AI decision making under resource constraints
- **System Programming**: Memory-efficient algorithm implementation

## Notes

The push_swap project represents a significant milestone in algorithmic thinking and optimization. It demonstrates the ability to work within constraints while achieving optimal performance, a skill essential in systems programming and performance-critical applications.

The choice of radix sort showcases understanding of algorithm selection based on specific problem constraints rather than general-purpose solutions. This project-specific optimization approach is crucial for real-world software development where constraints often dictate algorithm choice.

The project emphasizes that elegant solutions often come from understanding the problem domain deeply and choosing algorithms that work optimally within the given constraints, rather than applying generic solutions.

---

*Developed as part of the École 42 curriculum - mastering algorithmic thinking and optimization through constraint-based problem solving.*
