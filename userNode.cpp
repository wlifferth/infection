#include <string>
#include <vector>
#include "userNode.h"

using namespace std;

userNode::userNode(int userIDIn, string userNameIn, int versionIn)
{
    userID = userIDIn;
    userName = userNameIn;
    version = versionIn;
    visited = false;
    setID = -1;
    return;
}

int userNode::addTeacher(userNode* teacher)
{
    int i;
    for(i = 0; i < teachers.size(); i++) if(teachers[i] == teacher) return 1;
    teachers.push_back(teacher);
    return 0;
}

int userNode::addStudent(userNode* student)
{
    int i;
    for(i = 0; i < students.size(); i++) if(students[i] == student) return 1;
    students.push_back(student);
    return 0;
}

int userNode::infect(int versionIn)
{
    if(version == versionIn) return 1;
    version = versionIn;
    return 0;
}

int userNode::visit()
{
    if(visited) return 1;
    visited = true;
    return 0;
}

int userNode::changeSetID(int setIDIn)
{
    if(setID == setIDIn) return 1;
    setID = setIDIn;
    return 0;
}

vector<userNode*> userNode::getTeachers()
{
    return teachers;
}

vector<userNode*> userNode::getStudents()
{
    return students;
}

int userNode::getUserID()
{
    return userID;
}

string userNode::getUserName()
{
    return userName;
}

int userNode::getVersion()
{
    return version;
}

bool userNode::getVisited()
{
    return visited;
}

int userNode::getSetID()
{
    return setID;
}
