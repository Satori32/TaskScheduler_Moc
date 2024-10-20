/** /#include <stdio.h>
#include <time.h>

#include "Vector.h"
#include "String.h"

struct TaskItem {
	UTF_8 Title;
	UTF_8 Message;
	UTF_8 iiwake;
	time_t Time = 0;
	bool IsDeath = false;
};

String StringFormater(char* Format, ...) {//need Free();
	va_list V = NULL;
	char Buff[10230] = {0,};

	va_start(V, Format);
	sprintf(Buff, Format, V);

	String S = ConstructString(Buff, strlen(Buff));
	//va_end(V);

	return S;
}

bool New(TaskItem& In, char* Title, char* Message) {
	Free(In.Title);
	Free(In.Message);

	
	From(In.Title,Title, strlen(Title));
	From(In.Message,Message, strlen(Message));	

	In.Time = time(NULL);
	
	return true;
}
bool iieske(TaskItem& In, char* iiwake) {
	UTF_8 U;
	From(U, iiwake, strlen(iiwake));
	Add(In.iiwake, U);
	Free(U);
	
}
bool IsOver(TaskItem& In,const time_t& T) {
	if (In.Time < T) return true;
	return false;
}
bool IsNowOver(TaskItem& In) {
	if (In.Time < time(NULL)) return true;
	return false;
}
time_t GetTime(TaskItem& In) {
	return In.Time;
}
bool SetTime(TaskItem& In, const time_t& Base,const time_t& Advance){
	In.Time = Base + Advance;
	return true;
}

bool Kill(TaskItem& In) {
	In.IsDeath = true;
	return true;
}
bool IsDeath(TaskItem& In) {
	return In.IsDeath;
}
bool Free(TaskItem& In) {
	Free(In.Title);
	Free(In.Message);
}
struct LoggerItem {
	UTF_8 Title;
	UTF_8 Message;
	time_t Time = 0;
	bool IsDeath = false;
 };

bool New(LoggerItem& In, char* Title, char* Message) {
	From(In.Title, Title, strlen(Title));
	From(In.Title, Message, strlen(Message));
	In.Time = time(NULL);
	return true;
}
bool ToKill(LoggerItem& In) {
	In.IsDeath = false;
	return true;
}
bool Free(LoggerItem& In) {
	Free(In.Title);
	Free(In.Message);
	In.IsDeath = true;
	In.Time = NULL;
	return true;
}

struct Logger {
	Vector<LoggerItem> V;
};

Logger ConstructLogger() {
	Logger L;
	L.V = ConstructVector<LoggerItem>(16);
	return L;
}

bool Push(Logger& In, LoggerItem& B) {
	Push(In.V,B);
	return true;
}
LoggerItem* Index(Logger& In, size_t N) {
	size_t DC = 0;
	for (size_t i = 0; i < Size(In.V); i++) {
		if (Index(In.V, i) == NULL) { return NULL; }
		if (Index(In.V, i)->IsDeath) { DC++; }
		if ((i - DC) == N) { return Index(In.V, i); }
	}
	return NULL;
}

LoggerItem* Back(Logger& In) {
	for (intmax_t i = Size(In.V) - 1; i >= 0; i--) {
		if (Index(In.V, i) == NULL) { return NULL; }
		if (Index(In.V, i)->IsDeath != true) { return Index(In.V, i); }
	}

	return NULL;
}
bool Free(Logger& In) {
	for (size_t i = 0; i < Size(In.V); i++) {
		if (Index(In.V, i) == NULL) { return false; }
		Free(*Index(In.V, i));
	}
	Free(In.V);
	return true;
}

struct TaskScheduler {
	Vector<TaskItem> Task;
	Logger Log;
};

TaskScheduler ConstructTaskScheduler() {
	TaskScheduler T;
	T.Task = ConstructVector<TaskItem>(16);
	T.Log =  ConstructLogger();
	return T;
}
bool Free(TaskScheduler& In) {
	for (size_t i = 0; i < Size(In.Task); i++) {
		if (Index(In.Task, i) == NULL) { return false; }
		Free(*Index(In.Task, i));
	}
	Free(In.Task);

	for (size_t i = 0; i < Size(In.Log.V); i++) {
		if (Index(In.Log.V, i) == NULL) { return false; }
		Free(*Index(In.Log.V, i));
	}
	Free(In.Log.V);

	return true;
}
/**/