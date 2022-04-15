clear; clc; close all;

M = csvread('Book2.csv', 1 , 0);
M1 = csvread('Book2(1).csv', 1 , 0);
M2 = csvread('Book2(2).csv', 1 , 0);
M3 = csvread('Book2(3).csv', 1 , 0);
M4 = csvread('Book2(4).csv', 1 , 0);
M5 = csvread('Book2(5).csv', 1 , 0);
M6 = csvread('Book2(6).csv', 1 , 0);


subplot(3,2,6);
plot(M6(:,1), M6(:,2), '.', 'MarkerSize',2);

 subplot(3,2,1);
plot(M1(:,1), M1(:,2), '.', 'MarkerSize',.1);
 
 subplot(3,2,2);
 plot(M2(:,1), M2(:,2), '.', 'MarkerSize',.1);
 
 subplot(3,2,3);
 plot(M(:,1), M(:,2), '.', 'MarkerSize',.1);
 
 subplot(3,2,4);
 plot(M4(:,1), M4(:,2), '.', 'MarkerSize',.1);
 
 subplot(3,2,5);
 plot(M5(:,1), M5(:,2), '.', 'MarkerSize',.1);
