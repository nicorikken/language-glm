class ZIPload {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double heat_fraction; // fraction of ZIPload that is transferred as heat
	double base_power[kW]; // base real power of the overall load
	double power_pf; // power factor for constant power portion
	double current_pf; // power factor for constant current portion
	double impedance_pf; // power factor for constant impedance portion
	bool is_240; // load is 220/240 V (across both phases)
	double breaker_val[A]; // Amperage of connected breaker
	complex actual_power[kVA]; // variable to pull actual load as function of voltage
	double multiplier; // this variable is used to modify the base power as a function of multiplier x base_power
	bool heatgain_only; // allows the zipload to generate heat only (no kW), not activated by default
	bool demand_response_mode; // Activates equilibrium dynamic representation of demand response
	int16 number_of_devices; // Number of devices to model - base power is the total load of all devices
	int16 thermostatic_control_range; // Range of the thermostat's control operation
	double number_of_devices_off; // Total number of devices that are off
	double number_of_devices_on; // Total number of devices that are on
	double rate_of_cooling[K/h]; // rate at which devices cool down
	double rate_of_heating[K/h]; // rate at which devices heat up
	int16 temperature; // temperature of the device's controlled media (eg air temp or water temp)
	double phi; // duty cycle of the device
	double demand_rate[1/h]; // consumer demand rate that prematurely turns on a device or population
	double nominal_power; // the rated amount of power demanded by devices that are on
	double duty_cycle[pu]; // fraction of time in the on state
	double recovery_duty_cycle[pu]; // fraction of time in the on state, while in recovery interval
	double period[h]; // time interval to apply duty cycle
	double phase[pu]; // initial phase of load; duty will be assumed to occur at beginning of period
}

class appliance {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	complex_array powers;
	complex_array impedances;
	complex_array currents;
	double_array durations;
	double_array transitions;
	double_array heatgains;
}

class clotheswasher {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double motor_power[kW];
	double circuit_split;
	double queue[unit]; // the total laundry accumulated
	double demand[unit/day]; // the amount of laundry accumulating daily
	complex energy_meter[kWh];
	double stall_voltage[V];
	double start_voltage[V];
	double clothesWasherPower;
	complex stall_impedance[Ohm];
	double trip_delay[s];
	double reset_delay[s];
	double Is_on;
	double normal_perc;
	double perm_press_perc;
	double NORMAL_PREWASH_POWER;
	double NORMAL_WASH_POWER;
	double NORMAL_SPIN_LOW_POWER;
	double NORMAL_SPIN_MEDIUM_POWER;
	double NORMAL_SPIN_HIGH_POWER;
	double NORMAL_SMALLWASH_POWER;
	double NORMAL_PREWASH_ENERGY;
	double NORMAL_WASH_ENERGY;
	double NORMAL_SPIN_LOW_ENERGY;
	double NORMAL_SPIN_MEDIUM_ENERGY;
	double NORMAL_SPIN_HIGH_ENERGY;
	double NORMAL_SMALLWASH_ENERGY;
	double PERMPRESS_PREWASH_POWER;
	double PERMPRESS_WASH_POWER;
	double PERMPRESS_SPIN_LOW_POWER;
	double PERMPRESS_SPIN_MEDIUM_POWER;
	double PERMPRESS_SPIN_HIGH_POWER;
	double PERMPRESS_SMALLWASH_POWER;
	double PERMPRESS_PREWASH_ENERGY;
	double PERMPRESS_WASH_ENERGY;
	double PERMPRESS_SPIN_LOW_ENERGY;
	double PERMPRESS_SPIN_MEDIUM_ENERGY;
	double PERMPRESS_SPIN_HIGH_ENERGY;
	double PERMPRESS_SMALLWASH_ENERGY;
	double GENTLE_PREWASH_POWER;
	double GENTLE_WASH_POWER;
	double GENTLE_SPIN_LOW_POWER;
	double GENTLE_SPIN_MEDIUM_POWER;
	double GENTLE_SPIN_HIGH_POWER;
	double GENTLE_SMALLWASH_POWER;
	double GENTLE_PREWASH_ENERGY;
	double GENTLE_WASH_ENERGY;
	double GENTLE_SPIN_LOW_ENERGY;
	double GENTLE_SPIN_MEDIUM_ENERGY;
	double GENTLE_SPIN_HIGH_ENERGY;
	double GENTLE_SMALLWASH_ENERGY;
	double queue_min[unit];
	double queue_max[unit];
	double clotheswasher_run_prob;
	enumeration {SPIN4=9, SPIN3=8, SPIN2=7, SPIN1=6, WASH=5, PREWASH=4, STOPPED=0} state;
	enumeration {SMALLWASH=4, SPIN_WASH=3, SPIN_HIGH=2, SPIN_MEDIUM=1, SPIN_LOW=0} spin_mode;
	enumeration {GENTLE=2, PERM_PRESS=1, NORMAL=0} wash_mode;
}

