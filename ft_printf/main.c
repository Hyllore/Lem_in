#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <string.h>
#include <wchar.h>


// forbidden func: command nm

int		ft_printf(const char *format, ...);
/*
int		main(void)
{
	int			ft_pf;
	int			pf;
	int			*ptr;
	char		*str = "coucoulol";
	wchar_t		*wstr = L"𓀀 ⾁ᱭᱡ₤Ⅲ 𐀁 𐐁";
	unsigned char uc = 255;
	unsigned short us = USHRT_MAX;


	setlocale(LC_ALL, "");

	ptr = NULL;
	// ------- %s %p %d ------- //
	ft_printf("-- %%s %%p %%d %%%% --\n");

	ft_pf = ft_printf("%s\n", str);
	pf = printf("%s\n", str);
	ft_printf("%d, %d\n", ft_pf, pf);

	ft_pf = ft_printf("%s\n", NULL);
	pf = printf("%s\n", NULL);
	ft_printf("%d, %d\n", ft_pf, pf);

	ft_pf = ft_printf("%p\n", NULL);
	pf = printf("%p\n", NULL);
	ft_printf("%d, %d\n", ft_pf, pf);

	ft_pf = ft_printf("%p\n", &ptr);
	pf = printf("%p\n", &ptr);
	ft_printf("%d, %d\n", ft_pf, pf);

	ft_pf = ft_printf("%p\n", NULL);
	pf = printf("%p\n", NULL);
	ft_printf("%d, %d\n", ft_pf, pf);

	ft_pf = ft_printf("%10%\n");
	pf = printf("%10%\n");
	ft_printf("%d, %d\n", ft_pf, pf);

	ft_pf = ft_printf("%-10%\n");
	pf = printf("%-10%\n");
	ft_printf("%d, %d\n", ft_pf, pf);




	// ------ SDioOuUxXcC ------- //
	ft_printf("-- SDioOuUxXcC --\n");

	ft_pf = ft_printf("%S\n", wstr);
	pf = printf("%S\n", wstr);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%D\n", INT_MAX + 1);
	pf = printf("%D\n", INT_MAX + 1);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%o\n", -42);
	pf = printf("%o\n", -42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%O\n", -42);
	pf = printf("%O\n", -42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%u\n", UINT_MAX);
	pf = printf("%u\n", UINT_MAX);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%U\n", UINT_MAX);
	pf = printf("%U\n", UINT_MAX);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%x, %X\n", 255, 255);
	pf = printf("%x, %X\n", 255, 255);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%x\n", -42);
	pf = printf("%x\n", -42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%c, %C\n", 't', 233);
	pf = printf("%c, %C\n", 't', 233);
	ft_printf("%i, %i\n", ft_pf, pf);

	// ------ multi flag ------- //
	ft_printf("-- MULTI FLAG --\n");

	ft_pf = ft_printf("%d, %c, %s, %c, %d\n", INT_MIN, 97, "tototututiti", 98, -42);
	      pf = printf("%d, %c, %s, %c, %d\n", INT_MIN, 97, "tototututiti", 98, -42);
	ft_printf("%d, %d\n", ft_pf, pf);

	// ------ modifier pour dxuosc ------- //
	ft_printf("-- MODIFIER --\n");

	ft_pf = ft_printf("%hhx\n", uc);
	pf = printf("%hhx\n", uc);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%hu\n", us);
	pf = printf("%hu\n", us);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%ld\n", LONG_MAX);
	pf = printf("%ld\n", LONG_MAX);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%llo\n", LLONG_MAX);
	pf = printf("%llo\n", LLONG_MAX);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%ls\n", wstr);
	pf = printf("%ls\n", wstr);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%lc\n", *wstr);
	pf = printf("%lc\n", *wstr);
	ft_printf("%i, %i\n", ft_pf, pf);

	// ------ attributs ------- //
	ft_printf("-- ATTRIBUTS --\n");

	ft_pf = ft_printf("%#020.15o\n", 42);
	pf = printf("%#020.15o\n", 42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%-#10.15o\n", 42);
	pf = printf("%-#10.15o\n", 42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%#7.4x\n", 42);
	pf = printf("%#7.4x\n", 42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%#7.4X\n", 42);
	pf = printf("%#7.4X\n", 42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%07.4X\n", 42);
	pf = printf("%07.4X\n", 42);
	ft_printf("%i, %i\n", ft_pf, pf);

	// ------ precision ------- //
	ft_printf("-- PRECISION --\n");

	ft_pf = ft_printf("%.d\n", 0);
	pf = printf("%.d\n", 0);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%-.d\n", 0);
	pf = printf("%-.d\n", 0);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%.0d\n", 0);
	pf = printf("%.0d\n", 0);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%-.0d\n", 0);
	pf = printf("%-.0d\n", 0);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%.10d\n", -42);
	pf = printf("%.10d\n", -42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%-.10d\n", -42);
	pf = printf("%-.10d\n", -42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%.d\n", 42);
	pf = printf("%.d\n", 42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%.o\n", 0);
	pf = printf("%.o\n", 0);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%-.o\n", 0);
	pf = printf("%-.o\n", 0);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%.0o\n", 0);
	pf = printf("%.0o\n", 0);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%-.0o\n", 0);
	pf = printf("%-.0o\n", 0);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%.10o\n", -42);
	pf = printf("%.10o\n", -42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%-.10o\n", -42);
	pf = printf("%-.10o\n", -42);
	ft_printf("%i, %i\n", ft_pf, pf);

	ft_pf = ft_printf("%.o\n", 42);
	pf = printf("%.o\n", 42);
	ft_printf("%i, %i\n", ft_pf, pf);
	return (0);
}
*/
// --- LEAKS ---

int		main(void)
{
	wchar_t		*wstr = L"𓀀 ⾁ᱭᱡ₤Ⅲ 𐀁 𐐁";

	ft_printf("%.o\n", 42);
	ft_printf("%-.o\n", 0);
	ft_printf("%#020.15o\n", 42);
	ft_printf("%-#10.15o\n", 42);
	ft_printf("%#7.4x\n", 42);
	ft_printf("%#7.4X\n", 42);
	ft_printf("%07.4X\n", 42);
	ft_printf("%s\n", NULL);
	ft_printf("%d, %c, %s, %c, %d\n", INT_MIN, 97, "tototututiti", 98, -42);
	ft_printf("%c, %C\n", 't', 233);
	ft_printf("%S\n", wstr);
	ft_printf("apamdldlskskskfjsiejqs,x,xjdjdjjhrhhdhuzezuiddiz,idinzdnududfuhuhfeijfoeijfeiojfuzehiuaf\n", "");
	while (1)
		;

	return (0);
}
