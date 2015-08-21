#!/bin/sh

for testDir in $(ls -d test_*); do 
	(cd $testDir; make test | grep "FAILED" && make test || echo $testDir ok); 
done

