clear
echo "" > test_results.txt 
code test_results.txt

echo "test01 - test04" >> test_results.txt

gcc KindredSpirits.c test_cases/testcase01.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase02.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase03.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase04.c; ./a.out >> test_results.txt

echo "\ntest05 - test08" >> test_results.txt

gcc KindredSpirits.c test_cases/testcase05.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase06.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase07.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase08.c; ./a.out >> test_results.txt

echo "\ntest09 - test12" >> test_results.txt

gcc KindredSpirits.c test_cases/testcase09.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase10.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase11.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase12.c; ./a.out >> test_results.txt

echo "\ntest13 - test16" >> test_results.txt

gcc KindredSpirits.c test_cases/testcase13.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase14.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase15.c; ./a.out >> test_results.txt
gcc KindredSpirits.c test_cases/testcase16.c; ./a.out >> test_results.txt

rm a.out