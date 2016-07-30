class billdump {
	char32 group; // the group ID to output data for (all nodes if empty)
	timestamp runtime; // the time to check voltage data
	char256 filename; // the file to dump the voltage data into
	int32 runcount; // the number of times the file has been written to
	enumeration {METER=1, TRIPLEX_METER=0} meter_type; // describes whether to collect from 3-phase or S-phase meters
}

class capacitor {
	parent node;
	class node {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function delta_linkage_node();
		function interupdate_pwr_object();
		function delta_freq_pwr_object();
		enumeration {SWING=2, PV=1, PQ=0} bustype; // defines whether the node is a PQ, PV, or SWING node
		set {HASSOURCE=1} busflags; // flag indicates node has a source for voltage, i.e. connects to the swing node
		object reference_bus; // reference bus from which frequency is defined
		double maximum_voltage_error[V]; // convergence voltage limit or convergence criteria
		complex voltage_A[V]; // bus voltage, Phase A to ground
		complex voltage_B[V]; // bus voltage, Phase B to ground
		complex voltage_C[V]; // bus voltage, Phase C to ground
		complex voltage_AB[V]; // line voltages, Phase AB
		complex voltage_BC[V]; // line voltages, Phase BC
		complex voltage_CA[V]; // line voltages, Phase CA
		complex current_A[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex current_B[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex current_C[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex power_A[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex power_B[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex power_C[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex shunt_A[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex shunt_B[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex shunt_C[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex current_AB[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_BC[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_CA[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_AN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_BN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_CN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_AB[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_BC[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_CA[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_AN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_BN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_CN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex shunt_AB[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_BC[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_CA[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_AN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_BN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_CN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
		enumeration {OUT_OF_SERVICE=0, IN_SERVICE=1} service_status; // In and out of service flag
		double service_status_double; // In and out of service flag - type double - will indiscriminately override service_status - useful for schedules
		double previous_uptime[min]; // Previous time between disconnects of node in minutes
		double current_uptime[min]; // Current time since last disconnect of node in minutes
		bool Norton_dynamic; // Flag to indicate a Norton-equivalent connection -- used for generators and deltamode
		object topological_parent; // topological parent as per GLM configuration
	}

	function delta_linkage_node();
	function interupdate_pwr_object();
	function delta_freq_pwr_object();
	set {N=8, D=256, C=4, B=2, A=1} pt_phase; // Phase(s) that the PT is on, used as measurement points for control
	set {N=8, D=256, C=4, B=2, A=1} phases_connected; // phases capacitors connected to
	enumeration {CLOSED=1, OPEN=0} switchA; // capacitor A switch open or close
	enumeration {CLOSED=1, OPEN=0} switchB; // capacitor B switch open or close
	enumeration {CLOSED=1, OPEN=0} switchC; // capacitor C switch open or close
	enumeration {CURRENT=4, VARVOLT=3, VOLT=2, VAR=1, MANUAL=0} control; // control operation strategy
	double cap_A_switch_count; // number of switch operations on Phase A
	double cap_B_switch_count; // number of switch operations on Phase B
	double cap_C_switch_count; // number of switch operations on Phase C
	double voltage_set_high[V]; // Turn off if voltage is above this set point
	double voltage_set_low[V]; // Turns on if voltage is below this set point
	double VAr_set_high[VAr]; // high VAR set point for VAR control (turn off)
	double VAr_set_low[VAr]; // low VAR set point for VAR control (turn on)
	double current_set_low[A]; // high current set point for current control mode (turn on)
	double current_set_high[A]; // low current set point for current control mode (turn off)
	double capacitor_A[VAr]; // Capacitance value for phase A or phase AB
	double capacitor_B[VAr]; // Capacitance value for phase B or phase BC
	double capacitor_C[VAr]; // Capacitance value for phase C or phase CA
	double cap_nominal_voltage[V]; // Nominal voltage for the capacitor. Used for calculation of capacitance value
	double time_delay[s]; // control time delay
	double dwell_time[s]; // Time for system to remain constant before a state change will be passed
	double lockout_time[s]; // Time for capacitor to remain locked out from further switching operations (VARVOLT control)
	object remote_sense; // Remote object for sensing values used for control schemes
	object remote_sense_B; // Secondary Remote object for sensing values used for control schemes (VARVOLT uses two)
	enumeration {INDIVIDUAL=1, BANK=0} control_level; // define bank or individual control
}

class currdump {
	char32 group; // the group ID to output data for (all links if empty)
	timestamp runtime; // the time to check current data
	char256 filename; // the file to dump the current data into
	int32 runcount; // the number of times the file has been written to
	enumeration {polar=1, rect=0} mode;
}

class emissions {
	double Nuclear_Order;
	double Hydroelectric_Order;
	double Solarthermal_Order;
	double Biomass_Order;
	double Wind_Order;
	double Coal_Order;
	double Naturalgas_Order;
	double Geothermal_Order;
	double Petroleum_Order;
	double Naturalgas_Max_Out[kWh];
	double Coal_Max_Out[kWh];
	double Biomass_Max_Out[kWh];
	double Geothermal_Max_Out[kWh];
	double Hydroelectric_Max_Out[kWh];
	double Nuclear_Max_Out[kWh];
	double Wind_Max_Out[kWh];
	double Petroleum_Max_Out[kWh];
	double Solarthermal_Max_Out[kWh];
	double Naturalgas_Out[kWh];
	double Coal_Out[kWh];
	double Biomass_Out[kWh];
	double Geothermal_Out[kWh];
	double Hydroelectric_Out[kWh];
	double Nuclear_Out[kWh];
	double Wind_Out[kWh];
	double Petroleum_Out[kWh];
	double Solarthermal_Out[kWh];
	double Naturalgas_Conv_Eff[Btu/kWh];
	double Coal_Conv_Eff[Btu/kWh];
	double Biomass_Conv_Eff[Btu/kWh];
	double Geothermal_Conv_Eff[Btu/kWh];
	double Hydroelectric_Conv_Eff[Btu/kWh];
	double Nuclear_Conv_Eff[Btu/kWh];
	double Wind_Conv_Eff[Btu/kWh];
	double Petroleum_Conv_Eff[Btu/kWh];
	double Solarthermal_Conv_Eff[Btu/kWh];
	double Naturalgas_CO2[lb/Btu];
	double Coal_CO2[lb/Btu];
	double Biomass_CO2[lb/Btu];
	double Geothermal_CO2[lb/Btu];
	double Hydroelectric_CO2[lb/Btu];
	double Nuclear_CO2[lb/Btu];
	double Wind_CO2[lb/Btu];
	double Petroleum_CO2[lb/Btu];
	double Solarthermal_CO2[lb/Btu];
	double Naturalgas_SO2[lb/Btu];
	double Coal_SO2[lb/Btu];
	double Biomass_SO2[lb/Btu];
	double Geothermal_SO2[lb/Btu];
	double Hydroelectric_SO2[lb/Btu];
	double Nuclear_SO2[lb/Btu];
	double Wind_SO2[lb/Btu];
	double Petroleum_SO2[lb/Btu];
	double Solarthermal_SO2[lb/Btu];
	double Naturalgas_NOx[lb/Btu];
	double Coal_NOx[lb/Btu];
	double Biomass_NOx[lb/Btu];
	double Geothermal_NOx[lb/Btu];
	double Hydroelectric_NOx[lb/Btu];
	double Nuclear_NOx[lb/Btu];
	double Wind_NOx[lb/Btu];
	double Petroleum_NOx[lb/Btu];
	double Solarthermal_NOx[lb/Btu];
	double Naturalgas_emissions_CO2[lb];
	double Naturalgas_emissions_SO2[lb];
	double Naturalgas_emissions_NOx[lb];
	double Coal_emissions_CO2[lb];
	double Coal_emissions_SO2[lb];
	double Coal_emissions_NOx[lb];
	double Biomass_emissions_CO2[lb];
	double Biomass_emissions_SO2[lb];
	double Biomass_emissions_NOx[lb];
	double Geothermal_emissions_CO2[lb];
	double Geothermal_emissions_SO2[lb];
	double Geothermal_emissions_NOx[lb];
	double Hydroelectric_emissions_CO2[lb];
	double Hydroelectric_emissions_SO2[lb];
	double Hydroelectric_emissions_NOx[lb];
	double Nuclear_emissions_CO2[lb];
	double Nuclear_emissions_SO2[lb];
	double Nuclear_emissions_NOx[lb];
	double Wind_emissions_CO2[lb];
	double Wind_emissions_SO2[lb];
	double Wind_emissions_NOx[lb];
	double Petroleum_emissions_CO2[lb];
	double Petroleum_emissions_SO2[lb];
	double Petroleum_emissions_NOx[lb];
	double Solarthermal_emissions_CO2[lb];
	double Solarthermal_emissions_SO2[lb];
	double Solarthermal_emissions_NOx[lb];
	double Total_emissions_CO2[lb];
	double Total_emissions_SO2[lb];
	double Total_emissions_NOx[lb];
	double Total_energy_out[kWh];
	double Region;
	double cycle_interval[s];
}

class fault_check {
	function reliability_alterations();
	function handle_sectionalizer();
	enumeration {ALL=2, ONCHANGE=1, SINGLE=0} check_mode; // Frequency of fault checks
	char1024 output_filename; // Output filename for list of unsupported nodes
	bool reliability_mode; // General flag indicating if fault_check is operating under faulting or restoration mode -- reliability set this
	bool strictly_radial; // Flag to indicate if a system is known to be strictly radial -- uses radial assumptions for reliability alterations
	bool full_output_file; // Flag to indicate if the output_filename report contains both supported and unsupported nodes -- if false, just does unsupported
	object eventgen_object; // Link to generic eventgen object to handle unexpected faults
}

class frequency_gen {
	enumeration {AUTO=1, OFF=0} Frequency_Mode; // Frequency object operations mode
	double Frequency[Hz]; // Instantaneous frequency value
	double FreqChange[Hz/s]; // Frequency change from last timestep
	double Deadband[Hz]; // Frequency deadband of the governor
	double Tolerance[%]; // % threshold a power difference must be before it is cared about
	double M[pu*s]; // Inertial constant of the system
	double D[%]; // Load-damping constant
	double Rated_power[W]; // Rated power of system (base power)
	double Gen_power[W]; // Mechanical power equivalent
	double Load_power[W]; // Last sensed load value
	double Gov_delay[s]; // Governor delay time
	double Ramp_rate[W/s]; // Ramp ideal ramp rate
	double Low_Freq_OI[Hz]; // Low frequency setpoint for GFA devices
	double High_Freq_OI[Hz]; // High frequency setpoint for GFA devices
	double avg24[Hz]; // Average of last 24 hourly instantaneous measurements
	double std24[Hz]; // Standard deviation of last 24 hourly instantaneous measurements
	double avg168[Hz]; // Average of last 168 hourly instantaneous measurements
	double std168[Hz]; // Standard deviation of last 168 hourly instantaneous measurements
	int32 Num_Resp_Eqs; // Total number of equations the response can contain
}

class fuse {
	parent link;
	class link {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function interupdate_pwr_object();
		function update_power_pwr_object();
		function check_limits_pwr_object();
		enumeration {OPEN=0, CLOSED=1} status; // 
		object from; // from_node - source node
		object to; // to_node - load node
		complex power_in[VA]; // power flow in (w.r.t from node)
		complex power_out[VA]; // power flow out (w.r.t to node)
		double power_out_real[W]; // power flow out (w.r.t to node), real
		complex power_losses[VA]; // power losses
		complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
		complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
		complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
		complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
		complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
		complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
		complex power_losses_A[VA]; // power losses, phase A
		complex power_losses_B[VA]; // power losses, phase B
		complex power_losses_C[VA]; // power losses, phase C
		complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
		complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
		complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
		complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
		complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
		complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
		complex fault_current_in_A[A]; // fault current flowing in, phase A
		complex fault_current_in_B[A]; // fault current flowing in, phase B
		complex fault_current_in_C[A]; // fault current flowing in, phase C
		complex fault_current_out_A[A]; // fault current flowing out, phase A
		complex fault_current_out_B[A]; // fault current flowing out, phase B
		complex fault_current_out_C[A]; // fault current flowing out, phase C
		set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
		double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
		double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
		double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
		double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
	}

	function change_fuse_state();
	function reliability_operation();
	function create_fault();
	function fix_fault();
	function change_fuse_faults();
	function interupdate_pwr_object();
	function update_power_pwr_object();
	function check_limits_pwr_object();
	enumeration {GOOD=1, BLOWN=0} phase_A_status;
	enumeration {GOOD=1, BLOWN=0} phase_B_status;
	enumeration {GOOD=1, BLOWN=0} phase_C_status;
	enumeration {EXPONENTIAL=1, NONE=0} repair_dist_type;
	double current_limit[A];
	double mean_replacement_time[s];
	double fuse_resistance[Ohm]; // The resistance value of the fuse when it is not blown.
}

class impedance_dump {
	char32 group; // the group ID to output data for (all links if empty)
	char256 filename; // the file to dump the current data into
	timestamp runtime; // the time to check voltage data
	int32 runcount; // the number of times the file has been written to
}

class line {
	parent link;
	class link {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function interupdate_pwr_object();
		function update_power_pwr_object();
		function check_limits_pwr_object();
		enumeration {OPEN=0, CLOSED=1} status; // 
		object from; // from_node - source node
		object to; // to_node - load node
		complex power_in[VA]; // power flow in (w.r.t from node)
		complex power_out[VA]; // power flow out (w.r.t to node)
		double power_out_real[W]; // power flow out (w.r.t to node), real
		complex power_losses[VA]; // power losses
		complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
		complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
		complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
		complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
		complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
		complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
		complex power_losses_A[VA]; // power losses, phase A
		complex power_losses_B[VA]; // power losses, phase B
		complex power_losses_C[VA]; // power losses, phase C
		complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
		complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
		complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
		complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
		complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
		complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
		complex fault_current_in_A[A]; // fault current flowing in, phase A
		complex fault_current_in_B[A]; // fault current flowing in, phase B
		complex fault_current_in_C[A]; // fault current flowing in, phase C
		complex fault_current_out_A[A]; // fault current flowing out, phase A
		complex fault_current_out_B[A]; // fault current flowing out, phase B
		complex fault_current_out_C[A]; // fault current flowing out, phase C
		set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
		double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
		double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
		double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
		double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
	}

	function interupdate_pwr_object();
	function update_power_pwr_object();
	function check_limits_pwr_object();
	object configuration;
	double length[ft];
}

class line_configuration {
	object conductor_A;
	object conductor_B;
	object conductor_C;
	object conductor_N;
	object spacing;
	complex z11[Ohm/mile];
	complex z12[Ohm/mile];
	complex z13[Ohm/mile];
	complex z21[Ohm/mile];
	complex z22[Ohm/mile];
	complex z23[Ohm/mile];
	complex z31[Ohm/mile];
	complex z32[Ohm/mile];
	complex z33[Ohm/mile];
	double c11[nF/mile];
	double c12[nF/mile];
	double c13[nF/mile];
	double c21[nF/mile];
	double c22[nF/mile];
	double c23[nF/mile];
	double c31[nF/mile];
	double c32[nF/mile];
	double c33[nF/mile];
	double rating.summer.continuous[A]; // amp rating in summer, continuous
	double rating.summer.emergency[A]; // amp rating in summer, short term
	double rating.winter.continuous[A]; // amp rating in winter, continuous
	double rating.winter.emergency[A]; // amp rating in winter, short term
}

class line_spacing {
	double distance_AB[ft];
	double distance_BC[ft];
	double distance_AC[ft];
	double distance_AN[ft];
	double distance_BN[ft];
	double distance_CN[ft];
	double distance_AE[ft]; // distance between phase A wire and earth
	double distance_BE[ft]; // distance between phase B wire and earth
	double distance_CE[ft]; // distance between phase C wire and earth
	double distance_NE[ft]; // distance between neutral wire and earth
}

class link {
	parent powerflow_object;
	class powerflow_object {
		set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
		double nominal_voltage[V];
	}

	function interupdate_pwr_object();
	function update_power_pwr_object();
	function check_limits_pwr_object();
	enumeration {OPEN=0, CLOSED=1} status; // 
	object from; // from_node - source node
	object to; // to_node - load node
	complex power_in[VA]; // power flow in (w.r.t from node)
	complex power_out[VA]; // power flow out (w.r.t to node)
	double power_out_real[W]; // power flow out (w.r.t to node), real
	complex power_losses[VA]; // power losses
	complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
	complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
	complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
	complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
	complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
	complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
	complex power_losses_A[VA]; // power losses, phase A
	complex power_losses_B[VA]; // power losses, phase B
	complex power_losses_C[VA]; // power losses, phase C
	complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
	complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
	complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
	complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
	complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
	complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
	complex fault_current_in_A[A]; // fault current flowing in, phase A
	complex fault_current_in_B[A]; // fault current flowing in, phase B
	complex fault_current_in_C[A]; // fault current flowing in, phase C
	complex fault_current_out_A[A]; // fault current flowing out, phase A
	complex fault_current_out_B[A]; // fault current flowing out, phase B
	complex fault_current_out_C[A]; // fault current flowing out, phase C
	set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
	double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
	double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
	double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
	double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
}

class load {
	parent node;
	class node {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function delta_linkage_node();
		function interupdate_pwr_object();
		function delta_freq_pwr_object();
		enumeration {SWING=2, PV=1, PQ=0} bustype; // defines whether the node is a PQ, PV, or SWING node
		set {HASSOURCE=1} busflags; // flag indicates node has a source for voltage, i.e. connects to the swing node
		object reference_bus; // reference bus from which frequency is defined
		double maximum_voltage_error[V]; // convergence voltage limit or convergence criteria
		complex voltage_A[V]; // bus voltage, Phase A to ground
		complex voltage_B[V]; // bus voltage, Phase B to ground
		complex voltage_C[V]; // bus voltage, Phase C to ground
		complex voltage_AB[V]; // line voltages, Phase AB
		complex voltage_BC[V]; // line voltages, Phase BC
		complex voltage_CA[V]; // line voltages, Phase CA
		complex current_A[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex current_B[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex current_C[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex power_A[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex power_B[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex power_C[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex shunt_A[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex shunt_B[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex shunt_C[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex current_AB[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_BC[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_CA[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_AN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_BN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_CN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_AB[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_BC[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_CA[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_AN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_BN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_CN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex shunt_AB[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_BC[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_CA[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_AN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_BN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_CN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
		enumeration {OUT_OF_SERVICE=0, IN_SERVICE=1} service_status; // In and out of service flag
		double service_status_double; // In and out of service flag - type double - will indiscriminately override service_status - useful for schedules
		double previous_uptime[min]; // Previous time between disconnects of node in minutes
		double current_uptime[min]; // Current time since last disconnect of node in minutes
		bool Norton_dynamic; // Flag to indicate a Norton-equivalent connection -- used for generators and deltamode
		object topological_parent; // topological parent as per GLM configuration
	}

	function delta_linkage_node();
	function interupdate_pwr_object();
	function delta_freq_pwr_object();
	enumeration {A=4, I=3, C=2, R=1, U=0} load_class; // Flag to track load type, not currently used for anything except sorting
	complex constant_power_A[VA]; // constant power load on phase A, specified as VA
	complex constant_power_B[VA]; // constant power load on phase B, specified as VA
	complex constant_power_C[VA]; // constant power load on phase C, specified as VA
	double constant_power_A_real[W]; // constant power load on phase A, real only, specified as W
	double constant_power_B_real[W]; // constant power load on phase B, real only, specified as W
	double constant_power_C_real[W]; // constant power load on phase C, real only, specified as W
	double constant_power_A_reac[VAr]; // constant power load on phase A, imaginary only, specified as VAr
	double constant_power_B_reac[VAr]; // constant power load on phase B, imaginary only, specified as VAr
	double constant_power_C_reac[VAr]; // constant power load on phase C, imaginary only, specified as VAr
	complex constant_current_A[A]; // constant current load on phase A, specified as Amps
	complex constant_current_B[A]; // constant current load on phase B, specified as Amps
	complex constant_current_C[A]; // constant current load on phase C, specified as Amps
	double constant_current_A_real[A]; // constant current load on phase A, real only, specified as Amps
	double constant_current_B_real[A]; // constant current load on phase B, real only, specified as Amps
	double constant_current_C_real[A]; // constant current load on phase C, real only, specified as Amps
	double constant_current_A_reac[A]; // constant current load on phase A, imaginary only, specified as Amps
	double constant_current_B_reac[A]; // constant current load on phase B, imaginary only, specified as Amps
	double constant_current_C_reac[A]; // constant current load on phase C, imaginary only, specified as Amps
	complex constant_impedance_A[Ohm]; // constant impedance load on phase A, specified as Ohms
	complex constant_impedance_B[Ohm]; // constant impedance load on phase B, specified as Ohms
	complex constant_impedance_C[Ohm]; // constant impedance load on phase C, specified as Ohms
	double constant_impedance_A_real[Ohm]; // constant impedance load on phase A, real only, specified as Ohms
	double constant_impedance_B_real[Ohm]; // constant impedance load on phase B, real only, specified as Ohms
	double constant_impedance_C_real[Ohm]; // constant impedance load on phase C, real only, specified as Ohms
	double constant_impedance_A_reac[Ohm]; // constant impedance load on phase A, imaginary only, specified as Ohms
	double constant_impedance_B_reac[Ohm]; // constant impedance load on phase B, imaginary only, specified as Ohms
	double constant_impedance_C_reac[Ohm]; // constant impedance load on phase C, imaginary only, specified as Ohms
	complex constant_power_AN[VA]; // constant power wye-connected load on phase A, specified as VA
	complex constant_power_BN[VA]; // constant power wye-connected load on phase B, specified as VA
	complex constant_power_CN[VA]; // constant power wye-connected load on phase C, specified as VA
	double constant_power_AN_real[W]; // constant power wye-connected load on phase A, real only, specified as W
	double constant_power_BN_real[W]; // constant power wye-connected load on phase B, real only, specified as W
	double constant_power_CN_real[W]; // constant power wye-connected load on phase C, real only, specified as W
	double constant_power_AN_reac[VAr]; // constant power wye-connected load on phase A, imaginary only, specified as VAr
	double constant_power_BN_reac[VAr]; // constant power wye-connected load on phase B, imaginary only, specified as VAr
	double constant_power_CN_reac[VAr]; // constant power wye-connected load on phase C, imaginary only, specified as VAr
	complex constant_current_AN[A]; // constant current wye-connected load on phase A, specified as Amps
	complex constant_current_BN[A]; // constant current wye-connected load on phase B, specified as Amps
	complex constant_current_CN[A]; // constant current wye-connected load on phase C, specified as Amps
	double constant_current_AN_real[A]; // constant current wye-connected load on phase A, real only, specified as Amps
	double constant_current_BN_real[A]; // constant current wye-connected load on phase B, real only, specified as Amps
	double constant_current_CN_real[A]; // constant current wye-connected load on phase C, real only, specified as Amps
	double constant_current_AN_reac[A]; // constant current wye-connected load on phase A, imaginary only, specified as Amps
	double constant_current_BN_reac[A]; // constant current wye-connected load on phase B, imaginary only, specified as Amps
	double constant_current_CN_reac[A]; // constant current wye-connected load on phase C, imaginary only, specified as Amps
	complex constant_impedance_AN[Ohm]; // constant impedance wye-connected load on phase A, specified as Ohms
	complex constant_impedance_BN[Ohm]; // constant impedance wye-connected load on phase B, specified as Ohms
	complex constant_impedance_CN[Ohm]; // constant impedance wye-connected load on phase C, specified as Ohms
	double constant_impedance_AN_real[Ohm]; // constant impedance wye-connected load on phase A, real only, specified as Ohms
	double constant_impedance_BN_real[Ohm]; // constant impedance wye-connected load on phase B, real only, specified as Ohms
	double constant_impedance_CN_real[Ohm]; // constant impedance wye-connected load on phase C, real only, specified as Ohms
	double constant_impedance_AN_reac[Ohm]; // constant impedance wye-connected load on phase A, imaginary only, specified as Ohms
	double constant_impedance_BN_reac[Ohm]; // constant impedance wye-connected load on phase B, imaginary only, specified as Ohms
	double constant_impedance_CN_reac[Ohm]; // constant impedance wye-connected load on phase C, imaginary only, specified as Ohms
	complex constant_power_AB[VA]; // constant power delta-connected load on phase A, specified as VA
	complex constant_power_BC[VA]; // constant power delta-connected load on phase B, specified as VA
	complex constant_power_CA[VA]; // constant power delta-connected load on phase C, specified as VA
	double constant_power_AB_real[W]; // constant power delta-connected load on phase A, real only, specified as W
	double constant_power_BC_real[W]; // constant power delta-connected load on phase B, real only, specified as W
	double constant_power_CA_real[W]; // constant power delta-connected load on phase C, real only, specified as W
	double constant_power_AB_reac[VAr]; // constant power delta-connected load on phase A, imaginary only, specified as VAr
	double constant_power_BC_reac[VAr]; // constant power delta-connected load on phase B, imaginary only, specified as VAr
	double constant_power_CA_reac[VAr]; // constant power delta-connected load on phase C, imaginary only, specified as VAr
	complex constant_current_AB[A]; // constant current delta-connected load on phase A, specified as Amps
	complex constant_current_BC[A]; // constant current delta-connected load on phase B, specified as Amps
	complex constant_current_CA[A]; // constant current delta-connected load on phase C, specified as Amps
	double constant_current_AB_real[A]; // constant current delta-connected load on phase A, real only, specified as Amps
	double constant_current_BC_real[A]; // constant current delta-connected load on phase B, real only, specified as Amps
	double constant_current_CA_real[A]; // constant current delta-connected load on phase C, real only, specified as Amps
	double constant_current_AB_reac[A]; // constant current delta-connected load on phase A, imaginary only, specified as Amps
	double constant_current_BC_reac[A]; // constant current delta-connected load on phase B, imaginary only, specified as Amps
	double constant_current_CA_reac[A]; // constant current delta-connected load on phase C, imaginary only, specified as Amps
	complex constant_impedance_AB[Ohm]; // constant impedance delta-connected load on phase A, specified as Ohms
	complex constant_impedance_BC[Ohm]; // constant impedance delta-connected load on phase B, specified as Ohms
	complex constant_impedance_CA[Ohm]; // constant impedance delta-connected load on phase C, specified as Ohms
	double constant_impedance_AB_real[Ohm]; // constant impedance delta-connected load on phase A, real only, specified as Ohms
	double constant_impedance_BC_real[Ohm]; // constant impedance delta-connected load on phase B, real only, specified as Ohms
	double constant_impedance_CA_real[Ohm]; // constant impedance delta-connected load on phase C, real only, specified as Ohms
	double constant_impedance_AB_reac[Ohm]; // constant impedance delta-connected load on phase A, imaginary only, specified as Ohms
	double constant_impedance_BC_reac[Ohm]; // constant impedance delta-connected load on phase B, imaginary only, specified as Ohms
	double constant_impedance_CA_reac[Ohm]; // constant impedance delta-connected load on phase C, imaginary only, specified as Ohms
	complex measured_voltage_A; // current measured voltage on phase A
	complex measured_voltage_B; // current measured voltage on phase B
	complex measured_voltage_C; // current measured voltage on phase C
	complex measured_voltage_AB; // current measured voltage on phases AB
	complex measured_voltage_BC; // current measured voltage on phases BC
	complex measured_voltage_CA; // current measured voltage on phases CA
	bool phase_loss_protection; // Trip all three phases of the load if a fault occurs
	double base_power_A[VA]; // in similar format as ZIPload, this represents the nominal power on phase A before applying ZIP fractions
	double base_power_B[VA]; // in similar format as ZIPload, this represents the nominal power on phase B before applying ZIP fractions
	double base_power_C[VA]; // in similar format as ZIPload, this represents the nominal power on phase C before applying ZIP fractions
	double power_pf_A[pu]; // in similar format as ZIPload, this is the power factor of the phase A constant power portion of load
	double current_pf_A[pu]; // in similar format as ZIPload, this is the power factor of the phase A constant current portion of load
	double impedance_pf_A[pu]; // in similar format as ZIPload, this is the power factor of the phase A constant impedance portion of load
	double power_pf_B[pu]; // in similar format as ZIPload, this is the power factor of the phase B constant power portion of load
	double current_pf_B[pu]; // in similar format as ZIPload, this is the power factor of the phase B constant current portion of load
	double impedance_pf_B[pu]; // in similar format as ZIPload, this is the power factor of the phase B constant impedance portion of load
	double power_pf_C[pu]; // in similar format as ZIPload, this is the power factor of the phase C constant power portion of load
	double current_pf_C[pu]; // in similar format as ZIPload, this is the power factor of the phase C constant current portion of load
	double impedance_pf_C[pu]; // in similar format as ZIPload, this is the power factor of the phase C constant impedance portion of load
	double power_fraction_A[pu]; // this is the constant power fraction of base power on phase A
	double current_fraction_A[pu]; // this is the constant current fraction of base power on phase A
	double impedance_fraction_A[pu]; // this is the constant impedance fraction of base power on phase A
	double power_fraction_B[pu]; // this is the constant power fraction of base power on phase B
	double current_fraction_B[pu]; // this is the constant current fraction of base power on phase B
	double impedance_fraction_B[pu]; // this is the constant impedance fraction of base power on phase B
	double power_fraction_C[pu]; // this is the constant power fraction of base power on phase C
	double current_fraction_C[pu]; // this is the constant current fraction of base power on phase C
	double impedance_fraction_C[pu]; // this is the constant impedance fraction of base power on phase C
}

class load_tracker {
	object target; // target object to track the load of
	char256 target_property; // property on the target object representing the load
	enumeration {ANGLE=3, MAGNITUDE=2, IMAGINARY=1, REAL=0} operation; // operation to perform on complex property types
	double full_scale; // magnitude of the load at full load, used for feed-forward control
	double setpoint; // load setpoint to track to
	double deadband; // percentage deadband
	double damping; // load setpoint to track to
	double output; // output scaling value
	double feedback; // the feedback signal, for reference purposes
}

class meter {
	parent node;
	class node {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function delta_linkage_node();
		function interupdate_pwr_object();
		function delta_freq_pwr_object();
		enumeration {SWING=2, PV=1, PQ=0} bustype; // defines whether the node is a PQ, PV, or SWING node
		set {HASSOURCE=1} busflags; // flag indicates node has a source for voltage, i.e. connects to the swing node
		object reference_bus; // reference bus from which frequency is defined
		double maximum_voltage_error[V]; // convergence voltage limit or convergence criteria
		complex voltage_A[V]; // bus voltage, Phase A to ground
		complex voltage_B[V]; // bus voltage, Phase B to ground
		complex voltage_C[V]; // bus voltage, Phase C to ground
		complex voltage_AB[V]; // line voltages, Phase AB
		complex voltage_BC[V]; // line voltages, Phase BC
		complex voltage_CA[V]; // line voltages, Phase CA
		complex current_A[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex current_B[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex current_C[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex power_A[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex power_B[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex power_C[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex shunt_A[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex shunt_B[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex shunt_C[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex current_AB[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_BC[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_CA[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_AN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_BN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_CN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_AB[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_BC[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_CA[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_AN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_BN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_CN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex shunt_AB[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_BC[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_CA[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_AN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_BN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_CN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
		enumeration {OUT_OF_SERVICE=0, IN_SERVICE=1} service_status; // In and out of service flag
		double service_status_double; // In and out of service flag - type double - will indiscriminately override service_status - useful for schedules
		double previous_uptime[min]; // Previous time between disconnects of node in minutes
		double current_uptime[min]; // Current time since last disconnect of node in minutes
		bool Norton_dynamic; // Flag to indicate a Norton-equivalent connection -- used for generators and deltamode
		object topological_parent; // topological parent as per GLM configuration
	}

	function reset();
	function delta_linkage_node();
	function interupdate_pwr_object();
	function delta_freq_pwr_object();
	double measured_real_energy[Wh]; // metered real energy consumption, cummalitive
	double measured_reactive_energy[VAh]; // metered reactive energy consumption, cummalitive
	complex measured_power[VA]; // metered real power
	complex measured_power_A[VA]; // metered complex power on phase A
	complex measured_power_B[VA]; // metered complex power on phase B
	complex measured_power_C[VA]; // metered complex power on phase C
	double measured_demand[W]; // greatest metered real power during simulation
	double measured_real_power[W]; // metered real power
	double measured_reactive_power[VAr]; // metered reactive power
	complex meter_power_consumption[VA]; // metered power used for operating the meter; standby and communication losses
	complex measured_voltage_A[V]; // measured line-to-neutral voltage on phase A
	complex measured_voltage_B[V]; // measured line-to-neutral voltage on phase B
	complex measured_voltage_C[V]; // measured line-to-neutral voltage on phase C
	complex measured_voltage_AB[V]; // measured line-to-line voltage on phase AB
	complex measured_voltage_BC[V]; // measured line-to-line voltage on phase BC
	complex measured_voltage_CA[V]; // measured line-to-line voltage on phase CA
	complex measured_current_A[A]; // measured current on phase A
	complex measured_current_B[A]; // measured current on phase B
	complex measured_current_C[A]; // measured current on phase C
	bool customer_interrupted; // Reliability flag - goes active if the customer is in an 'interrupted' state
	bool customer_interrupted_secondary; // Reliability flag - goes active if the customer is in an 'secondary interrupted' state - i.e., momentary
	double monthly_bill[$]; // Accumulator for the current month's bill
	double previous_monthly_bill[$]; // Total monthly bill for the previous month
	double previous_monthly_energy[kWh]; // Total monthly energy for the previous month
	double monthly_fee[$]; // Once a month flat fee for customer hook-up
	double monthly_energy[kWh]; // Accumulator for the current month's energy consumption
	enumeration {TIERED_RTP=4, HOURLY=3, TIERED=2, UNIFORM=1, NONE=0} bill_mode; // Billing structure desired
	object power_market; // Market (auction object) where the price is being received from
	int32 bill_day; // day of month bill is to be processed (currently limited to days 1-28)
	double price[$/kWh]; // current price of electricity
	double price_base[$/kWh]; // Used only in TIERED_RTP mode to describe the price before the first tier
	double first_tier_price[$/kWh]; // price of electricity between first tier and second tier energy usage
	double first_tier_energy[kWh]; // switching point between base price and first tier price
	double second_tier_price[$/kWh]; // price of electricity between second tier and third tier energy usage
	double second_tier_energy[kWh]; // switching point between first tier price and second tier price
	double third_tier_price[$/kWh]; // price of electricity when energy usage exceeds third tier energy usage
	double third_tier_energy[kWh]; // switching point between second tier price and third tier price
}

class motor {
	parent node;
	class node {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function delta_linkage_node();
		function interupdate_pwr_object();
		function delta_freq_pwr_object();
		enumeration {SWING=2, PV=1, PQ=0} bustype; // defines whether the node is a PQ, PV, or SWING node
		set {HASSOURCE=1} busflags; // flag indicates node has a source for voltage, i.e. connects to the swing node
		object reference_bus; // reference bus from which frequency is defined
		double maximum_voltage_error[V]; // convergence voltage limit or convergence criteria
		complex voltage_A[V]; // bus voltage, Phase A to ground
		complex voltage_B[V]; // bus voltage, Phase B to ground
		complex voltage_C[V]; // bus voltage, Phase C to ground
		complex voltage_AB[V]; // line voltages, Phase AB
		complex voltage_BC[V]; // line voltages, Phase BC
		complex voltage_CA[V]; // line voltages, Phase CA
		complex current_A[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex current_B[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex current_C[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex power_A[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex power_B[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex power_C[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex shunt_A[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex shunt_B[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex shunt_C[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex current_AB[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_BC[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_CA[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_AN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_BN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_CN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_AB[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_BC[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_CA[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_AN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_BN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_CN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex shunt_AB[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_BC[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_CA[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_AN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_BN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_CN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
		enumeration {OUT_OF_SERVICE=0, IN_SERVICE=1} service_status; // In and out of service flag
		double service_status_double; // In and out of service flag - type double - will indiscriminately override service_status - useful for schedules
		double previous_uptime[min]; // Previous time between disconnects of node in minutes
		double current_uptime[min]; // Current time since last disconnect of node in minutes
		bool Norton_dynamic; // Flag to indicate a Norton-equivalent connection -- used for generators and deltamode
		object topological_parent; // topological parent as per GLM configuration
	}

}

class node {
	parent powerflow_object;
	class powerflow_object {
		set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
		double nominal_voltage[V];
	}

	function delta_linkage_node();
	function interupdate_pwr_object();
	function delta_freq_pwr_object();
	enumeration {SWING=2, PV=1, PQ=0} bustype; // defines whether the node is a PQ, PV, or SWING node
	set {HASSOURCE=1} busflags; // flag indicates node has a source for voltage, i.e. connects to the swing node
	object reference_bus; // reference bus from which frequency is defined
	double maximum_voltage_error[V]; // convergence voltage limit or convergence criteria
	complex voltage_A[V]; // bus voltage, Phase A to ground
	complex voltage_B[V]; // bus voltage, Phase B to ground
	complex voltage_C[V]; // bus voltage, Phase C to ground
	complex voltage_AB[V]; // line voltages, Phase AB
	complex voltage_BC[V]; // line voltages, Phase BC
	complex voltage_CA[V]; // line voltages, Phase CA
	complex current_A[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
	complex current_B[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
	complex current_C[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
	complex power_A[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
	complex power_B[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
	complex power_C[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
	complex shunt_A[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
	complex shunt_B[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
	complex shunt_C[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
	complex current_AB[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex current_BC[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex current_CA[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex current_AN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex current_BN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex current_CN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex power_AB[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex power_BC[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex power_CA[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex power_AN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex power_BN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex power_CN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
	complex shunt_AB[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
	complex shunt_BC[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
	complex shunt_CA[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
	complex shunt_AN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
	complex shunt_BN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
	complex shunt_CN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
	double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
	enumeration {OUT_OF_SERVICE=0, IN_SERVICE=1} service_status; // In and out of service flag
	double service_status_double; // In and out of service flag - type double - will indiscriminately override service_status - useful for schedules
	double previous_uptime[min]; // Previous time between disconnects of node in minutes
	double current_uptime[min]; // Current time since last disconnect of node in minutes
	bool Norton_dynamic; // Flag to indicate a Norton-equivalent connection -- used for generators and deltamode
	object topological_parent; // topological parent as per GLM configuration
}

class overhead_line {
	parent line;
	class line {
		parent link;
		class link {
			parent powerflow_object;
			class powerflow_object {
				set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
				double nominal_voltage[V];
			}

			function interupdate_pwr_object();
			function update_power_pwr_object();
			function check_limits_pwr_object();
			enumeration {OPEN=0, CLOSED=1} status; // 
			object from; // from_node - source node
			object to; // to_node - load node
			complex power_in[VA]; // power flow in (w.r.t from node)
			complex power_out[VA]; // power flow out (w.r.t to node)
			double power_out_real[W]; // power flow out (w.r.t to node), real
			complex power_losses[VA]; // power losses
			complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
			complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
			complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
			complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
			complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
			complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
			complex power_losses_A[VA]; // power losses, phase A
			complex power_losses_B[VA]; // power losses, phase B
			complex power_losses_C[VA]; // power losses, phase C
			complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
			complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
			complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
			complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
			complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
			complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
			complex fault_current_in_A[A]; // fault current flowing in, phase A
			complex fault_current_in_B[A]; // fault current flowing in, phase B
			complex fault_current_in_C[A]; // fault current flowing in, phase C
			complex fault_current_out_A[A]; // fault current flowing out, phase A
			complex fault_current_out_B[A]; // fault current flowing out, phase B
			complex fault_current_out_C[A]; // fault current flowing out, phase C
			set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
			double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
			double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
			double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
			double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
		}

		function interupdate_pwr_object();
		function update_power_pwr_object();
		function check_limits_pwr_object();
		object configuration;
		double length[ft];
	}

	function create_fault();
	function fix_fault();
	function interupdate_pwr_object();
	function recalc_distribution_line();
	function update_power_pwr_object();
	function check_limits_pwr_object();
}

class overhead_line_conductor {
	double geometric_mean_radius[ft]; // radius of the conductor
	double resistance[Ohm/mile]; // resistance in Ohms/mile of the conductor
	double diameter[in]; // Diameter of line for capacitance calculations
	double rating.summer.continuous[A]; // Continuous summer amp rating
	double rating.summer.emergency[A]; // Emergency summer amp rating
	double rating.winter.continuous[A]; // Continuous winter amp rating
	double rating.winter.emergency[A]; // Emergency winter amp rating
}

class power_metrics {
	function calc_metrics();
	function reset_interval_metrics();
	function reset_annual_metrics();
	function init_reliability();
	function logfile_extra();
	double SAIFI; // Displays annual SAIFI values as per IEEE 1366-2003
	double SAIFI_int; // Displays SAIFI values over the period specified by base_time_value as per IEEE 1366-2003
	double SAIDI; // Displays annual SAIDI values as per IEEE 1366-2003
	double SAIDI_int; // Displays SAIDI values over the period specified by base_time_value as per IEEE 1366-2003
	double CAIDI; // Displays annual CAIDI values as per IEEE 1366-2003
	double CAIDI_int; // Displays SAIDI values over the period specified by base_time_value as per IEEE 1366-2003
	double ASAI; // Displays annual AISI values as per IEEE 1366-2003
	double ASAI_int; // Displays AISI values over the period specified by base_time_value as per IEEE 1366-2003
	double MAIFI; // Displays annual MAIFI values as per IEEE 1366-2003
	double MAIFI_int; // Displays MAIFI values over the period specified by base_time_value as per IEEE 1366-2003
	double base_time_value[s]; // time period over which _int values are claculated
}

class powerflow_library {
}

class powerflow_object {
	set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
	double nominal_voltage[V];
}

class powerflow_object {
	set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
	double nominal_voltage[V];
}

class pqload {
	parent load;
	class load {
		parent node;
		class node {
			parent powerflow_object;
			class powerflow_object {
				set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
				double nominal_voltage[V];
			}

			function delta_linkage_node();
			function interupdate_pwr_object();
			function delta_freq_pwr_object();
			enumeration {SWING=2, PV=1, PQ=0} bustype; // defines whether the node is a PQ, PV, or SWING node
			set {HASSOURCE=1} busflags; // flag indicates node has a source for voltage, i.e. connects to the swing node
			object reference_bus; // reference bus from which frequency is defined
			double maximum_voltage_error[V]; // convergence voltage limit or convergence criteria
			complex voltage_A[V]; // bus voltage, Phase A to ground
			complex voltage_B[V]; // bus voltage, Phase B to ground
			complex voltage_C[V]; // bus voltage, Phase C to ground
			complex voltage_AB[V]; // line voltages, Phase AB
			complex voltage_BC[V]; // line voltages, Phase BC
			complex voltage_CA[V]; // line voltages, Phase CA
			complex current_A[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
			complex current_B[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
			complex current_C[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
			complex power_A[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
			complex power_B[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
			complex power_C[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
			complex shunt_A[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
			complex shunt_B[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
			complex shunt_C[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
			complex current_AB[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex current_BC[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex current_CA[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex current_AN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex current_BN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex current_CN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex power_AB[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex power_BC[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex power_CA[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex power_AN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex power_BN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex power_CN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
			complex shunt_AB[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
			complex shunt_BC[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
			complex shunt_CA[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
			complex shunt_AN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
			complex shunt_BN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
			complex shunt_CN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
			double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
			enumeration {OUT_OF_SERVICE=0, IN_SERVICE=1} service_status; // In and out of service flag
			double service_status_double; // In and out of service flag - type double - will indiscriminately override service_status - useful for schedules
			double previous_uptime[min]; // Previous time between disconnects of node in minutes
			double current_uptime[min]; // Current time since last disconnect of node in minutes
			bool Norton_dynamic; // Flag to indicate a Norton-equivalent connection -- used for generators and deltamode
			object topological_parent; // topological parent as per GLM configuration
		}

		function delta_linkage_node();
		function interupdate_pwr_object();
		function delta_freq_pwr_object();
		enumeration {A=4, I=3, C=2, R=1, U=0} load_class; // Flag to track load type, not currently used for anything except sorting
		complex constant_power_A[VA]; // constant power load on phase A, specified as VA
		complex constant_power_B[VA]; // constant power load on phase B, specified as VA
		complex constant_power_C[VA]; // constant power load on phase C, specified as VA
		double constant_power_A_real[W]; // constant power load on phase A, real only, specified as W
		double constant_power_B_real[W]; // constant power load on phase B, real only, specified as W
		double constant_power_C_real[W]; // constant power load on phase C, real only, specified as W
		double constant_power_A_reac[VAr]; // constant power load on phase A, imaginary only, specified as VAr
		double constant_power_B_reac[VAr]; // constant power load on phase B, imaginary only, specified as VAr
		double constant_power_C_reac[VAr]; // constant power load on phase C, imaginary only, specified as VAr
		complex constant_current_A[A]; // constant current load on phase A, specified as Amps
		complex constant_current_B[A]; // constant current load on phase B, specified as Amps
		complex constant_current_C[A]; // constant current load on phase C, specified as Amps
		double constant_current_A_real[A]; // constant current load on phase A, real only, specified as Amps
		double constant_current_B_real[A]; // constant current load on phase B, real only, specified as Amps
		double constant_current_C_real[A]; // constant current load on phase C, real only, specified as Amps
		double constant_current_A_reac[A]; // constant current load on phase A, imaginary only, specified as Amps
		double constant_current_B_reac[A]; // constant current load on phase B, imaginary only, specified as Amps
		double constant_current_C_reac[A]; // constant current load on phase C, imaginary only, specified as Amps
		complex constant_impedance_A[Ohm]; // constant impedance load on phase A, specified as Ohms
		complex constant_impedance_B[Ohm]; // constant impedance load on phase B, specified as Ohms
		complex constant_impedance_C[Ohm]; // constant impedance load on phase C, specified as Ohms
		double constant_impedance_A_real[Ohm]; // constant impedance load on phase A, real only, specified as Ohms
		double constant_impedance_B_real[Ohm]; // constant impedance load on phase B, real only, specified as Ohms
		double constant_impedance_C_real[Ohm]; // constant impedance load on phase C, real only, specified as Ohms
		double constant_impedance_A_reac[Ohm]; // constant impedance load on phase A, imaginary only, specified as Ohms
		double constant_impedance_B_reac[Ohm]; // constant impedance load on phase B, imaginary only, specified as Ohms
		double constant_impedance_C_reac[Ohm]; // constant impedance load on phase C, imaginary only, specified as Ohms
		complex constant_power_AN[VA]; // constant power wye-connected load on phase A, specified as VA
		complex constant_power_BN[VA]; // constant power wye-connected load on phase B, specified as VA
		complex constant_power_CN[VA]; // constant power wye-connected load on phase C, specified as VA
		double constant_power_AN_real[W]; // constant power wye-connected load on phase A, real only, specified as W
		double constant_power_BN_real[W]; // constant power wye-connected load on phase B, real only, specified as W
		double constant_power_CN_real[W]; // constant power wye-connected load on phase C, real only, specified as W
		double constant_power_AN_reac[VAr]; // constant power wye-connected load on phase A, imaginary only, specified as VAr
		double constant_power_BN_reac[VAr]; // constant power wye-connected load on phase B, imaginary only, specified as VAr
		double constant_power_CN_reac[VAr]; // constant power wye-connected load on phase C, imaginary only, specified as VAr
		complex constant_current_AN[A]; // constant current wye-connected load on phase A, specified as Amps
		complex constant_current_BN[A]; // constant current wye-connected load on phase B, specified as Amps
		complex constant_current_CN[A]; // constant current wye-connected load on phase C, specified as Amps
		double constant_current_AN_real[A]; // constant current wye-connected load on phase A, real only, specified as Amps
		double constant_current_BN_real[A]; // constant current wye-connected load on phase B, real only, specified as Amps
		double constant_current_CN_real[A]; // constant current wye-connected load on phase C, real only, specified as Amps
		double constant_current_AN_reac[A]; // constant current wye-connected load on phase A, imaginary only, specified as Amps
		double constant_current_BN_reac[A]; // constant current wye-connected load on phase B, imaginary only, specified as Amps
		double constant_current_CN_reac[A]; // constant current wye-connected load on phase C, imaginary only, specified as Amps
		complex constant_impedance_AN[Ohm]; // constant impedance wye-connected load on phase A, specified as Ohms
		complex constant_impedance_BN[Ohm]; // constant impedance wye-connected load on phase B, specified as Ohms
		complex constant_impedance_CN[Ohm]; // constant impedance wye-connected load on phase C, specified as Ohms
		double constant_impedance_AN_real[Ohm]; // constant impedance wye-connected load on phase A, real only, specified as Ohms
		double constant_impedance_BN_real[Ohm]; // constant impedance wye-connected load on phase B, real only, specified as Ohms
		double constant_impedance_CN_real[Ohm]; // constant impedance wye-connected load on phase C, real only, specified as Ohms
		double constant_impedance_AN_reac[Ohm]; // constant impedance wye-connected load on phase A, imaginary only, specified as Ohms
		double constant_impedance_BN_reac[Ohm]; // constant impedance wye-connected load on phase B, imaginary only, specified as Ohms
		double constant_impedance_CN_reac[Ohm]; // constant impedance wye-connected load on phase C, imaginary only, specified as Ohms
		complex constant_power_AB[VA]; // constant power delta-connected load on phase A, specified as VA
		complex constant_power_BC[VA]; // constant power delta-connected load on phase B, specified as VA
		complex constant_power_CA[VA]; // constant power delta-connected load on phase C, specified as VA
		double constant_power_AB_real[W]; // constant power delta-connected load on phase A, real only, specified as W
		double constant_power_BC_real[W]; // constant power delta-connected load on phase B, real only, specified as W
		double constant_power_CA_real[W]; // constant power delta-connected load on phase C, real only, specified as W
		double constant_power_AB_reac[VAr]; // constant power delta-connected load on phase A, imaginary only, specified as VAr
		double constant_power_BC_reac[VAr]; // constant power delta-connected load on phase B, imaginary only, specified as VAr
		double constant_power_CA_reac[VAr]; // constant power delta-connected load on phase C, imaginary only, specified as VAr
		complex constant_current_AB[A]; // constant current delta-connected load on phase A, specified as Amps
		complex constant_current_BC[A]; // constant current delta-connected load on phase B, specified as Amps
		complex constant_current_CA[A]; // constant current delta-connected load on phase C, specified as Amps
		double constant_current_AB_real[A]; // constant current delta-connected load on phase A, real only, specified as Amps
		double constant_current_BC_real[A]; // constant current delta-connected load on phase B, real only, specified as Amps
		double constant_current_CA_real[A]; // constant current delta-connected load on phase C, real only, specified as Amps
		double constant_current_AB_reac[A]; // constant current delta-connected load on phase A, imaginary only, specified as Amps
		double constant_current_BC_reac[A]; // constant current delta-connected load on phase B, imaginary only, specified as Amps
		double constant_current_CA_reac[A]; // constant current delta-connected load on phase C, imaginary only, specified as Amps
		complex constant_impedance_AB[Ohm]; // constant impedance delta-connected load on phase A, specified as Ohms
		complex constant_impedance_BC[Ohm]; // constant impedance delta-connected load on phase B, specified as Ohms
		complex constant_impedance_CA[Ohm]; // constant impedance delta-connected load on phase C, specified as Ohms
		double constant_impedance_AB_real[Ohm]; // constant impedance delta-connected load on phase A, real only, specified as Ohms
		double constant_impedance_BC_real[Ohm]; // constant impedance delta-connected load on phase B, real only, specified as Ohms
		double constant_impedance_CA_real[Ohm]; // constant impedance delta-connected load on phase C, real only, specified as Ohms
		double constant_impedance_AB_reac[Ohm]; // constant impedance delta-connected load on phase A, imaginary only, specified as Ohms
		double constant_impedance_BC_reac[Ohm]; // constant impedance delta-connected load on phase B, imaginary only, specified as Ohms
		double constant_impedance_CA_reac[Ohm]; // constant impedance delta-connected load on phase C, imaginary only, specified as Ohms
		complex measured_voltage_A; // current measured voltage on phase A
		complex measured_voltage_B; // current measured voltage on phase B
		complex measured_voltage_C; // current measured voltage on phase C
		complex measured_voltage_AB; // current measured voltage on phases AB
		complex measured_voltage_BC; // current measured voltage on phases BC
		complex measured_voltage_CA; // current measured voltage on phases CA
		bool phase_loss_protection; // Trip all three phases of the load if a fault occurs
		double base_power_A[VA]; // in similar format as ZIPload, this represents the nominal power on phase A before applying ZIP fractions
		double base_power_B[VA]; // in similar format as ZIPload, this represents the nominal power on phase B before applying ZIP fractions
		double base_power_C[VA]; // in similar format as ZIPload, this represents the nominal power on phase C before applying ZIP fractions
		double power_pf_A[pu]; // in similar format as ZIPload, this is the power factor of the phase A constant power portion of load
		double current_pf_A[pu]; // in similar format as ZIPload, this is the power factor of the phase A constant current portion of load
		double impedance_pf_A[pu]; // in similar format as ZIPload, this is the power factor of the phase A constant impedance portion of load
		double power_pf_B[pu]; // in similar format as ZIPload, this is the power factor of the phase B constant power portion of load
		double current_pf_B[pu]; // in similar format as ZIPload, this is the power factor of the phase B constant current portion of load
		double impedance_pf_B[pu]; // in similar format as ZIPload, this is the power factor of the phase B constant impedance portion of load
		double power_pf_C[pu]; // in similar format as ZIPload, this is the power factor of the phase C constant power portion of load
		double current_pf_C[pu]; // in similar format as ZIPload, this is the power factor of the phase C constant current portion of load
		double impedance_pf_C[pu]; // in similar format as ZIPload, this is the power factor of the phase C constant impedance portion of load
		double power_fraction_A[pu]; // this is the constant power fraction of base power on phase A
		double current_fraction_A[pu]; // this is the constant current fraction of base power on phase A
		double impedance_fraction_A[pu]; // this is the constant impedance fraction of base power on phase A
		double power_fraction_B[pu]; // this is the constant power fraction of base power on phase B
		double current_fraction_B[pu]; // this is the constant current fraction of base power on phase B
		double impedance_fraction_B[pu]; // this is the constant impedance fraction of base power on phase B
		double power_fraction_C[pu]; // this is the constant power fraction of base power on phase C
		double current_fraction_C[pu]; // this is the constant current fraction of base power on phase C
		double impedance_fraction_C[pu]; // this is the constant impedance fraction of base power on phase C
	}

	object weather;
	double T_nominal[degF];
	double Zp_T[ohm/degF];
	double Zp_H[ohm/%];
	double Zp_S[ohm*h/Btu];
	double Zp_W[ohm/mph];
	double Zp_R[ohm*h/in];
	double Zp[ohm];
	double Zq_T[F/degF];
	double Zq_H[F/%];
	double Zq_S[F*h/Btu];
	double Zq_W[F/mph];
	double Zq_R[F*h/in];
	double Zq[F];
	double Im_T[A/degF];
	double Im_H[A/%];
	double Im_S[A*h/Btu];
	double Im_W[A/mph];
	double Im_R[A*h/in];
	double Im[A];
	double Ia_T[deg/degF];
	double Ia_H[deg/%];
	double Ia_S[deg*h/Btu];
	double Ia_W[deg/mph];
	double Ia_R[deg*h/in];
	double Ia[deg];
	double Pp_T[W/degF];
	double Pp_H[W/%];
	double Pp_S[W*h/Btu];
	double Pp_W[W/mph];
	double Pp_R[W*h/in];
	double Pp[W];
	double Pq_T[VAr/degF];
	double Pq_H[VAr/%];
	double Pq_S[VAr*h/Btu];
	double Pq_W[VAr/mph];
	double Pq_R[VAr*h/in];
	double Pq[VAr];
	double input_temp[degF];
	double input_humid[%];
	double input_solar[Btu/h];
	double input_wind[mph];
	double input_rain[in/h];
	double output_imped_p[Ohm];
	double output_imped_q[Ohm];
	double output_current_m[A];
	double output_current_a[deg];
	double output_power_p[W];
	double output_power_q[VAr];
	complex output_impedance[ohm];
	complex output_current[A];
	complex output_power[VA];
}

class recloser {
	parent switch;
	class switch {
		parent link;
		class link {
			parent powerflow_object;
			class powerflow_object {
				set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
				double nominal_voltage[V];
			}

			function interupdate_pwr_object();
			function update_power_pwr_object();
			function check_limits_pwr_object();
			enumeration {OPEN=0, CLOSED=1} status; // 
			object from; // from_node - source node
			object to; // to_node - load node
			complex power_in[VA]; // power flow in (w.r.t from node)
			complex power_out[VA]; // power flow out (w.r.t to node)
			double power_out_real[W]; // power flow out (w.r.t to node), real
			complex power_losses[VA]; // power losses
			complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
			complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
			complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
			complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
			complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
			complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
			complex power_losses_A[VA]; // power losses, phase A
			complex power_losses_B[VA]; // power losses, phase B
			complex power_losses_C[VA]; // power losses, phase C
			complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
			complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
			complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
			complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
			complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
			complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
			complex fault_current_in_A[A]; // fault current flowing in, phase A
			complex fault_current_in_B[A]; // fault current flowing in, phase B
			complex fault_current_in_C[A]; // fault current flowing in, phase C
			complex fault_current_out_A[A]; // fault current flowing out, phase A
			complex fault_current_out_B[A]; // fault current flowing out, phase B
			complex fault_current_out_C[A]; // fault current flowing out, phase C
			set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
			double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
			double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
			double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
			double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
		}

		function change_switch_state();
		function reliability_operation();
		function create_fault();
		function fix_fault();
		function change_switch_faults();
		function interupdate_pwr_object();
		function update_power_pwr_object();
		function check_limits_pwr_object();
		enumeration {CLOSED=1, OPEN=0} phase_A_state; // Defines the current state of the phase A switch
		enumeration {CLOSED=1, OPEN=0} phase_B_state; // Defines the current state of the phase B switch
		enumeration {CLOSED=1, OPEN=0} phase_C_state; // Defines the current state of the phase C switch
		enumeration {BANKED=1, INDIVIDUAL=0} operating_mode; // Defines whether the switch operates in a banked or per-phase control mode
		double switch_resistance[Ohm]; // The resistance value of the switch when it is not blown.
	}

	function change_recloser_state();
	function recloser_reliability_operation();
	function change_recloser_faults();
	function interupdate_pwr_object();
	function update_power_pwr_object();
	function check_limits_pwr_object();
	double retry_time[s]; // the amount of time in seconds to wait before the recloser attempts to close
	double max_number_of_tries; // the number of times the recloser will try to close before permanently opening
	double number_of_tries; // Current number of tries recloser has attempted
}

class regulator {
	parent link;
	class link {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function interupdate_pwr_object();
		function update_power_pwr_object();
		function check_limits_pwr_object();
		enumeration {OPEN=0, CLOSED=1} status; // 
		object from; // from_node - source node
		object to; // to_node - load node
		complex power_in[VA]; // power flow in (w.r.t from node)
		complex power_out[VA]; // power flow out (w.r.t to node)
		double power_out_real[W]; // power flow out (w.r.t to node), real
		complex power_losses[VA]; // power losses
		complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
		complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
		complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
		complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
		complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
		complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
		complex power_losses_A[VA]; // power losses, phase A
		complex power_losses_B[VA]; // power losses, phase B
		complex power_losses_C[VA]; // power losses, phase C
		complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
		complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
		complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
		complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
		complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
		complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
		complex fault_current_in_A[A]; // fault current flowing in, phase A
		complex fault_current_in_B[A]; // fault current flowing in, phase B
		complex fault_current_in_C[A]; // fault current flowing in, phase C
		complex fault_current_out_A[A]; // fault current flowing out, phase A
		complex fault_current_out_B[A]; // fault current flowing out, phase B
		complex fault_current_out_C[A]; // fault current flowing out, phase C
		set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
		double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
		double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
		double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
		double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
	}

	function interupdate_pwr_object();
	function update_power_pwr_object();
	function check_limits_pwr_object();
	object configuration; // reference to the regulator_configuration object used to determine regulator properties
	int16 tap_A; // current tap position of tap A
	int16 tap_B; // current tap position of tap B
	int16 tap_C; // current tap position of tap C
	double tap_A_change_count; // count of all physical tap changes on phase A since beginning of simulation (plus initial value)
	double tap_B_change_count; // count of all physical tap changes on phase B since beginning of simulation (plus initial value)
	double tap_C_change_count; // count of all physical tap changes on phase C since beginning of simulation (plus initial value)
	object sense_node; // Node to be monitored for voltage control in remote sense mode
	double regulator_resistance[Ohm]; // The resistance value of the regulator when it is not blown.
}

class regulator_configuration {
	enumeration {CLOSED_DELTA=5, OPEN_DELTA_CABA=4, OPEN_DELTA_BCAC=3, OPEN_DELTA_ABBC=2, WYE_WYE=1, UNKNOWN=0} connect_type; // Designation of connection style
	double band_center[V]; // band center setting of regulator control
	double band_width[V]; // band width setting of regulator control
	double time_delay[s]; // mechanical time delay between tap changes
	double dwell_time[s]; // time delay before a control action of regulator control
	int16 raise_taps; // number of regulator raise taps, or the maximum raise voltage tap position
	int16 lower_taps; // number of regulator lower taps, or the minimum lower voltage tap position
	double current_transducer_ratio[pu]; // primary rating of current transformer
	double power_transducer_ratio[pu]; // potential transformer rating
	double compensator_r_setting_A[V]; // Line Drop Compensation R setting of regulator control (in volts) on Phase A
	double compensator_r_setting_B[V]; // Line Drop Compensation R setting of regulator control (in volts) on Phase B
	double compensator_r_setting_C[V]; // Line Drop Compensation R setting of regulator control (in volts) on Phase C
	double compensator_x_setting_A[V]; // Line Drop Compensation X setting of regulator control (in volts) on Phase A
	double compensator_x_setting_B[V]; // Line Drop Compensation X setting of regulator control (in volts) on Phase B
	double compensator_x_setting_C[V]; // Line Drop Compensation X setting of regulator control (in volts) on Phase C
	set {C=4, B=2, A=1} CT_phase; // phase(s) monitored by CT
	set {C=4, B=2, A=1} PT_phase; // phase(s) monitored by PT
	double regulation; // regulation of voltage regulator in %
	enumeration {BANK=2, INDIVIDUAL=1} control_level; // Designates whether control is on per-phase or banked level
	enumeration {REMOTE_NODE=3, LINE_DROP_COMP=4, OUTPUT_VOLTAGE=2, MANUAL=1} Control; // Type of control used for regulating voltage
	enumeration {LOCK_CURRENT_POSITION=2, LOCK_NEUTRAL=1, LOCK_NONE=0} reverse_flow_control; // Type of control used when power is flowing in reverse through the regulator
	enumeration {B=2, A=1} Type; // Defines regulator type
	int16 tap_pos_A; // initial tap position of phase A
	int16 tap_pos_B; // initial tap position of phase B
	int16 tap_pos_C; // initial tap position of phase C
}

class restoration {
	function perform_restoration();
	int32 reconfig_attempts; // Number of reconfigurations/timestep to try before giving up
	int32 reconfig_iteration_limit; // Number of iterations to let PF go before flagging this as a bad reconfiguration
	object source_vertex; // Source vertex object for reconfiguration
	object faulted_section; // Faulted section for reconfiguration
	char1024 feeder_power_limit; // Comma-separated power limit (VA) for feeders during reconfiguration
	char1024 feeder_power_links; // Comma-separated list of link-based objects for monitoring power through
	char1024 feeder_vertex_list; // Comma-separated object list that defines the feeder vertices
	char1024 microgrid_power_limit; // Comma-separated power limit (complex VA) for microgrids during reconfiguration
	char1024 microgrid_power_links; // Comma-separated list of link-based objects for monitoring power through
	char1024 microgrid_vertex_list; // Comma-separated object list that defines the microgrid vertices
	double lower_voltage_limit[pu]; // Lower voltage limit for the reconfiguration validity checks - per unit
	double upper_voltage_limit[pu]; // Upper voltage limit for the reconfiguration validity checks - per unit
	char1024 output_filename; // Output text file name to describe final or attempted switching operations
	bool generate_all_scenarios; // Flag to determine if restoration reconfiguration and continues, or explores the full space
}

class sectionalizer {
	parent switch;
	class switch {
		parent link;
		class link {
			parent powerflow_object;
			class powerflow_object {
				set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
				double nominal_voltage[V];
			}

			function interupdate_pwr_object();
			function update_power_pwr_object();
			function check_limits_pwr_object();
			enumeration {OPEN=0, CLOSED=1} status; // 
			object from; // from_node - source node
			object to; // to_node - load node
			complex power_in[VA]; // power flow in (w.r.t from node)
			complex power_out[VA]; // power flow out (w.r.t to node)
			double power_out_real[W]; // power flow out (w.r.t to node), real
			complex power_losses[VA]; // power losses
			complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
			complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
			complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
			complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
			complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
			complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
			complex power_losses_A[VA]; // power losses, phase A
			complex power_losses_B[VA]; // power losses, phase B
			complex power_losses_C[VA]; // power losses, phase C
			complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
			complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
			complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
			complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
			complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
			complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
			complex fault_current_in_A[A]; // fault current flowing in, phase A
			complex fault_current_in_B[A]; // fault current flowing in, phase B
			complex fault_current_in_C[A]; // fault current flowing in, phase C
			complex fault_current_out_A[A]; // fault current flowing out, phase A
			complex fault_current_out_B[A]; // fault current flowing out, phase B
			complex fault_current_out_C[A]; // fault current flowing out, phase C
			set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
			double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
			double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
			double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
			double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
		}

		function change_switch_state();
		function reliability_operation();
		function create_fault();
		function fix_fault();
		function change_switch_faults();
		function interupdate_pwr_object();
		function update_power_pwr_object();
		function check_limits_pwr_object();
		enumeration {CLOSED=1, OPEN=0} phase_A_state; // Defines the current state of the phase A switch
		enumeration {CLOSED=1, OPEN=0} phase_B_state; // Defines the current state of the phase B switch
		enumeration {CLOSED=1, OPEN=0} phase_C_state; // Defines the current state of the phase C switch
		enumeration {BANKED=1, INDIVIDUAL=0} operating_mode; // Defines whether the switch operates in a banked or per-phase control mode
		double switch_resistance[Ohm]; // The resistance value of the switch when it is not blown.
	}

	function change_sectionalizer_state();
	function sectionalizer_reliability_operation();
	function change_sectionalizer_faults();
	function interupdate_pwr_object();
	function update_power_pwr_object();
	function check_limits_pwr_object();
}

class series_reactor {
	parent link;
	class link {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function interupdate_pwr_object();
		function update_power_pwr_object();
		function check_limits_pwr_object();
		enumeration {OPEN=0, CLOSED=1} status; // 
		object from; // from_node - source node
		object to; // to_node - load node
		complex power_in[VA]; // power flow in (w.r.t from node)
		complex power_out[VA]; // power flow out (w.r.t to node)
		double power_out_real[W]; // power flow out (w.r.t to node), real
		complex power_losses[VA]; // power losses
		complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
		complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
		complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
		complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
		complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
		complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
		complex power_losses_A[VA]; // power losses, phase A
		complex power_losses_B[VA]; // power losses, phase B
		complex power_losses_C[VA]; // power losses, phase C
		complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
		complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
		complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
		complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
		complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
		complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
		complex fault_current_in_A[A]; // fault current flowing in, phase A
		complex fault_current_in_B[A]; // fault current flowing in, phase B
		complex fault_current_in_C[A]; // fault current flowing in, phase C
		complex fault_current_out_A[A]; // fault current flowing out, phase A
		complex fault_current_out_B[A]; // fault current flowing out, phase B
		complex fault_current_out_C[A]; // fault current flowing out, phase C
		set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
		double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
		double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
		double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
		double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
	}

	function interupdate_pwr_object();
	function update_power_pwr_object();
	function check_limits_pwr_object();
	complex phase_A_impedance[Ohm]; // Series impedance of reactor on phase A
	double phase_A_resistance[Ohm]; // Resistive portion of phase A's impedance
	double phase_A_reactance[Ohm]; // Reactive portion of phase A's impedance
	complex phase_B_impedance[Ohm]; // Series impedance of reactor on phase B
	double phase_B_resistance[Ohm]; // Resistive portion of phase B's impedance
	double phase_B_reactance[Ohm]; // Reactive portion of phase B's impedance
	complex phase_C_impedance[Ohm]; // Series impedance of reactor on phase C
	double phase_C_resistance[Ohm]; // Resistive portion of phase C's impedance
	double phase_C_reactance[Ohm]; // Reactive portion of phase C's impedance
	double rated_current_limit[A]; // Rated current limit for the reactor
}

class substation {
	parent node;
	class node {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function delta_linkage_node();
		function interupdate_pwr_object();
		function delta_freq_pwr_object();
		enumeration {SWING=2, PV=1, PQ=0} bustype; // defines whether the node is a PQ, PV, or SWING node
		set {HASSOURCE=1} busflags; // flag indicates node has a source for voltage, i.e. connects to the swing node
		object reference_bus; // reference bus from which frequency is defined
		double maximum_voltage_error[V]; // convergence voltage limit or convergence criteria
		complex voltage_A[V]; // bus voltage, Phase A to ground
		complex voltage_B[V]; // bus voltage, Phase B to ground
		complex voltage_C[V]; // bus voltage, Phase C to ground
		complex voltage_AB[V]; // line voltages, Phase AB
		complex voltage_BC[V]; // line voltages, Phase BC
		complex voltage_CA[V]; // line voltages, Phase CA
		complex current_A[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex current_B[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex current_C[A]; // bus current injection (in = positive), this an accumulator only, not a output or input variable
		complex power_A[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex power_B[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex power_C[VA]; // bus power injection (in = positive), this an accumulator only, not a output or input variable
		complex shunt_A[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex shunt_B[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex shunt_C[S]; // bus shunt admittance, this an accumulator only, not a output or input variable
		complex current_AB[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_BC[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_CA[A]; // bus current delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_AN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_BN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex current_CN[A]; // bus current wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_AB[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_BC[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_CA[VA]; // bus power delta-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_AN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_BN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex power_CN[VA]; // bus power wye-connected injection (in = positive), this an accumulator only, not a output or input variable
		complex shunt_AB[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_BC[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_CA[S]; // bus shunt delta-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_AN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_BN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		complex shunt_CN[S]; // bus shunt wye-connected admittance, this an accumulator only, not a output or input variable
		double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
		enumeration {OUT_OF_SERVICE=0, IN_SERVICE=1} service_status; // In and out of service flag
		double service_status_double; // In and out of service flag - type double - will indiscriminately override service_status - useful for schedules
		double previous_uptime[min]; // Previous time between disconnects of node in minutes
		double current_uptime[min]; // Current time since last disconnect of node in minutes
		bool Norton_dynamic; // Flag to indicate a Norton-equivalent connection -- used for generators and deltamode
		object topological_parent; // topological parent as per GLM configuration
	}

	complex zero_sequence_voltage[V]; // The zero sequence representation of the voltage for the substation object.
	complex positive_sequence_voltage[V]; // The positive sequence representation of the voltage for the substation object.
	complex negative_sequence_voltage[V]; // The negative sequence representation of the voltage for the substation object.
	double base_power[VA]; // The 3 phase VA power rating of the substation.
	double power_convergence_value[VA]; // Default convergence criterion before power is posted to pw_load objects if connected, otherwise ignored
	enumeration {PHASE_C=2, PHASE_B=1, PHASE_A=0} reference_phase; // The reference phase for the positive sequence voltage.
	complex transmission_level_constant_power_load[VA]; // the average constant power load to be posted directly to the pw_load object.
	complex transmission_level_constant_current_load[A]; // the average constant current load at nominal voltage to be posted directly to the pw_load object.
	complex transmission_level_constant_impedance_load[Ohm]; // the average constant impedance load at nominal voltage to be posted directly to the pw_load object.
	complex average_distribution_load[VA]; // The average of the loads on all three phases at the substation object.
	complex distribution_power_A[VA];
	complex distribution_power_B[VA];
	complex distribution_power_C[VA];
	complex distribution_voltage_A[V];
	complex distribution_voltage_B[V];
	complex distribution_voltage_C[V];
	complex distribution_voltage_AB[V];
	complex distribution_voltage_BC[V];
	complex distribution_voltage_CA[V];
	complex distribution_current_A[A];
	complex distribution_current_B[A];
	complex distribution_current_C[A];
	double distribution_real_energy[Wh];
}

class switch {
	parent link;
	class link {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function interupdate_pwr_object();
		function update_power_pwr_object();
		function check_limits_pwr_object();
		enumeration {OPEN=0, CLOSED=1} status; // 
		object from; // from_node - source node
		object to; // to_node - load node
		complex power_in[VA]; // power flow in (w.r.t from node)
		complex power_out[VA]; // power flow out (w.r.t to node)
		double power_out_real[W]; // power flow out (w.r.t to node), real
		complex power_losses[VA]; // power losses
		complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
		complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
		complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
		complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
		complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
		complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
		complex power_losses_A[VA]; // power losses, phase A
		complex power_losses_B[VA]; // power losses, phase B
		complex power_losses_C[VA]; // power losses, phase C
		complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
		complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
		complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
		complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
		complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
		complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
		complex fault_current_in_A[A]; // fault current flowing in, phase A
		complex fault_current_in_B[A]; // fault current flowing in, phase B
		complex fault_current_in_C[A]; // fault current flowing in, phase C
		complex fault_current_out_A[A]; // fault current flowing out, phase A
		complex fault_current_out_B[A]; // fault current flowing out, phase B
		complex fault_current_out_C[A]; // fault current flowing out, phase C
		set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
		double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
		double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
		double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
		double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
	}

	function change_switch_state();
	function reliability_operation();
	function create_fault();
	function fix_fault();
	function change_switch_faults();
	function interupdate_pwr_object();
	function update_power_pwr_object();
	function check_limits_pwr_object();
	enumeration {CLOSED=1, OPEN=0} phase_A_state; // Defines the current state of the phase A switch
	enumeration {CLOSED=1, OPEN=0} phase_B_state; // Defines the current state of the phase B switch
	enumeration {CLOSED=1, OPEN=0} phase_C_state; // Defines the current state of the phase C switch
	enumeration {BANKED=1, INDIVIDUAL=0} operating_mode; // Defines whether the switch operates in a banked or per-phase control mode
	double switch_resistance[Ohm]; // The resistance value of the switch when it is not blown.
}

class transformer {
	parent link;
	class link {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function interupdate_pwr_object();
		function update_power_pwr_object();
		function check_limits_pwr_object();
		enumeration {OPEN=0, CLOSED=1} status; // 
		object from; // from_node - source node
		object to; // to_node - load node
		complex power_in[VA]; // power flow in (w.r.t from node)
		complex power_out[VA]; // power flow out (w.r.t to node)
		double power_out_real[W]; // power flow out (w.r.t to node), real
		complex power_losses[VA]; // power losses
		complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
		complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
		complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
		complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
		complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
		complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
		complex power_losses_A[VA]; // power losses, phase A
		complex power_losses_B[VA]; // power losses, phase B
		complex power_losses_C[VA]; // power losses, phase C
		complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
		complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
		complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
		complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
		complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
		complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
		complex fault_current_in_A[A]; // fault current flowing in, phase A
		complex fault_current_in_B[A]; // fault current flowing in, phase B
		complex fault_current_in_C[A]; // fault current flowing in, phase C
		complex fault_current_out_A[A]; // fault current flowing out, phase A
		complex fault_current_out_B[A]; // fault current flowing out, phase B
		complex fault_current_out_C[A]; // fault current flowing out, phase C
		set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
		double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
		double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
		double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
		double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
	}

	function power_calculation();
	function interupdate_pwr_object();
	function update_power_pwr_object();
	function check_limits_pwr_object();
	object configuration; // Configuration library used for transformer setup
	object climate; // climate object used to describe thermal model ambient temperature
	double ambient_temperature[degC]; // ambient temperature in degrees C
	double top_oil_hot_spot_temperature[degC]; // top-oil hottest-spot temperature, degrees C
	double winding_hot_spot_temperature[degC]; // winding hottest-spot temperature, degrees C
	double percent_loss_of_life; // the percent loss of life
	double aging_constant; // the aging rate slope for the transformer insulation
	bool use_thermal_model; // boolean to enable use of thermal model
	double transformer_replacement_count; // counter of the number times the transformer has been replaced due to lifetime failure
	double aging_granularity[s]; // maximum timestep before updating thermal and aging model in seconds
}

class transformer_configuration {
	enumeration {SINGLE_PHASE_CENTER_TAPPED=5, SINGLE_PHASE=4, DELTA_GWYE=3, DELTA_DELTA=2, WYE_WYE=1, UNKNOWN=0} connect_type; // connect type enum: Wye-Wye, single-phase, etc.
	enumeration {VAULT=3, PADMOUNT=2, POLETOP=1, UNKNOWN=0} install_type; // Defines location of the transformer installation
	enumeration {DRY=2, MINERAL_OIL=1, UNKNOWN=0} coolant_type; // coolant type, used in life time model
	enumeration {DFOW=6, DFOA=5, NDFOW=4, NDFOA=3, FA=2, OA=1, UNKNOWN=0} cooling_type; // type of coolant fluid used in life time model
	double primary_voltage[V]; // primary voltage level in L-L value kV
	double secondary_voltage[V]; // secondary voltage level kV
	double power_rating[kVA]; // kVA rating of transformer, total
	double powerA_rating[kVA]; // kVA rating of transformer, phase A
	double powerB_rating[kVA]; // kVA rating of transformer, phase B
	double powerC_rating[kVA]; // kVA rating of transformer, phase C
	double resistance[pu*Ohm]; // Series impedance, pu, real
	double reactance[pu*Ohm]; // Series impedance, pu, imag
	complex impedance[pu*Ohm]; // Series impedance, pu
	double resistance1[pu*Ohm]; // Secondary series impedance (only used when you want to define each individual winding seperately, pu, real
	double reactance1[pu*Ohm]; // Secondary series impedance (only used when you want to define each individual winding seperately, pu, imag
	complex impedance1[pu*Ohm]; // Secondary series impedance (only used when you want to define each individual winding seperately, pu
	double resistance2[pu*Ohm]; // Secondary series impedance (only used when you want to define each individual winding seperately, pu, real
	double reactance2[pu*Ohm]; // Secondary series impedance (only used when you want to define each individual winding seperately, pu, imag
	complex impedance2[pu*Ohm]; // Secondary series impedance (only used when you want to define each individual winding seperately, pu
	double shunt_resistance[pu*Ohm]; // Shunt impedance on primary side, pu, real
	double shunt_reactance[pu*Ohm]; // Shunt impedance on primary side, pu, imag
	complex shunt_impedance[pu*Ohm]; // Shunt impedance on primary side, pu
	double core_coil_weight[lb]; // The weight of the core and coil assembly in pounds
	double tank_fittings_weight[lb]; // The weight of the tank and fittings in pounds
	double oil_volume[gal]; // The number of gallons of oil in the transformer
	double rated_winding_time_constant[h]; // The rated winding time constant in hours
	double rated_winding_hot_spot_rise[degC]; // winding hottest-spot rise over ambient temperature at rated load, degrees C
	double rated_top_oil_rise[degC]; // top-oil hottest-spot rise over ambient temperature at rated load, degrees C
	double no_load_loss[pu]; // Another method of specifying transformer impedances, defined as per unit power values (shunt)
	double full_load_loss[pu]; // Another method of specifying transformer impedances, defined as per unit power values (shunt and series)
	double reactance_resistance_ratio; // the reactance to resistance ratio (X/R)
	double installed_insulation_life[h]; // the normal lifetime of the transformer insulation at rated load, hours
}

class triplex_line {
	parent line;
	class line {
		parent link;
		class link {
			parent powerflow_object;
			class powerflow_object {
				set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
				double nominal_voltage[V];
			}

			function interupdate_pwr_object();
			function update_power_pwr_object();
			function check_limits_pwr_object();
			enumeration {OPEN=0, CLOSED=1} status; // 
			object from; // from_node - source node
			object to; // to_node - load node
			complex power_in[VA]; // power flow in (w.r.t from node)
			complex power_out[VA]; // power flow out (w.r.t to node)
			double power_out_real[W]; // power flow out (w.r.t to node), real
			complex power_losses[VA]; // power losses
			complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
			complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
			complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
			complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
			complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
			complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
			complex power_losses_A[VA]; // power losses, phase A
			complex power_losses_B[VA]; // power losses, phase B
			complex power_losses_C[VA]; // power losses, phase C
			complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
			complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
			complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
			complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
			complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
			complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
			complex fault_current_in_A[A]; // fault current flowing in, phase A
			complex fault_current_in_B[A]; // fault current flowing in, phase B
			complex fault_current_in_C[A]; // fault current flowing in, phase C
			complex fault_current_out_A[A]; // fault current flowing out, phase A
			complex fault_current_out_B[A]; // fault current flowing out, phase B
			complex fault_current_out_C[A]; // fault current flowing out, phase C
			set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
			double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
			double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
			double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
			double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
		}

		function interupdate_pwr_object();
		function update_power_pwr_object();
		function check_limits_pwr_object();
		object configuration;
		double length[ft];
	}

	function interupdate_pwr_object();
	function recalc_distribution_line();
	function update_power_pwr_object();
	function check_limits_pwr_object();
}

class triplex_line_conductor {
	double resistance[Ohm/mile]; // resistance of cable in ohm/mile
	double geometric_mean_radius[ft]; // geometric mean radius of the cable
	double rating.summer.continuous[A]; // amp ratings for the cable during continuous operation in summer
	double rating.summer.emergency[A]; // amp ratings for the cable during short term operation in summer
	double rating.winter.continuous[A]; // amp ratings for the cable during continuous operation in winter
	double rating.winter.emergency[A]; // amp ratings for the cable during short term operation in winter
}

class triplex_line_configuration {
	object conductor_1; // conductor type for phase 1
	object conductor_2; // conductor type for phase 2
	object conductor_N; // conductor type for phase N
	double insulation_thickness[in]; // thickness of insulation around cabling
	double diameter[in]; // total diameter of cable
	object spacing; // defines the line spacing configuration
	complex z11[Ohm/mile]; // phase 1 self-impedance, used for direct entry of impedance values
	complex z12[Ohm/mile]; // phase 1-2 induced impedance, used for direct entry of impedance values
	complex z21[Ohm/mile]; // phase 2-1 induced impedance, used for direct entry of impedance values
	complex z22[Ohm/mile]; // phase 2 self-impedance, used for direct entry of impedance values
	double rating.summer.continuous[A]; // amp rating in summer, continuous
	double rating.summer.emergency[A]; // amp rating in summer, short term
	double rating.winter.continuous[A]; // amp rating in winter, continuous
	double rating.winter.emergency[A]; // amp rating in winter, short term
}

class triplex_load {
	parent triplex_node;
	class triplex_node {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function delta_linkage_node();
		function interupdate_pwr_object();
		function delta_freq_pwr_object();
		enumeration {SWING=2, PV=1, PQ=0} bustype; // defines whether the node is a PQ, PV, or SWING node
		set {HASSOURCE=1} busflags; // flag indicates node has a source for voltage, i.e. connects to the swing node
		object reference_bus; // reference bus from which frequency is defined
		double maximum_voltage_error[V]; // convergence voltage limit or convergence criteria
		complex voltage_1[V]; // bus voltage, phase 1 to ground
		complex voltage_2[V]; // bus voltage, phase 2 to ground
		complex voltage_N[V]; // bus voltage, phase N to ground
		complex voltage_12[V]; // bus voltage, phase 1 to 2
		complex voltage_1N[V]; // bus voltage, phase 1 to N
		complex voltage_2N[V]; // bus voltage, phase 2 to N
		complex current_1[A]; // constant current load on phase 1, also acts as accumulator
		complex current_2[A]; // constant current load on phase 2, also acts as accumulator
		complex current_N[A]; // constant current load on phase N, also acts as accumulator
		double current_1_real[A]; // constant current load on phase 1, real
		double current_2_real[A]; // constant current load on phase 2, real
		double current_N_real[A]; // constant current load on phase N, real
		double current_1_reac[A]; // constant current load on phase 1, imag
		double current_2_reac[A]; // constant current load on phase 2, imag
		double current_N_reac[A]; // constant current load on phase N, imag
		complex current_12[A]; // constant current load on phase 1 to 2
		double current_12_real[A]; // constant current load on phase 1 to 2, real
		double current_12_reac[A]; // constant current load on phase 1 to 2, imag
		complex residential_nominal_current_1[A]; // posted current on phase 1 from a residential object, if attached
		complex residential_nominal_current_2[A]; // posted current on phase 2 from a residential object, if attached
		complex residential_nominal_current_12[A]; // posted current on phase 1 to 2 from a residential object, if attached
		double residential_nominal_current_1_real[A]; // posted current on phase 1, real, from a residential object, if attached
		double residential_nominal_current_1_imag[A]; // posted current on phase 1, imag, from a residential object, if attached
		double residential_nominal_current_2_real[A]; // posted current on phase 2, real, from a residential object, if attached
		double residential_nominal_current_2_imag[A]; // posted current on phase 2, imag, from a residential object, if attached
		double residential_nominal_current_12_real[A]; // posted current on phase 1 to 2, real, from a residential object, if attached
		double residential_nominal_current_12_imag[A]; // posted current on phase 1 to 2, imag, from a residential object, if attached
		complex power_1[VA]; // constant power on phase 1 (120V)
		complex power_2[VA]; // constant power on phase 2 (120V)
		complex power_12[VA]; // constant power on phase 1 to 2 (240V)
		double power_1_real[W]; // constant power on phase 1, real
		double power_2_real[W]; // constant power on phase 2, real
		double power_12_real[W]; // constant power on phase 1 to 2, real
		double power_1_reac[VAr]; // constant power on phase 1, imag
		double power_2_reac[VAr]; // constant power on phase 2, imag
		double power_12_reac[VAr]; // constant power on phase 1 to 2, imag
		complex shunt_1[S]; // constant shunt impedance on phase 1
		complex shunt_2[S]; // constant shunt impedance on phase 2
		complex shunt_12[S]; // constant shunt impedance on phase 1 to 2
		complex impedance_1[Ohm]; // constant series impedance on phase 1
		complex impedance_2[Ohm]; // constant series impedance on phase 2
		complex impedance_12[Ohm]; // constant series impedance on phase 1 to 2
		double impedance_1_real[Ohm]; // constant series impedance on phase 1, real
		double impedance_2_real[Ohm]; // constant series impedance on phase 2, real
		double impedance_12_real[Ohm]; // constant series impedance on phase 1 to 2, real
		double impedance_1_reac[Ohm]; // constant series impedance on phase 1, imag
		double impedance_2_reac[Ohm]; // constant series impedance on phase 2, imag
		double impedance_12_reac[Ohm]; // constant series impedance on phase 1 to 2, imag
		bool house_present; // boolean for detecting whether a house is attached, not an input
		enumeration {OUT_OF_SERVICE=0, IN_SERVICE=1} service_status; // In and out of service flag
		double service_status_double; // In and out of service flag - type double - will indiscriminately override service_status - useful for schedules
		double previous_uptime[min]; // Previous time between disconnects of node in minutes
		double current_uptime[min]; // Current time since last disconnect of node in minutes
		object topological_parent; // topological parent as per GLM configuration
	}

	function delta_linkage_node();
	function interupdate_pwr_object();
	function delta_freq_pwr_object();
	enumeration {A=4, I=3, C=2, R=1, U=0} load_class; // Flag to track load type, not currently used for anything except sorting
	complex constant_power_1[VA]; // constant power load on split phase 1, specified as VA
	complex constant_power_2[VA]; // constant power load on split phase 2, specified as VA
	complex constant_power_12[VA]; // constant power load on split phase 12, specified as VA
	double constant_power_1_real[W]; // constant power load on spit phase 1, real only, specified as W
	double constant_power_2_real[W]; // constant power load on phase 2, real only, specified as W
	double constant_power_12_real[W]; // constant power load on phase 12, real only, specified as W
	double constant_power_1_reac[VAr]; // constant power load on phase 1, imaginary only, specified as VAr
	double constant_power_2_reac[VAr]; // constant power load on phase 2, imaginary only, specified as VAr
	double constant_power_12_reac[VAr]; // constant power load on phase 12, imaginary only, specified as VAr
	complex constant_current_1[A]; // constant current load on phase 1, specified as Amps
	complex constant_current_2[A]; // constant current load on phase 2, specified as Amps
	complex constant_current_12[A]; // constant current load on phase 12, specified as Amps
	double constant_current_1_real[A]; // constant current load on phase 1, real only, specified as Amps
	double constant_current_2_real[A]; // constant current load on phase 2, real only, specified as Amps
	double constant_current_12_real[A]; // constant current load on phase 12, real only, specified as Amps
	double constant_current_1_reac[A]; // constant current load on phase 1, imaginary only, specified as Amps
	double constant_current_2_reac[A]; // constant current load on phase 2, imaginary only, specified as Amps
	double constant_current_12_reac[A]; // constant current load on phase 12, imaginary only, specified as Amps
	complex constant_impedance_1[Ohm]; // constant impedance load on phase 1, specified as Ohms
	complex constant_impedance_2[Ohm]; // constant impedance load on phase 2, specified as Ohms
	complex constant_impedance_12[Ohm]; // constant impedance load on phase 12, specified as Ohms
	double constant_impedance_1_real[Ohm]; // constant impedance load on phase 1, real only, specified as Ohms
	double constant_impedance_2_real[Ohm]; // constant impedance load on phase 2, real only, specified as Ohms
	double constant_impedance_12_real[Ohm]; // constant impedance load on phase 12, real only, specified as Ohms
	double constant_impedance_1_reac[Ohm]; // constant impedance load on phase 1, imaginary only, specified as Ohms
	double constant_impedance_2_reac[Ohm]; // constant impedance load on phase 2, imaginary only, specified as Ohms
	double constant_impedance_12_reac[Ohm]; // constant impedance load on phase 12, imaginary only, specified as Ohms
	complex measured_voltage_1; // current measured voltage on phase 1
	complex measured_voltage_2; // current measured voltage on phase 2
	complex measured_voltage_12; // current measured voltage on phase 12
	double base_power_1[VA]; // in similar format as ZIPload, this represents the nominal power on phase 1 before applying ZIP fractions
	double base_power_2[VA]; // in similar format as ZIPload, this represents the nominal power on phase 2 before applying ZIP fractions
	double base_power_12[VA]; // in similar format as ZIPload, this represents the nominal power on phase 12 before applying ZIP fractions
	double power_pf_1[pu]; // in similar format as ZIPload, this is the power factor of the phase 1 constant power portion of load
	double current_pf_1[pu]; // in similar format as ZIPload, this is the power factor of the phase 1 constant current portion of load
	double impedance_pf_1[pu]; // in similar format as ZIPload, this is the power factor of the phase 1 constant impedance portion of load
	double power_pf_2[pu]; // in similar format as ZIPload, this is the power factor of the phase 2 constant power portion of load
	double current_pf_2[pu]; // in similar format as ZIPload, this is the power factor of the phase 2 constant current portion of load
	double impedance_pf_2[pu]; // in similar format as ZIPload, this is the power factor of the phase 2 constant impedance portion of load
	double power_pf_12[pu]; // in similar format as ZIPload, this is the power factor of the phase 12 constant power portion of load
	double current_pf_12[pu]; // in similar format as ZIPload, this is the power factor of the phase 12 constant current portion of load
	double impedance_pf_12[pu]; // in similar format as ZIPload, this is the power factor of the phase 12 constant impedance portion of load
	double power_fraction_1[pu]; // this is the constant power fraction of base power on phase 1
	double current_fraction_1[pu]; // this is the constant current fraction of base power on phase 1
	double impedance_fraction_1[pu]; // this is the constant impedance fraction of base power on phase 1
	double power_fraction_2[pu]; // this is the constant power fraction of base power on phase 2
	double current_fraction_2[pu]; // this is the constant current fraction of base power on phase 2
	double impedance_fraction_2[pu]; // this is the constant impedance fraction of base power on phase 2
	double power_fraction_12[pu]; // this is the constant power fraction of base power on phase 12
	double current_fraction_12[pu]; // this is the constant current fraction of base power on phase 12
	double impedance_fraction_12[pu]; // this is the constant impedance fraction of base power on phase 12
}

class triplex_meter {
	parent triplex_node;
	class triplex_node {
		parent powerflow_object;
		class powerflow_object {
			set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
			double nominal_voltage[V];
		}

		function delta_linkage_node();
		function interupdate_pwr_object();
		function delta_freq_pwr_object();
		enumeration {SWING=2, PV=1, PQ=0} bustype; // defines whether the node is a PQ, PV, or SWING node
		set {HASSOURCE=1} busflags; // flag indicates node has a source for voltage, i.e. connects to the swing node
		object reference_bus; // reference bus from which frequency is defined
		double maximum_voltage_error[V]; // convergence voltage limit or convergence criteria
		complex voltage_1[V]; // bus voltage, phase 1 to ground
		complex voltage_2[V]; // bus voltage, phase 2 to ground
		complex voltage_N[V]; // bus voltage, phase N to ground
		complex voltage_12[V]; // bus voltage, phase 1 to 2
		complex voltage_1N[V]; // bus voltage, phase 1 to N
		complex voltage_2N[V]; // bus voltage, phase 2 to N
		complex current_1[A]; // constant current load on phase 1, also acts as accumulator
		complex current_2[A]; // constant current load on phase 2, also acts as accumulator
		complex current_N[A]; // constant current load on phase N, also acts as accumulator
		double current_1_real[A]; // constant current load on phase 1, real
		double current_2_real[A]; // constant current load on phase 2, real
		double current_N_real[A]; // constant current load on phase N, real
		double current_1_reac[A]; // constant current load on phase 1, imag
		double current_2_reac[A]; // constant current load on phase 2, imag
		double current_N_reac[A]; // constant current load on phase N, imag
		complex current_12[A]; // constant current load on phase 1 to 2
		double current_12_real[A]; // constant current load on phase 1 to 2, real
		double current_12_reac[A]; // constant current load on phase 1 to 2, imag
		complex residential_nominal_current_1[A]; // posted current on phase 1 from a residential object, if attached
		complex residential_nominal_current_2[A]; // posted current on phase 2 from a residential object, if attached
		complex residential_nominal_current_12[A]; // posted current on phase 1 to 2 from a residential object, if attached
		double residential_nominal_current_1_real[A]; // posted current on phase 1, real, from a residential object, if attached
		double residential_nominal_current_1_imag[A]; // posted current on phase 1, imag, from a residential object, if attached
		double residential_nominal_current_2_real[A]; // posted current on phase 2, real, from a residential object, if attached
		double residential_nominal_current_2_imag[A]; // posted current on phase 2, imag, from a residential object, if attached
		double residential_nominal_current_12_real[A]; // posted current on phase 1 to 2, real, from a residential object, if attached
		double residential_nominal_current_12_imag[A]; // posted current on phase 1 to 2, imag, from a residential object, if attached
		complex power_1[VA]; // constant power on phase 1 (120V)
		complex power_2[VA]; // constant power on phase 2 (120V)
		complex power_12[VA]; // constant power on phase 1 to 2 (240V)
		double power_1_real[W]; // constant power on phase 1, real
		double power_2_real[W]; // constant power on phase 2, real
		double power_12_real[W]; // constant power on phase 1 to 2, real
		double power_1_reac[VAr]; // constant power on phase 1, imag
		double power_2_reac[VAr]; // constant power on phase 2, imag
		double power_12_reac[VAr]; // constant power on phase 1 to 2, imag
		complex shunt_1[S]; // constant shunt impedance on phase 1
		complex shunt_2[S]; // constant shunt impedance on phase 2
		complex shunt_12[S]; // constant shunt impedance on phase 1 to 2
		complex impedance_1[Ohm]; // constant series impedance on phase 1
		complex impedance_2[Ohm]; // constant series impedance on phase 2
		complex impedance_12[Ohm]; // constant series impedance on phase 1 to 2
		double impedance_1_real[Ohm]; // constant series impedance on phase 1, real
		double impedance_2_real[Ohm]; // constant series impedance on phase 2, real
		double impedance_12_real[Ohm]; // constant series impedance on phase 1 to 2, real
		double impedance_1_reac[Ohm]; // constant series impedance on phase 1, imag
		double impedance_2_reac[Ohm]; // constant series impedance on phase 2, imag
		double impedance_12_reac[Ohm]; // constant series impedance on phase 1 to 2, imag
		bool house_present; // boolean for detecting whether a house is attached, not an input
		enumeration {OUT_OF_SERVICE=0, IN_SERVICE=1} service_status; // In and out of service flag
		double service_status_double; // In and out of service flag - type double - will indiscriminately override service_status - useful for schedules
		double previous_uptime[min]; // Previous time between disconnects of node in minutes
		double current_uptime[min]; // Current time since last disconnect of node in minutes
		object topological_parent; // topological parent as per GLM configuration
	}

	function delta_linkage_node();
	function interupdate_pwr_object();
	function delta_freq_pwr_object();
	double measured_real_energy[Wh]; // metered real energy consumption
	double measured_reactive_energy[VAh]; // metered reactive energy consumption
	complex measured_power[VA]; // metered power
	complex indiv_measured_power_1[VA]; // metered power, phase 1
	complex indiv_measured_power_2[VA]; // metered power, phase 2
	complex indiv_measured_power_N[VA]; // metered power, phase N
	double measured_demand[W]; // metered demand (peak of power)
	double measured_real_power[W]; // metered real power
	double measured_reactive_power[VAr]; // metered reactive power
	complex meter_power_consumption[VA]; // power consumed by meter operation
	complex measured_voltage_1[V]; // measured voltage, phase 1 to ground
	complex measured_voltage_2[V]; // measured voltage, phase 2 to ground
	complex measured_voltage_N[V]; // measured voltage, phase N to ground
	complex measured_current_1[A]; // measured current, phase 1
	complex measured_current_2[A]; // measured current, phase 2
	complex measured_current_N[A]; // measured current, phase N
	bool customer_interrupted; // Reliability flag - goes active if the customer is in an interrupted state
	bool customer_interrupted_secondary; // Reliability flag - goes active if the customer is in a secondary interrupted state - i.e., momentary
	double monthly_bill[$]; // Accumulator for the current month's bill
	double previous_monthly_bill[$]; // Total monthly bill for the previous month
	double previous_monthly_energy[kWh]; // 
	double monthly_fee[$]; // Total monthly energy for the previous month
	double monthly_energy[kWh]; // Accumulator for the current month's energy
	enumeration {TIERED_RTP=4, HOURLY=3, TIERED=2, UNIFORM=1, NONE=0} bill_mode; // Designates the bill mode to be used
	object power_market; // Designates the auction object where prices are read from for bill mode
	int32 bill_day; // Day bill is to be processed (assumed to occur at midnight of that day)
	double price[$/kWh]; // Standard uniform pricing
	double price_base[$/kWh]; // Used only in TIERED_RTP mode to describe the price before the first tier
	double first_tier_price[$/kWh]; // first tier price of energy between first and second tier energy
	double first_tier_energy[kWh]; // price of energy on tier above price or price base
	double second_tier_price[$/kWh]; // first tier price of energy between second and third tier energy
	double second_tier_energy[kWh]; // price of energy on tier above first tier
	double third_tier_price[$/kWh]; // first tier price of energy greater than third tier energy
	double third_tier_energy[kWh]; // price of energy on tier above second tier
}

class triplex_node {
	parent powerflow_object;
	class powerflow_object {
		set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
		double nominal_voltage[V];
	}

	function delta_linkage_node();
	function interupdate_pwr_object();
	function delta_freq_pwr_object();
	enumeration {SWING=2, PV=1, PQ=0} bustype; // defines whether the node is a PQ, PV, or SWING node
	set {HASSOURCE=1} busflags; // flag indicates node has a source for voltage, i.e. connects to the swing node
	object reference_bus; // reference bus from which frequency is defined
	double maximum_voltage_error[V]; // convergence voltage limit or convergence criteria
	complex voltage_1[V]; // bus voltage, phase 1 to ground
	complex voltage_2[V]; // bus voltage, phase 2 to ground
	complex voltage_N[V]; // bus voltage, phase N to ground
	complex voltage_12[V]; // bus voltage, phase 1 to 2
	complex voltage_1N[V]; // bus voltage, phase 1 to N
	complex voltage_2N[V]; // bus voltage, phase 2 to N
	complex current_1[A]; // constant current load on phase 1, also acts as accumulator
	complex current_2[A]; // constant current load on phase 2, also acts as accumulator
	complex current_N[A]; // constant current load on phase N, also acts as accumulator
	double current_1_real[A]; // constant current load on phase 1, real
	double current_2_real[A]; // constant current load on phase 2, real
	double current_N_real[A]; // constant current load on phase N, real
	double current_1_reac[A]; // constant current load on phase 1, imag
	double current_2_reac[A]; // constant current load on phase 2, imag
	double current_N_reac[A]; // constant current load on phase N, imag
	complex current_12[A]; // constant current load on phase 1 to 2
	double current_12_real[A]; // constant current load on phase 1 to 2, real
	double current_12_reac[A]; // constant current load on phase 1 to 2, imag
	complex residential_nominal_current_1[A]; // posted current on phase 1 from a residential object, if attached
	complex residential_nominal_current_2[A]; // posted current on phase 2 from a residential object, if attached
	complex residential_nominal_current_12[A]; // posted current on phase 1 to 2 from a residential object, if attached
	double residential_nominal_current_1_real[A]; // posted current on phase 1, real, from a residential object, if attached
	double residential_nominal_current_1_imag[A]; // posted current on phase 1, imag, from a residential object, if attached
	double residential_nominal_current_2_real[A]; // posted current on phase 2, real, from a residential object, if attached
	double residential_nominal_current_2_imag[A]; // posted current on phase 2, imag, from a residential object, if attached
	double residential_nominal_current_12_real[A]; // posted current on phase 1 to 2, real, from a residential object, if attached
	double residential_nominal_current_12_imag[A]; // posted current on phase 1 to 2, imag, from a residential object, if attached
	complex power_1[VA]; // constant power on phase 1 (120V)
	complex power_2[VA]; // constant power on phase 2 (120V)
	complex power_12[VA]; // constant power on phase 1 to 2 (240V)
	double power_1_real[W]; // constant power on phase 1, real
	double power_2_real[W]; // constant power on phase 2, real
	double power_12_real[W]; // constant power on phase 1 to 2, real
	double power_1_reac[VAr]; // constant power on phase 1, imag
	double power_2_reac[VAr]; // constant power on phase 2, imag
	double power_12_reac[VAr]; // constant power on phase 1 to 2, imag
	complex shunt_1[S]; // constant shunt impedance on phase 1
	complex shunt_2[S]; // constant shunt impedance on phase 2
	complex shunt_12[S]; // constant shunt impedance on phase 1 to 2
	complex impedance_1[Ohm]; // constant series impedance on phase 1
	complex impedance_2[Ohm]; // constant series impedance on phase 2
	complex impedance_12[Ohm]; // constant series impedance on phase 1 to 2
	double impedance_1_real[Ohm]; // constant series impedance on phase 1, real
	double impedance_2_real[Ohm]; // constant series impedance on phase 2, real
	double impedance_12_real[Ohm]; // constant series impedance on phase 1 to 2, real
	double impedance_1_reac[Ohm]; // constant series impedance on phase 1, imag
	double impedance_2_reac[Ohm]; // constant series impedance on phase 2, imag
	double impedance_12_reac[Ohm]; // constant series impedance on phase 1 to 2, imag
	bool house_present; // boolean for detecting whether a house is attached, not an input
	enumeration {OUT_OF_SERVICE=0, IN_SERVICE=1} service_status; // In and out of service flag
	double service_status_double; // In and out of service flag - type double - will indiscriminately override service_status - useful for schedules
	double previous_uptime[min]; // Previous time between disconnects of node in minutes
	double current_uptime[min]; // Current time since last disconnect of node in minutes
	object topological_parent; // topological parent as per GLM configuration
}

class underground_line {
	parent line;
	class line {
		parent link;
		class link {
			parent powerflow_object;
			class powerflow_object {
				set {A=1, B=2, C=4, D=256, N=8, S=112, G=128} phases;
				double nominal_voltage[V];
			}

			function interupdate_pwr_object();
			function update_power_pwr_object();
			function check_limits_pwr_object();
			enumeration {OPEN=0, CLOSED=1} status; // 
			object from; // from_node - source node
			object to; // to_node - load node
			complex power_in[VA]; // power flow in (w.r.t from node)
			complex power_out[VA]; // power flow out (w.r.t to node)
			double power_out_real[W]; // power flow out (w.r.t to node), real
			complex power_losses[VA]; // power losses
			complex power_in_A[VA]; // power flow in (w.r.t from node), phase A
			complex power_in_B[VA]; // power flow in (w.r.t from node), phase B
			complex power_in_C[VA]; // power flow in (w.r.t from node), phase C
			complex power_out_A[VA]; // power flow out (w.r.t to node), phase A
			complex power_out_B[VA]; // power flow out (w.r.t to node), phase B
			complex power_out_C[VA]; // power flow out (w.r.t to node), phase C
			complex power_losses_A[VA]; // power losses, phase A
			complex power_losses_B[VA]; // power losses, phase B
			complex power_losses_C[VA]; // power losses, phase C
			complex current_out_A[A]; // current flow out of link (w.r.t. to node), phase A
			complex current_out_B[A]; // current flow out of link (w.r.t. to node), phase B
			complex current_out_C[A]; // current flow out of link (w.r.t. to node), phase C
			complex current_in_A[A]; // current flow to link (w.r.t from node), phase A
			complex current_in_B[A]; // current flow to link (w.r.t from node), phase B
			complex current_in_C[A]; // current flow to link (w.r.t from node), phase C
			complex fault_current_in_A[A]; // fault current flowing in, phase A
			complex fault_current_in_B[A]; // fault current flowing in, phase B
			complex fault_current_in_C[A]; // fault current flowing in, phase C
			complex fault_current_out_A[A]; // fault current flowing out, phase A
			complex fault_current_out_B[A]; // fault current flowing out, phase B
			complex fault_current_out_C[A]; // fault current flowing out, phase C
			set {CN=768, CR=512, CF=256, BN=48, BR=32, BF=16, AN=3, AR=2, AF=1, UNKNOWN=0} flow_direction; // flag used for describing direction of the flow of power
			double mean_repair_time[s]; // Time after a fault clears for the object to be back in service
			double continuous_rating[A]; // Continuous rating for this link object (set individual line segments
			double emergency_rating[A]; // Emergency rating for this link object (set individual line segments
			double inrush_convergence_value[V]; // Tolerance, as change in line voltage drop between iterations, for deltamode in-rush completion
		}

		function interupdate_pwr_object();
		function update_power_pwr_object();
		function check_limits_pwr_object();
		object configuration;
		double length[ft];
	}

	function create_fault();
	function fix_fault();
	function interupdate_pwr_object();
	function recalc_distribution_line();
	function update_power_pwr_object();
	function check_limits_pwr_object();
}

class underground_line_conductor {
	double outer_diameter[in]; // Outer diameter of conductor and sheath
	double conductor_gmr[ft]; // Geometric mean radius of the conductor
	double conductor_diameter[in]; // Diameter of conductor
	double conductor_resistance[Ohm/mile]; // Resistance of conductor in ohm/mile
	double neutral_gmr[ft]; // Geometric mean radius of an individual neutral conductor/strand
	double neutral_diameter[in]; // Diameter of individual neutral conductor/strand of concentric neutral
	double neutral_resistance[Ohm/mile]; // Resistance of an individual neutral conductor/strand in ohm/mile
	int16 neutral_strands; // Number of cable strands in neutral conductor
	double shield_thickness[in]; // The thickness of Tape shield in inches
	double shield_diameter[in]; // The outside diameter of Tape shield in inches
	double insulation_relative_permitivitty[unit]; // Permitivitty of insulation, relative to air
	double shield_gmr[ft]; // Geometric mean radius of shielding sheath
	double shield_resistance[Ohm/mile]; // Resistance of shielding sheath in ohms/mile
	double rating.summer.continuous[A]; // amp rating in summer, continuous
	double rating.summer.emergency[A]; // amp rating in summer, short term
	double rating.winter.continuous[A]; // amp rating in winter, continuous
	double rating.winter.emergency[A]; // amp rating in winter, short term
}

class volt_var_control {
	enumeration {STANDBY=0, ACTIVE=1} control_method; // IVVC activated or in standby
	double capacitor_delay[s]; // Default capacitor time delay - overridden by local defintions
	double regulator_delay[s]; // Default regulator time delay - overriden by local definitions
	double desired_pf; // Desired power-factor magnitude at the substation transformer or regulator
	double d_max; // Scaling constant for capacitor switching on - typically 0.3 - 0.6
	double d_min; // Scaling constant for capacitor switching off - typically 0.1 - 0.4
	object substation_link; // Substation link, transformer, or regulator to measure power factor
	set {C=4, B=2, A=1} pf_phase; // Phase to include in power factor monitoring
	char1024 regulator_list; // List of voltage regulators for the system, separated by commas
	char1024 capacitor_list; // List of controllable capacitors on the system separated by commas
	char1024 voltage_measurements; // List of voltage measurement devices, separated by commas
	char1024 minimum_voltages; // Minimum voltages allowed for feeder, separated by commas
	char1024 maximum_voltages; // Maximum voltages allowed for feeder, separated by commas
	char1024 desired_voltages; // Desired operating voltages for the regulators, separated by commas
	char1024 max_vdrop; // Maximum voltage drop between feeder and end measurements for each regulator, separated by commas
	char1024 high_load_deadband; // High loading case voltage deadband for each regulator, separated by commas
	char1024 low_load_deadband; // Low loading case voltage deadband for each regulator, separated by commas
	bool pf_signed; // Set to true to consider the sign on the power factor.  Otherwise, it just maintains the deadband of +/-desired_pf
}

class voltdump {
	char32 group; // the group ID to output data for (all nodes if empty)
	timestamp runtime; // the time to check voltage data
	char256 filename; // the file to dump the voltage data into
	char256 file; // the file to dump the voltage data into
	int32 runcount; // the number of times the file has been written to
	enumeration {polar=1, rect=0} mode; // dumps the voltages in either polar or rectangular notation
}

