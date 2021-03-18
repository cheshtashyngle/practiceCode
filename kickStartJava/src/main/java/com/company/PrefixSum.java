package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CompletableFuture;
import java.util.stream.Collectors;

public class PrefixSum {

    static List<Integer> computePrefixParallel(List<Integer> numbers) {
        int sizeOfNumbers = numbers.size();

        if(sizeOfNumbers <= 1) {
            return numbers;
        }

        List<Integer> prefixSumFirstHalf = new ArrayList<>();
        List<Integer> prefixSumSecondHalf = new ArrayList<>();
        CompletableFuture.allOf(
                CompletableFuture.supplyAsync(() -> computePrefixParallel(numbers.subList(0, sizeOfNumbers/2)))
                        .thenAccept(prefixSumFirstHalf::addAll),
                CompletableFuture.supplyAsync(() -> computePrefixParallel(numbers.subList(sizeOfNumbers/2, sizeOfNumbers)))
                        .thenAccept(prefixSumSecondHalf::addAll)
        ).join();

        prefixSumSecondHalf = prefixSumSecondHalf.parallelStream().map(number ->
                number + prefixSumFirstHalf.get(sizeOfNumbers/2 - 1))
                .collect(Collectors.toList());

        List<Integer> prefixSum = new ArrayList<>(prefixSumFirstHalf);
        prefixSum.addAll(prefixSumSecondHalf);
        return prefixSum;
    }

    static List<Integer> computePrefixParallelLoop(List<Integer> numbers) {
        List<Integer> prefixSum = new ArrayList<>(numbers);
        for(int i = 2; i <= prefixSum.size(); i = i*2) {
            int diff = prefixSum.size() % i;
            if(diff > 0) {
                for(int count = 0; count < diff; count++) {
                    prefixSum.add(0, 0);
                }
            }
            // TODO: make the loop parallel
            for(int j = 0; j < prefixSum.size(); j = j + i) {
                // TODO: make the loop parallel
                for(int k = j + i/2; k < j + i; k++) {
                    prefixSum.set(k, prefixSum.get(j + (i / 2) - 1) + prefixSum.get(k));
                }
            }
        }
        return prefixSum;
    }

    static List<Integer> computePrefixSequential(List<Integer> numbers) {
        int sizeOfNumbers = numbers.size();
        if (sizeOfNumbers <=  1) {
            return numbers;
        }
        int index = sizeOfNumbers - 1;
        List<Integer> prefixSum = new ArrayList<>(computePrefixSequential(numbers.subList(0, index)));
        Integer lastNumber = prefixSum.get(index - 1) + numbers.get(index);
        prefixSum.add(lastNumber);
        return prefixSum;
    }

    static List<Integer> computePrefixSequentialLoop(List<Integer> numbers) {
        List<Integer> prefixSum = new ArrayList<>();
        int sum = 0;
        for (Integer number : numbers) {
            sum = sum + number;
            prefixSum.add(sum);
        }

        return prefixSum;
    }
}
