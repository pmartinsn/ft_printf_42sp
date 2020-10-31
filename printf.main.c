/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:23:17 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/30 16:23:57 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *fmt, ...);





int main()
{
	int 			return_printf= 0;
	int 			return_ft_printf= 0;
	unsigned int 	numero = 243;
	int				nbr = 64;
	unsigned int 	hexa = 22222;
//	char 			bob[] = "won";
	char 			nan[] = "12345";
	char 			jan[] = "ABCDE";
	char 			limit[] ="help";
	char 			h = 'h';
	int				duo = 18;
	char 			*test = "teste";

			 return_printf = printf("%-*d.....lllll%-*.0i%-*.0s%-*.0x%-*c.%-*p%-*.0udxX.llllAQ.AQ%.x.%.5X.%-x.%X..AQ%i.AQ%.d.%10c%s%.sAQ%.s\n",5,nbr, 5, numero, 15,jan,5, hexa,5,h,24,&test,5, numero,hexa, hexa,  hexa, hexa ,hexa, hexa,h, jan, jan, jan);
       return_ft_printf = ft_printf("%-*d.....lllll%-*.0i%-*.0s%-*.0x%-*c.%-*p%-*.0udxX.llllAQ.AQ%.x.%.5X.%-x.%X..AQ%i.AQ%.d.%10c%s%.sAQ%.s\n",5,nbr, 5, numero, 15,jan,5,hexa,5,h,24,&test,5, numero,hexa, hexa,  hexa, hexa , hexa, hexa,h, jan, jan, jan);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
		     return_printf = printf("%-.3icdxX111...%-5i...%-3i....%-s%-20s.%-s.%-i.%-c.%-p.%-u.%-x.%-X.%-x.%X..%-x.%-X.%-c\n",duo,nbr, nbr, nan,jan,limit,nbr,h,&test, numero, hexa, hexa,  hexa, hexa ,hexa, hexa,h);
       return_ft_printf = ft_printf("%-.3icdxX111...%-5i...%-3i....%-s%-20s.%-s.%-i.%-c.%-p.%-u.%-x.%-X.%-x.%X..%-x.%-X.%-c\n",duo,nbr, nbr,nan,jan,limit,nbr,h,&test, numero, hexa, hexa,  hexa, hexa , hexa, hexa,h);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);

		 return_printf = printf("%-5x%5c.%-15p.%-10u.%-5x.%.5X.%-x.%X..%-x.%-X.%20c\n",hexa,h,&test, numero, hexa, hexa,  hexa, hexa ,hexa, hexa,h);
   return_ft_printf = ft_printf("%-5x%5c.%-15p.%-10u.%-5x.%.5X.%-x.%X..%-x.%-X.%20c\n",hexa,h,&test, numero, hexa, hexa,  hexa, hexa , hexa, hexa,h);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
					      return_printf = printf("%i%i%-i%-i%-i\n",nbr, nbr,duo,nbr, nbr);
	                return_ft_printf = ft_printf("%i%i%-i%-i%-i\n",nbr, nbr,duo,nbr, nbr);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
				      return_printf = printf("%i%s%-s%-i%-i%-i\n",nbr,jan, jan,duo,nbr, nbr);
	        return_ft_printf = ft_printf("%i%s%-s%-i%-i%-i\n", nbr, jan, jan, duo, nbr, nbr);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
			      return_printf = printf("%i%s%-s%-i%-i%-i\n",nbr,jan, jan,duo,nbr, nbr);
	        return_ft_printf = ft_printf("%i%s%-s%-i%-i%-i\n", nbr, jan, jan, duo, nbr, nbr);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
		      return_printf = printf("%-s%c%-c%-i%-i%-i%s%s\n",jan,h,h,duo,nbr, nbr, nan,jan);
	    return_ft_printf = ft_printf("%-s%c%-c%-i%-i%-i%s%s\n",jan,h,h,duo,nbr, nbr,nan,jan );
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);

				 return_printf = printf("%u\n",numero);
	       return_ft_printf = ft_printf("%u\n",numero);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
				 return_printf = printf("%X\n",hexa);
	       return_ft_printf = ft_printf("%X\n",hexa);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
				     return_printf = printf("%x\n",hexa);
	       return_ft_printf = ft_printf("%x\n",hexa);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
			     return_printf = printf("%-p\n",&test);
	       return_ft_printf = ft_printf("%-p\n",&test);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
				     return_printf = printf("%%\n");
	       return_ft_printf = ft_printf("%%\n");
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);

		      return_printf = printf("%s%s%s%i%i%c%c\n",jan, nan,jan, nbr, nbr,h,h);
	    return_ft_printf = ft_printf("%s%s%s%i%i%c%c\n",jan, nan,jan, nbr, nbr,h,h );
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
			 return_printf = printf("%s%c%c%s%s\n",jan,h,h, nan,jan);
	   return_ft_printf = ft_printf("%s%c%c%s%s\n",jan,h,h,nan,jan );
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
		      return_printf = printf("%-s--%s%s%i%i%c%c\n",jan, nan,jan, nbr, nbr,h,h);
	    return_ft_printf = ft_printf("%-s--%s%s%i%i%c%c\n",jan, nan,jan, nbr, nbr,h,h );
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);

			      return_printf = printf("%-20i.%10i.\n",duo,nbr);
	  	    return_ft_printf = ft_printf("%-20i.%10i.\n",duo,nbr);
