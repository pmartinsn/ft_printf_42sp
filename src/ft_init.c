#include "ft_printf.h"

void	init_tail(s_param *tail){

	tail->hold = 0;
	tail->keeper = 0;
	tail->hnbr = 0;
	tail->nbr = 0;
	//tail->helpint = malloc
	

}
void	init_bdr(bdr *star){
	star->returned_s = 0;
	star->variables_counted = 0;
	star->hold = 0;
	star->keeper = 0;
	star->kpr2 = 0;
	star->kpr3 = 0;
	star->kpr4 = 0;
	star->kpr5 = 0;
	star->kpr6 = 0;
	star->kpr7 = 0;
	star->kpr8 = 0;
//	star->kpr9 = 0;
	star->ret_p = 0;
	star->ret__ = 0;
	star->count_arg = 0;
	star->yndex = 0;
	star->yndex2 = 0;
	star->retminus1 = 0;
	star->ret_minustotal = 0;
	star->ret_dealing = 0;
	star->bugfix = 0;
	star->ret_sortie = 0;

//	star->returned_s = 0;
	
}