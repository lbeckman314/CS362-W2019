import junit.framework.TestCase;
import java.util.Random;
import java.util.Vector;
import java.lang.Math;
import java.nio.charset.Charset; 


//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {

	public UrlValidatorTest(String testName) {
		super(testName);
	}

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
  
	// scheme partition (e.g. https) 
	// valid characters: [a-zA-Z0-9\-\+]
	// invalid characters: all other characters.
	// https://www.iana.org/assignments/uri-schemes/uri-schemes.xhtml
	// https://tools.ietf.org/html/rfc7595
	public void testYourFirstPartition()
	{
		UrlValidator urlChecker = new UrlValidator();
		String VALID_URL = "coolsite.org";
        Random random = new Random(); 	
        int stringLengthMin = 0;
        int stringLengthMax = 10;
        int stringNum = 100;
        
        Vector chars = new Vector();

        // add all valid characters
        for (int i = (int) 'a'; i < (int) 'z'; i++) {
        	chars.add(i);
        }
        for (int i = (int) 'A'; i < (int) 'Z'; i++) {
        	chars.add(i);
        }
        for (int i = (int) '0'; i < (int) '9'; i++) {
        	chars.add(i);
        }
        chars.add((int) '-');
        chars.add((int) '+');

        // add some invalid characters
        chars.add((int) ' ');
        chars.add((int) '/');
        chars.add((int) ':');

        int limitLeft = 0;
        int limitRight = chars.size() - 1;

        for (int i = 0; i < stringNum; i++) {
        	int randLength = stringLengthMin + (int) (random.nextFloat() * (stringLengthMax - stringLengthMin + 1));
        	StringBuilder buffer = new StringBuilder(randLength);
        	for (int n = 0; n < randLength; n++) {
        		int rand = limitLeft + (int) (random.nextFloat() * (limitRight - limitLeft + 1));
        		char randChar = (char)(int)(chars.get(rand));
        		//System.out.println(chars.get(rand));
        		//System.out.println("test:" + test);
        		buffer.append(randChar);
        	}
        	String scheme = buffer.toString();
        	System.out.println("scheme:" + scheme);

        	// assert false for all invalid schemes
        	if (scheme.length() == 0) {
				assertFalse(urlChecker.isValid(scheme + "://" + VALID_URL));
        	}
        	if (scheme.contains(" ") || scheme.contains("/") || scheme.contains(":")) {
				assertFalse(urlChecker.isValid(scheme + "://" + VALID_URL));
        	}

        	// assert true for all valid schemes
        	else {
				assertTrue(urlChecker.isValid(scheme + "://" + VALID_URL));
        	}
        	
        }
	}

	// authority partition (e.g. 192.168.107.123) 
	public void testYourSecondPartition(){

	}

	// port partition (e.g. 443) 
	public void testYourThirdPartition(){
		// number of random tests to run
		int RANDOM_TESTS = 100;
		String VALID_URL = "https://coolsite.org";
		UrlValidator urlValidator = new UrlValidator();

		// limit valid ports from 0 to 65536 exclusive (2^16)
        for (int i = 1; i < RANDOM_TESTS; i++) {
        	
        	// Generate random integers in range (-2 * 65536 - 1) to (2 * 65536 - 1)
        	// This should result in one quarter of the resulting values being
        	// valid port numbers (0 to 65536 exclusive).
        	int leftLimit = (int) (-2 * Math.pow(2,16) - 1);
        	int rightLimit = (int) (2 * Math.pow(2,16) - 1);
        	int rand = leftLimit + (int) (new Random().nextFloat() * (rightLimit - leftLimit));

        	// valid port
        	if (rand >= 0 && rand < (int)(Math.pow(2, 16))) {
				System.out.println(VALID_URL + ":" + rand); 
				assertTrue(urlValidator.isValid(VALID_URL + ":" + rand));
        	}
        	
        	// invalid port
        	else {
				assertFalse(urlValidator.isValid(VALID_URL + ":" + rand));
        	}
        }
	}
	
	// path partition (e.g. /cool/new/book.html)
	public void testYourFourthPartition(){

	}

	// queries partition (e.g. ?chapter=1)
	public void testYourFifthPartition(){

	}

   public void testIsValid() {

   }
}
