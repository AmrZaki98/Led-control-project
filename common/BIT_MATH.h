#ifndef BIT_MATH_H
#define BIT_MATH_H
#define SET_BIT(REG,n)					     (REG|=(1<<n))
#define CLR_BIT(REG,n)					    (REG=REG&(~(1<<n)))
#define GET_BIT(REG,n)							((REG>>n)&1)
#define TOGGLE_BIT(REG,n)						(REG^=(1<<n))
#endif
