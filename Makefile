all:
	g++ *.cc -o `ls *.cc | sed 's/\(.*\).cc/\1/'`

clean:
	rm `ls *.cc | sed 's/\(.*\).cc/\1/'`
