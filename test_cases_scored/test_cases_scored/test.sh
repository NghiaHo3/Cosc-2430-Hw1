#Compile the code
# if the file sum_rowcol exists then remove it
if [ -f sum_rowcol ]; then
    rm sum_rowcol
fi
g++ -std=c++11 *.cpp -o sum_rowcol
# if the file sum_rowcol does not exit then exit the test
if [ ! -f sum_rowcol ]; then
    echo -e "\033[1;91mCompile FAILED.\033[0m"
    exit
fi
# clean
rm *.out *.stderr *.stdcout
# For test case 1
# input 1.txt and output 1.out
./sum_rowcol "A=1.txt;C=1.out" 1>1.stdcout 2>1.stderr
# compare 1.out with 1.ans, output the difference to 1.diff
diff -iEBwu 1.ans 1.out > 1.diff
# if diff returns nothing, it means you pass the test case (Your ourput file 1.out is correct)
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 1    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 1    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f 1.diff
fi
# For test case 2
./sum_rowcol "A=2.txt;C=2.out" 1>2.stdcout 2>2.stderr
diff -iEBwu 2.ans 2.out > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 2    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 2    \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi
# For test case 3
./sum_rowcol "A=3.txt;C=3.out" 1>3.stdcout 2>3.stderr
diff -iEBwu 3.ans 3.out > 3.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 3    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 3    \033[1;92mPASSED.\033[0m"
    rm -f 3.diff
fi
# For test case 4
./sum_rowcol "A=4.txt;C=4.out" 1>4.stdcout 2>4.stderr
diff -iEBwu 4.ans 4.out > 4.diff
if [ $? -ne 0 ]; then
echo -e "Test case 4    \033[1;91mFAILED.\033[0m"
else
echo -e "Test case 4    \033[1;92mPASSED.\033[0m"
rm -f 4.diff
fi
# For test case 5
./sum_rowcol "A=5.txt;C=5.out" 1>5.stdcout 2>5.stderr
diff -iEBwu 5.ans 5.out > 5.diff
if [ $? -ne 0 ]; then
echo -e "Test case 5    \033[1;91mFAILED.\033[0m"
else
echo -e "Test case 5    \033[1;92mPASSED.\033[0m"
rm -f 5.diff
fi
# For test case 6
./sum_rowcol "A=6.txt;C=6.out" 1>6.stdcout 2>6.stderr
diff -iEBwu 6.ans 6.out > 6.diff
if [ $? -ne 0 ]; then
echo -e "Test case 6    \033[1;91mFAILED.\033[0m"
else
echo -e "Test case 6    \033[1;92mPASSED.\033[0m"
rm -f 6.diff
fi
# For test case 7
./sum_rowcol "A=7.txt;C=7.out" 1>7.stdcout 2>7.stderr
diff -iEBwu 7.ans 7.out > 7.diff
if [ $? -ne 0 ]; then
echo -e "Test case 7    \033[1;91mFAILED.\033[0m"
else
echo -e "Test case 7    \033[1;92mPASSED.\033[0m"
rm -f 7.diff
fi
# For test case 8
./sum_rowcol "A=8.txt;C=8.out" 1>8.stdcout 2>8.stderr
diff -iEBwu 8.ans 8.out > 8.diff
if [ $? -ne 0 ]; then
echo -e "Test case 8    \033[1;91mFAILED.\033[0m"
else
echo -e "Test case 8    \033[1;92mPASSED.\033[0m"
rm -f 8.diff
fi
# For test case 9
./sum_rowcol "A=9.txt;C=9.out" 1>9.stdcout 2>9.stderr
diff -iEBwu 9.ans 9.out > 9.diff
if [ $? -ne 0 ]; then
echo -e "Test case 9    \033[1;91mFAILED.\033[0m"
else
echo -e "Test case 9    \033[1;92mPASSED.\033[0m"
rm -f 9.diff
fi
# For test case 10
./sum_rowcol "A=10.txt;C=10.out" 1>10.stdcout 2>10.stderr
diff -iEBwu 10.ans 10.out > 10.diff
if [ $? -ne 0 ]; then
echo -e "Test case 10    \033[1;91mFAILED.\033[0m"
else
echo -e "Test case 10    \033[1;92mPASSED.\033[0m"
rm -f 10.diff
fi

