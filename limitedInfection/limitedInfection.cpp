#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include "../userNode.h"
#include "../readInput.cpp"

using namespace std;

// Reads in and parses the input from the two files, and stores all the data in the users map
//void readInput(map<int, userNode*>& users, string userFilename, string connectionsFilename);
// Deletes all the objects we created on the heap
void cleanup(map<int, userNode*> users);
// Prints the map of users; for each user it prints it, all its teachers, and all its students
void printUserMap(map<int, userNode*> users);
// Prints a list of all users; similar to printUserMap except it only prints each user once
void printUsers(map<int, userNode*> users);
// Splits the users into discrete components; returns a vector of setIDs (the first userID in the set) and the respective set sizes
void countSets(map<int, userNode*>& users, vector<int>& setIDs, vector<int>& setSizes);
// Recursive function to group components together; returns the size of the component including this one and past
int recursiveCountSet(map<int, userNode*>& users, int setID);
// Infects users in whole components to get as close as possible without going over the maxUsersInfected argument
void infect(map<int, userNode*>& users, int maxUsersInfected, int newVersion);
// Changes the version of this user and all the users connected to it
void recursiveInfect(userNode* user, int version);

int main(int argc, char** argv)
{
    char buffer[1000];
    string userFile;
    string connectionFile;
    int maxUsersInfected;
    int newVersion;
    // maps userID numbers to userNode pointers
    map<int, userNode*> users;
   
    // Lets get that command line input!
    if(argc != 5)
    {
        printf("USAGE: userFile connectionFile maxUsersInfected newVersion");
        exit(1);
    }
    sscanf(argv[1], "%s", buffer);
    userFile = buffer;
    sscanf(argv[2], "%s", buffer);
    connectionFile = buffer;
    sscanf(argv[3], "%d", &maxUsersInfected);
    sscanf(argv[4], "%d", &newVersion);
    
    // Now that we know where stuff is we can grab the data and put it gently into our users map
    readInput(users, userFile, connectionFile);

    // Print baseline
    printf("BEFORE INFECTION\n\n");
    printUserMap(users);

    infect(users, maxUsersInfected, newVersion);

    printf("\n\n\n");
    printf("AFTER INFECTION\n");
    printUsers(users);

    cleanup(users);
    return 0;
}

void infect(map<int, userNode*>& users, int maxUsersInfected, int newVersion)
{
    int i;
    vector<int> setIDs;
    vector<int> setSizes;
    // Variables for our greedy optimization algorithm
    vector<int> setsToInfect;
    int currentBestFit;
    int currentBestFitSize;
    int totalInfected = 0;
    bool gettingCloser = true;
    // This will count all the components in the users map via a disjoint-set like algorithm
    // The setIDs carries the IDs for each set (which is the userID of the first element in a new set) and at the same index setSizes carries the size of that set
    countSets(users, setIDs, setSizes);

    // I know enough to know that this is a greedy algorithm, but I don't know enough to know how to make it better
    while(gettingCloser)
    {
        // If we run through the entire list without being able to add a new set, then we're done
        gettingCloser = false;
        currentBestFitSize = 0;
        for(i = 0; i < setSizes.size(); i++)
        {
            if(setSizes[i] <= maxUsersInfected - totalInfected && setSizes[i] > currentBestFitSize)
            {
                currentBestFit = i;
                currentBestFitSize = setSizes[currentBestFit];
                gettingCloser = true;
            }
        }
        if(gettingCloser)
        // If we came across a set we could add without going over, we add it to our list
        {
            setsToInfect.push_back(setIDs[currentBestFit]);
            totalInfected += setSizes[currentBestFit];
            setSizes[currentBestFit] = 0;
            setIDs[currentBestFit] = 0;
        }
    }
    if(totalInfected == 0)
    // If we didn't find a single set we could add
    {
        printf("There's no way to infect that few people with out messing up the user experience--try picking a larger maxUsersInfected value.\n");
        exit(1);
    }
    for(i = 0; i < setsToInfect.size(); i++) recursiveInfect(users[setsToInfect[i]], newVersion);

}

int recursiveCountSet(userNode* user, int setID)
{
    if(user->getSetID() != -1) return 0;
    int i;
    vector<userNode*> teachers = user->getTeachers();
    vector<userNode*> students = user->getStudents();
    int size = 1;
    user->changeSetID(setID);
    for(i = 0; i < teachers.size(); i++)
    {
        size += recursiveCountSet(teachers[i], setID);
    }
    for(i = 0; i < students.size(); i++)
    {
        size += recursiveCountSet(students[i], setID);
    }
    return size;
}
    
