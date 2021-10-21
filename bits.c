/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // x&y取到x和y同为1的位,取反得到x和y不同为1的位
  // ~x&~y取到x和y同为0的位,取反得到x和y不同为0的位
  return ~(~x&~y)&~(x&y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(int x) {
  // 移位即可得
  return 0x1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // 2*Tmax+1为0xffffffff, 取反得0x00000000
  // 因为-1也满足,增加!(~x)用于区别
  return !(~(x+x+1)+(!(~x)));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // hex(a) = bin(1010),一个二进制数的所有奇数位都是1
  // 则其掩码是bin(10101010101010101010101010101010)
  // x&mask要等于mask, mask^mask=0
  int mask = 0xaa + (0xaa<<8) + (0xaa<<16) + (0xaa<<24);
  return !((x&mask)^mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  // -x = ~x + 1
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // 对任意属于0x30到0x39之间的数,均满足:
  // a, 0x39 - x >= 0
  // b, x - 0x30 >= 0
  int r1 = (0x39 + ~x +1) >> 31;
  int r2 = (x + ~(0x30) + 1) >> 31;
  return !(r1|r2);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // x是一个数,需要转换为布尔值,取逆和自身分别是!x和!(!x)
  // 0x1取反加1得到-1(0xffffffff),
  // 0x0取反加1还是0(0没有正负),可以用来做掩码
  int de_bool_x = !x;
  int bool_x = !(!(x));
  int mask_y = (~bool_x+1);
  int mask_z = (~de_bool_x+1);
  return (y&mask_y) + (z&mask_z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) { 
  // 判断符号是否相同,相同取差值; 
  // 不相同直接看x的符号就可以
  int outcome = y + ~x + 1;
  int shift = outcome >> 31;
  int shift_sign = shift & 0x1;
  int x_sign = (x >> 31) & 0x1;
  int y_sign = (y >> 31) & 0x1;
  int bit_xor = x_sign ^ y_sign;

  return ((!bit_xor)&(!shift_sign))|(bit_xor&x_sign);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // 获取x的符号,获取-x的符号
  // 只有x为0的时候,sign和neg_sigh都是0
  int sign = (x>>31) & 0x1;
  int neg_value = (~x + 1);
  int neg_sign = (neg_value >> 31) & 0x1;

  return (sign^0x1)&(neg_sign^0x1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // 需要先将x统一转换为非负数:
  // a, x是非负数时,返回值需要是能够表示x的最小位数加上1,因为需要左边一个0来保证不是负数
  // b, x是负数时,从左向右找到第一个为0的位,左边需要保留一个1,其余可忽略,这样的话,取反即可,当成非负数处理
  // 当x是负数时,算术右移31位得到掩码0xffffffff
  // 当x是非负数时,~mask为0xffffffff
  int b16, b8, b4, b2, b1, b0;
  int mask = x >> 31;
  x = (mask&~x)|(~mask&x);    // x转换成非负数

  b16 = !!(x>>16)<<4;         // 先确认前16位是否有数字,!!(x>>16)得到,有则b16为16,没有则是0
  x = x >> b16;               // 根据b16的值移位x,省略后16位,交给下一步处理

  b8 = !!(x>>8)<<3;           // 同b16
  x = x >> b8;

  b4 = !!(x>>4)<<2;           // 同b16
  x = x >> b4;

  b2 = !!(x>>2)<<1;           // 同b16
  x = x >> b2;

  b1 = !!(x>>1);
  x = x >> b1;

  b0 = x;

  return b16 + b8 + b4 + b2 + b1 + b0 + 1;  // 需要+1
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // 三段组合
  // 先区分exp为0和255的情况,直接返回
  // 当exp+1为255时,只需要判断frac是否都是0
  unsigned s = uf & 0x80000000;
  unsigned exp = (uf >> 23) & 0xff;
  
  if (exp==0xff) {
    return uf;
  } 
  else if (exp==0x0) {
    return s|((uf&0x7fffffff)<<1);
  }
  else if (((exp+1)==0xff) && ((uf&0x7fffff) == 0x0)) {
    return s|0x7f800000;
  }

  return s|((exp+1)<<23)|(uf&0x7fffff);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  // shifted_frac是规格化值的二进制表示
  // exp和frac都为0或者E小于0时,int无法表示,直接返回0x0
  // E大于31时,int同样无法表示,返回0x80000000u
  // 符号为负时,返回浮点数二进制表示值*(-1)
  // 符号为正时,返回浮点数二进制表示值,直接移位即可
  unsigned s = uf & 0x80000000;
  unsigned exp = (uf>>23) & 0xff;
  unsigned frac = uf & 0x7fffff;
  unsigned shifted_frac = (0x800000 + frac)>>23;
  int E = exp - 127;

  if ((exp == 0x0 && frac == 0x0) || E < 0x0) {
    return 0x0;
  }
  else if (E > 0x1f) {
    return 0x80000000u;
  }
  else if (s & 0x80000000) {
    return ~(shifted_frac << E) + 1;
  }
  else {
    return shifted_frac << E;
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // 最大可表示exp为ffffffff,exp为255,E为127
  // 最小可表示exp为00000000,exp为0,E为-126,最小值为-126-23
  // 小于V_MIN返回0,大于V_MAX,返回正无穷(0x7f800000)
  // 介于V_MIN和E_MIN之间,exp为0,只需要考虑frac部分
  // 在规格化范围内,直接返回即可
  int E_MIN = -126;    // 1 - 127
  int V_MIN = -149;    // -126 -23
  int V_MAX = 127;     // -126
   
  if (x<V_MIN) {
    return 0;
  }
  else if (x<E_MIN && x>=V_MIN) {
    return 0x00000000|(1<<(23-(-x+E_MIN)));
  }
  else if (x>V_MAX) {
    return 0x7f800000;
  }

  return 0x00000000|((x+127)<<23);
}
