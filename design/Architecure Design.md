I think the most sensible thing to do (that I've come across thus far) is to take the Model-View-Controller (MVC) approach. Unless research indicates a speed issue, I think for the model, I will use vectors that store custom struct types. The view will be handled by some fancy std::cout commands. The controller will be designed to be efficient and minimal.

## Program Requirements
- Store all of the data in txt file (or similar, maybe JSON, or maybe a database?) and automatically read and write to it.
- An overview of all current projects
- A unique view for each individual project
- Add, modify and delete tasks to a project
- Add, modify and delete projects
- Add notes to projects
- Add a last action note to projects
- Tasks should have urgency/importance rating and due date and a description, maybe also some filters

## Model
**Data-storage:** txt file (SQLite DB in future)

**Project Object:**
```
class Project {
	std::vector tasks<task>;
	std::vector notes<note>;
	std::string lastAction;
	std::string description[];

	constructor();

	void addTask();
	void deleteTask();

	void addNote();
	void deleteNote();
}
```

**Task Object:**
```
struct Task {
	std::string taskText;
	int urgency;
	int dueDate; // or datetype date
	std::string tags[];

	editTaskText();
	editTaskUrgency();
	editTaskDueDate();
	deleteTag();
	addTag();
}
```

**Note Object:**
```
struct Note {
	std::string noteText;

	editNoteText();
}
```


## View


## Controller
