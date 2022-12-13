#! /bin/bash

result=$(echo "Sha1 configure.ac" | ./rhasher)
sha_result=$(sha1sum configure.ac)
if [ "$result" -ne  "$sha_result" ]; then
    echo -e "Fail!\n";
    exit 1;
else
    echo "Success"
fi

result=$(echo "Md5 configure.ac" | ./rhasher)
md5_res=$(md5sum configure.ac)
if [ "$result" -ne "$md5_res" ]; then
    echo -e "Fail!\n";
    exit 1;
else
    echo "Success"
fi
