# Projecto Command List

## View Commands

```
    projecto                        // single focused project overview
    projecto projects               // overview of all projects
    projecto view <task|log> <id>   // show the details of the specified task or log
    projecto view tasks             // shows full text of all tasks
    projecto view logs              // shows full project log (truncated)
```

## Manipulation commands

```
    // TASKS
    projecto addTask "<TASK TEXT>" [due:<dueDate>] [urg:<L,M,H>]
    projecto editTask <ID> [text:"<NEW TEXT>"] [due:<YYYY-MM-DD>] [urg:<L,M,H>]
    projecto deleteTask <ID>
    projecto complete <ID>

    // LOG
    projecto addLog "<LOG TEXT>"
    projecto deleteLog <id>

    // PROJECT META
    projecto setName "<NEW PROJECT NAME>"
    projecto deleteProject <id>
    projecto newProject "<NEW PROJECT NAME>"
    projecto setProject "<PROJECT NAME>"
    projecto setDataPath "<FILEPATH>"
```

## Other commands

```
    projecto -h                     // shows help screen
    projecto -v                     // shows version number
```
---
> ## Key
>Words unenclosed by angular or square brackets are necessary for their commands. Words enclosed in angular brackets are necessary options the user must specify. Square bracket enclosures indicate optional arguments. Speech marks must be used where they appear.
>
>For a task, due date must be in the format XXXX-XX-XX, and the urgency must be one of L, M or H.

---