void countSets(map<int, userNode*>& users, vector<int>& setIDs, vector<int>& setSizes)
{
    map<int, userNode*>::iterator iter;
    int size;
    for(iter = users.begin(); iter != users.end(); iter++)
    {
        size = recursiveCountSet(iter->second, iter->first);
        if(size)
        {
            setIDs.push_back(iter->first);
            setSizes.push_back(size);
        }
    }
    return;
}

void recursiveInfect(userNode* user, int version)
{
    if(user->getVisited()) return;
    vector<userNode*> teachers = user->getTeachers();
    vector<userNode*> students = user->getStudents();
    int i;
    user->visit();
    user->infect(version);
    for(i = 0; i < teachers.size(); i++)
    {
        recursiveInfect(teachers[i], version);
    }
    for(i = 0; i < students.size(); i++)
    {
        recursiveInfect(students[i], version);
    }
    return;
}
/*
void readInput(map<int, userNode*>& users, string userFilename, string connectionsFilename)
{
    char buffer[1000];
    int userID;
    char userNameBuffer[1000];
    string userName;
    int version;
    userNode* newUser;
    int teacherID;
    int studentID;
    // Validate user input
    FILE* userFile = fopen(userFilename.c_str(), "r");
    if(userFile == NULL)
    {
        printf("USAGE: supplied user filename does not exist\n");
        exit(1);
    }
    FILE* connectionFile = fopen(connectionsFilename.c_str(), "r");
    if(connectionFile == NULL)
    {
        printf("USAGE: supplied connection filename does not exist\n");
        exit(1);
    }
    // Now we can go and read input
    // First we'll get all the users from the userFile
    while(fgets(buffer, 1000, userFile))
    {
        // Read in the line
        sscanf(buffer, "%d %s %d", &userID, userNameBuffer, &version);
        // stick the c string in a c++ string
        userName = userNameBuffer;
        // create a userNode object
        newUser = new userNode(userID, userName, version);
        // stick the user into our users map, keyed on userID
        users.insert(make_pair(newUser->getUserID(), newUser));
    }
    // Now we'll get all the connection from connectionsFile
    while(fgets(buffer, 1000, connectionFile))
    {
        // Read in the line
        sscanf(buffer, "%d %d", &teacherID, &studentID);
        // Add the student to the teachers student list
        users[teacherID]->addStudent(users[studentID]);
        // Add the teacher to the students teacher list
        users[studentID]->addTeacher(users[teacherID]);
    }
}
*/
void cleanup(map<int, userNode*> users)
{
    map<int, userNode*>::iterator iter;
    for(iter = users.begin(); iter != users.end(); iter++)
    {
        delete iter->second;
    }
}

void printUserMap(map<int, userNode*> users)
{
    map<int, userNode*>::iterator iter;
    vector<userNode*> teachers;
    vector<userNode*> students;
    int i;
    for(iter = users.begin(); iter != users.end(); iter++)
    {
        printf("Name: %10s\tID: %0.4d\tVersion: %0.2d\n", iter->second->getUserName().c_str(), iter->second->getUserID(), iter->second->getVersion());
        teachers = iter->second->getTeachers();
        if(teachers.size())
        {
            printf("Teachers ------------------------------------------\n");
            for(i = 0; i < teachers.size(); i++) printf("Name: %10s\tID: %0.4d\tVersion: %0.2d\n", teachers[i]->getUserName().c_str(), teachers[i]->getUserID(), teachers[i]->getVersion()); 
        }
        students = iter->second->getStudents();
        if(students.size())
        {
            printf("Students ------------------------------------------\n");
            for(i = 0; i < students.size(); i++) printf("Name: %10s\tID: %0.4d\tVersion: %0.2d\n", students[i]->getUserName().c_str(), students[i]->getUserID(), students[i]->getVersion()); 
        }
        printf("\n\n");
    }
}

void printUsers(map<int, userNode*> users)
{
    map<int, userNode*>::iterator iter;
    vector<userNode*> teachers;
    vector<userNode*> students;
    int i;
    for(iter = users.begin(); iter != users.end(); iter++) printf("Name: %10s\tID: %0.4d\tVersion: %0.2d\n", iter->second->getUserName().c_str(), iter->second->getUserID(), iter->second->getVersion());

}
