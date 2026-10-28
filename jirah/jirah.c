#include <stdio.h>

int main(void)
{
	const double burgerPrice = 80.0;
	const double chickenMealPrice = 120.0;
	const double spaghettiPrice = 100.0;
	int orderCount;
	long long totalMealsSold = 0;
	double totalRevenue = 0.0;

	printf("How many orders will be processed? ");
	if (scanf("%d", &orderCount) != 1 || orderCount < 0) {
		printf("Please enter a valid non-negative number of orders.\n");
		return 1;
	}

	for (int order = 1; order <= orderCount; order++) {
		int mealChoice;
		long long quantity;
		double mealPrice;

		printf("\nOrder %d\n", order);
		printf("1. Burger (P80)\n");
		printf("2. Chicken Meal (P120)\n");
		printf("3. Spaghetti (P100)\n");
		printf("Select a meal (1-3): ");

		if (scanf("%d", &mealChoice) != 1 || mealChoice < 1 || mealChoice > 3) {
			printf("Please enter a valid meal choice.\n");
			return 1;
		}

		printf("Enter quantity: ");
		if (scanf("%lld", &quantity) != 1 || quantity <= 0) {
			printf("Please enter a valid positive quantity.\n");
			return 1;
		}

		switch (mealChoice) {
			case 1:
				mealPrice = burgerPrice;
				break;
			case 2:
				mealPrice = chickenMealPrice;
				break;
			default:
				mealPrice = spaghettiPrice;
				break;
		}

		double orderTotal = mealPrice * quantity;
		printf("Order total: P%.2f\n", orderTotal);

		totalRevenue += orderTotal;
		totalMealsSold += quantity;
	}

	printf("\nTotal revenue: P%.2f\n", totalRevenue);
	printf("Total number of meals sold: %lld\n", totalMealsSold);

	return 0;
}
