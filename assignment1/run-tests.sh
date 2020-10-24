#/bin/bash

./giftcardreader 1 crash1.gft > /dev/null 
[ $? -ne 0 ] && echo "Negative Read test failed" || echo "Negative Read test passed"

./giftcardreader 1 crash2.gft > /dev/null
[ $? -ne 0 ] && echo "Heap Overwrite test failed" || echo "Heap Overwrite test passed"

timeout 5 ./giftcardreader 1 ./hang.gft > /dev/null 
[ $? -ne 0 ] && echo "Loop test failed" || echo "Loop test passed"
