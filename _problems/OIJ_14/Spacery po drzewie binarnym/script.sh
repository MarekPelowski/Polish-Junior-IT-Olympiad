for((i = 1; i <= 100; ++i)); do
	echo $i
	./gen $i > input
	./wzor < input > wzor_out
	./brute < input > brute_out
	diff -w brute_out wzor_out || break
done
