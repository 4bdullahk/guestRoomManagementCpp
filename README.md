# Guest Room Management System

A **C++ console-based Guest Room Management System** built to demonstrate practical **Data Structures & Algorithms (DSA)** concepts using a **Doubly Linked List** and **Stack**.

The system manages room allocations and guest records while providing searching, editing, deletion, undo functionality, and operation logging.

## Features

* 🏨 **Room Allocation**

  * Insert rooms at the end
  * Insert rooms at a specific position

* ✏️ **Guest Management**

  * Edit guest information
  * Display all allocated rooms

* 🔍 **Room Search**

  * Search for a room by room number
  * Check room availability

* 🗑️ **Room Deletion**

  * Delete allocated rooms
  * Automatically save deleted records for undo

* ↩️ **Undo Delete**

  * Restore the most recently deleted room using a **Stack**

* 📋 **Operation Logs**

  * Track room insertion, editing, and deletion operations

## DSA Concepts Used

| Concept                       | Usage                                 |
| ----------------------------- | ------------------------------------- |
| **Doubly Linked List**        | Stores and manages room/guest records |
| **Stack**                     | Implements undo functionality         |
| **Linear Search**             | Finds rooms by room number            |
| **Dynamic Memory Allocation** | Creates and deletes nodes dynamically |
| **Pointers**                  | Links nodes using `next` and `prev`   |
| **Insertion & Deletion**      | Manages room records dynamically      |

## Tech Stack

* **Language:** C++
* **Data Structures:** Doubly Linked List, Stack
* **Concepts:** Pointers, Dynamic Memory Allocation, Searching, Insertion, Deletion

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git
```

### 2. Navigate to the project

```bash
cd Guest-Room-Management-System
```

### 3. Compile

Using `g++`:

```bash
g++ main.cpp -o guest-room-system
```

### 4. Run

**Windows:**

```bash
guest-room-system.exe
```

**Linux/macOS:**

```bash
./guest-room-system
```

## Menu

```text
==============================
  Guest House Management
==============================
1. Allocate Room
2. Edit Guest Info
3. Display All Rooms
4. Search Room
5. Delete Room
6. Undo Last Delete
7. Show Logs
8. Exit
```

## Project Structure

```text
Guest-Room-Management-System/
│
├── main.cpp
└── README.md
```

## Learning Objective

This project was developed to apply **DSA concepts to a practical real-world scenario**, with particular focus on linked-list manipulation, pointer management, dynamic memory allocation, and implementing an **undo operation using a stack**.

---

**C++ | Data Structures & Algorithms | Doubly Linked List | Stack | Pointers**
