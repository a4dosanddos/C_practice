public class Sample {
  private native String sample(String src);

  public static void main(String[] args) {
    System.loadLibrary("Sample");
    Sample sample = new Sample();
    String result = sample.sample("Hello");
  }
}
