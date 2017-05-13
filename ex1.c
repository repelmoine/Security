#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <unistd.h>


int main (int argc, char **argv){

	int i;         
	mpz_t p, q,  primeNumber, rndBnd;       
	gmp_randstate_t state; 



	mpz_init(p);
	mpz_init(q);
	mpz_init_set_str(rndBnd, "1000", 10);

	gmp_randinit_default(state);

	gmp_randseed_ui(state, 1234567890);

  

	mpz_urandomm(p, state, rndBnd);
	mpz_nextprime (p, p);

	mpz_urandomm(q, state, rndBnd);
	mpz_nextprime (q, q);
    
    gmp_printf("p = %Zd\n", p);
    
	printf("\n"); 
    
	gmp_printf("q = %Zd\n", q);
	
	

	gmp_randclear(state);

	mpz_clear(p);
	mpz_clear(q);
	mpz_clear(rndBnd);

	return 0;
	
}


 
