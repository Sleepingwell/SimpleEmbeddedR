import embedr.SimpleEmbeddedR;



public class Tests {

	static {
		try {
    		System.loadLibrary("SimpleEmbeddedR");
		} catch (java.lang.SecurityException e) {
			System.out.println("Not allowed to load dynamic library SimpleEmbeddedR.");
			throw e;
    	} catch (java.lang.UnsatisfiedLinkError e) {
    		System.out.println("Failed to load dynamic library SimpleEmbeddedR.");
    		throw e;
    	}
	}
	
	public static void main(String args[]) {
		String res;
		try {
			res = SimpleEmbeddedR.runRCode("x <- rnorm(1000);paste(\"mean of x:\", mean(x))");
			System.out.println(res);
			res = SimpleEmbeddedR.runRCode("png('d:/temp/test.png');plot(1:10);dev.off()");
			System.out.println(res);
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
}
