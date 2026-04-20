# Data Structures & Algorithms Homeworks

Homework assignments for EE441 Data Structures course, implemented in C++.

## Assignments

### HW1 — Course and Student Management System

Manages students and their grades within a course.

- Stores student info: ID, name, quiz scores (×4), homework scores (×3), and a final exam score
- Supports adding/searching students and updating scores
- Calculates weighted final grades (Quiz 30% / Homework 30% / Final 40%)
- Filters students by a score threshold

**Key concepts:** Classes, arrays, basic OOP

---

### HW2 — Section Registration with Stack and Queue

Simulates a class registration system where students are assigned to sections or placed on a waiting list.

- `Section_Stack`: Stack-based structure with a fixed capacity for enrolled students
- `WaitingQueue`: Queue (up to 100 students) for overflow registrations
- Assigns students to sections based on availability and day preferences

**Key concepts:** Stack, Queue, priority-based assignment

---

### HW3 — Process Scheduling: Linked List vs. BST

Compares two data structures for managing OS-style process scheduling.

- `Linked_List_Schedular`: Singly linked list with O(n) insertion and search
- `BST`: Binary Search Tree offering faster lookup on larger datasets
- Tested against datasets of 100, 500, and 1000 processes
- Each process has an ID, arrival time, run time, and priority

**Key concepts:** Linked List, Binary Search Tree, performance comparison

---

## Structure

Each homework follows the same layout:

```text
e2307320_HWx/
├── include/   # Header files
├── src/       # Implementation files
└── main.cpp   # Entry point
```

## Build

Projects are configured for [Code::Blocks](https://www.codeblocks.org/) (`.cbp` files included). You can also compile manually with any C++ compiler:

```bash
g++ -o main main.cpp src/*.cpp -Iinclude
```
