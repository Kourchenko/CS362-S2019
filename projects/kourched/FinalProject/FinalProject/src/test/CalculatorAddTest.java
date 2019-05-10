package test;

import calculator.Calculator;
import junit.framework.TestCase;

public class CalculatorAddTest extends TestCase {
	protected void setUp() throws Exception {
		super.setUp();
	}
	protected void tearDown() throws Exception {
		super.tearDown();
	}

	public void testAdd() {
		Calculator cal = new Calculator();
		assertEquals(5, cal.add(2, 3));
	}

}
