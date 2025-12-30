//My GitHub account: github.com/ABDLLH2PG
#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace MyDateLib
{
	// ------------------------------------------------
	// Enums Definitions:
	// ------------------------------------------------

	enum enDayOfWeek { Sat = 1, Sun = 2, Mon = 3, Tue = 4, Wed = 5, Thu = 6, Fri = 7 };

	enum enMonthOfYear { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };
	
	// ------------------------------------------------
	// Print Date:
	// ------------------------------------------------

	string GetDayOfWeek(enDayOfWeek Day)
	{
		switch (Day)
		{
		case enDayOfWeek::Sat:
			return "Saturday";
		case enDayOfWeek::Sun:
			return "Sunday";
		case enDayOfWeek::Mon:
			return "Monday";
		case enDayOfWeek::Tue:
			return "Tuesday";
		case enDayOfWeek::Wed:
			return "Wednesday";
		case enDayOfWeek::Thu:
			return "Thursday";
		case enDayOfWeek::Fri:
			return "Friday";
		default:
			return "Not a valid Day";
		}
	}

	string GetMonthOfYear(enMonthOfYear Month)
	{
		switch (Month)
		{
		case enMonthOfYear::Jan:
			return "January";
		case enMonthOfYear::Feb:
			return "February";
		case enMonthOfYear::Mar:
			return "March";
		case enMonthOfYear::Apr:
			return "April";
		case enMonthOfYear::May:
			return "May";
		case enMonthOfYear::Jun:
			return "June";
		case enMonthOfYear::Jul:
			return "July";
		case enMonthOfYear::Aug:
			return "August";
		case enMonthOfYear::Sep:
			return "September";
		case enMonthOfYear::Oct:
			return "October";
		case enMonthOfYear::Nov:
			return "November";
		case enMonthOfYear::Dec:
			return "December";
		default:
			return "Not a valid Month";
		}
	}

	// ------------------------------------------------
	// Time Conversions:
	// ------------------------------------------------

	float HoursToDays(float NumberOfHours)
	{
		return (float)NumberOfHours / 24;
	}

	float DaysToHours(float NumberOfDays)
	{
		return (float)NumberOfDays * 24;
	}

	float DaysToWeeks(float NumberOfDays)
	{
		return (float)NumberOfDays / 7;
	}

	float WeeksToDays(float NumberOfWeeks)
	{
		return (float)NumberOfWeeks * 7;
	}

	float HoursToWeeks(float NumberOfHours)
	{
		return (float)NumberOfHours / 24 / 7;
	}

	float WeeksToHours(float NumberOfWeeks)
	{
		return (float)NumberOfWeeks * 7 * 24;
	}

}