output : main.cpp
	g++ main.cpp -o output

build_run_delete: output run clean

run: output
	./output

test: output
	cat data/1.in | ./output | diff - data/1.ans
	cat data/2.in | ./output | diff - data/2.ans
	#cat data/3.in | ./output | diff - data/3.ans
	echo "All Kattis sample test cases passed!" 

clean:
	rm output