class auction {
	function submit_bid_state();
	function get_market_for_time();
	function register_participant();
	char32 unit; // unit of quantity
	double period[s]; // interval of time between market clearings
	double latency[s]; // latency between market clearing and delivery
	int64 market_id; // unique identifier of market clearing
	object network; // the comm network used by object to talk to the market (if any)
	bool verbose; // enable verbose auction operations
	object linkref; // (DEPRECATED) reference to link object that has demand as power_out (only used when not all loads are bidding)
	double pricecap; // (DEPRECATED) the maximum price (magnitude) allowed
	double price_cap; // the maximum price (magnitude) allowed
	enumeration {BUYERS_ONLY=2, SELLERS_ONLY=1, NONE=0} special_mode;
	enumeration {OFF=1, ON=0} statistic_mode;
	double fixed_price;
	double fixed_quantity;
	object capacity_reference_object;
	char32 capacity_reference_property;
	double capacity_reference_bid_price;
	double max_capacity_reference_bid_quantity;
	double capacity_reference_bid_quantity;
	double init_price;
	double init_stdev;
	double future_mean_price;
	bool use_future_mean_price;
	timestamp current_market.start_time;
	timestamp current_market.end_time;
	double current_market.clearing_price[$];
	double current_market.clearing_quantity;
	enumeration {NULL=0, FAILURE=5, EXACT=4, MARGINAL_PRICE=3, MARGINAL_BUYER=2, MARGINAL_SELLER=1} current_market.clearing_type;
	double current_market.marginal_quantity_load;
	double current_market.marginal_quantity;
	double current_market.marginal_quantity_bid;
	double current_market.marginal_quantity_frac;
	double current_market.seller_total_quantity;
	double current_market.buyer_total_quantity;
	double current_market.seller_min_price;
	double current_market.buyer_total_unrep;
	double current_market.cap_ref_unrep;
	timestamp next_market.start_time;
	timestamp next_market.end_time;
	double next_market.clearing_price[$];
	double next_market.clearing_quantity;
	enumeration {NULL=0, FAILURE=5, EXACT=4, MARGINAL_PRICE=3, MARGINAL_BUYER=2, MARGINAL_SELLER=1} next_market.clearing_type;
	double next_market.marginal_quantity_load;
	double next_market.marginal_quantity_bid;
	double next_market.marginal_quantity_frac;
	double next_market.seller_total_quantity;
	double next_market.buyer_total_quantity;
	double next_market.seller_min_price;
	double next_market.cap_ref_unrep;
	timestamp past_market.start_time;
	timestamp past_market.end_time;
	double past_market.clearing_price[$];
	double past_market.clearing_quantity;
	enumeration {NULL=0, FAILURE=5, EXACT=4, MARGINAL_PRICE=3, MARGINAL_BUYER=2, MARGINAL_SELLER=1} past_market.clearing_type;
	double past_market.marginal_quantity_load;
	double past_market.marginal_quantity_bid;
	double past_market.marginal_quantity_frac;
	double past_market.seller_total_quantity;
	double past_market.buyer_total_quantity;
	double past_market.seller_min_price;
	double past_market.cap_ref_unrep;
	enumeration {PROB=2, DENY=1, NORMAL=0} margin_mode;
	int32 warmup;
	enumeration {TRUE=1, FALSE=0} ignore_failed_market;
	enumeration {TRUE=1, FALSE=0} ignore_pricecap;
	char256 transaction_log_file;
	int32 transaction_log_limit;
	char256 curve_log_file;
	int32 curve_log_limit;
	enumeration {EXTRA=1, NORMAL=0} curve_log_info;
}

