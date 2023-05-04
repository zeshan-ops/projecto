# Software Architecture Design
This project is built on the MVC architecture pattern. I chose this because it would help unit-testing and make implementing new features or new projects based on this one much easier. I am using TDD to develop this project, information about testing can be found here: [Testing](testing.md)

## Model
- [Model architecture](model.md)


## View
- [View architecture](view.md)
The output to the terminal needs to be neat, simple and readable. There are to be different views:
- Brief project overview
- Detailed project view
- Brief tasks overview
- Detailed tasks view
- Brief notes overview
- Detailed notes view
- Individual task view
- Individual note view
- Last action view

All tasks and notes should have their corresponding data shown. There should also be a filtering option for tasks by property - i.e. by urgency or by dueDate

The principle of the view code will be for individual functions/classes to generate the view text, then pass the view text to an outputter that displays it.

## Controller
- [Controller architecture](controller.md)