all: test_mock

.PHONY: test_mock

test_mock:
	src2dsk         test_mock.s
	applewin.sh -d1 test_mock.dsk