class auction {
	function submit_bid_state();
	function get_market_for_time();
	function register_participant();
	char32 unit; // unit of quantity
	double period[s]; // interval of time between market clearings
	double latency[s]; // latency between market clearing and delivery
	int64 market_id; // unique identifier of market clearing
	object network; // the comm network used by object to talk to the market (if any)
	bool verbose; // enable verbose auction operations
	object linkref; // (DEPRECATED) reference to link object that has demand as power_out (only used when not all loads are bidding)
	double pricecap; // (DEPRECATED) the maximum price (magnitude) allowed
	double price_cap; // the maximum price (magnitude) allowed
	enumeration {BUYERS_ONLY=2, SELLERS_ONLY=1, NONE=0} special_mode;
	enumeration {OFF=1, ON=0} statistic_mode;
	double fixed_price;
	double fixed_quantity;
	object capacity_reference_object;
	char32 capacity_reference_property;
	double capacity_reference_bid_price;
	double max_capacity_reference_bid_quantity;
	double capacity_reference_bid_quantity;
	double init_price;
	double init_stdev;
	double future_mean_price;
	bool use_future_mean_price;
	timestamp current_market.start_time;
	timestamp current_market.end_time;
	double current_market.clearing_price[$];
	double current_market.clearing_quantity;
	enumeration {NULL=0, FAILURE=5, EXACT=4, MARGINAL_PRICE=3, MARGINAL_BUYER=2, MARGINAL_SELLER=1} current_market.clearing_type;
	double current_market.marginal_quantity_load;
	double current_market.marginal_quantity;
	double current_market.marginal_quantity_bid;
	double current_market.marginal_quantity_frac;
	double current_market.seller_total_quantity;
	double current_market.buyer_total_quantity;
	double current_market.seller_min_price;
	double current_market.buyer_total_unrep;
	double current_market.cap_ref_unrep;
	timestamp next_market.start_time;
	timestamp next_market.end_time;
	double next_market.clearing_price[$];
	double next_market.clearing_quantity;
	enumeration {NULL=0, FAILURE=5, EXACT=4, MARGINAL_PRICE=3, MARGINAL_BUYER=2, MARGINAL_SELLER=1} next_market.clearing_type;
	double next_market.marginal_quantity_load;
	double next_market.marginal_quantity_bid;
	double next_market.marginal_quantity_frac;
	double next_market.seller_total_quantity;
	double next_market.buyer_total_quantity;
	double next_market.seller_min_price;
	double next_market.cap_ref_unrep;
	timestamp past_market.start_time;
	timestamp past_market.end_time;
	double past_market.clearing_price[$];
	double past_market.clearing_quantity;
	enumeration {NULL=0, FAILURE=5, EXACT=4, MARGINAL_PRICE=3, MARGINAL_BUYER=2, MARGINAL_SELLER=1} past_market.clearing_type;
	double past_market.marginal_quantity_load;
	double past_market.marginal_quantity_bid;
	double past_market.marginal_quantity_frac;
	double past_market.seller_total_quantity;
	double past_market.buyer_total_quantity;
	double past_market.seller_min_price;
	double past_market.cap_ref_unrep;
	enumeration {PROB=2, DENY=1, NORMAL=0} margin_mode;
	int32 warmup;
	enumeration {TRUE=1, FALSE=0} ignore_failed_market;
	enumeration {TRUE=1, FALSE=0} ignore_pricecap;
	char256 transaction_log_file;
	int32 transaction_log_limit;
	char256 curve_log_file;
	int32 curve_log_limit;
	enumeration {EXTRA=1, NORMAL=0} curve_log_info;
}

