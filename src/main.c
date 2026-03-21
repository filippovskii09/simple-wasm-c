#include <stdio.h>
#include <string.h>
#include "../include/cJSON.h"

enum {
	SHOP_SIZE = 3,
	PRODUCT_NAME_MAX_LEN = 40,
	BUFFER_SIZE = 1024
};

/*
 * In this case, we use double instead of float because it is more precise.
 * You can use float instead of double if you want, but it is not recommended(for prices).
 * If you want to use float, you must write 799.99f instead of 799.99.
 * Float type have size 4 bytes(32 bits), double type have size 8 bytes(64 bits).
*/
struct Product {
	int id;
	char name[PRODUCT_NAME_MAX_LEN];
	double price; // float price;
};

int main(void) {
	FILE *fptr;

	fptr = fopen("fake_data/product.json", "r");

	if(fptr == NULL) {
		printf("Error opening file\n");
		return 1;
	}

	struct Product shop[SHOP_SIZE];

	char buffer[BUFFER_SIZE];
	size_t n = fread(buffer, sizeof(char), BUFFER_SIZE, fptr);
	buffer[n] = '\0';

	cJSON *json = cJSON_Parse(buffer);
	if(json == NULL) {
		printf("Error parsing JSON\n");
		return 1;
	}

	cJSON *products = cJSON_GetObjectItem(json, "products");
	if(products == NULL) {
		printf("Error getting products array\n");
		return 1;
	}

	int array_size = cJSON_GetArraySize(products);

  for (int i = 0; i < array_size; i++) {
		cJSON *product = cJSON_GetArrayItem(products, i);
		
		cJSON *id_obj    = cJSON_GetObjectItem(product, "id");
		cJSON *name_obj  = cJSON_GetObjectItem(product, "name");
		cJSON *price_obj = cJSON_GetObjectItem(product, "price");
		
		shop[i].id = id_obj->valueint;
		strcpy(shop[i].name, name_obj->valuestring);
		shop[i].price = price_obj->valuedouble;
	}

	cJSON_Delete(json);

	printf("Read %zu products\n", n);

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
