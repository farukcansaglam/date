#include <stdio.h>

typedef unsigned int date;

date create_date(unsigned int,unsigned int,unsigned int);
void print_date(date);
void set_year(date*,unsigned int);
unsigned int get_year(date);
void set_month(date*,unsigned int);
unsigned int get_month(date);
void set_day(date*,unsigned int);
unsigned int get_day(date);
void set_hour(date*,unsigned int);
unsigned int get_hour(date);
void set_minute(date*,unsigned int);
unsigned int get_minute(date);

int main(){
	date d = create_date(2017,11,15);
	set_hour(&d,11);
	print_date(d);
}

date create_date(unsigned int year,unsigned int month,unsigned int day){
	date d = 0;
	d |= year << 20;
	d |= month << 16;
	d |= day << 11;
	return d;
}

void print_date(date d){
	printf("%u.%u.%u  %u:%u\n",get_year(d),get_month(d),get_day(d),get_hour(d),get_minute(d));
}

void set_year(date *d,unsigned int year){
	*d &= (~(((1 << 12) - 1) << 20));
	*d |= year << 20;
}

unsigned int get_year(date d){
	return d >> 20;
}

void set_month(date *d,unsigned int month){
	*d &= (~(((1 << 4) - 1) << 16));
	*d |= month << 16;
}

unsigned int get_month(date d){
	return (d & ~(((1 << 12) - 1) << 20)) >> 16; 
}

void set_day(date *d,unsigned int day){
	*d &= (~(((1 << 5) - 1) << 11));
	*d |= day << 11;
}

unsigned int get_day(date d){
	return (d & ~(((1 << 16) - 1) << 16)) >> 11; 
}

void set_hour(date *d,unsigned int hour){
	*d &= (~((1 << 6) - 1) << 6);
	*d |= hour << 6;
}

unsigned int get_hour(date d){
	return (d & ~(((1 << 21) - 1) << 11)) >> 6;
}

void set_minute(date *d,unsigned int minute){
	*d &= ~((1 << 6) - 1);
	*d |= minute;
}

unsigned int get_minute(date d){
	return (d & ~(((1 << 26) - 1) << 6));
}

