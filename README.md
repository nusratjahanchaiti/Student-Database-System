# Student Database System

## Description
This is a simple **Student Database System** written in C using a singly linked list. It allows users to manage student records via a menu-driven console interface.You can add, remove, search, and display student records through a text-based menu.

This was developed as part of my **Data Structures (CSE 207) course project** at university.

## Features
- Add a student (name, roll number, marks)
- Remove a student by roll number
- Search for a student by roll number
- Display all students
- Exit the system

## Data Structures
- `Student`: Struct representing a student record
- `StudentDatabase`: Struct holding the head pointer and student count

## Notes
- Uses dynamic memory (malloc) to store student data.
- Works completely in memory (no file storage).
- Roll numbers are used as unique identifiers.

## How to Compile and Run

```bash
gcc student_db.c -o student_db
./student_db
