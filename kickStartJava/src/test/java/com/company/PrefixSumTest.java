package com.company;

import org.junit.Test;

import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

import static org.hamcrest.core.Is.is;
import static org.junit.Assert.assertThat;

public class PrefixSumTest {

    @Test
    public void shouldComputePrefixParallel() {
        List<Integer> numbers = Arrays.asList(3, 5, 3, 1, 6);
        List<Integer> expectedSum = Arrays.asList(3, 8, 11, 12, 18);

        List<Integer> prefixSum = PrefixSum.computePrefixParallel(numbers);

        assertThat(prefixSum, is(expectedSum));
    }

    @Test
    public void shouldComputePrefixParallelLoop() {
        List<Integer> numbers = Arrays.asList(3, 5, 3, 1, 6);
        List<Integer> expectedSum = Arrays.asList(0, 0, 0, 3, 8, 11, 12, 18);

        List<Integer> prefixSum = PrefixSum.computePrefixParallelLoop(numbers);

        assertThat(prefixSum, is(expectedSum));
    }

    @Test
    public void shouldComputePrefixSequential() {
        List<Integer> numbers = Arrays.asList(3, 5, 3, 1, 6);
        List<Integer> expectedSum = Arrays.asList(3, 8, 11, 12, 18);

        List<Integer> prefixSum = PrefixSum.computePrefixSequential(numbers);

        assertThat(prefixSum, is(expectedSum));
    }

    @Test
    public void shouldComputePrefixSequentialLoop() {
        List<Integer> numbers = Arrays.asList(3, 5, 3, 1, 6);
        List<Integer> expectedSum = Arrays.asList(3, 8, 11, 12, 18);

        List<Integer> prefixSum = PrefixSum.computePrefixSequentialLoop(numbers);

        assertThat(prefixSum, is(expectedSum));
    }

    @Test
    public void checkTimeTaken() {
        int[] numbersArray = new Random().ints(1000, 0, 100).toArray();
        List<Integer> numbers = Arrays.stream(numbersArray)
                .boxed()
                .collect(Collectors.toList());

        long startTime = System.nanoTime();
        PrefixSum.computePrefixParallel(numbers);
        long stopTime = System.nanoTime();
        System.out.println("P R time taken " + (stopTime - startTime));

        startTime = System.nanoTime();
        PrefixSum.computePrefixSequential(numbers);
        stopTime = System.nanoTime();
        System.out.println("S R time taken " + (stopTime - startTime));

        startTime = System.nanoTime();
        PrefixSum.computePrefixSequentialLoop(numbers);
        stopTime = System.nanoTime();
        System.out.println("S L time taken " + (stopTime - startTime));
    }
}