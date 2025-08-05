#include <iostream>
#include <time.h>
#include <stdio.h>
#include "../references/Account.hpp"


// timestamp should be year/month/day_hour/minutes/seconds
int main()
{
	
}

static void	displayAccountsInfos(void)
{

}

static void _displayTimestamp(void)
{
	time_t rawtime;
	char	ptr[17];
	struct tm *time_info;

	time(&rawtime);
	time_info = localtime (&rawtime);
	strftime(ptr, 16, "%d%m%Y_%H%M%S", time_info);

	std::cout <<"[" << ptr << "]" << "\n";
}

Account::Account(int initial_deposit)
{
	
}