class dishwasher {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double control_power[W];
	double dishwasher_coil_power_1[W];
	double dishwasher_coil_power_2[W];
	double dishwasher_coil_power_3[W];
	double motor_power[W];
	double circuit_split;
	double queue[unit]; // number of loads accumulated
	double stall_voltage[V];
	double start_voltage[V];
	complex stall_impedance[Ohm];
	double trip_delay[s];
	double reset_delay[s];
	double total_power[W];
	enumeration {HEATEDDRY_ONLY=7, CONTROL_ONLY=6, COIL_ONLY=3, MOTOR_COIL_ONLY=4, MOTOR_ONLY=5, TRIPPED=2, STALLED=1, STOPPED=0} state;
	double energy_baseline[kWh];
	double energy_used[kWh];
	bool control_check1;
	bool control_check2;
	bool control_check3;
	bool control_check4;
	bool control_check5;
	bool control_check6;
	bool control_check7;
	bool control_check8;
	bool control_check9;
	bool control_check10;
	bool control_check11;
	bool control_check12;
	bool control_check_temp;
	bool motor_only_check1;
	bool motor_only_check2;
	bool motor_only_check3;
	bool motor_only_check4;
	bool motor_only_check5;
	bool motor_only_check6;
	bool motor_only_check7;
	bool motor_only_check8;
	bool motor_only_check9;
	bool motor_only_temp1;
	bool motor_only_temp2;
	bool motor_coil_only_check1;
	bool motor_coil_only_check2;
	bool heateddry_check1;
	bool heateddry_check2;
	bool coil_only_check1;
	bool coil_only_check2;
	bool coil_only_check3;
	bool Heateddry_option_check;
	double queue_min[unit];
	double queue_max[unit];
	double pulse_interval_1[s];
	double pulse_interval_2[s];
	double pulse_interval_3[s];
	double pulse_interval_4[s];
	double pulse_interval_5[s];
	double pulse_interval_6[s];
	double pulse_interval_7[s];
	double pulse_interval_8[s];
	double pulse_interval_9[s];
	double pulse_interval_10[s];
	double pulse_interval_11[s];
	double pulse_interval_12[s];
	double pulse_interval_13[s];
	double pulse_interval_14[s];
	double pulse_interval_15[s];
	double pulse_interval_16[s];
	double pulse_interval_17[s];
	double pulse_interval_18[s];
	double pulse_interval_19[s];
	double dishwasher_run_prob;
	double energy_needed[kWh];
	double dishwasher_demand[kWh];
	double daily_dishwasher_demand[kWh];
	double actual_dishwasher_demand[kWh];
	double motor_on_off;
	double motor_coil_on_off;
	bool is_240; // load is 220/240 V (across both phases)
}

class dryer {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double motor_power[W];
	double dryer_coil_power[W];
	double controls_power[W];
	double circuit_split;
	double queue[unit]; // number of loads accumulated
	double queue_min[unit];
	double queue_max[unit];
	double stall_voltage[V];
	double start_voltage[V];
	complex stall_impedance[Ohm];
	double trip_delay[s];
	double reset_delay[s];
	double total_power[W];
	enumeration {CONTROL_ONLY=5, MOTOR_COIL_ONLY=3, MOTOR_ONLY=4, TRIPPED=2, STALLED=1, STOPPED=0} state;
	double energy_baseline[kWh];
	double energy_used[kWh];
	double next_t;
	bool control_check;
	bool motor_only_check1;
	bool motor_only_check2;
	bool motor_only_check3;
	bool motor_only_check4;
	bool motor_only_check5;
	bool motor_only_check6;
	bool dryer_on;
	bool dryer_ready;
	bool dryer_check;
	bool motor_coil_only_check1;
	bool motor_coil_only_check2;
	bool motor_coil_only_check3;
	bool motor_coil_only_check4;
	bool motor_coil_only_check5;
	bool motor_coil_only_check6;
	double dryer_run_prob;
	double dryer_turn_on;
	double pulse_interval_1[s];
	double pulse_interval_2[s];
	double pulse_interval_3[s];
	double pulse_interval_4[s];
	double pulse_interval_5[s];
	double pulse_interval_6[s];
	double pulse_interval_7[s];
	double energy_needed[kWh];
	double daily_dryer_demand[kWh];
	double actual_dryer_demand[kWh];
	double motor_on_off;
	double motor_coil_on_off;
	bool is_240; // load is 220/240 V (across both phases)
}

