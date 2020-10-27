#/bin/bash

./build/giftcardreader_coverage 1 ./tests/crash1.gft > /dev/null 
[ $? -ne 0 ] && echo "Negative Read test failed" || echo "Negative Read test passed"

./build/giftcardreader_coverage 1 ./tests/crash2.gft > /dev/null
[ $? -ne 0 ] && echo "Heap Overwrite test failed" || echo "Heap Overwrite test passed"

timeout 5 ./build/giftcardreader_coverage 1 ./tests/hang.gft > /dev/null 
[ $? -ne 0 ] && echo "Loop test failed" || echo "Loop test passed"

./build/giftcardreader_coverage 2 ./tests/examplefile.gft  > /dev/null 
[ $? -ne 0 ] && echo "Example File JSON output failed" || echo "Example File JSON output passed"

./build/giftcardreader_coverage 2 ./tests/crash2.gft > /dev/null
[ $? -ne 0 ] && echo "Heap Overwrite (JSON) test failed" || echo "Heap Overwrite test passed"

failed=0
for test in ./afl_findings/queue/*; do
	./build/giftcardreader_coverage 1 $test > /dev/null
	if [[ $? -ne 0 ]]
	then
		echo "QUEUE: "$(basename $test | cut -d"," -f1)" Failed"
		failed=1
	fi
done


for test in ./afl_findings/crashes/*; do
	./build/giftcardreader_coverage 1 $test > /dev/null
	if [[ $? -ne 0 ]]
	then
		echo "CRASH: "$(basename $test | cut -d"," -f1)" Failed"
		failed=1
	fi
done

