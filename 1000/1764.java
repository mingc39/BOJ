import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		int n, m;
		String str;
		HashSet<String> set = new HashSet<>();
		List<String> list = new ArrayList<>();
		Scanner scan = new Scanner(System.in);
		str = scan.nextLine();
		n = Integer.parseInt(str.split(" ")[0]);
		m = Integer.parseInt(str.split(" ")[1]);
		
		for(int i = 0; i < n; i++) {
			str = scan.nextLine();
			set.add(str);
		}
		
		for(int i = 0; i < m; i++) {
			str = scan.nextLine();
			if(set.contains(str) == true) list.add(str);
		}
		
		System.out.println(list.size());
		
		Collections.sort(list);
		for(String s : list) System.out.println(s);

	}

}
