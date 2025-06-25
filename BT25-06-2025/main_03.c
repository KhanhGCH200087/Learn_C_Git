#include <stdio.h>
#include <stdlib.h>

//Question 3

struct Date { 
    int day; 
    int month; 
    int year; 
}; 

struct Book { 
    char title[100]; 
    char author[50]; 
    struct Date publishDate; 
};

void condition_day(int *day, int *check){ // check input day
	if(*day >= 1 && *day <= 31){
		*check = 0;
	} else {
		printf("\nEnter day again");
		*check = 1;
	}
}

void condition_month(int *month, int *check){ //check input month
	if(*month >= 1 && *month <= 12){
		*check = 0;
	} else {
		printf("\nEnter month again");
		*check = 1;
	}
}

void condition_year(int *year, int *check){ //check input year
	if(*year >= 0 && *year <= 2025){
		*check = 0;
	} else {
		printf("\nEnter year again");
		*check = 1;
	}
}

void insert_Book(struct Book *books, int n){ // Input Book
	for(int i = 0; i < n; i++){
		printf("\n\nEnter Book number %d", i);
		printf("\nEnter Title: ");
		scanf("%s", &books[i].title);
		printf("\nEnter Author: ");
		scanf("%s", &books[i].author);
		
		printf("\nEnter Date: ");
		
		int check_day = 1;
		while(check_day){
			printf("\nDay: ");
			scanf("%d", &books[i].publishDate.day);
			int day = books[i].publishDate.day;
			condition_day(&day, &check_day);
		}
		
		int check_month = 1;
		while(check_month){
			printf("\nMonth: ");
			scanf("%d", &books[i].publishDate.month);
			int month = books[i].publishDate.month;
			condition_month(&month, &check_month);
		}
		
		int check_year = 1;
		while(check_year){
			printf("\nYear: ");
			scanf("%d", &books[i].publishDate.year);
			int year = books[i].publishDate.year;
			condition_year(&year, &check_year);
		}
		
		printf("\n************");
	}
	
	printf("\n\nDone Enter ");
	printf("\n-----------------------------------------");
}

void print_1_Book(struct Book *books, int i){ //Print 1 Book
		printf("\nTitle: %s", books[i].title);
		printf("\nAuthor: %s", books[i].author);
		printf("\nDate: %d / %d / %d",
				books[i].publishDate.day,
				books[i].publishDate.month,
				books[i].publishDate.year);
}

void print_Book(struct Book *books, int n){ //Print list of Book
	printf("\nPrint list of Book");
	for(int i = 0; i < n; i++){
		printf("\n\nBook number %d", i);
		printf("\nTitle: %s", books[i].title);
		printf("\nAuthor: %s", books[i].author);
		printf("\nDate: %d / %d / %d",
				books[i].publishDate.day,
				books[i].publishDate.month,
				books[i].publishDate.year);
		printf("\n************");
	}
}

int book_recent_publish_date(struct Book *books, int n){ 
	int book_recent_year = 0; //vị trí trong array -> 0
	int book_recent_year_value = books[0].publishDate.year; //giá trị year của books[0]
	int i;
	for(i = 0; i < n; i++){
		if(book_recent_year_value < books[i].publishDate.year){
			book_recent_year_value = books[i].publishDate.year;
			book_recent_year = i; //tìm book với year lớn nhất
		}
	}
	int count_book_same_year = 0;
	for(i = 0; i < n; i++){ //tìm xem có book nào cùng year lớn nhất ko
		if(books[book_recent_year].publishDate.year == books[i].publishDate.year){
			count_book_same_year++;
		}
	}
	
	if(count_book_same_year < 0){ //Trường hợp có 1 year lớn nhất 
		printf("\n Book with the most recent publish date.");
		print_1_Book(&books, book_recent_year);
	} else {
		struct Book book_same_year[count_book_same_year]; //array lưu book với year giống nhau
		static int loop = 0;
		for(i = 0; i < n; i++){
			if(books[i].publishDate.year == books[book_recent_year].publishDate.year){
				book_same_year[loop] = books[i];
				loop++;
			}
		}
		
		//book_same_year[count_book_same_year]
		int book_recent_month = 0;
		int book_recent_month_value = book_same_year[0].publishDate.month; 
		int i;
		for(i = 0; i < count_book_same_year; i++){
			if(book_recent_month_value < book_same_year[i].publishDate.month){
				book_recent_month_value = book_same_year[i].publishDate.month;
				book_recent_month = i; //tìm book với month lớn nhất
			}
		}
		
		int count_book_same_month = 0;
		for(i = 0; i < n; i++){ //tìm xem có book nào cùng month lớn nhất ko
			if(book_recent_month_value == book_same_year[i].publishDate.month){
				count_book_same_month ++;
			}
		}
		
		if(count_book_same_month < 0){ //trường hợp có 1 month lớn nhất
			printf("\n Book with the most recent publish date.");
			print_1_Book(&book_same_year, book_recent_month);
		} else {
			struct Book book_same_month[count_book_same_month];
			static int loop = 0;
			for(i = 0; i < n; i++){
				if(book_same_month[i].publishDate.month == book_same_month[book_recent_month].publishDate.month){
					book_same_month[loop] = book_same_year[i];
					loop++;
				}
			}
			
			//book_same_month[count_book_same_month]
			int book_recent_day = 0;
			int book_recent_day_value = book_same_month[0].publishDate.day; 
			int i;
			for(i = 0; i < count_book_same_month; i++){
				if(book_recent_day_value < book_same_month[i].publishDate.day){
					book_recent_day_value = book_same_month[i].publishDate.day;
					book_recent_day = i; //tìm book với day lớn nhất
				}
			}
			
			int count_book_same_day = 0;
			for(i = 0; i < n; i++){ //tìm xem có book nào cùng month lớn nhất ko
				if(book_recent_day_value == book_same_month[i].publishDate.day){
					count_book_same_day ++;
				}
			}
			
			if(count_book_same_day < 0){ //trường hợp có 1 day lớn nhất
				printf("\n Book with the most recent publish date.");
				print_1_Book(&book_same_month, book_recent_day);
			} else {
				printf("\n Book with the most recent publish date.");
				print_Book(&book_same_month, count_book_same_month);
			}		
		}
	}

}

int main() {
	int n;
	printf("\nEnter n: ");
	scanf("%d", &n);
	if(n == 0){
		return 0;
	}
	struct Book books[n];
	
	insert_Book(&books, n);

	print_Book(&books, n);
	
	book_recent_publish_date(&books, n);

	return 0;
}