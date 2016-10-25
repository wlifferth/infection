# Test Case 1
to run:
`./totalInfection testCases/userFile1.txt testCases/connectionFiles1.txt 0006 02`
Test case 1 is just a basic data set with 2 classes, headed by usernames brussell and wlifferth. Each student only has one teacher, and eacher user is either a teacher or student (no overlap). It's very basic, but it shows that the platform is working; before running it everyone is version 1, and after running it all the users in the class headed by user brussell. 

# Test Case 2
to run:
`./totalInfection testCases/userFile2.txt testCases/connectionFile2.txt 0006 02`
Test case 2 is very similar to test case 1, except each of the students from test case one now has a student of their own (their running mate :P). Although it spits out a lot of text, it's easy to see that everything is in order, because every continuous group of text (representing the users who are connected by a coaching/teaching relationship) will have the same version.

# Test Case 3
to run:
`./totalInfection testCases/userFile3.txt testCases/connectionFile3.txt 0014 02`
Test case 3 is similar to test case 2, except we've introduced cyclical coaching relationships; the new students in case 2 (the VPs) now teach either of the original two teachers (Bertrand Russel or William Lifferth)

# Test Case 4
to run:
`./totalInfection testCases/userFile4.txt testCases/connectionFile4.txt 0003 03`
This one basically runs the gambit. We have several different components, some of which start with a different version. There are orphans (nodes not connected to anything else), as well as users with multiple teachers and/or students. hclinton is updated to 3, and all her connected components update as well.
