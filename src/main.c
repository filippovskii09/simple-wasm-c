#include <stdio.h>
#include <string.h>

#define SHOP_SIZE 3
#define PRODUCT_NAME_MAX_LEN 40

struct Product {
	int id;
	char name[PRODUCT_NAME_MAX_LEN];
	float price;
};

int main() {
	struct Product shop[SHOP_SIZE] = {
		{101, "Smartphone", 799.99},
		{102, "Laptop",     1250.00},
		{103, "Headphones", 150.50}
	};

	struct Product *ptr = shop;

	printf("=== SYSTEM OF GOODS ACCOUNTING ===\n\n");

	for (int i = 0; i < SHOP_SIZE; i++) {
		printf("Product #%d:\n", i + 1);
		printf("   ID: %d\n", ptr->id);
		printf("   Name: %s\n", ptr->name);
		printf("   Price: $%.2f\n", ptr->price);
		ptr++; 

		printf("------------------------------------\n");
	}

	printf("Size of one product: %lu bytes\n", sizeof(struct Product));
	printf("Size of the entire warehouse (%d products): %lu bytes\n", SHOP_SIZE, sizeof(shop));

	return 0;
}