class controller {
	enumeration {DOUBLE_RAMP=6, WATERHEATER=5, HOUSE_PRECOOL=4, HOUSE_PREHEAT=3, HOUSE_COOL=2, HOUSE_HEAT=1, NONE=0} simple_mode;
	enumeration {PROXY=2, OFF=0, ON=1} bid_mode;
	enumeration {ON=1, OFF=0} use_override;
	double ramp_low[degF]; // the comfort response below the setpoint
	double ramp_high[degF]; // the comfort response above the setpoint
	double range_low; // the setpoint limit on the low side
	double range_high; // the setpoint limit on the high side
	char32 target; // the observed property (e.g., air temperature)
	char32 setpoint; // the controlled property (e.g., heating setpoint)
	char32 demand; // the controlled load when on
	char32 load; // the current controlled load
	char32 total; // the uncontrolled load (if any)
	char32 market; // the market to bid into
	char32 state; // the state property of the controlled load
	char32 avg_target;
	char32 std_target;
	double bid_price; // the bid price
	double bid_quantity; // the bid quantity
	double set_temp[degF]; // the reset value
	double base_setpoint[degF];
	double market_price; // the current market clearing price seen by the controller.
	double period[s]; // interval of time between market clearings
	enumeration {DEV_LEVEL=2, DOUBLE_RAMP=1, RAMP=0} control_mode;
	enumeration {SLIDING=1, DEADBAND=0} resolve_mode;
	double slider_setting;
	double slider_setting_heat;
	double slider_setting_cool;
	char32 override;
	double heating_range_high[degF];
	double heating_range_low[degF];
	double heating_ramp_high;
	double heating_ramp_low;
	double cooling_range_high[degF];
	double cooling_range_low[degF];
	double cooling_ramp_high;
	double cooling_ramp_low;
	double heating_base_setpoint[degF];
	double cooling_base_setpoint[degF];
	char32 deadband;
	char32 heating_setpoint;
	char32 heating_demand;
	char32 cooling_setpoint;
	char32 cooling_demand;
	double sliding_time_delay[s]; // time interval desired for the sliding resolve mode to change from cooling or heating to off
	bool use_predictive_bidding;
	double device_actively_engaged;
	int32 cleared_market;
	int32 locked;
	double p_ON;
	double p_OFF;
	double p_ONLOCK;
	double p_OFFLOCK;
	double delta_u;
	char32 regulation_market_on; // the willing to change state from ON->OFF market to bid into for regulation case
	char32 regulation_market_off; // the willing to change state from OFF->ON market to bid into for regulation case
	double fast_regulation_signal[s]; // the regulation signal that the controller compares against (i.e., how often is there a control action
	double market_price_on; // the current market clearing price seen by the controller in ON->OFF regulation market
	double market_price_off; // the current market clearing price seen by the controller  in OFF->ON regulation market
	double period_on[s]; // interval of time between market clearings in ON->OFF regulation market
	double period_off[s]; // interval of time between market clearings in  OFF->ON regulation market
	int32 regulation_period; // fast regulation signal period
	double r1; // temporary diagnostic variable
	double mu0; // temporary diagnostic variable
	double mu1; // temporary diagnostic variable
	char32 average_target;
	char32 standard_deviation_target;
	int64 bid_id;
	int32 bid_delay;
	char32 thermostat_state; // The name of the thermostat state property within the object being controlled
	double proxy_average;
	double proxy_standard_deviation;
	int64 proxy_market_id;
	int64 proxy_market2_id;
	double proxy_clear_price[$];
	double proxy_price_cap;
	char32 proxy_market_unit;
	double proxy_initial_price;
}

class double_controller {
	enumeration {COOL=3, HEAT=2, OFF=1, INVALID=0} thermostat_mode;
	enumeration {COOL=3, HEAT=2, OFF=1, INVALID=0} last_mode;
	enumeration {STICKY=2, DEADBAND=1, NONE=0} resolve_mode;
	enumeration {HOUSE=1, NONE=0} setup_mode;
	enumeration {OFF=0, ON=1} bid_mode;
	int64 last_mode_timer;
	double cool_ramp_low;
	double cool_ramp_high;
	double cool_range_low;
	double cool_range_high;
	double cool_set_base;
	double cool_setpoint;
	double heat_ramp_low;
	double heat_ramp_high;
	double heat_range_low;
	double heat_range_high;
	double heat_set_base;
	double heat_setpoint;
	char32 temperature_name;
	char32 cool_setpoint_name;
	char32 cool_demand_name;
	char32 heat_setpoint_name;
	char32 heat_demand_name;
	char32 load_name;
	char32 total_load_name;
	char32 deadband_name;
	char32 state_name;
	object market; // the market to bid into
	double market_period;
	double bid_price; // the bid price
	double bid_quant; // the bid quantity
	char32 load; // the current controlled load
	char32 total; // the uncontrolled load (if any)
	double last_price;
	double temperature;
	double cool_bid;
	double heat_bid;
	double cool_demand;
	double heat_demand;
	double price;
	double avg_price;
	double stdev_price;
}

