public class ArrayCopy {
	public static void main(String agrs[]) {
		int s1[] = { 1, 3, 5, 7, 9 };
		int s2[] = { 2, 4, 6, 8, 10 };
		System.arraycopy(s1, 1, s2, 2, 3); /*
											 * java�е����鸴�����ģ�� ���в����ĺ���ֱ��ǣ�
											 * Դ�������ơ�Դ���鿪ʼ�㡣Ŀ���������ƣ�Ŀ�����鿪ʼ�㡣���Ƴ���
											 */
		for (int i = 0; i < s2.length; i++)
			System.out.print(s2[i] + "��");
		return;
	}
}