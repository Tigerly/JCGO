/*
 * @(#) $(JCGO)/include/jcgoarth.c --
 * a part of the JCGO runtime subsystem.
 **
 * Project: JCGO (http://www.ivmaisoft.com/jcgo/)
 * Copyright (C) 2001-2012 Ivan Maidanski <ivmai@ivmaisoft.com>
 * All rights reserved.
 */

/**
 * This file is compiled together with the files produced by the JCGO
 * translator (do not include and/or compile this file directly).
 */

/*
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 **
 * This software is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License (GPL) for more details.
 **
 * Linking this library statically or dynamically with other modules is
 * making a combined work based on this library. Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 **
 * As a special exception, the copyright holders of this library give you
 * permission to link this library with independent modules to produce an
 * executable, regardless of the license terms of these independent
 * modules, and to copy and distribute the resulting executable under
 * terms of your choice, provided that you also meet, for each linked
 * independent module, the terms and conditions of the license of that
 * module. An independent module is a module which is not derived from
 * or based on this library. If you modify this library, you may extend
 * this exception to your version of the library, but you are not
 * obligated to do so. If you do not wish to do so, delete this
 * exception statement from your version.
 */

#ifdef JCGO_VER

JCGO_NOSEP_INLINE jint JCGO_INLFRW_FASTCALL jcgo_div( jint v1, jint v2 )
{
 if (JCGO_EXPECT_FALSE(!v2))
  jcgo_throwArithmeticExc();
 if (JCGO_EXPECT_TRUE(v2 != -1))
  return v1 / v2;
 return -v1;
}

JCGO_NOSEP_INLINE jint JCGO_INLFRW_FASTCALL jcgo_mod( jint v1, jint v2 )
{
 if (JCGO_EXPECT_FALSE(!v2))
  jcgo_throwArithmeticExc();
 if (JCGO_EXPECT_TRUE(v2 != -1))
  return v1 % v2;
 return 0;
}

JCGO_NOSEP_INLINE jlong JCGO_INLFRW_FASTCALL jcgo_ldiv( jlong v1, jlong v2 )
{
 if (JCGO_EXPECT_FALSE(v2 == (jlong)0L))
  jcgo_throwArithmeticExc();
 if (JCGO_EXPECT_TRUE(v2 != (jlong)-1L))
  return v1 / v2;
 return -v1;
}

JCGO_NOSEP_INLINE jlong JCGO_INLFRW_FASTCALL jcgo_lmod( jlong v1, jlong v2 )
{
 if (JCGO_EXPECT_FALSE(v2 == (jlong)0L))
  jcgo_throwArithmeticExc();
 if (JCGO_EXPECT_TRUE(v2 != (jlong)-1L))
  return v1 % v2;
 return (jlong)0L;
}

#ifdef JCGO_USELONG

JCGO_NOSEP_INLINE jlong JCGO_INLFRW_FASTCALL jcgo_lshl( jlong v, int cnt )
{
 return JCGO_EXPECT_TRUE((unsigned)(cnt & 0x3f) < sizeof(jlong) * 8) ?
         v << (cnt & 0x3f) : (jlong)0L;
}

JCGO_NOSEP_INLINE jlong JCGO_INLFRW_FASTCALL jcgo_lshr( jlong v, int cnt )
{
 return JCGO_EXPECT_TRUE((unsigned)(cnt & 0x3f) < sizeof(jlong) * 8) ?
         v >> (cnt & 0x3f) : v < (jlong)0L ? (jlong)-1L : (jlong)0L;
}

JCGO_NOSEP_INLINE jlong JCGO_INLFRW_FASTCALL jcgo_lushr( jlong v, int cnt )
{
 return JCGO_EXPECT_TRUE((unsigned)(cnt & 0x3f) < sizeof(jlong) * 8) ?
         (jlong)(((u_jlong)v) >> (unsigned)(cnt & 0x3f)) : (jlong)0L;
}

#endif /* JCGO_USELONG */

#endif
