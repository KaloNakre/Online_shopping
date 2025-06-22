#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void signUp();
int logIn();
void viewProducts();
void buyProducts();
void checkout();
void logout();
void viewLaptops();
void viewSmartphones();
void viewPCs();
void viewAccessories();
void adminLogin();
void addProduct(int category);
void viewAdminProducts();
void printBanner(char banner[]);
void welcomeBanner();
void looding();
void systemCleaner();

char username[50], password[50];
float totalCost = 0;
char purchasedItems[100][50];
int purchaseCount = 0;

int laptopIds[50] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10,11};
char laptopNames[50][50] = {
    "Lenovo Legion",
    "Acer Nitro 5",
    "HP Victus",
    "MacBook M3",
    "MacBook M4",
    "Zenbook Pro 14 Duo OLED",
    "ASUS Zenbook Pro 16X OLED",
    "MacBook Air M3",
    "MacBook Air M3 pro",
    "MacBook Air M4",
    "MacBook Air M4 pro",

};
float laptopPrices[50] = {120000, 85000, 87000, 90000, 95000, 115000, 125000, 97000, 98000,99000,100000};
int laptopCount = 11;

int smartphoneIds[50] = {1, 2, 3, 4, 5, 6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
char smartphoneNames[50][50] = {
    "Samsung Galaxy S25",
    "Samsung Galaxy S25 Ultra",
    "Samsung Galaxy S24",
    "Samsung Galaxy S24 Ultra",
    "OnePlus 12",
    "OnePlus 12R",
    "OnePlus 12 pro",
     "iPhone 16",
    "iPhone 16 Pro ",
    "iPhone 16 Pro Max",
    "Pixel 7",
    "Pixel 7 Pro",
    "Pixel 8",
    "Pixel 8 Pro",
    "Xiomi Redmi Note 13",
    "Xiomi Redmi Note 13 Pro",
    "Xiomi Redmi Note 13 Pro Max",
    "Oppo Find X 3",
    "Oppo Find X 3 Pro",
    "Oppo Find X 3 Pro Max",


};
float smartphonePrices[50] = {130000, 150000, 110000, 100000, 115000, 131500,140000,112000,113000,114000,118000,122000,1223000,122500,1227000,130500,133000,135000,140500,150500};
int smartphoneCount = 20;
int pcIds[50] = {1, 2, 3, 4, 5,6,7};
char pcNames[50][50] = {
    "HP",
    "Apple",
    "ASUS",
    "Acer",
    "Dell",
    "xiomi",
    "Samsung"
};
float pcPrices[50] = {95000, 87000, 120000, 105000, 95000,11500,15500};
int pcCount = 7;
int accessoryIds[50] = {1, 2, 3, 4,5,6,7,8};
char accessoryNames[50][50] = {"Logitech Mouse", "Mechanical Keyboard", "Wireless Headset", "Webcam 1080p","RGB Keyboard","Wireless Keyboard","Wireless Mouse","PowerBank"};
float accessoryPrices[50] = {1500, 5000, 3000, 2500,2200,3300,4550,4000};
int accessoryCount = 8;

char adminUsername[] = "Admin";
char adminPassword[] = "12345";

int main() {
    looding();
    int choice;

    while (1) {
        welcomeBanner();
        printf("1. Sign Up\n");
        printf("2. Log In\n");
        printf("3. Admin Login\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            signUp();
            printf("Please log in now.\n");
        } else if (choice == 2) {
            if (logIn()) {
                break;
            } else {
                printf("Invalid credentials. Please sign up first.\n");
                signUp();
            }
        } else if (choice == 3) {
            adminLogin();
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    while (1) {
        systemCleaner();
        printBanner("Main Menu");
        printf("1. View Products\n");
        printf("2. Buy Products\n");
        printf("3. Checkout\n");
        printf("4. Logout\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            viewProducts();
        } else if (choice == 2) {
            buyProducts();
        } else if (choice == 3) {
            checkout();
        } else if (choice == 4) {
            logout();
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


void looding() {
    printf("\n................................................ONLINE..SHOP................................................................\n\n");
    for (int i = 0; i <= 560; i += 5) {
        printf("\r[");
        for (int j = 0; j < i / 5; j++) printf("=");
        for (int j = i / 5; j < 20; j++) printf(" ");
        printf("] %d%%", i);
        fflush(stdout);
        usleep(1000);
    }
    printf("\n\n");
}

void printBanner(char banner[]) {
    printf("\n======================== %s==========================\n", banner);
}

void welcomeBanner() {
    printBanner("Welcome to The Online Shop");
}

void signUp() {
    looding();
    printBanner("Sign Up");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Sign-up successful!\n");
}
int logIn() {
    systemCleaner();
    char inputUsername[50], inputPassword[50];
    looding();
    printf("Enter username: ");
    scanf("%s", inputUsername);
    printf("Enter password: ");
    scanf("%s", inputPassword);

    if (strcmp(username, inputUsername) == 0 && strcmp(password, inputPassword) == 0) {
        printf("Login successful! Welcome, %s.\n", username);
        return 1;
    } else {
        return 0;
    }
}

void viewProducts() {
    systemCleaner();
    looding();
    printBanner("Available Products");
    viewLaptops();
    viewSmartphones();
    viewPCs();
    viewAccessories();
}

void viewLaptops() {
    printf("\nLaptops:\n");
    for (int i = 0; i < laptopCount; i++) {
        printf("%d. %s - %.2f\n", laptopIds[i], laptopNames[i], laptopPrices[i]);
    }
}

void viewSmartphones() {
    printf("\nSmartphones:\n");
    for (int i = 0; i < smartphoneCount; i++) {
        printf("%d. %s - %.2f\n", smartphoneIds[i], smartphoneNames[i], smartphonePrices[i]);
    }
}

void viewPCs() {
    printf("\nPCs:\n");
    for (int i = 0; i < pcCount; i++) {
        printf("%d. %s - %.2f\n", pcIds[i], pcNames[i], pcPrices[i]);
    }
}

void viewAccessories() {
    printf("\nAccessories:\n");
    for (int i = 0; i < accessoryCount; i++) {
        printf("%d. %s - %.2f\n", accessoryIds[i], accessoryNames[i], accessoryPrices[i]);
    }
}


void buyProducts() {
    looding();
    int category, productId, quantity;
    char choice;
    do {
        printf("\nChoose a category to buy from:\n");
        printf("1. Laptops\n");
        printf("2. Smartphones\n");
        printf("3. PCs\n");
        printf("4. Accessories\n");
        printf("Choose an option: ");
        scanf("%d", &category);

        int count = 0;
        if (category == 1) {
            viewLaptops();
            count = laptopCount;
        } else if (category == 2) {
            viewSmartphones();
            count = smartphoneCount;
        } else if (category == 3) {
            viewPCs();
            count = pcCount;
        } else if (category == 4) {
            viewAccessories();
            count = accessoryCount;
        } else {
            printf("Invalid category!\n");
            return;
        }

        printf("\nEnter product ID to buy: ");
        scanf("%d", &productId);
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        int found = 0;
        for (int i = 0; i < count; i++) {
            if ((category == 1 && laptopIds[i] == productId) ||
                (category == 2 && smartphoneIds[i] == productId) ||
                (category == 3 && pcIds[i] == productId) ||
                (category == 4 && accessoryIds[i] == productId)) {

                if (category == 1) {
                    totalCost += laptopPrices[i] * quantity;
                    printf("%s added to cart. Total cost: taka %.2f\n", laptopNames[i], totalCost);
                } else if (category == 2) {
                    totalCost += smartphonePrices[i] * quantity;
                    printf("%s added to cart. Total cost: taka %.2f\n", smartphoneNames[i], totalCost);
                } else if (category == 3) {
                    totalCost += pcPrices[i] * quantity;
                    printf("%s added to cart. Total cost: taka %.2f\n", pcNames[i], totalCost);
                } else if (category == 4) {
                    totalCost += accessoryPrices[i] * quantity;
                    printf("%s added to cart. Total cost: taka %.2f\n", accessoryNames[i], totalCost);
                }
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Invalid product ID!\n");
        }

        printf("\nDo you want to shop again? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
}


void checkout() {
    systemCleaner();
    looding();
    char coupon[20];
    int paymentOption;

    if (totalCost > 120000) {
        totalCost *= 0.9;
        printf("You received a 10%% discount for your large purchase! New total: %.2f\n", totalCost);
    }

    printf("\nDo you have a coupon code? (Enter or type 'NO'): ");
    scanf("%s", coupon);

    if (strcmp(coupon, "BLACKFRIDAY") == 0) {
        totalCost *= 0.7;
        printf("BLACKFRIDAY applied! 30%% discount.\n");
    } else if (strcmp(coupon, "NEWYEAR") == 0) {
        totalCost *= 0.8;
        printf("NEWYEAR applied! 20%% discount.\n");
    } else if (strcmp(coupon, "NO") != 0) {
        printf("Invalid coupon! No discount applied.\n");
    }

    printf("Final Total: taka %.2f\n", totalCost);

    printf("\nChoose a payment method:\n");
    printf("1. Bkash\n");
    printf("2. Nagad\n");
    printf("3. IBBL Bank Transfer\n");
    printf("4. Check Payment\n");
    printf("5. Rocket\n");
    printf("Enter your choice: ");
    scanf("%d", &paymentOption);

    switch (paymentOption) {
        looding();
        case 1: printf("Bkash\n"); break;
        case 2: printf("Nagad\n"); break;
        case 3: printf("IBBL Bank Transfer\n"); break;
        case 4: printf("Check Payment\n"); break;
        case 5: printf("Rocket\n"); break;
        default: printf("Invalid method\n"); break;
    }

    printf("Thank you for shopping with us!\n");
    totalCost = 0;
}

void adminLogin() {
    systemCleaner();
    char inputUsername[50], inputPassword[50];
    looding();
    printf("Enter admin username: ");
    scanf("%s", inputUsername);
    printf("Enter admin password: ");
    scanf("%s", inputPassword);

    if (strcmp(adminUsername, inputUsername) == 0 && strcmp(adminPassword, inputPassword) == 0) {
        printf("Admin login successful!\n");
        int choice;
        do {
            printBanner("Admin Menu");
            printf("1. Add Product\n");
            printf("2. View Products\n");
            printf("3. Logout\n");
            printf("Choose an option: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Select Category to Add Product (1: Laptop, 2: Smartphone, 3: PC, 4: Accessory): ");
                    int category;
                    scanf("%d", &category);
                    addProduct(category);
                    break;
                case 2:
                    viewAdminProducts();
                    break;

                case 3:
                    printf("Admin logged out.\n");
                    return;
                default:
                    printf("Invalid choice! Please select a valid option.\n");
            }
        } while (1);
    } else {
        printf("Invalid admin credentials.\n");
    }
}

void addProduct(int category) {
    systemCleaner();
    looding();
    char name[50];
    float price;
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product price: ");
    scanf("%f", &price);

    switch (category) {
        case 1:
            if (laptopCount < sizeof(laptopIds) / sizeof(laptopIds[0])) {
                laptopIds[laptopCount] = laptopCount + 1;
                strcpy(laptopNames[laptopCount], name);
                laptopPrices[laptopCount] = price;
                laptopCount++;
                printf("Laptop added successfully!\n");
            } else {
                printf("Laptop list is full! Cannot add more laptops.\n");
            }
            break;
        case 2:
            if (smartphoneCount < sizeof(smartphoneIds) / sizeof(smartphoneIds[0])) {
                smartphoneIds[smartphoneCount] = smartphoneCount + 1;
                strcpy(smartphoneNames[smartphoneCount], name);
                smartphonePrices[smartphoneCount] = price;
                smartphoneCount++;
                printf("Smartphone added successfully!\n");
            } else {
                printf("Smartphone list is full! Cannot add more smartphones.\n");
            }
            break;
        case 3:
            if (pcCount < sizeof(pcIds) / sizeof(pcIds[0])) {
                pcIds[pcCount] = pcCount + 1;
                strcpy(pcNames[pcCount], name);
                pcPrices[pcCount] = price;
                pcCount++;
                printf("PC added successfully!\n");
            } else {
                printf("PC list is full! Cannot add more PCs.\n");
            }
            break;
        case 4:
            if (accessoryCount < sizeof(accessoryIds) / sizeof(accessoryIds[0])) {
                accessoryIds[accessoryCount] = accessoryCount + 1;
                strcpy(accessoryNames[accessoryCount], name);
                accessoryPrices[accessoryCount] = price;
                accessoryCount++;
                printf("Accessory added successfully!\n");
            } else {
                printf("Accessory list is full! Cannot add more accessories.\n");
            }
            break;
        default:
            printf("Invalid category! Please choose a valid category.\n");
    }
}
void viewAdminProducts() {
    systemCleaner();
    looding();
    printBanner("View All Products");

    printf("\nLaptops:\n");
    if (laptopCount > 0) {
        for (int i = 0; i < laptopCount; i++) {
            printf("%d. %s - %.2f\n", laptopIds[i], laptopNames[i], laptopPrices[i]);
        }
    } else {
        printf("No laptops available.\n");
    }

    printf("\nSmartphones:\n");
    if (smartphoneCount > 0) {
        for (int i = 0; i < smartphoneCount; i++) {
            printf("%d. %s - %.2f\n", smartphoneIds[i], smartphoneNames[i], smartphonePrices[i]);
        }
    } else {
        printf("No smartphones available.\n");
    }

    printf("\nPCs:\n");
    if (pcCount > 0) {
        for (int i = 0; i < pcCount; i++) {
            printf("%d. %s - %.2f\n", pcIds[i], pcNames[i], pcPrices[i]);
        }
    } else {
        printf("No PCs available.\n");
    }

    printf("\nAccessories:\n");
    if (accessoryCount > 0) {
        for (int i = 0; i < accessoryCount; i++) {
            printf("%d. %s - %.2f\n", accessoryIds[i], accessoryNames[i], accessoryPrices[i]);
        }
    } else {
        printf("No accessories available.\n");
    }
}
void systemCleaner() {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
    system("clear || cls");
}
void logout() {
    printf("\nLogging out...\n");
    looding();
    main();
}