/*
    Frequency To/From Mockingboard Tones
    by Michael Pohoreski
    GitHub: https://github.com/Michaelangel007/apple2_mockingboard


The Mockingboard document at:

* ftp://ftp.apple.asimov.net/pub/apple_II/documentation/hardware/sound/Mockingboard%20Docs.pdf

has several incorrect values:

APPENDIX E

                             Course & Fine
    Note  Octave  Frequency  Decimal  Hex.  Notes
    A     0         27.500   9  20    09 14 <-- should be 90F Exact 27.5 Hz -- bottom key on Piano
    A#    0         29.135   8 145    08 91 <-- should be 88D
    B     0         30.868   8  22    08 16 <-- should be 812

    C     1         32.703   7 163    07 A3 <-- should be 79E
    C#    1         34.648   7  53    07 35 <-- should be 731
    D     1         36.708   6 205    06 CD <-- should be 6C9
    D#    1         38.891   6 108    06 6C <-- should be 668
    E     1         41.203   6  15    06 0F <-- should be 60C
    F     1         43.654   5 184    05 B8 <-- should be 5B5
    F#    1         46.249   5 102    05 66 <-- should be 563
    G     1         48.999   5  24    05 18 <-- should be 516
    G#    1         51.913   4 207    04 CF <-- should be 4CD
    A     1         55.000   4 138    04 8A <-- should be 488 Exact 55.0 Hz
    A#    1         58.270   4  73    04 49 <-- should be 447
    B     1         61.735   4  11    04 0B <-- should be 409

    C     2         65.406   3 209    03 D1 <-- should be 3CF
    C#    2         69.296   3 154    03 9A <-- should be 398
    D     2         73.416   3 102    03 66 <-- should be 365
    D#    2         77.782   3  54    03 36 <-- should be 335
    E     2         82.406   3   7    03 07 <-- should be 306
    F     2         87.308   2 220    02 DC <-- should be 2DB
    F#    2         92.498   2 179    02 B3 <-- should be 2B2
    G     2         97.998   2 140    02 8C <-- should be 28B
    G#    3        103.826   2 103    02 67 <-- should be 266
    A     3        110.000   2  69    02 45 <-- should be 244 Exact 110.0 Hz
    A#    3        116.540   2  36    02 24 <-- should be 223
    B     3        123.470   2   5    02 05

    C     3        130.812   1 232    01 E8
    C#    3        138.592   1 205    01 CD <-- should be 1CC
    D     3        146.832   1 179    01 B3 <-- should be 1C2
    D#    3        155.564   1 155    01 9B <-- should be 19A
    E     3        164.812   1 131    01 83
    F     3        174.616   1 110    01 6E <-- should be 16D
    F#    3        184.996   1  89    01 59
    G     3        195.996   1  70    01 46 <-- should be 145
    G#    3        207.652   1  51    01 33
    A     3        220.000   1  34    01 22
    A#    3        233.080   1  18    01 12
    B     3        246.940   1   2    01 02

    C     4        261.624   0 244    00 F4 -- Middle C4 --
    C#    4        277.184   0 230    00 E6
    D     4        293.664   0 217    00 D9
    D#    4        311.128   0 205    00 CD
    E     4        329.624   0 193    00 C1 <-- 329.628 Hz
    F     4        349.232   0 183    00 B7 <-- 349.228 Hz
    F#    4        369.992   0 172    00 AC
    G     4        391.992   0 163    00 A3
    G#    4        415.304   0 153    00 99 <-- should be 9A
    A     4        440.000   0 145    00 91                  Exact 440 Hz -- Concert Tuning A440
    A#    4        466.160   0 137    00 89
    B     4        493.880   0 129    00 81

    C     5        523.248   0 122    00 7A
    C#    5        554.368   0 115    00 73
    D     5        587.328   0 108    00 6C <-- should be 6D
    D#    5        622.256   0 102    00 66 <-- should be 67
    E     5        659.248   0  96    00 60 <-- should be 61, and 659.255 Hz
    F     5        698.464   0  91    00 58 <-- Should be 5B
    F#    5        739.984   0  86    00 56
    G     5        783.984   0  81    00 51
    G#    5        830.608   0  76    00 4C <-- should be 4D
    A     5        880.000   0  72    00 48                  Exact 880 Hz
    A#    5        932.320   0  68    00 44 <-- 932.328 Hz
    B     5        987.760   0  64    00 40 <-- should be 41, and 987.767 Hz

    C     6       1046.496   0  61    00 3D                  -- every frequency
    C#    6       1108.736   0  57    00 39 <-- should be 3A -- from this point
    D     6       1174.656   0  54    00 36                  -- forward is slightly
    D#    6       1244.512   0  51    00 33                  -- off except for 'A'
    E     6       1318.496   0  48    00 30
    F     6       1396.928   0  45    00 2D <-- should be 2E, and 1396.913 Hz
    F#    6       1479.968   0  43    00 2B
    G     6       1567.968   0  40    00 2B <-- Should be 29
    G#    6       1661.216   0  38    00 26
    A     6       1760.000   0  36    00 24                  Exact 1760 Hz
    A#    6       1864.640   0  34    00 22
    B     6       1975.520   0  32    00 20

    C     7       2092.992   0  30    00 1E                  2093.005 Hz
    C#    7       2217.472   0  28    00 1C <-- should be 1D
    D     7       2349.312   0  27    00 1B
    D#    7       2489.024   0  25    00 19 <-- should be 1A
    E     7       2636.992   0  24    00 18
    F     7       2793.856   0  22    00 16 <-- should be 17
    F#    7       2959.936   0  21    00 15 <-- should be 16
    G     7       3135.936   0  20    00 14
    G#    7       3322.432   0  19    00 13
    A     7       3520.000   0  18    00 12                  Exact 3520 Hz
    A#    7       3729.280   0  17    00 11
    B     7       3951.040   0  16    00 10

    C     8       4185.984   0  15    00 0F                  -- top key on Piano
    C#    8       4434.944   0  14    00 0E
    D     8       4698.624   0  13    00 0D
    D#    8       4978.048   0  12    00 0C
    E     8       5273.984   0  12    00 0C                  5274.041 Hz
    F     8       5587.712   0  11    00 0B
    F#    8       5919.872   0  10    00 0A
    G     8       6271.872   0  10    00 0A
    G#    8       6644.864   0   9    00 09
    A     8       7040.000   0   9    00 09 Exact 7040 Hz
    A#    8       7458.560   0   8    00 08
    B     8       7902.080   0   8    00 08


Here are the correct frequencies and tones
along with the relative error:

    Note  Frequency     Tone   Decimal   reproduced  Relative Error

    A0    27.500 Hz -> $090F (  9  15) ~  27.503 Hz  (+0.012%)
    A0#   29.135 Hz -> $088D (  8 141) ~  29.137 Hz  (+0.005%)
    B0    30.868 Hz -> $0812 (  8  18) ~  30.871 Hz  (+0.012%)

    C1    32.703 Hz -> $079E (  7 158) ~  32.708 Hz  (+0.014%)
    C1#   34.648 Hz -> $0731 (  7  49) ~  34.644 Hz  (-0.010%)
    D1    36.708 Hz -> $06C9 (  6 201) ~  36.719 Hz  (+0.029%)
    D1#   38.891 Hz -> $0668 (  6 104) ~  38.890 Hz  (-0.001%)
    E1    41.203 Hz -> $060C (  6  12) ~  41.202 Hz  (-0.004%)
    F1    43.654 Hz -> $05B5 (  5 181) ~  43.655 Hz  (+0.004%)
    F1#   46.249 Hz -> $0563 (  5  99) ~  46.251 Hz  (+0.004%)
    G1    48.999 Hz -> $0516 (  5  22) ~  48.986 Hz  (-0.027%)
    G1#   51.913 Hz -> $04CD (  4 205) ~  51.896 Hz  (-0.033%)
    A1    55.000 Hz -> $0488 (  4 136) ~  54.983 Hz  (-0.031%)
    A1#   58.270 Hz -> $0447 (  4  71) ~  58.247 Hz  (-0.041%)
    B1    61.735 Hz -> $0409 (  4   9) ~  61.743 Hz  (+0.012%)

    C2    65.406 Hz -> $03CF (  3 207) ~  65.416 Hz  (+0.014%)
    C2#   69.296 Hz -> $0398 (  3 152) ~  69.326 Hz  (+0.044%)
    D2    73.416 Hz -> $0365 (  3 101) ~  73.395 Hz  (-0.029%)
    D2#   77.782 Hz -> $0334 (  3  52) ~  77.781 Hz  (-0.001%)
    E2    82.407 Hz -> $0306 (  3   6) ~  82.403 Hz  (-0.004%)
    F2    87.307 Hz -> $02DB (  2 219) ~  87.251 Hz  (-0.065%)
    F2#   92.499 Hz -> $02B2 (  2 178) ~  92.435 Hz  (-0.069%)
    G2    97.999 Hz -> $028B (  2 139) ~  97.973 Hz  (-0.027%)
    G2#  103.826 Hz -> $0266 (  2 102) ~ 103.877 Hz  (+0.049%)
    A2   110.000 Hz -> $0244 (  2  68) ~ 109.966 Hz  (-0.031%)
    A2#  116.541 Hz -> $0223 (  2  35) ~ 116.600 Hz  (+0.051%)
    B2   123.471 Hz -> $0205 (  2   5) ~ 123.366 Hz  (-0.085%)

    C3   130.813 Hz -> $01E8 (  1 232) ~ 130.697 Hz  (-0.088%)
    C3#  138.591 Hz -> $01CC (  1 204) ~ 138.653 Hz  (+0.044%)
    D3   146.832 Hz -> $01B2 (  1 178) ~ 146.959 Hz  (+0.086%)
    D3#  155.563 Hz -> $019A (  1 154) ~ 155.562 Hz  (-0.001%)
    E3   164.814 Hz -> $0183 (  1 131) ~ 164.807 Hz  (-0.004%)
    F3   174.614 Hz -> $016D (  1 109) ~ 174.740 Hz  (+0.072%)
    F3#  184.997 Hz -> $0159 (  1  89) ~ 184.870 Hz  (-0.069%)
    G3   195.998 Hz -> $0145 (  1  69) ~ 196.247 Hz  (+0.127%)
    G3#  207.652 Hz -> $0133 (  1  51) ~ 207.753 Hz  (+0.049%)
    A3   220.000 Hz -> $0122 (  1  34) ~ 219.932 Hz  (-0.031%)
    A3#  233.082 Hz -> $0112 (  1  18) ~ 232.775 Hz  (-0.132%)
    B3   246.942 Hz -> $0102 (  1   2) ~ 247.210 Hz  (+0.109%)

    C4   261.626 Hz -> $00F4 (  0 244) ~ 261.395 Hz  (-0.088%)
    C4#  277.183 Hz -> $00E6 (  0 230) ~ 277.306 Hz  (+0.044%)
    D4   293.665 Hz -> $00D9 (  0 217) ~ 293.918 Hz  (+0.086%)
    D4#  311.127 Hz -> $00CD (  0 205) ~ 311.123 Hz  (-0.001%)
    E4   329.628 Hz -> $00C1 (  0 193) ~ 330.468 Hz  (+0.255%)
    F4   349.228 Hz -> $00B7 (  0 183) ~ 348.526 Hz  (-0.201%)
    F4#  369.994 Hz -> $00AC (  0 172) ~ 370.816 Hz  (+0.222%)
    G4   391.995 Hz -> $00A3 (  0 163) ~ 391.290 Hz  (-0.180%)
    G4#  415.305 Hz -> $009A (  0 154) ~ 414.158 Hz  (-0.276%)
    A4   440.000 Hz -> $0091 (  0 145) ~ 439.864 Hz  (-0.031%)
    A4#  466.164 Hz -> $0089 (  0 137) ~ 465.549 Hz  (-0.132%)
    B4   493.883 Hz -> $0081 (  0 129) ~ 494.421 Hz  (+0.109%)

    C5   523.251 Hz -> $007A (  0 122) ~ 522.789 Hz  (-0.088%)
    C5#  554.365 Hz -> $0073 (  0 115) ~ 554.611 Hz  (+0.044%)
    D5   587.330 Hz -> $006D (  0 109) ~ 585.140 Hz  (-0.373%)
    D5#  622.254 Hz -> $0067 (  0 103) ~ 619.226 Hz  (-0.487%)
    E5   659.255 Hz -> $0061 (  0  97) ~ 657.529 Hz  (-0.262%)
    F5   698.456 Hz -> $005B (  0  91) ~ 700.882 Hz  (+0.347%)
    F5#  739.989 Hz -> $0056 (  0  86) ~ 741.631 Hz  (+0.222%)
    G5   783.991 Hz -> $0051 (  0  81) ~ 787.411 Hz  (+0.436%)
    G5#  830.609 Hz -> $004D (  0  77) ~ 828.315 Hz  (-0.276%)
    A5   880.000 Hz -> $0048 (  0  72) ~ 885.837 Hz  (+0.663%)
    A5#  932.328 Hz -> $0044 (  0  68) ~ 937.945 Hz  (+0.603%)
    B5   987.767 Hz -> $0041 (  0  65) ~ 981.235 Hz  (-0.661%)

    C6  1046.502 Hz -> $003D (  0  61) ~1045.578 Hz  (-0.088%)
    C6# 1108.731 Hz -> $003A (  0  58) ~1099.660 Hz  (-0.818%)
    D6  1174.659 Hz -> $0036 (  0  54) ~1181.116 Hz  (+0.550%)
    D6# 1244.508 Hz -> $0033 (  0  51) ~1250.594 Hz  (+0.489%)
    E6  1318.510 Hz -> $0030 (  0  48) ~1328.756 Hz  (+0.777%)
    F6  1396.913 Hz -> $002E (  0  46) ~1386.528 Hz  (-0.743%)
    F6# 1479.978 Hz -> $002B (  0  43) ~1483.262 Hz  (+0.222%)
    G6  1567.982 Hz -> $0029 (  0  41) ~1555.616 Hz  (-0.789%)
    G6# 1661.219 Hz -> $0026 (  0  38) ~1678.428 Hz  (+1.036%)
    A6  1760.000 Hz -> $0024 (  0  36) ~1771.674 Hz  (+0.663%)
    A6# 1864.655 Hz -> $0022 (  0  34) ~1875.890 Hz  (+0.603%)
    B6  1975.533 Hz -> $0020 (  0  32) ~1993.133 Hz  (+0.891%)

    C7  2093.005 Hz -> $001E (  0  30) ~2126.009 Hz  (+1.577%)
    C7# 2217.461 Hz -> $001D (  0  29) ~2199.320 Hz  (-0.818%)
    D7  2349.318 Hz -> $001B (  0  27) ~2362.232 Hz  (+0.550%)
    D7# 2489.016 Hz -> $001A (  0  26) ~2453.087 Hz  (-1.443%)
    E7  2637.020 Hz -> $0018 (  0  24) ~2657.511 Hz  (+0.777%)
    F7  2793.826 Hz -> $0017 (  0  23) ~2773.055 Hz  (-0.743%)
    F7# 2959.955 Hz -> $0016 (  0  22) ~2899.103 Hz  (-2.056%)
    G7  3135.963 Hz -> $0014 (  0  20) ~3189.014 Hz  (+1.692%)
    G7# 3322.438 Hz -> $0013 (  0  19) ~3356.856 Hz  (+1.036%)
    A7  3520.000 Hz -> $0012 (  0  18) ~3543.348 Hz  (+0.663%)
    A7# 3729.310 Hz -> $0011 (  0  17) ~3751.781 Hz  (+0.603%)
    B7  3951.066 Hz -> $0010 (  0  16) ~3986.267 Hz  (+0.891%)

    C8  4186.009 Hz -> $000F (  0  15) ~4252.018 Hz  (+1.577%)
    C8# 4434.922 Hz -> $000E (  0  14) ~4555.734 Hz  (+2.724%)
    D8  4698.636 Hz -> $000E (  0  14) ~4555.734 Hz  (-3.041%)
    D8# 4978.032 Hz -> $000D (  0  13) ~4906.175 Hz  (-1.443%)
    E8  5274.041 Hz -> $000C (  0  12) ~5315.023 Hz  (+0.777%)
    F8  5587.652 Hz -> $000B (  0  11) ~5798.206 Hz  (+3.768%)
    F8# 5919.911 Hz -> $000B (  0  11) ~5798.206 Hz  (-2.056%)
    G8  6271.927 Hz -> $000A (  0  10) ~6378.027 Hz  (+1.692%)
    G8# 6644.875 Hz -> $000A (  0  10) ~6378.027 Hz  (-4.016%)

Reference:

* https://en.wikipedia.org/wiki/Piano_key_frequencies
* http://www.sciencebuddies.org/Fi les/3443/5/Phys_img024.jpg

*/

