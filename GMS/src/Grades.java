 /**

* Student's own grades.

* @author Encore

* @Time 2016/3/19

*

*/
public class Grades {

	/**
	 * @uml.property  name="name"
	 */
	private String name;	          		   		 //name
	/**
	 * @uml.property  name="id"
	 */
	private long id;                    			 //ID
	/**
	 * @uml.property  name="lab1"
	 */
	private int lab1;     			 //lab scores.
	/**
	 * @uml.property  name="lab2"
	 */
	private int lab2;
	/**
	 * @uml.property  name="lab3"
	 */
	private int lab3;
	/**
	 * @uml.property  name="mid_term"
	 */
	private int mid_term;    			 //exam scores.
	/**
	 * @uml.property  name="finalexam"
	 */
	private int finalexam;
	/**
	 * @uml.property  name="average"
	 */
	private int average;                			 //average score.
	
	public Grades(String name , long id , int lab1 , int lab2 , int lab3 , int mid_term , int finalexam){
		this.name = name;
		this.id = id;
		this.lab1 = lab1;
		this.lab2 = lab2;
		this.lab3 = lab3;
		this.mid_term = mid_term;
		this.finalexam = finalexam;
	}
	
	public Grades(){
		name = null;
	}
	
	public Grades(String info)throws Exception{
		/**
		 * get student's information 
		 * @throws exception
		 */
		String[] s = info.split(" ");
		if(s.length != 7){
			s[1] = s[1] + s[2] + s[3];
			s[2] = s[4];
			s[3] = s[5];
			s[4] = s[6];
			s[5] = s[7];
		} 
		if(s[0].charAt(0) == 65279) 
			s[0] = s[0].substring(1, s[0].length());
//		System.out.println((int)s[0].charAt(0));
		this.id = Long.parseLong(s[0]);
		this.name = s[1];
		this.lab1 = Integer.parseInt(s[2]);
		this.lab2 = Integer.parseInt(s[3]);
		this.lab3 = Integer.parseInt(s[4]);
		this.mid_term = Integer.parseInt(s[5]);
		this.finalexam = Integer.parseInt(s[6]);
	}
	
	public void CountAverage(int[] weight){
		/**
		 * count student's average score��round to integer��
		 * @param weight  the weight of average score
		 */
		average = (int)((lab1 * weight[0] + lab2 * weight[1] + lab3 * weight[2] + mid_term * weight[3] + finalexam * weight[4]) /100);
	}
	
	/**
	 * @return
	 * @uml.property  name="average"
	 */
	public int getAverage(){
		/**
		 * get average score.
		 * @return average  average score.
		 */
		return average;
	}
	
	public long getID(){
		/**
		 * get ID
		 * @return ID
		 */
		return id;
	}
	
	
	/**
	 * @return
	 * @uml.property  name="name"
	 */
	public String getName(){
		/**
		 * get name
		 * @return name
		 */
		return name;
	}
	
	public int[] getGrades()
	{
		/**
		 * return student's grades.
		 * @return grades  an array of score.
		 */
		int[] grades = {lab1,lab2,lab3,mid_term,finalexam,average};
		return grades;
	}
	
	
}
