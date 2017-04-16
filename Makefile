all: test_mock scales freq

.PHONY: test_mock

C_FLAGS=-Wall -Wextra

test_mock:
	src2dsk         test_mock.s
	applewin.sh -d1 test_mock.dsk

scales: scales.s
	src2dsk                    $<
	applewin.sh -d1 $(basename $<).dsk

freq: freq.c
	g++ $(C_FLAGS) $< -o $@

