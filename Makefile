all:
	g++ *.cc -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE -o `ls *.cc | sed 's/\(.*\).cc/\1/'`

clean:
	rm `ls *.cc | sed 's/\(.*\).cc/\1/'`
