set pagination off
set logging file gdb.output


set $count = 0


b range.c:50 
commands 
	set $count++
	if (($count >= 27) && ($count <= 35))
  		echo @@@
  		printf "@@@ %d %d %d %d\n", I->begin, I->end, I->step, i
	end
  	continue
end

run -100 100 3 > /dev/null

set logging off
quit