#include <stdio.h>
#include <math.h>

#define DEBUG 0

    // Every 64th cycle is stretched to be a 65th cycle
    //const double _1MHz_NTSC = 14318180.0 / 14.0; // 1,022,727 Hz
      const double _1MHz_NTSC =  1020484.32; // Avg Hz, Table 3.1, Page 3-5, UtA2E, Jim Sather
    //const double _1MHz_PAL  = 14250000.0 / 14.0;
    //const double A2_FREQ    = 1023000.0; // common incorrect value

/*
Mockingboard:
    Tone Freq = A2 Clock Freq / ((256*Course + Fine) * 16)

6502:
    Master = 14.31818 MHz
    NTSC Cycle = 14.31818 / 14 = 1.0227271429... MHz = 1022727 Hz
    PAL  Cycle = 14.25    / 14 = 1.0178571429... MHz = 1017857 Hz

    n      = Floor( 1,022,727 / freq )
    Course = Floor( n / 4096 )
    Fine   = (n - (4096*Course)) / 16
*/


// Convert Mockingboard Tone Period into Frequency
// ========================================================================
double MockingboardGetFreq( int tone_period )
{
    // / 256  = >>  8
    // * 4096 = << 12
    // int n = ((tone_period & 0xFF00) << 4) + ((tone_period & 0x00FF) << 4);
    return _1MHz_NTSC / (double) (tone_period << 4);
}

