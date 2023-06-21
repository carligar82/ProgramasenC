/**
 * Escribe los números primos (sólo divisibles por 1 y por si mismos) hasta donde tu quieras
 * @date 07-12-2021
 * @author Carlos Limeres
 * */
package demo;

import java.util.Scanner;

public class DemoTranslation {
	public static boolean primo(int a) {
		for(int b = 2; b <= a - 1; b++) {
			if(a % b == 0) {
				return false;
			}
		}
		return true;
	}

	public static void main() {
		int c = 0, d, x = 1;
		while(x != 0) {
			System.out.print("Limite: ");
			x = STDIN_SCANNER.nextInt();
			if(x != 0) {
				for(int a = 1; a <= x; a++) {
					if(primo(a)) {
						System.out.println(a);
						c = c + 1;
					}
					if(c == 16 && a != x) {
						System.out.print("Mas ? ");
						d = STDIN_SCANNER.nextInt();
						if(d == 0) {
							a = x + 1;
						} else {
							c = 0;
						}
					}
				}
			}
		}
	}

	public final static Scanner STDIN_SCANNER = new Scanner(System.in);
}