# Software Architecture Design
This project is built on the MVC architecture format. I chose this because it would help unit-testing and make implementing new features or new projects based on this one much easier.

## Model
### Objects
There are three principle objects, tasks, notes and projects. Tasks and notes exist as their own indepedent classes, composition is used to then create the project objects which contain vectors that store tasks and notes plus some other properties.

The idea is that the project object itself will be the interface, using either methods from itself or methods from the task and note class to perform actions.

### Data storage
For now, data storage will be done using .txt files that store data about one project per file. These files will be read from to populate the project objects and will be written to using the data from the project objects.

Separate classes will be used to read/write from the .txt files. This allows cleaner code than incorporating this functionality directly into the project object, also allows a future shift to using a databse rather than .txt files easier to do.

## View

## Controller
