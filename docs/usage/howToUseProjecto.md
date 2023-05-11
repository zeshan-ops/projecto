# How to use Projecto

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
    projecto setProject "<PROJECT NAME>"   // sets the focused project

    // TASKS
    projecto addTask "<TASK TEXT>" [due:<dueDate>] [urg:<L,M,H>]
    projecto editTask <ID> [text:"<NEW TEXTt>"] [due:<XXXX-XX-XX>] [urg:<L,M,H>]
    projecto deleteTask <ID>

    // NOTES
    projecto addLog "<LOG TEXT>"
    projecto deleteLog <ID>

    // LOG
    projecto addLog "<LOG TEXT>"
    projecto deleteLog <id>

    // PROJECT META
    projecto setName "<NEW PROJECT NAME>"
    projecto deleteProject <id>
    projecto newProject "<NEW PROJECT NAME>"
```

## Other commands

```
    projecto -h                     // shows help screen
    projecto -v                     // shows version number
```