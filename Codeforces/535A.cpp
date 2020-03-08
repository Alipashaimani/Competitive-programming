#include<bits/stdc++.h>
using namespace std;
int main(){
	int i;
	cin >> i;
	if(i==100000)
	cout<< "one hundred thousand";

	if(i%100000<100000 && i%100000>=90000)
	cout<< "ninety";
	if(i%100000<90000 && i%100000>=80000)
	cout<< "eighty";
	if(i%100000<80000 && i%100000>=70000)
	cout<< "seventy";
	if(i%100000<70000 && i%100000>=60000)
	cout<< "sixty";
	if(i%100000<60000 && i%100000>=50000)
	cout<< "fifty";
	if(i%100000<50000 && i%100000>=40000)
	cout<< "forty";
	if(i%100000<40000 && i%100000>=30000)
	cout<< "thirty";
	if(i%100000<30000 && i%100000>=20000)
	cout<< "twenty";

	if(i%100000<20000 && i%100000>=19000)
	cout<< "nineteen thousand";
	if(i%100000<19000 && i%100000>=18000)
	cout<< "eighteen thousand";
	if(i%100000<18000 && i%100000>=17000)
	cout<< "seventeen thousand";
	if(i%100000<17000 && i%100000>=16000)
	cout<< "sixteen thousand";
	if(i%100000<16000 && i%100000>=15000)
	cout<< "fifteen thousand";
	if(i%100000<15000 && i%100000>=14000)
	cout<< "fourteen thousand";
	if(i%100000<14000 && i%100000>=13000)
	cout<< "thirteen thousand";
	if(i%100000<13000 && i%100000>=12000)
	cout<< "twelve thousand";
	if(i%100000<12000 && i%100000>=11000)
	cout<< "eleven thousand";
	if(i%100000<11000 && i%100000>=10000)
	cout<< "ten thousand";

	if((i%100000<21000 && i%100000>=20000) ||(i%100000<31000 && i%100000>=30000)|| (i%100000<41000 && i%100000>=40000) || (i%100000<51000 && i%100000>=50000) || (i%100000<61000 && i%100000>=60000) || (i%100000<71000 && i%100000>=70000) || (i%100000<81000 && i%100000>=80000) || (i%100000<91000 && i%100000>=90000))
	cout<< " thousand";

	if(i>10000 && i%100000>=20000 && i!=20000 && i!=30000 && i!=40000 && i!=50000 && i!=60000 && i!=70000 && i!=80000 && i!=90000)
	cout<< "-";
	if(i%10000<10000 && i%10000>=9000 && (i>=20000 || i<10000))
	cout<< "nine";
	if(i%10000<9000 && i%10000>=8000 && (i>=20000 || i<10000))
	cout<< "eight";
	if(i%10000<8000 && i%10000>=7000 && (i>=20000 || i<10000))
	cout<< "seven";
	if(i%10000<7000 && i%10000>=6000 && (i>=20000 || i<10000))
	cout<< "six";
	if(i%10000<6000 && i%10000>=5000 && (i>=20000 || i<10000))
	cout<< "five";
	if(i%10000<5000 && i%10000>=4000 && (i>=20000 || i<10000))
	cout<< "four";
	if(i%10000<4000 && i%10000>=3000 && (i>=20000 || i<10000))
	cout<< "three";
	if(i%10000<3000 && i%10000>=2000 && (i>=20000 || i<10000))
	cout<< "two";
	if(i%10000<2000 && i%10000>=1000 && (i>=20000 || i<10000))
	cout<< "one";

	if((i%100000<10000 && i%100000>=1000) || (i%100000>21000 && i%100000<30000) || (i%100000>31000 && i%100000<40000) || (i%100000>41000 && i%100000<50000) || (i%100000>51000 && i%100000<60000) || (i%100000>61000 && i%100000<70000) || (i%100000>71000 && i%100000<80000) || (i%100000>81000 && i%100000<90000) || (i%100000>91000 && i%100000<100000))
	cout<< " thousand";

	if(i%1000<1000 && i%1000>=900)
	cout<< " nine hundred";
	if(i%1000<900 && i%1000>=800)
	cout<< " eight hundred";
	if(i%1000<800 && i%1000>=700)
	cout<< " seven hundred";
	if(i%1000<700 && i%1000>=600)
	cout<< " six hundred";
	if(i%1000<600 && i%1000>=500)
	cout<< " five hundred";
	if(i%1000<500 && i%1000>=400)
	cout<< " four hundred";
	if(i%1000<400 && i%1000>=300)
	cout<< " three hundred";
	if(i%1000<300 && i%1000>=200)
	cout<< " two hundred";
	if(i%1000<200 && i%1000>=100)
	cout<< " one hundred";

	if(i>100 && i%100>10)
	cout<< " and ";
	if(i%100<100 && i%100>=90)
	cout<< "ninety";
	if(i%100<90 && i%100>=80)
	cout<< "eighty";
	if(i%100<80 && i%100>=70)
	cout<< "seventy";
	if(i%100<70 && i%100>=60)
	cout<< "sixty";
	if(i%100<60 && i%100>=50)
	cout<< "fifty";
	if(i%100<50 && i%100>=40)
	cout<< "forty";
	if(i%100<40 && i%100>=30)
	cout<< "thirty";
	if(i%100<30 && i%100>=20)
	cout<< "twenty";

	if(i%100==19)
	cout<< "nineteen";
	if(i%100==18)
	cout<< "eighteen";
	if(i%100==17)
	cout<< "seventeen";
	if(i%100==16)
	cout<< "sixteen";
	if(i%100==15)
	cout<< "fifteen";
	if(i%100==14)
	cout<< "fourteen";
	if(i%100==13)
	cout<< "thirteen";
	if(i%100==12)
	cout<< "twelve";
	if(i%100==11)
	cout<< "eleven";
	if(i%100==10)
	cout<< "ten";

	if(i>10 && (i%100>19 || i%100<10) && i%10!=0)
	cout<< "-";
	if(i%10==9 && (i%100>19 || i%100<10))
	cout<< "nine";
	if(i%10==8 && (i%100>19 || i%100<10))
	cout<< "eight";
	if(i%10==7 && (i%100>19 || i%100<10))
	cout<< "seven";
	if(i%10==6 && (i%100>19 || i%100<10))
	cout<< "six";
	if(i%10==5 && (i%100>19 || i%100<10))
	cout<< "five";
	if(i%10==4 && (i%100>19 || i%100<10))
	cout<< "four";
	if(i%10==3 && (i%100>19 || i%100<10))
	cout<< "three";
	if(i%10==2 && (i%100>19 || i%100<10))
	cout<< "two";
	if(i%10==1 && (i%100>19 || i%100<10))
	cout<< "one";
	if (i == 0 ){ cout << "zero";}
	return 0;
}
