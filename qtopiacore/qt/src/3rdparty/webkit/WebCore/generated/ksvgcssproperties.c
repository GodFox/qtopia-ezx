/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: gperf -c -a -L ANSI-C -G -D -E -C -o -t --key-positions='*' -NfindSVGProp -Hhash_prop -Wwordlist_prop -D -s 3 ksvgcssproperties.gperf  */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "ksvgcssproperties.gperf"

/* This file is automatically generated from ksvgcssproperties.in by cssmakeprops, do not edit */
#include "ksvgcssproperties.h"
#line 5 "ksvgcssproperties.gperf"
struct css_prop {
    const char* name;
    int id;
};

static const struct css_prop *findSVGProp (register const char *str, register unsigned int len);
enum
  {
    PROP_TOTAL_KEYWORDS = 42,
    PROP_MIN_WORD_LENGTH = 4,
    PROP_MAX_WORD_LENGTH = 28,
    PROP_MIN_HASH_VALUE = 4,
    PROP_MAX_HASH_VALUE = 113
  };

/* maximum key range = 110, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash_prop (register const char *str, register unsigned int len)
{
  static const unsigned char asso_values[] =
    {
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114,   0, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114,   5,  15,   5,
        0,   0,   0,   0,  10,   0,  15,   0,   0,   0,
        5,  10,   0, 114,   0,   0,   0,  10,  30,  30,
       35,   0,   0, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
      114, 114, 114, 114, 114, 114
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[27]];
      /*FALLTHROUGH*/
      case 27:
        hval += asso_values[(unsigned char)str[26]];
      /*FALLTHROUGH*/
      case 26:
        hval += asso_values[(unsigned char)str[25]];
      /*FALLTHROUGH*/
      case 25:
        hval += asso_values[(unsigned char)str[24]];
      /*FALLTHROUGH*/
      case 24:
        hval += asso_values[(unsigned char)str[23]];
      /*FALLTHROUGH*/
      case 23:
        hval += asso_values[(unsigned char)str[22]];
      /*FALLTHROUGH*/
      case 22:
        hval += asso_values[(unsigned char)str[21]];
      /*FALLTHROUGH*/
      case 21:
        hval += asso_values[(unsigned char)str[20]];
      /*FALLTHROUGH*/
      case 20:
        hval += asso_values[(unsigned char)str[19]];
      /*FALLTHROUGH*/
      case 19:
        hval += asso_values[(unsigned char)str[18]];
      /*FALLTHROUGH*/
      case 18:
        hval += asso_values[(unsigned char)str[17]];
      /*FALLTHROUGH*/
      case 17:
        hval += asso_values[(unsigned char)str[16]];
      /*FALLTHROUGH*/
      case 16:
        hval += asso_values[(unsigned char)str[15]];
      /*FALLTHROUGH*/
      case 15:
        hval += asso_values[(unsigned char)str[14]];
      /*FALLTHROUGH*/
      case 14:
        hval += asso_values[(unsigned char)str[13]];
      /*FALLTHROUGH*/
      case 13:
        hval += asso_values[(unsigned char)str[12]];
      /*FALLTHROUGH*/
      case 12:
        hval += asso_values[(unsigned char)str[11]];
      /*FALLTHROUGH*/
      case 11:
        hval += asso_values[(unsigned char)str[10]];
      /*FALLTHROUGH*/
      case 10:
        hval += asso_values[(unsigned char)str[9]];
      /*FALLTHROUGH*/
      case 9:
        hval += asso_values[(unsigned char)str[8]];
      /*FALLTHROUGH*/
      case 8:
        hval += asso_values[(unsigned char)str[7]];
      /*FALLTHROUGH*/
      case 7:
        hval += asso_values[(unsigned char)str[6]];
      /*FALLTHROUGH*/
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

