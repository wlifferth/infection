./exactInfection testCases/userFile1.txt testCases/connectionFile1.txt 3 02 > tmp
if ! cmp tmp testCases/correctSTDOUT1.txt >/dev/null 2>&1
then
    echo "TEST CASE 1 FAILED"
    echo "Test output can be found in tmp"
    echo "Correct output can be found in testCases/correctSTDOUT1.txt"
    exit
fi

./exactInfection testCases/userFile2.txt testCases/connectionFile2.txt 5 02 > tmp
if ! cmp tmp testCases/correctSTDOUT2.txt  >/dev/null 2>&1
then
    echo "TEST CASE 2 FAILED"
    echo "Test output can be found in tmp"
    echo "Correct output can be found in testCases/correctSTDOUT2.txt"
    exit
fi

./exactInfection testCases/userFile3.txt testCases/connectionFile3.txt 7 02 > tmp
if ! cmp tmp testCases/correctSTDOUT3.txt >/dev/null 2>&1
then
    echo "TEST CASE 3 FAILED"
    echo "Test output can be found in tmp"
    echo "Correct output can be found in testCases/correctSTDOUT3.txt"
    exit
fi

./exactInfection testCases/userFile4.txt testCases/connectionFile4.txt 3 03 > tmp
if ! cmp tmp testCases/correctSTDOUT4.txt >/dev/null 2>&1
then
    echo "TEST CASE 4 FAILED"
    echo "Test output can be found in tmp"
    echo "Correct output can be found in testCases/correctSTDOUT4.txt"
    exit
fi

./exactInfection testCases/userFile5.txt testCases/connectionFile5.txt 7 02 > tmp
if ! cmp tmp testCases/correctSTDOUT5.txt >/dev/null 2>&1
then
    echo "TEST CASE 5 FAILED"
    echo "Test output can be found in tmp"
    echo "Correct output can be found in testCases/correctSTDOUT5.txt"
    exit
fi

./exactInfection testCases/userFile6.txt testCases/connectionFile6.txt 8 03 > tmp
if ! cmp tmp testCases/correctSTDOUT6.txt >/dev/null 2>&1
then
    echo "TEST CASE 6 FAILED"
    echo "Test output can be found in tmp"
    echo "Correct output can be found in testCases/correctSTDOUT6.txt"
    exit
fi

rm tmp
echo "ALL TEST CASES PASSED"


