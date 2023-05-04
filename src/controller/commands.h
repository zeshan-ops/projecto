enum command {
    addTask,
    editTask,
    deleteTask,

    addNote,
    editNote,
    deleteNote,

    editProjectName,
    editProjectDescription,
    editLastAction,

    projectView
};

void commandParser(int argc, char* argv[]);