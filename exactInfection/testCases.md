# Test Case 1
to run:
./exactInfection testCases/userFile1.txt testCases/connectionFile1.txt 3 02
Test case 1 is just a basic data set with 2 classes, headed by usernames brussell and wlifferth. Each student only has one teacher, and eacher user is either a teacher or student (no overlap). It's very basic, but it shows that the platform is working; the class headed by brussell contains 3 users, so we should choose to infect that component and leave the other component (taught by wlifferth) alone. 

# Test Case 2
to run:
./exactInfection testCases/userFile2.txt testCases/connectionFile2.txt 5 02
Test case 2 is very similar to test case 1, except we're now setting out maxUsersInfected value to 5; this means the class headed by wlifferth (size 5) will now get switched instead of the class headed by brussell (size 3). All this does is give some insight into how the greedy optimization works. 

# Test Case 3
to run:
./exactInfection testCases/userFile3.txt testCases/connectionFile3.txt 7 02
In this test case 14 users are split into 7 pairs. Because of that we can only infect in even numbers, thereore exactInfection should fail and print out a fail message. 

# Test Case 4
to run:
./exactInfection testCases/userFile4.txt testCases/connectionFile4.txt 3 03
Test exactInfection with multiple starting versions.


# Test Case 5
to run:
./exactInfection testCases/userFile5.txt testCases/connectionFile5.txt 7 02
Tests exactInfection with a larger input.

# Test Case 6
to run:
./exactInfection testCases/userFile6.txt testCases/connectionFile6.txt 8 03
This test case has groups of size 2, 4, 6, and 7. This is significant because this is a scenario in which a greedy algorithm (in either direction) would fail. If we were to select the smallest on each iteration we would choose 2 and then 4, and stop before choosing 6 which would leave us with a total of 6 infected users (suboptimal); if we were to select the largest legal on each iteration we would choose 7, then stop without choosing anything else, leaving us with a total of 7 infected users (suboptimal). The optimal solution is to infect the group of 2 and the group of 6, hitting our goal of 8 infected users exactly.