class generator_controller {
	enumeration {STARTING=2, RUNNING=1, OFF=0} generator_state; // Current generator state
	enumeration {LINEAR_BID=2, LINEAR_COST=1, EXPONENTIAL=0} amortization_type; // Amortization compounding method
	int32 generator_state_number; // Current generator state as numeric value
	object market; // Market the object will watch and bid into
	char1024 bid_curve; // Bidding curve text format
	char1024 bid_curve_file; // Bidding curve file name
	double bid_generator_rating[VA]; // Size of generator in VA for the bid curve
	bool update_curve; // Flag to force updating of bidding curve parse
	bool is_marginal_gen; // Flag to indicate if the generator is a marginal generator
	double generator_rating[VA]; // Size of generator in VA for the active bid
	double generator_output; // Current real power output of generator
	double input_unit_base[MW]; // Base multiplier for generator bid units
	double startup_cost[$]; // Cost to start the generator from OFF status
	double shutdown_cost[$]; // Cost to shut down the generator prematurely
	double minimum_runtime[s]; // Minimum time the generator should run to avoid shutdown cost
	double minimum_downtime[s]; // Minimum down time for the generator before it can bid again
	double capacity_factor; // Calculation of generator's current capacity factor based on the market period
	double amortization_factor[1/s]; // Exponential decay factor in 1/s for shutdown cost repayment
	double bid_delay; // Time before a market closes to bid
	enumeration {BUILDING=1, STANDALONE=0} generator_attachment; // Generator attachment type - determines interactions
	double building_load_curr; // Present building load value (if BUILDING attachment)
	double building_load_bid; // Expected building load value for currently bidding market period (if BUILDING attachment)
	double year_runtime_limit[h]; // Total number of hours the generator can run in a year
	double current_year_runtime[h]; // Total number of hours generator has run this year
	char1024 runtime_year_end; // Date and time the generator runtime year resets
	double scaling_factor[unit]; // scaling factor applied to license premium calculation
	double license_premium; // current value of the generator license premium calculated
	double hours_in_year[h]; // Number of hours assumed for the total year
	double op_and_maint_cost[$]; // Operation and maintenance cost per runtime year
	int64 bid_id;
}

