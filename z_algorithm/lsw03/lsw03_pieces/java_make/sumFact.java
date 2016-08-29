import java.math.*;

public final class sumFact
{
	public static void main(String[] args)
	{
		BigDecimal sums=BigDecimal.ONE;
		for(int i=1;i<=100;i++)
			sums=sums.add(Lfact(i));			
		System.out.println("the sum of 1!  to 100!  is \n"+sums);
		
		BigDecimal sums1=BigDecimal.ONE;
		BigDecimal a=new BigDecimal(1.0);
		for(int i=0;i<=68;i++)
			sums1=sums1.add(a.divide(Lfact(i),103,BigDecimal.ROUND_HALF_UP));
		System.out.println("the sum of 1/(0!)  to 1/(70!)  is \n"+sums1.setScale(99,BigDecimal.ROUND_HALF_UP));
		
	}
	public static BigDecimal Lfact(int n)
	{
		BigDecimal result=BigDecimal.ONE;
		for(int i=1;i<=n;i++)
			result=result.multiply(new BigDecimal(i+""));
		return result;
	}
}