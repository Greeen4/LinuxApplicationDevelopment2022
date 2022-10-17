#!/bin/bash

DELAY=0.01

if [[ ${#} -gt 0 ]]
then
    DELAY=${1}
fi

readarray text

elnum=0; elnums=()

for i in ${!text[@]}
do
    line=${text[${i}]}
    elnum=$(( ${elnum} + ${#line} ))
	echo ${elnum}
    elnums+=(${#line})
done

randoms=$( shuf -i0-$(( ${elnum} - 1)) )

tput clear

for i in ${randoms}
do
    bound=0
    r=-1
    for j in ${!elnums[@]}
    do
        len=${elnums[${j}]}
        r=$(( ${r} + 1 ))
        bound=$(( ${bound} + ${len} ))
        if [[ ${bound} -gt ${i} ]]
        then
            bound=$(( ${bound} - ${len} ))
            break
        fi
    done
    c=$(( ${i} - ${bound} ))

    row=${text[${r}]}
    tput cup ${r} ${c} && echo -n ${row:${c}:1}
    sleep ${DELAY}
done

tput cup ${#text[@]} 0
