# Test Case 1
to run:
./limitedInfection testCases/userFile1.txt testCases/connectionFile1.txt 4 02
Test case 1 is just a basic data set with 2 classes, headed by usernames brussell and wlifferth. Each student only has one teacher, and eacher user is either a teacher or student (no overlap). It's very basic, but it shows that the platform is working; 

# Test Case 2
to run:
./limitedInfection testCases/userFile2.txt testCases/connectionFile2.txt 5 02
Test case 2 is very similar to test case 1, except we're now setting out maxUsersInfected value to 5; this means the class headed by wlifferth (size 5) will now get switched instead of the class headed by brussell (size 3). All this does is give some insight into how the greedy optimization works. 

# Test Case 3
to run:
./limitedInfection testCases/userFile3.txt testCases/connectionFile3.txt 7 02
In this test case 14 users are split into 7 pairs. The max number of users infected is 7, so the first 3 pairs will get infected for a total of 6 users.

# Test Case 4
to run:
./limitedInfection testCases/userFile4.txt testCases/connectionFile4.txt 8 03
This test case feautres a more complex graph 
