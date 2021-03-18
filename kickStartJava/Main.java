import java.util.Scanner;

import static java.util.Arrays.sort;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfTestCases = scanner.nextInt();
        int[] houses = new int[numberOfTestCases];
        for(int i = 0; i < numberOfTestCases; i++) {
            int numberOfHouses = scanner.nextInt();
            int[] houseRents = new int[numberOfHouses];
            int budget = scanner.nextInt();
            for (int j = 0; j < numberOfHouses; j++) {
                houseRents[j] = scanner.nextInt();
            }
            houses[i] = maxNumberOfHouses(houseRents, budget);
        }

        for(int i = 0; i < numberOfTestCases; i++) {
            System.out.println("Case #" + (i+1) + ": " + houses[i]);
        }
    }

    private static int maxNumberOfHouses(int[] houseCostList, int budget) {
        int numberOfHouse = 0;
        int remainingBudget = budget;
        sort(houseCostList);
        for (int houseCost : houseCostList) {
            if (remainingBudget >= houseCost) {
                numberOfHouse++;
                remainingBudget -= houseCost;
            }
        }
        return numberOfHouse;
    }
}