printf("...XXXXXXXXXXXXXXreturn_printf:%i\n", return_printf);
printf("XXXXXXXXXXXXXXreturn_ft_printf:%i\n", return_ft_printf);
		      return_printf = printf("%-11c%-c%-c\n",h,h,h);
	    return_ft_printf = ft_printf("%-11c%-c%-c\n",h,h,h);
	printf("..............--------return_printf:%i\n", return_printf);
	printf("...........--------return_ft_printf:%i\n", return_ft_printf);
	      return_printf = printf("%%12%s%-s%-s%-i%c%c\n",nan,jan,limit,nbr,h,h);
	return_ft_printf = ft_printf("%%12%s%-s%-s%-i%c%c\n",nan,jan,limit,nbr,h,h);
	printf("...............return_printf:%i\n", return_printf);
	printf("............return_ft_printf:%i\n", return_ft_printf);
	         	      return_printf = printf("%-c%-c%-c%-c%-c%-c\n",h,h,h,h,h,h);
	           return_ft_printf = ft_printf("%-c%-c%-c%-c%-c%-c\n",h,h,h,h,h,h);
	printf("...............return_printf:%i\n", return_printf);
	printf("------------return_ft_printf:%i\n", return_ft_printf);
	      return_printf = printf("%s%-s%-s%-i%c%c\n",nan,jan,limit,nbr,h,h);
	return_ft_printf = ft_printf("%s%-s%-s%-i%c%c\n",nan,jan,limit,nbr,h,h);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
		      return_printf = printf("%-i%-i\n",nbr,duo);
	    return_ft_printf = ft_printf("%-i%-i\n",nbr,duo);
	printf(".................return_printf:%i\n", return_printf);
	printf("..............return_ft_printf:%i\n", return_ft_printf);

		      return_printf = printf("12345%c%c%c%c%c%c%c%c\n",h,h,h,h,h,h,h,h);
	    return_ft_printf = ft_printf("12345%c%c%c%c%c%c%c%c\n",h,h,h,h,h,h,h,h);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
	      return_printf = printf("%%%%%%%%%%%%%s%-s%-s%-i%c%c%c%c%c%c%c%c\n",nan,jan,limit,nbr,h,h,h,h,h,h,h,h);
	return_ft_printf = ft_printf("%%%%%%%%%%%%%s%-s%-s%-i%c%c%c%c%c%c%c%c\n",nan,jan,limit,nbr,h,h,h,h,h,h,h,h);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
	      return_printf = printf("%s12345%%%%67891s%-s%-s%-i%c%c%c%c%c%c%c%c\n",nan,jan,limit,nbr,h,h,h,h,h,h,h,h);
	return_ft_printf = ft_printf("%s12345%%%%67891s%-s%-s%-i%c%c%c%c%c%c%c%c\n",nan,jan,limit,nbr,h,h,h,h,h,h,h,h);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
	          return_printf = printf("%%%%%%%%%%12\n");
	    return_ft_printf = ft_printf("%%%%%%%%%%12\n");
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
			      return_printf = printf("%%%%%%%%%%\n");
	    return_ft_printf = ft_printf("%%%%%%%%%%\n");
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
	     return_printf = printf("%-5c%-c%-c%-5i111.%-5i.%-i.%-s%-s.%-s.%-i.%-c.%-p.%-u.%-x.%-X.%-x.%X..%-x.%-X.%-c\n",h,h,h,duo,nbr, nbr, nan,jan,limit,nbr,h,&test, numero, hexa, hexa,  hexa, hexa ,hexa, hexa,h);
   return_ft_printf = ft_printf("%-5c%-c%-c%-5i111.%-5i.%-i.%-s%-s.%-s.%-i.%-c.%-p.%-u.%-x.%-X.%-x.%X..%-x.%-X.%-c\n",h,h,h,duo,nbr, nbr,nan,jan,limit,nbr,h,&test, numero, hexa, hexa,  hexa, hexa , hexa, hexa,h);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);

			  
			//printf("\nthis is the RETURN of ft_printf:%i\n", test);
}

/*int	print_x_noflag( bdr *star)
{
//	printf("\nentrou  no x\n");
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	star->kpr6= ft_strlen(character);
	ft_putstr(character);
	free(character);
	return(star->kpr6);
}
int	print_X_noflag(bdr *star)
{
	printf("\nentrou  no X\n");
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
	star->kpr7= ft_strlen(character);
	ft_putstr(character);
	free(character);
	return(star->kpr7);
}*/