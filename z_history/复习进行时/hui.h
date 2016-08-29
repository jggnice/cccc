int hui(int z)
{int p,y=0,x1,i=0,c;

x1=z;

	while(x1>0)
	{y=y*10+x1%10;x1/=10;}

	
	if(y==z)p=1;else p=0;
	return p;
		
     
}
