//My GitHub account: github.com/ABDLLH2PG
#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "MyInputLib.h"
#include "MyStringLib.h"

using namespace std;

namespace MyDateLib
{
	// ------------------------------------------------
	// Enums & Structs Definitions:
	// ------------------------------------------------

	enum enDayOfWeek { Sat = 1, Sun = 2, Mon = 3, Tue = 4, Wed = 5, Thu = 6, Fri = 7 };

	enum enMonthOfYear { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	struct stDate
	{
		short Year;
		short Month;
		short Day;
	};

	struct stPeriod
	{
		stDate StartDate;
		stDate EndDate;
	};

	// ------------------------------------------------
	// 1. Basic Year & Month Properties:
	// ------------------------------------------------

	bool IsLeapYear(short Year)
	{
		// if year is divisible by 4 AND bot divisible by 100
		// OR if year is divisible by 400
		// them it is a leap year

		return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
	}

	short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}

	int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}

	short NumberOfDaysInAMonth(short Year, short Month)
	{
		if (Month < 1 || Month > 12)
			return 0;

		int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return (Month == 2) ? IsLeapYear(Year) ? 29 : 28 : NumberOfDays[Month - 1];
	}

	short NumberOfHoursInAMonth(short Year, short Month)
	{
		return NumberOfDaysInAMonth(Year, Month) * 24;
	}

	int NumberOfMinutesInAMonth(short Year, short Month)
	{
		return NumberOfHoursInAMonth(Year, Month) * 60;
	}

	int NumberOfSecondsInAMonth(short Year, short Month)
	{
		return NumberOfMinutesInAMonth(Year, Month) * 60;
	}

	// ------------------------------------------------
	// 2. Names & Orders Functions:
	// ------------------------------------------------

	short DayOfWeekOrder(short Year, short Month, short Day)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder(stDate Date)
	{
		return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
	}

	string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return arrDayNames[DayOfWeekOrder];
	}

	string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
							  "Apr", "May", "Jun",
							  "Jul", "Aug", "Sep",
							  "Oct", "Nov", "Dec" };

		return (Months[MonthNumber - 1]);
	}

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
	// 3. Calendar Printing:
	// ------------------------------------------------

	void PrintMonthCalendar(short Year, short Month)
	{
		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(Year, Month, 1);

		int NumberOfDays = NumberOfDaysInAMonth(Year, Month);

		// Print the current month name
		printf("\n  _______________%s_______________\n\n",
			MonthShortName(Month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
		{
			printf("     ");
		}

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");
	}

	void PrintYearCalendar(short Year)
	{
		printf("\n  _________________________________\n");
		printf("\n         Calendar - %d", Year);
		printf("\n  _________________________________\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(Year, i);
		}
	}

	// ------------------------------------------------
	// 4. Date Conversion & Ordering:
	// ------------------------------------------------

	short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(Year, i);
		}

		return (TotalDays + Day);
	}

	stDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		stDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;

		Date.Year = Year;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Year, Date.Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
	}

	stDate ReadFullDate()
	{
		stDate Date;

		Date.Day = MyInputLib::ReadNumber("\nPlease enter a Day? ");
		Date.Month = MyInputLib::ReadNumber("\nPlease enter a Month? ");
		Date.Year = MyInputLib::ReadNumber("\nPlease enter a Year? ");

		return Date;
	}

	void PrintDate(stDate Date)
	{
		cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
	}

	// ------------------------------------------------
	// 5. Date Comparisons & Validation:
	// ------------------------------------------------

	bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year)
			? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month
				? Date1.Day < Date2.Day : false)) : false);
	}

	bool IsDate1EqualDate2(stDate Date1, stDate Date2)
	{
		return (Date1.Year == Date2.Year)
			? ((Date1.Month == Date2.Month)
				? ((Date1.Day == Date2.Day)
					? true : false) : false) : false;
	}

	bool IsDate1AfterDate2(stDate Date1, stDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
	}

	enDateCompare CompareDates(stDate Date1, stDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}

	bool IsLastDayInMonth(stDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
	}

	bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool IsValidDate(stDate Date)
	{
		if (Date.Day < 1 || Date.Day > 31)
			return false;

		if (Date.Month < 1 || Date.Month > 12)
			return false;

		if (Date.Month == 2)
		{
			if (IsLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		short DaysInAMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

		if (Date.Day > DaysInAMonth)
			return false;

		return true;
	}

	// ------------------------------------------------
	// 6. Date Swapping & Differences:
	// ------------------------------------------------

	void SwapDates(stDate& Date1, stDate& Date2)
	{
		stDate TempDate;

		TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;

		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;

		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;
	}

	stDate IncreaseDateByOneDay(stDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}

	int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return (IncludeEndDay ? ++Days : Days) * SwapFlagValue;
	}

	stDate GetSystemDate()
	{
		stDate Date;
		time_t t = time(0);
		tm* now = localtime(&t);

		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;
	}

	// ------------------------------------------------
	// 7. Date Addition Functions:
	// ------------------------------------------------

	stDate DateAddDays(stDate Date, short Days)
	{
		short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
		short MonthDays = 0;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;

				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	stDate IncreaseDateByOneDay(stDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}

	stDate IncreaseDateByXDays(short Days, stDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	stDate IncreaseDateByOneWeek(stDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}

	stDate IncreaseDateByOneMonth(stDate Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should 
		// not be 31 / 2 / 2022, it should be 28/2/2022

		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	stDate IncreaseDateByXMonth(short Months, stDate Date)
	{
		for (int i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}

	stDate IncreaseDateByOneYear(stDate Date)
	{
		Date.Year++;
		return Date;
	}

	stDate IncreaseDateByXYears(short Years, stDate Date)
	{
		Date.Year += Years;
		return Date;
	}

	stDate IncreaseDateByOneDecades(stDate Date)
	{
		Date.Year += 10;
		return Date;
	}

	stDate IncreaseDateByXDecades(short Decades, stDate Date)
	{
		Date.Year += Decades * 10;
		return Date;
	}

	stDate IncreaseDateByOneCentury(stDate Date)
	{
		Date.Year += 100;
		return Date;
	}

	stDate IncreaseDateByOneMillennium(stDate Date)
	{
		Date.Year += 1000;
		return Date;
	}

	// ------------------------------------------------
	// 8. Date Subtraction Functions:
	// ------------------------------------------------

	stDate DecreaseDateByOneDay(stDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
			}
		}
		else
		{
			Date.Day--;
		}

		return Date;
	}

	stDate DecreaseDateByXDay(short Days, stDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	stDate DecreaseDateByOneWeek(stDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;
	}

	stDate DecreaseDateByOneMonth(stDate Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}

		//last check day in date should not exceed max days in the current month
		//example if date is 31/3/2022 decreasing one month should not be 31/2/2022,
		//it should be 28/2/2022

		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	stDate DecreaseDateByXMonth(short Months, stDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}

	stDate DecreaseDateByOneYear(stDate Date)
	{
		Date.Year--;
		return Date;
	}

	stDate DecreaseDateByXYear(short Years, stDate Date)
	{
		Date.Year -= Years;
		return Date;
	}

	stDate DecreaseDateByOneDecade(stDate Date)
	{
		Date.Year -= 10;
		return Date;
	}

	stDate DecreaseDateByXDecade(short Decades, stDate Date)
	{
		Date.Year -= Decades * 10;
		return Date;
	}

	stDate DecreaseDateByOneCentury(stDate Date)
	{
		Date.Year -= 100;
		return Date;
	}

	stDate DecreaseDateByOneMillennium(stDate Date)
	{
		Date.Year -= 1000;
		return Date;
	}

	// ------------------------------------------------
	// 9. Weekends & Vacation Utilities:
	// ------------------------------------------------

	bool IsEndOfWeek(stDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}

	bool IsWeekEnd(stDate Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsBusinessDay(stDate Date)
	{
		return !IsWeekEnd(Date);
	}

	short DaysUntiTheEndOfWeek(stDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}

	short DaysUntiTheEndOfMonth(stDate Date)
	{
		stDate EndOfMonthDate;
		EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;

		return  GetDifferenceInDays(Date, EndOfMonthDate, true);
	}

	short DaysUntiTheEndOfYear(stDate Date)
	{
		stDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;

		return GetDifferenceInDays(Date, EndOfYearDate, true);
	}

	short CalculateVacationDays(stDate DateFrom, stDate DateTo)
	{
		short DaysCount = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DaysCount;
	}

	stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{
			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}

	// ------------------------------------------------
	// 10. Period & Overlap Utilities:
	// ------------------------------------------------

	bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
	{
		if (
			CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before
			||
			CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After
			)
			return false;
		else
			return true;
	}

	int PeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
	}

	bool IsDateInPeriod(stDate Date, stPeriod Period)
	{
		return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before

			||
			CompareDates(Date, Period.EndDate) == enDateCompare::After);
	}

	int CountOverlapDays(stPeriod Period1, stPeriod Period2)
	{
		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);
		int OverlapDays = 0;

		if (!IsOverlapPeriods(Period1, Period2))
			return 0;

		if (Period1Length < Period2Length)
		{
			while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateInPeriod(Period1.StartDate, Period2))
					OverlapDays++;

				Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);

			}
		}
		else
		{
			while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsDateInPeriod(Period2.StartDate, Period1))
					OverlapDays++;

				Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
			}
		}

		return OverlapDays;
	}

	// ------------------------------------------------
	// 11. String <-> Date & Formatting:
	// ------------------------------------------------

	stDate StringToDate(string DateString)
	{
		stDate Date;
		vector <string> vDate;

		vDate = MyStringLib::SplitString(DateString, "/");
		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;
	}

	string DateToString(stDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string FormateDate(stDate Date, string DateFormate = "dd/mm/yyyy")
	{
		string FormattedDateString = "";
		FormattedDateString = MyStringLib::ReplaceWordInStringUsingBuiltInFunction(DateFormate, "dd", to_string(Date.Day));
		FormattedDateString = MyStringLib::ReplaceWordInStringUsingBuiltInFunction(FormattedDateString, "mm", to_string(Date.Month));
		FormattedDateString = MyStringLib::ReplaceWordInStringUsingBuiltInFunction(FormattedDateString, "yyyy", to_string(Date.Year));

		return FormattedDateString;
	}

	// ------------------------------------------------
	// 12. Time Conversions:
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