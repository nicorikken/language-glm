class collector {
	char1024 property;
	char32 trigger;
	char1024 file;
	int32 limit;
	char256 group;
	int32 flush;
	double interval[s];
}

class group_recorder {
	char256 file; // output file name
	char1024 group; // group definition string
	double interval[s]; // recordering interval (0 'every iteration', -1 'on change')
	double flush_interval[s]; // file flush interval (0 never, negative on samples)
	bool strict; // causes the group_recorder to stop the simulation should there be a problem opening or writing with the group_recorder
	bool print_units; // flag to append units to each written value, if applicable
	char256 property; // property to record
	int32 limit; // the maximum number of lines to write to the file
	enumeration {ANG_RAD=5, ANG_DEG=4, MAG=3, IMAG=2, REAL=1, NONE=0} complex_part; // the complex part to record if complex properties are gathered
}

class histogram {
	char1024 filename; // the name of the file to write
	char8 filetype; // the format to output a histogram in
	char32 mode; // the mode of file output
	char1024 group; // the GridLAB-D group expression to use for this histogram
	char1024 bins; // the specific bin values to use
	char256 property; // the property to sample
	double min; // the minimum value of the auto-sized bins to use
	double max; // the maximum value of the auto-sized bins to use
	double samplerate[s]; // the rate at which samples are read
	double countrate[s]; // the reate at which bins are counted and written
	int32 bin_count; // the number of auto-sized bins to use
	int32 limit; // the number of samples to write
}

class multi_recorder {
	double interval[s];
	char1024 property;
	char32 trigger;
	char1024 file;
	char8 filetype;
	char32 mode;
	char1024 multifile;
	int32 limit;
	char1024 plotcommands;
	char32 xdata;
	char32 columns;
	enumeration {SVG=6, PNG=5, PDF=4, JPG=3, GIF=2, EPS=1, SCREEN=0} output;
	enumeration {NONE=2, ALL=1, DEFAULT=0} header_units;
	enumeration {NONE=2, ALL=1, DEFAULT=0} line_units;
}

class player {
	char256 property;
	char1024 file;
	char8 filetype;
	char32 mode;
	int32 loop;
}

class player {
	char256 property;
	char1024 file;
	char8 filetype;
	char32 mode;
	int32 loop;
}

class recorder {
	char1024 property;
	char32 trigger;
	char1024 file;
	char8 filetype;
	char32 mode;
	char1024 multifile;
	int32 limit;
	char1024 plotcommands;
	char32 xdata;
	char32 columns;
	int32 flush;
	double interval[s];
	enumeration {SVG=6, PNG=5, PDF=4, JPG=3, GIF=2, EPS=1, SCREEN=0} output;
	enumeration {NONE=2, ALL=1, DEFAULT=0} header_units;
	enumeration {NONE=2, ALL=1, DEFAULT=0} line_units;
}

class shaper {
	char1024 file;
	char8 filetype;
	char32 mode;
	char256 group;
	char256 property;
	double magnitude;
	double events;
}

class violation_recorder {
	char256 file; // output file name
	char256 summary; // summary output file name
	char256 virtual_substation; // name of the substation node to monitor for reverse flow violation
	double interval[s]; // recording interval (0 'every iteration', -1 'on change')
	double flush_interval[s]; // file flush interval (0 never, negative on samples)
	bool strict; // causes the violation_recorder to stop the simulation should there be a problem opening or writing with the violation_recorder
	bool echo; // causes the violation_recorder to echo messages to the screen
	int32 limit; // the maximum number of lines to write to the file
	int32 violation_delay; // the number of seconds to skip before recording violations
	double xfrmr_thermal_limit_upper; // xfrmr_thermal_limit_upper
	double xfrmr_thermal_limit_lower; // xfrmr_thermal_limit_lower
	double line_thermal_limit_upper; // line_thermal_limit_upper
	double line_thermal_limit_lower; // line_thermal_limit_lower
	double node_instantaneous_voltage_limit_upper; // node_instantaneous_voltage_limit_upper
	double node_instantaneous_voltage_limit_lower; // node_instantaneous_voltage_limit_lower
	double node_continuous_voltage_limit_upper; // node_continuous_voltage_limit_upper
	double node_continuous_voltage_limit_lower; // node_continuous_voltage_limit_lower
	double node_continuous_voltage_interval; // node_continuous_voltage_interval
	double secondary_dist_voltage_rise_upper_limit; // secondary_dist_voltage_rise_upper_limit
	double secondary_dist_voltage_rise_lower_limit; // secondary_dist_voltage_rise_lower_limit
	double substation_breaker_A_limit; // breaker_phase_A_limit
	double substation_breaker_B_limit; // breaker_phase_B_limit
	double substation_breaker_C_limit; // breaker_phase_C_limit
	double substation_pf_lower_limit; // substation_pf_lower_limit
	double inverter_v_chng_per_interval_upper_bound; // inverter_v_chng_per_interval_upper_bound
	double inverter_v_chng_per_interval_lower_bound; // inverter_v_chng_per_interval_lower_bound
	double inverter_v_chng_interval; // inverter_v_chng_interval
	set {ALLVIOLATIONS=255, VIOLATION8=128, VIOLATION7=64, VIOLATION6=32, VIOLATION5=16, VIOLATION4=8, VIOLATION3=4, VIOLATION2=2, VIOLATION1=1, VIOLATION0=0} violation_flag; // bit set for determining which violations to check
}

