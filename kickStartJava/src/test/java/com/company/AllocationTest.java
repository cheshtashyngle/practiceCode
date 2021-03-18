package com.company;

import org.junit.Test;

import static org.hamcrest.core.Is.is;
import static org.junit.Assert.assertThat;

public class AllocationTest {

    private Allocation allocation = new Allocation();

    @Test
    public void shouldTestNumberOfHouse1() {
        int[] houseRentList = {20, 90, 40, 90};
        int budget = 100;
        int numberOfHouses = allocation.maxNumberOfHouses(houseRentList, budget);

        assertThat(numberOfHouses, is(2));
    }

    @Test
    public void shouldTestNumberOfHouse2() {
        int[] houseRentList = {30, 30, 10, 10};
        int budget = 50;
        int numberOfHouses = allocation.maxNumberOfHouses(houseRentList, budget);

        assertThat(numberOfHouses, is(3));
    }

    @Test
    public void shouldTestNumberOfHouse() {
        int[] houseRentList = {999, 999, 999};
        int budget = 300;
        int numberOfHouses = allocation.maxNumberOfHouses(houseRentList, budget);

        assertThat(numberOfHouses, is(0));
    }
}