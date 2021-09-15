/*
*********************************************************************************
* TO RUN ON WINDOWS :
* STEP I   - Open x64 Native Command Prompt Of Visual Studio
* STEP II  - run [$ cl.exe PeriodicTable.c] command
* STEP III - run [$ PeriodicTable.exe]
*********************************************************************************
*/

#include "PeriodicTable.h"

int main(void)
{
    int menuchoice(void);
    void printOnConsole(void);
    void printInFile(void);

    // Code
    int atomicNumberIndex;
    int returnCharacter;

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

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    do
    {
        returnCharacter = menuchoice();

        switch (returnCharacter)
        {
        case EXIT:
            printf("Thank You For Using The Program!\n");
            break;

        case PRINT_ON_CONSOLE:
            printf("Displaying The Output On The Console...\n");
            printOnConsole();
            break;

        case PRINT_IN_FILE:
            printf("Saving The Details In 'PeriodicTableElementFile.txt'\n");
            printInFile();
            break;

        default:
            printf("INVALID CHOICE, PLEASE SELECT THE VALID OPTION\n");
            break;
        }

    } while (returnCharacter != 0);

    return (0);
}

int menuchoice(void)
{
    // Code
    int character;

    printf("\n");
    printf("::::::::::::::::::::::::::::::::::::\n");
    printf(":::::::::::: MENUCHOICE ::::::::::::\n");
    printf("::::::::::::::::::::::::::::::::::::\n");
    printf("::                                ::\n");
    printf(":: EXIT               -     0     ::\n");
    printf(":: PRINT ON CONSOLE   -     1     ::\n");
    printf(":: PRINT IN FILE      -     2     ::\n");
    printf("::                                ::\n");
    printf("::::::::::::::::::::::::::::::::::::\n");

    printf("\n => SELECT ANY OPTION FROM ABOVE (DO NOT USE ANY CHARACTER FOR INPUT) - ");
    scanf("%d", &character);

    return (character);
}

void printOnConsole(void)
{
    // Code
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
    // Code
    FILE *periodicTableElementFile = NULL;
    char *periodicTableElementFileName = "PeriodicTableElementFile.txt";

    char *stateValue = NULL;
    int atomicNumberIndex;
    double meltingPointValue;
    double boilingPointValue;

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
