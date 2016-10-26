# Infection
Interconnected users pose a problem to any platform that needs to A/B test or roll out new features. If different versions are given to two users who are "connected" this could cause confusion and detract from the user experience. This can effectively be modeled as a graph-based "connected component" problem, and each of the three following programs in this repo uses some variation of that paradigm to address the problem in a different way.
Each program (found in the three subdirectories) has its own makefiles, compiling with the g++ compiler. Each program also has a set of test cases. testCases.md contains details about each test case, and the command to run them, and the testCases directory contains the appropriate input and output for each test case. Each program has a test.sh script which runs through all the test cases until one test case fails, then exits with a message about the first test case that failed.

# Total Infection
./totalInfection [user file] [connections file] [target user id] [new version]
Often we may want to give a new version to a specific user. totalInfection.cpp allows the user to input two input files, the ID of a target user to infect, and the new version number to infect them with. It reads in all the data from the input files and models the users as a node-based graph. The program then goes on to do a depth-first traversal of the graph, changing the assigned version to each connected component.
In order to view what changes, totalInfection prints out a text-based representation of the user graph before and after the target user has been infected. The printout will be in the following format:

Name:   brussell        ID: 0001        Version: 01
Students ------------------------------------------
Name:     dtrump        ID: 0004        Version: 01
Name:     jstein        ID: 0006        Version: 01


Name:  wlifferth        ID: 0002        Version: 01
Students ------------------------------------------
Name:   hclinton        ID: 0003        Version: 01
Name:   gjohnson        ID: 0005        Version: 01
Name: rdelafuente       ID: 0008        Version: 01
Name:  emcmullin        ID: 0007        Version: 01

First a user is listed, along with their ID and their Version. Then underneath them all their students and teachers are printed, along with their information. It is easy to verify this program worked by inspecting each block of text; each block of version numbers (the rightmost column) should be homogenous. If this is true and the target user has the new version, the problem is by definition solved.

# Limited Infection
./limitedInfection [user file] [connections file] [target number of users] [new version]
The only problem with the above solution is that depending on how interconnected the target is, the group you end up infecting may be too big or too small. Ideally we'd be able to say "I want no more than X users to get the new version so we can test it out". limitedInfection.cpp implements that functionality. Now instead of a target user ID, the user passes in a target number of users to infect.
The program reads in the input, then cycles through each element and uses a type of disjoint set algorithm to define a list of sets. It then uses a greedy algorithm that picks the next largest set that doesn't push the total infect number over the target until we either hit the target, or can't add anymore sets. Then it goes through and infects each of those sets.
The output of limitedInfection is a bit different; it prints out the before and after state of the data, but because we care more about the total number of infected users, the previous format includes a lot of uncessary information. The before state of the data is printed out in the same way, but the after state is printed out with just a single line for each user. To veryify the program worked one could count the number of times the new version number shows up in the rightmost column. It should be noted that this assumes the new version number is actually new--we could input check for that, or even alter it so the behaviour is "X MORE uesrs will be upgraded to version Y" instead of "X users will be on version Y".

# Exact Infection
./exactInfection [user file] [connections file] [target number of users] [new version]
limitedInfection works well, but there are some cases where we might want to infect exactly X number of people, not just close to that amount. That's what exactInfection does. Accepting the same input as limitedInfection, it behaves in much the same way in how it classifies components. The change happens when it decides which components to infect. Instead of utilizing a greedy algorithm like limitedInfection, exactInfection uses a recursive function to iterate over the power set of components, essentially brute-forcing the search space. If it comes across any combination of components that fit our criteria, we then go on to infect those components. If not, we print and error and exit.

# A Word On File Input
The input file format was essentially modeled after a relational database. User files are text files that contain lines of the format
[user id] [user name] [user version]
Connection files are text files that contain lines of the format
[teacher user id] [student user id]
By joining over the user and the connection tables, one could select a list of all one's students or all one's teachers.
