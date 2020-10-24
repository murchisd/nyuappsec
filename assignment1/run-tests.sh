#/bin/bash

./build/giftcardreader_coverage 1 crash1.gft > /dev/null 
[ $? -ne 0 ] && echo "Negative Read test failed" || echo "Negative Read test passed"

./build/giftcardreader_coverage 1 crash2.gft > /dev/null
[ $? -ne 0 ] && echo "Heap Overwrite test failed" || echo "Heap Overwrite test passed"

timeout 5 ./build/giftcardreader_coverage 1 ./hang.gft > /dev/null 
[ $? -ne 0 ] && echo "Loop test failed" || echo "Loop test passed"

./build/giftcardreader_coverage 2 examplefile.gft  > /dev/null 
[ $? -ne 0 ] && echo "Example File JSON output failed" || echo "Example File JSON output passed"

./build/giftcardreader_coverage 2 crash2.gft > /dev/null
[ $? -ne 0 ] && echo "Heap Overwrite (JSON) test failed" || echo "Heap Overwrite test passed"


