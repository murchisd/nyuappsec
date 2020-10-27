#/bin/bash

failed=0
./build/giftcardreader 1 ./tests/crash1.gft > /dev/null 
if [[ $? -ne 0 ]]
then
	echo "Negative Read test failed"
        failed=1
fi

./build/giftcardreader 1 ./tests/crash2.gft > /dev/null
if [[ $? -ne 0 ]]
then
	echo "Heap Overwrite test failed"
	failed=1
fi

timeout 5 ./build/giftcardreader 1 ./tests/hang.gft > /dev/null 
if [[ $? -ne 0 ]]
then
	echo "Loop test failed"
	failed=1
fi

./build/giftcardreader 1 ./tests/cov1.gft > /dev/null
if [[ $? -ne 0 ]]
then
        echo "Simple print Amount Change record failed"
        failed=1
fi

./build/giftcardreader 1 ./tests/cov2.gft > /dev/null
if [[ $? -ne 0 ]]
then
        echo "Simple print Message record failed"
        failed=1
fi

for test in ./afl_findings/queue/*; do
	./build/giftcardreader 1 $test > /dev/null
	if [[ $? -ne 0 ]]
	then
		echo "QUEUE: "$(basename $test | cut -d"," -f1)" Failed"
		failed=1
	fi
done


for test in ./afl_findings/crashes/*; do
	./build/giftcardreader 1 $test > /dev/null
	if [[ $? -ne 0 ]]
	then
		echo "CRASH: "$(basename $test | cut -d"," -f1)" Failed"
		failed=1
	fi
done

exit $failed