class evcharger {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	enumeration {HIGH=2, MEDIUM=1, LOW=0} charger_type;
	enumeration {HYBRID=1, ELECTRIC=0} vehicle_type;
	enumeration {WORK=1, HOME=0, UNKNOWN=4294967295} state;
	double p_go_home[unit/h];
	double p_go_work[unit/h];
	double work_dist[mile];
	double capacity[kWh];
	double charge[unit];
	bool charge_at_work;
	double charge_throttle[unit];
	double charger_efficiency[unit]; // Efficiency of the charger in terms of energy in to battery stored
	double power_train_efficiency[mile/kWh]; // Miles per kWh of battery charge
	double mileage_classification[mile]; // Miles expected range on battery only
	char1024 demand_profile;
}

class evcharger_det {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double charge_rate[W]; // Current demanded charge rate of the vehicle
	double variation_mean[s]; // Mean of normal variation of schedule variation
	double variation_std_dev[s]; // Standard deviation of normal variation of schedule times
	double variation_trip_mean[mile]; // Mean of normal variation of trip distance variation
	double variation_trip_std_dev[mile]; // Standard deviation of normal variation of trip distance
	double mileage_classification[mile]; // Mileage classification of electric vehicle
	bool work_charging_available; // Charging available when at work
	char1024 data_file; // Path to .CSV file with vehicle travel information
	int32 vehicle_index; // Index of vehicles in file this particular vehicle's data
	enumeration {DRIVING_WORK=4, DRIVING_HOME=3, WORK=2, HOME=1, UNKNOWN=0} vehicle_location;
	double travel_distance[mile]; // Distance vehicle travels from home to home
	double arrival_at_work; // Time vehicle arrives at work - HHMM
	double duration_at_work[s]; // Duration the vehicle remains at work
	double arrival_at_home; // Time vehicle arrives at home - HHMM
	double duration_at_home[s]; // Duration the vehicle remains at home
	double battery_capacity[kWh]; // Current capacity of the battery in kWh
	double battery_SOC[%]; // State of charge of battery
	double battery_size[kWh]; // Full capacity of battery
	double mileage_efficiency[mile/kWh]; // Efficiency of drive train in mile/kWh
	double maximum_charge_rate[W]; // Maximum output rate of charger in kW
	double charging_efficiency[unit]; // Efficiency of charger (ratio) when charging
}

class freezer {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double size[cf];
	double rated_capacity[Btu/h];
	double temperature[degF];
	double setpoint[degF];
	double deadband[degF];
	timestamp next_time;
	double output;
	double event_temp;
	double UA[Btu/degF*h];
	enumeration {ON=1, OFF=0} state;
}

