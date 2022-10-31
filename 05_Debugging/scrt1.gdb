set pagination off
set logging file gdb.output

b range.c:50 if i%5 == 0
commands 1
  echo @@@
  printf "@@@ %d %d %d %d\n", I->begin, I->end, I->step, i
  continue
end

run 1 12 > /dev/null

set logging off
quit
