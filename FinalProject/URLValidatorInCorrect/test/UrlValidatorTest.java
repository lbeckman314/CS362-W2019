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
	
	// Random Testing

	private int stdTests = 100;

	// tests scheme partition (e.g. https) 
	// valid characters: [a-zA-Z0-9\-\+]
	// invalid characters: all other characters.
	// https://www.iana.org/assignments/uri-schemes/uri-schemes.xhtml
	// https://tools.ietf.org/html/rfc7595
	public void testYourFirstPartition()
	{
		UrlValidator urlValidator = new UrlValidator();
		String VALID_URL = "www.test.org";
		//assertTrue(urlValidator.isValid(VALID_URL));

		for (int i = 0; i < stdTests; i++) {
			String scheme = genScheme();
			System.out.println("scheme: " + scheme);
			String TEST_URL = scheme + "://" + VALID_URL;
			System.out.println("TEST_URL: " + TEST_URL);

			// assert false for all invalid schemes
			if (scheme.length() == 0) {
				assertFalse(urlValidator.isValid(TEST_URL));
			}

			if (scheme.contains(" ") || scheme.contains("/") || scheme.contains(":")) {
				assertFalse(urlValidator.isValid(TEST_URL));
			}

			// assert true for all valid schemes
			else {
				assertTrue(urlValidator.isValid(TEST_URL));
			}
		}
	}

	// tests authority partition (e.g. 192.168.107.123)
	public void testYourSecondPartition(){
		UrlValidator urlChecker = new UrlValidator();
		String VALID_URL = "https://";

		for (int i = 0; i < stdTests; i++) {
			String auth = genAuth();
			System.out.println("auth: " + auth);
			String TEST_URL = VALID_URL + auth;
			System.out.println("TEST_URL: " + TEST_URL);

			// assert false for all invalid authorities
			if (auth.length() == 0) {
				assertFalse(urlChecker.isValid(TEST_URL));
			}

			// assert true for all valid authorities
			else {
				assertTrue(urlChecker.isValid(TEST_URL));
			}
		}
	}


	// tests port partition (e.g. 443) 
	public void testYourThirdPartition(){
		String VALID_URL = "https://www.test.com";
		UrlValidator urlValidator = new UrlValidator();
		//assertTrue(urlValidator.isValid(VALID_URL));

		for (int i = 0; i < stdTests; i++) {
			int rand = genPort();
			System.out.println("port: " + rand);
			String TEST_URL = VALID_URL + ":" + rand;
			System.out.println("TEST_URL: " + TEST_URL);

			// limit valid ports from 0 to 65536 exclusive (2^16)
			if (rand >= 0 && rand < (int)(Math.pow(2, 16))) {
				System.out.println(TEST_URL);
				assertTrue(urlValidator.isValid(TEST_URL));
			}

			// invalid port
			else {
				assertFalse(urlValidator.isValid(TEST_URL));
			}
		}
	}


	// tests path partition (e.g. /cool/new/book.html)
	// source: https://tools.ietf.org/html/rfc1738
	public void testYourFourthPartition() {
		UrlValidator urlValidator = new UrlValidator();
		String VALID_URL = "https://www.test.org";
		//assertTrue(urlValidator.isValid(VALID_URL));

		for (int i = 0; i < stdTests; i++) {
			String path = genPath();
			System.out.println("path: " + path);
			String TEST_URL = VALID_URL + path;
			System.out.println("TEST_URL: " + TEST_URL);

			// assert true for all empty paths
			if (path.length() == 0) {
				assertTrue(urlValidator.isValid(TEST_URL));
			}

			// assert true for all other paths
			else {
				assertTrue(urlValidator.isValid(TEST_URL));
			}
		}
	}

	
	// tests queries partition (e.g. ?chapter=1)
	public void testYourFifthPartition() {
		UrlValidator urlValidator = new UrlValidator();
		String VALID_URL = "https://www.test.org";
		//assertTrue(urlValidator.isValid(VALID_URL));

		for (int i = 0; i < stdTests; i++) {
			String queries = genQueries();
			System.out.println("queries: " + queries);
			String TEST_URL = VALID_URL + "/" + queries;
			System.out.println("TEST_URL: " + TEST_URL);

			// assert true for all empty queries
			if (queries.length() == 0) {
				assertTrue(urlValidator.isValid(TEST_URL));
			}

			// assert true for all other queries
			else {
				System.out.println(VALID_URL + "/" + queries);
				assertTrue(urlValidator.isValid(TEST_URL));
			}
		}
	}


	// Random Generators
	
	// minimum length of random strings
	private int stdMin = 0;
	
	// maximum length of random strings
	private int stdMax = 10;

	// generates a randomized scheme
	private String genScheme() {
		Random random = new Random(); 	
		int stringLenMin = stdMin;
		int stringLenMax = stdMax;

		Vector<Integer> chars = genChar(2);

		int limitLeft = stdMin;
		int limitRight = chars.size() - 1;

		int randLen = stringLenMin + (int) (random.nextFloat() * (stringLenMax - stringLenMin + 1));
		StringBuilder buffer = new StringBuilder(randLen);
		for (int n = 0; n < randLen; n++) {
			int rand = limitLeft + (int) (random.nextFloat() * (limitRight - limitLeft + 1));
			char randChar = (char)(int)(chars.get(rand));
			buffer.append(randChar);
		}
		String scheme = buffer.toString();
		return scheme;
	}


	// generates a randomized authority
	private String genAuth() {
		// human readable hosts
		// subdomain
		int subLenMin = 3;
		int subLenMax = 3;
		int subNum = randomInRange(subLenMin, subLenMax);

		// domain
		int domainLenMin = stdMin;
		int domainLenMax = stdMax;
		int domainNum = randomInRange(domainLenMin, domainLenMax);

		// tld
		int tldLenMin = 3;
		int tldLenMax = 3;
		int tldNum = randomInRange(tldLenMin, tldLenMax);

		String auth = "";

		Vector<Integer> chars = genChar(0);

		for (int i = 0; i < subNum; i++) {
			auth += (char)(int) chars.get(randomInRange(0, chars.size()-1));
		}

		auth += ".";

		for (int i = 0; i < domainNum; i++) {
			auth += (char)(int) chars.get(randomInRange(0, chars.size()-1));
		}

		auth += ".";

		for (int i = 0; i < tldNum; i++) {
			auth += (char)(int) chars.get(randomInRange(0, chars.size()-1));
		}

		return auth;
	}


	// generates a randomized port number
	private int genPort() {
		// Generate random integers in range (-2 * 65536 - 1) to (2 * 65536 - 1)
		// This should result in one quarter of the resulting values being
		// valid port numbers (0 to 65536 exclusive).
		int leftLimit = (int) (-2 * Math.pow(2,16) - 1);
		int rightLimit = (int) (2 * Math.pow(2,16) - 1);
		int rand = leftLimit + (int) (new Random().nextFloat() * (rightLimit - leftLimit));

		return rand;
	}


	// generates a randomized path
	private String genPath() {
		Random random = new Random(); 	

		// number of directories and subdirectories
		int dirNumMin = stdMin;
		int dirNumMax = stdMax;
		int dirNumRand = randomInRange(dirNumMin, dirNumMax);

		// number of characters in each file
		int fileLenMin = stdMin;
		int fileLenMax = stdMax;
		int fileLenRand = randomInRange(fileLenMin, fileLenMax);

		// filetype extension (e.g. html)
		int filetypeLenMin = stdMin;
		int filetypeLenMax = stdMax;
		int filetypeLenRand = randomInRange(fileLenMin, fileLenMax);

		String path = "";

		Vector<Integer> chars = genChar(0);

		int limitLeft = stdMin;
		int limitRight = chars.size() - 1;

		// number of directories
		for (int i = 0; i < dirNumRand; i++) {
			path += "/";

			// number of characters in each directory
			int dirLenMin = stdMin;
			int dirLenMax = stdMax;
			int dirLenRand = dirLenMin + (int) (random.nextFloat() * (dirLenMax - dirLenMin + 1));

			// length of each of the directories
			for (int n = 0; n < dirLenRand; n++) {
				path += (char)(int) chars.get(randomInRange(0, chars.size() - 1));
			}
		}

		path += "/";

		// add filename to path
		for (int k = 0; k < fileLenRand; k++) {
			path += (char)(int) chars.get(randomInRange(0, chars.size() - 1));
		}

		path += ".";

		// add filetype/extensions to path
		for (int k = 0; k < filetypeLenRand; k++) {
			path += (char)(int) chars.get(randomInRange(0, chars.size() - 1));
		}

		return path;
	}


	// generates a randomized query
	private String genQueries() {
		int queriesMin = stdMin;
		int queriesMax = stdMax / 2;
		int queriesNum = randomInRange(queriesMin, queriesMax);

		String queries = "";
		Vector<Integer> chars = genChar(0);

		for (int i = 0; i < queriesNum; i++) {

			int queriesLenMin = stdMin;
			int queriesLenMax = stdMax;
			int queriesLenNum = randomInRange(queriesLenMin, queriesLenMax);
			queries += "?";

			for (int n = 0; n < queriesLenNum; n++) {
				queries += (char) (int) chars.get(randomInRange(0, chars.size() - 1));
			}

			int queriesValueMin = stdMin;
			int queriesValueMax = stdMax;
			int queriesValueNum = randomInRange(queriesValueMin, queriesValueMax);
			queries += "=";
			for (int n = 0; n < queriesValueNum; n++) {
				queries += (char) (int) chars.get(randomInRange(0, chars.size() - 1));
			}
		}

		return queries;
	}


	// returns a random integer within the range of min to max inclusive
	private int randomInRange(int min, int max) {
		Random random = new Random(); 	
		int rand = min + (int) (random.nextFloat() * (max - min + 1));
		return rand;
	}


	// returns a vector of characters
	// charType 0: only add alphanumeric characters to the final vector.
	// charType 1: add the above along with other URI-valid characters (e.g. '-' and '+').
	// charType 2: add the above along with URI-invalid characters (e.g. ' ', '/', and ':').
	private Vector<Integer> genChar(int charType) {
		Vector<Integer> chars = new Vector<Integer>();

		if (charType >= 0) {
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
		}

		if (charType >= 1) {
			chars.add((int) '-');
			chars.add((int) '+');
		}

		if (charType >= 2) {
			// add some invalid characters
			chars.add((int) ' ');
			chars.add((int) '/');
			chars.add((int) ':');
		}

		return chars;
	}


	// generate a complete URL using all random generator functions.
	public void genUrl() {
		String url = genScheme() + genAuth() + genPort() + genPath() + genQueries();
		//System.out.println("URL: " + url);
	}


	public void testIsValid() {
		//String url = genScheme() + "://" + genAuth() + ":" + genPort() + genPath() + genQueries();
		//System.out.println("URL: " + url);
	}
}
