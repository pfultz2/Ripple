/* 
 * File:   config.h
 * Author: pfultz
 *
 * Created on January 17, 2012, 1:02 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef _MSC_VER
#define PX_CONFIG_MSVC
#endif

#if defined(__GNUC__) || defined(__clang__)
#define PX_CONFIG_STD
#endif

#endif	/* CONFIG_H */

