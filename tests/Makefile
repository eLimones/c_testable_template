all: buildTest 

buildTest:
	for testDir in $$(ls -d test_*); do \
	make -s --directory=$$testDir ; \
	done;
clean:
	for testDir in $$(ls -d test_*); do \
	make -s --directory=$$testDir clean ; \
	done;
test: buildTest
	./testIterator.sh
