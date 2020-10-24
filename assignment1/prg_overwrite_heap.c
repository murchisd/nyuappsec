/*
 * Gift Card Example Writer
 * Original Author: Shoddycorp's Cut-Rate Contracting
 * Maintainer: ???
 * Comments added by Justin Cappos (JAC)
 * Modification Date: 8 July 2020
 */

#include <stdio.h>
#include "giftcard.h"

/* JAC: Why is this included? */
#include <time.h>

struct this_gift_card examplegc;
struct gift_card_data examplegcd;
struct gift_card_record_data examplegcrd;
struct gift_card_amount_change examplegcac;
struct gift_card_program exampleprg;



// Break it up so that we don't have long functions!  Good programming style!
//  (JAC: This is so wrong.  Global variable use / initialization is a 
//  terrible thing to do.)
void setupgc() {
	//examplegc.num_bytes = 116;
	//Base size numbytes + merchant + customer + num records
        examplegc.num_bytes = 4 + 32 + 32 + 4;
	examplegc.gift_card_data = (void *) &examplegcd;
	examplegcd.merchant_id = "GiftCardz.com                   ";
	examplegcd.customer_id = "DuaneGreenes Store 1451         ";
	examplegcd.number_of_gift_card_records = 2;

	//examplegcd.gift_card_record_data = (void *)malloc(examplegcd.number_of_gift_card_records*sizeof(void*));
	examplegcd.gift_card_record_data = (void *)malloc(sizeof(void*));
	//for (int i=0; i<examplegcd.number_of_gift_card_records; i++){
	//for (int i=0; i<1; i++){
                //Base record data - record size + type
    examplegc.num_bytes += 4 + 4;
		examplegcd.gift_card_record_data[0] = malloc(sizeof(struct gift_card_record_data));
		examplegcrd.record_size_in_bytes = 160;
		//examplegcrd.record_size_in_bytes = 12;
		examplegcrd.type_of_record = 3; // JAC: Should be enum!  amount_change
		examplegcrd.actual_record = (void *) &examplegcac;
    examplegc.num_bytes += 32;
    exampleprg.message="\xffiftCardz.com                   ";
    examplegc.num_bytes += 157; 
    exampleprg.program="\x01\x00\x00\x03\x80\x00\x03\xc8\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00\x02\x00\x00\x03\x01\x00";
		//examplegcac.amount_added = 100;
		//examplegcac.actual_signature = "[ insert crypto signature here ]";
		//examplegc.num_bytes += 4 + 32;
		//examplegc.num_bytes += 4; 
	//}
	//Base record data - record size + type
        //examplegc.num_bytes += 4 + 4;
        //examplegcd.gift_card_record_data[examplegcd.number_of_gift_card_records-1] = malloc(sizeof(struct gift_card_record_data));
        //examplegcrd.record_size_in_bytes = 44;
        //examplegcrd.record_size_in_bytes = 12;
        //examplegcrd.type_of_record = 1; // JAC: Should be enum!  amount_change
        //examplegcrd.actual_record = (void *) &examplegcac;
        //examplegcac.amount_added = 100;
        //examplegcac.actual_signature = "[ insert crypto signature here \0";
        //examplegc.num_bytes += 4 + 32;
        //examplegc.num_bytes += 4; 
        //examplegc.num_bytes =  2147483647;
}


// moved into separate files to avoid erroenous style checker error...
/* JAC: opening and writing a fixed filename using a global is terrible style.
 *     the style checker was right!  This code is terrible   
 */
void writegc(FILE *fd1) {
	// JAC: Why don't any of these check for error return codes?!?
	fwrite(&examplegc.num_bytes,4,1,fd1);
	fwrite(examplegcd.merchant_id,32,1,fd1);
	fwrite(examplegcd.customer_id,32,1,fd1);
	fwrite(&examplegcd.number_of_gift_card_records,4,1,fd1);
	//for (int i=0; i<examplegcd.number_of_gift_card_records; i++){
	//for (int i=0; i<2; i++){
		fwrite(&examplegcrd.record_size_in_bytes,4,1,fd1);
		fwrite(&examplegcrd.type_of_record,4,1,fd1);
    fwrite(exampleprg.message,32,1,fd1);
    fwrite(exampleprg.program,157,1,fd1);
		//fwrite(&examplegcac.amount_added,4,1,fd1);
		//fwrite(examplegcac.actual_signature,32,1,fd1);
	//}
}

/* JAC: No args and return -1 for no reason!?! */
int main(int argc, char** argv) {
	if(argc == 2){
                FILE *output_file = fopen(argv[1],"w");
                printf("Opened File\n");
                setupgc();
		//for (int i=0; i<10000; i++){
                	writegc(output_file);
		//}
                fclose(output_file);
                return 0;
        }
        printf("Usage: %s <output file path>",argv[0]);
        return -1;
}

