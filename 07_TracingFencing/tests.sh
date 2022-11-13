#!/bin/sh

touch input.txt
strace -e openat -P "input.txt" -e fault=openat:error=EACCES ./move "input.txt" "out.txt"
if [ $? -ne 13 ]; then
	echo "ERROR"
else
	echo "Success"
fi

touch PROTECTED_file

LD_PRELOAD=./protect.so ./move PROTECTED_file abcd

ls PROTECTED_file >& /dev/null
if [ $? == "2" ]; then
    echo Failed! Protected file deleted;
else
    echo Success!;
fi

./move PROTECTED_file abcd
ls PROTECTED_file >& /dev/null
if [ $? != "2" ]; then

    echo Failed! File wasnt deleted;
else
    echo Success!;
fi
