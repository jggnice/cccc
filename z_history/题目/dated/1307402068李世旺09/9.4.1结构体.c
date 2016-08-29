#include"stdio.h"
struct complex
{double m_r;double m_i;};


main()
{struct complex c1={1.2,2.3},c2={0.2,0.3};
struct complex c;
c.m_r=c1.m_r+c2.m_r;
c.m_i=c1.m_i+c2.m_i;
printf("c=%g+i%g\n",c.m_r,c.m_i);
}