./totalInfection testCases/userFile1.txt testCases/connectionFile1.txt 0006 02 > tmp
if ! cmp tmp testCases/correctSTDOUT1.txt >/dev/null 2>&1
then
    echo "TEST CASE 1 FAILED"
    echo "Test output can be found in testSTDOUT1.txt"
    echo "Correct output can be found in testCases/correctSTDOUT1.txt"
    mv tmp testSTDOUT1.txt
    exit
fi

./totalInfection testCases/userFile2.txt testCases/connectionFile2.txt 0006 02 > tmp
if ! cmp tmp testCases/correctSTDOUT2.txt  >/dev/null 2>&1
then
    echo "TEST CASE 2 FAILED"
    echo "Test output can be found in testSTDOUT2.txt"
    echo "Correct output can be found in testCases/correctSTDOUT2.txt"
    mv tmp testSTDOUT2.txt
    exit
fi

./totalInfection testCases/userFile3.txt testCases/connectionFile3.txt 0014 02 > tmp
if ! cmp tmp testCases/correctSTDOUT3.txt >/dev/null 2>&1
then
    echo "TEST CASE 3 FAILED"
    echo "Test output can be found in testSTDOUT3.txt"
    echo "Correct output can be found in testCases/correctSTDOUT3.txt"
    mv tmp testSTDOUT3.txt
    exit
fi

./totalInfection testCases/userFile4.txt testCases/connectionFile4.txt 0003 03 > tmp
if ! cmp tmp testCases/correctSTDOUT4.txt >/dev/null 2>&1
then
    echo "TEST CASE 4 FAILED"
    echo "Test output can be found in testSTDOUT4.txt"
    echo "Correct output can be found in testCases/correctSTDOUT4.txt"
    mv tmp testSTDOUT4.txt
    exit
fi
rm tmp
echo "ALL TEST CASES PASSED"
