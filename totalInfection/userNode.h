#include <string>
#include <vector>

using namespace std;

class userNode
{
    public:
        userNode(int userID, string userName, int version);
        // Returns 0 for success, 1 for no change (if the given value already exists there)
        int addTeacher(userNode* teacher);
        int addStudent(userNode* student);
        int infect(int newVersion);
        int visit();
        // Getter functions
        vector<userNode*> getTeachers();
        vector<userNode*> getStudents();
        int getUserID();
        string getUserName();
        int getVersion();
        bool getVisited();
    private:
        int userID;
        string userName;
        int version;
        bool visited;
        vector<userNode*> teachers;
        vector<userNode*> students;
};