static const struct css_prop wordlist_prop[] =
  {
#line 28 "ksvgcssproperties.gperf"
    {"fill", SVGCSS_PROP_FILL},
#line 17 "ksvgcssproperties.gperf"
    {"filter", SVGCSS_PROP_FILTER},
#line 15 "ksvgcssproperties.gperf"
    {"mask", SVGCSS_PROP_MASK},
#line 33 "ksvgcssproperties.gperf"
    {"marker", SVGCSS_PROP_MARKER},
#line 35 "ksvgcssproperties.gperf"
    {"marker-mid", SVGCSS_PROP_MARKER_MID},
#line 38 "ksvgcssproperties.gperf"
    {"stroke", SVGCSS_PROP_STROKE},
#line 52 "ksvgcssproperties.gperf"
    {"kerning", SVGCSS_PROP_KERNING},
#line 30 "ksvgcssproperties.gperf"
    {"fill-rule", SVGCSS_PROP_FILL_RULE},
#line 34 "ksvgcssproperties.gperf"
    {"marker-end", SVGCSS_PROP_MARKER_END},
#line 36 "ksvgcssproperties.gperf"
    {"marker-start", SVGCSS_PROP_MARKER_START},
#line 14 "ksvgcssproperties.gperf"
    {"clip-rule", SVGCSS_PROP_CLIP_RULE},
#line 43 "ksvgcssproperties.gperf"
    {"stroke-miterlimit", SVGCSS_PROP_STROKE_MITERLIMIT},
#line 13 "ksvgcssproperties.gperf"
    {"clip-path", SVGCSS_PROP_CLIP_PATH},
#line 32 "ksvgcssproperties.gperf"
    {"image-rendering", SVGCSS_PROP_IMAGE_RENDERING},
#line 29 "ksvgcssproperties.gperf"
    {"fill-opacity", SVGCSS_PROP_FILL_OPACITY},
#line 41 "ksvgcssproperties.gperf"
    {"stroke-linecap", SVGCSS_PROP_STROKE_LINECAP},
#line 37 "ksvgcssproperties.gperf"
    {"shape-rendering", SVGCSS_PROP_SHAPE_RENDERING},
#line 22 "ksvgcssproperties.gperf"
    {"stop-opacity", SVGCSS_PROP_STOP_OPACITY},
#line 44 "ksvgcssproperties.gperf"
    {"stroke-opacity", SVGCSS_PROP_STROKE_OPACITY},
#line 21 "ksvgcssproperties.gperf"
    {"stop-color", SVGCSS_PROP_STOP_COLOR},
#line 26 "ksvgcssproperties.gperf"
    {"color-profile", SVGCSS_PROP_COLOR_PROFILE},
#line 48 "ksvgcssproperties.gperf"
    {"baseline-shift", SVGCSS_PROP_BASELINE_SHIFT},
#line 27 "ksvgcssproperties.gperf"
    {"color-rendering", SVGCSS_PROP_COLOR_RENDERING},
#line 39 "ksvgcssproperties.gperf"
    {"stroke-dasharray", SVGCSS_PROP_STROKE_DASHARRAY},
#line 40 "ksvgcssproperties.gperf"
    {"stroke-dashoffset", SVGCSS_PROP_STROKE_DASHOFFSET},
#line 19 "ksvgcssproperties.gperf"
    {"flood-opacity", SVGCSS_PROP_FLOOD_OPACITY},
#line 20 "ksvgcssproperties.gperf"
    {"lighting-color", SVGCSS_PROP_LIGHTING_COLOR},
#line 18 "ksvgcssproperties.gperf"
    {"flood-color", SVGCSS_PROP_FLOOD_COLOR},
#line 54 "ksvgcssproperties.gperf"
    {"writing-mode", SVGCSS_PROP_WRITING_MODE},
#line 47 "ksvgcssproperties.gperf"
    {"alignment-baseline", SVGCSS_PROP_ALIGNMENT_BASELINE},
#line 46 "ksvgcssproperties.gperf"
    {"text-rendering", SVGCSS_PROP_TEXT_RENDERING},
#line 42 "ksvgcssproperties.gperf"
    {"stroke-linejoin", SVGCSS_PROP_STROKE_LINEJOIN},
#line 31 "ksvgcssproperties.gperf"
    {"font-size-adjust", SVGCSS_PROP_FONT_SIZE_ADJUST},
#line 45 "ksvgcssproperties.gperf"
    {"stroke-width", SVGCSS_PROP_STROKE_WIDTH},
#line 23 "ksvgcssproperties.gperf"
    {"pointer-events", SVGCSS_PROP_POINTER_EVENTS},
#line 49 "ksvgcssproperties.gperf"
    {"dominant-baseline", SVGCSS_PROP_DOMINANT_BASELINE},
#line 24 "ksvgcssproperties.gperf"
    {"color-interpolation", SVGCSS_PROP_COLOR_INTERPOLATION},
#line 53 "ksvgcssproperties.gperf"
    {"text-anchor", SVGCSS_PROP_TEXT_ANCHOR},
#line 25 "ksvgcssproperties.gperf"
    {"color-interpolation-filters", SVGCSS_PROP_COLOR_INTERPOLATION_FILTERS},
#line 16 "ksvgcssproperties.gperf"
    {"enable-background", SVGCSS_PROP_ENABLE_BACKGROUND},
#line 51 "ksvgcssproperties.gperf"
    {"glyph-orientation-vertical", SVGCSS_PROP_GLYPH_ORIENTATION_VERTICAL},
#line 50 "ksvgcssproperties.gperf"
    {"glyph-orientation-horizontal", SVGCSS_PROP_GLYPH_ORIENTATION_HORIZONTAL}
  };