// Convert Frequency into Mockingboard Tone Period
// ========================================================================
int MockingboardGetTone( double freq_hz )
{
    const int n  = (int) (_1MHz_NTSC / freq_hz);
    const int hi = n / 4096;
    const int lo = (n  - (hi * 4096)) / 16;

    // See if Lo-1, Lo, or Lo+1 has better absolute error
    const int tone = hi*256 + lo;

    double freq_a = MockingboardGetFreq( tone-1 );
    double freq_b = MockingboardGetFreq( tone   );
    double freq_c = MockingboardGetFreq( tone+1 );

    double abs_err_a = fabs(freq_a - freq_hz) / freq_hz * 100.0;
    double abs_err_b = fabs(freq_b - freq_hz) / freq_hz * 100.0;
    double abs_err_c = fabs(freq_c - freq_hz) / freq_hz * 100.0;

#if DEBUG // absolute error
    printf( "%8.3f Hz (%9.6f) : %8.3f Hz (%9.6f) : %8.3f Hz (%9.6f) *** "
        , freq_a, abs_err_a
        , freq_b, abs_err_b
        , freq_c, abs_err_c
    );
#endif // DEBUG

    if (abs_err_a < abs_err_b) return tone-1;
    if (abs_err_b < abs_err_c) return tone;
    /*                      */ return tone+1;
}


