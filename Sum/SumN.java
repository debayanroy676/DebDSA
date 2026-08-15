import java.io.InputStream;
import java.io.PrintStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
public class SumN {
	private InputStream in;
	private PrintStream out;
	private InputStreamReader isr;
	private BufferedReader br;
	private int N;
	private int[] num1, num2, added_val;
	public SumN() throws IOException {
		this.in = System.in;
		this.out = System.out;
		this.isr = new InputStreamReader(this.in);
		this.br = new BufferedReader(this.isr);
	}
	public void set() throws IOException {
		out.print("Enter the length of your number : ");
		this.N = Integer.parseInt(br.readLine());
		out.println("Enter the 1st number in individual digits :");
		this.num1 = new int[this.N+1];
		this.num1 = set_digit(this.num1);
		out.println("Enter the 2nd number in individual digits :");
		this.num2 = new int[this.N+1];
		this.num2 = set_digit(this.num2);
		this.added_val = new int[this.N+1];
		add();
	}
	private int[] set_digit(int[] arr) throws IOException {
		for(int i=1; i<=N; i++) {
			out.printf("Digit 10^%d >>> ",(N-i));
			arr[i] = Integer.parseInt(br.readLine());
			if(arr[i]>=0 && arr[i]<=9) continue;
			else throw new RuntimeException("Digit should be in the range [0, 9]");
		}
		return arr;
	}
	private void add() {
		int base, i, carry=0;
		for(i=0; i<=this.N; i++)
			this.added_val[i] = this.num1[i] + this.num2[i];
		for(i=this.N; i>=0; i--){
			this.added_val[i] = this.added_val[i] + carry;
			base = this.added_val[i]%10;
			carry = this.added_val[i]/10;
			this.added_val[i] = base;
		}
	}
	private String toStr(int[] arr) {
		String arr_str = "";
		for(int i:arr)
			arr_str = arr_str + i;
		return arr_str;
	}
	public void display() {
		out.printf("%s + %s = %s",toStr(num1), toStr(num2), toStr(added_val));
	}
	public static void main(String[] args) throws IOException {
		SumN obj = new SumN();
		obj.set();
		obj.display();
	}
}
