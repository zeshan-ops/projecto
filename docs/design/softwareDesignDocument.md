# Projecto Software Design Document
This document outlines the design of Projecto, a simple command line interface project management tool. 

## Table of contents
---
- [Description](#description)
    - [User stories](#user-stories)
    - [Features and functionality](#features-and-functionality)
- [Architecture and design](#architecture-and-design)
    - [Overview](#overview)
    - [Implementation Details](#implementation-details)
- [Testing](#testing)
- [Deployment and maintenance](#deployment-and-maintenance)
---

## Description
Projecto was born out of a desire to easily manage hobby coding projects directly from VS code without switching to another app. The ease of use of github from the terminal prompted me to create this application with a command line interface. This project also serves as way for me to learn more about the entire software design process.

There are two key aspects of project management that I wanted Projecto to be able to handle: task management and keeping a log. Task management is self-explanatory, and I decided that a log was needed because it helps to keep track of progress and remind me of the last action I took on a project, making it easier to be productive on projects that take a while to complete.

### User stories
The target audience are users that want a simple way to manage hobby coding projects. Since I myself am the primary target audience, I will write the user stories centred on my own need cases:

- As a user, I want to have an overview of my project that can show its tasks and a log of actions so that I can easily keep track of my coding exploits.
- As a user, I want to be able to quickly add, edit, delete and view tasks and quickly add, delete and view log entries (I feel that editing log entries serves no purpose for my envisioned use) so that using Projecto is not cumbersome.
- As a user, I want to be able to store multiple projects and access them in such a manner that calling Projecto shows a specific project unless the focused project is changed (i.e., everytime projecto is called, it shows the same project it showed last time unless told otherwise) so that calling projecto is not unecessarily burdensome.
- As a user, I want the terminal output to be aesthetically pleasing so that I enjoy using the tool.
- As a developer, I want to have a robust and flexible codebase so that I can easily extend the feature of Projecto in the future.

### Features and Functionality
To satisfy the [user stories](#user-stories) above, the following features are planned to be implemented for the initial relsease.
- **Tasks**:
    - Each task should have text describing it, optionally a low, medium or high urgency and optionally a due date.
    - Should be able to add, edit, complete and delete tasks from each project.
- **Logs**:
    - Each log should have text and datetime. The datetime should be recorded when the log entry is added to the project.
    - Should be able to add and delete logs from each project.
- **Terminal output**:
    - When multiple tasks are output to the terminal, they should be sorted by date, then by priority, then no preference.
    - A view that shows an overview of all projects. The names of each project, the number of outstanding tasks it has and its last action (final log entry).
    - A view that shows an overview of a single project. The name of the project, the outstanding tasks, their priorities and due dates, and the last action taken on the project.
    - A view that shows the details of a single task. The full text of the task, its priority and its due date.
    - A view that shows the details of a log entry. The full text of the log entry and its datetime.
    - A view that shows all the tasks of a single project. Pending and completed tasks with full text, priorities and due dates.
    - A view that shows all the log entries of a single project. All log entires, truncated and with their datetime.
    - Messages printed to terminal whenever a command is executed, e.g. `Added task`.
- **Other**:
    - Ability to change the *focused project*. There should be a command that allows the user to change which project they want to view and edit. The change should be persistent so that Projecto always loads the same project it did on its previous call unless commanded otherwise by the user.

## Architecture and design

### Overview
Projecto is based on the MVC architectural design pattern. The *flavour* of MVC followed can be seen in the diagram below. The controller deals with user commands and then communicates with both the view and model appropriately. This decouples the view entirely from the model, making the system more robust and flexible. The data file handling will be included in the model part of the codebase.

<div align=center>

<img src="../../assets/MVC Diagram.png" width="600">

***(MVC Diagram)***

</div>

### Implementation Details

#### Model + Data
There are four key objects in the model + data part of the codebase:

1. `Project`
2. `Task`
3. `Log`
4. `jsonDataInterface`

The `Project` object is an aggregration of `Task` and `Log` objects, essentially functioning as a container for them. Vectors will be used to store the tasks and log entries, making adding, deleting and editing them easy.

When editing a task that belogns to a project, the entire `Task` object will be replaced by a new one inside the `Project` object. This means that the `Project` object does not need to access methods from the `Task` class, reducing coupling.


The data will be stored in JSON format with the help of the [Nlohmann JSON](https://github.com/nlohmann/json) library. This library could have been used to construct the model too, but I chose to use a separate implementation in case I changed the data storage method in future. This will be handled by the `jsonDataInterface` object.

The `jsonDataInterface` object is the most complex object in the model. It will act as a container of the application's data when the program runs: reading the data upon initialisation and copying it into a member variable, editing the copied data, and then rewriting it back to the data file. This object will also be able to convert a `Project` object into JSON format.


<div align=center>

<img src="../../assets/projectoModelClassDiagram.png" width = 600>

***(Model + Data Class Diagram)***

</div>

#### View
There must be the following views available in the terminal:

- All project overview: list of project names + the number of tasks for each project
- Individual project overview: list of project tasks and the last action of the project (the last log entry)
- Individual log view: view a single log entry
- Individual task view: full text of a task
- Full task view: full task text + completed tasks
- Full log view: view the entire log of the project
- Messages printed to the terminal after the success/failure of a command input

The view will be restricted to a max width of 80 characters per line (to match the 80 character/line code readability guide). ANSI sequences will be used for text formatting - this restricts the program to working only on terminals that support these sequences.

Each unique view will have its own object which has a single public render function. These view objects will have no knowledge of the model at all. They will take vector, string, int etc inputs. This is to decouple them entirely from the model which makes the code more involved but improves robustness and flexibility.

<div align=center>

<img src="../../assets/projectoViewClassDiagram.png" width = 600>

***(View Class Diagram)***

</div>



#### Controller
The controller is responsible for taking user input, parsing it, verifying it and then communicating with the model + data and view to perform the appropriate actions.

The commands of Projecto can be split into three categories which follow similar steps:

**Group A**:
The commands in this group are:
- Adding, editing, completing or deleting a task
- Adding or deleting a log entry
- Viewing project overview
- Viewing all project tasks
- Viewing all project logs
- Viewing individual project task
- Viewing individual project log

**Group B**:
The commands in this group are:
- Adding a new project
- Deleting an existing project
- Changing the name of an existing project
- Viewing all projects overview

**Group C**:
The commands in this group are:
- Changing the focused project

This program flow diagram elucidates how the different parts of the system are envisioned to work together:

<div align=center>

<img src="../../assets/projectoFlowDiagram.png" width = 600> 

***(Program flow diagram)***

</div>

## Testing
Projecto will be unit-tested and integration tested. The [Doctest](https://github.com/doctest/doctest) header-only library will be used for testing. The development process will be similar to TDD without rigidly sticking to the requirement of writing test cases before code. I have found that sometimes a first draft of a unit of code is useful in elucidating the syntax the code will use and its necessary test cases. Generally, code will be written in small units, tested and refactored before developing the next part of the codebase.

Code coverage will also be measured using gcov with [Gcovr](https://github.com/gcovr/gcovr) providing the coverage reports. The aim is to get as high a branch coverage as possible, though I anticipate this being difficult due to C++ throw branches.

## Deployment and maintenance
Projecto will make use of continuous integration (CI) during development and after initial release. Github actions will be used to implement the CI.

After the initial release, semantic versioning will be used for the application and a roadmap of future features will be created.