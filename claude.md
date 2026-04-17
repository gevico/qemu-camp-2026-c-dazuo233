# QEMU Camp C Exercises - OpenCode Agent Guide

## Project Overview
This is a C programming training repository with **20 basic stage exercises (01-20)**. Each exercise has:
- Source code in `exercises/XX_name/XX_name.c` (NEEDS IMPLEMENTATION)
- Test file in `tests/test_XX_name.c` (READ ONLY - defines requirements)
- A `// I AM NOT DONE` marker that must be removed when complete

## Workflow for Each Exercise

### Step 1: Identify the Exercise
- Use `make list` to see all exercises and their completion status
- Or check `exercises/` directory for available exercises

### Step 2: Read the Test File (CRITICAL)
**ALWAYS read the test file first** to understand requirements:
```bash
# Example for exercise 01
cat tests/test_01_insert_sort.c
```
The test file shows:
- What the program should output
- What assertions must pass
- Input/output format expectations

### Step 3: Read the Exercise Source
```bash
# Example for exercise 01
cat exercises/01_insert_sort/01_insert_sort.c
```
Look for:
- `// TODO` comments indicating where to add code
- `// I AM NOT DONE` marker that must be removed
- Function signatures that need implementation

### Step 4: Implement the Solution
Edit the exercise source file:
```bash
# Example: edit exercises/01_insert_sort/01_insert_sort.c
```
- Implement all TODO functions
- Ensure the program compiles with `gcc -Wall -Wextra -std=c11`
- **Remove the `// I AM NOT DONE` line when complete**

### Step 5: Test Locally
```bash
# Test a single exercise
make check 01
# OR with full name
make check 01_insert_sort

# Test all exercises
make check-all
```

### Step 6: Run the Program (Optional)
```bash
# Compile and run a specific exercise
./run.sh 01_insert_sort
```

### Step 7: Move to Next Exercise
Repeat steps 2-6 for the next exercise.

---

## Key Files Reference

| File/Directory | Purpose | Read/Write |
|---------------|---------|------------|
| `exercises/XX_name/XX_name.c` | Exercise source - **IMPLEMENT HERE** | WRITE |
| `tests/test_XX_name.c` | Test specifications - **READ ONLY** | READ |
| `checker/test_framework.h` | Test framework headers | READ |
| `checker.c` | Checker source (compiles to `c-checker`) | READ |
| `Makefile` | Build commands | READ |
| `run.sh` | Helper to compile and run exercises | READ |

---

## Important Rules

1. **NEVER modify test files** (`tests/test_*.c`) - they define the requirements
2. **NEVER modify checker files** (`checker/`, `checker.c`) - they run the tests
3. **ALWAYS remove `I AM NOT DONE`** marker when exercise is complete
4. **ALWAYS read test file first** before implementing
5. **Test locally** with `make check XX` before considering done

---

## Common Commands

```bash
# Build the checker
make c-checker

# List all exercises with status
make list

# Get hints for an exercise
make hint 01

# Check specific exercise
make check 01

# Check all exercises
make check-all

# Clean build artifacts
make clean

# Watch mode (auto-rebuild on changes)
make watch
```

---

## Exercise List (01-20 Basic Stage)

| # | Exercise | Topic |
|---|----------|-------|
| 01 | insert_sort | Insertion sort |
| 02 | merge_sort | Merge sort |
| 03 | quick_sort | Quick sort |
| 04 | linear_search | Linear search |
| 05 | binary_search | Binary search |
| 06 | stack_maze | Stack-based maze solver |
| 07 | queue_maze | Queue-based BFS maze solver |
| 08 | circular_queue | Circular queue (Josephus problem) |
| 09 | word_counter | Word count |
| 10 | my_strcpy | String copy implementation |
| 11 | command_interpreter | Simple command interpreter |
| 12 | student_management | Student info management |
| 13 | universal_sorter | Generic sorting interface |
| 14 | calculator | Arithmetic calculator |
| 15 | url_parser | URL parameter parser |
| 16 | mysed | Simple stream editor |
| 17 | myfile | ELF file header viewer |
| 18 | mywc | Word frequency counter |
| 19 | mytrans | Dictionary translator |
| 20 | mybash | Command interpreter project |

### Categories
- **01-05**: Sorting and searching algorithms
- **06-08**: Stack, queue, circular queue
- **09-10**: String operations
- **11-15**: File I/O and parsing
- **16-20**: System tools (sed, wc, bash)

---

## Example Session

```bash
# 1. List exercises
make list

# 2. Read test to understand requirements
cat tests/test_01_insert_sort.c

# 3. Read current source
cat exercises/01_insert_sort/01_insert_sort.c

# 4. Edit the source (implement insertion_sort, remove I AM NOT DONE)
# ... edit exercises/01_insert_sort/01_insert_sort.c ...

# 5. Test
make check 01

# 6. If passed, move to next
cat tests/test_02_merge_sort.c
```

---

## Success Criteria

An exercise is complete when:
1. All TODO functions are implemented
2. `I AM NOT DONE` marker is removed
3. `make check XX` shows all tests passing
4. Program compiles without errors/warnings

---

## Notes for OpenCode Agent

- Always check `make list` first to see current progress
- Read test files carefully - they contain the exact requirements
- Some exercises have additional files (data files, headers) in their directory
- Exercise 20 (mybash) has a different structure with `src/` subdirectory
- Some exercises (16-20) have their own Makefiles
