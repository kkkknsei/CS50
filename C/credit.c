#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long n;     //input
    int count = 0;  //integer for calculating the long length
    long k;    //float for keeping input's value, we'll get into it later
    long a;    //float for keeping input's values, we'll get into it later
	long aa = 0;
	long bb = 0;
	long cc = 0;
	long dd = 0;
	long ee = 0;
	long ff = 0;
	long gg = 0;
	long hh = 0;
	long ii = 0;
	long jj = 0;
	long kk = 0;
	long ll = 0;
	long mm = 0;
	long nn = 0;
	long oo = 0;
	long pp = 0;
	
    do          //get the long (input) — the credit card number
    {
    n = get_long("CC Number: ");

        if (n <= 0)
        printf ("INVALID CC NUMBER!\n");  //if the input number is negative, show error message and go back
    }
    while (!(n > 0));   //limiting the input values to positive numbers
    k = n;              //keeping the input's value
    a = n;              //keeping the input's value
    long aaa = n;
	long bbb = n;
	long ccc = n;
	long ddd = n;
	long eee = n;
	long fff = n;
	long ggg = n;
	long hhh = n;
	long iii = n;
	long jjj = n;
	long kkk = n;
	long lll = n;
	long mmm = n;
	long nnn = n;
	long ooo = n;
	long ppp = n;
	

    while (n != 0)      //finding the length of input, it'll divide the input by 10 until finding the number of characters
    {
        n /= 10;
        count++;            //adding "1" to "count" every time the input is divided by 10
    }                   //here we lost the input for "n", that's why we needed to hold this input as "k"
    
    while (k >= 100)     //finding the two first numbers to limit the inputs to real credit cards
    {
        k /= 10;        //we're dividing the input by 10 until find the first two numbers
    }
    
    while (a >=10)
    {
        a /=10;
    }
	
	if (count == 16)
	{
		while(aaa >= pow(10, (count))) {aaa = aaa / 10;}
		aa = aaa % 10;
		while(bbb >= pow(10, (count-1))) {bbb = bbb / 10;}
		bb = bbb % 10;
		bb = bb * 2;
		while(ccc >= pow(10, (count-2))) {ccc = ccc / 10;}
		cc = ccc % 10;
		while(ddd >= pow(10, (count-3))) {ddd = ddd / 10;}
		dd = ddd % 10;
		dd = dd * 2;
		while(eee >= pow(10, (count-4))) {eee = eee / 10;}
		ee = eee % 10;
		while(fff >= pow(10, (count-5))) {fff = fff / 10;}
		ff = fff % 10;
		ff = ff * 2;
		while(ggg >= pow(10, (count-6))) {ggg = ggg / 10;}
		gg = ggg % 10;
		while(hhh >= pow(10, (count-7))) {hhh = hhh / 10;}
		hh = hhh % 10;
		hh = hh * 2;
		while(iii >= pow(10, (count-8))) {iii = iii / 10;}
		ii = iii % 10;
		while(jjj >= pow(10, (count-9))) {jjj = jjj / 10;}
		jj = jjj % 10;
		jj = jj * 2;
		while(kkk >= pow(10, (count-10))) {kkk = kkk / 10;}
		kk = kkk % 10;
		while(lll >= pow(10, (count-11))) {lll = lll / 10;}
		ll = lll % 10;
		ll = ll * 2;
		while(mmm >= pow(10, (count-12))) {mmm = mmm / 10;}
		mm = mmm % 10;
		while(nnn >= pow(10, (count-13))) {nnn = nnn / 10;}
		nn = nnn % 10;
		nn = nn * 2;
		while(ooo >= pow(10, (count-14))) {ooo = ooo / 10;}
		oo = ooo % 10;
		while(ppp >= pow(10, (count-15))) {ppp = ppp / 10;}
		pp = ppp % 10;
		pp = pp * 2;
	}
	else if (count == 15)
	{
		while(aaa >= pow(10, (count))) {aaa = aaa / 10;}
		aa = aaa % 10;
		while(bbb >= pow(10, (count-1))) {bbb = bbb / 10;}
		bb = bbb % 10;
		bb = bb * 2;
		while(ccc >= pow(10, (count-2))) {ccc = ccc / 10;}
		cc = ccc % 10;
		while(ddd >= pow(10, (count-3))) {ddd = ddd / 10;}
		dd = ddd % 10;
		dd = dd * 2;
		while(eee >= pow(10, (count-4))) {eee = eee / 10;}
		ee = eee % 10;
		while(fff >= pow(10, (count-5))) {fff = fff / 10;}
		ff = fff % 10;
		ff = ff * 2;
		while(ggg >= pow(10, (count-6))) {ggg = ggg / 10;}
		gg = ggg % 10;
		while(hhh >= pow(10, (count-7))) {hhh = hhh / 10;}
		hh = hhh % 10;
		hh = hh * 2;
		while(iii >= pow(10, (count-8))) {iii = iii / 10;}
		ii = iii % 10;
		while(jjj >= pow(10, (count-9))) {jjj = jjj / 10;}
		jj = jjj % 10;
		jj = jj * 2;
		while(kkk >= pow(10, (count-10))) {kkk = kkk / 10;}
		kk = kkk % 10;
		while(lll >= pow(10, (count-11))) {lll = lll / 10;}
		ll = lll % 10;
		ll = ll * 2;
		while(mmm >= pow(10, (count-12))) {mmm = mmm / 10;}
		mm = mmm % 10;
		while(nnn >= pow(10, (count-13))) {nnn = nnn / 10;}
		nn = nnn % 10;
		nn = nn * 2 ;
		while(ooo >= pow(10, (count-14))) {ooo = ooo / 10;}
		oo = ooo % 10;
	}
	else if (count == 13)
	{
		while(aaa >= pow(10, (count))) {aaa = aaa / 10;}
		aa = aaa % 10;
		while(bbb >= pow(10, (count-1))) {bbb = bbb / 10;}
		bb = bbb % 10;
		bb = bb * 2;
		while(ccc >= pow(10, (count-2))) {ccc = ccc / 10;}
		cc = ccc % 10;
		while(ddd >= pow(10, (count-3))) {ddd = ddd / 10;}
		dd = ddd % 10;
		dd = dd * 2;
		while(eee >= pow(10, (count-4))) {eee = eee / 10;}
		ee = eee % 10;
		while(fff >= pow(10, (count-5))) {fff = fff / 10;}
		ff = fff % 10;
		ff = ff * 2;
		while(ggg >= pow(10, (count-6))) {ggg = ggg / 10;}
		gg = ggg % 10;
		while(hhh >= pow(10, (count-7))) {hhh = hhh / 10;}
		hh = hhh % 10;
		hh = hh * 2;
		while(iii >= pow(10, (count-8))) {iii = iii / 10;}
		ii = iii % 10;
		while(jjj >= pow(10, (count-9))) {jjj = jjj / 10;}
		jj = jjj % 10;
		jj = jj * 2;
		while(kkk >= pow(10, (count-10))) {kkk = kkk / 10;}
		kk = kkk % 10;
		while(lll >= pow(10, (count-11))) {lll = lll / 10;}
		ll = lll % 10;
		ll = ll * 2;
		while(mmm >= pow(10, (count-12))) {mmm = mmm / 10;}
		mm = mmm % 10;
	}

    
    long bbbb1 = 0;
    long bbbb2 = 0;
    long dddd1 = 0;
    long dddd2 = 0;
    long ffff1 = 0;
    long ffff2 = 0;
    long hhhh1 = 0;
    long hhhh2 = 0;
    long jjjj1 = 0;
    long jjjj2 = 0;
    long llll1 = 0;
    long llll2 = 0;
    long nnnn1 = 0;
    long nnnn2 = 0;
    long pppp1 = 0;
    long pppp2 = 0;
    long bb2 = bb;
    long dd2 = dd;
    long ff2 = ff;
    long hh2 = hh;
    long jj2 = jj;
    long ll2 = ll;
    long nn2 = nn;
    long pp2 = pp;
    
	if (bb >= 10) {bbbb1 = bb % 10; bb /= 10; bbbb2 = bb % 10;}
    if (dd >= 10) {dddd1 = dd % 10; dd /= 10; dddd2 = dd % 10;}
    if (ff >= 10) {ffff1 = ff % 10; ff /= 10; ffff2 = ff % 10;}
    if (hh >= 10) {hhhh1 = hh % 10; hh /= 10; hhhh2 = hh % 10;}
    if (jj >= 10) {jjjj1 = jj % 10; jj /= 10; jjjj2 = jj % 10;}
    if (ll >= 10) {llll1 = ll % 10; ll /= 10; llll2 = ll % 10;}
    if (nn >= 10) {nnnn1 = nn % 10; nn /= 10; nnnn2 = nn % 10;}
    if (pp >= 10) {pppp1 = pp % 10; pp /= 10; pppp2 = pp % 10;}
	
	long soma = 0;
	
	if (bb2 > 0 || dd2 > 0 || ff2 > 0 || hh2 > 0 || jj2 > 0 || ll2 > 0 || nn2 > 0 || pp2 > 0)
	{
		soma = bbbb1 + bbbb2 + dddd1 + dddd2 + ffff1 + ffff2 + hhhh1 + hhhh2 + jjjj1 + jjjj2 + llll1 + llll2 + nnnn1 + nnnn2 + pppp1 + pppp2;
	}

	if (bb2 < 10) {soma = soma + bb2;}
	if (dd2 < 10) {soma = soma + dd2;}
	if (ff2 < 10) {soma = soma + ff2;}
	if (hh2 < 10) {soma = soma + hh2;}
	if (jj2 < 10) {soma = soma + jj2;}
	if (ll2 < 10) {soma = soma + ll2;}
	if (nn2 < 10) {soma = soma + nn2;}
	if (pp2 < 10) {soma = soma + pp2;}

	soma = soma + aa + cc + ee + gg + ii + kk + mm + oo;
	
    if ((count == 13 || count == 16) && (a == 4) && (soma % 10 == 0))
    printf ("VISA\n");
    else if ((k == 34 || k == 37) && (count == 15) && (soma % 10 == 0))
    printf ("AMEX\n");
    else if ((k == 51 || k == 52 || k == 53 || k == 54 || k == 55) && (count == 16) && (soma % 10 == 0))
    printf("MASTERCARD\n");
    else
    printf("INVALID\n");
}