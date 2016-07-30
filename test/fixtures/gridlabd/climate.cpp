class climate {
	function calculate_solar_radiation_degrees();
	function calculate_solar_radiation_radians();
	function calculate_solar_radiation_shading_degrees();
	function calculate_solar_radiation_shading_radians();
	function calculate_solar_radiation_shading_position_radians();
	function calculate_solpos_radiation_shading_position_radians();
	function calc_solar_ideal_shading_position_radians();
	double solar_elevation;
	double solar_azimuth;
	char32 city;
	char1024 tmyfile;
	double temperature[degF];
	double humidity[%];
	double solar_flux[W/sf];
	double solar_direct[W/sf];
	double solar_diffuse[W/sf];
	double solar_global[W/sf];
	double extraterrestrial_direct_normal[W/sf];
	double pressure[mbar];
	double wind_speed[m/s];
	double wind_dir[deg];
	double wind_gust[mph];
	double record.low[degF];
	int32 record.low_day;
	double record.high[degF];
	int32 record.high_day;
	double record.solar[W/sf];
	double rainfall[in/h];
	double snowdepth[in];
	enumeration {QUADRATIC=2, LINEAR=1, NONE=0} interpolate; // the interpolation mode used on the climate data
	double solar_horiz;
	double solar_north;
	double solar_northeast;
	double solar_east;
	double solar_southeast;
	double solar_south;
	double solar_southwest;
	double solar_west;
	double solar_northwest;
	double solar_raw[W/sf];
	double ground_reflectivity[pu];
	object reader;
	char1024 forecast; // forecasting specifications
	enumeration {CUMULUS=1, NONE=0} cloud_model; // the cloud model to use
	double cloud_opacity[pu];
	double cloud_reflectivity[pu];
}

class climate {
	function calculate_solar_radiation_degrees();
	function calculate_solar_radiation_radians();
	function calculate_solar_radiation_shading_degrees();
	function calculate_solar_radiation_shading_radians();
	function calculate_solar_radiation_shading_position_radians();
	function calculate_solpos_radiation_shading_position_radians();
	function calc_solar_ideal_shading_position_radians();
	double solar_elevation;
	double solar_azimuth;
	char32 city;
	char1024 tmyfile;
	double temperature[degF];
	double humidity[%];
	double solar_flux[W/sf];
	double solar_direct[W/sf];
	double solar_diffuse[W/sf];
	double solar_global[W/sf];
	double extraterrestrial_direct_normal[W/sf];
	double pressure[mbar];
	double wind_speed[m/s];
	double wind_dir[deg];
	double wind_gust[mph];
	double record.low[degF];
	int32 record.low_day;
	double record.high[degF];
	int32 record.high_day;
	double record.solar[W/sf];
	double rainfall[in/h];
	double snowdepth[in];
	enumeration {QUADRATIC=2, LINEAR=1, NONE=0} interpolate; // the interpolation mode used on the climate data
	double solar_horiz;
	double solar_north;
	double solar_northeast;
	double solar_east;
	double solar_southeast;
	double solar_south;
	double solar_southwest;
	double solar_west;
	double solar_northwest;
	double solar_raw[W/sf];
	double ground_reflectivity[pu];
	object reader;
	char1024 forecast; // forecasting specifications
	enumeration {CUMULUS=1, NONE=0} cloud_model; // the cloud model to use
	double cloud_opacity[pu];
	double cloud_reflectivity[pu];
}

class csv_reader {
	int32 index;
	char32 city_name;
	char32 state_name;
	double lat_deg;
	double lat_min;
	double long_deg;
	double long_min;
	double low_temp;
	double high_temp;
	double peak_solar;
	int32 elevation;
	enumeration {ERROR=2, OPEN=1, INIT=0} status;
	char32 timefmt;
	char32 timezone;
	double timezone_offset;
	char256 columns;
	char256 filename;
}

class weather {
	double temperature[degF];
	double humidity[%];
	double solar_dir[W/sf];
	double solar_direct[W/sf];
	double solar_diff[W/sf];
	double solar_diffuse[W/sf];
	double solar_global[W/sf];
	double wind_speed[mph];
	double rainfall[in/h];
	double snowdepth[in];
	double pressure[mbar];
	int16 month;
	int16 day;
	int16 hour;
	int16 minute;
	int16 second;
}