class house {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	function attach_enduse();
	object weather; // reference to the climate object
	double floor_area[sf]; // home conditioned floor area
	double gross_wall_area[sf]; // gross outdoor wall area
	double ceiling_height[ft]; // average ceiling height
	double aspect_ratio; // aspect ratio of the home's footprint
	double envelope_UA[Btu/degF*h]; // overall UA of the home's envelope
	double window_wall_ratio; // ratio of window area to wall area
	double number_of_doors; // ratio of door area to wall area
	double exterior_wall_fraction; // ratio of exterior wall area to total wall area
	double interior_exterior_wall_ratio; // ratio of interior to exterior walls
	double exterior_ceiling_fraction; // ratio of external ceiling sf to floor area
	double exterior_floor_fraction; // ratio of floor area used in UA calculation
	double window_shading; // transmission coefficient through window due to glazing
	double window_exterior_transmission_coefficient; // coefficient for the amount of energy that passes through window
	double solar_heatgain_factor; // product of the window area, window transmitivity, and the window exterior transmission coefficient
	double airchange_per_hour[unit/h]; // number of air-changes per hour
	double airchange_UA[Btu/degF*h]; // additional UA due to air infiltration
	double UA[Btu/degF*h]; // the total UA
	double internal_gain[Btu/h]; // internal heat gains
	double solar_gain[Btu/h]; // solar heat gains
	double incident_solar_radiation[Btu/h*sf]; // average incident solar radiation hitting the house
	double heat_cool_gain[Btu/h]; // system heat gains(losses)
	set {W=16, S=8, E=4, N=2, H=1, NONE=0} include_solar_quadrant; // bit set for determining which solar incidence quadrants should be included in the solar heatgain
	double horizontal_diffuse_solar_radiation[Btu/h*sf]; // incident solar radiation hitting the top of the house
	double north_incident_solar_radiation[Btu/h*sf]; // incident solar radiation hitting the north side of the house
	double northwest_incident_solar_radiation[Btu/h*sf]; // incident solar radiation hitting the northwest side of the house
	double west_incident_solar_radiation[Btu/h*sf]; // incident solar radiation hitting the west side of the house
	double southwest_incident_solar_radiation[Btu/h*sf]; // incident solar radiation hitting the southwest side of the house
	double south_incident_solar_radiation[Btu/h*sf]; // incident solar radiation hitting the south side of the house
	double southeast_incident_solar_radiation[Btu/h*sf]; // incident solar radiation hitting the southeast side of the house
	double east_incident_solar_radiation[Btu/h*sf]; // incident solar radiation hitting the east side of the house
	double northeast_incident_solar_radiation[Btu/h*sf]; // incident solar radiation hitting the northeast side of the house
	enumeration {CURVED=3, LINEAR=2, FLAT=1, DEFAULT=0} heating_cop_curve; // Defines the function type to use for the adjusted heating COP as a function of outside air temperature.
	enumeration {CURVED=3, LINEAR=2, FLAT=1, DEFAULT=0} heating_cap_curve; // Defines the function type to use for the adjusted heating capacity as a function of outside air temperature.
	enumeration {CURVED=3, LINEAR=2, FLAT=1, DEFAULT=0} cooling_cop_curve; // Defines the function type to use for the adjusted cooling COP as a function of outside air temperature.
	enumeration {CURVED=3, LINEAR=2, FLAT=1, DEFAULT=0} cooling_cap_curve; // Defines the function type to use for the adjusted cooling capacity as a function of outside air temperature.
	bool use_latent_heat; // Boolean for using the heat latency of the air to the humidity when cooling.
	bool include_fan_heatgain; // Boolean to choose whether to include the heat generated by the fan in the ETP model.
	double thermostat_deadband[degF]; // deadband of thermostat control
	double dlc_offset[degF]; // used as a cap to offset the thermostat deadband for direct load control applications
	int16 thermostat_cycle_time; // minimum time in seconds between thermostat updates
	int16 thermostat_off_cycle_time; // the minimum amount of time the thermostat cycle must stay in the off state
	int16 thermostat_on_cycle_time; // the minimum amount of time the thermostat cycle must stay in the on state
	timestamp thermostat_last_cycle_time; // last time the thermostat changed state
	double heating_setpoint[degF]; // thermostat heating setpoint
	double cooling_setpoint[degF]; // thermostat cooling setpoint
	double design_heating_setpoint[degF]; // system design heating setpoint
	double design_cooling_setpoint[degF]; // system design cooling setpoint
	double over_sizing_factor; // over sizes the heating and cooling system from standard specifications (0.2 ='s 120% sizing)
	bool simulate_window_openings; // activates a representation of an occupant opening a window and de-activating the HVAC system
	double is_window_open; // defines the state of the window opening, 1=open, 2=closed
	double window_low_temperature_cutoff[degF]; // lowest temperature at which the window opening might occur
	double window_high_temperature_cutoff[degF]; // highest temperature at which the window opening might occur
	double window_quadratic_coefficient; // quadratic coefficient for describing function between low and high temperature cutoffs
	double window_linear_coefficient; // linear coefficient for describing function between low and high temperature cutoffs
	double window_constant_coefficient; // constant coefficient for describing function between low and high temperature cutoffs
	double window_temperature_delta; // change in outdoor temperature required to update the window opening model
	double design_heating_capacity[Btu/h]; // system heating capacity
	double design_cooling_capacity[Btu/h]; // system cooling capacity
	double cooling_design_temperature[degF]; // system cooling design temperature
	double heating_design_temperature[degF]; // system heating design temperature
	double design_peak_solar[Btu/h*sf]; // system design solar load
	double design_internal_gains[W/sf]; // system design internal gains
	double air_heat_fraction[pu]; // fraction of heat gain/loss that goes to air (as opposed to mass)
	double mass_solar_gain_fraction[pu]; // fraction of the heat gain/loss from the solar gains that goes to the mass
	double mass_internal_gain_fraction[pu]; // fraction of heat gain/loss from the internal gains that goes to the mass
	double auxiliary_heat_capacity[Btu/h]; // installed auxiliary heating capacity
	double aux_heat_deadband[degF]; // temperature offset from standard heat activation to auxiliary heat activation
	double aux_heat_temperature_lockout[degF]; // temperature at which auxiliary heat will not engage above
	double aux_heat_time_delay[s]; // time required for heater to run until auxiliary heating engages
	double cooling_supply_air_temp[degF]; // temperature of air blown out of the cooling system
	double heating_supply_air_temp[degF]; // temperature of air blown out of the heating system
	double duct_pressure_drop[inH2O]; // end-to-end pressure drop for the ventilation ducts, in inches of water
	double fan_design_power[W]; // designed maximum power draw of the ventilation fan
	double fan_low_power_fraction[pu]; // fraction of ventilation fan power draw during low-power mode (two-speed only)
	double fan_power[kW]; // current ventilation fan power draw
	double fan_design_airflow[cfm]; // designed airflow for the ventilation system
	double fan_impedance_fraction[pu]; // Impedance component of fan ZIP load
	double fan_power_fraction[pu]; // Power component of fan ZIP load
	double fan_current_fraction[pu]; // Current component of fan ZIP load
	double fan_power_factor[pu]; // Power factor of the fan load
	double heating_demand[kW]; // the current power draw to run the heating system
	double cooling_demand[kW]; // the current power draw to run the cooling system
	double heating_COP[pu]; // system heating performance coefficient
	double cooling_COP[Btu/kWh]; // system cooling performance coefficient
	double air_temperature[degF]; // indoor air temperature
	double outdoor_temperature[degF]; // outdoor air temperature
	double outdoor_rh[%]; // outdoor relative humidity
	double mass_heat_capacity[Btu/degF]; // interior mass heat capacity
	double mass_heat_coeff[Btu/degF*h]; // interior mass heat exchange coefficient
	double mass_temperature[degF]; // interior mass temperature
	double air_volume[cf]; // air volume
	double air_mass[lb]; // air mass
	double air_heat_capacity[Btu/degF]; // air thermal mass
	double latent_load_fraction[pu]; // fractional increase in cooling load due to latent heat
	double total_thermal_mass_per_floor_area[Btu/degF*sf];
	double interior_surface_heat_transfer_coeff[Btu/h*degF*sf];
	double number_of_stories; // number of stories within the structure
	double is_AUX_on; // logic statement to determine population statistics - is the AUX on? 0 no, 1 yes
	double is_HEAT_on; // logic statement to determine population statistics - is the HEAT on? 0 no, 1 yes
	double is_COOL_on; // logic statement to determine population statistics - is the COOL on? 0 no, 1 yes
	double thermal_storage_present; // logic statement for determining if energy storage is present
	double thermal_storage_in_use; // logic statement for determining if energy storage is being utilized
	enumeration {COOL=3, HEAT=2, AUTO=1, OFF=0} thermostat_mode; // tells the thermostat whether it is even allowed to heat or cool the house.
	set {RESISTIVE=16, TWOSTAGE=8, FORCEDAIR=4, AIRCONDITIONING=2, GAS=1, NONE=0} system_type; // heating/cooling system type/options
	set {LOCKOUT=4, TIMER=2, DEADBAND=1, NONE=0} auxiliary_strategy; // auxiliary heating activation strategies
	enumeration {AUX=3, COOL=4, OFF=1, HEAT=2, UNKNOWN=0} system_mode; // heating/cooling system operation state
	enumeration {AUX=3, COOL=4, OFF=1, HEAT=2, UNKNOWN=0} last_system_mode; // heating/cooling system operation state
	enumeration {RESISTANCE=4, HEAT_PUMP=3, GAS=2, NONE=1} heating_system_type;
	enumeration {HEAT_PUMP=2, ELECTRIC=2, NONE=1} cooling_system_type;
	enumeration {ELECTRIC=2, NONE=1} auxiliary_system_type;
	enumeration {TWO_SPEED=3, ONE_SPEED=2, NONE=1} fan_type;
	enumeration {UNKNOWN=7, VERY_GOOD=6, GOOD=5, ABOVE_NORMAL=4, NORMAL=3, BELOW_NORMAL=2, LITTLE=1, VERY_LITTLE=0} thermal_integrity_level; // default envelope UA settings
	enumeration {LOW_E_GLASS=2, GLASS=1, OTHER=0} glass_type; // glass used in the windows
	enumeration {INSULATED=4, WOOD=3, THERMAL_BREAK=2, ALUMINIUM=1, ALUMINUM=1, NONE=0} window_frame; // type of window frame
	enumeration {HIGH_S=5, LOW_S=4, REFL=3, ABS=2, CLEAR=1, OTHER=0} glazing_treatment; // the treatment to increase the reflectivity of the exterior windows
	enumeration {OTHER=4, THREE=3, TWO=2, ONE=1} glazing_layers; // number of layers of glass in each window
	enumeration {FULL=2, BASIC=1, NONE=0} motor_model; // indicates the level of detail used in modelling the hvac motor parameters
	enumeration {VERY_GOOD=4, GOOD=3, AVERAGE=2, POOR=1, VERY_POOR=0} motor_efficiency; // when using motor model, describes the efficiency of the motor
	int64 last_mode_timer;
	double hvac_motor_efficiency[unit]; // when using motor model, percent efficiency of hvac motor
	double hvac_motor_loss_power_factor[unit]; // when using motor model, power factor of motor losses
	double Rroof[degF*sf*h/Btu]; // roof R-value
	double Rwall[degF*sf*h/Btu]; // wall R-value
	double Rfloor[degF*sf*h/Btu]; // floor R-value
	double Rwindows[degF*sf*h/Btu]; // window R-value
	double Rdoors[degF*sf*h/Btu]; // door R-value
	double hvac_breaker_rating[A]; // determines the amount of current the HVAC circuit breaker can handle
	double hvac_power_factor[unit]; // power factor of hvac
	double hvac_load[kW]; // heating/cooling system load
	double last_heating_load[kW]; // stores the previous heating/cooling system load
	double last_cooling_load[kW]; // stores the previous heating/cooling system load
	complex hvac_power[kVA]; // describes hvac load complex power consumption
	double total_load[kW]; // total panel enduse load
	enduse panel; // the enduse load description
	complex panel.energy[kVAh]; // the total energy consumed since the last meter reading
	complex panel.power[kVA]; // the total power consumption of the load
	complex panel.peak_demand[kVA]; // the peak power consumption since the last meter reading
	double panel.heatgain[Btu/h]; // the heat transferred from the enduse to the parent
	double panel.cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
	double panel.heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
	double panel.current_fraction[pu]; // the fraction of total power that is constant current
	double panel.impedance_fraction[pu]; // the fraction of total power that is constant impedance
	double panel.power_fraction[pu]; // the fraction of the total power that is constant power
	double panel.power_factor; // the power factor of the load
	complex panel.constant_power[kVA]; // the constant power portion of the total load
	complex panel.constant_current[kVA]; // the constant current portion of the total load
	complex panel.constant_admittance[kVA]; // the constant admittance portion of the total load
	double panel.voltage_factor[pu]; // the voltage change factor
	double panel.breaker_amps[A]; // the rated breaker amperage
	set {IS220=1, IS110=0} panel.configuration; // the load configuration options
	double design_internal_gain_density[W/sf]; // average density of heat generating devices in the house
	bool compressor_on;
	int64 compressor_count;
	timestamp hvac_last_on;
	timestamp hvac_last_off;
	double hvac_period_length[s];
	double hvac_duty_cycle;
	enumeration {NONE=2, BAND=1, FULL=0} thermostat_control; // determine level of internal thermostatic control
}

