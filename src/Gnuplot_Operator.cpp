#include "Gnuplot_Operator.h"

#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <fstream>

#pragma warning(disable: 4996)


#define PATH_GNUPLOT        "C:\\vendor\\libgnuplot\\binary\\gnuplot_4.6.3\\bin\\pgnuplot.exe"
#define PATH_POSTSCRIPT_DIR "C:\\vendor\\libgnuplot\\binary\\gnuplot_4.6.3\\share\\PostScript"


namespace Gnuplot
{


Operator::Operator (void) : mFp(NULL)
{
	mFp = _popen(PATH_GNUPLOT, "w");
}


Operator::~Operator (void)
{
	_pclose(mFp);
}


void Operator::command (const char *commandline, ...)
{
	if (mFp == NULL)
	{
		; // Can't find gnuplot
	}
	else
	{
		char buf[BUFSIZ];
		va_list ap;

		va_start(ap, commandline);
		vsprintf(buf, commandline, ap);
		va_end(ap);

		fprintf(mFp, "%s\n", buf);

		fflush(mFp);
	}
}


void Operator::setGrid (void)
{
	command ("set grid");
}


void Operator::setTicsX (const float &value)
{
	command ("set xtics %f", value);
}


void Operator::setTicsY (const float &value)
{
	command ("set ytics %f", value);
}


void Operator::setTicsZ (const float &value)
{
	command ("set ztics %f", value);
}


void Operator::setTicsXm (const float &value)
{
	command ("set mxtics %f", value);
}


void Operator::setTicsYm (const float &value)
{
	command ("set mytics %f", value);
}


void Operator::setTicsZm (const float &value)
{
	command ("set mztics %f", value);
}


void Operator::setLabelX (const char* label)
{
	command ("set xlabel '%s'", label);
}


void Operator::setLabelY (const char* label)
{
	command ("set ylabel '%s'", label);
}


void Operator::setLabel (const char* label_x, const char* label_y)
{
	setLabelX(label_x);
	setLabelY(label_y);
}


void Operator::setTitle  (const char* title)
{
	command ("set title '%s'", title);
}


void Operator::setRangeX (const float &min, const float &max)
{
	command ("set xrange [%f:%f]", min, max);
}


void Operator::setRangeY (const float &min, const float &max)
{
	command ("set yrange [%f:%f]", min, max);
}


void Operator::setRange  (const float &min_x, const float &max_x, const float &min_y, const float &max_y)
{
	setRangeX (min_x, max_x);
	setRangeY (min_y, max_y);
}


void Operator::setFormatX (const char *format)
{
	command ("set format x '%s'", format);
}


void Operator::setFormatY (const char *format)
{
	command ("set format y '%s'", format);
}


void Operator::setFormatZ (const char *format)
{
	command ("set format z '%s'", format);
}


void Operator::setFormat  (const char *format)
{
	command ("set format '%s'", format);
}


void Operator::setLogscaleX (void)
{
	command ("set logscale x");
}


void Operator::setLogscaleY (void)
{
	command ("set logscale y");
}


void Operator::setLogscaleZ (void)
{
	command ("set logscale z");
}


void Operator::replot (void)
{
	command ("replot");
}


void Operator::toPng (const char* filename)
{
	command ("set terminal png");
	command ("set output '%s'", filename);
	command ("replot");

	command ("set output");
	command ("set terminal window");
}


void Operator::toEps (const char* filename)
{
	command ("set loadpath '%s'", PATH_POSTSCRIPT_DIR);

	command ("set terminal postscript eps enhanced color");
	command ("set output '%s'", filename);
	command ("replot");

	command ("set output");
	command ("set terminal window");
}


void Operator::load (const char* filename)
{
	command ("load '%s'", filename);
}


void Operator::save (const char* filename)
{
	command ("save '%s'", filename);
}


} // namespace Gnuplot