class passive_controller {
	int32 input_state;
	double input_setpoint;
	bool input_chained;
	double observation; // the observed value
	double mean_observation; // the observed mean value
	double stdev_observation; // the observed standard deviation value
	double expectation; // the observed expected value
	double sensitivity; // (DEPRECATED) the sensitivity of the control actuator to observation deviations
	double period[s]; // the cycle period for the controller logic
	char32 expectation_prop; // (DEPRECATED) the name of the property to observe for the expected value
	object expectation_obj; // (DEPRECATED) the object to watch for the expectation property
	char32 expectation_property; // the name of the property to observe for the expected value
	object expectation_object; // the object to watch for the expectation property
	char32 setpoint_prop; // (DEPRECATED) the name of the setpoint property in the parent object
	char32 setpoint; // the name of the setpoint property in the parent object
	char32 state_prop; // (DEPRECATED) the name of the actuator property in the parent object
	char32 state_property; // the name of the actuator property in the parent object
	object observation_obj; // (DEPRECATED) the object to observe
	char32 observation_prop; // (DEPRECATED) the name of the observation property
	object observation_object; // the object to observe
	char32 observation_property; // the name of the observation property
	char32 mean_observation_prop; // (DEPRECATED) the name of the mean observation property
	char32 stdev_observation_prop; // (DEPRECATED) the name of the standard deviation observation property
	char32 stdev_observation_property; // the name of the standard deviation observation property
	int32 cycle_length; // (DEPRECATED) length of time between processing cycles
	double base_setpoint; // the base setpoint to base control off of
	double critical_day; // used to switch between TOU and CPP days, 1 is CPP, 0 is TOU
	bool two_tier_cpp;
	double daily_elasticity;
	double sub_elasticity_first_second;
	double sub_elasticity_first_third;
	int32 second_tier_hours;
	int32 third_tier_hours;
	int32 first_tier_hours;
	double first_tier_price;
	double second_tier_price;
	double third_tier_price;
	double old_first_tier_price;
	double old_second_tier_price;
	double old_third_tier_price;
	double Percent_change_in_price;
	double Percent_change_in_peakoffpeak_ratio;
	double Percent_change_in_Criticalpeakoffpeak_ratio;
	bool linearize_elasticity;
	double price_offset;
	bool pool_pump_model; // Boolean flag for turning on the pool pump version of the DUTYCYCLE control
	double base_duty_cycle; // This is the duty cycle before modification due to the price signal
	int32 trigger_time_under_frequency; // Time to stay in triggered off state in seconds
	int32 trigger_time_over_frequency; // Time to stay in triggered on state in seconds
	int32 release_time_under_frequency; // Time to stay in released on state in seconds
	int32 release_time_over_frequency; // Time to stay in released off state in seconds
	double release_point_under_frequency; // Frequency value for releasing GFA in under frequency mode
	double release_point_over_frequency; // Frequency value for releasing GFA in over frequency mode
	double trigger_point_under_frequency; // Frequency value for triggereing GFA in under frequency mode
	double trigger_point_over_frequency; // Frequency value for triggereing GFA in over frequency mode
	double frequency; // Frequency value
	enumeration {OVER_UNDER_FREQUENCY=2, UNDER_FREQUENCY=1, OVER_FREQUENCY=0} PFC_mode; // operation mode of the primary frequency controller
	enumeration {RELEASED_ON=6, RELEASED_OFF=5, FORCED_ON=4, FORCED_OFF=3, TRIGGERED_ON=2, TRIGGERED_OFF=1, FREE=0} PFC_state; // State of the primary frequency controller
	char32 state_observed; // the name of the observed state property in the parent object
	char32 power_observed; // the name of the observed state property in the parent object
	int32 output_observed;
	int32 bid_delay; // time the controller will bid in advance before clearing
	double voltage_lockout[%]; // lockout primary frequency control if voltage is deviating % from nominal
	double voltage_lockout_time[s]; // voltage lockout period
	int32 voltage_lockout_state; // value to determine if water heater is in voltage lockout
	enumeration {UNIFORM=2, EXPONENTIAL=1, NORMAL=0} distribution_type;
	double comfort_level;
	double range_high;
	double range_low;
	double ramp_high;
	double ramp_low;
	double prob_off;
	int32 output_state; // the target setpoint given the input observations
	double output_setpoint;
	enumeration {PRIMARY_FREQUENCY_CONTROL=8, DIRECT_LOAD_CONTROL=7, ELASTICITY_MODEL=6, PROBABILITY_OFF=5, DUTYCYCLE=4, RAMP=1, NONE=0} control_mode; // the control mode to use for determining controller action
	enumeration {CYCLING=1, OFF=0} dlc_mode; // this mode is roughly designed to force cycle an AC unit
	double cycle_length_off[s];
	double cycle_length_on[s];
}

class stub_bidder {
	double bid_period[s];
	int16 count;
	object market;
	enumeration {SELLER=1, BUYER=0} role;
	double price;
	double quantity;
	int64 bid_id;
}

class stubauction {
	char32 unit; // unit of quantity
	double period[s]; // interval of time between market clearings
	double last.P; // last cleared price
	double current_market.clearing_price; // next cleared price
	double past_market.clearing_price; // last cleared price
	double next.P; // next cleared price
	double avg24; // daily average of price
	double std24; // daily stdev of price
	double avg72; // three day price average
	double std72; // three day price stdev
	double avg168; // weekly average of price
	double std168; // weekly stdev of price
	int64 market_id; // unique identifier of market clearing
	bool verbose; // enable verbose stubauction operations
	enumeration {DISABLED=1, NORMAL=0} control_mode; // the control mode to use for determining average and deviation calculations
}

class supervisory_control {
	char32 unit; // unit of quantity
	double period[s]; // interval of time between market clearings
	int32 market_id; // unique identifier of market clearing
	double nominal_frequency[Hz]; // nominal frequency
	double droop[%]; // droop value for the supervisor
	double frequency_deadband[Hz]; // frequency deadband for assigning trigger frequencies
	enumeration {OVER_UNDER_FREQUENCY=2, UNDER_FREQUENCY=1, OVER_FREQUENCY=0} PFC_mode; // operation mode of the primary frequency controller
	enumeration {VOLTAGE_EXTREMES=4, VOLTAGE_DEVIAION_FROM_NOMINAL=3, POWER_DECREASING=2, POWER_INCREASING=1, NONE=0} bid_sort_mode; // Determines how the bids into the market is sorted to contruct the PF curve
}

