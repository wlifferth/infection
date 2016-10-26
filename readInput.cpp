#ifndef _READINPU_CPP_IS_DEFINED_
#define _READINPU_CPP_IS_DEFINED_

#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include "userNode.h"

using namespace std;

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

#endif
