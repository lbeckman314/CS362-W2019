import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest() {
       UrlValidator urlChecker = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);

       assertTrue(urlChecker.isValid("http://localhost"));
       assertTrue(urlChecker.isValid("http://localhost/"));
       assertTrue(urlChecker.isValid("http://www.oregonstate.edu"));
       assertTrue(urlChecker.isValid("http://www.oregonstate.edu/"));
       assertTrue(urlChecker.isValid("http://www.oregonstate.edu/future"));
       assertTrue(urlChecker.isValid("http://oregonstate.edu"));
       assertTrue(urlChecker.isValid("http://oregonstate.edu?key=value"));
       //assertTrue(urlChecker.isValid("http://web.engr.oregonstate.edu/~kovskye/"));
       //assertTrue(urlChecker.isValid("https://oregonstate.instructure.com/"));
       assertTrue(urlChecker.isValid("http://classes.engr.oregonstate.edu"));
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   
}
