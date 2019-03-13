import junit.framework.TestCase;
import java.util.Random;
import java.lang.Math;
import java.nio.charset.Charset;

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

   // scheme partition (e.g. https)
   public void testYourFirstPartition() {
       UrlValidator urlChecker = new UrlValidator();
       Random random = new Random();
       int limitLeft = (int) 'a';
       int limitRight = (int) 'z';
       int stringLength = 10;
       int stringNum = 100;

       for (int i = 0; i < stringNum; i++) {
           StringBuilder buffer = new StringBuilder(stringLength);
           for (int n = 0; n < stringLength; n++) {
               int rand = limitLeft + (int) (random.nextFloat() * (limitRight - limitLeft + 1));
               buffer.append((char) rand);
           }
           String finalString = buffer.toString();
           System.out.println(finalString);
       }
   }

   // authority partition (e.g. 192.168.107.123)
   public void testYourSecondPartition() {

   }

   // port partition (e.g. 443)
   public void testYourThirdPartition() {
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
               // TODO use of assert halts the program
               assertTrue(urlValidator.isValid(VALID_URL + ":" + rand));
           }

           // invalid port
           else {
               assertFalse(urlValidator.isValid(VALID_URL + ":" + rand));
           }
       }
   }


   // path partition (e.g. /cool/new/book.html)
   public void testYourFourthPartition() {

   }

   // queries partition (e.g. ?chapter=1)
   public void testYourFifthPartition() {

   }

   public void testIsValid() {

   }
}
