all:leetcode

leetcode:leetcode.cpp
	g++ -std=c++11 leetcode.cpp -o leetcode

clean:
	rm leetcode
