g++ -O3 -static not.cpp -o not std=c++20
g++ -O3 -static brute.cpp -o brute std=c++20
g++ -O3 -static gen.cpp -o gen std=c++20

for((i = 1; i <= 100; ++i)); do
	echo $i
	./gen $i > input
	./not < input > wzor_out
	./brute < input > brute_out
	diff -w brute_out wzor_out || break
done
