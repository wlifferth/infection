#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include "../userNode.h"
#include "../readInput.cpp"

using namespace std;

//void readInput(map<int, userNode*>& users, string userFilename, string connectionsFilename);
void cleanup(map<int, userNode*> users);
void printUserMap(map<int, userNode*> users);
void recursiveInfect(userNode* user, int version);

int main(int argc, char** argv)
{
    char buffer[1000];
    string userFile;
    string connectionFile;
    int userID;
    int newVersion;
    // maps userID numbers to userNode pointers
    map<int, userNode*> users;
   
    // Lets get that command line input!
    if(argc != 5)
    {
        printf("USAGE: userFile connectionFile userID newVersion");
        exit(1);
    }
    sscanf(argv[1], "%s", buffer);
    userFile = buffer;
    sscanf(argv[2], "%s", buffer);
    connectionFile = buffer;
    sscanf(argv[3], "%d", &userID);
    sscanf(argv[4], "%d", &newVersion);
    
    // Now that we know where stuff is we can grab the data and put it gently into our users map
    readInput(users, userFile, connectionFile);

    printf("BEFORE INFECTION\n\n");
    printUserMap(users);
    recursiveInfect(users[userID], newVersion);
    printf("\n\n\n");
    printf("AFTER INFECTION\n");
    printf("User %0.4d was updated to version %0.2d, and everone connected to that user was upgraded as well\n\n", userID, newVersion);
    printUserMap(users);

    cleanup(users);
    return 0;
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
