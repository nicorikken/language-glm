class assert {
	enumeration {NONE=3, FALSE=2, TRUE=1, INIT=0} status; // desired outcome of assert test
	char1024 target; // the target property to test
	char32 part; // the target property part to test
	enumeration {outside=7, inside=6, !==3, >==2, >=5, <==1, <=4, ===0} relation; // the relation to use for the test
	char1024 value; // the value to compare with for binary tests
	char1024 within; // the bounds within which the value must bed compared
	char1024 lower; // the lower bound to compare with for interval tests
	char1024 upper; // the upper bound to compare with for interval tests
}

class assert {
	enumeration {NONE=3, FALSE=2, TRUE=1, INIT=0} status; // desired outcome of assert test
	char1024 target; // the target property to test
	char32 part; // the target property part to test
	enumeration {outside=7, inside=6, !==3, >==2, >=5, <==1, <=4, ===0} relation; // the relation to use for the test
	char1024 value; // the value to compare with for binary tests
	char1024 within; // the bounds within which the value must bed compared
	char1024 lower; // the lower bound to compare with for interval tests
	char1024 upper; // the upper bound to compare with for interval tests
}

class complex_assert {
	enumeration {ASSERT_NONE=3, ASSERT_FALSE=2, ASSERT_TRUE=1} status; // Conditions for the assert checks
	enumeration {ONCE_DONE=2, ONCE_TRUE=1, ONCE_FALSE=0} once; // Conditions for a single assert check
	enumeration {ANGLE=4, MAGNITUDE=3, IMAGINARY=2, REAL=1, FULL=0} operation; // Complex operation for the comparison
	complex value; // Value to assert
	double within; // Tolerance for a successful assert
	char1024 target; // Property to perform the assert upon
}

class double_assert {
	enumeration {ASSERT_NONE=3, ASSERT_FALSE=2, ASSERT_TRUE=1} status; // Conditions for the assert checks
	enumeration {ONCE_DONE=2, ONCE_TRUE=1, ONCE_FALSE=0} once; // Conditions for a single assert check
	enumeration {WITHIN_RATIO=1, WITHIN_VALUE=0} within_mode; // Method of applying tolerance
	double value; // Value to assert
	double within; // Tolerance for a successful assert
	char1024 target; // Property to perform the assert upon
}

class enum_assert {
	enumeration {ASSERT_NONE=3, ASSERT_FALSE=2, ASSERT_TRUE=1} status; // Conditions for the assert checks
	int32 value; // Value to assert
	char1024 target; // Property to perform the assert upon
}

class int_assert {
	enumeration {ASSERT_NONE=3, ASSERT_FALSE=2, ASSERT_TRUE=1} status;
	enumeration {ONCE_DONE=2, ONCE_TRUE=1, ONCE_FALSE=0} once;
	enumeration {WITHIN_RATIO=1, WITHIN_VALUE=0} within_mode;
	int32 value;
	int32 within;
	char1024 target;
}

