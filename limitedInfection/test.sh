./limitedInfection testCases/userFile1.txt testCases/connectionFile1.txt 4 02 > tmp
if ! cmp tmp testCases/correctSTDOUT1.txt >/dev/null 2>&1
then
    echo "TEST CASE 1 FAILED"
    echo "Test output can be found in tmp"
    echo "Correct output can be found in testCases/correctSTDOUT1.txt"
    exit
fi

./limitedInfection testCases/userFile2.txt testCases/connectionFile2.txt 5 02 > tmp
if ! cmp tmp testCases/correctSTDOUT2.txt  >/dev/null 2>&1
then
    echo "TEST CASE 2 FAILED"
    echo "Test output can be found in tmp"
    echo "Correct output can be found in testCases/correctSTDOUT2.txt"
    exit
fi

./limitedInfection testCases/userFile3.txt testCases/connectionFile3.txt 7 02 > tmp
if ! cmp tmp testCases/correctSTDOUT3.txt >/dev/null 2>&1
then
    echo "TEST CASE 3 FAILED"
    echo "Test output can be found in tmp"
    echo "Correct output can be found in testCases/correctSTDOUT3.txt"
    mv tmp testSTDOUT3.txt
    exit
fi

./limitedInfection testCases/userFile4.txt testCases/connectionFile4.txt 8 03 > tmp
if ! cmp tmp testCases/correctSTDOUT4.txt >/dev/null 2>&1
then
    echo "TEST CASE 4 FAILED"
    echo "Test output can be found in tmp"
    echo "Correct output can be found in testCases/correctSTDOUT4.txt"
    mv tmp testSTDOUT4.txt
    exit
fi
rm tmp
echo "ALL TEST CASES PASSED"

