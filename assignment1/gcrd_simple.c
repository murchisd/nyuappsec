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
	examplegcd.number_of_gift_card_records = 1;
  


	examplegcd.gift_card_record_data = (void *)malloc(sizeof(void*));
  //Base record data - record size + type
  examplegc.num_bytes += 4 + 4;
	examplegcd.gift_card_record_data[0] = malloc(sizeof(struct gift_card_record_data));
	examplegcrd.record_size_in_bytes = 44;
	examplegcrd.type_of_record = 2; // JAC: Should be enum!  amount_change
	examplegcac.actual_signature = "[ insert crypto signature here ]";
	examplegc.num_bytes += 32;

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
	for (int i=0; i<examplegcd.number_of_gift_card_records; i++){
		fwrite(&examplegcrd.record_size_in_bytes,4,1,fd1);
		fwrite(&examplegcrd.type_of_record,4,1,fd1);
		fwrite(examplegcac.actual_signature,32,1,fd1);
	}
}

/* JAC: No args and return -1 for no reason!?! */
int main(int argc, char** argv) {
	if(argc == 2){
                FILE *output_file = fopen(argv[1],"w");
                printf("Opened File\n");
                setupgc();
                writegc(output_file);
                fclose(output_file);
                return 0;
        }
        printf("Usage: %s <output file path>",argv[0]);
        return -1;
}

