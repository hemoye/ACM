public class ArrayCopy {
	public static void main(String agrs[]) {
		int s1[] = { 1, 3, 5, 7, 9 };
		int s2[] = { 2, 4, 6, 8, 10 };
		System.arraycopy(s1, 1, s2, 2, 3); /*
											 * java中的数组复制类库模版 其中参数的含义分别是：
											 * 源数组名称。源数组开始点。目标数组名称，目标数组开始点。复制长度
											 */
		for (int i = 0; i < s2.length; i++)
			System.out.print(s2[i] + "、");
		return;
	}
}