class lights {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	enumeration {HID=4, SSL=3, CFL=2, FLUORESCENT=1, INCANDESCENT=0} type; // lighting type (affects power_factor)
	enumeration {OUTDOOR=1, INDOOR=0} placement; // lighting location (affects where heatgains go)
	double installed_power[kW]; // installed lighting capacity
	double power_density[W/sf]; // installed power density
	double curtailment[pu]; // lighting curtailment factor
	double demand[pu]; // the current lighting demand
	complex actual_power[kVA]; // actual power demand of lights object
}

class microwave {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double installed_power[kW]; // rated microwave power level
	double standby_power[kW]; // standby microwave power draw (unshaped only)
	double circuit_split;
	enumeration {ON=1, OFF=0} state; // on/off state of the microwave
	double cycle_length[s]; // length of the combined on/off cycle between uses
	double runtime[s]; // 
	double state_time[s]; // 
}

class occupantload {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	int32 number_of_occupants;
	double occupancy_fraction[unit];
	double heatgain_per_person[Btu/h];
}

class plugload {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double circuit_split;
	double demand[unit];
	double installed_power[kW]; // installed plugs capacity
	complex actual_power[kVA]; // actual power demand
}

class range {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double oven_volume[gal]; // the volume of the oven
	double oven_UA[Btu/degF*h]; // the UA of the oven (surface area divided by R-value)
	double oven_diameter[ft]; // the diameter of the oven
	double oven_demand[gpm]; // the hot food take out from the oven
	double heating_element_capacity[kW]; // the power of the heating element
	double inlet_food_temperature[degF]; // the inlet temperature of the food
	enumeration {GASHEAT=1, ELECTRIC=0} heat_mode; // the energy source for heating the oven
	enumeration {GARAGE=1, INSIDE=0} location; // whether the range is inside or outside
	double oven_setpoint[degF]; // the temperature around which the oven will heat its contents
	double thermostat_deadband[degF]; // the degree to heat the food in the oven, when needed
	double temperature[degF]; // the outlet temperature of the oven
	double height[ft]; // the height of the oven
	double food_density; // food density
	double specificheat_food;
	double queue_cooktop[unit]; // number of loads accumulated
	double queue_oven[unit]; // number of loads accumulated
	double queue_min[unit];
	double queue_max[unit];
	double time_cooktop_operation;
	double time_cooktop_setting;
	double cooktop_run_prob;
	double oven_run_prob;
	double cooktop_coil_setting_1[kW];
	double cooktop_coil_setting_2[kW];
	double cooktop_coil_setting_3[kW];
	double total_power_oven[kW];
	double total_power_cooktop[kW];
	double total_power_range[kW];
	double demand_cooktop[unit/day]; // number of loads accumulating daily
	double demand_oven[unit/day]; // number of loads accumulating daily
	double stall_voltage[V];
	double start_voltage[V];
	complex stall_impedance[Ohm];
	double trip_delay[s];
	double reset_delay[s];
	double time_oven_operation[s];
	double time_oven_setting[s];
	enumeration {CT_TRIPPED=6, CT_STALLED=5, STAGE_8_ONLY=4, STAGE_7_ONLY=3, STAGE_6_ONLY=2, CT_STOPPED=1} state_cooktop;
	double cooktop_energy_baseline[kWh];
	double cooktop_energy_used;
	double Toff;
	double Ton;
	double cooktop_interval_setting_1[s];
	double cooktop_interval_setting_2[s];
	double cooktop_interval_setting_3[s];
	double cooktop_energy_needed[kWh];
	bool heat_needed;
	bool oven_check;
	bool remainon;
	bool cooktop_check;
	double actual_load[kW]; // the actual load based on the current voltage across the coils
	double previous_load[kW]; // the actual load based on current voltage stored for use in controllers
	complex actual_power[kVA]; // the actual power based on the current voltage across the coils
	double is_range_on; // simple logic output to determine state of range (1-on, 0-off)
}

