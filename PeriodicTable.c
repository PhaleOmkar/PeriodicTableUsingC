/*
*********************************************************************************
* TO RUN ON WINDOWS :
* STEP I   - Open x64 Native Command Prompt Of Visual Studio
* STEP II  - run [$ cl.exe PeriodicTable.c] command
* STEP III - run [$ PeriodicTable.exe]
*********************************************************************************
*/

#include <stdio.h>

#define NUMBER_OF_ELEMENTS 118

struct PeriodicTableElement
{
    char *symbol;
    char *name;
    char *block;

    int atomic_number; //Z
    int standard_state;
    int period;
    int group;

    double melting_point;          //(K)
    double boiling_point;          //(K)
    double density;                // (g/cm^3)
    double standard_atomic_weight; //(Da)
} elements[NUMBER_OF_ELEMENTS];

enum ATOMIC_STATES
{
    UNKNOWN_STATE = 0,
    SOLID = 1,
    LIQUID = 2,
    GAS = 3
};

char *atomicSymbols[] = {"H ", /*********************************************************************************************/ "He",
                         "Li", "Be", /*********************************************************/ "B ", "C ", "N ", "O ", "F ", "Ne",
                         "Na", "Mg", /*********************************************************/ "Al", "Si", "P ", "S ", "Cl", "Ar",
                         "K ", "Ca", "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
                         "Rb", "Sr", "Y ", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I ", "Xe",
                         "Cs", "Ba",

                         /* Lanthanides */
                         "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu",

                         /*********/ "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Ti", "Pb", "Bi", "Po", "At", "Rn",
                         "Fr", "Ra",

                         /* Actinides */

                         "Ac", "Th", "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr",
                         /*********/ "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

char *atomicNames[] = {"Hydrogen", "Helium",
                       "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",
                       "Sodium", "Magnesium", "Aluminium", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon",
                       "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton",
                       "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon",
                       "Caesium", "Barium",
                       "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium",
                       "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon",
                       "Francium", "Radium",
                       "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium",
                       "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};

char *atomicBlock[] = {"s-block", /*****************************************************************************************************************************************************************************/ "s-block",
                       "s-block", "s-block", /***********************************************************************************************************/ "p-block", "p-block", "p-block", "p-block", "p-block", "p-block",
                       "s-block", "s-block", /***********************************************************************************************************/ "p-block", "p-block", "p-block", "p-block", "p-block", "p-block",
                       "s-block", "s-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "p-block", "p-block", "p-block", "p-block", "p-block", "p-block",
                       "s-block", "s-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "p-block", "p-block", "p-block", "p-block", "p-block", "p-block",
                       "s-block", "s-block",

                       /* Lanthanides */
                       "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block",

                       /*******************/ "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "p-block", "p-block", "p-block", "p-block", "p-block", "p-block",
                       "s-block", "s-block",

                       /* Actinides */
                       "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block", "f-block",
                       /*******************/ "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "d-block", "p-block", "p-block", "p-block", "p-block", "p-block", "p-block"};

int atomicState[] = {GAS, GAS,
                     SOLID, SOLID, SOLID, SOLID, GAS, GAS, GAS, GAS,
                     SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, GAS, GAS,
                     SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, LIQUID, GAS,
                     SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, GAS,
                     SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, LIQUID,
                     SOLID, SOLID, SOLID, SOLID, UNKNOWN_STATE, GAS, UNKNOWN_STATE,
                     SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID, SOLID,
                     UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE, UNKNOWN_STATE};

double meltingPoints[] = {14.01, 0, 453.69, 1560, 2349, 4000, 63.15, 54.36, 53.53, 24.56, 370.87, 923, 933.47, 1687, 317.3,
                          388.36, 171.6, 83.8, 336.53, 1115, 1814, 1941, 2183, 2180, 1519, 1811, 1768, 1728, 1357.77, 692.88, 302.9146, 1211.4,
                          1090, 453, 265.8, 115.79, 312.46, 1050, 1799, 2128, 2750, 2896, 2430, 2607, 2237, 1828.05, 1234.93, 594.22, 429.75, 505.08,
                          903.78, 722.66, 386.85, 161.4, 301.59, 1000, 1193, 1068, 1208, 1297, 1315, 1345, 1099, 1585, 1629, 1680, 1734, 1802, 1818, 1097,
                          1925, 2506, 3290, 3695, 3459, 3306, 2719, 2041.4, 1337.33, 234.43, 577, 600.61, 544.7, 527, 575, 202, 281, 973, 1323,
                          2115, 1841, 1405.3, 917, 912.5, 1449, 1613, 1259, 1173, 1133, 1125, -1100, -1100, -1900, -2400, 0, 0, 0, 0, 0, 0, 0, -283,
                          -700, 200, -700, -700, -700, -325};

double boilingPoints[] = {20.28,
                          4.22,
                          1560,
                          2742,
                          4200,
                          4300,
                          77.36,
                          90.2,
                          85.03,
                          27.07,
                          1156,
                          1363,
                          2792,
                          3538,
                          550,
                          717.87,
                          239.11,
                          87.3,
                          1032,
                          1757,
                          3109,
                          3560,
                          3680,
                          2944,
                          2334,
                          3134,
                          3200,
                          3186,
                          2835,
                          1180,
                          2673,
                          3106,
                          887,
                          958,
                          332,
                          119.93,
                          961,
                          1655,
                          3609,
                          4682,
                          5017,
                          4912,
                          4538,
                          4423,
                          3968,
                          3236,
                          2435,
                          1040,
                          2345,
                          2875,
                          1860,
                          1261,
                          457.4,
                          165.03,
                          944,
                          2170,
                          3737,
                          3716,
                          3793,
                          3347,
                          3273,
                          2067,
                          1802,
                          3546,
                          3503,
                          2840,
                          2993,
                          3141,
                          2223,
                          1469,
                          3675,
                          4876,
                          5731,
                          5828,
                          5869,
                          5285,
                          4701,
                          4098,
                          3129,
                          629.88,
                          1746,
                          2022,
                          1837,
                          1235,
                          610,
                          211.3,
                          890,
                          2010,
                          3471,
                          5061,
                          4300,
                          4404,
                          4273,
                          3501,
                          2880,
                          3383,
                          2900,
                          1743,
                          -1269,
                          0,
                          0,
                          0,
                          0,
                          -5800,
                          0,
                          0,
                          0,
                          0,
                          0,
                          0,
                          0,
                          340,
                          -1400,
                          -380,
                          -1400,
                          -1100,
                          -883,
                          -450};

double densityValue[] = {0.00008988,
                         0.0001785,
                         0.534,
                         1.85,
                         2.34,
                         2.267,
                         0.0012506,
                         0.001429,
                         0.001696,
                         0.0008999,
                         0.971,
                         1.738,
                         2.698,
                         2.3296,
                         1.82,
                         2.067,
                         0.003214,
                         0.0017837,
                         0.862,
                         1.54,
                         2.989,
                         4.54,
                         6.11,
                         7.15,
                         7.44,
                         7.874,
                         8.86,
                         8.912,
                         8.96,
                         7.134,
                         5.907,
                         5.323,
                         5.776,
                         4.809,
                         3.122,
                         0.003733,
                         1.532,
                         2.64,
                         4.469,
                         6.506,
                         8.57,
                         10.22,
                         11.5,
                         12.37,
                         12.41,
                         12.02,
                         10.501,
                         8.69,
                         7.31,
                         7.287,
                         6.685,
                         6.232,
                         4.93,
                         0.005887,
                         1.873,
                         3.594,
                         6.145,
                         6.77,
                         6.773,
                         7.007,
                         7.26,
                         7.52,
                         5.243,
                         7.895,
                         8.229,
                         8.55,
                         8.795,
                         9.066,
                         9.321,
                         6.965,
                         9.84,
                         13.31,
                         16.654,
                         19.25,
                         21.02,
                         22.61,
                         22.56,
                         21.46,
                         19.282,
                         13.5336,
                         11.85,
                         11.342,
                         9.807,
                         9.32,
                         7,
                         0.00973,
                         1.87,
                         5.5,
                         10.07,
                         11.72,
                         15.37,
                         18.95,
                         20.45,
                         19.84,
                         13.69,
                         13.51,
                         14.79,
                         15.1,
                         8.84,
                         9.7,
                         -10.3,
                         -9.9,
                         -15.6,
                         -23.2,
                         -29.3,
                         -35,
                         -37.1,
                         -40.7,
                         -37.4,
                         -34.8,
                         -28.7,
                         -14,
                         -16,
                         -9.928,
                         -13.5,
                         -12.9,
                         -7.2,
                         -7};

int periodNumber[] = {1, 1,
                      2, 2, 2, 2, 2, 2, 2, 2,
                      3, 3, 3, 3, 3, 3, 3, 3,
                      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                      5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                      6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
                      6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
                      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};

int groupNumber[] = {1, /*****************************************************/ 18,
                     1, 2, /******************************/ 13, 14, 15, 16, 17, 18,
                     1, 2, /******************************/ 13, 14, 15, 16, 17, 18,
                     1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
                     1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
                     1, 2,

                     /* Lanthanides */
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     /***/ 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
                     1, 2,

                     /* Actinides */
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     /***/ 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

double atomicWeightValue[] = {1.008, 4.0026, 6.94, 9.0122, 10.81, 12.011, 14.007, 15.999, 18.998, 20.18, 22.99, 24.305, 26.982, 28.085, 30.974,
                              32.06, 35.45, 39.95, 39.098, 40.078, 44.956, 47.867, 50.942, 51.996, 54.938, 55.845, 58.933, 58.693, 63.546, 65.38, 69.723,
                              72.63, 74.922, 78.971, 79.904, 83.798, 85.468, 87.62, 88.906, 91.224, 92.906, 95.95, 97, 101.07, 102.91, 106.42, 107.87,
                              112.41, 114.82, 118.71, 121.76, 127.6, 126.9, 131.29, 132.91, 137.33, 138.91, 140.12, 140.91, 144.24, 145, 150.36, 151.96,
                              157.25, 158.93, 162.5, 164.93, 167.26, 168.93, 173.05, 174.97, 178.49, 180.95, 183.84, 186.21, 190.23, 192.22, 195.08, 196.97,
                              200.59, 204.38, 207.2, 208.98, 209, 210, 222, 223, 226, 227, 232.04, 231.04, 238.03, 237, 244, 243, 247, 247, 251, 252,
                              257, 258, 259, 266, 267, 268, 269, 270, 269, 278, 281, 282, 285, 286, 289, 290, 293, 294, 294};

char *description =
    "-> The periodic table, also known as the periodic table of (the) elements, is a tabular display of the chemical elements.\n"
    "-> It is widely used in chemistry, physics, and other sciences, and is generally seen as an icon of chemistry.\n"
    "-> It is a graphic formulation of the periodic law, which states that the properties of the chemical elements exhibit a periodic\n"
    "   dependence on their atomic numbers.\n"
    "-> The table is divided into four roughly rectangular areas called blocks.\n"
    "-> The rows of the table are called periods, and the columns are called groups.\n"
    "-> Elements from the same column group of the periodic table show similar chemical characteristics.\n"
    "-> Trends run through the periodic table, with nonmetallic character (keeping their own electrons) increasing from left to right across a period,\n"
    "   and from down to up across a group, and metallic character (surrendering electrons to other atoms)increasing in the opposite direction.\n"
    "-> The underlying reason for these trends is electron configurations of atoms.\n"
    "-> The first periodic table to become generally accepted was that of the Russian chemist Dmitri Mendeleev in 1869: he formulated the periodic\n"
    "   law as a dependence of chemical properties on atomic mass. Because not all elements were then known, there were gaps in his periodic table,\n"
    "   and Mendeleev successfully used the periodic law to predict properties of some of the missing elements.\n"
    "-> The periodic law was recognized as a fundamental discovery in the late 19th century, and it was explained with the discovery of the atomic number\n"
    "   and pioneering work in quantum mechanics of the early 20th century that illuminated the internal structure of the atom.\n"
    "-> With Glenn T. Seaborg's 1945 discovery that the actinides were in fact f-block rather than d-block elements, a recognisably modern form of the table was reached.\n"
    "-> The periodic table and law are now a central and indispensable part of modern chemistry.\n"
    "-> The periodic table continues to evolve with the progress of science. In nature, only elements up to atomic number 94 exist; to go further,\n"
    "   it was necessary to synthesise new elements in the laboratory. Today, all the first 118 elements are known, completing the first seven rows of\n"
    "   the table, but chemical characterisation is still needed for the heaviest elements to confirm that their properties match their positions.\n"
    "-> It is not yet known how far the table will stretch beyond and whether the patterns of the known part of the table will continue into this unknown region.\n"
    "-> Some scientific discussion also continues regarding whether some elements are correctly positioned in today's table. Many alternative representations of\n"
    "   the periodic law exist, and there is some discussion as to whether or not there is an optimal form of the periodic table.";

int main(void)
{
    void printOnConsole(void);
    void printInFile(void);

    //Code
    int atomicNumberIndex;
    for (atomicNumberIndex = 0; atomicNumberIndex < NUMBER_OF_ELEMENTS; atomicNumberIndex++)
    {
        elements[atomicNumberIndex].symbol = atomicSymbols[atomicNumberIndex];
        elements[atomicNumberIndex].name = atomicNames[atomicNumberIndex];
        elements[atomicNumberIndex].block = atomicBlock[atomicNumberIndex];

        elements[atomicNumberIndex].atomic_number = (atomicNumberIndex + 1);
        elements[atomicNumberIndex].standard_state = atomicState[atomicNumberIndex];
        elements[atomicNumberIndex].period = periodNumber[atomicNumberIndex];
        elements[atomicNumberIndex].group = groupNumber[atomicNumberIndex];

        elements[atomicNumberIndex].melting_point = meltingPoints[atomicNumberIndex];
        elements[atomicNumberIndex].boiling_point = boilingPoints[atomicNumberIndex];
        elements[atomicNumberIndex].density = densityValue[atomicNumberIndex];
        elements[atomicNumberIndex].standard_atomic_weight = atomicWeightValue[atomicNumberIndex];
    }

    printOnConsole();
    printInFile();

    return (0);
}

void printOnConsole(void)
{
    //Code
    int atomicNumberIndex;
    char *stateValue = NULL;
    double meltingPointValue;
    double boilingPointValue;

    printf("\n");
    printf("#########################################################################################################################################################################\n");
    printf("##################################################################### Periodic Table Of The Elements ####################################################################\n");
    printf("#########################################################################################################################################################################\n");
    printf("\n");

    printf(":::::::::::::::::\n");
    printf(":: DESCRIPTION ::\n");
    printf(":::::::::::::::::\n");
    printf("%s", description);
    printf("\n\n");

    printf(":::::::::::\n");
    printf(":: TABLE ::\n");
    printf(":::::::::::\n");
    printf(" +===============+========+================+=========+===============+=====================+====================+=================+========+=======+====================+\n");
    printf(" | Atomic Number | Symbol |      Name      |  Group  |  Atomic State |  Melting Points (K) | Boiling Points (K) | Density (g/cm3) | Period | Group | Atomic Weight (Da) |\n");
    printf(" +===============+========+================+=========+===============+=====================+====================+=================+========+=======+====================+\n");
    // printf(" +---------------+--------+----------------+---------+---------------+---------------------+--------------------+-----------------+--------+-------+--------------------+\n");

    for (atomicNumberIndex = 0; atomicNumberIndex < NUMBER_OF_ELEMENTS; atomicNumberIndex++)
    {
        switch (elements[atomicNumberIndex].standard_state)
        {
        case UNKNOWN_STATE:
            stateValue = "Unknown State";
            break;

        case SOLID:
            stateValue = "Solid";
            break;

        case LIQUID:
            stateValue = "Liquid";
            break;

        case GAS:
            stateValue = "Gas";
            break;

        default:
            break;
        }

        printf(" | %8.3d\t | %4s\t  | %-14s | %7s | %-14s|",
               elements[atomicNumberIndex].atomic_number,
               elements[atomicNumberIndex].symbol,
               elements[atomicNumberIndex].name,
               elements[atomicNumberIndex].block,
               stateValue);

        meltingPointValue = elements[atomicNumberIndex].melting_point;
        if (meltingPointValue == 0)
        {
            printf("          -          |");
        }

        else if (meltingPointValue == 4000)
        {
            printf("      > %.4f    |", meltingPointValue);
        }
        else
        {
            printf("     %-4.6f\t   |", meltingPointValue);
        }

        boilingPointValue = elements[atomicNumberIndex].boiling_point;
        if (boilingPointValue == 0)
        {
            printf("          -         |");
        }
        else
        {
            printf("    %-4.6f\t|", boilingPointValue);
        }

        printf("  %-4.8f\t  |", elements[atomicNumberIndex].density);

        printf(" %4d   |", elements[atomicNumberIndex].period);
        printf(" %4d  |", elements[atomicNumberIndex].group);
        printf("       %-11.4f  |", elements[atomicNumberIndex].standard_atomic_weight);

        printf("\n +---------------+--------+----------------+---------+---------------+---------------------+--------------------+-----------------+--------+-------+--------------------+\n");
    }

    printf("\n");
    printf("XoooooooooooooooooooooooooooooooooooooooooooooooooooooooooX\n");
    printf("X Reference : Wikipedia \t||\t By : Omkar Phale X\n");
    printf("XoooooooooooooooooooooooooooooooooooooooooooooooooooooooooX\n");
}

void printInFile(void)
{
    //Code
    char *periodicTableElementFileName = "PeriodicTableElementFile.txt";
    FILE *periodicTableElementFile = NULL;
    char *stateValue = NULL;
    double meltingPointValue;
    double boilingPointValue;

    int atomicNumberIndex;

    periodicTableElementFile = fopen(periodicTableElementFileName, "w");
    if (periodicTableElementFile != NULL)
    {

        fprintf(periodicTableElementFile, "#####################################################################################################################################################################\n");
        fprintf(periodicTableElementFile, "################################################################### Periodic Table Of The Elements ##################################################################\n");
        fprintf(periodicTableElementFile, "#####################################################################################################################################################################\n");
        fprintf(periodicTableElementFile, "\n");

        fprintf(periodicTableElementFile, ":::::::::::::::::\n");
        fprintf(periodicTableElementFile, ":: DESCRIPTION ::\n");
        fprintf(periodicTableElementFile, ":::::::::::::::::\n");
        fprintf(periodicTableElementFile, "%s", description);
        fprintf(periodicTableElementFile, "\n\n");

        fprintf(periodicTableElementFile, ":::::::::::\n");
        fprintf(periodicTableElementFile, ":: TABLE ::\n");
        fprintf(periodicTableElementFile, ":::::::::::\n");
        fprintf(periodicTableElementFile, "+===============+========+================+=========+===============+===================+===================+================+========+=======+====================+\n");
        fprintf(periodicTableElementFile, "| Atomic Number | Symbol |      Name      |  Group  |  Atomic State | Melting Points(K) | Boiling Points(K) | Density(g/cm3) | Period | Group | Atomic Weight (Da) |\n");
        fprintf(periodicTableElementFile, "+===============+========+================+=========+===============+===================+===================+================+========+=======+====================+\n");
        // fprintf(periodicTableElementFile, "+---------------+--------+----------------+---------+---------------+-------------------+-------------------+----------------+--------+-------+--------------------+\n");

        for (atomicNumberIndex = 0; atomicNumberIndex < NUMBER_OF_ELEMENTS; atomicNumberIndex++)
        {
            switch (elements[atomicNumberIndex].standard_state)
            {
            case UNKNOWN_STATE:
                stateValue = "Unknown State";
                break;

            case SOLID:
                stateValue = "Solid";
                break;

            case LIQUID:
                stateValue = "Liquid";
                break;

            case GAS:
                stateValue = "Gas";
                break;

            default:
                break;
            }

            fprintf(periodicTableElementFile, "| %8.3d      | %4s   |  %-14s| %7s | %-14s|",
                    elements[atomicNumberIndex].atomic_number,
                    elements[atomicNumberIndex].symbol,
                    elements[atomicNumberIndex].name,
                    elements[atomicNumberIndex].block, stateValue);

            meltingPointValue = elements[atomicNumberIndex].melting_point;
            if (meltingPointValue == 0)
            {
                fprintf(periodicTableElementFile, "          -        |");
            }
            else if (meltingPointValue == 4000)
            {
                fprintf(periodicTableElementFile, "    > %-4.4f    |", meltingPointValue);
            }
            else if (meltingPointValue > 0)
            {
                fprintf(periodicTableElementFile, "    %9.4f      |", meltingPointValue);
            }
            else if (meltingPointValue < 0)
            {
                if (meltingPointValue > -1000)
                {
                    fprintf(periodicTableElementFile, "    %-4.4f      |", meltingPointValue);
                }
                else
                {
                    fprintf(periodicTableElementFile, "    %-4.3f      |", meltingPointValue);
                }
            }

            boilingPointValue = elements[atomicNumberIndex].boiling_point;
            if (boilingPointValue == 0)
            {
                fprintf(periodicTableElementFile, "         -         |");
            }
            else if (boilingPointValue < 100)
            {
                fprintf(periodicTableElementFile, "   %10.6f   \t|", boilingPointValue);
            }
            else
            {
                fprintf(periodicTableElementFile, "   %.6f   \t|", boilingPointValue);
            }

            fprintf(periodicTableElementFile, "  %11.6f\t  |", elements[atomicNumberIndex].density);

            fprintf(periodicTableElementFile, " %4d   |", elements[atomicNumberIndex].period);
            fprintf(periodicTableElementFile, " %4d  |", elements[atomicNumberIndex].group);
            fprintf(periodicTableElementFile, "       %-11.4f  |", elements[atomicNumberIndex].standard_atomic_weight);

            fprintf(periodicTableElementFile, "\n+---------------+--------+----------------+---------+---------------+-------------------+-------------------+----------------+--------+-------+--------------------+\n");
        }

        fprintf(periodicTableElementFile, "\n");
        fprintf(periodicTableElementFile, "XoooooooooooooooooooooooooooooooooooooooooooooooooX\n");
        fprintf(periodicTableElementFile, "X Reference : Wikipedia \t||\t By : Omkar Phale X\n");
        fprintf(periodicTableElementFile, "XoooooooooooooooooooooooooooooooooooooooooooooooooX\n");
    }

    if (periodicTableElementFile)
    {
        fclose(periodicTableElementFile);
        periodicTableElementFile = NULL;
    }
}
