/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2011 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License Version 3.0 (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.systemc.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/* ---------------------------------------------------------------------------------------
 @file tlm_version.h

 @brief TLM version header

  Original Author:
    Charles Wilson, XtremeEDA Corporation

 @description
  This header contains preprocessor and compiler symbols to allow for the determination
   of the TLM version information. This conforms to IEEE 1666-2005 section 8.5.5 - 8.5.7
   .
   The following are provided:
   .
   preprocessor: TLM_VERSION_MAJOR        numeric
                 TLM_VERSION_MINOR        numeric
                 TLM_VERSION_PATCH        numeric
                 TLM_VERSION_ORIGINATOR   string       ([A-Z][a-z][0-9]_)
                 TLM_VERSION_RELEASE_DATE ISO8601 date (YYYYMMDD)
                 TLM_VERSION_PRERELEASE   string       ([A-Z][a-z][0-9]_)
                 TLM_IS_PRERELEASE        bool         (1,0)
                 TLM_VERSION              string       {2.0.0_DR3-TLMWG}
                 TLM_COPYRIGHT            string
   .
   compiler:     tlm_version_major        const unsigned int
                 tlm_version_minor        const unsigned int
                 tlm_version_patch        const unsigned int
                 tlm_version_originator   const std::string
                 tlm_version_release_date const std::string
                 tlm_version_prerelease   const std::string
                 tlm_is_prerelease        const bool
                 tlm_version              const string
                 tlm_copyright            const string
   .
   accessors:    inline const char* tlm_release   (void)
                 inline const char* tlm_version   (void)
                 inline const char* tlm_copyright (void)

--------------------------------------------------------------------------------------- */

#ifndef __TLM_VERSION_H__
#define __TLM_VERSION_H__

namespace tlm
{

#define TLM_VERSION_MAJOR                   2           ///< version major level ( numeric )
#define TLM_VERSION_MINOR                   0           ///< version minor level ( numeric )
#define TLM_VERSION_PATCH                   2           ///< version patch level ( numeric )
#define TLM_VERSION_ORIGINATOR              "ACCELLERA" ///< TLM creator string
#define TLM_VERSION_SEPARATOR               "."         ///< version string separator

#define TLM_IS_PRERELEASE                   1           ///< pre-release flag ( 1 / 0 )
#define TLM_VERSION_PRERELEASE              "ALPHA"     ///< pre-release version string

#define TLM_VERSION_RELEASE_YEAR            "2012"      ///< release year  ( YYYY )
#define TLM_VERSION_RELEASE_MONTH           "05"        ///< release month ( MM )
#define TLM_VERSION_RELEASE_DAY             "11"        ///< release day   ( DD )

#define TLM_COPYRIGHT                       "        Copyright (c) 1996-" TLM_VERSION_RELEASE_YEAR " by all Contributors\n" \
                                            "                    ALL RIGHTS RESERVED"

/************************** do not modify below this line *******************************/

/******************************* preprocessor symbols ***********************************/

#define TLM_VERSION_RELEASE_DATE            TLM_VERSION_RELEASE_YEAR \
                                            TLM_VERSION_RELEASE_MONTH \
                                            TLM_VERSION_RELEASE_DAY

#define TLM_VERSION_STR(x)                  TLM_VERSION_STR_HELPER(x)
#define TLM_VERSION_STR_HELPER(x)           #x

#define TLM_VERSION_STRING_MAJOR            TLM_VERSION_STR(TLM_VERSION_MAJOR)
#define TLM_VERSION_STRING_MINOR            TLM_VERSION_STR(TLM_VERSION_MINOR)
#define TLM_VERSION_STRING_PATCH            TLM_VERSION_STR(TLM_VERSION_PATCH)

#define TLM_VERSION_STRING_MMP              TLM_VERSION_STRING_MAJOR TLM_VERSION_SEPARATOR \
                                            TLM_VERSION_STRING_MINOR TLM_VERSION_SEPARATOR \
                                            TLM_VERSION_STRING_PATCH

#define TLM_VERSION_STRING_PRE_START        "_"
#define TLM_VERSION_STRING_PRE_END          "-"

#if ( TLM_IS_PRERELEASE == 1 )

#define TLM_VERSION_STRING_PRERELEASE       TLM_VERSION_PRERELEASE
#define TLM_VERSION_STRING_RELEASE_DATE     ""

#else   /* TLM_IS_PRERELEASE == 1 */

#define TLM_VERSION_STRING_PRERELEASE       ""
#define TLM_VERSION_STRING_RELEASE_DATE     TLM_VERSION_RELEASE_DATE

#endif  /* TLM_IS_PRERELEASE == 1 */

#define TLM_VERSION_STRING                  TLM_VERSION_STRING_MMP \
                                            TLM_VERSION_STRING_PRE_START \
                                            TLM_VERSION_STRING_PRERELEASE \
                                            TLM_VERSION_STRING_PRE_END \
                                            TLM_VERSION_ORIGINATOR

#define TLM_VERSION_STRING_2                "             TLM " \
                                            TLM_VERSION_STRING_MMP \
                                            " --- " \
                                            TLM_VERSION_RELEASE_YEAR \
                                            "-" \
                                            TLM_VERSION_RELEASE_MONTH \
                                            "-" \
                                            TLM_VERSION_RELEASE_DAY

#define TLM_VERSION                         TLM_VERSION_STRING

/********************************* compiler symbols **************************************/

const unsigned int tlm_version_major        ( TLM_VERSION_MAJOR               );
const unsigned int tlm_version_minor        ( TLM_VERSION_MINOR               );
const unsigned int tlm_version_patch        ( TLM_VERSION_PATCH               );

const bool         tlm_is_prerelease(TLM_IS_PRERELEASE);
const std::string  tlm_version_string       ( TLM_VERSION_STRING              );
const std::string  tlm_version_originator   ( TLM_VERSION_ORIGINATOR          );
const std::string  tlm_version_prerelease   ( TLM_VERSION_PRERELEASE          );
const std::string  tlm_version_release_date ( TLM_VERSION_STRING_RELEASE_DATE );
const std::string  tlm_copyright_string     ( TLM_COPYRIGHT                   );
const std::string  tlm_version_string_2     ( TLM_VERSION_STRING_2            );

inline const char*
tlm_release
( void
)
{
  return tlm_version_string.c_str ();
}

inline const char*
tlm_version
( void
)
{
  return tlm_version_string_2.c_str ();
}

inline const char*
tlm_copyright
( void
)
{
  return tlm_copyright_string.c_str ();
}

} // namespace tlm

#endif /* __TLM_VERSION_H__ */
