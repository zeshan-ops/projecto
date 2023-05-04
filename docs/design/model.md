# Model architecture
The model of projecto is built on three key objects: tasks, notes and projects. Aggregation is used to build up functionality. Projects contain task and note objects plus a few other personal attributes; methods to do with converting JSON data are also aggregated into the project object.

## Tasks
A task is a custom data type that currently has the following attributes:

```c++
    std::string taskText;
    int urgency;
    int dueDate;
    bool completed;
```

There also getter and setter methods within the `Task` class for encapsulation, helping to ensure that any problems with tasks can be traced back to the task class implementation alone. The object is also easily extensible, new functionality can be added in a single place in the model codebase.

The task object has a constructor that requires `taskText`, `urgency` and `dueDate` to be set, `completed` is set to `false` upon intialisation.

There is also a comparison operator overload defined which is used during unit-testing.

## Notes
A note is a custom data type that current has the following attribute:

```c++
    std::string noteText;
```

The implementation is identical to the `Task` object, just with less features, encapsulation is used etc.

There is a simple constructor that requires `noteText` to be set. 

There is also a comparison operator overload defined which is used during unit-testing.

## Projects
A project is a custom data type that aggregrates the task and note objects by storing vector of tasks and notes. It also has a few other attributes: 

```c++
    std::string projectName;
    std::vector<Task> tasks;
    std::vector<Note> notes;
    std::string lastAction;
    std::string description;
```

There are two constructors for the project class:
- The first is a *manual* constructor, where all attributes must be passed except the `lastAction` which has a default value of `"No last action written"`.
- The second constructor takes JSON input and creates a `Project` object. This is done with methods implemented in a separate utility module.

The second constructor is the main one used for the current program implementation as JSON files are being used for data storage (see [Data Storage](#data-storage)) with the help of the [Nlohmann JSON Library](https://github.com/nlohmann/json). The encapsulation of the project class also means that any future changes to data storage format are easy to implement.

The class also has a method to output its attributes into JSON format (i.e. returning a JSON object that contains the data).


## Data storage
For now, data storage will be done using JSON files. These files will be read from to populate the project objects and will be written to using the data from the project objects.

The [Nlohmann JSON library](https://github.com/nlohmann/json) will be used to parse JSON data to and from the files.