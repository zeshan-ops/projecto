# Projecto Flow Diagram
<center>

![Flow diagram](../../assets/projectoFlowDiagram.png)

</center>

---
*Diagram Key:* The boxes in the above diagram are colour-coded to roughly match what part of the architecture they fall under. This is an indicator of which part of the codebase these steps will call on.
- Grey box: initial program call
- Yellow boxes: controller
- Blue box: model 
- Teal boxes: data
- Blue/teal boxes: model + data
- Green boxes: view

> Note:
>
> The controller is responsible for handling the logic and instructions to go from one step to the next (shown by arrows in the diagram)
---

## Elaboration
When projecto is called, there are three common first steps.
1. Parsing the command line arguments, separating the command name and its modifiers
    - Identifying the command from `argv[1]` by comparing it to a list of possible commands
        - If the command has no matches, output error message: command unrecognised
    - Copying `argv[2+]` into a vector of strings
2. Initialising the program (setting the focused project and data file path)
    - Reading the initialisation file and setting the appropriate variable values
3. Choosing the appropriate command
    - Passing the command and the parameters to a command chooser which creates the appropriate command object
    - Command object verifies the parameter syntax
        - If the paramater syntax is incorrect, output error message
    - Execute the command.

There are then three groupings of command type, A, B and C. These are grouped because they have similar steps to follow.



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
- Changing the data file storage path
- Changing the focused project




