#pragma once
#include <stdio.h>
#include <time.h>

#include "Vector.h"
#include "String.h"
#include "ToggleSwitch.h"

typedef tm TimeStruct;// if you need

struct TaskItem {
	UTF_8 Title;
	UTF_8 Message;
	UTF_8 iiwake;
	time_t Time = 0;
	bool IsDeath = false;
//	bool (*Task)(TaskScheduler&)=NULL;
 	bool (*Task)()=NULL;
};

struct LoggerItem {
	UTF_8 Title;
	UTF_8 Message;
	time_t Time = 0;
	//bool IsDeath = false;
	ToggleSwitch T;// Off Is kill log
};

struct Logger {
	Vector<LoggerItem> V;
};

struct TaskScheduler {
	Vector<TaskItem> Task;
	Logger Log;
};

String StringFormater(char* Format, ...);
time_t GetTimeByStruct(tm& In);
//bool DoTask(TaskItem& In, TaskScheduler& Self);
bool DoTask(TaskItem& In);
tm GetTimeFormated_Local(TaskItem& In);
tm GetTimeFormated_GM(TaskItem& In);
bool New(TaskItem& In, char* Title, char* Message);
bool iieske(TaskItem& In, char* iiwake);
bool IsOver(TaskItem& In, const time_t& T);
bool IsNowOver(TaskItem& In);
time_t GetTime(TaskItem& In);
bool SetTime(TaskItem& In, const time_t& Base, const time_t& Advance);
bool Kill(TaskItem& In);
bool IsDeath(TaskItem& In);
bool Free(TaskItem& In);
bool New(LoggerItem& In, char* Title, char* Message);
tm GetTimeFormatted_GM(LoggerItem& In);
tm GetTimeFormatted_Local(LoggerItem& In);
bool ToKill(LoggerItem& In);
bool Free(LoggerItem& In);
Logger ConstructLogger();
bool Push(Logger& In, LoggerItem& B);
LoggerItem* Index(Logger& In, size_t N);
LoggerItem* Back(Logger& In);
bool Free(Logger& In);
TaskScheduler ConstructTaskScheduler();
bool Free(TaskScheduler& In);
bool SortByTime(TaskScheduler& In);