class refrigerator {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double size[cf]; // volume of the refrigerator
	double rated_capacity[Btu/h];
	double temperature[degF];
	double setpoint[degF];
	double deadband[degF];
	double cycle_time[s];
	double output;
	double event_temp;
	double UA[Btu/degF*h];
	double compressor_off_normal_energy;
	double compressor_off_normal_power[W];
	double compressor_on_normal_energy;
	double compressor_on_normal_power[W];
	double defrost_energy;
	double defrost_power[W];
	double icemaking_energy;
	double icemaking_power[W];
	double ice_making_probability;
	int32 FF_Door_Openings;
	int32 door_opening_energy;
	int32 door_opening_power;
	double DO_Thershold;
	double dr_mode_double;
	double energy_needed;
	double energy_used;
	double refrigerator_power;
	bool icemaker_running;
	int32 check_DO;
	bool is_240;
	double defrostDelayed;
	bool long_compressor_cycle_due;
	double long_compressor_cycle_time;
	double long_compressor_cycle_power;
	double long_compressor_cycle_energy;
	double long_compressor_cycle_threshold;
	enumeration {COMPRESSOR_TIME=3, DOOR_OPENINGS=2, TIMED=1} defrost_criterion;
	bool run_defrost;
	double door_opening_criterion;
	double compressor_defrost_time;
	double delay_defrost_time;
	int32 daily_door_opening;
	enumeration {COMPRESSSOR_ON_NORMAL=3, COMPRESSSOR_ON_LONG=4, COMPRESSSOR_OFF_NORMAL=2, DEFROST=1} state;
}

