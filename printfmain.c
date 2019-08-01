#include <stdio.h>
#include "inclu/ft_printf.h"

int         main(void)
{
    int     i;
    char    *str;

    i = 0;
    str = "345";
    // setbuf(stdout, NULL);
    // /* D flag test*/
    // printf("%s\n\n", "D flags");
    // i = printf("1 no flags: %d\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 no flags: %d\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 plus: %+d\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 plus: %+d\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 space: % d\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 space: % d\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 width: %+24d\n", 1534976367);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 width: %+24d\n", 1534976367);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 precision: %.5d\n", 15355);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 precision: %.5d\n", 15355);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 zero: %05d\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 zero: %05d\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 minus: %-5d\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 minus: %-5d\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 l: %lld\n", __LONG_LONG_MAX__);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 l: %lld\n", __LONG_LONG_MAX__);
    // printf("2 return value: %d\n\n", i);

    //  /* i flag test*/
    // printf("%s\n\n", "I flags");
    // i = printf("1 no flags: %i\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 no flags: %i\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 plus: %+i\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 plus: %+i\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 space: % i\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 space: % i\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 width: %5i\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 width: %5i\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 precision: %.5i\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 precision: %.5i\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 zero: %05i\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 zero: %05i\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 minus: %-5i\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 minus: %-5i\n", 153);
    // printf("2 return value: %d\n\n", i);
    // // i = printf("1 l: %li\n", 9999999999);
    // // printf("1 return value: %d\n", i);
    // // i = ft_printf("2 l: %li\n", 9999999999);
    // // printf("2 return value: %d\n\n", i);

    //  /* o flag test*/
    // printf("%s\n\n", "O flags");
    // i = printf("1 no flags: %#05o\n", 60);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 no flags: %#05o\n", 60);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 width: %5o\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 width: %5o\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 precision: %.5o\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 precision: %.5o\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 zero: %05o\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 zero: %05o\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 minus: %-5o\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 minus: %-5o\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 l: %lo\n", 9999999999);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 l: %lo\n", 9999999999);
    // printf("2 return value: %d\n\n", i);

    //  /* p flag test*/
    // printf("%s\n\n", "P flags");
    // i = printf("1 no flags: %p\n", str);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 no flags: %p\n", str);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 width: %5p\n", str);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 width: %5p\n", str);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 minus: %-5p\n", str);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 minus: %-5p\n", str);
    // printf("2 return value: %d\n\n", i);

    //  /* x flag test*/
    // printf("%s\n\n", "x flags");
    // i = printf("1 no flags: %#x\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 no flags: %#x\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 width: %5x\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 width: %5x\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 precision: %.5x\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 precision: %.5x\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 zero: %05x\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 zero: %05x\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 minus: %-5x\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 minus: %-5x\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 l: %lx\n", 9999999999);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 l: %lx\n", 9999999999);
    // printf("2 return value: %d\n\n", i);

    //  /* X flag test*/
    // printf("%s\n\n", "X flags");
    // i = printf("1 no flags: %X\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 no flags: %X\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 width: |%#-5X|\n", 348);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 width: |%#-5X|\n", 348);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 precision: %.5X\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 precision: %.5X\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 zero: %05X\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 zero: %05X\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 minus: %-5X\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 minus: %-5X\n", 153);
    // printf("2 return value: %d\n\n", i);
    // // i = printf("1 l: %lX\n", 9999999999);
    // // printf("1 return value: %d\n", i);
    // // i = ft_printf("2 l: %lX\n", 9999999999);
    // // printf("2 return value: %d\n\n", i);

    //  /* U flag test*/
    // printf("%s\n\n", "U flags");
    // i = printf("1 no flags: %u\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 no flags: %u\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 width: %5u\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 width: %5u\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 precision: %.5u\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 precision: %.5u\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 zero: %05u\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 zero: %05u\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 minus: %-5u\n", 153);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 minus: %-5u\n", 153);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 l: %lu\n", 9999999999);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 l: %lu\n", 9999999999);
    // printf("2 return value: %d\n\n", i);

    //   /* C flag test*/
    // printf("%s\n\n", "C flags");
    i = printf("1 no flags: |%f|\n", (double)0);
    printf("1 return value: %d\n", i);
    i = ft_printf("2 no flags: |%f|\n", (double)0);
    printf("2 return value: %d\n\n", i);
    // i = printf("1 width: %5c\n", '$');
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 width: %5c\n", '$');
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 minus: %-5c\n", '$');
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 minus: %-5c\n", '$');
    // printf("2 return value: %d\n\n", i);

    //  /* S flag test*/
    // printf("%s\n\n", "S flags");
    // i = printf("1 no flags: %s\n", str);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 no flags: %s\n", str);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 width: %5s\n", str);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 width: %5s\n", str);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 precision: %.5s\n", str);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 precision: %.5s\n", str);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 minus: %-5s\n", str);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 minus: %-5s\n", str);
    // printf("2 return value: %d\n\n", i);

    // /* % flag test*/
    // printf("%s\n\n", "Percent Sign");
    // i = printf("1 no flag: %%\n");
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 no flag: %%\n");
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 width: %5%\n");
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 width: %5%\n");
    // printf("2 return value: %d\n\n", i);

    //  /* MIX test*/
    // printf("%s\n\n", "MIX");
    // i = printf("1 d: %+5d s: %10s c: %9c\n", 13, str, '$');
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 d: %+5d s: %10s c: %9c\n", 13, str, '$');
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 s: %.5s o: %#9.7o x: %#4.8x i:  %+15i\n", str, 25, 63, 85);
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 s: %.5s o: %#9.7o x: %#4.8x i:  %+15i\n", str, 25, 63, 85);
    // printf("2 return value: %d\n\n", i);
    // i = printf("1 p: %6p d: %+.6d c: %3c\n", str, 1675, '$');
    // printf("1 return value: %d\n", i);
    // i = ft_printf("2 p: %6p d: %+.6d c: %3c\n", str, 1675, '$');
    // printf("2 return value: %d\n\n", i);

    //  /* B flag test*/
    // printf("%s\n\n", "B flags");
    // i = ft_printf("2 no flags: |%b|\n", 9);
    // printf("2 return value: %d\n\n", i);
    // i = ft_printf("2 width: |%5b|\n", 9);
    // printf("2 return value: %d\n\n", i);
    // i = ft_printf("2 precision: |%.5b|\n", 9);
    // printf("2 return value: %d\n\n", i);
    // i = ft_printf("2 zero: |%05b|\n", 9);
    // printf("2 return value: %d\n\n", i);
    // i = ft_printf("2 minus: |%-5b|\n", 9);
    // printf("2 return value: %d\n\n", i);
    // // i = ft_printf("2 l: |%lb|\n", 9999999999);
    // // printf("2 return value: %d\n\n", i);
    system("leaks test");
	return (0);
}