// ========================================================================
int main( const int nArg, const char *aArg[] )
{
    (void) nArg;

    // 0freq = asm low  byte
    // 1freq = asm high byte
    int is_asm = 1*(aArg[0][0] == '0') +
                 2*(aArg[0][0] == '1') ;
    const char *names[ 12 ] =
    {
        "A ", // 2^( 0/12)
        "A#", // 2^( 1/12)
        "B ", // 2^( 2/12)
        "C ", // 2^( 3/12)
        "C#", // 2^( 4/12)
        "D ", // 2^( 5/12)
        "D#", // 2^( 6/12)
        "E ", // 2^( 7/12)
        "F ", // 2^( 8/12)
        "F#", // 2^( 9/12)
        "G ", // 2^(10/12)
        "G#"  // 2^(11/12)
    };

    double halfstep_freq[12];

    for( int half_step = 0; half_step < 12; half_step++ )
        halfstep_freq[ half_step ] = pow( 2.0, (half_step / 12.0) );

    if( !is_asm )
        printf( "Note  Frequency     Tone   Decimal   reproduced  Relative Error\n" );

    for( int octave = 0; octave < 8; octave++ )
    {
        double octave_freq = 440.0 * pow( 2.0, (octave - 4.0));

        for( int half_step = 0; half_step < 12; half_step++ )
        {
            double actual  = octave_freq * halfstep_freq[ half_step ];
            int    tone    = MockingboardGetTone( actual );
            double measure = MockingboardGetFreq( tone );
            double rel_err = (measure - actual) / actual * 100.0;

if( is_asm )
            printf( "%*s.byte $%02X ; %c%d%c %8.3f Hz\n"
                , 8, " "
                ,(tone >> ((is_asm-1) * 8)) & 0xFF
                , names[ half_step ][0]
                , octave + (half_step > 2)
                , names[ half_step ][1]
                , actual
            );
else
            printf( "%c%d%c %8.3f Hz -> $%04X (%3d %3d) ~%8.3f Hz  (%+5.3f%%)\n"
                , names[ half_step ][0]
                , octave + (half_step > 2)
                , names[ half_step ][1]
                , actual
                , tone
                , (tone >> 8) & 0xFF
                , (tone >> 0) & 0xFF
                , measure
                , rel_err
            );

            if( half_step == 2 )
                printf( "\n" );
        }
    }
    printf( "\n" );

    return 0;
}