class residential_enduse {
	loadshape shape;
	enduse load; // the enduse load description
	complex energy[kVAh]; // the total energy consumed since the last meter reading
	complex power[kVA]; // the total power consumption of the load
	complex peak_demand[kVA]; // the peak power consumption since the last meter reading
	double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
	double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
	double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
	double current_fraction[pu]; // the fraction of total power that is constant current
	double impedance_fraction[pu]; // the fraction of total power that is constant impedance
	double power_fraction[pu]; // the fraction of the total power that is constant power
	double power_factor; // the power factor of the load
	complex constant_power[kVA]; // the constant power portion of the total load
	complex constant_current[kVA]; // the constant current portion of the total load
	complex constant_admittance[kVA]; // the constant admittance portion of the total load
	double voltage_factor[pu]; // the voltage change factor
	double breaker_amps[A]; // the rated breaker amperage
	set {IS220=1, IS110=0} configuration; // the load configuration options
	enumeration {OFF=2, ON=1, NORMAL=0} override;
	enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
}

class residential_enduse {
	loadshape shape;
	enduse load; // the enduse load description
	complex energy[kVAh]; // the total energy consumed since the last meter reading
	complex power[kVA]; // the total power consumption of the load
	complex peak_demand[kVA]; // the peak power consumption since the last meter reading
	double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
	double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
	double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
	double current_fraction[pu]; // the fraction of total power that is constant current
	double impedance_fraction[pu]; // the fraction of total power that is constant impedance
	double power_fraction[pu]; // the fraction of the total power that is constant power
	double power_factor; // the power factor of the load
	complex constant_power[kVA]; // the constant power portion of the total load
	complex constant_current[kVA]; // the constant current portion of the total load
	complex constant_admittance[kVA]; // the constant admittance portion of the total load
	double voltage_factor[pu]; // the voltage change factor
	double breaker_amps[A]; // the rated breaker amperage
	set {IS220=1, IS110=0} configuration; // the load configuration options
	enumeration {OFF=2, ON=1, NORMAL=0} override;
	enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
}

