//package testr20;
// waiting run
import java.math.*;

public class Rational2 extends Number implements Comparable
{
	//Data field
	private BigInteger fenzi=BigInteger.ZERO;
	private BigInteger fenmu=BigInteger.ONE;
	//construct a rational
	public Rational2(BigInteger fenzi,BigInteger fenmu)
	{
		BigInteger gcd1=fenzi.gcd(fenmu);
		this.fenzi=((fenmu.compareTo(BigInteger.ZERO)>0)?BigInteger.ONE:new BigInteger("-1")).multiply(fenzi).divide(gcd1);
		this.fenmu=(fenmu).divide(gcd1);
		if(this.fenmu.compareTo(BigInteger.ZERO)<0)
			this.fenmu=this.fenmu.multiply(new BigInteger("-1"));
	}
	//BigInteger.gcd(other_one)
	public Rational2()
	{
		this(BigInteger.ZERO,BigInteger.ONE);
	}
	//get
	public BigInteger getFenzi(){return fenzi;}
	public BigInteger getFenmu(){return fenmu;}
	//RN_add
	public Rational2 RN_add(Rational2 r1)
	{
		BigInteger n=fenzi.multiply(r1.getFenmu()).add(fenmu.multiply(r1.getFenzi()));
		BigInteger d=fenmu.multiply(r1.getFenmu());
		return new Rational2(n,d);
	}
	//RN_mul
	public Rational2 RN_mul(Rational2 r1)
	{
		BigInteger n=fenzi.multiply(r1.getFenzi());
		BigInteger d=fenmu.multiply(r1.getFenmu());
		return new Rational2(n,d);
	}
	//RN_sub
	public Rational2 RN_sub(Rational2 r1)
	{
		BigInteger n=new BigInteger("-1").multiply(r1.getFenzi());
		BigInteger d=r1.getFenmu();
		Rational2 r0=new Rational2(n,d);
		return this.RN_add(r0);	
	}
	//RN_div
	public Rational2 RN_div(Rational2 r1)
	{
		BigInteger n=fenzi.multiply(r1.getFenmu());
		BigInteger d=fenmu.multiply(r1.getFenzi());
		return new Rational2(n,d);
	}
	//toString
	public String toString()
	{
		String str1=fenzi.toString();
		String str2=fenmu.toString();
		int str1length=30-str1.length();
		int str2length=30-str2.length();
		String str11="_";String str22="_";
		for(int ii=0;ii<str1length-1;ii++)
			str11=str11.concat("_");
		for(int jj=0;jj<str2length-1;jj++)
			str22=str22.concat("_");
		
		str11=str11.concat(str1).concat("/").concat(str2).concat(str22);
		return str11;
	}
	//equals method
	public boolean equals(Object o)
	{
		if(((this.RN_sub((Rational2)(o))).getFenzi()).compareTo(BigInteger.ZERO)==0)
			return true;
		else return false;
	}
 	//(datatype)Value
	public int intValue(){return (int)doubleValue();}
	public long longValue(){return (long)doubleValue();}
	public float floatValue(){return (float)doubleValue();}
	public double doubleValue(){return 1.0/4;} 
	//compareTo
	public int compareTo(Object o)
	{
		if(this.RN_sub((Rational2)(o)).getFenzi().compareTo(BigInteger.ZERO)>0)
			return 1;
		else if(this.RN_sub((Rational2)(o)).getFenzi().compareTo(BigInteger.ZERO)<0)
			return -1;
		else
			return 0;
	}
}