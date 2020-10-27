#/bin/bash

failed=0
./build/giftcardreader_coverage 1 ./tests/crash1.gft > /dev/null 
if [[ $? -ne 0 ]]
then
	echo "Negative Read test failed"
        failed=1
fi

./build/giftcardreader_coverage 1 ./tests/crash2.gft > /dev/null
if [[ $? -ne 0 ]]
then
	echo "Heap Overwrite test failed"
	failed=1
fi

timeout 5 ./build/giftcardreader_coverage 1 ./tests/hang.gft > /dev/null 
if [[ $? -ne 0 ]]
then
	echo "Loop test failed"
	failed=1
fi

./build/giftcardreader_coverage 1 ./tests/cov1.gft > /dev/null
if [[ $? -ne 0 ]]
then
	echo "Simple print Amount Change record failed"
	failed=1
fi

./build/giftcardreader_coverage 1 ./tests/cov2.gft > /dev/null
if [[ $? -ne 0 ]]
then
	echo "Simple print Message record failed"
	failed=1
fi

exit $failed
