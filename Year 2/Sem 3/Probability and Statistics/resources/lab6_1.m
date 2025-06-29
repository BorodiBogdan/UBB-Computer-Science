% Load the statistics package
pkg load statistics

alpha = input("Give alpha (significance level): ");
X = [7, 7, 4, 5, 9, 9, 4, 12, 8, 1, 8, 7, 3, 13, 2, 1, 17, 7, 12, 5, 6, 2, 1, 13, 14, 10, 2, 4, 9, 11, 3, 5, 12, 6, 10, 7];
n = length(X);
sigma = 5;
m0 = 9;

% Calculate the Z-test manually as ztest function may not be available
X_mean = mean(X);
Z = (X_mean - m0) / (sigma / sqrt(n));
pval = normcdf(Z, 0, 1); % This is for a left-tailed test
ci = [X_mean + norminv(alpha, 0, 1) * sigma / sqrt(n), Inf];
h = (Z < norminv(alpha, 0, 1));

disp("We are solving the first part of the first problem");
disp("We are using a left-tailed test for the mean when we know sigma");
if h
  disp("The null hypothesis is rejected");
else
  disp("The null hypothesis is not rejected");
endif
disp(["The value of the test statistic Z is: ", num2str(Z)]);
disp(["The p-value of the test is: ", num2str(pval)]);
disp(["The rejection region is less than ", num2str(norminv(alpha, 0, 1))]);

% Part b
disp("We are solving the second part of the first problem");
m0 = 5.5;
[h, pval, ci, stats] = ttest(X, m0, 'Alpha', alpha, 'Tail', 'right');

disp("We are using a right-tailed test for the mean when we do not know sigma but we have a large sample");
if h
  disp("The null hypothesis is rejected");
else
  disp("The null hypothesis is not rejected");
endif
disp(["The value of the test statistic T is: ", num2str(stats.tstat)]);
disp(["The p-value of the test is: ", num2str(pval)]);
disp(["The rejection region is greater than ", num2str(norminv(1-alpha, 0, 1))]);

