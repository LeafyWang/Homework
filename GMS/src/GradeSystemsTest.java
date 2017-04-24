import static org.junit.Assert.*;

import org.junit.Test;
import org.junit.Before;

public class GradeSystemsTest {

	/**
	 * @uml.property  name="gs"
	 * @uml.associationEnd  
	 */
	private GradeSystems gs;
	@Before
	public void before(){
		gs = new GradeSystems("gradeinput.txt");
	}

	@Test
	public final void testFindPosition() {
		gs.findPosition(985002004);
		assertEquals(14, gs.position);
	}

	@Test
	public final void testContains() {
		String name = gs.contains(985002002);
		assertEquals(name, "林芯妤");
	}


	@Test
	public final void testShowRank() {
		int rank = gs.showRank(985002005);
		assertEquals(10, rank);
	}


}
