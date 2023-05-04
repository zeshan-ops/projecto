command commandParser(int argc, char *argv[]) {
    command inputCommand;
    if(argc <=1) {
        inputCommand = projectView;
        return inputCommand;
    }

    switch(argv[1]) {
        case "addTask":
            try {
                if(argc >= 3) {
                    inputCommand = addTask;
                }
                else {
                    throw 
                }
            }
    }
}