static const signed char lookupProp[] =
  {
    -1, -1, -1, -1,  0, -1,  1, -1, -1,  2, -1,  3, -1, -1,
    -1,  4,  5,  6, -1,  7,  8, -1,  9, -1, 10, -1, -1, 11,
    -1, 12, 13, -1, 14, -1, -1, -1, -1, -1, -1, 15, 16, -1,
    17, -1, 18, 19, -1, -1, 20, 21, 22, 23, 24, 25, 26, -1,
    27, 28, 29, 30, 31, 32, 33, -1, 34, -1, -1, 35, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, 36, -1, 37, -1, -1,
    -1, -1, -1, 38, -1, -1, -1, -1, 39, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 40,
    -1, 41
  };

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct css_prop *
findSVGProp (register const char *str, register unsigned int len)
{
  if (len <= PROP_MAX_WORD_LENGTH && len >= PROP_MIN_WORD_LENGTH)
    {
      register int key = hash_prop (str, len);

      if (key <= PROP_MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookupProp[key];

          if (index >= 0)
            {
              register const char *s = wordlist_prop[index].name;

              if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
                return &wordlist_prop[index];
            }
        }
    }
  return 0;
}
#line 55 "ksvgcssproperties.gperf"


namespace SVG
{


static const unsigned short propList[] = {
    65535,
    12,
    10,
    2,
    39,
    1,
    27,
    25,
    26,
    19,
    17,
    34,
    36,
    38,
    20,
    22,
    0,
    14,
    7,
    32,
    13,
    3,
    8,
    4,
    9,
    16,
    5,
    23,
    24,
    15,
    31,
    11,
    18,
    33,
    30,
    29,
    21,
    35,
    41,
    40,
    6,
    37,
    28,
    65535
};

const char *getSVGCSSPropertyName(unsigned short id)
{
    if (!id || id > SVGCSS_PROP_MAX) return "";
    return wordlist_prop[propList[id]].name;
}

int getSVGCSSPropertyID(const char *tagStr, int len)
{
    const struct css_prop *propPtr = findSVGProp(tagStr, len);
    if(!propPtr)
      return 0;
    return propPtr->id;
}

}