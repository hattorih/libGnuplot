/********************************************************************************
Copyright (c) 2013-2014 Hironori Hattori <hattorih@cs.cmu.edu>.
All rights reserved.
---------------------------------------------------------------------------------
$Id: $
********************************************************************************/

// "libGnuplot - Operator"

// Hironori Hattori, Carnegie Mellon University
// hattorih@cs.cmu.edu


#ifndef __LIB_GNUPLOT_OPERATOR_H__
#define __LIB_GNUPLOT_OPERATOR_H__


#include <string>


namespace Gnuplot
{


class Operator
{
public:
	Operator (void);

	~Operator (void);

	void command (const char *commandline, ...);

	void setGrid (void);

	void setTicsX (const float &value);
	void setTicsY (const float &value);
	void setTicsZ (const float &value);

	void setTicsXm (const float &value);
	void setTicsYm (const float &value);
	void setTicsZm (const float &value);

	void setLabelX (const char* label);
	void setLabelY (const char* label);
	void setLabel  (const char* label_x, const char* label_y);

	void setTitle  (const char* title);

	void setRangeX (const float &min, const float &max);
	void setRangeY (const float &min, const float &max);
	void setRange  (const float &min_x, const float &max_x, const float &min_y, const float &max_y);

	void setFormatX (const char *format);
	void setFormatY (const char *format);
	void setFormatZ (const char *format);

	void setLogscaleX (void);
	void setLogscaleY (void);
	void setLogscaleZ (void);

	void setFormat (const char *format);

	void replot(void);

	void toPng (const char* filename);
	void toEps (const char* filename);

	// Commands from File
	void load (const char* filename);

	// Commands to File
	void save (const char* filename);

private:
	FILE* mFp;
};


} // namespace Gnuplot


#endif // __LIB_GNUPLOT_OPERATOR_H__

