# Software Architecture Design
This project is built on the MVC architecture pattern. I chose this because it would help unit-testing, maintenance and future extensions. It also just makes sense for this type of application.

## Model
A project needs to be able to have tasks and log entries (with the last log entry functioning as a **"last action**"). The model will therefore have project objects that act as containers of tasks and log entries.

To reduce the coupling of the project object to its aggregated objects, when editing one of them that corresponds to that project, it will be done by replacing the entire object. This way the project object does not care what the objects are, only that they exist.

Communication with the project object is therefore based entirely around adding, deleting, replacing or returning the tasks and log entries it stores. To get information about the specific aggregated objects, communication with the objects directly will be used.

![](../../assets/modelUmlDiagram.png)


### Data
Data storage will be done, for now, using the json format with the help of the [Nlohmann JSON Library](https://github.com/nlohmann/json). A single json file will store all the projects. The storage will mimic the model, i.e. a json project is an object that contains lists of task and log json objects. 

A dataReading object will read the json storage file and convert it into model object inputs. The public method returns a Project object.

Expanding or changing any of the model objects would require editing the code for the dataReading object, but the usage of the object throughout the code would be unchanged.

A dataWriting object will take Project as an input, convert it to json format and write it to the storage file. Again, changes to the model would require changes to this object but the usage of it is unchanged.

The data reading and writing process is coupled, therefore, to the model, but I think this is the best approach for now.


> Note: 
>
> The model could have be reconstrued to use json objects directlty using the library, but I decided against this to make a switch to a different data storage format in future easier to do.

## View
There needs to be the following views in the project:

- All project overview: list of project names + the number of tasks for each project
- Individual project overview: list of project tasks and the last action of the project (the last log entry)
- Individual log view: view a single log entry
- Individual task view: full text of a task
- Full log view: view the entire log of the project
- Messages printed to the terminal after the success/failure of a command input

The view will be restricted to a max width of 80 characters per line (to match the 80 character/line code readability guide). ANSI sequences will be used for text formatting - this restricts the program to working only on terminals that support these sequences, in future I may shift to using a library such as [CPP Terminal](https://github.com/jupyter-xeus/cpp-terminal), but for now the terminals I will be using have full support for ANSI sequences.

> Note:
>
> The colour formatting could be made optional depending on whether the terminal supports it I think, I have seen something like this in the [Taskwarrior](https://github.com/GothenburgBitFactory/taskwarrior) source code.

The view will not interface directly with the model, but will take vector/string/int inputs and display them. The controller will be responsible for passing this data to the view when calling it.

## Controller
The controller will take user inputs and transform them into model and view commands. Command line argument parsing will be its own module, I will code this from scratch rather than use a library to make it as lightweight as possible and also because the options are simple.