class thermal_storage {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double total_capacity[Btu]; // total storage capacity of unit
	double stored_capacity[Btu]; // amount of capacity that is stored
	double recharge_power[kW]; // installed compressor power usage
	double discharge_power[kW]; // installed pump power usage
	double recharge_pf; // installed compressor power factor
	double discharge_pf; // installed pump power factor
	enumeration {EXTERNAL=1, INTERNAL=0} discharge_schedule_type; // Scheduling method for discharging
	enumeration {EXTERNAL=1, INTERNAL=0} recharge_schedule_type; // Scheduling method for charging
	double recharge_time; // Flag indicating if recharging is available at the current time (1 or 0)
	double discharge_time; // Flag indicating if discharging is available at the current time (1 or 0)
	double discharge_rate[Btu/h]; // rating of discharge or cooling
	double SOC[%]; // state of charge as percentage of total capacity
	double k[W/m/K]; // coefficient of thermal conductivity (W/m/K)
}

class waterheater {
	parent residential_enduse;
	class residential_enduse {
		loadshape shape;
		enduse load; // the enduse load description
		complex energy[kVAh]; // the total energy consumed since the last meter reading
		complex power[kVA]; // the total power consumption of the load
		complex peak_demand[kVA]; // the peak power consumption since the last meter reading
		double heatgain[Btu/h]; // the heat transferred from the enduse to the parent
		double cumulative_heatgain[Btu]; // the cumulative heatgain from the enduse to the parent
		double heatgain_fraction[pu]; // the fraction of the heat that goes to the parent
		double current_fraction[pu]; // the fraction of total power that is constant current
		double impedance_fraction[pu]; // the fraction of total power that is constant impedance
		double power_fraction[pu]; // the fraction of the total power that is constant power
		double power_factor; // the power factor of the load
		complex constant_power[kVA]; // the constant power portion of the total load
		complex constant_current[kVA]; // the constant current portion of the total load
		complex constant_admittance[kVA]; // the constant admittance portion of the total load
		double voltage_factor[pu]; // the voltage change factor
		double breaker_amps[A]; // the rated breaker amperage
		set {IS220=1, IS110=0} configuration; // the load configuration options
		enumeration {OFF=2, ON=1, NORMAL=0} override;
		enumeration {UNKNOWN=2, ON=1, OFF=0} power_state;
	}

	double tank_volume[gal]; // the volume of water in the tank when it is full
	double tank_UA[Btu*h/degF]; // the UA of the tank (surface area divided by R-value)
	double tank_diameter[ft]; // the diameter of the water heater tank
	double tank_height[ft]; // the height of the water heater tank
	double water_demand[gpm]; // the hot water draw from the water heater
	double heating_element_capacity[kW]; // the power of the heating element
	double inlet_water_temperature[degF]; // the inlet temperature of the water tank
	enumeration {NONE=3, FORTRAN=2, TWONODE=1, ONEZNODE=0} waterheater_model; // the water heater model to use
	enumeration {HEAT_PUMP=2, GASHEAT=1, ELECTRIC=0} heat_mode; // the energy source for heating the water heater
	enumeration {GARAGE=1, INSIDE=0} location; // whether the water heater is inside or outside
	double tank_setpoint[degF]; // the temperature around which the water heater will heat its contents
	double thermostat_deadband[degF]; // the degree to heat the water tank, when needed
	double temperature[degF]; // the outlet temperature of the water tank
	double height[ft]; // the height of the hot water column within the water tank
	complex demand[kVA]; // the water heater power consumption
	double actual_load[kW]; // the actual load based on the current voltage across the coils
	double previous_load[kW]; // the actual load based on current voltage stored for use in controllers
	complex actual_power[kVA]; // the actual power based on the current voltage across the coils
	double is_waterheater_on; // simple logic output to determine state of waterheater (1-on, 0-off)
	double gas_fan_power[kW]; // load of a running gas waterheater
	double gas_standby_power[kW]; // load of a gas waterheater in standby
	double heat_pump_coefficient_of_performance[Btu/kWh]; // current COP of the water heater pump - currently calculated internally and not an input
	double Tcontrol[degF]; // in heat pump operation, defines the blended temperature used for turning on and off HP - currently calculated internally and not an input
	enumeration {EMPTY=2, PARTIAL=1, FULL=0} current_tank_status;
	double dr_signal; // the on/off signal to send to the fortran waterheater model
	double COP; // the cop of the fortran heat pump water heater model.
	double operating_mode; // the operating mode the fortran water heater should be using.
	double fortran_sim_time[s]; // the amount of time the fortran model should simulate.
	double waterheater_power[kW]; // the current power draw from the fortran water heater.
	enumeration {STABLE=2, RECOVERING=1, DEPLETING=0} load_state;
	enumeration {OV_OFF=2, OV_NORMAL=0, OV_ON=1} re_override; // the override setting for the water heater
}

