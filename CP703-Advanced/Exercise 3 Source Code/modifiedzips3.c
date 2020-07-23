/***************************************************************************
 *
 * File: zips3.c
 *
 * System: C Programming Advanced, Exercise 3
 * 
 * Description: 
 *
 * External Functions:
 *     ZIPS_parse_zips_rec
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 18-Apr-2005  Arsenio Locsin		Completed the ZIPS_parse_zips_rec function
									Labor 4.0
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <zips.h>

#define BASE	10
#define MAXCHAR 1024
#define MAXZIP	100000

struct FIPS_data
{
	int fipsCode;
	char state[ZIPS_STATE_LEN + 1];
} FIPS_data_t;

/* The values for this structure was taken from
   http://www.itl.nist.gov/fipspubs/fip5-2.htm
*/
struct FIPS_data fips[] =
{
	{ 1, "AL"}, { 2, "AK"}, { 4, "AZ"}, { 5, "AR"}, { 6, "CA"}, { 8, "CO"}, 
	{ 9, "CT"}, {10, "DE"}, {11, "DC"}, {12, "FL"}, {13, "GA"}, {15, "HI"}, 
	{16, "ID"}, {17, "IL"}, {18, "IN"}, {19, "IA"}, {20, "KS"}, {21, "KY"}, 
	{22, "LA"}, {23, "ME"}, {24, "MD"}, {25, "MA"}, {26, "MI"}, {27, "MN"}, 
	{28, "MS"}, {29, "MO"}, {30, "MT"}, {31, "NE"}, {32, "NV"}, {33, "NH"}, 
	{34, "NJ"}, {35, "NM"}, {36, "NY"}, {37, "NC"}, {38, "ND"}, {39, "OH"}, 
	{40, "OK"}, {41, "OR"}, {42, "PA"}, {44, "RI"}, {45, "SC"}, {46, "SD"}, 
	{47, "TN"}, {48, "TX"}, {49, "UT"}, {50, "VT"}, {51, "VA"}, {53, "WA"}, 
	{54, "WV"}, {55, "WI"}, {56, "WY"}

};

/***************************************************************************
 * Function: ZIPS_parse_zips_rec
 * Description:  parse the input buffer zips information and
 *              initialize the structure fields
 * Input:
 *    buf - char array that contains zips information 
 * Output:
 *    zips_rec - pointer to zips record
 * Return:
 *    TRUE - translated buffer without error
 *    FALSE - error translating buffer
 * Special Logic:
 *   If FALSE returned, parse_struct is NOT modified 
 ***************************************************************************/
extern int ZIPS_parse_zips_rec( char * buf, ZIPS_data_p_t zips_rec )
{
    int returnValue = FALSE;
	char temp[MAXCHAR + 1] = " ";
	const char tokenSeperators[] = " ,\"";
	ZIPS_data_t tempStruct;
	char * ptr = NULL;
	int fieldPosition = 0;
	char * end = NULL;
	int i = 0;				/* Counter */
	int testResult = 0;
	int numFipsData = sizeof(fips) / sizeof(FIPS_data_t);
	int maxFips = 56;

	assert(buf);
	assert(zips_rec);

	strncpy(temp, buf, MAXCHAR);
	temp[MAXCHAR] = '\0';

	ptr = strtok(temp, tokenSeperators);

	if(NULL != ptr)
	{
		returnValue = TRUE;
	}

	while(ptr)
	{
		fieldPosition++;
		switch( fieldPosition )
		{
			case 1:	/* FIPS Code */
				
				tempStruct.fips_code = strtol(ptr, &end, BASE);
				
				if(*end != '\0' )
				{
					returnValue = FALSE;
				}

				if(tempStruct.fips_code < 1 || tempStruct.fips_code > maxFips)
				{
					returnValue = FALSE;
				}
				break;
				
			
			case 2: /* ZIP Code*/
				tempStruct.zip_code = strtol(ptr, &end, BASE);
				
				if(*end != '\0' || MAXZIP <= tempStruct.zip_code)
				{
					returnValue = FALSE;
				}
				break;

			case 3:	/* State */
				strncpy(tempStruct.state, ptr, ZIPS_STATE_LEN);
				tempStruct.state[ZIPS_STATE_LEN] = '\0';

				while( i < numFipsData)
				{
					if(fips[i].fipsCode == tempStruct.fips_code)
					{
						testResult = strcmp(fips[i].state, tempStruct.state);
						if(testResult)
						{
							i= numFipsData;
							returnValue = FALSE;
						}							
					}							
					i++;
				}				
				break;

			case 4: /* Name*/
				strncpy(tempStruct.name, ptr, ZIPS_CODE_NAME_LEN);
				tempStruct.name[ZIPS_CODE_NAME_LEN] = '\0';
				break;

			case 5: /* Longtitude */
				tempStruct.longitude = strtod(ptr, &end);

				if(*end != '\0')
				{
					returnValue = FALSE;
				}				
				break;

			case 6:	/* Latitude */
				tempStruct.latitude = strtod(ptr, &end);

				if(*end != '\0')
				{
					returnValue = FALSE;
				}
				break;

			case 7: /* Population*/
				tempStruct.population = strtol(ptr, &end, BASE);

				if(*end != '\0')
				{
					returnValue = FALSE;
				}
				break;

			case 8: /* Allocation */
				tempStruct.allocation = strtod(ptr, &end);

				if( *end != '\0' )
					returnValue = FALSE;
				break;

			//default:
			//	returnValue = FALSE;
			//	break;
			
		}

		if(fieldPosition + 1 == 4)
		{
			ptr = returnValue ? ptr = strtok(NULL, "\"" ) : NULL;
			ptr = returnValue ? ptr = strtok(NULL, ",\"" ): NULL;
		}
		else
		{
			ptr = returnValue ? ptr = strtok(NULL, tokenSeperators): NULL;
		}

		//if(!returnValue)
		//{
		//	ptr = NULL;
		//}		
	}

	if(fieldPosition >= 8 && returnValue)
	{
		*zips_rec = tempStruct; 
		returnValue = TRUE;
	}

	return returnValue;
}