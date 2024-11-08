#include <stdio.h>
#include <string.h>
#include <ctype.h>
char * ones[]= {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char * teens[]= {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char * tens[]= {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char * thousands[]= {"", "Thousand", "Million"};
int isDigitsOnly(char str[]) {
	for (int i=(0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00); (i < strlen(str)) & !!(i < strlen(str)); i++) {
		if (!isdigit(str[i])) {
			return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
		};
	};
	return (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
};
int isLettersOnly(char str[]) {
	for (int i=(0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00); (i < strlen(str)) & !!(i < strlen(str)); i++) {
		if (!isalpha(str[i])) {
			return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
		};
	};
	return (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
};
void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {};
};
void convertThreeDigit(int num,char* output) {
	if ((num >= (0x00000000000000C8 + 0x0000000000000264 + 0x0000000000000864 - 0x0000000000000B2C)) & !!(num >= (0x00000000000000C8 + 0x0000000000000264 + 0x0000000000000864 - 0x0000000000000B2C))) {
		strcat(output,ones[num / (0x00000000000000C8 + 0x0000000000000264 + 0x0000000000000864 - 0x0000000000000B2C)]);
		strcat(output,"\x20""H\165n\x64""r\145d\x20""");
		num %= (0x00000000000000C8 + 0x0000000000000264 + 0x0000000000000864 - 0x0000000000000B2C);
	};
	if ((num >= (0x0000000000000028 + 0x0000000000000214 + 0x0000000000000814 - 0x0000000000000A3C)) & !!(num >= (0x0000000000000028 + 0x0000000000000214 + 0x0000000000000814 - 0x0000000000000A3C))) {
		strcat(output,tens[num / (0x0000000000000014 + 0x000000000000020A + 0x000000000000080A - 0x0000000000000A1E)]);
		strcat(output,"\x20""");
		num %= (0x0000000000000014 + 0x000000000000020A + 0x000000000000080A - 0x0000000000000A1E);
	}
	else if ((num >= (0x0000000000000014 + 0x000000000000020A + 0x000000000000080A - 0x0000000000000A1E)) & !!(num >= (0x0000000000000014 + 0x000000000000020A + 0x000000000000080A - 0x0000000000000A1E))) {
		strcat(output,teens[num - (0x0000000000000014 + 0x000000000000020A + 0x000000000000080A - 0x0000000000000A1E)]);
		strcat(output,"\x20""");
		num = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
	};;
	if ((num > (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)) & !!(num > (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00))) {
		strcat(output,ones[num]);
		strcat(output,"\x20""");
	};
};
void convertToWords(int num,char* output) {
	int thousandCounter=(0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
	while ((num > (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)) & !!(num > (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00))) {
		if ((num % (0x00000000000007D0 + 0x00000000000005E8 + 0x0000000000000BE8 - 0x00000000000015B8) ^ 0x0000000000000000)) {
			char temp[(0x00000000000000C8 + 0x0000000000000264 + 0x0000000000000864 - 0x0000000000000B2C)]="";
			convertThreeDigit(num % (0x00000000000007D0 + 0x00000000000005E8 + 0x0000000000000BE8 - 0x00000000000015B8),temp);
			strcat(temp,thousands[thousandCounter]);
			strcat(temp,"\x20""");
			strcat(temp,output);
			strcpy(output,temp);
		};
		num /= (0x00000000000007D0 + 0x00000000000005E8 + 0x0000000000000BE8 - 0x00000000000015B8);
		thousandCounter++;
	};
	if (strlen(output) == (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)) {
		strcpy(output,"\x5A""e\162o\x20""");
	};
};
int main() {
	char student_id[(0x000000000000001E + 0x000000000000020F + 0x000000000000080F - 0x0000000000000A2D)];
	char first_name[(0x000000000000001E + 0x000000000000020F + 0x000000000000080F - 0x0000000000000A2D)];
	char last_name[(0x000000000000001E + 0x000000000000020F + 0x000000000000080F - 0x0000000000000A2D)];
	char gender[(0x0000000000000014 + 0x000000000000020A + 0x000000000000080A - 0x0000000000000A1E)];
	int course;
	int year;
	int subjects;
	float amountTendered;
	do {
		printf("Enter Student ID Number (Max 15 characters, numbers only): ");
		scanf("%s", student_id);
		if (!isDigitsOnly(student_id)) {
			printf("Error: Student ID should contain numbers only.\n");
		}
	} while (!isDigitsOnly(student_id));
	do {
		printf("Enter First Name (Max 15 characters, letters only): ");
		scanf("%s", first_name);
		if (!isLettersOnly(first_name)) {
			printf("Error: First Name should contain letters only.\n");
		}
	} while (!isLettersOnly(first_name));
	do {
		printf("Enter Last Name (Max 15 characters, letters only): ");
		scanf("%s", last_name);
		if (!isLettersOnly(last_name)) {
			printf("Error: Last Name should contain letters only.\n");
		}
	} while (!isLettersOnly(last_name));
	int validGender=(0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
	do {
		printf("Enter Gender (Female, Male, Gay, Lesbian): ");
		scanf("%s", gender);
		if (strcmp(gender, "Female") == 0 || strcmp(gender, "Male") == 0 ||
		        strcmp(gender, "Gay") == 0 || strcmp(gender, "Lesbian") == 0) {
			validGender = 1;
		} else {
			printf("Error: Please enter a valid gender (Female, Male, Gay, Lesbian).\n");
		}
	} while (!validGender);
	while ((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
		printf("\x53""e\154e\x63""t\040C\x6F""u\162s\x65"":\012");
		printf("\x31"" \055 \x42""S\111T\x0A""");
		printf("\x32"" \055 \x42""S\110M\x0A""");
		printf("\x33"" \055 \x42""S\105D\x0A""");
		printf("\x34"" \055 \x43""O\115P\x45""\x0A");
		printf("\x45""n\164e\x72"" \164h\x65"" \143o\x72""r\145s\x70""o\156d\x69""n\147 \x6E""u\155b\x65""r\040f\x6F""r\040y\x6F""u\162 \x63""o\165r\x73""e\072 ");
		if ((scanf("\x25""d",&course) ^ 0x0000000000000001) || (course < (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) & !!(course < (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) || (course > (0x0000000000000008 + 0x0000000000000204 + 0x0000000000000804 - 0x0000000000000A0C)) & !!(course > (0x0000000000000008 + 0x0000000000000204 + 0x0000000000000804 - 0x0000000000000A0C))) {
			printf("\x45""r\162o\x72"":\040P\x6C""e\141s\x65"" \163e\x6C""e\143t\x20""a\040v\x61""l\151d\x20""c\157u\x72""s\145 \x6E""u\155b\x65""r\040(\x31""-\064)\x2E""\x0A");
			clearInputBuffer();
		} else {
			break;
		};
	};
	while ((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
		printf("\x45""n\164e\x72"" \131e\x61""r\040L\x65""v\145l\x20""(\061-\x35"")\072 ");
		if ((scanf("\x25""d",&year) ^ 0x0000000000000001) || (year < (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) & !!(year < (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) || (year > (0x000000000000000A + 0x0000000000000205 + 0x0000000000000805 - 0x0000000000000A0F)) & !!(year > (0x000000000000000A + 0x0000000000000205 + 0x0000000000000805 - 0x0000000000000A0F))) {
			printf("\x45""r\162o\x72"":\040Y\x65""a\162 \x4C""e\166e\x6C"" \155u\x73""t\040b\x65"" \142e\x74""w\145e\x6E"" \061 \x61""n\144 \x35"".\012");
			clearInputBuffer();
		} else {
			break;
		};
	};
	while ((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) {
		printf("\x45""n\164e\x72"" \116u\x6D""b\145r\x20""o\146 \x53""u\142j\x65""c\164s\x20""E\156r\x6F""l\154e\x64"" \050M\x61""x\0401\x30"")\072 ");
		if ((scanf("\x25""d",&subjects) ^ 0x0000000000000001) || (subjects < (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) & !!(subjects < (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)) || (subjects > (0x0000000000000014 + 0x000000000000020A + 0x000000000000080A - 0x0000000000000A1E)) & !!(subjects > (0x0000000000000014 + 0x000000000000020A + 0x000000000000080A - 0x0000000000000A1E))) {
			printf("\x45""r\162o\x72"":\040N\x75""m\142e\x72"" \157f\x20""s\165b\x6A""e\143t\x73"" \155u\x73""t\040b\x65"" \142e\x74""w\145e\x6E"" \061 \x61""n\144 \x31""0\056\x0A");
			clearInputBuffer();
		} else {
			break;
		};
	};
	float tuitionPerUnit=450.00;
	float registrationFee,miscellaneousFee=1000.00,laboratoryFee;
	switch (course) {
	case (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03):
		registrationFee = 545.00;
		laboratoryFee = 3000.00;
		break;
	case (0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06):
		registrationFee = 550.00;
		laboratoryFee = 3500.00;
		break;
	case (0x0000000000000006 + 0x0000000000000203 + 0x0000000000000803 - 0x0000000000000A09):
		registrationFee = 555.00;
		laboratoryFee = 1500.00;
		break;
	case (0x0000000000000008 + 0x0000000000000204 + 0x0000000000000804 - 0x0000000000000A0C):
		registrationFee = 560.00;
		laboratoryFee = 3000.00;
		break;
	};
	int totalUnits=subjects * (0x0000000000000006 + 0x0000000000000203 + 0x0000000000000803 - 0x0000000000000A09);
	float totalTuition=(totalUnits * tuitionPerUnit) + registrationFee + miscellaneousFee + laboratoryFee;
	int totalTuitionInt=(int )totalTuition;
	int cents=(int )((totalTuition - totalTuitionInt) * (0x00000000000000C8 + 0x0000000000000264 + 0x0000000000000864 - 0x0000000000000B2C));
	do {
		printf("Enter Amount Tendered (Must be no less than %.2f): ", totalTuition);
		if (scanf("%f", &amountTendered) != 1 || amountTendered < totalTuition) {
			printf("Error: Amount tendered is less than the total assessment. Please provide a sufficient amount.\n");
			clearInputBuffer(); /* clear invalid input */
		} else {
			break;
		}
	} while (1);
	char totalInWords[(0x00000000000003E8 + 0x00000000000003F4 + 0x00000000000009F4 - 0x0000000000000FDC)]="";
	convertToWords(totalTuitionInt,totalInWords);
	printf("\x0A""\x0A\125n\x69""v\145r\x73""i\164y\x20""o\146 \x43""e\142u\x20""-\040M\x61""i\156 \x43""a\155p\x75""s\012O\x46""F\111C\x49""A\114 \x52""E\103E\x49""P\124\x0A\x0A""");
	printf("\x49""D\040#\x3A"" \045s\x0A""",student_id);
	printf("\x4E""a\155e\x3A"" \045s\x2C"" \045s\x0A""",last_name,first_name);
	printf("\x47""e\156d\x65""r\072 \x25""s\012",gender);
	printf("\x43""o\165r\x73""e\072 ");
	switch (course) {
	case (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03):
		printf("\x42""S\111T\x20""-\040");
		break;
	case (0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06):
		printf("\x42""S\110M\x20""-\040");
		break;
	case (0x0000000000000006 + 0x0000000000000203 + 0x0000000000000803 - 0x0000000000000A09):
		printf("\x42""S\105D\x20""-\040");
		break;
	case (0x0000000000000008 + 0x0000000000000204 + 0x0000000000000804 - 0x0000000000000A0C):
		printf("\x43""O\115P\x45"" \055 ");
		break;
	};
	printf("\x25""d\012",year);
	printf("\x54""o\164a\x6C"" \125n\x69""t\163:\x20""%\144\x0A",totalUnits);
	printf("\x54""o\164a\x6C"" \101s\x73""e\163s\x6D""e\156t\x3A"" \045.\x32""f\012",totalTuition);
	if ((cents > (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)) & !!(cents > (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00))) {
		printf("\x41""m\157u\x6E""t\040i\x6E"" \167o\x72""d\163:\x20""%\163a\x6E""d\040%\x64""/\0610\x30""\x0A",totalInWords,cents);
	} else {
		printf("\x41""m\157u\x6E""t\040i\x6E"" \167o\x72""d\163:\x20""%\163\x0A",totalInWords);
	};
	return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
};
