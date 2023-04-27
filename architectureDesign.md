# Software Architecture Design
This project is built on the MVC architecture format. I chose this because it would help unit-testing and make implementing new features or new projects based on this one much easier.

## Model
### Objects
There are three principle objects, tasks, notes and projects. Tasks and notes exist as their own indepedent classes, composition is used to then create the project objects which contain vectors that store tasks and notes plus some other properties.

The idea is that the project object itself will be the interface, using either methods from itself or methods from the task and note class to perform actions. All data is assumed to be of correct form when accessing the model, checks on user inputs and correctness of stored data will take place in the controller and the data utility parts of the program.

### Data storage
For now, data storage will be done using JSON files. These files will be read from to populate the project objects and will be written to using the data from the project objects.

The [Nlohmann JSON library](https://github.com/nlohmann/json) will be used to parse JSON data to and from the files, with extra functions then being used to pass this data to and from the project object. I suppose that this data storage aspect could be included in the controller part of the architecture, but I think it fits just as well here too.

## View

## Controller
